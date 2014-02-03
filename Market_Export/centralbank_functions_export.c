#include "../header.h"
#include "../centralbank_agent_header.h"


/*
 * \fn: int centralbank_import_transactions()
 * \brief: Central bank updates foreign currency reserves due to imports
 */
int centralbank_import_transactions()
{
   

    return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int centralbank_export_transactions()
 * \brief: central bank processes fx transactions between foreign sector and export firms
 */
int centralbank_export_transactions()
{
	double fx_revenues, revenues;
    int id;

	START_FOREIGNSECTOR_CENTRALBANK_REVENUES_MESSAGE_LOOP
    fx_revenues = foreignsector_centralbank_revenues_message->fx_revenues;
    id = foreignsector_centralbank_revenues_message->id;
    revenues = fx_revenues*EXCHANGE_RATE;
    //add_centralbank_firm_revenues_message(id,revenues);
    FX_LIQUIDITY += fx_revenues;
    LIQUIDITY -= revenues; 
 	FINISH_FOREIGNSECTOR_CENTRALBANK_REVENUES_MESSAGE_LOOP

	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int centralbank_set_exchangerate()
 * \brief: Central bank sets exchange rates.
 */
int centralbank_set_exchangerate()
{
   

    return 0; /* Returning zero means the agent is not removed */
}