#include "header.h"
#include "firm_agent_header.h"
#include <math.h>

/*
 * \fn: int firm_init_post_id()
 * \brief:
 */
int firm_init_post_id()
{
    add_firm_jpoffice_id_message(ID, ISCONSTRUCTOR);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_init_employment()
 * \brief:
 */
int firm_init_employment()
{
    int new_employee;
        
    START_JPOFFICE_FIRM_EMPLOYEE_MESSAGE_LOOP
    new_employee = jpoffice_firm_employee_message->employee_id;
    add_int(&EMPLOYEES, new_employee);
    FINISH_JPOFFICE_FIRM_EMPLOYEE_MESSAGE_LOOP
    
    NO_EMPLOYEES = EMPLOYEES.size;
    EMPLOYEES_NEEDED = NO_EMPLOYEES;
    LABOUR_COSTS = NO_EMPLOYEES * WAGE_OFFER;
    DEBT = (NO_EMPLOYEES * WAGE_OFFER * 0.2) / LOANS_INTEREST_RATE;
    TOTAL_INTEREST_PAYMENTS = DEBT * LOANS_INTEREST_RATE / 4;
    OPERATING_COSTS = LABOUR_COSTS + TOTAL_INTEREST_PAYMENTS;
    EQUITY = DEBT / FIRM_STARTUP_LEVERAGE;
    TOTAL_ASSETS = DEBT + EQUITY;
    LOAN_LIST[0].amount = DEBT;
    
                                                                               
    if (ISCONSTRUCTOR == 0) {
        PRODUCTION_CURRENT = NO_EMPLOYEES * LABOUR_PRODUCTIVITY;
        INVENTORY = 0;
        SALES = PRODUCTION_CURRENT;
        REVENUES = SALES * UNIT_GOODS_PRICE;
        EBIT = REVENUES - LABOUR_COSTS;
        NET_EARNINGS = REVENUES - OPERATING_COSTS;
        LIQUIDITY = NET_EARNINGS;
        PHYSICAL_CAPITAL = (int) ceil((TOTAL_ASSETS - UNIT_GOODS_PRICE * INVENTORY - LIQUIDITY)/CAPITAL_GOODS_PRICE);
        CAPITAL_GOODS = PHYSICAL_CAPITAL;
        PHYSICAL_CAPITAL_CONSTRUCTION = 0;
        CAPITAL_PRODUCTIVITY_CONSTRUCTION = 0;
    } else {
        PRODUCTION_CURRENT = NO_EMPLOYEES * LABOUR_PRODUCTIVITY_CONSTRUCTION / 12;
        INVENTORY = PRODUCTION_CURRENT;
        SALES = 0;
        REVENUES = SALES * UNIT_HOUSE_PRICE;
        PHYSICAL_CAPITAL = 0;
        EBIT = REVENUES - LABOUR_COSTS;
        NET_EARNINGS = REVENUES - OPERATING_COSTS;
        LIQUIDITY = NET_EARNINGS;
        PHYSICAL_CAPITAL_CONSTRUCTION = (int) ceil((TOTAL_ASSETS - UNIT_HOUSE_PRICE * INVENTORY - LIQUIDITY)/CAPITAL_GOODS_PRICE);
        CAPITAL_GOODS = PHYSICAL_CAPITAL_CONSTRUCTION;
        CAPITAL_PRODUCTIVITY_CONSTRUCTION = LABOUR_PRODUCTIVITY_CONSTRUCTION * NO_EMPLOYEES / (0.7 * PHYSICAL_CAPITAL_CONSTRUCTION);
    }
    
    
    if (PRINT_DEBUG_MODE) {
        printf("Firm %d --> Size = %d \n", ID, NO_EMPLOYEES);
    }

        
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_init_balancesheet()
 * \brief:
 */
int firm_init_balancesheet()
{
   /*The firms are initiliazed loans only with their preferred banks. 
    */
    add_firm_bank_init_loans_message(BANK_ID, LOAN_LIST[0].amount);
    
    add_firm_bank_init_deposit_message(BANK_ID, LIQUIDITY);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_iterate()
 * \brief: 
 */
int firm_iterate()
{
    if (DATA_COLLECTION_MODE && COLLECT_FIRM_DATA) {
        if (IT_NO == 0)
        {
            char * filename;
            FILE * file1;
            filename = malloc(100*sizeof(char));
            
            if (ISCONSTRUCTOR) {
                /* @\fn: int firm_labour_workforce_needed() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Constructor_Firm_Monthly.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s\n","IT_NO", "ID", "WAGE_OFFER", "NO_EMPLOYEES", "EMPLOYEES_NEEDED", "INVENTORY", "PRODUCTION_PLAN");
                //fprintf(file1,"%d %d %f %d %d %d %d\n",IT_NO, ID, WAGE_OFFER, NO_EMPLOYEES, EMPLOYEES_NEEDED, INVENTORY, PRODUCTION_PLAN);
                fclose(file1);
                
                
                /* @\fn: int firm_credit_compute_income_statement() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Constructor_Firm_Quarterly_IncomeStatement.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s %s\n","IT_NO", "ID", "REVENUES", "OPERATING_COSTS", "LABOUR_COSTS", "TOTAL_INTEREST_PAYMENTS", "EBIT", "NET_EARNINGS");
                //fprintf(file1,"%d %d %f %f %f %f %f %f\n", IT_NO, ID, REVENUES, OPERATING_COSTS, LABOUR_COSTS, TOTAL_INTEREST_PAYMENTS, EBIT, NET_EARNINGS);
                fclose(file1);
                
                
                /* @\fn: int firm_credit_compute_dividends() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Constructor_Firm_Quarterly_Dividends.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s\n","IT_NO", "ID", "DIVIDENDS_PAID", "DIVIDENDS_TO_BE_PAID");
                //fprintf(file1,"%d %d %f %f\n", IT_NO, ID, DIVIDENDS_PAID, DIVIDENDS_TO_BE_PAID);
                fclose(file1);
                
                /* @\fn: int firm_credit_do_balance_sheet() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Constructor_Firm_Quarterly_BalanceSheet.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s %s %s %s %s %s\n","IT_NO", "ID", "ISINSOLVENT", "ISILLIQUID", "TOTAL_ASSETS", "LIQUIDITY", "INVENTORY", "UNIT_HOUSE_PRICE", "CAPITAL_GOODS_PRICE", "CAPITAL_GOODS", "PHYSICAL_CAPITAL_CONSTRUCTION", "DEBT");
                //fprintf(file1,"%d %d %d %d %f %f %d %f %f %d %d %f\n",IT_NO, ID, ISINSOLVENT, ISILLIQUID, TOTAL_ASSETS, LIQUIDITY, INVENTORY, UNIT_HOUSE_PRICE, CAPITAL_GOODS_PRICE, CAPITAL_GOODS, PHYSICAL_CAPITAL_CONSTRUCTION, DEBT);
                fclose(file1);
            }
            else
            {
                /* @\fn: int firm_labour_workforce_needed() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Firm_Monthly.txt");
                file1 = fopen(filename,"w");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s\n","IT_NO", "ID", "WAGE_OFFER", "NO_EMPLOYEES", "EMPLOYEES_NEEDED", "INVENTORY", "PRODUCTION_PLAN");
                //fprintf(file1,"%d %d %f %d %d %d %d\n",IT_NO, ID, WAGE_OFFER, NO_EMPLOYEES, EMPLOYEES_NEEDED, INVENTORY, PRODUCTION_PLAN);
                fclose(file1);
                
                
                /* @\fn: int firm_credit_compute_income_statement() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Firm_Quarterly_IncomeStatement.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s %s\n","IT_NO", "ID", "REVENUES", "OPERATING_COSTS", "LABOUR_COSTS", "TOTAL_INTEREST_PAYMENTS", "EBIT", "NET_EARNINGS");
                //fprintf(file1,"%d %d %f %f %f %f %f %f\n", IT_NO, ID, REVENUES, OPERATING_COSTS, LABOUR_COSTS, TOTAL_INTEREST_PAYMENTS, EBIT, NET_EARNINGS);
                fclose(file1);
                
                
                /* @\fn: int firm_credit_compute_dividends() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Firm_Quarterly_Dividends.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s\n","IT_NO", "ID", "DIVIDENDS_PAID", "DIVIDENDS_TO_BE_PAID");
                //fprintf(file1,"%d %d %f %f\n", IT_NO, ID, DIVIDENDS_PAID, DIVIDENDS_TO_BE_PAID);
                fclose(file1);
                
                /* @\fn: int firm_credit_do_balance_sheet() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Firm_Quarterly_BalanceSheet.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s %s %s %s %s %s\n","IT_NO", "ID", "ISINSOLVENT", "ISILLIQUID", "TOTAL_ASSETS", "LIQUIDITY", "INVENTORY", "UNIT_GOODS_PRICE", "CAPITAL_GOODS_PRICE", "CAPITAL_GOODS", "PHYSICAL_CAPITAL", "DEBT");
                //fprintf(file1,"%d %d %d %d %f %f %d %f %f %d %d %f\n",IT_NO, ID, ISINSOLVENT, ISILLIQUID, TOTAL_ASSETS, LIQUIDITY, INVENTORY, UNIT_GOODS_PRICE, CAPITAL_GOODS_PRICE, CAPITAL_GOODS, PHYSICAL_CAPITAL, DEBT);
                fclose(file1);
            }
            
            free(filename);
        }
    }
    
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
    
    if (PRINT_DEBUG_MODE) {
        printf("Firm ID = %d a liquidity amount = %f has deposited to bank.\n", ID, LIQUIDITY);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}
