#include "header.h"
#include "centralbank_agent_header.h"


/*
 * \fn: int centralbank_init_balancesheet()
 * \brief:
 */
int centralbank_init_balancesheet()
{
    double amount;
    
    LOANS_BANKS = 0;
    START_BANK_CENTRALBANK_INIT_DEBT_MESSAGE_LOOP
    LOANS_BANKS += bank_centralbank_init_debt_message->amount;
    FINISH_BANK_CENTRALBANK_INIT_DEBT_MESSAGE_LOOP
    
    LIQUIDITY = 0;
    
    LIQUIDITY_BANKS = 0;
    START_BANK_CENTRALBANK_INIT_DEPOSIT_MESSAGE_LOOP
    amount = bank_centralbank_init_deposit_message->amount;
    LIQUIDITY_BANKS += amount;
    FINISH_BANK_CENTRALBANK_INIT_DEPOSIT_MESSAGE_LOOP
    
    START_GOV_CENTRALBANK_INIT_DEPOSIT_MESSAGE_LOOP
    amount = gov_centralbank_init_deposit_message->amount;
    LIQUIDITY_GOVERNMENT = amount;
    FINISH_GOV_CENTRALBANK_INIT_DEPOSIT_MESSAGE_LOOP
    
   
    START_FUND_CENTRALBANK_INIT_DEPOSIT_MESSAGE_LOOP
    amount = fund_centralbank_init_deposit_message->amount;
    LIQUIDITY_EQUITYFUND = amount;
    FINISH_FUND_CENTRALBANK_INIT_DEPOSIT_MESSAGE_LOOP
    
    FIAT_MONEY = 0;
    LOANS_GOVERNMENT = 0;
    TOTAL_WRITEOFFS = 0;
    
    LIQUIDITY = LIQUIDITY_BANKS + LIQUIDITY_EQUITYFUND + LIQUIDITY_GOVERNMENT;
    TOTAL_ASSETS = LIQUIDITY + LOANS_BANKS + LOANS_GOVERNMENT;
    EQUITY = TOTAL_ASSETS - (LIQUIDITY_GOVERNMENT + LIQUIDITY_EQUITYFUND + LIQUIDITY_BANKS + FIAT_MONEY);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int centralbank_iterate()
 * \brief: 
 */
int centralbank_iterate()
{
    if (DATA_COLLECTION_MODE) {
        if (IT_NO == 0) {
            char * filename;
            FILE * file1;
            
            /* @/fn: centralbank_do_balance_sheet() */
            filename = malloc(100*sizeof(char));
            filename[0]=0;
            strcpy(filename, "./outputs/data/CentralBank_snapshot.txt");
            file1 = fopen(filename,"w");
            fprintf(file1,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n","IT_NO", "INTEREST_RATE", "INFLATION_RATE", "REVENUES", "TOTAL_COSTS", "NET_EARNINGS", "TOTAL_ASSETS", "LIQUIDITY", "LOANS_BANKS", "LOANS_GOVERNMENT", "EQUITY","FIAT_MONEY", "LIQUIDITY_BANKS", "LIQUIDITY_GOVERNMENT", "LIQUIDITY_EQUITYFUND");
            //fprintf(file1,"%d %f %f %f %f %f %f %f %f %f %f %f %f %f\n",IT_NO, INTEREST_RATE, INFLATION_RATE, REVENUES, TOTAL_COSTS, NET_EARNINGS, TOTAL_ASSETS, LIQUIDITY, LOANS_BANKS, LOANS_GOVERNMENT, EQUITY,FIAT_MONEY, LIQUIDITY_BANKS, LIQUIDITY_GOVERNMENT, LIQUIDITY_EQUITYFUND);
            fclose(file1);
            
            /* @\fn: centralbank_credit_set_interest_rate() */
            filename[0]=0;
            strcpy(filename, "./outputs/data/ICEACE_identity_cb.txt");
            file1 = fopen(filename,"w");
            fprintf(file1,"%s %s\n","IT_NO", "LIQUIDITY_GOVERNMENT");
            fclose(file1);
            
            free(filename);
        }
        
        if (IT_NO == 0) {
            char * filename;
            FILE * file1;
            
            /* @/fn: () */
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "./outputs/data/BankruptcyInspection.txt");
            file1 = fopen(filename,"w");
            fprintf(file1,"%s %s %s %s %s %s\n","IT", "ID", "Agent", "Writeoff_Type", "Bank", "Amount");
            fclose(file1);
            free(filename);
        }
    }
    
    IT_NO++;
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int centralbank_update_deposits()
 * \brief:
 */
int centralbank_update_deposits()
{
    double pre, post, delta_deposits;
 
    pre = LIQUIDITY_BANKS + LIQUIDITY_EQUITYFUND + LIQUIDITY_GOVERNMENT;
   
    
    LIQUIDITY_BANKS = 0;
    START_BANK_CENTRALBANK_UPDATE_DEPOSIT_MESSAGE_LOOP
    LIQUIDITY_BANKS += bank_centralbank_update_deposit_message->amount;
    FINISH_BANK_CENTRALBANK_UPDATE_DEPOSIT_MESSAGE_LOOP
    
    LIQUIDITY_GOVERNMENT = 0;
    START_GOV_CENTRALBANK_UPDATE_DEPOSIT_MESSAGE_LOOP
    LIQUIDITY_GOVERNMENT = gov_centralbank_update_deposit_message->amount;
    FINISH_GOV_CENTRALBANK_UPDATE_DEPOSIT_MESSAGE_LOOP
    
    LIQUIDITY_EQUITYFUND = 0;
    START_FUND_CENTRALBANK_UPDATE_DEPOSIT_MESSAGE_LOOP
    LIQUIDITY_EQUITYFUND = fund_centralbank_update_deposit_message->amount;
    FINISH_FUND_CENTRALBANK_UPDATE_DEPOSIT_MESSAGE_LOOP
    
    post = LIQUIDITY_BANKS + LIQUIDITY_EQUITYFUND + LIQUIDITY_GOVERNMENT;
    
    delta_deposits = post - pre;
    
    LIQUIDITY += delta_deposits;
    
    /* This is where Central Bank prints banknotes. */
    if (LIQUIDITY < 0) {
        FIAT_MONEY -= LIQUIDITY;
        LIQUIDITY = 0;
    }
    

	return 0; /* Returning zero means the agent is not removed */
}

