#include "header.h"
#include "equityfund_agent_header.h"



/*
 * \fn: int equityfund_init()
 * \brief: completes runtime initializations.
 */
int equityfund_init()
{
	if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        
        /* @\fn: eqyuityfund_compute_income_statement() */
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/EquityFund_snapshot.txt");
        file1 = fopen(filename,"w");
        fprintf(file1,"%s %s %s %s %s %s %s %s\n","IT_NO", "DIVIDENDS_RECIEVED", "DIVIDENDS_PAID", "SHARE_FIRMS", "SHARE_CONSTRUCTION_FIRMS", "SHARE_BANKS", "DIVIDENDS_RETAINED", "LIQUIDITY");
        //fprintf(file1,"%d %f %f %f %f %f %f %f\n",IT_NO, DIVIDENDS_RECIEVED, DIVIDENDS_PAID, SHARE_FIRMS, SHARE_CONSTRUCTION_FIRMS, SHARE_BANKS, DIVIDENDS_RETAINED, LIQUIDITY_ACTUAL);
        fclose(file1);
        free(filename);
    }
    
    add_fund_centralbank_init_deposit_message(LIQUIDITY);
  
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int equityfund_iterate()
 * \brief:
 */
int equityfund_iterate()
{
    
    IT_NO++;
    
	return 0; /* Returning zero means the agent is not removed */
}

