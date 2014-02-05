#include "header.h"
#include "firm_agent_header.h"
#include <math.h>

/*
 * \fn: int firm_init_post_id()
 * \brief:
 */
int firm_init_post_id()
{
    add_firm_jpoffice_id_message(ID, FIRMTYPE);
    
    /*** Balancesheet Verification. */
    if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/Firm_ID_Liquidity_Loan.txt");
        file1 = fopen(filename,"w");
        //fprintf(file1,"%d %f %f\n",ID, LIQUIDITY, DEBT);
        fclose(file1);
        free(filename);
    }
    
    
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
    TOTAL_INTEREST_PAYMENTS = DEBT * (LOANS_INTEREST_RATE / 4);
    OPERATING_COSTS = LABOUR_COSTS + TOTAL_INTEREST_PAYMENTS;
    EQUITY = DEBT / FIRM_STARTUP_LEVERAGE;
    TOTAL_ASSETS = DEBT + EQUITY;
    LOAN_LIST[0].amount = DEBT;
    
                                                                               
    if (FIRMTYPE == 0) {
        PRODUCTION_CURRENT = (int) (NO_EMPLOYEES * LABOUR_PRODUCTIVITY);
        INVENTORY = (int) (PRODUCTION_CURRENT / 10);
        SALES = PRODUCTION_CURRENT;
        REVENUES = SALES * UNIT_GOODS_PRICE;
        CAPITAL_GOODS = ceil((TOTAL_ASSETS - UNIT_GOODS_PRICE * INVENTORY - LIQUIDITY)/(UNIT_CGOODS_PRICE * EXCHANGE_RATE));
    } else if (FIRMTYPE == 1) {
        PRODUCTION_CURRENT = (int) (NO_EMPLOYEES * LABOUR_PRODUCTIVITY / 12);
        INVENTORY = PRODUCTION_CURRENT;
        SALES = 0;
        REVENUES = SALES * UNIT_HOUSE_PRICE;
        CAPITAL_GOODS = ceil((TOTAL_ASSETS - UNIT_HOUSE_PRICE * INVENTORY - LIQUIDITY)/(UNIT_CGOODS_PRICE * EXCHANGE_RATE));
        CAPITAL_PRODUCTIVITY = LABOUR_PRODUCTIVITY * NO_EMPLOYEES / (0.7 * CAPITAL_GOODS);
    } else{
        PRODUCTION_CURRENT = (int) (NO_EMPLOYEES * LABOUR_PRODUCTIVITY);
        INVENTORY = 0;
        SALES = PRODUCTION_CURRENT;
        REVENUES = SALES * UNIT_XGOODS_PRICE * EXCHANGE_RATE;
        CAPITAL_GOODS = ceil((TOTAL_ASSETS - UNIT_XGOODS_PRICE * INVENTORY * EXCHANGE_RATE - LIQUIDITY)/(UNIT_CGOODS_PRICE * EXCHANGE_RATE));
    }

    RAWMATERIAL_COSTS = PRODUCTION_CURRENT * 3 * UNIT_RAW_PRICE * EXCHANGE_RATE;
    CGOODS_COSTS = CAPITAL_GOODS * DEPRECIATION_RATE * UNIT_CGOODS_PRICE * EXCHANGE_RATE;

    EBIT = REVENUES - LABOUR_COSTS - RAWMATERIAL_COSTS - CGOODS_COSTS;
    NET_EARNINGS = EBIT - TOTAL_INTEREST_PAYMENTS;
    LIQUIDITY = NET_EARNINGS;

    
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
    
    /*** Balancesheet Verification. */
    if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/Firm_ID_Liquidity_Loan.txt");
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %f %f\n",ID, LIQUIDITY, DEBT);
        fclose(file1);
        free(filename);

    }
    
    
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
            
            if (FIRMTYPE == 1) {
                /* @\fn: firm_production_construction_plan() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Constructor_Firm_Monthly.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s %s %s %s\n","IT_NO", "ID", "WAGE_OFFER", "NO_EMPLOYEES", "EMPLOYEES_NEEDED", "SALES", "INVENTORY", "PRODUCTION_CURRENT", "PRODUCTION_PLAN", "UNIT_HOUSE_PRICE");
                //fprintf(file1,"%d %d %f %d %d %d %d %d %f\n",IT_NO, ID, WAGE_OFFER, NO_EMPLOYEES, EMPLOYEES_NEEDED, SALES, INVENTORY, PRODUCTION_CURRENT, PRODUCTION_PLAN, UNIT_HOUSE_PRICE);
                fclose(file1);
                
                
                /* @\fn: firm_credit_compute_income_statement() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Constructor_Firm_Quarterly_IncomeStatement.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s %s\n","IT_NO", "ID", "REVENUES", "OPERATING_COSTS", "LABOUR_COSTS", "TOTAL_INTEREST_PAYMENTS", "EBIT", "NET_EARNINGS");
                //fprintf(file1,"%d %d %f %f %f %f %f %f\n", IT_NO, ID, REVENUES, OPERATING_COSTS, LABOUR_COSTS, TOTAL_INTEREST_PAYMENTS, EBIT, NET_EARNINGS);
                fclose(file1);
                
                
                /* @\fn: firm_credit_pay_dividends() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Constructor_Firm_Quarterly_Dividends.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s\n","IT_NO", "ID", "DIVIDENDS_PAID", "DIVIDENDS_TO_BE_PAID");
                //fprintf(file1,"%d %d %f %f\n", IT_NO, ID, DIVIDENDS_PAID, DIVIDENDS_TO_BE_PAID);
                fclose(file1);
                
                /* @\fn: firm_credit_do_balance_sheet() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Constructor_Firm_Quarterly_BalanceSheet.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n","IT_NO", "ID", "ISLIQUIDSHORT", "HASLOAN", "HASINVESTMENT", "LIQUIDITY_NEED", "ISINSOLVENT", "ISILLIQUID", "TOTAL_ASSETS", "LIQUIDITY", "INVENTORY", "UNIT_HOUSE_PRICE", "UNIT_CGOODS_PRICE", "CAPITAL_GOODS", "DEBT", "EQUITY");
                //fprintf(file1,"%d %d %d %d %d %f %d %d %f %f %d %f %f %d %d %f %f\n",IT_NO, ID, ISLIQUIDSHORT, HASLOAN, HASINVESTMENT, LIQUIDITY_NEED, ISINSOLVENT, ISILLIQUID, TOTAL_ASSETS, LIQUIDITY, INVENTORY, UNIT_HOUSE_PRICE, UNIT_CGOODS_PRICE, CAPITAL_GOODS, PHYSICAL_CAPITAL_CONSTRUCTION, DEBT, EQUITY);
                fclose(file1);
            }
            else if (FIRMTYPE == 0) {
                /* @\fn: firm_production_plan() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Firm_Monthly.txt");
                file1 = fopen(filename,"w");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s %s %s %s\n","IT_NO", "ID", "WAGE_OFFER", "NO_EMPLOYEES", "EMPLOYEES_NEEDED", "SALES", "INVENTORY", "PRODUCTION_CURRENT", "PRODUCTION_PLAN", "UNIT_GOODS_PRICE");
                //fprintf(file1,"%d %d %f %d %d %d %d %d %f\n",IT_NO, ID, WAGE_OFFER, NO_EMPLOYEES, EMPLOYEES_NEEDED, SALES, INVENTORY, PRODUCTION_CURRENT, PRODUCTION_PLAN, UNIT_GOODS_PRICE);
                fclose(file1);
                
                
                /* @\fn: firm_credit_compute_income_statement() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Firm_Quarterly_IncomeStatement.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s %s\n","IT_NO", "ID", "REVENUES", "OPERATING_COSTS", "LABOUR_COSTS", "TOTAL_INTEREST_PAYMENTS", "EBIT", "NET_EARNINGS");
                //fprintf(file1,"%d %d %f %f %f %f %f %f\n", IT_NO, ID, REVENUES, OPERATING_COSTS, LABOUR_COSTS, TOTAL_INTEREST_PAYMENTS, EBIT, NET_EARNINGS);
                fclose(file1);
                
                
                /* @\fn: firm_credit_pay_dividends() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Firm_Quarterly_Dividends.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s\n","IT_NO", "ID", "DIVIDENDS_PAID", "DIVIDENDS_TO_BE_PAID");
                //fprintf(file1,"%d %d %f %f\n", IT_NO, ID, DIVIDENDS_PAID, DIVIDENDS_TO_BE_PAID);
                fclose(file1);
                
                /* @\fn: firm_credit_do_balance_sheet() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Firm_Quarterly_BalanceSheet.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n","IT_NO", "ID", "ISLIQUIDSHORT", "HASLOAN", "HASINVESTMENT", "LIQUIDITY_NEED","ISINSOLVENT", "ISILLIQUID", "TOTAL_ASSETS", "LIQUIDITY", "INVENTORY", "UNIT_GOODS_PRICE", "UNIT_CGOODS_PRICE", "CAPITAL_GOODS", "DEBT", "EQUITY");
                
                //fprintf(file1,"%d %d %d %d %d %f %d %d %f %f %d %f %f %d %d %f %f\n",IT_NO, ID, ISLIQUIDSHORT, HASLOAN, HASINVESTMENT, LIQUIDITY_NEED, ISINSOLVENT, ISILLIQUID, TOTAL_ASSETS, LIQUIDITY, INVENTORY, UNIT_GOODS_PRICE, UNIT_CGOODS_PRICE, CAPITAL_GOODS, PHYSICAL_CAPITAL, DEBT, EQUITY);
                fclose(file1);
            } else {
                /* @\fn: firm_production_plan() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Export_Firm_Monthly.txt");
                file1 = fopen(filename,"w");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s %s %s %s\n","IT_NO", "ID", "WAGE_OFFER", "NO_EMPLOYEES", "EMPLOYEES_NEEDED", "SALES", "INVENTORY", "PRODUCTION_CURRENT", "PRODUCTION_PLAN", "UNIT_XGOODS_PRICE");
                //fprintf(file1,"%d %d %f %d %d %d %d %d %f\n",IT_NO, ID, WAGE_OFFER, NO_EMPLOYEES, EMPLOYEES_NEEDED, SALES, INVENTORY, PRODUCTION_CURRENT, PRODUCTION_PLAN, UNIT_GOODS_PRICE);
                fclose(file1);
                
                
                /* @\fn: firm_credit_compute_income_statement() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Export_Firm_Quarterly_IncomeStatement.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s %s\n","IT_NO", "ID", "REVENUES", "OPERATING_COSTS", "LABOUR_COSTS", "TOTAL_INTEREST_PAYMENTS", "EBIT", "NET_EARNINGS");
                //fprintf(file1,"%d %d %f %f %f %f %f %f\n", IT_NO, ID, REVENUES, OPERATING_COSTS, LABOUR_COSTS, TOTAL_INTEREST_PAYMENTS, EBIT, NET_EARNINGS);
                fclose(file1);
                
                
                /* @\fn: firm_credit_pay_dividends() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Export_Firm_Quarterly_Dividends.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s\n","IT_NO", "ID", "DIVIDENDS_PAID", "DIVIDENDS_TO_BE_PAID");
                //fprintf(file1,"%d %d %f %f\n", IT_NO, ID, DIVIDENDS_PAID, DIVIDENDS_TO_BE_PAID);
                fclose(file1);
                
                /* @\fn: firm_credit_do_balance_sheet() */
                filename[0]=0;
                strcpy(filename, "./outputs/data/Export_Firm_Quarterly_BalanceSheet.txt");
                file1 = fopen(filename,"w");
                fprintf(file1,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n","IT_NO", "ID", "ISLIQUIDSHORT", "HASLOAN", "HASINVESTMENT", "LIQUIDITY_NEED","ISINSOLVENT", "ISILLIQUID", "TOTAL_ASSETS", "LIQUIDITY", "INVENTORY", "UNIT_XGOODS_PRICE", "UNIT_CGOODS_PRICE", "CAPITAL_GOODS", "DEBT", "EQUITY");
                
                //fprintf(file1,"%d %d %d %d %d %f %d %d %f %f %d %f %f %d %d %f %f\n",IT_NO, ID, ISLIQUIDSHORT, HASLOAN, HASINVESTMENT, LIQUIDITY_NEED, ISINSOLVENT, ISILLIQUID, TOTAL_ASSETS, LIQUIDITY, INVENTORY, UNIT_GOODS_PRICE, UNIT_CGOODS_PRICE, CAPITAL_GOODS, PHYSICAL_CAPITAL, DEBT, EQUITY);
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
