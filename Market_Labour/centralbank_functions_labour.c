#include "../header.h"
#include "../centralbank_agent_header.h"

/*
 * \fn: int centralbank_trace_unemployment_status()
 * \brief:
 */
int centralbank_trace_unemployment_status(){
    int unemployed = 0;
    double total = 0;
    int id;
    START_EMPLOYMENT_STATUS_MESSAGE_LOOP
        id = employment_status_message->employer_id;
        if (id == 0) {unemployed++;}
        total++;
    FINISH_EMPLOYMENT_STATUS_MESSAGE_LOOP
    if (total == 0) {
        UNEMPLOYMENT_RATE = 0;
    } else {
        UNEMPLOYMENT_RATE = unemployed / total;
    }
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int centralbank_trace_unemployment_status()
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
    
    for(i = 11; i > 0; i--){
        CONSUMPTION_GOODS_PRICES[i] = CONSUMPTION_GOODS_PRICES[i-1];
    }
    CONSUMPTION_GOODS_PRICES[0] = price_avg;

	return 0; /* Returning zero means the agent is not removed */
}