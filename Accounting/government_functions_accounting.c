#include "../header.h"
#include "../government_agent_header.h"

/*
 * \fn: int government_accounting_do_balance_sheet()
 * \brief: Government does the balance sheet accounting.
 */
int government_accounting_do_balance_sheet()
{
    EQUITY = LIQUIDITY - DEBT;
    
	return 0; /* Returning zero means the agent is not removed */
}

