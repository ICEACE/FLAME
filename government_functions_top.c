#include "header.h"
#include "government_agent_header.h"

/*
 * \fn: int government_init()
 * \brief: notifies its id by printing out agent id.
 */
int government_init()
{
	// Read from memory
	//printf("Government Id = %d\n", ID);

    char * filename;
    FILE * file1;
    
    filename = malloc(40*sizeof(char));
    filename[0]=0;
    strcpy(filename, "./outputs/data/Government_snapshot.txt");
    if (IT_NO == 0) {
        file1 = fopen(filename,"w");
        fprintf(file1,"%s %s %s %s %s %s %s %s %s %s\n","IT_NO","ID","AVERAGE_WAGE","TAX_RATE","LABOUR_TAX_INCOME","CAPITAL_TAX_INCOME","CENTRALBANK_INCOME","UNEMPLOYMENT_RATE","UNEMPLOYMENT_BENEFITS","GENERAL_BENEFITS");
        fclose(file1);
        free(filename);
        IT_NO++;
        return 0;
    }
    
    file1 = fopen(filename,"a");
    fprintf(file1,"%d %d %f %f %f %f %f %f %f %f\n",IT_NO,ID,AVERAGE_WAGE,LABOUR_TAX_RATE,LABOUR_TAX_INCOME,CAPITAL_TAX_INCOME,CENTRALBANK_INCOME,UNEMPLOYMENT_RATE,UNEMPLOYMENT_BENEFITS,GENERAL_BENEFITS);
    
    fclose(file1);
    free(filename);
    
    IT_NO++;
	return 0; /* Returning zero means the agent is not removed */
}

