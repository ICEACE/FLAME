#include "../header.h"
#include "../bank_agent_header.h"

/*
 * \fn: int bank_credit_process_loan_requests_1()
 * \brief:
 */
int bank_credit_process_loan_requests_1()
{
    double risks, amount;
    int firm;

    START_LOAN_REQUEST_1_MESSAGE_LOOP
    risks = LOANS + MORTGAGES;
    amount = loan_request_1_message->amount;
    firm = loan_request_1_message->firm_id;
    // code redundancy is to prevent division by zero error. 
    if (risks == 0) {
        LOANS = amount;
        LIQUIDITY -= amount;
        add_loan_acknowledge_1_message(ID, firm, amount);
    }
    else if ((EQUITY / risks) >= RISKY_ASSETS_RATIO) {
        LOANS += amount;
        LIQUIDITY -= amount;
        add_loan_acknowledge_1_message(ID, firm, amount);
    }
    else {
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
    double risks, amount;
    int firm, primary_bank;
    
    START_LOAN_REQUEST_2_MESSAGE_LOOP
    risks = LOANS + MORTGAGES;
    amount = loan_request_2_message->amount;
    firm = loan_request_2_message->firm_id;
    primary_bank = loan_request_2_message->bank_id;
    
    // Ignore re-aplicatiotions to the same bank.
    if (primary_bank == ID) {
        return 0;
    }
    // code redundancy is to prevent division by zero error.
    else if (risks == 0) {
        LOANS = amount;
        LIQUIDITY -= amount;
        add_loan_acknowledge_2_message(ID, firm, amount);
    }
    else if ((EQUITY / risks) >= RISKY_ASSETS_RATIO) {
        LOANS += amount;
        LIQUIDITY -= amount;
        add_loan_acknowledge_2_message(ID, firm, amount);
    }
    else {
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



/*
 * \fn: int bank_credit_send_dividends()
 * \brief:
 */
int bank_credit_send_dividends()
{
    double net_income;
    
    net_income = INTERESTS_ACCRUED - TOTAL_WRITEOFFS;
    if (net_income <= 0) { return 0; }
    
    add_bank_net_profit_message(ID, net_income);
    DIVIDENDS_PAID += net_income;
    LIQUIDITY -= net_income;
    INTERESTS_ACCRUED = 0;
    TOTAL_WRITEOFFS = 0;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_credit_request_liquidity()
 * \brief: If a bank has a negative liquidity at the end of a quarter, requests loans from
 * the central bank.
 */
int bank_credit_request_liquidity()
{
    //The condition checked by state transition conditions. See model description file.
    double amount;
    amount = -1 * LIQUIDITY;
    add_debt_request_message(ID, amount);
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int bank_credit_recieve_liquidity()
 * \brief: Bank recieves the loan from the central bank and updates its book.
 */
int bank_credit_recieve_liquidity()
{
    //Model description filter picks the notice.
    double amount;
    
    START_DEBT_ACK_MESSAGE_LOOP
    amount = debt_ack_message->amount;
    LIQUIDITY += amount;
    DEBT += amount;
    FINISH_DEBT_ACK_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_credit_do_balance_sheet()
 * \brief: Bank does the balance sheet accounting.
 */
int bank_credit_do_balance_sheet()
{
    double assets, liabilities;
    
    assets = LIQUIDITY + LOANS + MORTGAGES;
    liabilities = DEPOSITS + DEBT;
    EQUITY = assets - liabilities;
    
	return 0; /* Returning zero means the agent is not removed */
}