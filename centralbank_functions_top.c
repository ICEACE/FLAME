#include "header.h"
#include "centralbank_agent_header.h"

/*
 * \fn: int centralbank_init()
 * \brief: notifies its id by printing out agent id.
 */
int centralbank_init()
{
	// Read from memory
	//printf("Central Bank Id = %d\n", ID);
    char * filename;
    FILE * file1;
    
    filename = malloc(40*sizeof(char));
    filename[0]=0;
    strcpy(filename, "./outputs/data/CentralBank_snapshot.txt");
    if (IT_NO == 0) {
        file1 = fopen(filename,"w");
        fprintf(file1,"%s %s %s\n","IT_NO","ID","INTEREST_RATE");
        fclose(file1);
        free(filename);
        IT_NO++;
        return 0;
    }
    
    file1 = fopen(filename,"a");
    fprintf(file1,"%d %d %f\n",IT_NO,ID,INTEREST_RATE);
    fclose(file1);
    free(filename);
    
    IT_NO++;
	return 0; /* Returning zero means the agent is not removed */
}

