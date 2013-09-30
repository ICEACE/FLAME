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
    
    printf("Firm Id = %d at Consumption Market\n", ID);
    if (UNIT_GOODS_PRICE == 0) {
        return 0;
    }
    if (INVENTORY > 0) {
        add_sell_message(ID, UNIT_GOODS_PRICE, INVENTORY);
        printf("Firm Id = %d Sends = %d Goods to Mall with a price = %f\n", ID, INVENTORY, UNIT_GOODS_PRICE);
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
    weekly_sales_income = quantity_sold * UNIT_GOODS_PRICE;
    
    //update inventory.
    INVENTORY = sold_message->unsold_quantities;
    
    //update sales.
    SALES += quantity_sold;
    
	FINISH_SOLD_MESSAGE_LOOP
    
    LIQUIDITY += weekly_sales_income;
    REVENUES += weekly_sales_income;
    
    //printf("Firm Id = %d Quantity Sold = %d Weekly Revenue = %f\n", ID, quantity_sold, weekly_sales_income);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_consumption_update_market_price()
 * \brief: The producer firm gets average market price per good.
 */
int firm_consumption_update_market_price()
{
    START_GOODS_TRANSACTIONS_SUMMARY_MESSAGE_LOOP
    AVERAGE_GOODS_PRICE = goods_transactions_summary_message->avg_price;
	FINISH_GOODS_TRANSACTIONS_SUMMARY_MESSAGE_LOOP

	return 0; /* Returning zero means the agent is not removed */
}
