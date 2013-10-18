#include "../header.h"
#include "../firm_agent_header.h"
#include "../library_header.h"

/*
 * \fn: int firm_housing_enter_market()
 * \brief: The construction firm enters the market buy number housing inventory
 * and a stochastically determined price increase.
 */
int firm_housing_enter_market()
{
    double price_difference, price;
    
    int i = 1;
    while (i <= INVENTORY) {
        price_difference = (double)((random_int(0, 100)/100) * HOUSING_PRICE_UP_RATE);
        price = UNIT_HOUSE_PRICE * (1 + price_difference);
        add_sell_housing_message(ID, price, 1);
        i++;
    }
    
    if (PRINT_DEBUG_MODE) {
        printf("Firm ID = %d goes to housing market with %d housing units to sell. \n", ID, INVENTORY);
    }
	return 0; /* Returning zero means the agent is not removed */
}
/*
 * \fn: int firm_housing_collect_sale_revenues()
 * \brief: The contructor firm checks its ID from the message board and 
 * updates its inventory, revenue, sales and liquidity when monthly
 * housing markets is closed.
 */
int firm_housing_collect_sale_revenues()
{
    int n_sold_units = 0;
    int total_sold = 0;
    double sale_unit_price, sales_income;
    
    
    START_SOLD_HOUSING_MESSAGE_LOOP
    /* The message is filtered via xmml. */
    n_sold_units = sold_housing_message->quantity_sold;
    sale_unit_price = sold_housing_message->price_sold;
    
    /* Updating inventory. */
    INVENTORY -= n_sold_units;
    total_sold += n_sold_units;
    
    /* Updating sales. */
    SALES += n_sold_units;
    
    /* Updating revenue and liquidity */
    sales_income = n_sold_units * sale_unit_price;
    LIQUIDITY += sales_income;
    REVENUES += sales_income;
    
	FINISH_SOLD_HOUSING_MESSAGE_LOOP
    
    if (PRINT_DEBUG_MODE) {
        printf("Firm ID = %d has sold %d housing units at this round. \n", ID, total_sold);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int firm_housing_update_market_price()
 * \brief: The construction firm updated unit housing price based on
 * recieved average market price.
 */
int firm_housing_update_market_price()
{
    double oldprice;
    
    START_HOUSING_PRICE_MESSAGE_LOOP
    oldprice = UNIT_HOUSE_PRICE;
    UNIT_HOUSE_PRICE = housing_price_message->price;
    DELTA_HOUSING_PRICE = UNIT_HOUSE_PRICE - oldprice;
	FINISH_HOUSING_PRICE_MESSAGE_LOOP
	return 0; /* Returning zero means the agent is not removed */
}

