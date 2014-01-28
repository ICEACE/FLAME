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
    IT_NO++;
	return 0; /* Returning zero means the agent is not removed */
}

