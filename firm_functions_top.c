#include "header.h"
#include "firm_agent_header.h"

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
        INVENTORY = PRODUCTION_CURRENT;
        SALES = INVENTORY;
        REVENUES = SALES * UNIT_GOODS_PRICE;
        EBIT = REVENUES - LABOUR_COSTS;
        NET_EARNINGS = REVENUES - OPERATING_COSTS;
        LIQUIDITY = NET_EARNINGS;
        // this should be fixed as int and we will get the ceiling value.
        PHYSICAL_CAPITAL = (TOTAL_ASSETS - UNIT_GOODS_PRICE * INVENTORY - LIQUIDITY)/CAPITAL_GOODS_PRICE;
        CAPITAL_CONSTRUCTION = 0;
        CAPITAL_GOODS = PHYSICAL_CAPITAL;
    } else {
        PRODUCTION_CURRENT = NO_EMPLOYEES * LABOUR_PRODUCTIVITY_CONSTRUCTION / 12;
        INVENTORY = PRODUCTION_CURRENT;
        SALES = 0;
        REVENUES = SALES * UNIT_HOUSE_PRICE;
        PHYSICAL_CAPITAL = 0;
        EBIT = REVENUES - LABOUR_COSTS;
        NET_EARNINGS = REVENUES - OPERATING_COSTS;
        LIQUIDITY = NET_EARNINGS;

        // this should be fixed as int and we will get the ceiling value.
        CAPITAL_CONSTRUCTION = (TOTAL_ASSETS - UNIT_HOUSE_PRICE * INVENTORY - LIQUIDITY)/CAPITAL_GOODS_PRICE;
        CAPITAL_GOODS = CAPITAL_CONSTRUCTION;
    }
    
    printf("\nFirm %d --> employed: ", ID);
    for (int i = 0; i < EMPLOYEES.size; i++) {
        printf(" %d ", EMPLOYEES.array[i]);
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
    
    printf("Firm %d Size = %d, %d \n", ID, NO_EMPLOYEES, EMPLOYEES.size);
    
    
   
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
    
    //printf("Firm ID = %d Liquidity amount = %f\n", ID, LIQUIDITY);
    
	return 0; /* Returning zero means the agent is not removed */
}
