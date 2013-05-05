#include "../header.h"
#include "../household_agent_header.h"

/*
 * \fn: int household_accounting_collect_shares()
 * \brief: Collecting shares from the firms via Equity Fund.
 */
int household_accounting_collect_shares()
{
    
    FUND_SHARES = 0;
    
    START_HOUSEHOLD_SHARE_MESSAGE_LOOP
    FUND_SHARES += DIVIDENDS * household_share_message->amount;
	FINISH_HOUSEHOLD_SHARE_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int household_accounting_do_balance_sheet()
 * \brief:
 */
int household_accounting_do_balance_sheet()
{
    double housing;
    double assets;
    
    // Updating value of housing assets.
    housing = HOUSING_UNITS * HOUSING_PRICE;
    
    assets = LIQUIDITY + FUND_SHARES + housing;
    EQUITY = assets - MORTGAGES;
    
    //Shares are liquidified.
    LIQUIDITY += FUND_SHARES;
    
    
    //printf(" Household Id = %d, Equity %f \n", ID, EQUITY);
    
        
	return 0; /* Returning zero means the agent is not removed */
}

