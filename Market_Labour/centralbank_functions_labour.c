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
        UNEMPLOYMENT_RATE = 1.0;
    } else {
        UNEMPLOYMENT_RATE = unemployed / total;
    }
	return 0; /* Returning zero means the agent is not removed */
}