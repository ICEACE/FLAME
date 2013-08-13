#include "../header.h"
#include "../household_agent_header.h"

/*
 * \fn: int household_accounting_wealth_effect()
 * \brief:
 */
int household_consumption_monthly_budget()
{
    double disposable_income;
    double labour_income;
    double budget;
    
    labour_income = PREVIOUS_WAGES[0]+PREVIOUS_WAGES[1]+PREVIOUS_WAGES[2];
    
    disposable_income = (labour_income + FUND_SHARES - HOUSING_PAYMENT)/3;
    
    
    budget = disposable_income;
    budget += CONSUMPTION_ADJUSTMENT_SPEED * (LIQUIDITY - RATIO_LIQUIDITY * disposable_income);
    budget += WEALTH_EFFECT * EQUITY;
    // here instead equity use delta-assets for the wealth effect.
    // wealth effect amount is quarterly it should be divided by 3 for monthly budget.
    
    WEEKLY_CONSUMPTION_BUDGET = budget / 4;
    
    CONSUMPTION_BUDGET = 0;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_consumption_demand()
 * \brief:
 */
int household_consumption_demand()
{
    CONSUMPTION_BUDGET += WEEKLY_CONSUMPTION_BUDGET;
    
    if (CONSUMPTION_BUDGET > 0) {
        add_buy_message(ID, CONSUMPTION_BUDGET);
    }

	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_consumption_recieve_goods()
 * \brief:
 */
int household_consumption_recieve_goods()
{
    double money_spent = 0;
    int quantity_bought = 0;
    
    START_BOUGHT_MESSAGE_LOOP
    // household recieves this only when she went shopping with a budget.
    // there should be at most a single message. 
    money_spent = CONSUMPTION_BUDGET - bought_message->money_left;
    quantity_bought = bought_message->recieved_quantity;
    CONSUMPTION_BUDGET = bought_message->money_left;
	FINISH_BOUGHT_MESSAGE_LOOP
    
        
    //update liquidity.
    LIQUIDITY  -= money_spent;

    
    //printf("Household Id = %d money spent = %f\n", ID, money_spent);
    
	return 0; /* Returning zero means the agent is not removed */
}
