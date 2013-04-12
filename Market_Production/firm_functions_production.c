#include "../header.h"
#include "../firm_agent_header.h"

/*
 * \fn: int firm_production_produce_goods()
 * \brief: Firm audits number of items produced.
 */
int firm_production_produce_goods()
{
    printf("Firm ID = %d\n", ID);
    printf("    Goods not sold = %d\n", INVENTORIES);
    PRODUCTION_CURRENT = NO_EMPLOYEES * LABOUR_PRODUCTIVITY;
    printf("    New goods available for the market = %d\n", PRODUCTION_CURRENT);
        
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_production_set_price()
 * \brief: Firm sets price of goods produced.
 */
int firm_production_set_price()
{
    int goods_to_sale = 0;
    double costs = 0;
    
    goods_to_sale = INVENTORIES + PRODUCTION_CURRENT;
    costs = UNIT_GOODS_PRICE * (double)INVENTORIES;
    costs += WAGE_OFFER * (double)NO_EMPLOYEES;
    costs += DEBT * RATIO_DEBT_FIRM;
    if (goods_to_sale != 0) {
        UNIT_GOODS_PRICE = costs / (double)goods_to_sale;
    }
    
    printf("    Unit Price = %f\n", UNIT_GOODS_PRICE);
    
    return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_production_plan()
 * \brief: Firm determines number of items to be produced for the next period.
 * It updates inventory accordingly.
 */
int firm_production_plan()
{
    // estimate the production for next period.
    if (INVENTORIES == 0) {
        PRODUCTION_ESTIMATE = (int)(1.0 + MU_PRODUCTION_MARKUP) * PRODUCTION_CURRENT;
    }
    else if (INVENTORIES < PRODUCTION_CURRENT) {
        PRODUCTION_ESTIMATE = PRODUCTION_CURRENT;

    }
    else if ((PRODUCTION_CURRENT <= INVENTORIES) && (INVENTORIES <= (2 * PRODUCTION_CURRENT))) {
        PRODUCTION_ESTIMATE = 2 * PRODUCTION_CURRENT - INVENTORIES;
    }
    else {
        PRODUCTION_ESTIMATE = 0;
    }
    printf("    Production Estimate = %d\n", PRODUCTION_ESTIMATE);
    
    // compute production plan considering firm memory persistance
    // and production estimates.
    PRODUCTION_PLAN = (int) (ETA_FIRM_MEMORY_PERSISTANCE * (double)PRODUCTION_CURRENT);
    PRODUCTION_PLAN += (int)((1.0 - ETA_FIRM_MEMORY_PERSISTANCE) * (double)PRODUCTION_ESTIMATE);
    
    printf("    Production Plan = %d\n", PRODUCTION_PLAN);
    
    
    // inventories available for sell is updated.
    INVENTORIES += PRODUCTION_CURRENT;
    PRODUCTION_CURRENT = 0;
    printf("    Inventories available for sale = %d\n", INVENTORIES);
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: firm_production_compute_labour_demand()
 * \brief: Firm determines required number of labourers for current
 * production plan.
 */
int firm_production_compute_labour_demand()
{
    EMPLOYEES_NEEDED = PRODUCTION_PLAN / (int)LABOUR_PRODUCTIVITY;
    printf("    Employees Needed = %d\n", EMPLOYEES_NEEDED);
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * Constructor Firm Roles:
 */


/*
 * \fn: int firm_production_construct_houses()
 * \brief: Firm audits number of houses completed.
 */
int firm_production_construct_houses()
{
    printf("Firm ID = %d\n", ID);
    printf("    Goods not sold = %d\n", INVENTORIES);
    PRODUCTION_CURRENT = NO_EMPLOYEES * LABOUR_PRODUCTIVITY;
    printf("    New goods available for the market = %d\n", PRODUCTION_CURRENT);
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int firm_production_construction_plan()
 * \brief: Firm determines number of housing units to be constructed for the next period.
 */
int firm_production_construction_plan()
{
    // estimate the production for next period.
    if (INVENTORIES == 0) {
        PRODUCTION_ESTIMATE = (int)(1.0 + MU_PRODUCTION_MARKUP) * PRODUCTION_CURRENT;
    }
    else if (INVENTORIES < PRODUCTION_CURRENT) {
        PRODUCTION_ESTIMATE = PRODUCTION_CURRENT;
        
    }
    else if ((PRODUCTION_CURRENT <= INVENTORIES) && (INVENTORIES <= (2 * PRODUCTION_CURRENT))) {
        PRODUCTION_ESTIMATE = 2 * PRODUCTION_CURRENT - INVENTORIES;
    }
    else {
        PRODUCTION_ESTIMATE = 0;
    }
    printf("    Production Estimate = %d\n", PRODUCTION_ESTIMATE);
    
    // compute production plan considering firm memory persistance
    // and production estimates.
    PRODUCTION_PLAN = (int) (ETA_FIRM_MEMORY_PERSISTANCE * (double)PRODUCTION_CURRENT);
    PRODUCTION_PLAN += (int)((1.0 - ETA_FIRM_MEMORY_PERSISTANCE) * (double)PRODUCTION_ESTIMATE);
    
    printf("    Production Plan = %d\n", PRODUCTION_PLAN);
    
    
    // inventories available for sell is updated.
    INVENTORIES += PRODUCTION_CURRENT;
    PRODUCTION_CURRENT = 0;
    printf("    Inventories available for sale = %d\n", INVENTORIES);
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: firm_production_construction_labour_demand()
 * \brief: Firm determines required number of workers for current
 * construction plan.
 */
int firm_production_construction_labour_demand()
{
    EMPLOYEES_NEEDED = PRODUCTION_PLAN / (int)LABOUR_PRODUCTIVITY;
    printf("    Employees Needed = %d\n", EMPLOYEES_NEEDED);
    
	return 0; /* Returning zero means the agent is not removed */
}
