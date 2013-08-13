#include "../header.h"
#include "../bank_agent_header.h"

/*
 * \fn: int bank_credit_process_loan_requests_1()
 * \brief:
 */
int bank_credit_process_loan_requests_1()
{


	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_credit_process_loan_requests_2()
 * \brief:
 */
int bank_credit_process_loan_requests_2()
{
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_credit_recieve_loan_writeoffs()
 * \brief:
 */
int bank_credit_recieve_loan_writeoffs()
{
    
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int bank_credit_recieve_new_entrant_loan_requests()
 * \brief:
 */
int bank_credit_recieve_new_entrant_loan_requests()
{
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_credit_collect_loan_interests()
 * \brief:
 */
int bank_credit_collect_loan_interests()
{
    
    
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