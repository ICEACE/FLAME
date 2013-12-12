#include "../header.h"
#include "../centralbank_agent_header.h"


/*
 * \fn: int centralbank_trace_goods_prices()
 * \brief:
 */
int centralbank_trace_goods_prices()
{
    START_GOODS_TRANSACTIONS_SUMMARY_MESSAGE_LOOP
    GOODS.quantity = goods_transactions_summary_message->quantity;
    GOODS.avg_price = goods_transactions_summary_message->avg_price;
	FINISH_GOODS_TRANSACTIONS_SUMMARY_MESSAGE_LOOP

    for (int i = 0; i < 3; i++) {
        WEEKLY_PRICE_AVERAGES[i] = WEEKLY_PRICE_AVERAGES[i+1];
    }
    WEEKLY_PRICE_AVERAGES[3] = GOODS.avg_price;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int centralbank_update_price_indices()()
 * \brief: The function updates monthly consumption goods prices.
 */
int centralbank_update_price_indices(){
    double price_avg, prices;
    int i;
    
    prices = 0;
    for(i = 0; i < 4; i++){
        prices += WEEKLY_PRICE_AVERAGES[i];
    }
    price_avg = prices / 4;
    
    for(i = 0; i < 11; i++){
        CONSUMPTION_GOODS_PRICES[i] = CONSUMPTION_GOODS_PRICES[i+1];
    }
    CONSUMPTION_GOODS_PRICES[11] = price_avg;
    
	return 0; /* Returning zero means the agent is not removed */
}