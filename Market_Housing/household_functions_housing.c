#include "../header.h"
#include "../household_agent_header.h"
#include "../library_header.h"
#include <math.h> 

/*
 * \fn: int household_housing_market_role()
 * \brief: Sets the market role of the household. It is a fire seller, determined by financial distress. Otherwise, household plays role of a buyer or seller equally likely. iseseller, 'intention' variable is set accordingly.
 */
int household_housing_market_role()
{
    double quarterly_mortgage_costs;
    double quarterly_income;
    
    quarterly_income = LABOUR_INCOME + CAPITAL_INCOME;
    
    quarterly_mortgage_costs = MORTGAGE_COSTS[0] + MORTGAGE_COSTS[1] + MORTGAGE_COSTS[2];
    
    // check financial distress for the file sale case.
    if (quarterly_mortgage_costs > FIRE_SALE_THRESHOLD * quarterly_income){
        if (HOUSING_UNITS == 0) { HMARKET_ROLE = 0; } else { HMARKET_ROLE  = 1;}
        return 0;
    }
    
    // inactive:
    if (random_int(0, 99) < (100 - 2 * HOUSING_MARKET_ENTRANCE_PROB * 100)) {
        HMARKET_ROLE = 0;
        return 0;
    }
    
    // set a regular buyer or seller role, flip the coin.
    if (random_int(0, 99) > 50) {
        //regular seller.
        if (HOUSING_UNITS == 0) { HMARKET_ROLE = 0;} else { HMARKET_ROLE  = 2;}
    }
    else {
        //buyer
        HMARKET_ROLE = 3;
    }
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_housing_check_wealth()
 * \brief: The househld computes his equity ratio.
 */
int household_housing_check_wealth()
{
    double wealth = 0;
    
    //Capital incomes CAPITAL_INCOME are liquidified as sooon as they are recieved.
    wealth = LIQUIDITY + HOUSING_VALUE;
    
    if (wealth == 0){
        EQUITY_RATIO = 0;
    } else {
        EQUITY_RATIO = EQUITY / wealth;
    }
    
    // Print this to a file:
    if (EQUITY_RATIO <= 0 ) {
       printf("Equity Ratio Household %d --> %f/n", ID, EQUITY_RATIO); 
    }
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int household_housing_enter_market()
 * \brief: the household enters the housing market as a buyer
 */
int household_housing_enter_market()
{
    double mortgage_costs;
    double income;
    
    income = LABOUR_INCOME + CAPITAL_INCOME;
    
    mortgage_costs = MORTGAGE_COSTS[0] + MORTGAGE_COSTS[1] + MORTGAGE_COSTS[2];
    
    add_buy_housing_message(ID, BANK_ID, LIQUIDITY, income, mortgage_costs);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_housing_bargain()
 * \brief:
 */
int household_housing_buy()
{
    double mortgage_used, liquidity_spent, annuity;
    mortgage_used = 0;
    liquidity_spent = 0;
    
    START_BOUGHT_HOUSING_MESSAGE_LOOP
    //The message is filtered via xmml.
    mortgage_used = bought_housing_message->mortgage_used;
    liquidity_spent = bought_housing_message->liquidity_spent;
    annuity = bought_housing_message->annuity;
	FINISH_BOUGHT_HOUSING_MESSAGE_LOOP
    
    if (mortgage_used + liquidity_spent > 0){
        HOUSING_UNITS += 1;
        MORTGAGES += mortgage_used + liquidity_spent;
    }
    
    if (liquidity_spent > 0){
        LIQUIDITY -= liquidity_spent;
    }
    
    if (mortgage_used > 0){
        double quarterly_interest;
        double quarterly_principal;
        
        quarterly_interest = mortgage_used * MORTGAGES_INTEREST_RATE / 4;
        quarterly_principal = (mortgage_used / annuity) - quarterly_interest;
        
        // update mortgages array.
        
        add_mortgage(&MORTGAGES_LIST, BANK_ID, 160, mortgage_used, quarterly_interest, quarterly_principal);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int household_housing_sell()
 * \brief: a regular seller household, going with some price over the average.
 */
int household_housing_sell()
{
    if (HOUSING_UNITS == 0) {return 0;}
    
    double price_difference, price;
    
    price_difference = (double)((random_int(0, 100)/100) * HOUSING_PRICE_UP_RATE);
    
    price = HOUSING_PRICE * (1 + price_difference);
    
    add_sell_housing_message(ID, price, 1);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_housing_fire_sell()
 * \brief: a fire seller household, going with some price below  the average.
 */
int household_housing_fire_sell()
{
    if (HOUSING_UNITS == 0) {return 0;}
    
    double price_difference, price;
    
    price_difference = (double)((random_int(0, 100)/100) * HOUSING_PRICE_DOWN_RATE);
    
    price = HOUSING_PRICE * (1 - price_difference);
    
    if (price > 0) {
        add_sell_housing_message(ID, price, 1);
    }
        
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_housing_collect_sale_revenue()
 * \brief:
 */
int household_housing_collect_sale_revenue()
{
    double sale_price;
    int sold = 0;
    
    START_SOLD_HOUSING_MESSAGE_LOOP
    //The message is filtered via xmml.
    sold = sold_housing_message->quantity_sold;
    sale_price = sold_housing_message->price_sold;
    FINISH_SOLD_HOUSING_MESSAGE_LOOP
    
    if (sold == 0){
        return 0;
    }
    
    int ind;
    mortgage mort;
    init_mortgage(&mort);
    double new_principle;
    double new_quarterly_interest;
    double new_quarterly_principal;
    double annuity;
    double d1, d2;
    
    HOUSING_UNITS -= 1;
    
    //Regular seller:
    if (HMARKET_ROLE == 2){
        ind = MORTGAGES_LIST.size - 1;
        mort = MORTGAGES_LIST.array[ind];
        if (mort.principal < sale_price){
            MORTGAGES -= mort.principal;
            LIQUIDITY += sale_price - mort.principal;
            add_mortgage_payment_from_sale_message(BANK_ID, mort.principal);
        }
        else {
            MORTGAGES -= sale_price;
            new_principle = mort.principal - sale_price;
            
            d1 = MORTGAGES_INTEREST_RATE/4;
            d2 = d1 * pow((1 + d1), mort.quarters_left);
            annuity = 1/d1 - 1/d2;
            
            new_quarterly_interest = new_principle * d1;
            new_quarterly_principal = (new_principle / annuity) - new_quarterly_interest;
            
            add_mortgage_payment_from_sale_message(BANK_ID, sale_price);
            // I was not sure of data mutation here, for safety reasons, the updated entry is removed and a new entry is added to the list.
            add_mortgage(&MORTGAGES_LIST, BANK_ID, mort.quarters_left, new_principle, new_quarterly_interest, new_quarterly_principal);
        }
        remove_mortgage(&MORTGAGES_LIST, ind);
        free_mortgage(&mort);
        return 0;
    }
    
    //Fire seller:
    //Pay mortgage while sold amount available to pay mortgages.
    while (sale_price > 0) {
        
        if (MORTGAGES_LIST.size == 0){ break;}
        
        //pay the newest mortgage first!
        ind = MORTGAGES_LIST.size - 1;
        mort = MORTGAGES_LIST.array[ind];
        if (mort.principal < sale_price){
            MORTGAGES -= mort.principal;
            add_mortgage_payment_from_sale_message(BANK_ID, mort.principal);
            sale_price -= mort.principal;
        }
        else {
            MORTGAGES -= sale_price;
            new_principle = mort.principal - sale_price;
            
            d1 = MORTGAGES_INTEREST_RATE/4;
            d2 = d1 * pow((1 + d1), mort.quarters_left);
            annuity = 1/d1 - 1/d2;
            
            new_quarterly_interest = new_principle * d1;
            new_quarterly_principal = (new_principle / annuity) - new_quarterly_interest;
                    
            add_mortgage_payment_from_sale_message(BANK_ID, sale_price);
            
            // I was not sure of data mutation here, for safety reasons, the updated entry is removed and a new entry is added to the list.
            add_mortgage(&MORTGAGES_LIST, BANK_ID, mort.quarters_left, new_principle, new_quarterly_interest, new_quarterly_principal);
        }
       remove_mortgage(&MORTGAGES_LIST, ind); 
    }
    
    LIQUIDITY += sale_price;
    
    free_mortgage(&mort);
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_housing_update_market_price()
 * \brief: Avg market price of housing is updated.
 */
int household_housing_update_market_price()
{
    //printf("HousingMarket Household Old Housing Price = %f\n", HOUSING_PRICE);
 
    START_HOUSING_PRICE_MESSAGE_LOOP
    HOUSING_PRICE = housing_price_message->price;
	FINISH_HOUSING_PRICE_MESSAGE_LOOP
    
    //printf("HousingMarket Household New Housing Price = %f\n", HOUSING_PRICE);
	    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_housing_pay_mortgages()
 * \brief: mortgage payments are sent to bank.
 */
int household_housing_pay_mortgages()
{
    int size, ind;
    
    size = MORTGAGES_LIST.size;
    if (size == 0){ return 0;}
    
    mortgage mort;
    init_mortgage(&mort);
    
    double total_interest_paid = 0;
    double total_principal_paid = 0;
    double interest;
    double principal;
    while (size > 0) {
        ind = size - 1;
        mort = MORTGAGES_LIST.array[ind];
        interest = mort.quarterly_interest / 3;
        principal = mort.quarterly_principal / 3;
        total_interest_paid += interest;
        total_principal_paid += principal;
        if ((total_interest_paid + total_principal_paid) > LIQUIDITY) {
            break;
        }
        add_mortgage_payment_message(mort.bank_id, interest, principal);
        size = ind;
    }
    
    MORTGAGE_COSTS[2] = MORTGAGE_COSTS[1];
    MORTGAGE_COSTS[1] = MORTGAGE_COSTS[0];
    MORTGAGE_COSTS[0] = total_principal_paid + total_interest_paid;
    
    MORTGAGES -= total_principal_paid;
    LIQUIDITY -= MORTGAGE_COSTS[0];
    
    free_mortgage(&mort);
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: household_housing_debt_writeoff()
 * \brief: if household pays a significant amount of his to
 * to mortgages a debt write off occures and its mortgage
 * is restructured.
 */
int household_housing_debt_writeoff()
{
    int size, ind;
    double total_income;
    
    size = MORTGAGES_LIST.size;
    if (size == 0){ return 0;}
    
    mortgage mort;
    init_mortgage(&mort);
    
    double mortgage_costs = 0;
    
    while (size > 0) {
        ind = size - 1;
        mort = MORTGAGES_LIST.array[ind];
        mortgage_costs += mort.quarterly_interest;
        mortgage_costs += mort.quarterly_principal;
        size = ind;
    }
    
    total_income = LABOUR_INCOME + CAPITAL_INCOME;
    if (mortgage_costs > HOUSEHOLD_MORTGAGE_WRITEOFF_HIGH * total_income)
    {
        double quarterly_principal, quarterly_interest;
        double annuity, d1, d2;
        
        for (ind = 0; ind < size; ind++){remove_mortgage(&MORTGAGES_LIST, ind);}
        
        MORTGAGES = HOUSEHOLD_MORTGAGE_WRITEOFF_LOW * total_income / MORTGAGES_INTEREST_RATE;
        
        d1 = MORTGAGES_INTEREST_RATE/4;
        d2 = d1 * pow((1 + d1), 160);
        annuity = 1/d1 - 1/d2;
        
        quarterly_interest = MORTGAGES * MORTGAGES_INTEREST_RATE / 4;
        quarterly_principal = (MORTGAGES / annuity) - quarterly_interest;
        
        add_mortgage(&MORTGAGES_LIST, BANK_ID, 160, MORTGAGES, quarterly_interest, quarterly_principal);
    }
    
    free_mortgage(&mort);
	return 0; /* Returning zero means the agent is not removed */
}

