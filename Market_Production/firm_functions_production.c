#include "../header.h"
#include "../firm_agent_header.h"
#include "../library_header.h"

/*
 * \fn: int firm_production_produce_goods()
 * \brief: Firm releases number of items produced.
 */
int firm_production_produce_goods()
{
    printf("Firm ID = %d\n", ID);   
    /*
     Production amount based on Lentoif production function.
     Capital productivity is set to inf. This results in a production solely based on availability
     of labour.
     */
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
    double unit_cost;
    
    goods_to_sale = INVENTORY + PRODUCTION_CURRENT;
    costs = UNIT_GOODS_PRICE * (double)INVENTORY;
    costs += WAGE_OFFER * (double)NO_EMPLOYEES;
    costs += DEBT * RATIO_DEBT_FIRM;
    
    if (goods_to_sale != 0) {
        unit_cost = costs / (double)goods_to_sale;
        UNIT_GOODS_PRICE = (1 + PRICE_MARKUP) * unit_cost;
    }
    
    printf("Firm ID = %d\n", ID);
    printf("    New unit Price = %f\n", UNIT_GOODS_PRICE);
    
    return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_production_plan()
 * \brief: Firm determines number of items to be produced for the next period.
 * It updates inventory accordingly.
 */
int firm_production_plan()
{

    
    // Estimate the production for next period.
    if (INVENTORY == 0) {
        PRODUCTION_ESTIMATE = (int)(1.0 + PRODUCTION_MARKUP) * SALES;
    }
    else if (INVENTORY < PRODUCTION_CURRENT) {
        PRODUCTION_ESTIMATE = SALES;

    }
    else if ((PRODUCTION_CURRENT <= INVENTORY) && (INVENTORY <= (2 * PRODUCTION_CURRENT))) {
        PRODUCTION_ESTIMATE = 2 * SALES - INVENTORY;
    }
    // This case added to the model, needs to be checked!
    else {
        PRODUCTION_ESTIMATE = 0;
    }
    printf("    Production Estimate = %d\n", PRODUCTION_ESTIMATE);
    
    // compute production plan considering firm memory persistance
    // and production estimates.
    PRODUCTION_PLAN = (int) (FIRM_MEMORY_PERSISTANCE * (double)PRODUCTION_CURRENT);
    PRODUCTION_PLAN += (int)((1.0 - FIRM_MEMORY_PERSISTANCE) * (double)PRODUCTION_ESTIMATE);
    
    printf("    Production Plan = %d\n", PRODUCTION_PLAN);
    
    // INVENTORY available for sell is updated.
    INVENTORY += PRODUCTION_CURRENT;
    PRODUCTION_CURRENT = 0;
    printf("    Total INVENTORY available for sale = %d\n", INVENTORY);
    
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
    EMPLOYEES_NEEDED = PRODUCTION_PLAN / (int)LABOUR_PRODUCTIVITY;
    printf("    Employees Needed = %d\n", EMPLOYEES_NEEDED);
    
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
    int capital, labour, units_produced;
    printf("Constructor Firm ID = %d\n", ID);
    printf("    Houses not sold = %d\n", INVENTORY);
    
    labour = NO_EMPLOYEES * LABOUR_PRODUCTIVITY;
    capital = CAPITAL_PRODUCTIVITY_CONSTRUCTION * CAPITAL_CONSTRUCTION;
    //Lentoif production function:
    units_produced = min_int(labour, capital);
    
    //make sure that finished goods were transfered to inventories.
    //unfinished housing units are advanced one at a time.
    PROJECTS[0] = 0;
    for (int i = 1; i<=12; i++) {
        if (units_produced == 0) { break; }
        if (PROJECTS[i] <= units_produced) {
            PROJECTS[i-1] += PROJECTS[i];
            units_produced -= PROJECTS[i];
            PROJECTS[i] = 0;
        } else {
            PROJECTS[i-1] += units_produced;
            PROJECTS[i] -= units_produced;
            units_produced = 0;
        }
    }
    if (units_produced > 0) {
        PROJECTS[12] += units_produced;
    }
    
    PRODUCTION_CURRENT = PROJECTS[0];
    
    
    printf("    New housing units available for the market = %d\n", PRODUCTION_CURRENT);
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int firm_production_construction_plan()
 * \brief: Firm determines number of housing units to be constructed for the next period.
 */
int firm_production_construction_plan()
{
    double new_price, old_price;
    int work_in_progress, price;

    // New housing units produced in previous month
    // is made available for sale at the start of current month.
    INVENTORY += PRODUCTION_CURRENT;
    PRODUCTION_CURRENT = 0;
    
    printf("Constructor Firm ID = %d\n", ID);
    printf("    Total inventories available for sale = %d\n", INVENTORY);
    
    //Estimate the production for next period.
    old_price = UNIT_HOUSE_PRICE;
    
    //This randomly determined price scheme to be updated later!!!!!
    price = random_int((int) 0.9 * old_price, (int) 1.1 * old_price);
    new_price = (double)price;
    
        
    //Get number of ongoing projects.
    work_in_progress = 0;
    for (int i = 1; i<=12; i++) { work_in_progress += PROJECTS[i]; }
    
    printf("Work in progress %d\n", price);

    
    int maxsize = (int) CAPITAL_PRODUCTIVITY_CONSTRUCTION * CAPITAL_CONSTRUCTION;
    
    //The first 3 condition is added to the model! Needs to be chekced.
    if (maxsize == 0){
        PRODUCTION_PLAN = 0;
    }
    else if (work_in_progress == 0) {
        PRODUCTION_PLAN = random_int(1, NO_EMPLOYEES * (int) LABOUR_PRODUCTIVITY);
    }
    else if (work_in_progress >= maxsize) {
        PRODUCTION_PLAN = random_int(1, work_in_progress);
    }
    else if (new_price > old_price) {
        PRODUCTION_PLAN = random_int(work_in_progress, maxsize);
    }
    else {
        PRODUCTION_PLAN = random_int(1, work_in_progress);
    }

    printf("    Planned number of new houses for the next term = %d\n", PRODUCTION_PLAN);
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
    printf("    Number of Constructor Workers Needed = %d\n", EMPLOYEES_NEEDED);
    
	return 0; /* Returning zero means the agent is not removed */
}
