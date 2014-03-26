#include "header.h"
#include "badbank_agent_header.h"



/*
 * \fn: int equityfund_init()
 * \brief: completes runtime initializations.
 */
int badbank_init()
{
    if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        
        /* @\fn: eqyuityfund_compute_income_statement() */
        filename = malloc(100*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/BadBank_snapshot.txt");
        file1 = fopen(filename,"w");
        fprintf(file1,"%s %s %s %s %s %s \n","IT_NO", "LIQUIDITY", "FX_LIQIDITY", "SHARE_BANKS", "DIVIDEND_RECEIVED","DIVIDEND_PAID");
        fclose(file1);
        free(filename);
    }
  
    return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int equityfund_iterate()
 * \brief:
 */
int badbank_iterate()
{
    
    IT_NO++;
    
    return 0; /* Returning zero means the agent is not removed */
}

