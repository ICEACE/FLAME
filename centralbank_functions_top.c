#include "header.h"
#include "CentralBank_agent_header.h"

/*
 * \fn: int notifier
 * \brief: notifies its id by printing out agent id.
 */
int centralbank_notifier()
{
	// Read from memory
	printf("Central Bank Id = %d\n", ID);

	return 0; /* Returning zero means the agent is not removed */
}

