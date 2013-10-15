#include "../header.h"
#include "../reagency_agent_header.h"

/*
 * \fn: int reagency_check_interest_rate()
 * \brief:
 */
int reagency_check_interest_rate()
{
    
    START_INTEREST_RATE_MESSAGE_LOOP
    MORTGAGES_INTEREST_RATE = interest_rate_message->rate + 0.02;
	FINISH_INTEREST_RATE_MESSAGE_LOOP
    
    
	return 0; /* Returning zero means the agent is not removed */
}



