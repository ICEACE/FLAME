#include "../header.h"
#include "../government_agent_header.h"

/*
 * \fn: int government_trace_unemployment_status()
 * \brief: Government collects info from the population to keep trace
 * of average wages and number of households in the population.
 */
int government_trace_unemployment_status(){
    int unemployed = 0;
    double total_wages = 0;
    int total = 0;
    int id;
    START_EMPLOYMENT_STATUS_MESSAGE_LOOP
        id = employment_status_message->employer_id;
        if (id == 0) {
            unemployed++;
        }
        else{
            total_wages += employment_status_message->wage;
        }
        total++;
    FINISH_EMPLOYMENT_STATUS_MESSAGE_LOOP
    
    if (total == 0 || unemployed == total) {
        UNEMPLOYMENT_RATE = 1.0;
        AVERAGE_WAGE = 0;
    } else {
        UNEMPLOYMENT_RATE = (double) unemployed / total;
        AVERAGE_WAGE = total_wages / (total - unemployed);
    }
    POPULATION_SIZE = total;
    
    
	return 0; /* Returning zero means the agent is not removed */
}