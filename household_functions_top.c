#include "header.h"
#include "household_agent_header.h"

/*
 * \fn: int household_init()
 * \brief: notifies its id by printing out agent id.
 */
int household_init()
{
    // Read from memory
	//printf(("Household Id: %d\n", ID);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_update_bank_account()
 * \brief: puts money to deposit account of its prefered bak. */
int household_update_bank_account()
{
    if (LIQUIDITY > 0) {
        add_household_bank_update_deposit_message(BANK_ID, LIQUIDITY);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}