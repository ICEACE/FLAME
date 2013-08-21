#include "../header.h"
#include "../firm_agent_header.h"

/*
 * \fn: int firm_credit_check_interest_rate()
 * \brief: it receives interest rate from the central bank and updates interest to be paid on loans.
 */
int firm_credit_check_interest_rate()
{
    double rcb;
    START_INTEREST_RATE_MESSAGE_LOOP
    // 1 percent increase determined by the model.
    rcb = interest_rate_message->rate;
    LOANS_INTEREST_RATE = rcb + 0.01;
    
	FINISH_INTEREST_RATE_MESSAGE_LOOP
        
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_check_liquidity_need()
 * \brief: 
 */
int firm_credit_check_liquidity_need()
{
    double dividends_to_be_paid;
    double interests_to_be_paid;
        
    dividends_to_be_paid = REVENUE - COSTS;
    interests_to_be_paid = DEBT * LOANS_INTEREST_RATE;
    LIQUIDITY_NEED = dividends_to_be_paid + interests_to_be_paid - LIQUIDITY;
    
    if (LIQUIDITY_NEED < 0) {
        LIQUIDITY_NEED = 0  ;
    }

	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_demand_loans_1()
 * \brief:
 */
int firm_credit_demand_loans_1()
{
    if (LIQUIDITY_NEED > 0){
       add_loan_request_1_message(ID, BANK_ID, LIQUIDITY_NEED);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_borrow_loans_1()
 * \brief: The function is run when there is liquidity need.
 */
int firm_credit_borrow_loans_1()
{
    double amount = 0;

    START_LOAN_ACKNOWLEDGE_1_MESSAGE_LOOP
    amount = loan_acknowledge_1_message->amount;
 	FINISH_LOAN_ACKNOWLEDGE_1_MESSAGE_LOOP
    
    if (amount >= LIQUIDITY_NEED){
        LIQUIDITY_NEED = 0;
        LIQUIDITY += amount;
        DEBT += amount;
        LOAN_LIST[0].amount += amount;
        HASLOAN = 1;
    }
    else{
        HASLOAN = 0;
        add_loan_request_2_message(ID, LOAN_LIST[1].bank_id, LIQUIDITY_NEED);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_borrow_loans_2()
 * \brief:
 */
int firm_credit_borrow_loans_2()
{
    double amount = 0;
    
    START_LOAN_ACKNOWLEDGE_2_MESSAGE_LOOP
    amount = loan_acknowledge_2_message->amount;
 	FINISH_LOAN_ACKNOWLEDGE_2_MESSAGE_LOOP

    if (amount >= LIQUIDITY_NEED){
        LIQUIDITY_NEED = 0;
        LIQUIDITY += amount;
        DEBT += amount;
        LOAN_LIST[1].amount += amount;
        HASLOAN = 1;
    }
    else{
        HASLOAN = 0;
    }
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_request_investment()
 * \brief: Firm goes to equity fund to get the required amount of liquidity it needs. Dividend payments are 
 * deferred.
 */
int firm_credit_request_investment()
{
    // Check critical liquidity need.
    double interests_to_be_paid;
    
    interests_to_be_paid = DEBT * LOANS_INTEREST_RATE;
    LIQUIDITY_NEED = interests_to_be_paid - LIQUIDITY;
    
    if (LIQUIDITY_NEED < 0) {
        LIQUIDITY_NEED = 0  ;
    }

    double assets;
    
    if (LIQUIDITY_NEED > 0){
        if (ISCONSTRUCTOR == 1) {
            assets = INVENTORY * UNIT_HOUSE_PRICE;
            assets += LIQUIDITY + CAPITAL_CONSTRUCTION;
        } else {
            assets = INVENTORY * UNIT_GOODS_PRICE;
            assets += LIQUIDITY + CAPITAL_GOODS;
        }
        
        EQUITY = assets - DEBT;
        
        if (assets = 0){
            return 0;
        }
        if ((EQUITY / assets) > FIRMS_MINIMUM_EQUITY_RATIO) {
           add_fund_request_message(ID, LIQUIDITY_NEED); 
        }
    }
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_check_investment()
 * \brief: Firms check if they are invested by Equity Fund for their liquidity need.
 */
int firm_credit_check_investment()
{
    double amount = 0;
    
    HASINVESTMENT = 0;
    
    START_FUND_REQUEST_ACK_MESSAGE_LOOP
    amount = fund_request_ack_message->amount;
 	FINISH_FUND_REQUEST_ACK_MESSAGE_LOOP
    
    if (amount > 0) {
        LIQUIDITY += amount;
        HASINVESTMENT = 1;
        EQUITY += amount;
        LIQUIDITY_NEED = 0;
    }
	return 0; /* Returning zero means the agent is not removed */
}



/*
 * \fn: int firm_credit_illiquidity_bankrupt()
 * \brief: Firm debt is restructured.
 */
int firm_credit_illiquidity_bankrupt()
{
    double ebit;
    double new_loans, current_loans;
    double ratio, current_amount, new_amount;
    int bank;
    
    current_loans = LOAN_LIST[0].amount + LOAN_LIST[1].amount;
    
    /* Earning before interest and taxes.
     */
    ebit = REVENUE - COSTS;
    
    /* maximum amount debts that can be paid.
     */
    if (ebit < 0){ new_loans = 0;}
    else { new_loans = ebit / LOANS_INTEREST_RATE;}
    
    if (current_loans = 0) { ratio = 0;}
    else { ratio = new_loans / current_loans;}
    
    DEBT = DEBT - current_loans + new_loans;
    
    for (int i = 0; i < 2; i++) {
        bank = LOAN_LIST[i].bank_id;
        current_amount = LOAN_LIST[i].amount;
        new_amount = current_amount * ratio;
        LOAN_LIST[i].amount = new_amount;
        add_loan_writeoff_message(bank, new_amount);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int firm_credit_exit_market()
 * \brief:
 */
int firm_credit_exit_market()
{
    
    /* The firm will skip production for the first time and enters the labour market.
     The variable below is used for that purpose in production and labour markets.
     */
    ISINSOLVENT = 1;
    
    /* Writeoff debts.
     */
    int bank;
    double amount;
    double total_assets;
    
    for (int i = 0; i < 2; i++) {
        bank = LOAN_LIST[i].bank_id;
        amount = LOAN_LIST[i].amount;
        add_loan_writeoff_message(bank, amount);
        LOAN_LIST[i].amount = 0;
    }
    DEBT = 0;
    LIQUIDITY = 0;
    SALES = 0;
    REVENUE = 0;
    COSTS = 0;
    /* Pysical capital kept the same.
     */
    
    if (ISCONSTRUCTOR == 0) {
        INVENTORY = LABOUR_PRODUCTIVITY * 1;
        total_assets = INVENTORY * AVERAGE_GOODS_PRICE + LIQUIDITY;
        UNIT_GOODS_PRICE = AVERAGE_GOODS_PRICE;
    } else {
        INVENTORY = 0;
        total_assets = CAPITAL_PRODUCTIVITY_CONSTRUCTION * 1 + LIQUIDITY;
        /* Constructor firms keep the avergae house prices */
    }
    /* Getting initial loan */
    total_assets += PHYSICAL_CAPITAL;
    DEBT = total_assets / (1 + FIRM_STARTUP_LEVERAGE);
    add_new_entrant_loan_message(ID, BANK_ID, DEBT);
    LOAN_LIST[0].amount = DEBT;
    //LIQUIDITY += DEBT;
    EQUITY = total_assets - DEBT;
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_distribute_net_profit ()
 * \brief: Within this implementation the firm sends all of net income
 * to the Fund Equity to be distributed equally to households.
 */
int firm_credit_distribute_net_profit()
{
    double net_profit, ebit;
    
    // Labour cost is decremented from liquidity on a monthly basis.
    // Cost and revenue are updated incrementally.
    
    ebit = REVENUE - COSTS;
    
    // Firms doesn't pay tax but interest on loans.
    int bank;
    double interest_to_be_paid;
    for (int i = 0; i < 2; i++) {
        bank = LOAN_LIST[i].bank_id;
        interest_to_be_paid = LOAN_LIST[i].amount * LOANS_INTEREST_RATE;
    }
    net_profit = ebit - interest_to_be_paid;
    
    
    // In case net income is positive it is sent to be distributed.
    if (net_profit > 0) {
        add_firm_net_profit_message(ID, ISCONSTRUCTOR, net_profit);
        //Check this with production market.
        REVENUE = 0;
        COSTS = 0;
        // The amount sent is decremented from liquidity
        LIQUIDITY -= net_profit;
    }
    
    //printf(" Firm Id = %d, Net Profit %f \n", ID, net_profit);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_pay_interest_on_loans()
 * \brief:
 */
int firm_credit_pay_interest_on_loans()
{

    int bank;
    double to_be_paid;
    
    for (int i = 0; i < 2; i++) {
        bank = LOAN_LIST[i].bank_id;
        to_be_paid = LOAN_LIST[i].amount * LOANS_INTEREST_RATE;
        LIQUIDITY -= to_be_paid;
        add_interest_on_loan_message(bank, to_be_paid);
    }

 	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int firm_credit_do_balance_sheet()
 * \brief: Firm does the balance sheet accounting.
 */
int firm_credit_do_balance_sheet()
{
    double assets;
    
    if (ISCONSTRUCTOR == 1) {
        assets = INVENTORY * UNIT_HOUSE_PRICE;
        assets += LIQUIDITY + CAPITAL_CONSTRUCTION;
    } else {
        assets = INVENTORY * UNIT_GOODS_PRICE;
        assets += LIQUIDITY + CAPITAL_GOODS;
    }
    
    EQUITY = assets - DEBT;
    
    //printf(" Firm Id = %d, Equity %f \n", ID, EQUITY);
    
	return 0; /* Returning zero means the agent is not removed */
}


