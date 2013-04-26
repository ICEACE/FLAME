#include "../header.h"
#include "../firm_agent_header.h"

/*
 * \fn: int firm_accounting_distribute_net_income()
 * \brief: Within this implementation the firm sends all of net income
 * to the Fund Equity to be distributed equally to households.
 */ 
int firm_accounting_distribute_net_income()
{
    double net_income;
    
    //Labour cost is decremented from liquidity on a monthly basis.
    
    net_income = LIQUIDITY - COSTS;
    
    // In case net income is negative, households will end loosing capital(?).
    add_firm_net_income_message(ID, ISCONSTRUCTOR, net_income);
    
    //Check this with production market.
    LIQUIDITY = 0;
    COSTS = 0;

	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_accounting_do_balance_sheet()
 * \brief: Firm does the balance sheet accounting.
 */
int firm_accounting_do_balance_sheet()
{
    double assets;
    
    assets = INVENTORY * PRICE_UNIT_PRODUCT;
    assets += LIQUIDITY + CAPITAL_GOODS;
    EQUITY = assets - DEBT;
    
    printf(" Firm Id = %d, Equity %f \n", ID, EQUITY);
    
	return 0; /* Returning zero means the agent is not removed */
}

