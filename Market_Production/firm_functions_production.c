#include "../header.h"
#include "../firm_agent_header.h"
#include "../library_header.h"
#include <math.h>

/*
 * \fn: int firm_production_skip()
 * \brief: Firm skips the production for the current turn.
 */
int firm_production_skip()
{
    ISINSOLVENT = 0;
    EMPLOYEES_NEEDED = 1;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_production_produce_goods()
 * \brief: Firm releases number of items produced.
 */
int firm_production_produce_goods()
{
    /*
     Production amount based on Lentoif production function.
     Capital productivity is set to inf. This results in a production solely based on availability
     of labour.
     */
    PRODUCTION_CURRENT = (int)(NO_EMPLOYEES * LABOUR_PRODUCTIVITY);

	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_production_set_price()
 * \brief: Firm sets price of goods produced.
 */
int firm_production_set_price()
{
    int goods_to_sale = 0;
    double unit_cost_old, unit_cost_new;
    
    unit_cost_old = UNIT_COST;
    
    goods_to_sale = INVENTORY;
    
    unit_cost_new = WAGE_OFFER * (double)NO_EMPLOYEES;
    unit_cost_new += DEBT * LOANS_INTEREST_RATE / 3;
    
    unit_cost_new = unit_cost_new / PRODUCTION_CURRENT;
   
    if (goods_to_sale != 0) {
        UNIT_COST = ((INVENTORY * unit_cost_old) + (PRODUCTION_CURRENT * unit_cost_new) ) / goods_to_sale;
        UNIT_GOODS_PRICE = (1 + PRICE_MARKUP) * UNIT_COST;
    }
    
    return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_production_plan()
 * \brief: Firm determines number of items to be produced for the next period.
 * It updates inventory accordingly.
 */
int firm_production_plan()
{
   
    /* Estimate the production for next period. */
    if (INVENTORY == 0) {
        EXPECTED_SALES = (int)(1.0 + PRODUCTION_MARKUP) * SALES;
    }
    //else if (INVENTORY < PRODUCTION_CURRENT) {
    else{
        EXPECTED_SALES = SALES;
    }
    /*
    else if ((PRODUCTION_CURRENT <= INVENTORY) && (INVENTORY <= (2 * PRODUCTION_CURRENT))) {
        PRODUCTION_ESTIMATE = 2 * SALES - INVENTORY;
    }
    // This case added to the model, needs to be checked!
    else {
        PRODUCTION_ESTIMATE = 0;
    }
     */
    
    
    if (INVENTORY > EXPECTED_SALES) {
        PRODUCTION_PLAN = EXPECTED_SALES - (INVENTORY - EXPECTED_SALES);
    }
    else {
        PRODUCTION_PLAN = EXPECTED_SALES;
    }
    
    
    /*This case has been observed during the experiment. Production model should be revised!*/
    if (PRODUCTION_PLAN < 0) {
        PRODUCTION_PLAN = SALES;
        if (WARNING_MODE) {
            printf("Warning @firm_production_plan(): A negative production planning occurred Firm ID = %d, previous sales is targeted instead,  Sales = %d\n", ID, SALES);
        }

        
    }
    /* Computing production plan considering firm memory persistance
    and production estimates.
     */
    PRODUCTION_PLAN = FIRM_MEMORY_PERSISTANCE * PRODUCTION_CURRENT + (1.0 - FIRM_MEMORY_PERSISTANCE) * PRODUCTION_PLAN;
    
    /* Updating the inventory available for sell. */
    INVENTORY += PRODUCTION_CURRENT;
    PRODUCTION_CURRENT = 0;
    
    /* Sales are reset to 0 for monthly periods. */
    SALES = 0;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: firm_production_compute_labour_demand()
 * \brief: Firm determines required number of labourers for current
 * production plan.
 */
int firm_production_compute_labour_demand()
{
    EMPLOYEES_NEEDED = (int) ceil(PRODUCTION_PLAN / LABOUR_PRODUCTIVITY);

    if (EMPLOYEES_NEEDED < 1) {EMPLOYEES_NEEDED = 1;}
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * Constructor Firm Roles:
 */


/*
 * \fn: int firm_production_construct_houses()
 * \brief: Firm releases number of houses completed.
 */
int firm_production_construct_houses()
{
    int capital, labour, units_to_produce;
    
    
    labour = (int)(NO_EMPLOYEES * LABOUR_PRODUCTIVITY_CONSTRUCTION);
    capital = (int) (CAPITAL_PRODUCTIVITY_CONSTRUCTION * PHYSICAL_CAPITAL_CONSTRUCTION);
    
    /* Lentoif production function: */
    units_to_produce = min_int(labour, capital);
    
    /* Finished goods were transfered to inventories.
     Unfinished housing units are advanced one at a time.
     */
    PROJECTS[0] = 0;
    
    while (units_to_produce > 0) {
        for(int i = 0; i<=10; i++) {
            if (units_to_produce <= 0) {break;}
            if (PROJECTS[i+1] == 0) {continue;}
            PROJECTS[i] += 1;
            PROJECTS[i+1] -= 1;
            units_to_produce -=1;
        }
        if (units_to_produce > 0) {
            PROJECTS[11] += 1;
            units_to_produce -= 1;
        }
    }
    /*
    for (int i = 1; i<=12; i++) {
        if (units_to_produce == 0) { break; }
        if (PROJECTS[i] <= units_to_produce) {
            PROJECTS[i-1] += PROJECTS[i];
            units_to_produce -= PROJECTS[i];
            PROJECTS[i] = 0;
        } else {
            PROJECTS[i-1] += units_to_produce;
            PROJECTS[i] -= units_to_produce;
            units_to_produce = 0;
        }
    }
    if (units_to_produce > 0) {
        PROJECTS[12] += units_to_produce;
    }
    */
    
    PRODUCTION_CURRENT = PROJECTS[0];
    
    if (PRINT_DEBUG_MODE) {
        printf("Constructor Firm %d produces %d houses.\n", ID, PRODUCTION_CURRENT);
    }
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int firm_production_construction_plan()
 * \brief: Firm determines number of housing units to be constructed for the next period.
 */
int firm_production_construction_plan()
{
    int work_in_progress;
    int maxsize;

    /* Those housing units which are produced in previous month are made
     available for sale at the start of current month.
     */
    INVENTORY += PRODUCTION_CURRENT;
    PRODUCTION_CURRENT = 0;
    
    
    /* Getting number of ongoing projects. */
    work_in_progress = 0;
    
    for (int i = 1; i<=11; i++) {
        work_in_progress += PROJECTS[i];
    }
    
    
    maxsize = (int) (CAPITAL_PRODUCTIVITY_CONSTRUCTION * PHYSICAL_CAPITAL_CONSTRUCTION);
    
    
    /* Some conditions are added to the model! Needs to be double chekced.*/
    if (maxsize <= 0){
        PRODUCTION_PLAN = 0;
    }
    else if (DELTA_HOUSING_PRICE >= 0) {
        if (work_in_progress < maxsize) {
            PRODUCTION_PLAN = random_int(work_in_progress, maxsize);
        } else {
            PRODUCTION_PLAN = maxsize;
        }
    }
    else {
        if (work_in_progress < 2) {
            PRODUCTION_PLAN = work_in_progress;
        } else {
            PRODUCTION_PLAN = random_int(1, work_in_progress);
        }
    }
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: firm_production_construction_labour_demand()
 * \brief: Firm determines required number of workers for current
 * construction plan.
 */
int firm_production_construction_labour_demand()
{
    EMPLOYEES_NEEDED = (int) (PRODUCTION_PLAN / LABOUR_PRODUCTIVITY_CONSTRUCTION);
    
	return 0; /* Returning zero means the agent is not removed */
}
