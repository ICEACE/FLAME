#include "../header.h"
#include "../Household_agent_header.h"



/*
 * \fn: int job application
 * \brief: An household applies a job when he/she is unemployed
 * or has seen a new better paid job post.
 */
int household_labour_job_application()
{
    int applied = 0;
    int position_no, employer_id;
    

    
	START_VACANCY_MESSAGE_LOOP
    // Checking announced positions by reading in vacancy messages.
    // The first randomly received higher paid job is applied.
    if (!applied) {
        employer_id = vacancy_message->employer_id;
        position_no = vacancy_message->position_no;
        add_job_application_message(ID, employer_id, position_no);
        printf("Household %d applies to Firm %d for position no %d\n", ID, employer_id, position_no);
        applied = 1;
    }
	FINISH_VACANCY_MESSAGE_LOOP

	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int job update
 * \brief: An household updates his/her employment status if a position is offered.
 */
int household_labour_job_update()
{
    int previous_employer, previous_position;
    int new_employer, new_position;
    
    previous_employer = MY_EMPLOYER_ID;
    previous_position = MY_JOB_POSITION;
    
	START_JOB_OFFER_MESSAGE_LOOP
    // Checking if recently applied position is offered.
        new_employer = job_offer_message->employer_id;
        new_position = job_offer_message->position_no;
        WAGE = job_offer_message->wage;
        MY_EMPLOYER_ID  = new_employer;
        MY_JOB_POSITION  = new_position;
        if (previous_employer > 0){
        // was already employed
            if (new_employer != previous_employer ||  (new_employer == previous_employer && new_position != previous_position))
            {
                add_job_change_message(previous_employer, ID, previous_position);
                printf("Household %d has left Employer %d Position %d\n",ID, previous_employer, previous_position);
                
            }
        }
        printf("Household %d is employed at Firm %d with a wage %f\n",ID,MY_EMPLOYER_ID,WAGE);
    FINISH_JOB_OFFER_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

