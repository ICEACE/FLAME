#include "header.h"
#include "bank_agent_header.h"

/*
 * \fn: int bank_init()
 * \brief: notifies its id by printing out agent id.
 */
int bank_init()
{
	// Read from memory
	//printf("Bank Id = %d\n", ID);
    char * filename;
    FILE * file1;
    
    filename = malloc(40*sizeof(char));
    filename[0]=0;
    strcpy(filename, "./outputs/data/Bank_snapshot.txt");
    
    if (IT_NO == 0) {
        file1 = fopen(filename,"w");
        fprintf(file1,"%s %s %s %s %s %s %s\n","IT_NO","ID","MORTGAGES","LOANS","DEPOSITS","INTERESTS_ACCRUED","TOTAL_WRITEOFFS");
        fclose(file1);
        free(filename);
        IT_NO++;
        return 0;
    }
    
    file1 = fopen(filename,"a");
    fprintf(file1,"%d %d %f %f %f %f %f\n",IT_NO,ID,MORTGAGES,LOANS,DEPOSITS,INTERESTS_ACCRUED,TOTAL_WRITEOFFS);
    fclose(file1);
    free(filename);
    
    IT_NO++;
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_update_deposits()
 * \brief: puts money to deposit account of its prefered bak. */
int bank_update_deposits()
{
    double current_deposit, delta_deposit;
    double deposits_households = 0;
    double deposits_firms = 0;
    
    START_HOUSEHOLD_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP
    deposits_households += household_bank_update_deposit_message->amount;
    FINISH_HOUSEHOLD_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP
    
    START_FIRM_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP
    deposits_firms += firm_bank_update_deposit_message->amount;
    FINISH_FIRM_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP

    current_deposit = deposits_households + deposits_firms;
    delta_deposit = current_deposit - DEPOSITS;
    
    DEPOSITS = current_deposit;
    LIQUIDITY += delta_deposit;
    
	return 0; /* Returning zero means the agent is not removed */
}
