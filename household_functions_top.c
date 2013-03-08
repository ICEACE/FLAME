#include "header.h"
#include "household_agent_header.h"

/*
 * \fn: int notifier
 * \brief: notifies its id by printing out agent id.
 */
int household_notifier()
{
    // Read from memory
	printf("Household Id: %d\n", ID);
    printf("    Bank = %d Employer= %d Position=%d Wage %f\n", BANK_ID, MY_EMPLOYER_ID, MY_JOB_POSITION, WAGE);

	return 0; /* Returning zero means the agent is not removed */
}

