#include "header.h"
#include "firm_agent_header.h"

/*
 * \fn: int firm_init()
 * \brief: notifies its id by printing out agent id.
 */
int firm_init()
{
    char * filename;
    FILE * file1;
    
    filename = malloc(40*sizeof(char));
    filename[0]=0;
    strcpy(filename, "./outputs/data/Firm_labour_size.txt");
    file1 = fopen(filename,"a");
    fprintf(file1,"\n %d %d %d %d",IT_NO,ID,NO_EMPLOYEES,VACANCIES);
    fclose(file1);
    free(filename);
    
    IT_NO++;
    
   
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_update_bank_account()
 * \brief: puts money to deposit account of its prefered bak. */
int firm_update_bank_account()
{
    if (LIQUIDITY > 0) {
        add_firm_bank_update_deposit_message(BANK_ID, LIQUIDITY);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}
