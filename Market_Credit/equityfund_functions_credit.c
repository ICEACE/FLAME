#include "../header.h"
#include "../equityfund_agent_header.h"

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
    DIVIDENDS_RECIEVED += producers + constructors;
    
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
    DIVIDENDS_RECIEVED += shares;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int equityfund_credit_distribute_shares()
 * \brief:Equity fund sends out shares to households.
 */
int equityfund_credit_distribute_shares()
{
    double per_share;
    
    if (FIRM_INVESTMENT > 0) {
        DIVIDENDS_RETAINED = FIRM_INVESTMENT;
    } else {
        DIVIDENDS_RETAINED = 0;
    }
    
    DIVIDENDS_PAID = DIVIDENDS_RECIEVED - DIVIDENDS_RETAINED;
    
    if (N_DIVIDENDS > 0) {
        per_share = DIVIDENDS_PAID / N_DIVIDENDS;
    }
    else {
        per_share = DIVIDENDS_PAID / 8000;
    }
    
    LIQUIDITY -= DIVIDENDS_PAID;
    
    add_household_share_message(per_share);
    
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


