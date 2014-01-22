#include "header.h"
#include "government_agent_header.h"


/*
 * \fn: int government_init()
 * \brief:
 */
int government_init()
{
    if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        
        /* @\fn: government_compute_income_statement() */
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/Government_snapshot.txt");
        file1 = fopen(filename,"w");
        fprintf(file1,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n","IT_NO", "UNEMPLOYMENT_RATE", "AVERAGE_WAGE", "LABOUR_TAX_RATE", "CAPITAL_TAX_RATE", "GOV_GENERAL_BENEFIT_RATE", "LABOUR_TAX_INCOME",  "CAPITAL_TAX_INCOME", "CENTRALBANK_INCOME", "UNEMPLOYMENT_BENEFITS", "GENERAL_BENEFITS", "LIQUIDITY", "DEBT", "EARNINGS", "EXPENDITURES");
        fclose(file1);
    }
    
    add_gov_centralbank_init_deposit_message(LIQUIDITY);
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int government_iterate()
 * \brief:
 */
int government_iterate()
{
    IT_NO++;

	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int government_update_deposit()
 * \brief:
 */
int government_update_deposit()
{
    
    add_gov_centralbank_update_deposit_message(LIQUIDITY);
    
	return 0; /* Returning zero means the agent is not removed */
}
