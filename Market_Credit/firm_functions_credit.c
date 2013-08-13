#include "../header.h"
#include "../firm_agent_header.h"

/*
 * \fn: int firm_credit_check_interest_rate()
 * \brief: it receives interest rate from the central bank and updates interest to be paid on loans.
 */
int firm_credit_check_interest_rate()
{
    double rcb;
    START_INTEREST_RATE_MESSAGE_LOOP
    // 1 percent increase determined by the model.
    rcb = interest_rate_message->rate;
    LOANS_INTEREST_RATE = rcb + 0.01;
    
	FINISH_INTEREST_RATE_MESSAGE_LOOP
        
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_check_liquidity_need()
 * \brief: 
 */
int firm_credit_check_liquidity_need()
{
    /* Compute LIQUIDTY_NEED
     Compute/check EQUITY.
     It maybe possible that it is needed to decrement the loans and dividends to be paid within the current quarter to compute the equity
     */
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_demand_loans_1()
 * \brief:
 */
int firm_credit_demand_loans_1()
{
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_borrow_loans_1()
 * \brief:
 */
int firm_credit_borrow_loans_1()
{
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_borrow_loans_2()
 * \brief:
 */
int firm_credit_borrow_loans_2()
{
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_check_illiquidity()
 * \brief:
 */
int firm_credit_check_illiquidity()
{
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_exit_market()
 * \brief:
 */
int firm_credit_exit_market()
{
    
    // The firm will skip production for the first time and enters the labour market.
    ISINSOLVENT = 1;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_credit_distribute_net_profit ()
 * \brief: Within this implementation the firm sends all of net income
 * to the Fund Equity to be distributed equally to households.
 */
int firm_credit_distribute_net_profit()
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
 * \fn: int firm_credit_pay_interest_on_loans()
 * \brief:
 */
int firm_credit_pay_interest_on_loans()
{

 	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int firm_credit_do_balance_sheet()
 * \brief: Firm does the balance sheet accounting.
 */
int firm_credit_do_balance_sheet()
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


