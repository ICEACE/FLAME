#include "../header.h"
#include "../bank_agent_header.h"

/*
 * \fn: int bank_housing_compute_capital_status()
 * \brief: The bank sends out its equity and risky assets.
 * The risky assets are loans to firms and mortgages to households plus liquidity.
 * The message is recieved by the real estate agency to while 'counselling'
 * households regarding their mortgage applications. The policy which
 * requires a base for equity is applied. See Real Estate Agent implementation.
 */
int bank_housing_compute_capital_status()
{
    double risk;
    /* liquidity is removed from the risk */
    risk = MORTGAGES + LOANS_START;
    add_bank_reagency_credibility_message(ID,EQUITY, risk);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_housing_deliver_mortages()
 * \brief:
 */
int bank_housing_deliver_mortages()
{
    double amount = 0;
    
    START_MORTGAGE_REQUESTS_MESSAGE_LOOP
    /* The message is filtered via xmml. */
    amount = mortgage_requests_message->amount;
    MORTGAGES += mortgage_requests_message->amount;
    LIQUIDITY -= amount;
    if (PRINT_DEBUG_MODE) {
        printf("Bank ID = %d has given %f amount of mortgages. \n",ID, amount);
    }
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
    /* The message is filtered via xmml. */
    amount = mortgage_payment_from_sale_message->amount;
    /* The amount recieved from households fire sale are considered solely as principal payment.
     It does not contain interests.
     */
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
    /* The message is filtered via xmml. */
    principal = mortgage_payment_message->principal;
    interest = mortgage_payment_message->interest;

    MORTGAGES -= principal;
    LIQUIDITY += principal + interest;
    /* Households gets mortgages from their own bank only. */
    //DEPOSITS -= principal + interest;
    INTERESTS_ACCRUED += interest;
    
	FINISH_MORTGAGE_PAYMENT_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_housing_mortage_writeoff()
 * \brief: Bank recieves mortgages that are written off.
 */
int bank_housing_debt_writeoff()
{
    double amount = 0;
    
    START_MORTGAGE_WRITEOFF_MESSAGE_LOOP
    /* The message is filtered via xmml. */
    amount = mortgage_writeoff_message->amount;
    MORTGAGES -= amount;
    TOTAL_WRITEOFFS += amount;
    
    if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/BankruptcyInspection.txt");
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %d %s %s %d %f\n",IT_NO, ID, "Bank", "Mortgages", ID, amount);
        fclose(file1);
        free(filename);
    }
    
	FINISH_MORTGAGE_WRITEOFF_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

