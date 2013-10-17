#include "header.h"
#include "mall_agent_header.h"

/*
 * \fn: int mall_init()
 * \brief: notifies its id by printing out agent id.
 */
int mall_init()
{
    if (DATA_COLLECTION_MODE) {
        if (IT_NO == 0) {
            char * filename;
            FILE * file1;
            
            /* @\fn: mall_consumption_summary() */
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "./outputs/data/Mall_snapshot.txt");
            file1 = fopen(filename,"w");
            fprintf(file1,"%s %s %s\n","IT_NO", "TRANSACTION_QUANTITY", "AVG_GOODS_PRICE");
            fprintf(file1,"%d %d %f\n",IT_NO, GOODS_TRANSACTIONS.quantity,GOODS_TRANSACTIONS.avg_price);
            fclose(file1);
            free(filename);
        }
    }

    IT_NO++;
	return 0; /* Returning zero means the agent is not removed */
}

