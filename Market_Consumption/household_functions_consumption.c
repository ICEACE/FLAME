#include "../header.h"
#include "../household_agent_header.h"

/*
 * \fn: int household_consumption_demand()
 * \brief:
 */
int household_consumption_demand()
{

    if (WEEKLY_CONSUMPTION_BUDGET > 0) {
        add_buy_message(ID, WEEKLY_CONSUMPTION_BUDGET);
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
    money_spent = WEEKLY_CONSUMPTION_BUDGET - bought_message->money_left;
    quantity_bought = bought_message->recieved_quantity;

    //update liquidity.
    LIQUIDITY  -= money_spent;
   
	FINISH_BOUGHT_MESSAGE_LOOP
    
    printf("Household Id = %d Weakly Spenditure = %f\n", ID, money_spent);
    
	return 0; /* Returning zero means the agent is not removed */
}
