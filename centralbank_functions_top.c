#include "header.h"
#include "centralbank_agent_header.h"


/*
 * \fn: int centralbank_init_balancesheet()
 * \brief:
 */
int centralbank_init_balancesheet()
{
    
    LOANS_BANKS = 0;
    
    START_BANK_CENTRALBANK_INIT_DEBT_MESSAGE_LOOP
    LOANS_BANKS += bank_centralbank_init_debt_message->amount;
    FINISH_BANK_CENTRALBANK_INIT_DEBT_MESSAGE_LOOP
    
    
    LIQUIDITY = LOANS_BANKS;
    LIQUIDITY_BANKS = LOANS_BANKS;
    TOTAL_ASSETS = LIQUIDITY;
    
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
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "./outputs/data/CentralBank_snapshot.txt");
            file1 = fopen(filename,"w");
            fprintf(file1,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n","IT_NO", "INTEREST_RATE", "INFLATION_RATE", "REVENUES", "TOTAL_COSTS", "NET_EARNINGS", "TOTAL_ASSETS", "LIQUIDITY", "LOANS_BANKS", "LOANS_GOVERNMENT", "EQUITY","FIAT_MONEY", "LIQUIDITY_BANKS", "LIQUIDITY_GOVERNMENT");
            //fprintf(file1,"%d %f %f %f %f %f %f %f %f %f %f %f %f %f\n",IT_NO, INTEREST_RATE, INFLATION_RATE, REVENUES, TOTAL_COSTS, NET_EARNINGS, TOTAL_ASSETS, LIQUIDITY, LOANS_BANKS, LOANS_GOVERNMENT, EQUITY,FIAT_MONEY, LIQUIDITY_BANKS, LIQUIDITY_GOVERNMENT);
            fclose(file1);
            free(filename);
        }
    }
    
    IT_NO++;
	return 0; /* Returning zero means the agent is not removed */
}

