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
    /* The 1 percent increase is determined by the model. */
    rcb = interest_rate_message->rate;
    LOANS_INTEREST_RATE = rcb + 0.01;
    
	FINISH_INTEREST_RATE_MESSAGE_LOOP
        
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int firm_credit_check_tax_rate()
 * \brief: Recieved from the government.
 */
int firm_credit_check_tax_rate()
{

    START_LABOUR_TAX_RATE_MESSAGE_LOOP
    LABOUR_TAX_RATE = labour_tax_rate_message->value;
	FINISH_LABOUR_TAX_RATE_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_compute_income_statement()
 * \brief: Firm computes its income statement.
 */
int firm_credit_compute_income_statement()
{
    int bank;
    double to_be_paid;
    
    TOTAL_INTEREST_PAYMENTS = 0;
    
    for (int i = 0; i < 2; i++) {
        bank = LOAN_LIST[i].bank_id;
        to_be_paid = LOAN_LIST[i].amount * LOANS_INTEREST_RATE / 4;
        LOAN_LIST[i].to_be_paid = to_be_paid;
        TOTAL_INTEREST_PAYMENTS += to_be_paid;
    }

    /* Labour cost is decremented from liquidity on a monthly basis.
     Costs (wages) and revenues (from sales) are updated incrementally.
     */
    
    OPERATING_COSTS = LABOUR_COSTS;
    EBIT = REVENUES - OPERATING_COSTS;
    NET_EARNINGS = EBIT - TOTAL_INTEREST_PAYMENTS;

    if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        filename = malloc(100*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/Firm_Quarterly_IncomeStatement.txt");
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %d %d %f %f %f %f %f %f\n", IT_NO, ID, ISCONSTRUCTOR, REVENUES, OPERATING_COSTS, LABOUR_COSTS, TOTAL_INTEREST_PAYMENTS, EBIT, NET_EARNINGS);
        fclose(file1);
        free(filename);
    }
    
    REVENUES = 0;
    OPERATING_COSTS = 0;
    LABOUR_COSTS = 0;
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_investment_decisions()
 * \brief: 
 */
int firm_credit_investment_decisions()
{
    RETAINED_EARNINGS = 0;
    PLANNED_INVESTMENT_COSTS = 0;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_compute_dividends()
 * \brief: Within this implementation the firm sends all of net income
 * to the Fund Equity to be distributed equally to households.
 */
int firm_credit_compute_dividends()
{
    DIVIDENDS_TO_BE_PAID = NET_EARNINGS - RETAINED_EARNINGS;
    
    if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        filename = malloc(100*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/Firm_Quarterly_Dividends.txt");
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %d %d %f %f\n", IT_NO, ID, ISCONSTRUCTOR, DIVIDENDS_PAID, DIVIDENDS_TO_BE_PAID);
        fclose(file1);
        free(filename);
    }
    
    DIVIDENDS_PAID = 0;
    RETAINED_EARNINGS = 0;
        
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_check_liquidity_need()
 * \brief: Firm checks its liquidity need. The information will be used for the decisio
 * to enter the credit market or not.
 */
int firm_credit_check_liquidity_need()
{
    
    LIQUIDITY_NEED = DIVIDENDS_TO_BE_PAID + TOTAL_INTEREST_PAYMENTS + PLANNED_INVESTMENT_COSTS - LIQUIDITY;
    
    if (LIQUIDITY_NEED < 0) {
        LIQUIDITY_NEED = 0  ;
    }
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_demand_loans_1()
 * \brief: Firm goes to its own bank for the loan request.
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
    
    if (PRINT_DEBUG_MODE){
        printf("Firm ID = %d @ Loan Stage 1 received %f of loans. \n", ID, amount);
    }
    
    
    if (amount == LIQUIDITY_NEED){
        LIQUIDITY_NEED = 0;
        LIQUIDITY += amount;
        DEBT += amount;
        LOAN_LIST[0].amount += amount;
        HASLOAN = 1;
    }
    /* Shall we allow partial loans? */
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

    if (PRINT_DEBUG_MODE){
        printf("Firm ID = %d @ Loan Stage 2 received %f of loans. \n", ID, amount);
    }

    
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
 * \fn: int firm_credit_request_equityfund_investment()
 * \brief: Firm goes to equity fund to get the required amount of liquidity it needs. Dividend payments are 
 * deferred.
 */
int firm_credit_request_equityfund_investment()
{
    LIQUIDITY_NEED = TOTAL_INTEREST_PAYMENTS - LIQUIDITY;
    
    if (LIQUIDITY_NEED < 0) {
        DIVIDENDS_TO_BE_PAID = 0;
        PLANNED_INVESTMENT_COSTS = 0;
        LIQUIDITY_NEED = 0 ;}

    if (LIQUIDITY_NEED > 0){
        if (TOTAL_ASSETS == 0){ return 0;}
        if ((EQUITY / TOTAL_ASSETS) > FIRMS_MINIMUM_EQUITY_RATIO) {
           add_fund_request_message(ID, LIQUIDITY_NEED); 
        }
    }
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_check_equityfund_investment()
 * \brief: Firms check if they are invested by Equity Fund for their liquidity need.
 */
int firm_credit_check_equityfund_investment()
{
    double amount = 0;
    
    HASINVESTMENT = 0;
    
    START_FUND_REQUEST_ACK_MESSAGE_LOOP
    amount = fund_request_ack_message->amount;
 	FINISH_FUND_REQUEST_ACK_MESSAGE_LOOP
    
    if (PRINT_DEBUG_MODE){
        printf("Firm ID = %d @ Loan - Equity Fund received %f amount of funding investment. \n", ID, amount);
    }

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
    double new_loans, current_loans;
    double ratio, current_amount, new_amount, delta_amount;
    int bank;
    
    current_loans = DEBT;
        
    /* Maximum amount of debts that can be paid.
     */
    if (EBIT < 0){
        new_loans = 0;}
    else {
        new_loans = EBIT / LOANS_INTEREST_RATE;
    }
    
    if (current_loans){
        ratio = new_loans / current_loans;}
    else {
        ratio = 0;
    }
    
    DEBT = new_loans;
    
    if (PRINT_DEBUG_MODE) {
        printf("Firm ID = %d is illiquidity bankrupt!\n", ID);
    }
    for (int i = 0; i < 2; i++) {
        bank = LOAN_LIST[i].bank_id;
        current_amount = LOAN_LIST[i].amount;
        new_amount = current_amount * ratio;
        LOAN_LIST[i].amount = new_amount;
        delta_amount = current_amount - new_amount;
        add_loan_writeoff_message(bank, delta_amount);
        if (PRINT_DEBUG_MODE) {
            printf("Firm ID = %d illiquidity bankrupt burden on Bank = %d is = %f \n",ID,bank, delta_amount);
        }

    }
    
    ISILLIQUID = 0;
    
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
        to_be_paid = LOAN_LIST[i].to_be_paid;
        LIQUIDITY -= to_be_paid;
        add_interest_on_loan_message(bank, to_be_paid);
    }

 	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int firm_credit_pay_dividends()
 * \brief: Firm send dividends to to the Fund Equity to be distributed
 * to households.
 */
int firm_credit_pay_dividends()
{
     
    if (DIVIDENDS_TO_BE_PAID < 0) {
        DIVIDENDS_TO_BE_PAID = 0;
        DIVIDENDS_PAID = DIVIDENDS_TO_BE_PAID;
        if (PRINT_DEBUG_MODE) {
            printf("Firm ID = %d, has no positive earnings to send out to share holders. \n", ID);
        }
        return 0;
    }
    
    if (DIVIDENDS_TO_BE_PAID > LIQUIDITY) {
        if (PRINT_DEBUG_MODE) {
         printf("Firm ID = %d, Dividends to be paid = %f, is more than liquidity = %f \n", ID, DIVIDENDS_TO_BE_PAID, LIQUIDITY);
        }
    }
    else{
        DIVIDENDS_PAID = DIVIDENDS_TO_BE_PAID;
        LIQUIDITY -= DIVIDENDS_TO_BE_PAID;
        add_firm_net_profit_message(ID, ISCONSTRUCTOR, DIVIDENDS_TO_BE_PAID);
        DIVIDENDS_TO_BE_PAID = 0;
    }

	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int firm_credit_do_balance_sheet()
 * \brief: Firm does the balance sheet accounting.
 */
int firm_credit_do_balance_sheet()
{
    
    if (ISCONSTRUCTOR) {
        TOTAL_ASSETS  = INVENTORY * UNIT_HOUSE_PRICE;
        TOTAL_ASSETS += LIQUIDITY + PHYSICAL_CAPITAL_CONSTRUCTION * CAPITAL_GOODS_PRICE;
    } else {
        TOTAL_ASSETS = INVENTORY * UNIT_GOODS_PRICE;
        TOTAL_ASSETS += LIQUIDITY + CAPITAL_GOODS * CAPITAL_GOODS_PRICE;
    }
    
    EQUITY = TOTAL_ASSETS - DEBT;
    
    if (EQUITY < 0) {
        ISINSOLVENT = 1;
    } else {
        ISINSOLVENT = 0;
    }
    
    if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        filename = malloc(100*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/Firm_Quarterly_BalanceSheet.txt");
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %d %d %d %d %f %f %d %f %f %f %d %d %f\n",IT_NO, ID, ISCONSTRUCTOR, ISINSOLVENT, ISILLIQUID, TOTAL_ASSETS, LIQUIDITY, INVENTORY, UNIT_GOODS_PRICE, UNIT_HOUSE_PRICE, CAPITAL_GOODS_PRICE, CAPITAL_GOODS, PHYSICAL_CAPITAL_CONSTRUCTION, DEBT);
        fclose(file1);
        free(filename);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_insolvency_bankruptcy()
 * \brief:
 */
int firm_credit_insolvency_bankruptcy()
{
    
    /* The firm will skip production for the first time and enters the labour market.
     The variable below is used for that purpose in production and labour markets.
     */
    
    /* Writeoff debts.
     */
    int bank;
    double amount;
    
    if (PRINT_DEBUG_MODE) {
        printf("Firm ID = %d is insolvent bankrupt!! \n", ID);
    }
    
    for (int i = 0; i < 2; i++) {
        bank = LOAN_LIST[i].bank_id;
        amount = LOAN_LIST[i].amount;
        add_loan_writeoff_message(bank, amount);
        LOAN_LIST[i].amount = 0;
    }
    DEBT = 0;
    LIQUIDITY = 0;
    SALES = 0;
    REVENUES = 0;
    OPERATING_COSTS = 0;
    /* Pysical capital kept the same.
     */
    
    if (ISCONSTRUCTOR == 0) {
        INVENTORY = LABOUR_PRODUCTIVITY * 1;
        TOTAL_ASSETS = INVENTORY * AVERAGE_GOODS_PRICE + LIQUIDITY;
        UNIT_GOODS_PRICE = AVERAGE_GOODS_PRICE;
    } else {
        INVENTORY = 0;
        TOTAL_ASSETS = CAPITAL_PRODUCTIVITY_CONSTRUCTION * 1 + LIQUIDITY;
        /* Constructor firms keep the avergae house prices */
    }
    /* Getting initial loan */
    TOTAL_ASSETS += CAPITAL_GOODS * CAPITAL_GOODS_PRICE;
    DEBT = TOTAL_ASSETS / (1 + FIRM_STARTUP_LEVERAGE);
    add_new_entrant_loan_message(ID, BANK_ID, DEBT);
    LOAN_LIST[0].amount = DEBT;
    EQUITY = TOTAL_ASSETS - DEBT;
	return 0; /* Returning zero means the agent is not removed */
}

