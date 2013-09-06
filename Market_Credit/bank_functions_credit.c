#include "../header.h"
#include "../bank_agent_header.h"

/*
 * \fn: int bank_credit_check_interest_rate()
 * \brief: Checks quarterly interest rate determined by central bank.
 */
int bank_credit_check_interest_rate()
{
    
    START_INTEREST_RATE_MESSAGE_LOOP
    INTEREST_RATE = interest_rate_message->rate;
	FINISH_INTEREST_RATE_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_credit_compute_income_statement()
 * \brief:
 */
int bank_credit_compute_income_statement()
{
    /* No payment on principal amount of debt is considered here!
     The principal payment is done within balance sheet accounting.
     */
    INTERESTS_PAID = CENTRALBANK_DEBT * INTEREST_RATE;
    LIQUIDITY -= INTERESTS_PAID;
    add_bank_centralbank_interest_payment_message(ID, INTERESTS_PAID);
    
    REVENUES = INTERESTS_ACCRUED;
    TOTAL_COSTS = TOTAL_WRITEOFFS + INTERESTS_PAID;
    NET_EARNINGS = REVENUES - TOTAL_COSTS;
    // output revenues, interests collected and paid, writeoffs
    INTERESTS_ACCRUED = 0;
    TOTAL_WRITEOFFS = 0;
    INTERESTS_PAID = 0;
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int bank_credit_compute_dividends()
 * \brief:
 */
int bank_credit_compute_dividends()
{
    
    if (NET_EARNINGS <= 0) {
        TOTAL_DIVIDENDS = 0;
        RETAINED_EARNINGS = 0;
        return 0;
    }
    // determine if dividends retained.
    
    if (TOTAL_ASSETS > 0) {
        if ((EQUITY / TOTAL_ASSETS) < (CAPITAL_ADEQUECY_RATIO + CAR_BUFFER_THRESHOLD)){
            RETAINED_EARNINGS = NET_EARNINGS;
            TOTAL_DIVIDENDS = 0;
        }
        else{
            RETAINED_EARNINGS = 0;
            TOTAL_DIVIDENDS = NET_EARNINGS;;
        }
    }
    else
    {
        // stytem exit: put log file the information.
        printf("Total Asset of Bank = %d is Negative or Zero!!!\n", ID);
    }
    
    //add_bank_fund_dividends_message()
    LIQUIDITY -= TOTAL_DIVIDENDS;
    add_bank_net_profit_message(ID, TOTAL_DIVIDENDS);
    // data: retained_earnings, total_dividends.
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_credit_do_balance_sheet()
 * \brief: Bank does the balance sheet accounting.
 * If the bank is out of liquidity it compensates it from the central bank.
 * If the bank has positive liquidity and debt to central bank, it pays its debt.
 */
int bank_credit_do_balance_sheet()
{
    double amount;
    
    if (LIQUIDITY < 0) {
        amount = -1 * LIQUIDITY;
        CENTRALBANK_DEBT += amount;
        LIQUIDITY = 0;
        add_debt_request_message(ID, amount);
    }
    
    if (LIQUIDITY > 0 && CENTRALBANK_DEBT > 0) {
        if (LIQUIDITY > CENTRALBANK_DEBT){
            amount = CENTRALBANK_DEBT;
            LIQUIDITY -= amount;
            CENTRALBANK_DEBT = 0;
            add_bank_centralbank_debt_payment_message(ID, amount);
        }
        else{
            amount = LIQUIDITY;
            CENTRALBANK_DEBT -= amount;
            LIQUIDITY = 0;
            add_bank_centralbank_debt_payment_message(ID, amount);
        }
    }
       
    TOTAL_ASSETS = LIQUIDITY + LOANS + MORTGAGES;
    EQUITY = TOTAL_ASSETS - DEPOSITS - CENTRALBANK_DEBT;
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int bank_credit_process_loan_requests_1()
 * \brief:
 */
int bank_credit_process_loan_requests_1()
{
    double risk_weighted_assets, amount;
    int firm;
    
    //Liquidity may need to be removed from equation!!
    risk_weighted_assets = LOANS + MORTGAGES + LIQUIDITY;
    
    START_LOAN_REQUEST_1_MESSAGE_LOOP
    amount = loan_request_1_message->amount;
    firm = loan_request_1_message->firm_id;
    
    // code redundancy is to prevent division by zero error. 
    if (risk_weighted_assets == 0) {
        LOANS += amount;
        LIQUIDITY -= amount;
        add_loan_acknowledge_1_message(ID, firm, amount);
    }
    else if ((EQUITY / risk_weighted_assets) >= CAPITAL_ADEQUECY_RATIO) {
        LOANS += amount;
        LIQUIDITY -= amount;
        add_loan_acknowledge_1_message(ID, firm, amount);
    }
    else {
        printf("Error: bank_credit_process_loan_requests1 risk weighted assest below ZERO!!!");
    }
    FINISH_LOAN_REQUEST_1_MESSAGE_LOOP
    

	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_credit_process_loan_requests_2()
 * \brief: Processes requests from a rationed firms.
 */
int bank_credit_process_loan_requests_2()
{
    double risk_weighted_assets, amount;
    int firm;
    
    //Liquidity may need to be removed from equation!!
    risk_weighted_assets = LOANS + MORTGAGES + LIQUIDITY;
    
    START_LOAN_REQUEST_2_MESSAGE_LOOP
    amount = loan_request_2_message->amount;
    firm = loan_request_2_message->firm_id;
    
    // code redundancy is to prevent division by zero error.
    if (risk_weighted_assets == 0) {
        LOANS += amount;
        LIQUIDITY -= amount;
        add_loan_acknowledge_2_message(ID, firm, amount);
    }
    else if ((EQUITY / risk_weighted_assets) >= CAPITAL_ADEQUECY_RATIO) {
        LOANS += amount;
        LIQUIDITY -= amount;
        add_loan_acknowledge_2_message(ID, firm, amount);
    }
    else {
        printf("Error: bank_credit_process_loan_requests_2 risk weighted assest below ZERO!!!");
    }
    FINISH_LOAN_REQUEST_2_MESSAGE_LOOP

    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_credit_recieve_loan_writeoffs()
 * \brief:
 */
int bank_credit_recieve_loan_writeoffs()
{
    double amount;
    
    START_LOAN_WRITEOFF_MESSAGE_LOOP
    amount = loan_writeoff_message->amount;
    LOANS -= amount;
    EQUITY -= amount;
    TOTAL_WRITEOFFS += amount;
    FINISH_LOAN_WRITEOFF_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int bank_credit_recieve_new_entrant_loan_requests()
 * \brief:
 */
int bank_credit_recieve_new_entrant_loan_requests()
{
    double amount;
    
    START_NEW_ENTRANT_LOAN_MESSAGE_LOOP
    amount = new_entrant_loan_message->amount;
    LOANS += amount;
    LIQUIDITY -= amount;
    FINISH_NEW_ENTRANT_LOAN_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_credit_collect_loan_interests()
 * \brief:
 */
int bank_credit_collect_loan_interests()
{
    double amount;
    
    START_INTEREST_ON_LOAN_MESSAGE_LOOP
    amount = interest_on_loan_message->amount;
    LIQUIDITY += amount;
    INTERESTS_ACCRUED += amount;
    FINISH_INTEREST_ON_LOAN_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}




