#include "../header.h"
#include "../bank_agent_header.h"

/*
 * \fn: int bank_accounting_do_balance_sheet()
 * \brief: Bank does the balance sheet accounting.
 */
int bank_accounting_do_balance_sheet()
{
    double assets, liabilities;
    
    assets = LIQUIDITY + LOANS + MORTGAGES;
    liabilities = DEPOSITS + DEBT;
    EQUITY = assets - liabilities;
    
	return 0; /* Returning zero means the agent is not removed */
}

