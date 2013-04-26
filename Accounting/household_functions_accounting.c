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
    FUND_SHARES += household_share_message->amount;
	FINISH_HOUSEHOLD_SHARE_MESSAGE_LOOP

	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_accounting_compute_net_income()
 * \brief:
 */
int household_accounting_compute_net_income()
{
    double labour_income;
    
    labour_income = PREVIOUS_WAGES[0]+PREVIOUS_WAGES[1]+PREVIOUS_WAGES[2];
    
    NET_INCOME = labour_income + FUND_SHARES - HOUSING_PAYMENT;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_accounting_wealth_effect()
 * \brief:
 */
int household_accounting_wealth_effect()
{
    double dX;
    double change;
    
    // dX = w * (X(t-1) - X(t))
    dX = TOTAL_ASSETS - HOUSING_UNITS * HOUSING_PRICE;
    dX = WEALTH_EFFECT * dX;
    
    change = 0.1 * (LIQUIDITY - dX);
    
    if (LIQUIDITY <= NET_INCOME) {
        change = -1 * change;
    }
    
    WEEKLY_CONSUMPTION_BUDGET = (NET_INCOME + change + dX) / 12;
    
    // Updating value of housing assets.
    TOTAL_ASSETS = HOUSING_UNITS * HOUSING_PRICE;
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int household_accounting_do_balance_sheet()
 * \brief:
 */
int household_accounting_do_balance_sheet()
{
    double assets;
    
    //Shares are liquidified.
    LIQUIDITY += FUND_SHARES - HOUSING_PAYMENT;
    assets = LIQUIDITY + TOTAL_ASSETS;
    
    EQUITY = assets - MORTGAGES;
    
    printf(" Household Id = %d, Equity %f \n", ID, EQUITY);
    
        
	return 0; /* Returning zero means the agent is not removed */
}

