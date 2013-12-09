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
    /* 2 percent increase determined by the model. */
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
    START_LABOUR_TAX_RATE_MESSAGE_LOOP
    LABOUR_TAX_RATE = labour_tax_rate_message->value;
	FINISH_LABOUR_TAX_RATE_MESSAGE_LOOP
    
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
    double principal;
    
    size = MORTGAGES_LIST.size;
    i = 0;
    while (i < size) {
        mort = MORTGAGES_LIST.array[i];
        principal = mort.principal;
        
        if (principal < 0.1) {
            remove_mortgage(&MORTGAGES_LIST, i);
            size--;
            continue;
        }
        
        if (mort.quarters_left == 0){
            if (principal >= 0.1) {
                MORTGAGES_LIST.array[i].quarters_left = 1;
                if (WARNING_MODE) {
                    printf("Warning @household_credit_update_mortgage_rates(): Mortgage life is over but the debt is not finished! Household = %d, The mortgage = %f\n", ID, principal);
                }
            }
            else{
                remove_mortgage(&MORTGAGES_LIST, i);
                size--;
                continue;
            }
        }
        
        i++;
    }
    
    if (size == 0) {
        free_mortgage(&mort);
        return 0;
    }
    
    int quarters_left;
    double new_quarterly_interest;
    double new_quarterly_principal;
    double annuity;
    double d1, d2;

    
    EXPECTED_HOUSING_PAYMENT = 0;
    for (i = 0; i < size; i++) {
        mort = MORTGAGES_LIST.array[i];
        principal = mort.principal;
        quarters_left = mort.quarters_left - 1;
        
        d1 = MORTGAGES_INTEREST_RATE/4;
        d2 = d1 * pow((1 + d1), quarters_left);
        annuity = 1/d1 - 1/d2;
        
        new_quarterly_interest = principal * d1;
        new_quarterly_principal = (principal / annuity) - new_quarterly_interest;
        
        MORTGAGES_LIST.array[i].quarters_left = quarters_left;
        MORTGAGES_LIST.array[i].quarterly_interest = new_quarterly_interest;
        MORTGAGES_LIST.array[i].quarterly_principal = new_quarterly_principal;
        
        EXPECTED_HOUSING_PAYMENT += new_quarterly_interest + new_quarterly_principal;
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
    
    CAPITAL_INCOME = 0;
    
    START_HOUSEHOLD_SHARE_MESSAGE_LOOP
    CAPITAL_INCOME += N_SHARES * household_share_message->amount;
	FINISH_HOUSEHOLD_SHARE_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int household_credit_do_balance_sheet()
 * \brief:
 */
int household_credit_do_balance_sheet()
{
    /* Updating value of housing assets.
     It is up to date. Update is done monthly.
     */
    // HOUSING_VALUE = HOUSING_UNITS * HOUSING_PRICE;
    
    /* Liquidity contains labour incomes. */
    TOTAL_ASSETS = LIQUIDITY +  HOUSING_VALUE + CAPITAL_INCOME;
    EQUITY = TOTAL_ASSETS - MORTGAGES;

    if (DATA_COLLECTION_MODE && COLLECT_HOUSEHOLD_DATA) {
        char * filename;
        FILE * file1;
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/Household_Quarterly.txt");
        
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %d %f %f %f %f %f %f %f %f %f\n",IT_NO, ID, TOTAL_ASSETS, LIQUIDITY, HOUSING_VALUE, LABOUR_INCOME, GOVERNMENT_BENEFITS, CAPITAL_INCOME, MORTGAGES, HOUSING_PAYMENT, EQUITY);
        fclose(file1);
        free(filename);
    }
    
    /* Shares are liquidified. */
    LIQUIDITY += CAPITAL_INCOME;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_credit_collect_benefits()
 * \brief: Collect general transfer benefits and/or unemployment benefits from the government.
 */
int household_credit_collect_benefits()
{
    double general_benefit = 0;
    
    START_GENERAL_BENEFIT_MESSAGE_LOOP
    general_benefit = general_benefit_message->amount;
    LIQUIDITY += general_benefit;
    GOVERNMENT_BENEFITS = general_benefit;
	FINISH_GENERAL_BENEFIT_MESSAGE_LOOP

    double unemployment_benefit = 0;
    
    if (MY_EMPLOYER_ID == 0) {
        START_UNEMPLOYMENT_BENEFIT_MESSAGE_LOOP
        unemployment_benefit = unemployment_benefit_message->amount;
        LIQUIDITY += unemployment_benefit;
        GOVERNMENT_BENEFITS += unemployment_benefit;
        FINISH_UNEMPLOYMENT_BENEFIT_MESSAGE_LOOP
    }
    
    /* Updating history of benefits */
    PREVIOUS_BENEFITS[2] = PREVIOUS_BENEFITS[1];
    PREVIOUS_BENEFITS[1] = PREVIOUS_BENEFITS[0];
    PREVIOUS_BENEFITS[0] = GOVERNMENT_BENEFITS;
    
    if (DATA_COLLECTION_MODE && COLLECT_HOUSEHOLD_DATA) {
        char * filename;
        FILE * file1;
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/Household_Monthly_LastDay.txt");
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %d %d %f %f %f\n",IT_NO, ID, MY_EMPLOYER_ID, WAGE, unemployment_benefit, general_benefit);
        fclose(file1);
        free(filename);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}


