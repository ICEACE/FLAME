#include "../header.h"
#include "../household_agent_header.h"

/*
 * \fn: int household_credit_check_interest_rate()
 * \brief: checks monthly interest rate and sets the mortgage interest rates
 */
int household_credit_check_interest_rate()
{

    START_INTEREST_RATE_MESSAGE_LOOP
    // 2 percent increase determined by the model.
    MORTGAGES_INTEREST_RATE = interest_rate_message->rate + 0.02;
    
	FINISH_INTEREST_RATE_MESSAGE_LOOP

	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_credit_check_tax_rate()
 * \brief:
 */
int household_credit_check_tax_rate()
{
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_credit_update_mortgage_rates()
 * \brief:
 */
int household_credit_update_mortgage_rates()
{
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_credit_collect_shares()
 * \brief: Collecting shares from the firms via Equity Fund.
 */
int household_credit_collect_shares()
{
    
    FUND_SHARES = 0;
    
    START_HOUSEHOLD_SHARE_MESSAGE_LOOP
    FUND_SHARES += DIVIDENDS * household_share_message->amount;
	FINISH_HOUSEHOLD_SHARE_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_credit_update_mortgage_rates()
 * \brief:
 */
int household_credit_pay_capital_tax()
{
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_credit_do_balance_sheet()
 * \brief:
 */
int household_credit_do_balance_sheet()
{
    double housing;
    double assets;
    
    // use a delta asset to be used to incorporate wealth effect on consumption.
    // Updating value of housing assets.
    housing = HOUSING_UNITS * HOUSING_PRICE;
    
    //Shares are liquidified.
    LIQUIDITY += FUND_SHARES;
    
    assets = LIQUIDITY +  housing;
    EQUITY = assets - MORTGAGES;
    
   
    
    
    //printf(" Household Id = %d, Equity %f \n", ID, EQUITY);
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_credit_collect_benefits()
 * \brief: Collect general transfer benefits from the government.
 */
int household_credit_collect_benefits()
{
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_credit_collect_unemployment()
 * \brief: Collect unemployment payment from the government.
 */
int household_credit_collect_unemployment()
{
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_credit_pay_labour_tax()
 * \brief: Pay tax on labour earnings.
 */
int household_credit_pay_labour_tax()
{
    
    
	return 0; /* Returning zero means the agent is not removed */
}

