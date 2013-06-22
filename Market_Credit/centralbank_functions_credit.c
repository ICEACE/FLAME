#include "../header.h"
#include "../centralbank_agent_header.h"


/*
 * \fn: int centralbank_set_interest_rate()
 * \brief:
 */
int centralbank_set_interest_rate()
{


	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int centralbank_do_balance_sheet()
 * \brief: Central Bank does the balance sheet accounting.
 */
int centralbank_do_balance_sheet()
{
    double assets, liabilities;
    
    assets = LIQUIDITY + LOANS_BANKS + LOANS_GOVERNMENT;
    liabilities = FIAT_MONEY + LIQUIDITY_BANKS + LIQUIDITY_GOVERNMENT;
    EQUITY = assets - liabilities;
    
	return 0; /* Returning zero means the agent is not removed */
}
