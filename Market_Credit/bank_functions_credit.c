#include "../header.h"
#include "../bank_agent_header.h"

/*
 * \fn: int bank_credit_check_interest_rate()
 * \brief: Checks quarterly interest rate determined by central bank.
 */
int bank_credit_check_interest_rate()
{
    
    START_INTEREST_RATE_MESSAGE_LOOP
    INTEREST_RATE = interest_rate_message->rate;
	FINISH_INTEREST_RATE_MESSAGE_LOOP
    
    char * filename;
    FILE * file1;
    filename = malloc(40*sizeof(char));
    
    filename[0]=0;
    strcpy(filename, "./outputs/data/ICEACE_identity_bank.txt");
    file1 = fopen(filename,"a");
    double current_equity = 0;
    current_equity = LIQUIDITY + LOANS + MORTGAGES - DEPOSITS - CENTRALBANK_DEBT;
    fprintf(file1,"%d %d %f %f %f %f %f\n",IT_NO, ID, LOANS, MORTGAGES, DEPOSITS, current_equity, INTERESTS_PAID);
    
    fclose(file1);
    free(filename);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_credit_compute_income_statement()
 * \brief:
 */
int bank_credit_compute_income_statement()
{
    /* No payment on principal amount of debt is considered here!
     The principal payment is done within balance sheet accounting.
     */
    
    //printf("Bank ID = %d at Income Statement, pre-liquidity = %f \n", ID, LIQUIDITY);
    INTERESTS_PAID = 0;
    INTERESTS_PAID = CENTRALBANK_DEBT * INTEREST_RATE / 4;
    LIQUIDITY -= INTERESTS_PAID;
    add_bank_centralbank_interest_payment_message(ID, INTERESTS_PAID);
    
    REVENUES = INTERESTS_ACCRUED;
    TOTAL_COSTS = TOTAL_WRITEOFFS + INTERESTS_PAID;
    NET_EARNINGS = REVENUES - TOTAL_COSTS;
    
    if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/Bank_IncomeStatement.txt");
        
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %d %f %f %f %f %f %f %f %f\n",IT_NO, ID, REVENUES, INTERESTS_ACCRUED, TOTAL_COSTS, TOTAL_WRITEOFFS, INTERESTS_PAID, NET_EARNINGS, RETAINED_EARNINGS, TOTAL_DIVIDENDS);
        fclose(file1);
        free(filename);
    }
    
    INTERESTS_ACCRUED = 0;
    TOTAL_WRITEOFFS = 0;
    
    //printf("Bank ID = %d at Income Statement, post-liquidity = %f \n", ID, LIQUIDITY);
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int bank_credit_compute_dividends()
 * \brief:
 */
int bank_credit_compute_dividends()
{
    
    if (NET_EARNINGS <= 0) {
        TOTAL_DIVIDENDS = 0;
        RETAINED_EARNINGS = 0;
        return 0;
    }
    /* determine if dividends retained.*/
    
    //printf("Bank ID = %d at Computing Dividends, pre-liquidity = %f \n", ID, LIQUIDITY);
    
    double risky_assets;
    risky_assets = LOANS + MORTGAGES;
    if (risky_assets > 0) {
        double threshold;
        threshold = CAPITAL_ADEQUECY_RATIO + CAR_BUFFER_THRESHOLD;
        if (EQUITY / risky_assets < threshold){
            /* instead of keeping whole earnings a portion of earnings
             that is large enough to satisfy equity ratio is to be used.
            */
            double needed;
            needed = threshold * risky_assets - EQUITY;
            if (needed < NET_EARNINGS) {
                RETAINED_EARNINGS = needed;
                TOTAL_DIVIDENDS = NET_EARNINGS - needed;
            }
            else {
                RETAINED_EARNINGS = NET_EARNINGS;
                TOTAL_DIVIDENDS = 0;
            }
        }
        else {
            RETAINED_EARNINGS = 0;
            TOTAL_DIVIDENDS = NET_EARNINGS;
        }
    }
    else {
        RETAINED_EARNINGS = 0;
        TOTAL_DIVIDENDS = NET_EARNINGS;
        if (PRINT_DEBUG_MODE){
            printf("Total Asset of Bank = %d is Negative or Zero!!!\n", ID);
        }
    }
    
    if (TOTAL_DIVIDENDS > 0) {
        LIQUIDITY -= TOTAL_DIVIDENDS;
        add_bank_net_profit_message(ID, TOTAL_DIVIDENDS);
        if (PRINT_DEBUG_MODE){
            printf("Bank ID= %d has earnings to send to the Fund. \n", ID);
        }
    }
    
    //printf("Bank ID = %d at Computing Dividends, post-liquidity = %f \n", ID, LIQUIDITY);
    
    return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_credit_do_balance_sheet()
 * \brief: Bank does the balance sheet accounting.
 * If the bank is out of liquidity it compensates it from the central bank.
 * If the bank has positive liquidity and debt to central bank, it pays its debt.
 */
int bank_credit_do_balance_sheet()
{
    double amount;
    
    //printf("Bank ID = %d at Balance Sheet, pre-liquidity = %f, CB Debt = %f \n", ID, LIQUIDITY, CENTRALBANK_DEBT);
    
    if (LIQUIDITY < 0) {
        amount = -1 * LIQUIDITY;
        CENTRALBANK_DEBT += amount;
        LIQUIDITY = 0;
        add_bank_centralbank_debt_request_message(ID, amount);
    }
    
    if (LIQUIDITY > 0) {
        if (LIQUIDITY > CENTRALBANK_DEBT){
            amount = CENTRALBANK_DEBT;
            LIQUIDITY -= amount;
            CENTRALBANK_DEBT = 0;
            add_bank_centralbank_debt_payment_message(ID, amount);
        }
        else{
            amount = LIQUIDITY;
            CENTRALBANK_DEBT -= amount;
            LIQUIDITY = 0;
            add_bank_centralbank_debt_payment_message(ID, amount);
        }
    }
    
    add_bank_centralbank_update_deposit_message(ID, LIQUIDITY);
    
    TOTAL_ASSETS = LIQUIDITY + LOANS + MORTGAGES;
    EQUITY = TOTAL_ASSETS - DEPOSITS - CENTRALBANK_DEBT;
    
    //printf("Bank ID = %d at Balance Sheet, post-liquidity = %f, CB Debt = %f \n", ID, LIQUIDITY, CENTRALBANK_DEBT);

    
    /* Added to give households as equal chance as firms at getting bank credits. 
     */
    LOANS_START = LOANS;
    
    if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/Bank_BalanceSheet.txt");
        
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %d %f %f %f %f %f %f %f\n",IT_NO, ID, TOTAL_ASSETS, LIQUIDITY, LOANS, MORTGAGES, DEPOSITS, CENTRALBANK_DEBT, EQUITY);
        fclose(file1);
        free(filename);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int bank_credit_process_loan_requests_1()
 * \brief:
 */
int bank_credit_process_loan_requests_1()
{
    double risk_weighted_assets, amount;
    int firm;
    
    risk_weighted_assets = LOANS + MORTGAGES;
    
    START_FIRM_BANK_LOAN_REQUEST_1_MESSAGE_LOOP
    amount = firm_bank_loan_request_1_message->amount;
    firm = firm_bank_loan_request_1_message->firm_id;
    
    if (EQUITY >= CAPITAL_ADEQUECY_RATIO * risk_weighted_assets) {
        LOANS += amount;
        LIQUIDITY -= amount;
        add_bank_firm_loan_acknowledge_1_message(ID, firm, amount);
        
        //printf("Bank ID = %d Loan Stage 1: %f --> Firm ID = %d, Current Loans = %f \n", ID, amount, firm, LOANS);
        
        if (PRINT_DEBUG_MODE){
            printf("Bank ID = %d Loan Stage 1: %f --> Firm ID = %d!\n", ID, amount, firm);
        }
    }
    else {
        //printf("Bank ID = %d at Loan Stage 1: Denies %f for Firm ID = %d, Current Loans = %f \n", ID, amount, firm, LOANS);
        
        if (PRINT_DEBUG_MODE){
            printf("Bank ID = %d at Loan Stage 1: denies a %f amount loan request from Firm ID = %d \n", ID, amount, firm);
        }
    }
    FINISH_FIRM_BANK_LOAN_REQUEST_1_MESSAGE_LOOP
    

	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_credit_process_loan_requests_2()
 * \brief: Processes requests from a rationed firms.
 */
int bank_credit_process_loan_requests_2()
{
    double risk_weighted_assets, amount;
    int firm;
    
    risk_weighted_assets = LOANS + MORTGAGES;
    
    START_FIRM_BANK_LOAN_REQUEST_2_MESSAGE_LOOP
    amount = firm_bank_loan_request_2_message->amount;
    firm = firm_bank_loan_request_2_message->firm_id;
    
    if (EQUITY >= CAPITAL_ADEQUECY_RATIO * risk_weighted_assets) {
        LOANS += amount;
        LIQUIDITY -= amount;
        add_bank_firm_loan_acknowledge_2_message(ID, firm, amount);
        
        //printf("Bank ID = %d Loan Stage 2: %f --> Firm ID = %d, Current Loans = %f \n", ID, amount, firm, LOANS);
        
        if (PRINT_DEBUG_MODE){
            printf("Bank ID = %d Loan Stage 2: %f --> Firm ID = %d!\n", ID, amount, firm);
        }
    }
    else {
        
        
        //printf("Bank ID = %d at Loan Stage 2: Denies %f for Firm ID = %d, Current Loans = %f \n", ID, amount, firm, LOANS);
        
        if (PRINT_DEBUG_MODE){
            printf("Bank ID = %d at Loan Stage 2: denies a %f amount loan request from Firm ID = %d \n", ID, amount, firm);
        }
    }
    FINISH_FIRM_BANK_LOAN_REQUEST_2_MESSAGE_LOOP

    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_credit_recieve_loan_writeoffs()
 * \brief:
 */
int bank_credit_recieve_loan_writeoffs()
{
    double amount;
    
    START_FIRM_BANK_INSOLVENT_ACCOUNT_MESSAGE_LOOP
    amount = firm_bank_insolvent_account_message->liquidity;
    LIQUIDITY += amount;
    DEPOSITS -= amount;
    FINISH_FIRM_BANK_INSOLVENT_ACCOUNT_MESSAGE_LOOP
    
    
    START_LOAN_WRITEOFF_MESSAGE_LOOP
    amount = loan_writeoff_message->amount;
    LOANS -= amount;
    TOTAL_WRITEOFFS += amount;
    
    
    //printf("Write off: Bank ID = %d, Amount = %f, Updated Loan = %f \n", ID, amount, LOANS);
    
    if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/BankruptcyInspection.txt");
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %d %s %s %d %f\n",IT_NO, ID, "Bank", "Loans", ID, amount);
        fclose(file1);
        free(filename);
    }
    FINISH_LOAN_WRITEOFF_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int bank_credit_recieve_new_entrant_loan_requests()
 * \brief:
 */
int bank_credit_recieve_new_entrant_loan_requests()
{
    double amount;
    
    START_NEW_ENTRANT_LOAN_MESSAGE_LOOP
    amount = new_entrant_loan_message->amount;
    LOANS += amount;
    LIQUIDITY -= amount;
    
    //printf("New entrant: Bank ID = %d, Amount = %f, Updated Loan = %f \n", ID, amount, LOANS);
    FINISH_NEW_ENTRANT_LOAN_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_credit_collect_loan_interests()
 * \brief:
 */
int bank_credit_collect_loan_interests()
{
    double amount;
    
    START_FIRM_BANK_INTEREST_ON_LOAN_MESSAGE_LOOP
    amount = firm_bank_interest_on_loan_message->amount;
    LIQUIDITY += amount;
    INTERESTS_ACCRUED += amount;
    FINISH_FIRM_BANK_INTEREST_ON_LOAN_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}




