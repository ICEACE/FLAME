#include "header.h"
#include "equityfund_agent_header.h"

/*
 * \fn: int equityfund_init()
 * \brief: notifies its id by printing out agent id.
 */
int equityfund_init()
{
	// Read from memory
	//printf("Equity Fund Agency = %d\n", ID);
    
    char * filename;
    FILE * file1;
    
    filename = malloc(40*sizeof(char));
    filename[0]=0;
    strcpy(filename, "./outputs/data/EquityFund_snapshot.txt");
    
    if (IT_NO == 0) {
        file1 = fopen(filename,"w");
        fprintf(file1,"%s %s %s %s %s %s %s %s\n","IT_NO","ID","DIVIDENDS_RECIEVED","SHARE_FIRMS","SHARE_CONSTRUCTION_FIRMS","SHARE_BANKS","DIVIDENDS_PAID","DIVIDENDS_RETAINED");
        fclose(file1);
        free(filename);
        IT_NO++;
        return 0;
    }
    
    file1 = fopen(filename,"a");
    fprintf(file1,"%d %d %f %f %f %f %f %f\n",IT_NO,ID,DIVIDENDS_RECIEVED, SHARE_FIRMS,SHARE_CONSTRUCTION_FIRMS,SHARE_BANKS, DIVIDENDS_PAID, DIVIDENDS_RETAINED);
    fclose(file1);
    free(filename);
    
    IT_NO++;
    

	return 0; /* Returning zero means the agent is not removed */
}

