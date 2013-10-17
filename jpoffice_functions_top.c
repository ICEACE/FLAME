#include "header.h"
#include "jpoffice_agent_header.h"
#include "./library_header.h"

/*
 * \fn: int jpoffice_init_employment()
 * \brief:
 */
int jpoffice_init_employment()
{
    /* Initialize */
    
    /* Allocate firms and household arrays. */
    int_array household_list;
    int_array regular_firm_list;
    int_array constructor_firm_list;
    
    int firm_type, firm_id, household_id;
    int nhouseholds, nrfirms, ncfirms;
    int constructor_firm_size, employment_size;
    int nemployed = 0;
    int i,j;
    
    /* initialize arrays */
    init_int_array(&household_list);
    init_int_array(&regular_firm_list);
    init_int_array(&constructor_firm_list);
    
    
    /* Collect household IDs */
    START_HOUSEHOLD_JPOFFICE_ID_MESSAGE_LOOP
    household_id = household_jpoffice_id_message->household_id;
    add_int(&household_list, household_id);
	FINISH_HOUSEHOLD_JPOFFICE_ID_MESSAGE_LOOP
    
    nhouseholds = household_list.size;
    if (nhouseholds == 0 ) {
        if (PRINT_DEBUG_MODE) {
            printf("Experiment Error: No household is detected at initiliazation.\n");    
        }
        free_int_array(&household_list);
        free_int_array(&regular_firm_list);
        free_int_array(&constructor_firm_list);
        return 0;
    }
    
    /* Collect firm IDs */
    START_FIRM_JPOFFICE_ID_MESSAGE_LOOP
    firm_id = firm_jpoffice_id_message->firm_id;
    firm_type = firm_jpoffice_id_message->isconstructor;
    if (firm_type == 0) {
        add_int(&regular_firm_list, firm_id);
    } else {
        add_int(&constructor_firm_list, firm_id);
    }
	FINISH_FIRM_JPOFFICE_ID_MESSAGE_LOOP
    
    nrfirms = regular_firm_list.size;
    ncfirms = constructor_firm_list.size;
    
    /* employment ratio is 0.9
     * number of employees at construction sector is 7.5% of population.
     * These 2 values should be added to jpoffice memory for parameterization!!
     */
    constructor_firm_size = (int) (nhouseholds * 0.075 / ncfirms);
    employment_size = (int) (nhouseholds * 0.9);
    
    if (PRINT_DEBUG_MODE) {
        printf("nRFirms: %d nCFirms: %d, nHH: %d\n", nrfirms, ncfirms, nhouseholds);
        printf("nCFirm Size: %d, nEmployment: %d\n", constructor_firm_size, employment_size);
    }
    
    /* Each constructor is assigned one employee */
    for (i = 0; i < ncfirms; i++) {
        if (nemployed > employment_size) {
            if (PRINT_DEBUG_MODE) {
                printf("Experiment Error: There are more constructor firms then employable number of households.");
            }
            free_int_array(&household_list);
            free_int_array(&regular_firm_list);
            free_int_array(&constructor_firm_list);
            return 0;
        }
        firm_id = constructor_firm_list.array[i];
        household_id = household_list.array[0];
        add_jpoffice_household_employer_message(household_id, firm_id);
        add_jpoffice_firm_employee_message(firm_id, household_id);
        remove_int(&household_list, 0);
        nemployed++;
    }
    
    /* Each regular firm is assigned one employee */
    for (i = 0; i < nrfirms; i++) {
        if (nemployed > employment_size) {
            if (PRINT_DEBUG_MODE) {
                printf("Experiment Error: There are more firms then employable number of households.");
            }
            free_int_array(&household_list);
            free_int_array(&regular_firm_list);
            free_int_array(&constructor_firm_list);
            return 0;
        }
        firm_id = regular_firm_list.array[i];
        household_id = household_list.array[0];
        add_jpoffice_household_employer_message(household_id, firm_id);
        add_jpoffice_firm_employee_message(firm_id, household_id);
        remove_int(&household_list, 0);
        nemployed++;
    }
    
    /* Each constructor is assigned additional constant employees */
    for (i = 0; i < ncfirms; i++) {
        firm_id = constructor_firm_list.array[0];
        for (j = 1; j < constructor_firm_size; j++) {
            if (nemployed > employment_size) {
                if (PRINT_DEBUG_MODE) {
                   printf("Experiment Warning: Household shortage is observed at assigning additional labour to constructor firms."); 
                }
                free_int_array(&household_list);
                free_int_array(&regular_firm_list);
                free_int_array(&constructor_firm_list);
                return 0;
            }
            household_id = household_list.array[0];
            add_jpoffice_household_employer_message(household_id, firm_id);
            add_jpoffice_firm_employee_message(firm_id, household_id);
            remove_int(&household_list, 0);
            nemployed++;
        }
        remove_int(&constructor_firm_list, 0);
    }
    
    /* Rest of households are assigned to firms randomly.
     * If a normal or a scale-free distribution for firm size to be opted,
     * it should be implemented hereby.
     */
    do {
        if (nemployed > employment_size){
            break;
        }
        j = nrfirms - 1;
        i = random_int(0, j);
        firm_id = regular_firm_list.array[i];
        household_id = household_list.array[0];
        add_jpoffice_household_employer_message(household_id, firm_id);
        add_jpoffice_firm_employee_message(firm_id, household_id);
        remove_int(&household_list, 0);
        nemployed++;
    } while (1);
    
    if (PRINT_DEBUG_MODE) {
        printf("No of total employement %d\n", nemployed);
    }
    
    /* Finish */
    free_int_array(&household_list);
    free_int_array(&regular_firm_list);
    free_int_array(&constructor_firm_list);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int jpoffice_iterate()
 * \brief: 
 */
int jpoffice_iterate()
{
	IT_NO++;
	return 0; /* Returning zero means the agent is not removed */
}

