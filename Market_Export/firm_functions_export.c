#include "../header.h"
#include "../firm_agent_header.h"
#include "../library_header.h"
#include <math.h>

/*
 * \fn: int firm_export_sell()
 * \brief: Firm sells export goods to foreign sector.
 */
int firm_export_sell()
{
    SALES = INVENTORY;

    add_firm_foreignsector_amount_message(ID,SALES);

    INVENTORY = 0;
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int firm_export_sell()
 * \brief: A firm recieves sales revenues through the central bank.
 */
int firm_export_receive_sales()
{
    START_CENTRALBANK_FIRM_REVENUES_MESSAGE_LOOP
    REVENUES += centralbank_firm_revenues_message->revenues;
    LIQUIDITY += REVENUES; 
    FINISH_CENTRALBANK_FIRM_REVENUES_MESSAGE_LOOP

    return 0; /* Returning zero means the agent is not removed */
}