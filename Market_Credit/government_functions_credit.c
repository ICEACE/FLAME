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
        LABOUR_TAX_RATE = LABOUR_TAX_RATE + dTax;
        CAPITAL_TAX_RATE = CAPITAL_TAX_RATE + dTax;
        GOV_GENERAL_BENEFIT_RATE = GOV_GENERAL_BENEFIT_RATE - dBenefit;
    }
    
    // The increment portion (0.05) and threshold below (500) is picked from the model description.
    // However, I suggest this be parameterized and be treated as one of policy parameters. bulent.
    if (balance > 500){
        dTax = (1 - RATIO_FISCAL_POLICY) * 0.05;
        dBenefit =  RATIO_FISCAL_POLICY * 0.05;
        LABOUR_TAX_RATE = LABOUR_TAX_RATE - dTax;
        CAPITAL_TAX_RATE = CAPITAL_TAX_RATE - dTax;
        GOV_GENERAL_BENEFIT_RATE = GOV_GENERAL_BENEFIT_RATE + dBenefit;
    }
    
    if (CAPITAL_TAX_RATE > 0.5) {
        CAPITAL_TAX_RATE = 0.5;
    }
    if (CAPITAL_TAX_RATE < 0.1) {
        CAPITAL_TAX_RATE = 0.1;
    }
    
    if (LABOUR_TAX_RATE > 0.5) {
        LABOUR_TAX_RATE = 0.5;
    }
    if (LABOUR_TAX_RATE < 0.1) {
        LABOUR_TAX_RATE = 0.1;
    }
    
    if (GOV_GENERAL_BENEFIT_RATE > 0.4){
        GOV_GENERAL_BENEFIT_RATE = 0.4;
    }
    
    if (GOV_GENERAL_BENEFIT_RATE < 0){
        GOV_GENERAL_BENEFIT_RATE = 0;
    }

    
    add_labour_tax_rate_message(LABOUR_TAX_RATE);
    add_capital_tax_rate_message(CAPITAL_TAX_RATE);
    
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
 * \fn: int government_collect_centralbank_profit()
 * \brief:
 */
int government_collect_centralbank_profit()
{
    double amount = 0;
    
    START_CENTRALBANK_GOVERNMENT_PROFIT_MESSAGE_LOOP
    amount = centralbank_government_profit_message->amount;
    CENTRALBANK_INCOME += amount;
    LIQUIDITY += amount;
	FINISH_CENTRALBANK_GOVERNMENT_PROFIT_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int government_compute_income_statement()
 * \brief: Government computes income statement.
 */
int government_compute_income_statement()
{
    EARNINGS = CAPITAL_TAX_INCOME + LABOUR_TAX_INCOME + CENTRALBANK_INCOME;
    EXPENDITURES = UNEMPLOYMENT_BENEFITS + GENERAL_BENEFITS;
    
    if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/Government_snapshot.txt");
        
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %f %f %f %f %f %f %f %f %f %f %f\n",IT_NO, UNEMPLOYMENT_RATE, LABOUR_TAX_RATE, CAPITAL_TAX_RATE, GOV_GENERAL_BENEFIT_RATE, LABOUR_TAX_INCOME,  CAPITAL_TAX_INCOME, CENTRALBANK_INCOME, UNEMPLOYMENT_BENEFITS, GENERAL_BENEFITS, LIQUIDITY, DEBT);
        fclose(file1);
        free(filename);
    }
    
    /* These values can be kept longer to be able to implement long term government fiscal policy decisons.
     */
    CAPITAL_TAX_INCOME = 0;
    LABOUR_TAX_INCOME = 0;
    GENERAL_BENEFITS = 0;
    UNEMPLOYMENT_BENEFITS = 0;
    CENTRALBANK_INCOME = 0;
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int government_do_balance_sheet()
 * \brief: Government does the balance sheet accounting.
 */
int government_do_balance_sheet()
{
    EQUITY = LIQUIDITY - DEBT;
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


