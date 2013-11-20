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
    if (WAGE == 0) {
        if (WARNING_MODE) {
            if ((MY_EMPLOYER_ID > 0 && WAGE == 0) || (MY_EMPLOYER_ID == 0 && WAGE > 0)) {
                printf("Warning @household_init_employment(): Wage and employment status doesn't match at the initialization! Household ID = %d, Wage = %f, Employer = %d, Wage is set to 5.0 \n", ID, WAGE, MY_EMPLOYER_ID);
            }
        }
        WAGE = 5.0;
    }
    FINISH_JPOFFICE_HOUSEHOLD_EMPLOYER_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int household_init_balancesheet()
 * \brief: 
 */
int household_init_balancesheet()
{
    /* The firms are initiliazed loans only with their preferred banks.
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
    if (DATA_COLLECTION_MODE && COLLECT_HOUSEHOLD_DATA) {
        if (IT_NO == 0) {
            char * filename;
            FILE * file1;
            filename = malloc(80*sizeof(char));
            
            /* Writing the column names. Make sure that an household with that ID does exist. */
            if (ID == 542)  {
                
                /* @\fn: int household_consumption_recieve_goods() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Household_Weekly.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s\n","IT_NO", "ID", "LIQUIDITY", "WEEKLY_CONSUMPTION_BUDGET", "money_to_spend", "money_spent");
                //fprintf(file1,"%d %d %f %f %f %f\n",IT_NO, ID, LIQUIDITY, WEEKLY_CONSUMPTION_BUDGET, 0.0, 0.0);
                fclose(file1);
                
                /* @\fn: household_housing_debt_writeoff() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Household_Monthly_FirstDay.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s %s\n", "IT_NO", "ID", "MORTGAGES", "MORTGAGE_COST", "HOUSING_UNITS", "HOUSING_VALUE", "EQUITY_RATIO", "LIQUIDITY");
                //fprintf(file1,"%d %d %f %f %d %f %f %f\n",IT_NO, ID, MORTGAGES, MORTGAGE_COSTS[0], HOUSING_UNITS, HOUSING_VALUE, EQUITY_RATIO, LIQUIDITY);
                fclose(file1);
                
                /* @\fn: int household_credit_collect_benefits() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Household_Monthly_LastDay.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s\n","IT_NO", "ID", "MY_EMPLOYER_ID", "WAGE", "unemployment_benefit", "general_benefit");
                //fprintf(file1,"%d %d %d %f %f %f\n",IT_NO, ID, MY_EMPLOYER_ID, WAGE, 0.0, 0.0);
                fclose(file1);
                
                /* @\fn: int household_credit_do_balance_sheet() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Household_Quarterly.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s %s %s %s %s\n","IT_NO", "ID", "TOTAL_ASSETS", "LIQUIDITY", "HOUSING_VALUE", "LABOUR_INCOME", "BENEFITS", "CAPITAL_INCOME", "MORTGAGES", "HOUSING_PAYMENT", "EQUITY");
                //fprintf(file1,"%d %d %f %f %f %f %f %f %f %f %f\n",IT_NO, ID, TOTAL_ASSETS, LIQUIDITY, HOUSING_VALUE, LABOUR_INCOME, GOVERNMENT_BENEFITS, CAPITAL_INCOME, MORTGAGES, HOUSING_PAYMENT, EQUITY);
                fclose(file1);
                
                free(filename);
            }
        }
    }
    
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
    
    if (PRINT_DEBUG_MODE) {
        if (ID > 40 && ID < 60) {
            printf("Household ID = %d has a liquidity amount = %f deposited to bank.\n", ID, LIQUIDITY);
        }
        
    }
	return 0; /* Returning zero means the agent is not removed */
}