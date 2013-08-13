#include "../header.h"
#include "../centralbank_agent_header.h"


/*
 * \fn: int centralbank_set_interest_rate()
 * \brief:
 */
int centralbank_set_interest_rate()
{
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
    
    double inflation, rcb;
    
    if (CONSUMPTION_GOODS_PRICES[0] == 0) {
        inflation = CONSUMPTION_GOODS_PRICES[11];
    }
    else {
    inflation = (CONSUMPTION_GOODS_PRICES[11] - CONSUMPTION_GOODS_PRICES[0]) / CONSUMPTION_GOODS_PRICES[0];
    }
    
    // Taylors Rule:
    rcb = inflation;
    rcb += (inflation - INFLATION_TARGET) / 2;
    rcb -=  UNEMPLOYMENT_RATE / 2;
    
    if (rcb < 0.005){ rcb = 0.005;}
    
    add_interest_rate_message(rcb);

	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int centralbank_process_debt_requests()
 * \brief: Central Bank handles each bank debt request.
 */
int centralbank_process_debt_requests()
{
    double request;
    int id;
    
    START_DEBT_REQUEST_MESSAGE_LOOP
    request = debt_request_message->amount;
    id = debt_request_message->bank_id;
    LOANS_BANKS += request;
    LIQUIDITY -= request;
    add_debt_ack_message(id, request);
    FINISH_DEBT_REQUEST_MESSAGE_LOOP

    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int centralbank_do_balance_sheet()
 * \brief: Central Bank does the balance sheet accounting.
 */
int centralbank_do_balance_sheet()
{
    double assets, liabilities;
    
    assets = LIQUIDITY + LOANS_BANKS + LOANS_GOVERNMENT;
    liabilities = FIAT_MONEY + LIQUIDITY_BANKS + LIQUIDITY_GOVERNMENT;
    EQUITY = assets - liabilities;
    
	return 0; /* Returning zero means the agent is not removed */
}
