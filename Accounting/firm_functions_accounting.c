#include "../header.h"
#include "../firm_agent_header.h"

/*
 * \fn: int firm_accounting_distribute_net_profit ()
 * \brief: Within this implementation the firm sends all of net income
 * to the Fund Equity to be distributed equally to households.
 */ 
int firm_accounting_distribute_net_profit()
{
    double net_profit;
    
    // Labour cost is decremented from liquidity on a monthly basis.
    // Cost and revenue are updated incrementally.
    
    net_profit = REVENUE - COSTS;
    
    // In case net income is positive it is sent to be distributed.
    if (net_profit > 0) {
        add_firm_net_profit_message(ID, ISCONSTRUCTOR, net_profit);
        //Check this with production market.
        REVENUE = 0;
        COSTS = 0;
        // The amount sent is decremented from liquidity
        LIQUIDITY -= net_profit;
    }
    
    //printf(" Firm Id = %d, Net Profit %f \n", ID, net_profit);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_accounting_do_balance_sheet()
 * \brief: Firm does the balance sheet accounting.
 */
int firm_accounting_do_balance_sheet()
{
    double assets;
    
    if (ISCONSTRUCTOR == 1) {
        assets = INVENTORY * UNIT_HOUSE_PRICE;
        assets += LIQUIDITY + CAPITAL_CONSTRUCTION;
    } else {
        assets = INVENTORY * UNIT_GOODS_PRICE;
        assets += LIQUIDITY + CAPITAL_GOODS;
    }
    
    EQUITY = assets - DEBT;
    
    //printf(" Firm Id = %d, Equity %f \n", ID, EQUITY);
    
	return 0; /* Returning zero means the agent is not removed */
}

