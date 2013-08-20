#include "../header.h"
#include "../equityfund_agent_header.h"

/*
 * \fn: int equityfund_audit_dividends()
 * \brief: The funding agency collects number of shares.
 */
int equityfund_audit_dividends(){
    int dividends = 0;
   
    START_EMPLOYMENT_STATUS_MESSAGE_LOOP
        dividends += employment_status_message->ndividends;
    FINISH_EMPLOYMENT_STATUS_MESSAGE_LOOP
    N_DIVIDENDS = dividends;
	return 0; /* Returning zero means the agent is not removed */
}