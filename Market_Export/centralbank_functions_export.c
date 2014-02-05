#include "../header.h"
#include "../centralbank_agent_header.h"


/*
 * \fn: int centralbank_import_transactions()
 * \brief: Central bank updates foreign currency reserves due to imports
 */
int centralbank_import_transactions()
{
    double fx_costs = 0;
    double costs = 0;

    START_FOREIGNSECTOR_CENTRALBANK_RAWCOSTS_MESSAGE_LOOP
    fx_costs += foreignsector_centralbank_rawcosts_message->fx_costs;
    FINISH_FOREIGNSECTOR_CENTRALBANK_RAWCOSTS_MESSAGE_LOOP

    START_FOREIGNSECTOR_CENTRALBANK_CGOODSCOSTS_MESSAGE_LOOP
    fx_costs += foreignsector_centralbank_cgoodscosts_message->fx_costs;
    FINISH_FOREIGNSECTOR_CENTRALBANK_CGOODSCOSTS_MESSAGE_LOOP

    costs = fx_costs * EXCHANGE_RATE;
    FX_LIQUIDITY -= fx_costs;
    LIQUIDITY += costs;
    MONTHLY_IMPORT_COSTS = costs;
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
    MONTHLY_EXPORT_REVENUES += revenues;
 	FINISH_FOREIGNSECTOR_CENTRALBANK_REVENUES_MESSAGE_LOOP
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int centralbank_set_exchangerate()
 * \brief: Central bank sets exchange rates.
 */
int centralbank_set_exchangerate()
{
    if (MONTHLY_IMPORT_COSTS == 0 || MONTHLY_EXPORT_REVENUES == 0){
        EXCHANGE_RATE = EXCHANGE_RATE;
    }
    else {
        EXCHANGE_RATE = EXCHANGE_RATE * 0.9 +  (MONTHLY_IMPORT_COSTS / MONTHLY_EXPORT_REVENUES) * 0.1;
    }
    add_centralbank_firm_exchangerate_message(EXCHANGE_RATE);

    MONTHLY_EXPORT_REVENUES = 0;
    MONTHLY_IMPORT_COSTS = 0;

    return 0; /* Returning zero means the agent is not removed */
}