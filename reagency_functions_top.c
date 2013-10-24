#include "header.h"
#include "reagency_agent_header.h"

/*
 * \fn: int reagency_init()
 * \brief: notifies its id by printing out agent id.
 */
int reagency_init()
{
    if (DATA_COLLECTION_MODE) {
        if (IT_NO == 0) {
            char * filename;
            FILE * file1;
            
            /* @\fn: int reagency_housing_summary() */
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "./outputs/data/REAgency_snapshot.txt");
            
            file1 = fopen(filename,"w");
            fprintf(file1,"%s %s %s\n","IT_NO", "TRANSACTION_QUANTITY", "AVG_HOUSING_PRICE");
            //fprintf(file1,"%d %d %f\n",IT_NO, HOUSING_TRANSACTIONS.quantity,HOUSING_TRANSACTIONS.avg_price);
            fclose(file1);
            free(filename);
        }
    }

    IT_NO++;
	return 0; /* Returning zero means the agent is not removed */
}

