#include "header.h"
#include "Firm_agent_header.h"

/*
 * \fn: int notifier
 * \brief: notifies its id by printing out agent id.
 */
int firm_notifier()
{
    int i, employee_id;
    double wage;
    
    //employee an_employee;
    //init_employee(&an_employee);
    // initializing model data type.
    
    int firm_size;
    //size of the firm in terms of its number of employers
    firm_size =sizeof(EMPLOYEE_LIST)/sizeof(employee);
    
	// Read from memory
	printf("Firm Id: %d\n", ID);
    
    for (i = 0; i < firm_size; i++) {
        //an_employee = EMPLOYEE_LIST[i];
        //employee_id = an_employee.id;
        //wage = an_employee.wage;
        if (EMPLOYEE_LIST[i].id == 0) {
            printf("    Vacant Position Id: %d\n", i);
            continue;
        }
        printf("    Employee Id: %d ", EMPLOYEE_LIST[i].id);
        printf("Wage: %f\n", EMPLOYEE_LIST[i].wage);
    }
    
    //free_employee(&an_employee);
	return 0; /* Returning zero means the agent is not removed */
}

