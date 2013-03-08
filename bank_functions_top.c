#include "header.h"
#include "bank_agent_header.h"

/*
 * \fn: int notifier
 * \brief: notifies its id by printing out agent id.
 */
int bank_notifier()
{
	// Read from memory
	printf("Bank Id = %d\n", ID);

	return 0; /* Returning zero means the agent is not removed */
}

