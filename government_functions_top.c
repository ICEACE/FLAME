#include "header.h"
#include "government_agent_header.h"

/*
 * \fn: int government_init()
 * \brief: notifies its id by printing out agent id.
 */
int government_init()
{
    if (DATA_COLLECTION_MODE) {
        if (IT_NO == 0) {
            char * filename;
            FILE * file1;
            
            /* @\fn: government_compute_income_statement() */
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "./outputs/data/Government_snapshot.txt");
            file1 = fopen(filename,"w");
            fprintf(file1,"%s %s %s %s %s %s %s %s %s %s %s %s\n","IT_NO", "UNEMPLOYMENT_RATE", "LABOUR_TAX_RATE", "CAPITAL_TAX_RATE", "GOV_GENERAL_BENEFIT_RATE", "LABOUR_TAX_INCOME",  "CAPITAL_TAX_INCOME", "CENTRALBANK_INCOME", "UNEMPLOYMENT_BENEFITS", "GENERAL_BENEFITS", "LIQUIDITY", "DEBT");
            //fprintf(file1,"%d %f %f %f %f %f %f %f %f %f %f %f\n",IT_NO, UNEMPLOYMENT_RATE, LABOUR_TAX_RATE, CAPITAL_TAX_RATE, GOV_GENERAL_BENEFIT_RATE, LABOUR_TAX_INCOME,  CAPITAL_TAX_INCOME, CENTRALBANK_INCOME, UNEMPLOYMENT_BENEFITS, GENERAL_BENEFITS, LIQUIDITY, DEBT);
            fclose(file1);
            free(filename);
        }
    }
    
    IT_NO++;

	return 0; /* Returning zero means the agent is not removed */
}

