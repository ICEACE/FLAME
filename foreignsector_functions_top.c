#include "header.h"
#include "foreignsector_agent_header.h"




/*
 * \fn: int foreignsector_init()
 * \brief: Agent runtime initilialization.
 */
int foreignsector_init()
{
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int foreignsector_iterate()
 * \brief: Regular loop start point.
 */
int foreignsector_iterate()
{
    if (DATA_COLLECTION_MODE) {
        if (IT_NO == 0) {
            char * filename;
            FILE * file1;
            
            /* @/fn: foreignsector_set_prices() */
            filename = malloc(100*sizeof(char));
            filename[0]=0;
            strcpy(filename, "./outputs/data/ForeignSector_Monthly.txt");
            file1 = fopen(filename,"w");
            fprintf(file1,"%s %s %s\n","IT_NO", "EXPORTS", "IMPORTS");
            fclose(file1);
            free(filename);
        }
    }
    
    IT_NO++;
	return 0; /* Returning zero means the agent is not removed */
}

