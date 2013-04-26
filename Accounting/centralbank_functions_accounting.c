#include "../header.h"
#include "../centralbank_agent_header.h"

/*
 * \fn: int centralbank_accounting_do_balance_sheet()
 * \brief: Central Bank does the balance sheet accounting.
 */
int centralbank_accounting_do_balance_sheet()
{
    double assets, liabilities;
    
    assets = LIQUIDITY + LOANS_BANKS + LOANS_GOVERNMENT;
    liabilities = FIAT_MONEY + LIQUIDITY_BANKS + LIQUIDITY_GOVERNMENT;
    EQUITY = assets - liabilities;
    
	return 0; /* Returning zero means the agent is not removed */
}
