#include "../header.h"
#include "../household_agent_header.h"
#include "../library_header.h"

/*
 * \fn: int household_labour_check_fired()
 * \brief: At the start of each month each household checks if he/she has been fired.
 * In case of lay off employment status is updated. The message filtering is done beforehand.
 */
int household_labour_check_fired()
{
    START_FIRED_MESSAGE_LOOP
    // Recieving announced fired messages.
    printf("Household %d is fired now! \n", ID);
    // resetting wage and employment status.
    WAGE = 0;
    MY_EMPLOYER_ID = 0;
    FINISH_FIRED_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int household_labour_turnover()
 * \brief: An household applies a job when he/she is employed
 * and has seen a new better paid job post. Employer applies to a new job
 * with a turnover probability. 
 */
int household_labour_reemployment_application()
{
    if (random_int(0,99) < BETA * 100){
        add_job_application_stage1_message(ID, WAGE);
        printf("Stage 1: Household %d sends application (current wage: %d) \n", ID, (int)WAGE);
    }
 
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int household_labour_turnover()
 * \brief: An already employed household updates his/her employment status
 * when a new better paid wage is offered.
 */
int household_labour_turnover()
{
    int previous_employer, new_employer;
    double pre_wage;
    
    previous_employer = MY_EMPLOYER_ID;
    pre_wage = WAGE;
    
	START_JOB_MATCH_STAGE1_MESSAGE_LOOP
    // Checking if recently applied position is offered.
    new_employer = job_match_stage1_message->employer_id;
    WAGE = job_match_stage1_message->wage;
    MY_EMPLOYER_ID  = new_employer;
    add_job_change_message(previous_employer, ID);
    printf("Stage 1: Household %d job change: %d --> %d wage change %f --> %f\n",ID, previous_employer, MY_EMPLOYER_ID,pre_wage, WAGE);
    FINISH_JOB_MATCH_STAGE1_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_labour_employment_application()
 * \brief: An household applies a job when he/she is unemployed. 
 * This behviour activated in the second stage of labour market.
 */
int household_labour_employment_application()
{  
    add_job_application_stage2_message(ID);
    printf("Stage 2: Unemployed Household %d sends an application. \n", ID);
    
    return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int household_labour_employment()
 * \brief: PReviously unemployed household updates his/her employment status
 * when a position is offered.
 */
int household_labour_employment()
{    
	START_JOB_MATCH_STAGE2_MESSAGE_LOOP
    // Checking if recently applied position is offered.
    MY_EMPLOYER_ID = job_match_stage2_message->employer_id;
    WAGE = job_match_stage2_message->wage;
    printf("Stage 2: Unemployed Household %d is now employed at Firm %d with a wage %f\n",ID,MY_EMPLOYER_ID,WAGE);
    FINISH_JOB_MATCH_STAGE2_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int household_labour_recieve_wage()
 * \brief: An household updates its wage history at the end
 * of the month.
 */
int household_labour_recieve_wage()
{
    int wage_total, w0, w1, w2;
    
    PREVIOUS_WAGES[2] = PREVIOUS_WAGES[1];
    PREVIOUS_WAGES[1] = PREVIOUS_WAGES[0];
    PREVIOUS_WAGES[0] = WAGE;
    
    w0 = (int)PREVIOUS_WAGES[0];
    w1 = (int)PREVIOUS_WAGES[1];
    w2 = (int)PREVIOUS_WAGES[2];
    wage_total = w0 + w1 + w2;
    
    printf("Household Id = %d income for last 3 months sums up to  %d\n",ID, wage_total);
    
	return 0; /* Returning zero means the agent is not removed */
}


