#include "../header.h"
#include "../centralbank_agent_header.h"


/*
 * \fn: int centralbank_set_interest_rate()
 * \brief:
 */
int centralbank_set_interest_rate()
{
    double inflation, rcb;
    
    if (CONSUMPTION_GOODS_PRICES[11] == 0) {
        inflation = CONSUMPTION_GOODS_PRICES[0];
    }
    else {
    inflation = (CONSUMPTION_GOODS_PRICES[0] - CONSUMPTION_GOODS_PRICES[11]) / CONSUMPTION_GOODS_PRICES[11];
    }
    
    // Taylors Rule:
    rcb = inflation;
    rcb += (inflation - INFLATION_TARGET) / 2;
    rcb -=  UNEMPLOYMENT_RATE / 2;
    
    if (rcb < 0.005){rcb = 0.005;}
    
    INFLATION_RATE = inflation;
    INTEREST_RATE = rcb;
    
    add_interest_rate_message(INTEREST_RATE);

	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int centralbank_collect_interest_payments()
 * \brief: Central Bank collects interest payments from banks.
 */
int centralbank_collect_interest_payments()
{
    double amount;
    START_BANK_CENTRALBANK_INTEREST_PAYMENT_MESSAGE_LOOP
    amount = bank_centralbank_interest_payment_message->amount;
    INTERESTS_ACCRUED += amount;
    LIQUIDITY += amount;
    FINISH_BANK_CENTRALBANK_INTEREST_PAYMENT_MESSAGE_LOOP

	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int centralbank_process_debt_requests()
 * \brief: Central Bank handles each bank debt request.
 */
int centralbank_process_debt_requests()
{
    double amount;
    
    START_DEBT_REQUEST_MESSAGE_LOOP
    amount = debt_request_message->amount;
    LOANS_BANKS += amount;
    FIAT_MONEY += amount;
    FINISH_DEBT_REQUEST_MESSAGE_LOOP

    START_BANK_CENTRALBANK_DEBT_PAYMENT_MESSAGE_LOOP
    amount = bank_centralbank_debt_payment_message->amount;
    LOANS_BANKS -= amount;
    FIAT_MONEY -= amount;
    FINISH_BANK_CENTRALBANK_DEBT_PAYMENT_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int centralbank_compute_income_statement()
 * \brief: Central Bank computes the income statement.
 * Profits are sent to the government.
 */
int centralbank_compute_income_statement()
{
    REVENUES = INTERESTS_ACCRUED;
    TOTAL_COSTS = TOTAL_WRITEOFFS;
    NET_EARNINGS = REVENUES - TOTAL_COSTS;
    if (NET_EARNINGS > 0) {
        add_centralbank_government_profit_message(NET_EARNINGS);
        LIQUIDITY -= NET_EARNINGS;
        NET_EARNINGS = 0;
    }
    //data: revenues, interests collected and writeoffs
    INTERESTS_ACCRUED = 0;
    TOTAL_WRITEOFFS = 0;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int centralbank_do_balance_sheet()
 * \brief: Central Bank does the balance sheet accounting.
 */
int centralbank_do_balance_sheet()
{
    double liabilities;
    
    TOTAL_ASSETS = LIQUIDITY + LOANS_BANKS + LOANS_GOVERNMENT;
    liabilities = FIAT_MONEY + LIQUIDITY_BANKS + LIQUIDITY_GOVERNMENT;
    EQUITY = TOTAL_ASSETS - liabilities;
    
    if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/CentralBank_snapshot.txt");
        
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %f %f %f %f %f %f %f %f %f %f %f %f %f\n",IT_NO, INTEREST_RATE, INFLATION_RATE, REVENUES, TOTAL_COSTS, NET_EARNINGS, TOTAL_ASSETS, LIQUIDITY, LOANS_BANKS, LOANS_GOVERNMENT, EQUITY,FIAT_MONEY, LIQUIDITY_BANKS, LIQUIDITY_GOVERNMENT);
        fclose(file1);
        free(filename);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}

