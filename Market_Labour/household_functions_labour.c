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
    MY_EMPLOYER_ID = 0;
    WAGE = 0;
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
    if (random_int(0,99) < TURNOVER_PROBABILITY * 100){
        add_job_application_stage1_message(ID, WAGE);
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
    
    previous_employer = MY_EMPLOYER_ID;
    
    
	START_JOB_MATCH_STAGE1_MESSAGE_LOOP
    new_employer = job_match_stage1_message->employer_id;
    WAGE = job_match_stage1_message->wage;
    MY_EMPLOYER_ID  = new_employer;
    add_job_change_message(previous_employer, ID);
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
    MY_EMPLOYER_ID = job_match_stage2_message->employer_id;
    WAGE = job_match_stage2_message->wage;
    FINISH_JOB_MATCH_STAGE2_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int household_labour_report_status()
 * \brief: Sending out employment status.
 */
int household_labour_report_status()
{
    add_employment_status_message(MY_EMPLOYER_ID, WAGE, N_SHARES);
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int household_labour_recieve_wage()
 * \brief: An household updates its wage history and liquidity at the end
 * of the month.
 */
int household_labour_recieve_wage()
{
    if (MY_EMPLOYER_ID == 0) {
        WAGE = 0;
    }
    else {
        double net_wage = 0;
        net_wage = WAGE * (1.0 - LABOUR_TAX_RATE);
        LIQUIDITY += net_wage;
    }
    
    PREVIOUS_WAGES[2] = PREVIOUS_WAGES[1];
    PREVIOUS_WAGES[1] = PREVIOUS_WAGES[0];
    PREVIOUS_WAGES[0] = WAGE;
    
    LABOUR_INCOME = PREVIOUS_WAGES[0] + PREVIOUS_WAGES[1] + PREVIOUS_WAGES[2];
    /* Wages after labour tax is added to the income */
    LABOUR_INCOME = (1.0 - LABOUR_TAX_RATE) * LABOUR_INCOME;
    
	return 0; /* Returning zero means the agent is not removed */
}


