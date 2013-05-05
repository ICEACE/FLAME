#include "../header.h"
#include "../equityfund_agent_header.h"


/*
 * \fn: int equityfund_accounting_collect_firm_shares()
 * \brief: Within this implementation the equity fund receives all of net income
 * to be distributed equally to households.
 */
int equityfund_accounting_collect_firm_shares()
{
    START_FIRM_NET_PROFIT_MESSAGE_LOOP
    if (firm_net_profit_message->isconstructor == 1) {
        SHARE_CONSTRUCTION_FIRMS += firm_net_profit_message->net_income;
    } else {
        SHARE_FIRMS += firm_net_profit_message->net_income;
    }
	FINISH_FIRM_NET_PROFIT_MESSAGE_LOOP
    
    // Net incomes are liquidified right away to be distributed to households.
    LIQUIDITY = SHARE_CONSTRUCTION_FIRMS + SHARE_FIRMS;
    SHARE_CONSTRUCTION_FIRMS = 0;
    SHARE_FIRMS = 0;
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int equityfund_accounting_distribute_shares()
 * \brief:Equity fund sends out shares to households.
 */
int equityfund_accounting_distribute_shares()
{
    double per_house;
    
    per_house = LIQUIDITY / N_DIVIDENDS;
    
    add_household_share_message(per_house);
    
    LIQUIDITY = 0;
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int equityfund_accounting_do_balance_sheet()
 * \brief: Equity Fund does the balance sheet accounting.
 */
int equityfund_accounting_do_balance_sheet()
{
    EQUITY = LIQUIDITY + SHARE_FIRMS + SHARE_CONSTRUCTION_FIRMS + SHARE_BANKS;
    
     ////printf(" Equity Fund Id = %d, Equity %f \n", ID, EQUITY);
    
	return 0; /* Returning zero means the agent is not removed */
}


