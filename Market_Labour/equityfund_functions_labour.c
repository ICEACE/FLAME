#include "../header.h"
#include "../equityfund_agent_header.h"

/*
 * \fn: int equityfund_audit_dividends()
 * \brief: The funding agency collects number of shares.
 */
int equityfund_audit_dividends(){
    int shares = 0;
   
    START_EMPLOYMENT_STATUS_MESSAGE_LOOP
    shares += employment_status_message->nshares;
    FINISH_EMPLOYMENT_STATUS_MESSAGE_LOOP
    N_SHARES = shares;
	return 0; /* Returning zero means the agent is not removed */
}