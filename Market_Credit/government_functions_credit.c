#include "../header.h"
#include "../government_agent_header.h"



/*
 * \fn: int government_update_fiscal_policy()
 * \brief:
 */
int government_update_fiscal_policy()
{
    double balance;
    double dTax;
    double dBenefit;
    
    balance = LABOUR_TAX_INCOME + CAPITAL_TAX_INCOME;
    balance -= GENERAL_BENEFITS + UNEMPLOYMENT_BENEFITS;
    
    if (balance < 0) {
        dTax = RATIO_FISCAL_POLICY * 0.05;
        dBenefit = (1- RATIO_FISCAL_POLICY) * 0.05;
        GOV_TAX_RATE = GOV_TAX_RATE + dTax;
        GOV_GENERAL_BENEFIT_RATE = GOV_GENERAL_BENEFIT_RATE - dBenefit;
    }
    
    // The increment portion (0.05) and threshold below (500) is picked from the model description.
    // However, I suggest this be parameterized and be treated as one of policy parameters.
    if (balance > 500){
        dTax = (1 - RATIO_FISCAL_POLICY) * 0.05;
        dBenefit =  RATIO_FISCAL_POLICY * 0.05;
        GOV_TAX_RATE = GOV_TAX_RATE - dTax;
        GOV_GENERAL_BENEFIT_RATE = GOV_GENERAL_BENEFIT_RATE + dBenefit;
    }
    
    if (GOV_TAX_RATE > 0.5) {
        GOV_TAX_RATE = 0.5;
    }
    if (GOV_TAX_RATE < 0.1) {
        GOV_TAX_RATE = 0.1;
    }
    
    if (GOV_GENERAL_BENEFIT_RATE > 0.4){
        GOV_GENERAL_BENEFIT_RATE = 0.4;
    }
    
    if (GOV_GENERAL_BENEFIT_RATE < 0){
        GOV_GENERAL_BENEFIT_RATE = 0;
    }

    
    add_tax_rate_message(GOV_TAX_RATE);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int government_collect_capital_tax()
 * \brief: 
 */
int government_collect_capital_tax()
{
    double amount = 0;
    START_CAPITAL_TAX_MESSAGE_LOOP
    amount = capital_tax_message->amount;
    CAPITAL_TAX_INCOME += amount;
    LIQUIDITY += amount;
	FINISH_CAPITAL_TAX_MESSAGE_LOOP
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int government_do_balance_sheet()
 * \brief: Government does the balance sheet accounting.
 */
int government_do_balance_sheet()
{
    EQUITY = LIQUIDITY - DEBT;
    // These values can be kept longer to be able to implement
    // long term government fiscal policy decisons.
    CAPITAL_TAX_INCOME = 0;
    LABOUR_TAX_INCOME = 0;
    GENERAL_BENEFITS = 0;
    UNEMPLOYMENT_BENEFITS = 0;
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int government_collect_labour_tax()
 * \brief: Monthly collected labour tax.
 */
int government_collect_labour_tax()
{
    double amount = 0;
    START_LABOUR_TAX_MESSAGE_LOOP
    amount = labour_tax_message->amount;
    LABOUR_TAX_INCOME += amount;
    LIQUIDITY += amount;
	FINISH_LABOUR_TAX_MESSAGE_LOOP
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int government_distribute_general_benefits()
 * \brief: All households recieve equal amount of benefits.
 */
int government_distribute_general_benefits()
{
    double benefit = 0;
    double total_benefits;
    
    benefit = AVERAGE_WAGE * GOV_GENERAL_BENEFIT_RATE;
    add_general_benefit_message(benefit);
    total_benefits = benefit * POPULATION_SIZE;
    GENERAL_BENEFITS += total_benefits;
    LIQUIDITY -= total_benefits;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int government_distribute_unemployment_benefits()
 * \brief:
 */
int government_distribute_unemployment_benefits()
{
    double benefit = 0;
    double total_benefits;
    
    benefit = AVERAGE_WAGE * 0.5;
    add_unemployment_benefit_message(benefit);
    total_benefits = benefit * POPULATION_SIZE * UNEMPLOYMENT_RATE;
    UNEMPLOYMENT_BENEFITS += total_benefits;
    LIQUIDITY -= total_benefits;
    
	return 0; /* Returning zero means the agent is not removed */
}


