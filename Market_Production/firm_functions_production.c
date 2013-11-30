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
    PRODUCTION_CURRENT = (int) (NO_EMPLOYEES * LABOUR_PRODUCTIVITY);
    
    /* Update of the inventory available for sell is updated at the first day of the month.*/
    //INVENTORY += PRODUCTION_CURRENT;
    if (PRODUCTION_CURRENT <= 0) {
        PRODUCTION_CURRENT = 1;
        if (WARNING_MODE) {
        printf("Warning @firm_production_produce_goods(): Firm Id = %d, Production current is not positive!? = %d\n", ID, PRODUCTION_CURRENT);
        }
    }
    
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
    
    /* Excluding newly finished goods at cost computation. */
    unit_cost_old = UNIT_COST;
    
    /* The update of the inventory is not made yet. */
    goods_to_sale = INVENTORY + PRODUCTION_CURRENT;
    
    unit_cost_new = WAGE_OFFER * (double)NO_EMPLOYEES;
    unit_cost_new += DEBT * LOANS_INTEREST_RATE / 12;
    
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
        EXPECTED_SALES = (int) ((1.0 + PRODUCTION_MARKUP) * SALES);
    }
    else{
        EXPECTED_SALES = SALES;
    }
    
    int goods_to_sale = INVENTORY + PRODUCTION_CURRENT;
    if ((goods_to_sale - EXPECTED_SALES) >= 0) {
        PRODUCTION_PLAN = 0;
    } else {
        PRODUCTION_PLAN = EXPECTED_SALES - (goods_to_sale - EXPECTED_SALES);
    }
    
    
    /* Computing production plan considering firm memory persistance and production estimates.
     */
     PRODUCTION_PLAN = (int) (FIRM_MEMORY_PERSISTANCE * PRODUCTION_CURRENT + (1.0 - FIRM_MEMORY_PERSISTANCE) * PRODUCTION_PLAN);
    
    if (PRINT_DEBUG_MODE) {
       printf("Firm Id = %d, I = %d, PC = %d, GtoS = %d, S = %d, ES = %d, PP = %d\n", ID, INVENTORY, PRODUCTION_CURRENT, goods_to_sale, SALES, EXPECTED_SALES, PRODUCTION_PLAN);
    }
    
    
    if (DATA_COLLECTION_MODE && COLLECT_FIRM_DATA) {
        char * filename;
        FILE * file1;
        filename = malloc(100*sizeof(char));
        filename[0]=0;
        int needed = ceil(PRODUCTION_PLAN / LABOUR_PRODUCTIVITY);
        if (needed < 1) {needed = 1;}
        strcpy(filename, "./outputs/data/Firm_Monthly.txt");
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %d %f %d %d %d %d %d %d %f\n",IT_NO, ID, WAGE_OFFER, NO_EMPLOYEES, EMPLOYEES_NEEDED, SALES, INVENTORY, PRODUCTION_CURRENT, PRODUCTION_PLAN, UNIT_GOODS_PRICE);
        
        fclose(file1);
        free(filename);
    }
    
    /* Update is made here to prevent any sales of new products right at the end of the month. */
    INVENTORY += PRODUCTION_CURRENT;
    
    /*This case has been observed during the experiment. Production model should be revised!*/
    if (PRODUCTION_PLAN < 0) {
        PRODUCTION_PLAN = SALES;
        if (WARNING_MODE) {
            printf("Warning @firm_production_plan(): A negative production planning occurred Firm ID = %d, previous sales is targeted instead,  Sales = %d\n", ID, SALES);
        }
    }
    
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
    EMPLOYEES_NEEDED = ceil(PRODUCTION_PLAN / LABOUR_PRODUCTIVITY);

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
    int last_production;

    /* Those housing units which are produced in previous month are made
     available for sale at the start of current month.
     */
    INVENTORY += PRODUCTION_CURRENT;
    last_production = PRODUCTION_CURRENT;
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
    else if (DELTA_HOUSING_PRICE >= 0){
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
    
    if (DATA_COLLECTION_MODE && COLLECT_FIRM_DATA) {
        char * filename;
        FILE * file1;
        filename = malloc(100*sizeof(char));
        filename[0]=0;
        
        int needed = ceil(PRODUCTION_PLAN / LABOUR_PRODUCTIVITY_CONSTRUCTION);
        if (needed < 1) {needed = 1;}
        strcpy(filename, "./outputs/data/Constructor_Firm_Monthly.txt");
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %d %f %d %d %d %d %d %d %f\n",IT_NO, ID, WAGE_OFFER, NO_EMPLOYEES, needed, SALES, INVENTORY, last_production, PRODUCTION_PLAN, UNIT_HOUSE_PRICE);
        
        fclose(file1);
        free(filename);
    }

    /* Sales are reset to 0 for monthly periods. */
    SALES = 0;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: firm_production_construction_labour_demand()
 * \brief: Firm determines required number of workers for current
 * construction plan.
 */
int firm_production_construction_labour_demand()
{
    EMPLOYEES_NEEDED = ceil(PRODUCTION_PLAN / LABOUR_PRODUCTIVITY_CONSTRUCTION);
    
    if (EMPLOYEES_NEEDED < 1) {EMPLOYEES_NEEDED = 1;}
    
	return 0; /* Returning zero means the agent is not removed */
}
