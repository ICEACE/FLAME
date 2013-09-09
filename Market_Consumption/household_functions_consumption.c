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
    // here instead equity use delta-assets for the wealth effect.
    // wealth effect amount is quarterly it should be divided by 3 for monthly budget.
    if (budget < 0) {
        WEEKLY_CONSUMPTION_BUDGET = 0;
    } else {
        WEEKLY_CONSUMPTION_BUDGET = budget / 12;
    }
    
    PLANNED_CONSUMPTION_BUDGET = 0;
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_consumption_demand()
 * \brief: The function computes actual amount of money to be spent at the mall.
 */
int household_consumption_demand()
{
    PLANNED_CONSUMPTION_BUDGET += WEEKLY_CONSUMPTION_BUDGET;
    
    if (LIQUIDITY < 0 ) { return 0; }
    
    // This may happen that liquidty of an household is drawn due to housing expenditures, etc.
    if (PLANNED_CONSUMPTION_BUDGET > LIQUIDITY) {
        PLANNED_CONSUMPTION_BUDGET = LIQUIDITY;
        add_buy_message(ID, LIQUIDITY);
    } else {
        add_buy_message(ID, PLANNED_CONSUMPTION_BUDGET);
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
    int quantity_bought = 0;
    
    START_BOUGHT_MESSAGE_LOOP
    // household recieves this only when she/he went shopping with a budget.
    // there should be at most a single message. 
    money_spent = PLANNED_CONSUMPTION_BUDGET - bought_message->money_left;
    // The amount of goods consumed can be used later...
    quantity_bought = bought_message->recieved_quantity;
    PLANNED_CONSUMPTION_BUDGET = bought_message->money_left;
    //update liquidity.
    LIQUIDITY  -= money_spent;
	FINISH_BOUGHT_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}
