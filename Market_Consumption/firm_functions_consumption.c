#include "../header.h"
#include "../firm_agent_header.h"

/*
 * \fn: int firm_consumption_supply()
 * \brief:
 */
int firm_consumption_supply()
{
    if (ISCONSTRUCTOR == 1) {
        return 0;
    }
    
    if (PRICE_UNIT_PRODUCT == 0) {
        return 0;
    }
    if (INVENTORY > 0) {
        add_sell_message(ID, PRICE_UNIT_PRODUCT, INVENTORY);
    }

	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_consumption_recieve_sales()
 * \brief:
 */
int firm_consumption_recieve_sales()
{
    int quantity_sold = 0;
    double weekly_sales_income = 0;
    
    
    START_SOLD_MESSAGE_LOOP
    quantity_sold = INVENTORY - sold_message->unsold_quantities;
    weekly_sales_income = quantity_sold * PRICE_UNIT_PRODUCT;
    
    //update inventory.
    INVENTORY = sold_message->unsold_quantities;
    
    //update sales.
    SALES += quantity_sold;
    
	FINISH_SOLD_MESSAGE_LOOP
    
    LIQUIDITY += weekly_sales_income;
    
    printf("Firm Id = %d Quantity Sold = %d Weekly Revenue = %f\n", ID, quantity_sold, weekly_sales_income);
    
	return 0; /* Returning zero means the agent is not removed */
}
