#include "../header.h"
#include "../firm_agent_header.h"
#include "../library_header.h"
#include <math.h>

/*
 * \fn: int firm_export_import_rawmaterials()
 * \brief: Firm imports raw materialsr.
 */
int firm_export_import_rawmaterials()
{
    int amount;
    
    if (FIRMTYPE == 1) {
        int capital, labour;
    
        labour = (int) (NO_EMPLOYEES * LABOUR_PRODUCTIVITY);
        capital = (int) (CAPITAL_PRODUCTIVITY * CAPITAL_GOODS);
    
        /* Construction firms need 4000 units of raw material to advance one house one month forward*/
        amount = min_int(labour, capital)*4000;
    }
    else {
        /* Regular firms and  need 3 units of raw material to produce one unit of goods */
        amount = (int) (NO_EMPLOYEES * LABOUR_PRODUCTIVITY * 3);
    }
    RAWMATERIAL_COSTS = amount * UNIT_RAW_PRICE * EXCHANGE_RATE;
    LIQUIDITY -= RAWMATERIAL_COSTS;

    add_firm_foreignsector_rawmaterials_message(ID,amount);

    return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_export_import_capitalgoods()
 * \brief: Firm imports capital goods
 */
int firm_export_import_capitalgoods()
{
    int depreciated_cgoods;
    int amount;

    depreciated_cgoods = (int) (CAPITAL_GOODS * DEPRECIATION_RATE);
    amount = depreciated_cgoods + CAPITAL_GOODS_INVESTMENT;

    CGOODS_COSTS = amount * UNIT_CGOODS_PRICE * EXCHANGE_RATE;
    LIQUIDITY -= CGOODS_COSTS;

    add_firm_foreignsector_cgoods_message(ID,amount);
    
    return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int firm_export_sell()
 * \brief: Firm sells export goods to foreign sector.
 */
int firm_export_sell()
{
    SALES = INVENTORY;

    add_firm_foreignsector_xgoods_message(ID,SALES);

    INVENTORY = 0;
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int firm_export_sell()
 * \brief: A firm recieves sales revenues through the central bank.
 */
int firm_export_receive_sales()
{

    REVENUES = SALES * UNIT_XGOODS_PRICE * EXCHANGE_RATE;
    LIQUIDITY += REVENUES;
    //START_CENTRALBANK_FIRM_REVENUES_MESSAGE_LOOP
    //REVENUES += centralbank_firm_revenues_message->revenues;
    //LIQUIDITY += REVENUES; 
    //FINISH_CENTRALBANK_FIRM_REVENUES_MESSAGE_LOOP

    return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_export_check_pricesandrates()
 * \brief: Firm receives exchange rate from Central bank and prices from foreign sector.
 */
int firm_export_check_pricesandrates()
{

    START_FOREIGNSECTOR_FIRM_PRICES_MESSAGE_LOOP
    UNIT_XGOODS_PRICE = foreignsector_firm_prices_message->xgoods;
    UNIT_RAW_PRICE = foreignsector_firm_prices_message->rawmaterial;
    UNIT_CGOODS_PRICE = foreignsector_firm_prices_message->cgoods;
    FINISH_FOREIGNSECTOR_FIRM_PRICES_MESSAGE_LOOP

    START_CENTRALBANK_FIRM_EXCHANGERATE_MESSAGE_LOOP
    EXCHANGE_RATE = centralbank_firm_exchangerate_message->rate; 
    FINISH_CENTRALBANK_FIRM_EXCHANGERATE_MESSAGE_LOOP

    return 0; /* Returning zero means the agent is not removed */
}

