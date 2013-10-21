#include "../header.h"
#include "../household_agent_header.h"

/*
 * \fn: int household_consumption_compute_budget()
 * \brief: Household computes its regular weekly budget
 * and its monthly consumption limit. The incomes and costs are based on
 * a 3 months long history.
 */
int household_consumption_compute_budget()
{
    double disposable_income;
    double budget;
    
    HOUSING_PAYMENT = MORTGAGE_COSTS[0] + MORTGAGE_COSTS[1] + MORTGAGE_COSTS[2];
    
    disposable_income = LABOUR_INCOME + CAPITAL_INCOME - HOUSING_PAYMENT;
    
    
    budget = disposable_income;
    budget += CONSUMPTION_ADJUSTMENT_SPEED * (LIQUIDITY - RATIO_LIQUIDITY * disposable_income);
    budget += WEALTH_EFFECT * DELTA_HOUSING_VALUE;
    
    if (budget < 0) {
        WEEKLY_CONSUMPTION_BUDGET = 0;
    } else {
        WEEKLY_CONSUMPTION_BUDGET = budget / 12;
    }
    
    MALL_BUDGET = 0;
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_consumption_demand()
 * \brief: The function computes actual amount of money to be spent at the mall.
 */
int household_consumption_demand()
{
    MALL_BUDGET += WEEKLY_CONSUMPTION_BUDGET;
    
    if (LIQUIDITY <= 0 ) {
        if (PRINT_DEBUG_MODE){
            printf("Household ID = %d has no money to go to the mall!\n", ID);
        }
        return 0;
    }
    
    /* Below case may occur when liquidty of an household is taken down by housing expenditures, etc.
     */
    if (MALL_BUDGET > LIQUIDITY) {
        MALL_BUDGET = LIQUIDITY;
        if (LIQUIDITY > 0) {
         add_buy_message(ID, LIQUIDITY);   
        }
    } else {
        if (MALL_BUDGET > 0) {
         add_buy_message(ID, MALL_BUDGET);   
        }
    }
    
    if (PRINT_DEBUG_MODE) {
        if (ID > 50 && ID < 60) {
            printf("Household ID = %d goes to market with a budget = %f \n", ID, MALL_BUDGET);
        }
    }
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_consumption_recieve_goods()
 * \brief: Household updates its post-mall planned consumption and liquidity.
 */
int household_consumption_recieve_goods()
{
    double money_spent = 0;
    double money_to_spend;
    int quantity_bought = 0;
    
    if (PRINT_DEBUG_MODE) {
        if (ID > 50 && ID < 60) {
            printf("Household ID = %d waiting to receive goods from the mall. \n", ID);
        }
    }

    
    money_to_spend = MALL_BUDGET;
    
    START_BOUGHT_MESSAGE_LOOP
    money_spent = MALL_BUDGET - bought_message->money_left;
    quantity_bought = bought_message->recieved_quantity;
    MALL_BUDGET = bought_message->money_left;
	FINISH_BOUGHT_MESSAGE_LOOP
    
    LIQUIDITY  -= money_spent;
    
    if (PRINT_DEBUG_MODE) {
        if (ID > 50 && ID < 60) {
          printf("Household ID = %d bought %d goods \n", ID, quantity_bought);   
        }
    }
    
    if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/Household_Weekly.txt");
        
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %d %f %f %f %f\n",IT_NO, ID, LIQUIDITY, WEEKLY_CONSUMPTION_BUDGET, money_to_spend, money_spent);
        fclose(file1);
        free(filename);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}
