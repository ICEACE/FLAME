#include "../header.h"
#include "../foreignsector_agent_header.h"


/*
 * \fn: int foreignsector_consumption_buy_goods()
 * \brief: Foreign sector consumption of locally produced goods.
 */
int foreignsector_consumption_buy_goods()
{
    
    START_CENTRALBANK_FOREIGNSECTOR_GOODS_MESSAGE_LOOP
    EXPORTS += centralbank_foreignsector_goods_message->fx_revenues
    FINISH_CENTRALBANK_FOREIGNSECTOR_GOODS_MESSAGE_LOOP

	return 0; /* Returning zero means the agent is not removed */
}