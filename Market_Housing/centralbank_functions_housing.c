#include "../header.h"
#include "../centralbank_agent_header.h"


/*
 * \fn: int centralbank_trace_housing_prices()
 * \brief:
 */
int centralbank_trace_housing_prices()
{
    START_HOUSING_TRANSACTIONS_SUMMARY_MESSAGE_LOOP
    HOUSES.quantity = housing_transactions_summary_message->quantity;
    HOUSES.avg_price = housing_transactions_summary_message->avg_price;
	FINISH_HOUSING_TRANSACTIONS_SUMMARY_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

