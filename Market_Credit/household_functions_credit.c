#include "../header.h"
#include "../household_agent_header.h"

/*
 * \fn: int household_credit_check_interest_rate()
 * \brief: Household hecks quarterly interest rate and
 * sets the mortgage interest rates accordingly.
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
    START_TAX_RATE_MESSAGE_LOOP
    TAX_RATE = tax_rate_message->value;
	FINISH_TAX_RATE_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_credit_update_mortgage_rates()
 * \brief:
 */
int household_credit_update_mortgage_rates()
{
    int size, i;
    mortgage mort;
    init_mortgage(&mort);
    double principle;
    int quarters_left;
    double new_quarterly_interest;
    double new_quarterly_principal;
    double annuity;
    double d1, d2;
    
    size = MORTGAGES_LIST.size;
    
    if (size == 0) {
        free_mortgage(&mort);
        return 0;
    }
    
    for (i = 0; i < size - 1; i++) {
        mort = MORTGAGES_LIST.array[i];
        principle = mort.principal;
        quarters_left = mort.quarters_left - 1;
        
        d1 = MORTGAGES_INTEREST_RATE/4;
        d2 = d1 * pow((1 + d1), quarters_left);
        annuity = 1/d1 - 1/d2;
        
        new_quarterly_interest = principle * d1;
        new_quarterly_principal = (principle / annuity) - new_quarterly_interest;
        
        add_mortgage(&MORTGAGES_LIST, BANK_ID, quarters_left, principle, new_quarterly_interest, new_quarterly_principal);
    }
    
    //updates above added to the array, code snippet below remove redundant entries. No in place mutation is done.
    for (i = 0; i < size - 1; i++) {
        remove_mortgage(&MORTGAGES_LIST, i);
    }
    
    free_mortgage(&mort);
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_credit_collect_shares()
 * \brief: Collecting shares from the firms via Equity Fund.
 */
int household_credit_collect_shares()
{
    double amount = 0;
    
    CAPITAL_INCOME = 0;
    
    START_HOUSEHOLD_SHARE_MESSAGE_LOOP
    amount = N_SHARES * household_share_message->amount;
    CAPITAL_INCOME += amount;
    //Shares are liquidified.
    LIQUIDITY += amount;
	FINISH_HOUSEHOLD_SHARE_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int household_credit_do_balance_sheet()
 * \brief:
 */
int household_credit_do_balance_sheet()
{
    double old_housing;
    
    old_housing = HOUSING_VALUE;

    // use a delta asset to be used to incorporate wealth effect on consumption.
    // Updating value of housing assets.
    HOUSING_VALUE = HOUSING_UNITS * HOUSING_PRICE;
    DELTA_HOUSING_VALUE = HOUSING_VALUE - old_housing;
    // do the same for total_assets, equity.
    
    //Liquidity contains fund shares the capital goods.
    
    TOTAL_ASSETS = LIQUIDITY +  HOUSING_VALUE;
    EQUITY = TOTAL_ASSETS - MORTGAGES;
    
    //printf(" Household Id = %d, Equity %f \n", ID, EQUITY);
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_credit_collect_benefits()
 * \brief: Collect general transfer benefits from the government.
 */
int household_credit_collect_benefits()
{
    double benefit = 0;
    
    START_GENERAL_BENEFIT_MESSAGE_LOOP
    benefit = general_benefit_message->amount;
    LIQUIDITY += benefit;
	FINISH_GENERAL_BENEFIT_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_credit_collect_unemployment()
 * \brief: Collect unemployment payment from the government.
 */
int household_credit_collect_unemployment()
{
    double benefit = 0;
    
    START_UNEMPLOYMENT_BENEFIT_MESSAGE_LOOP
    benefit = unemployment_benefit_message->amount;
    LIQUIDITY += benefit;
	FINISH_UNEMPLOYMENT_BENEFIT_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}


