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
    strcpy(filename, "./outputs/data/Firm_snapshot.txt");
    
    if (IT_NO == 0) {
        file1 = fopen(filename,"w");
        fprintf(file1,"%s %s %s %s %s %s %s %s %s\n","IT_NO","ID","ISCONSTRUCTOR","NO_EMPLOYEES","REVENUES","TOTAL_ASSETS","LIQUIDITY","DEBT","INVENTORY");
        fclose(file1);
        free(filename);
        IT_NO++;
        return 0;
    }
    
    file1 = fopen(filename,"a");
    fprintf(file1,"%d %d %d %d %f %f %f %f %d\n",IT_NO,ID,ISCONSTRUCTOR,NO_EMPLOYEES,REVENUES,TOTAL_ASSETS,LIQUIDITY,DEBT,INVENTORY);
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
    
    printf("Firm ID = %d Liquidity amount = %f\n", ID, LIQUIDITY);
    
	return 0; /* Returning zero means the agent is not removed */
}
