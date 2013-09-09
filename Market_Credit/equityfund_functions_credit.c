#include "../header.h"
#include "../equityfund_agent_header.h"


/*
 * \fn: int equityfund_credit_check_tax_rate()
 * \brief: Recieved from the government.
 */
int equityfund_credit_check_tax_rate()
{
    
    START_TAX_RATE_MESSAGE_LOOP
    TAX_RATE = tax_rate_message->value;
	FINISH_TAX_RATE_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: equityfund_credit_invest_illiquids()
 * \brief: Equity Fund recieves investement request. Firms send request when they need 
 * liquidity.
 */
int equityfund_credit_invest_illiquids()
{
    double request;
    int firm_id;
    
    START_FUND_REQUEST_MESSAGE_LOOP
    request = fund_request_message->amount;
    firm_id = fund_request_message->firm_id;
    if (LIQUIDITY > request) {
        add_fund_request_ack_message(firm_id, request);
        LIQUIDITY -= request;
        FIRM_INVESTMENT += request;
    }
    FINISH_FUND_REQUEST_MESSAGE_LOOP
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int equityfund_credit_distribute_shares()
 * \brief:Equity fund sends out shares to households.
 */
int equityfund_credit_distribute_shares()
{
    double per_share = 0;
    
    DIVIDENDS_PAID = DIVIDENDS_RECIEVED - FIRM_INVESTMENT;
    
    if (DIVIDENDS_PAID < 0) {
        DIVIDENDS_PAID = 0;
        add_household_share_message(per_share);
        add_capital_tax_message(DIVIDENDS_PAID * TAX_RATE);
        
        return 0;
    }
    
    if (N_SHARES > 0) {
        per_share = DIVIDENDS_PAID / N_SHARES;
        LIQUIDITY -= DIVIDENDS_PAID;
        per_share -= per_share * TAX_RATE;
    }
    else{
        per_share = 0;
        DIVIDENDS_PAID = 0;
    }
    add_household_share_message(per_share);
    add_capital_tax_message(DIVIDENDS_PAID * TAX_RATE);
    
	return 0; /* Returning zero means the agent is not removed */
}



/*
 * \fn: int equityfund_credit_collect_firm_shares()
 * \brief: Within this implementation the equity fund receives all of net income
 * to be distributed equally to households.
 */
int equityfund_credit_collect_firm_shares()
{
    double producers = 0;
    double constructors = 0;
    
    START_FIRM_NET_PROFIT_MESSAGE_LOOP
    if (firm_net_profit_message->isconstructor == 1) {
         constructors = firm_net_profit_message->net_income;
    } else {
        producers = firm_net_profit_message->net_income;
    }
	FINISH_FIRM_NET_PROFIT_MESSAGE_LOOP
    
    SHARE_FIRMS += producers;
    SHARE_CONSTRUCTION_FIRMS += constructors;
    LIQUIDITY += producers + constructors;
        
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int equityfund_credit_collect_bank_shares()
 * \brief: Within this implementation the equity fund receives all of net income
 * to be distributed equally to households.
 */
int equityfund_credit_collect_bank_shares()
{
    double shares = 0;
       
    START_BANK_NET_PROFIT_MESSAGE_LOOP
    shares = bank_net_profit_message->net_income;
	FINISH_BANK_NET_PROFIT_MESSAGE_LOOP

    SHARE_BANKS += shares;
    LIQUIDITY += shares;
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int eqyuityfund_compute_income_statement()
 * \brief: fund computes the income statement.
 */
int equityfund_compute_income_statement()
{
    DIVIDENDS_RECIEVED = SHARE_BANKS + SHARE_FIRMS + SHARE_CONSTRUCTION_FIRMS;
    DIVIDENDS_RETAINED = FIRM_INVESTMENT;
    //DIVIDENDS_PAID is computed while shares are sent to fund.
    
    SHARE_CONSTRUCTION_FIRMS = 0;
    SHARE_FIRMS = 0;
    SHARE_BANKS = 0;
    FIRM_INVESTMENT = 0;
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int equityfund_credit_do_balance_sheet()
 * \brief: Equity Fund does the balance sheet accounting.
 */
int equityfund_credit_do_balance_sheet()
{
    EQUITY = LIQUIDITY ;
    
     ////printf(" Equity Fund Id = %d, Equity %f \n", ID, EQUITY);
	return 0; /* Returning zero means the agent is not removed */
}


