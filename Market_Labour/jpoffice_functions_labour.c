#include "../header.h"
#include "../jpoffice_agent_header.h"
#include "../library_header.h"

/*
 * \fn: int jpoffice_labour_stage1
 * \brief: The function collects vacancies and jop applications.
 * The function performs jop placement. Lower indexed households
 * have priority.
 */
int jpoffice_labour_stage1()
{
// Initialize
    
    /* Allocate local vacancies and applicants. */
    vacancy_array vacancy_list;
    employee_array applicant_list;
    int firm_id, household_id;
    double current_wage, wage_offer;
    int i,j;
    
    /* initialize */
    init_vacancy_array(&vacancy_list);
    init_employee_array(&applicant_list);
        

// Collect vacancies    
    START_VACANCY_STAGE1_MESSAGE_LOOP
    
    firm_id = vacancy_stage1_message->employer_id;
    wage_offer = vacancy_stage1_message->wage;
    
    /* Add vacancy to the list */
    add_vacancy(&vacancy_list, firm_id, wage_offer);
    
	FINISH_VACANCY_STAGE1_MESSAGE_LOOP
    
// Collect job applications
    START_JOB_APPLICATION_STAGE1_MESSAGE_LOOP
    
    household_id = job_application_stage1_message->employee_id;
    current_wage = job_application_stage1_message->wage;
    
    /* Add applicant to the list */
    add_employee(&applicant_list, household_id, current_wage);
    
	FINISH_JOB_APPLICATION_STAGE1_MESSAGE_LOOP

    
// Do the matching
    /* Input assumptions:
     * applicants are sorted ascendingly by household id.
     * vacancies are sorted descendingly by wage.
     * messages are sorted and listed fullfilling above requirements.
     */
    i = 0;
    j = 0;
    do {
        // no applicants recieved.
        if (applicant_list.size == 0 ) { break; }
        // no vacancies posted.
        if (vacancy_list.size == 0 ) { break; }
        // no unemployed left.
        if (i == applicant_list.size) { break;}
        // no positions left.
        if (j == vacancy_list.size) { break; }
        
        if (vacancy_list.array[j].wage > applicant_list.array[i].wage) {
            wage_offer = vacancy_list.array[j].wage;
            household_id = applicant_list.array[i].id;
            firm_id = vacancy_list.array[j].id;
            //send out job matching messages.
            add_job_match_stage1_message(firm_id, household_id, wage_offer);
            // proceed with matching.
            i++;
            j++;
        } else {
            // current applicant's wage is higher than any of vacancies left.
            // proceed with next applicant.
            i++;
        }
                
    } while (1);
    
// Finish
    
    //printf("Stage 1 Employment Summary: Applicants: %d, Vacancy: %d, Placement: %d \n", applicant_list.size, vacancy_list.size, j);
    
    /* Free vacancies */
    free_vacancy_array(&vacancy_list);
    
    /* Free applications */
    free_employee_array(&applicant_list);
    
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int jpoffice_labour_stage2
 * \brief: The function collects still open vacancies and list of
 * unemployed households.
 * The function performs jop placament. Lower indexed households have
 * priority.
 */
int jpoffice_labour_stage2()
{
// Initialize
    
    /* Allocate local vacancies and applicants. */
    vacancy_array vacancy_list;
    int_array applicant_list;
    int firm_id, household_id;
    double wage_offer;
    int i,j;
    
    /* initialize */
    init_vacancy_array(&vacancy_list);
    init_int_array(&applicant_list);    
    
// Collect vacancies
    START_VACANCY_STAGE2_MESSAGE_LOOP
    
    firm_id = vacancy_stage2_message->employer_id;
    wage_offer = vacancy_stage2_message->wage;
    
    /* Add vacancy to the list */
    add_vacancy(&vacancy_list, firm_id, wage_offer);
    
	FINISH_VACANCY_STAGE2_MESSAGE_LOOP
    
// Collect job applications
    START_JOB_APPLICATION_STAGE2_MESSAGE_LOOP
    
    household_id = job_application_stage2_message->employee_id;
    /* Add applicant to the list */
    add_int(&applicant_list, household_id);
    
	FINISH_JOB_APPLICATION_STAGE2_MESSAGE_LOOP
    
    
    // Do the matching
    /* Input assumptions:
     * applicants are sorted ascendingly by household id.
     * vacancies are sorted descendingly by wage.
     * messages are sorted and listed fullfilling above requirements.
     */
    i = 0;
    j = 0;
    do {
        // no applicants recieved.
        if (applicant_list.size == 0 ) {break;}
        // no vacancies posted.
        if (vacancy_list.size == 0 ) {break;}
        // no unemployed left.
        if (i == applicant_list.size) {break;}
        // no positions left.
        if (j == vacancy_list.size) {break;}
        
        wage_offer = vacancy_list.array[j].wage;
        household_id = applicant_list.array[i];
        firm_id = vacancy_list.array[j].id;
        //send out job matching messages.
        add_job_match_stage2_message(firm_id, household_id, wage_offer);
        // proceed with matching.
        i++;
        j++;
    } while (1 == 1);
    
// Finish
    //printf("Stage 2 Employment Summary: Applicants: %d, Vacancy: %d, Placement: %d \n", applicant_list.size, vacancy_list.size, j);
    
    /* Free vacancies */
    free_vacancy_array(&vacancy_list);
    /* Free applications */
    free_int_array(&applicant_list);
    
	return 0; /* Returning zero means the agent is not removed */
}