#include "header.h"
#include "household_agent_header.h"


/*
 * \fn: int household_init_post_id()
 * \brief:
 */
int household_init_post_id()
{
    add_household_jpoffice_id_message(ID);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_init_employment()
 * \brief:
 */
int household_init_employment()
{
    START_JPOFFICE_HOUSEHOLD_EMPLOYER_MESSAGE_LOOP
    MY_EMPLOYER_ID = jpoffice_household_employer_message->employer_id;
    FINISH_JPOFFICE_HOUSEHOLD_EMPLOYER_MESSAGE_LOOP
    
    //printf("Household: %d employed at %d \n", ID, MY_EMPLOYER_ID);
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int household_init_balancesheet()
 * \brief: 
 */
int household_init_balancesheet()
{
    /*The firms are initiliazed loans only with their preferred banks.
     */
    add_household_bank_init_mortgages_message(BANK_ID, MORTGAGES);
    add_household_bank_init_deposit_message(BANK_ID, LIQUIDITY);
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_iterate()
 * \brief: Resumes its regular functions.
 */
int household_iterate()
{
    
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