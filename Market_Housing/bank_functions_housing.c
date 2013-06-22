#include "../header.h"
#include "../bank_agent_header.h"

/*
 * \fn: int bank_housing_compute_capital_status()
 * \brief: The bank sends out its equity and risky assets.
 * The risky assets are loans to firms and mortgages to households.
 * The message is recieved by the real estate agency to while 'counselling'
 * households regarding their mortgage applications. The policy which
 * requires a base for equity is applied. See Real Estate Agent implementation.
 */
int bank_housing_compute_capital_status()
{
    add_mortgaging_capacity_message(ID,EQUITY,MORTGAGES+LOANS);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_housing_deliver_mortages()
 * \brief:
 */
int bank_housing_deliver_mortages()
{
    START_MORTGAGE_REQUESTS_MESSAGE_LOOP
    //The message is filtered via xmml.
    
    MORTGAGES += mortgage_requests_message->amount;
        
	FINISH_MORTGAGE_REQUESTS_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_housing_recieve_mortgage_principals()
 * \brief: Bank recieves the mortgage principals from households.
 */
int bank_housing_recieve_mortgage_principals()
{
    double amount;
    
    START_MORTGAGE_PAYMENT_FROM_SALE_MESSAGE_LOOP
    //The message is filtered via xmml.
    amount = mortgage_payment_from_sale_message->amount;
    //The amount recieved from households fire sale are considered the principal
    // payment. It does not contain interests.
    MORTGAGES -= amount;
    LIQUIDITY += amount;
    
	FINISH_MORTGAGE_PAYMENT_FROM_SALE_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_housing_recieve_mortgages()
 * \brief: Bank recives regular mortgage payments.
 */
int bank_housing_recieve_mortgages()
{
    double principal;
    double interest;
    
    START_MORTGAGE_PAYMENT_MESSAGE_LOOP
    //The message is filtered via xmml.
    principal = mortgage_payment_message->principal;
    interest = mortgage_payment_message->interest;
    
    MORTGAGES -= principal;
    LIQUIDITY += principal + interest;
    
	FINISH_MORTGAGE_PAYMENT_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_housing_mortage_writeoff()
 * \brief: Bank recieves mortgages that are written off.
 */
int bank_housing_debt_writeoff()
{
    START_MORTGAGE_WRITEOFF_MESSAGE_LOOP
    //The message is filtered via xmml.
    
    MORTGAGES += mortgage_writeoff_message->amount;
    
	FINISH_MORTGAGE_WRITEOFF_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

