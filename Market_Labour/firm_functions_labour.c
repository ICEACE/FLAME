#include "../header.h"
#include "../Firm_agent_header.h"

/*
 * \fn: int random_number(int a, int b)
 * \brief: Return a random interger between a and b inclusive.
 */
int random_number(int a, int b)
{
	return (a+(int)(((double)b)*rand()/(RAND_MAX+1.0)));
}

/*
 * \fn: int dummy function
 * \brief:
 */
int firm_labour_dummy()
{


	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int job announcement
 * \brief: a firm announces a number of vacancies.
 * a vacancy message holds firm id, job no and wage to be paid.
 */
int firm_labour_job_announcement()
{
    int i, position_no, firm_id;
    double wage;
    
    employee an_employee;
    init_employee(&an_employee);
    // initializing model data type
    
    int firm_size;
    //size of the firm in terms of its number of employers
    firm_size =sizeof(EMPLOYEE_LIST)/sizeof(employee);
    

	// Check vacant poistions and do job announcements.
    // Right now wage is determined randomly within an interval.
    for (i = 0; i < firm_size; i++) {
        an_employee = EMPLOYEE_LIST[i];
        if (an_employee.id == 0) {
            // when there is vacancy
            firm_id = ID;
            position_no = i;
            if (an_employee.wage == 0) {
                //when the vacant position does not have a salary that is determined earlier
                wage = (double)random_number(1500,3000);
                EMPLOYEE_LIST[i].wage = wage;
            } else {
                wage = EMPLOYEE_LIST[i].wage;
            }
            
            // Randomly determined wage is stored at the agent memory.
            add_vacancy_message(firm_id, position_no, wage);
            printf("job announcement @=%d job=%d wage =%f\n", firm_id, position_no, wage);
        }

    }
    
    free_employee(&an_employee);
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int job offer function
 * \brief: the firm recieves job application messages in a random fashion.
 * Positions are served on a first come first served basis.
 */
int firm_labour_job_offer()
{
    int position_no, candidate;
    double wage;
    
    // Recieve job application messages.
    START_JOB_APPLICATION_MESSAGE_LOOP
    position_no = job_application_message->position_no;
    candidate = job_application_message->employee_id;
    if (EMPLOYEE_LIST[position_no].id == 0){
        // if not taken yet.
        // send the job offer/hire.
        wage = EMPLOYEE_LIST[position_no].wage;
        EMPLOYEE_LIST[position_no].id = candidate;
        add_job_offer_message(ID, candidate, wage, position_no);
        printf("Firm No=%d offers Household No=%d a wage =%f\n", ID, candidate, wage);
    }
	FINISH_JOB_APPLICATION_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int labour update function
 * \brief: the firm recieves job resignation message.
 * Labour status is updated.
 */
int firm_labour_update()
{
    int position, resigned_employee;
        
    // Recieve job resignation messages addressed to the firm.
    START_JOB_CHANGE_MESSAGE_LOOP
        resigned_employee = job_change_message->employee_id;
        position = job_change_message->position_no;
        EMPLOYEE_LIST[position].id = 0;
        printf("Position No=%d at Firm =%d is empty\n", position, ID);
	FINISH_JOB_CHANGE_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}
