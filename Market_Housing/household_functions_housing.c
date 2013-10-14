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
    double quarterly_income;
    
    quarterly_income = LABOUR_INCOME + CAPITAL_INCOME;
    
    // check financial distress for the file sale case.
    if (HOUSING_PAYMENT > FIRE_SALE_THRESHOLD * quarterly_income){
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
    
    printf("Household: %d Equity %f, Liquidity = %f, Housing Value = %f, Wealth = %f \n", ID, EQUITY, LIQUIDITY, HOUSING_VALUE, wealth);
    
    if (wealth == 0){
        EQUITY_RATIO = 0;
    } else {
        EQUITY_RATIO = EQUITY / wealth;
    }
    
    // Print this to a file:
    if (EQUITY_RATIO <= 0 ) {
        printf("Household %d has a negative equity ratio = %f \n", ID, EQUITY_RATIO);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int household_housing_enter_market()
 * \brief: the household enters the housing market as a buyer
 */
int household_housing_enter_market()
{
    double income;
    
    income = LABOUR_INCOME + CAPITAL_INCOME;
    
    add_buy_housing_message(ID, BANK_ID, LIQUIDITY, income, HOUSING_PAYMENT);
    
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
    /* The message is filtered via xmml. */
    mortgage_used = bought_housing_message->mortgage_used;
    liquidity_spent = bought_housing_message->liquidity_spent;
    annuity = bought_housing_message->annuity;
	FINISH_BOUGHT_HOUSING_MESSAGE_LOOP
    
    if (mortgage_used + liquidity_spent > 0){
        HOUSING_UNITS += 1;
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
        add_mortgage(&MORTGAGES_LIST, BANK_ID, mortgage_used, 160, quarterly_interest, quarterly_principal);
        MORTGAGES += mortgage_used;
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
    
    if (sold == 0){ return 0; }
    
    int ind;
    mortgage mort;
    init_mortgage(&mort);
    
    // In current implementation sold = 1;
    HOUSING_UNITS -= sold;
    // Latest mortgage is sold.
    ind = MORTGAGES_LIST.size - 1;
    mort = MORTGAGES_LIST.array[ind];
    MORTGAGES -= mort.principal;
    // If the sale is lower than the principal amount. The liquid asset is used.
    add_mortgage_payment_from_sale_message(BANK_ID, mort.principal);
    LIQUIDITY += sale_price - mort.principal;
    remove_mortgage(&MORTGAGES_LIST, ind);
    free_mortgage(&mort);
    return 0;

    /* The process below can be applied for finer managemnt of money from hoouse sails.
     double new_principle;
     double new_quarterly_interest;
     double new_quarterly_principal;
     double annuity;
     double d1, d2;
     
    //Regular seller:
    if (HMARKET_ROLE == 2){
        ind = MORTGAGES_LIST.size - 1;
        mort = MORTGAGES_LIST.array[ind];
        if (mort.principal <= sale_price){
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
            add_mortgage(&MORTGAGES_LIST, BANK_ID, new_principle, mort.quarters_left, new_quarterly_interest, new_quarterly_principal);
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
            add_mortgage(&MORTGAGES_LIST, BANK_ID, new_principle, mort.quarters_left, new_quarterly_interest, new_quarterly_principal);
        }
       remove_mortgage(&MORTGAGES_LIST, ind); 
    }
    LIQUIDITY += sale_price;

    free_mortgage(&mort);
	return 0;
    */
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
    
    HOUSING_VALUE = HOUSING_UNITS * HOUSING_PRICE;
    
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
    double interest_paid;
    double principal_paid, principal_left;
    
    for (int i = 0; i < size; i++) {
        mort = MORTGAGES_LIST.array[i];
        interest_paid = mort.quarterly_interest / 3;
        principal_paid = mort.quarterly_principal / 3;
        principal_left = mort.principal - principal_paid;
        MORTGAGES_LIST.array[i].principal = principal_left;
        //if ((total_interest_paid + total_principal_paid) > LIQUIDITY) {break;}
        add_mortgage_payment_message(mort.bank_id, interest_paid, principal_paid);
        //add_mortgage(&MORTGAGES_LIST, BANK_ID, principal_left, mort.quarters_left, mort.quarterly_interest, mort.quarterly_principal);
        total_interest_paid += interest_paid;
        total_principal_paid += principal_paid;
    }
    
    /* Updates are done for above entries. No in place mutation is done.
    for (ind = 0; ind < size; ind++){
        remove_mortgage(&MORTGAGES_LIST, ind);
    }
    */
    
    
    MORTGAGE_COSTS[2] = MORTGAGE_COSTS[1];
    MORTGAGE_COSTS[1] = MORTGAGE_COSTS[0];
    MORTGAGE_COSTS[0] = total_principal_paid + total_interest_paid;
    
    MORTGAGES -= total_principal_paid;
    LIQUIDITY -= MORTGAGE_COSTS[0];
    
    HOUSING_PAYMENT = 0;
    for (ind = 0; ind < 3; ind++) {
        HOUSING_PAYMENT += MORTGAGE_COSTS[ind];
    }
    
    free_mortgage(&mort);
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: household_housing_debt_writeoff()
 * \brief: if household pays a significant amount of his income
 * to mortgages a debt write off occures and its mortgage
 * is restructured.
 */
int household_housing_debt_writeoff()
{
    int size, ind;
    double total_income;
    double pre_mortgages, writeoff;
    
    size = MORTGAGES_LIST.size;
    if (size == 0){ return 0;}
    
    mortgage mort;
    init_mortgage(&mort);
    
    double mortgage_costs = 0;
    ind = 0;
    while (ind < size) {
        mort = MORTGAGES_LIST.array[ind];
        mortgage_costs += mort.quarterly_interest;
        mortgage_costs += mort.quarterly_principal;
        ind++;
    }
    
    total_income = LABOUR_INCOME + CAPITAL_INCOME;
    if (mortgage_costs > HOUSEHOLD_MORTGAGE_WRITEOFF_HIGH * total_income)
    {
        double quarterly_principal, quarterly_interest;
        double annuity, d1, d2;
        
        pre_mortgages = MORTGAGES;
        MORTGAGES = HOUSEHOLD_MORTGAGE_WRITEOFF_LOW * total_income / MORTGAGES_INTEREST_RATE;
        writeoff = pre_mortgages - MORTGAGES;
        
        for (ind = 0; ind < size; ind++){remove_mortgage(&MORTGAGES_LIST, ind);}
        
        d1 = MORTGAGES_INTEREST_RATE/4;
        d2 = d1 * pow((1 + d1), 160);
        annuity = 1/d1 - 1/d2;
        
        quarterly_interest = MORTGAGES * MORTGAGES_INTEREST_RATE / 4;
        quarterly_principal = MORTGAGES / annuity - quarterly_interest;
        
        add_mortgage(&MORTGAGES_LIST, BANK_ID, MORTGAGES, 160, quarterly_interest, quarterly_principal);
        
        //This holds as with current implementation all mortgages are acquired from the same bank.
        add_mortgage_writeoff_message(BANK_ID, writeoff);

        printf("Household ID = %d, has his debts written off -> # of mortgages = %d. Loss on Bank ID = %d amounts to %f \n", ID, size, BANK_ID, writeoff);
        
        
    }
    
    free_mortgage(&mort);
	return 0; /* Returning zero means the agent is not removed */
}

