#include "../header.h"
#include "../foreignsector_agent_header.h"
#include "../library_header.h"
#include <math.h>


/*
 * \fn: int foreignsector_export_sell_rawmaterials()
 * \brief: Foreign sector sells raw materials to firms.
 */
int foreignsector_export_sell_rawmaterials()
{   
   

    return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int foreignsector_export_sell_capitalgoods()
 * \brief: Foreign sector sells capital goods to firms.
 */
int foreignsector_export_sell_capitalgoods()
{   
   

    return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int foreignsector_export_buy()
 * \brief: foreign sector buys export goods from export firms
 */
int foreignsector_export_buy()
{	
	int amount, id;

	START_FIRM_FOREIGNSECTOR_XGOODS_MESSAGE_LOOP
    amount = firm_foreignsector_xgoods_message->amount;
    id = firm_foreignsector_xgoods_message->id;
    add_xtransaction(&EXPORT_LIST,id,amount);
 	FINISH_FIRM_FOREIGNSECTOR_XGOODS_MESSAGE_LOOP

	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int foreignsector_export_pay()
 * \brief: foreign sector payment for export goods from export firms to central bank
 */
int foreignsector_export_pay()
{
	double payment;
	int id;
	for (int i = 0; i < EXPORT_LIST.size; i++) {
        payment = EXPORT_LIST.array[i].amount*UNIT_XGOODS_PRICE;
        id = EXPORT_LIST.array[i].id;
        add_foreignsector_centralbank_revenues_message(id,payment);
        EXPORTS += payment;
    }
    
    int size = EXPORT_LIST.size;
    while (size > 0) {
    remove_xtransaction(&EXPORT_LIST,0);
        size = EXPORT_LIST.size;
    }
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int foreignsector_set_prices()
 * \brief: Foreign sector sets prices
 */
int foreignsector_set_prices()
{
    double delta_price, price_change_range;
    /* the price range for export goods is fixed in time, currency exchange rate will however change in time */
    price_change_range = 0.0006*EXPORT_PRICE_CHANGE_RATE;
    delta_price = (((double)random_int(-100, 100)) / 100.0)*price_change_range;
    UNIT_XGOODS_PRICE = UNIT_XGOODS_PRICE + delta_price;

    return 0; /* Returning zero means the agent is not removed */
}