#include "header.h"
#include "bank_agent_header.h"


/*
 * \fn: int bank_init_loans()
 * \brief:
 */
int bank_init_loans()
{
    LOANS = 0;
    
    START_FIRM_BANK_INIT_LOANS_MESSAGE_LOOP
    LOANS += firm_bank_init_loans_message->amount;
    FINISH_FIRM_BANK_INIT_LOANS_MESSAGE_LOOP
    
    return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_init_mortgages()
 * \brief:
 */
int bank_init_mortgages()
{
    MORTGAGES = 0;
    
    START_HOUSEHOLD_BANK_INIT_MORTGAGES_MESSAGE_LOOP
    MORTGAGES += household_bank_init_mortgages_message->amount;
    FINISH_HOUSEHOLD_BANK_INIT_MORTGAGES_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_init_deposits()
 * \brief:
 */
int bank_init_deposits()
{
    double deposits_households = 0;
    double deposits_firms = 0;
    
    START_HOUSEHOLD_BANK_INIT_DEPOSIT_MESSAGE_LOOP
    deposits_households += household_bank_init_deposit_message->amount;
    FINISH_HOUSEHOLD_BANK_INIT_DEPOSIT_MESSAGE_LOOP
    
    START_FIRM_BANK_INIT_DEPOSIT_MESSAGE_LOOP
    deposits_firms += firm_bank_init_deposit_message->amount;
    FINISH_FIRM_BANK_INIT_DEPOSIT_MESSAGE_LOOP
    
    DEPOSITS = deposits_households + deposits_firms;
    
    /* Initialization Check:
    printf("Bank ID = %d, Deposits HH= %f, Firms = %f \n", ID, deposits_households, deposits_firms);
    */
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_init_balancesheet()
 * \brief:
 */
int bank_init_balancesheet()
{
    
    LIQUIDITY = (LOANS + MORTGAGES) * 0.1;
    TOTAL_ASSETS = LOANS + MORTGAGES + LIQUIDITY;
    EQUITY = TOTAL_ASSETS * 0.1;
    CENTRALBANK_DEBT = TOTAL_ASSETS - DEPOSITS - EQUITY;
    
    if (CENTRALBANK_DEBT < 0) {
        LIQUIDITY += CENTRALBANK_DEBT;
        CENTRALBANK_DEBT = 0;
    }
    
    /* Simulation starts with credit markets and net earnings are computed after central bank debt but before interest collections.
     Following initialization is done to prevent Banks with a negative earnings.
     */
    INTERESTS_ACCRUED = LOANS * ((INTEREST_RATE + 0.01) / 4);
    INTERESTS_ACCRUED += MORTGAGES * ((INTEREST_RATE + 0.02) / 4);
    LIQUIDITY += INTERESTS_ACCRUED;
    INTERESTS_PAID = CENTRALBANK_DEBT * INTEREST_RATE / 4;
    
   
    
    add_bank_centralbank_init_debt_message(ID,CENTRALBANK_DEBT);
    
    
    add_bank_centralbank_init_deposit_message(ID,LIQUIDITY);
    
    /* Initialization Check*
    printf("Bank ID = %d, Loans = %f, Mortgages = %f, Deposits = %f, Liquidity =%f, Equity =%f, Debt = %f \n", ID, LOANS, MORTGAGES, DEPOSITS, LIQUIDITY, EQUITY, CENTRALBANK_DEBT);
    printf("Bank ID = %d, Equity Ratio = %f \n", ID, EQUITY/(LOANS + MORTGAGES));
    */
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int bank_iterate()
 * \brief:
 */
int bank_iterate()
{
    
    if (DATA_COLLECTION_MODE) {
        if (IT_NO == 0 || RESUME_MODE) {
            char * filename;
            FILE * file1;
            filename = malloc(40*sizeof(char));
            
            /* @\fn: bank_credit_compute_income_statement() */
            filename[0]=0;
            strcpy(filename, "./outputs/data/Bank_IncomeStatement.txt");
            file1 = fopen(filename,"w");
            fprintf(file1,"%s %s %s %s %s %s %s %s %s %s\n","IT_NO", "ID", "REVENUES", "INTERESTS_ACCRUED", "TOTAL_COSTS", "TOTAL_WRITEOFFS", "INTERESTS_PAID", "NET_EARNINGS", "RETAINED_EARNINGS", "TOTAL_DIVIDENDS");
            //fprintf(file1,"%d %d %f %f %f %f %f %f %f %f\n",IT_NO, ID, REVENUES, INTERESTS_ACCRUED, TOTAL_COSTS, TOTAL_WRITEOFFS, INTERESTS_PAID, NET_EARNINGS, RETAINED_EARNINGS, TOTAL_DIVIDENDS);
            fclose(file1);
    
            
            /* @\fn: bank_credit_do_balance_sheet() */
            filename[0]=0;
            strcpy(filename, "./outputs/data/Bank_BalanceSheet.txt");
            file1 = fopen(filename,"w");
            fprintf(file1,"%s %s %s %s %s %s %s %s %s\n","IT_NO", "ID", "TOTAL_ASSETS", "LIQUIDITY", "LOANS", "MORTGAGES", "DEPOSITS", "CENTRALBANK_DEBT", "EQUITY");
            //fprintf(file1,"%d %d %f %f %f %f %f %f %f\n",IT_NO, ID, TOTAL_ASSETS, LIQUIDITY, LOANS, MORTGAGES, DEPOSITS, CENTRALBANK_DEBT, EQUITY);
            fclose(file1);
            
            free(filename);
        }
    }
    
    IT_NO++;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_update_deposits()
 * \brief: puts money to deposit account of its prefered bak. */
int bank_update_deposits()
{
    double current_deposit, delta_deposit;
    double deposits_households = 0;
    double deposits_firms = 0;
    
    //printf("Bank ID = %d, pre-liquidity = %f, pre-deposits = %f \n", ID, LIQUIDITY, DEPOSITS);

    START_HOUSEHOLD_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP
    deposits_households += household_bank_update_deposit_message->amount;
    FINISH_HOUSEHOLD_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP
    
    current_deposit = deposits_households;
    
    START_FIRM_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP
    deposits_firms += firm_bank_update_deposit_message->amount;
    FINISH_FIRM_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP

    current_deposit += deposits_firms;
    delta_deposit = current_deposit - DEPOSITS;
    
    DEPOSITS = current_deposit;
    LIQUIDITY += delta_deposit;
    
    //printf("Bank ID = %d Deposits: From Firms = %f , from HH = %f, Total = %f, post-liquidity = %f \n", ID, deposits_firms, deposits_households, DEPOSITS, LIQUIDITY);
    
    if (PRINT_DEBUG_MODE) {
        printf("Bank ID = %d Deposits: From Firms = %f , from HH = %f, Total = %f \n", ID, deposits_firms, deposits_households, DEPOSITS);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_update_centralbank_deposit()
 * \brief:
 */
int bank_update_centralbank_deposit()
{
    
    add_bank_centralbank_update_deposit_message(ID, LIQUIDITY);
    
    
	return 0; /* Returning zero means the agent is not removed */
}


