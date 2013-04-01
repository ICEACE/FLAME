#include "header.h"
#include "firm_agent_header.h"

/*
 * \fn: int notifier
 * \brief: notifies its id by printing out agent id.
 */
int firm_notifier()
{
    int i;
    
    //employee an_employee;
    //init_employee(&an_employee);
    // initializing model data type.
    
    int firm_size;
    //size of the firm in terms of its number of employers
    firm_size = EMPLOYEES.size;
    
	// Read from memory
	//printf(("Firm Id: %d\n", ID);
    //printf((" Size = %d\n", firm_size);
    //printf((" Wage Offer = %d\n", (int)WAGE_OFFER);
    //printf((" Employees: ");
    for (i = 0; i < firm_size; i++) {
        //an_employee = EMPLOYEE_LIST[i];
        //employee_id = an_employee.id;
        //wage = an_employee.wage;
        //printf((" %d ", EMPLOYEES.array[i]);
    }
    //printf(("\n");
    
    //free_employee(&an_employee);
	return 0; /* Returning zero means the agent is not removed */
}

