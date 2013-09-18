#include "header.h"
#include "household_agent_header.h"

/*
 * \fn: int household_init()
 * \brief: notifies its id by printing out agent id.
 */
int household_init()
{
    // Read from memory
	//printf(("Household Id: %d\n", ID);
    
    char * filename;
    FILE * file1;
    
    filename = malloc(40*sizeof(char));
    filename[0]=0;
    strcpy(filename, "./outputs/data/Household_snapshot.txt");
    
    
    if (IT_NO == 0) {
        file1 = fopen(filename,"w");
        fprintf(file1,"%s %s %s %s %s\n","IT_NO","ID","WAGE","HOUSING_VALUE","LIQUIDITY");
        fclose(file1);
        free(filename);
        IT_NO++;
        return 0;
    }
    
    file1 = fopen(filename,"a");
    fprintf(file1,"%d %d %f %f %f\n",IT_NO,ID,WAGE,HOUSING_VALUE,LIQUIDITY);
    fclose(file1);
    free(filename);
    
    IT_NO++;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_update_bank_account()
 * \brief: puts money to deposit account of its prefered bak. */
int household_update_bank_account()
{
    if (LIQUIDITY > 0) {
        add_household_bank_update_deposit_message(BANK_ID, LIQUIDITY);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}