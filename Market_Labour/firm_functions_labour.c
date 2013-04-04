#include "../header.h"
#include "../firm_agent_header.h"
#include "../library_header.h"

/*
 * \fn: int firm_labour_workforce_needed()
 * \brief:  A firm computes required number of employees to fulfill production
 * requirements.
 */
int firm_labour_workforce_needed()
{
    // Algorithm:
    // Determine number of employees needed.
    // To be computed with the input from consumption goods market.
    
    printf("Firm Id = %d is computing workforce it needs along with current size = %d \n", ID, NO_EMPLOYEES);
    // There is a 0.50 chance that a firm keeps its employee size.
    if (random_int(0,99) < 50) {
        printf("    goes with existing vacancy = %d!\n", VACANCIES);
    }
    else {
        if (random_int(0,99) > 50) {
            // hire
            VACANCIES += random_int(0, NO_EMPLOYEES);
            EMPLOYEES_NEEDED =  NO_EMPLOYEES +  VACANCIES;
            printf("    needs to fill in vacancies = %d!!\n", VACANCIES);
        } else {
            // fire
            EMPLOYEES_NEEDED =  NO_EMPLOYEES - random_int(0, NO_EMPLOYEES);
            VACANCIES = 0;
            printf("    will fire a number of employees = %d!!!\n", NO_EMPLOYEES - EMPLOYEES_NEEDED);
        }
    }
    
    
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_labour_fire()
 * \brief:  A firm picks a number of employees to be fired. And sends out a
 * notification message.
 */
int firm_labour_fire()
{
    // Algorithm:
    // Determine number of employees to be fired.
    // Make a deterministic sampling. Pick the ones with higher indices.
    // Send out fired message.
    
    int n_to_fire, i, index;
    
    n_to_fire = NO_EMPLOYEES - EMPLOYEES_NEEDED;
    
    for (i = 0; i < n_to_fire; i++) {
        index = EMPLOYEES.size - 1;
        add_fired_message(EMPLOYEES.array[index]);
        remove_int(&EMPLOYEES, index);
    }
    
    printf("Firm Id = %d has layed off %d employees. \n", ID, n_to_fire);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_labour_job_announcement_stage1()
 * \brief: a firm announces a number of vacancies.
 * a vacancy message holds firm id and wage to be paid.
 */
int firm_labour_job_announcement_stage1()
{
    int i;
    
    for (i = 0; i < VACANCIES; i++) {
        add_vacancy_stage1_message(ID,WAGE_OFFER);
    }
    
    printf("Stage 1: Firm Id = %d is attempting to hire %d new employees. \n", ID, VACANCIES);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_labour_job_offer()
 * \brief: the firm recieves job application messages. Messages are sorted
 * by employee ids. Applicants with lower indices (employee ids) are hired.
 * This leads to a type of deterministic sampling. An employee applies to a
 * post one at a time.
 */
int firm_labour_job_offer_stage1()
{
    int n_hired, candidate;

    // Recieve job application messages.
    n_hired = 0;
    
    START_JOB_MATCH_STAGE1_MESSAGE_LOOP
    candidate = job_match_stage1_message->employee_id;
    add_int(&EMPLOYEES, candidate);
    n_hired +=1;
    printf("Stage 1: Firm Id = %d has hired Household Id = %d \n", ID, candidate);
	FINISH_JOB_MATCH_STAGE1_MESSAGE_LOOP
    
    //It is possible that few applications was recieved.
    VACANCIES = VACANCIES - n_hired;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_labour_update()
 * \brief: the firm recieves job resignation message.
 * Labour force status is updated. Messages addresed to this agent
 * is filtered before hand.
 */
int firm_labour_update()
{
    int id_resigned, n_resigned, index, i;
    
    n_resigned = 0;
    // Recieve job resignation messages addressed to the firm.
    START_JOB_CHANGE_MESSAGE_LOOP
    id_resigned = job_change_message->employee_id;
    n_resigned++;
    index = EMPLOYEES.size - 1;
    for (i=0; i<EMPLOYEES.size; i++) {
        if (EMPLOYEES.array[i] == id_resigned) {
            index = i;
            break;
        }
    }
    remove_int(&EMPLOYEES, index);
    printf("Stage 1: Household Id = %d has resigned from Firm Id = %d\n", id_resigned, ID);
	FINISH_JOB_CHANGE_MESSAGE_LOOP
    
    NO_EMPLOYEES = EMPLOYEES.size;
    VACANCIES += n_resigned;
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_labour_job_announcement_stage2()
 * \brief: a firm announces a number of unfilled or resigned vacancies.
 * a vacancy message holds firm id and wage to be paid. The behaviour is
 * activated only when there are still vacancies.
 */
int firm_labour_job_announcement_stage2()
{
    int i;
    
    for (i = 0; i < VACANCIES; i++) {
        add_vacancy_stage2_message(ID,WAGE_OFFER);
    }
    printf("Stage 2: Firm Id = %d has posted: %d positions it still needs. \n", ID, VACANCIES);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_labour_job_offer_stage2()
 * \brief: the firm recieves job application messages in the second round. 
 * Messages are sorted by employee ids. Applicants with lower indices 
 * (employee ids) are hired.
 * This leads to a type of deterministic sampling. An employee applies to a
 * post one at a time.
 */
int firm_labour_job_offer_stage2()
{
    int n_hired, candidate;
    
    // Recieve job application messages.
    n_hired = 0;
    
    START_JOB_MATCH_STAGE2_MESSAGE_LOOP
    candidate = job_match_stage2_message->employee_id;
    add_int(&EMPLOYEES, candidate);
    n_hired++;
    printf("Stage 2: Firm Id = %d hired Household Id = %d \n", ID, candidate);
	FINISH_JOB_MATCH_STAGE2_MESSAGE_LOOP
    
    //It is possible that few applications was recieved.
    VACANCIES -= n_hired;
    NO_EMPLOYEES = EMPLOYEES.size;
    
    printf("Stage 2: Firm Id = %d, Size = %d, Vacancy = %d, Needed: %d Hired: %d \n", ID, NO_EMPLOYEES, VACANCIES, EMPLOYEES_NEEDED, n_hired);
    
	return 0; /* Returning zero means the agent is not removed */
}
