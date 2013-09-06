/**
 * \file  main.c
 * \brief Holds main function of the program.
 */

#include "header.h"
#define COMPACT_PRINTOUT_P_THRESHOLD 8

/** \fn int main(int argc, char * argv[])
 * \brief Main program loop.
 * \param argc Argument count.
 * \param argv Pointer Pointer to Argument vector.
 */
int main(int argc, char * argv[])
{
	/* Timing variables */
	double start, stop, interval;
	FILE *file;
	char data[100];
	char logfilepath[1000];
	char inputpath[1000];
	char * c;
	int lastd = 0;
	int i;
	int rc;
	int iteration_number = 0;
	int iteration_total;
	int * p_iteration_number = &iteration_number;
	//xmachine_memory_firm * temp_xmachine_firm;
	//xmachine_memory_household * temp_xmachine_household;
	//xmachine_memory_equityfund * temp_xmachine_equityfund;
	//xmachine_memory_bank * temp_xmachine_bank;
	//xmachine_memory_government * temp_xmachine_government;
	//xmachine_memory_centralbank * temp_xmachine_centralbank;
	//xmachine_memory_jpoffice * temp_xmachine_jpoffice;
	//xmachine_memory_mall * temp_xmachine_mall;
	//xmachine_memory_reagency * temp_xmachine_reagency;

	int FLAME_firm_bank_update_deposit_message_board_write;
	int FLAME_firm_bank_update_deposit_message_board_read;
	int FLAME_household_bank_update_deposit_message_board_write;
	int FLAME_household_bank_update_deposit_message_board_read;
	int FLAME_interest_rate_message_board_write;
	int FLAME_interest_rate_message_board_read;
	int FLAME_tax_rate_message_board_write;
	int FLAME_tax_rate_message_board_read;
	int FLAME_buy_message_board_write;
	int FLAME_buy_message_board_read;
	int FLAME_bought_message_board_write;
	int FLAME_bought_message_board_read;
	int FLAME_sell_message_board_write;
	int FLAME_sell_message_board_read;
	int FLAME_sold_message_board_write;
	int FLAME_sold_message_board_read;
	int FLAME_goods_transactions_summary_message_board_write;
	int FLAME_goods_transactions_summary_message_board_read;
	int FLAME_fired_message_board_write;
	int FLAME_fired_message_board_read;
	int FLAME_vacancy_stage1_message_board_write;
	int FLAME_vacancy_stage1_message_board_read;
	int FLAME_job_application_stage2_message_board_write;
	int FLAME_job_application_stage2_message_board_read;
	int FLAME_job_application_stage1_message_board_write;
	int FLAME_job_application_stage1_message_board_read;
	int FLAME_job_match_stage1_message_board_write;
	int FLAME_job_match_stage1_message_board_read;
	int FLAME_job_change_message_board_write;
	int FLAME_job_change_message_board_read;
	int FLAME_vacancy_stage2_message_board_write;
	int FLAME_vacancy_stage2_message_board_read;
	int FLAME_job_match_stage2_message_board_write;
	int FLAME_job_match_stage2_message_board_read;
	int FLAME_employment_status_message_board_write;
	int FLAME_employment_status_message_board_read;
	int FLAME_loan_request_1_message_board_write;
	int FLAME_loan_request_1_message_board_read;
	int FLAME_loan_request_2_message_board_write;
	int FLAME_loan_request_2_message_board_read;
	int FLAME_loan_acknowledge_1_message_board_write;
	int FLAME_loan_acknowledge_1_message_board_read;
	int FLAME_loan_acknowledge_2_message_board_write;
	int FLAME_loan_acknowledge_2_message_board_read;
	int FLAME_debt_request_message_board_write;
	int FLAME_debt_request_message_board_read;
	int FLAME_household_share_message_board_write;
	int FLAME_household_share_message_board_read;
	int FLAME_capital_tax_message_board_write;
	int FLAME_capital_tax_message_board_read;
	int FLAME_labour_tax_message_board_write;
	int FLAME_labour_tax_message_board_read;
	int FLAME_unemployment_benefit_message_board_write;
	int FLAME_unemployment_benefit_message_board_read;
	int FLAME_general_benefit_message_board_write;
	int FLAME_general_benefit_message_board_read;
	int FLAME_fund_request_message_board_write;
	int FLAME_fund_request_message_board_read;
	int FLAME_fund_request_ack_message_board_write;
	int FLAME_fund_request_ack_message_board_read;
	int FLAME_new_entrant_loan_message_board_write;
	int FLAME_new_entrant_loan_message_board_read;
	int FLAME_interest_on_loan_message_board_write;
	int FLAME_interest_on_loan_message_board_read;
	int FLAME_loan_writeoff_message_board_write;
	int FLAME_loan_writeoff_message_board_read;
	int FLAME_firm_net_profit_message_board_write;
	int FLAME_firm_net_profit_message_board_read;
	int FLAME_bank_net_profit_message_board_write;
	int FLAME_bank_net_profit_message_board_read;
	int FLAME_bank_centralbank_interest_payment_message_board_write;
	int FLAME_bank_centralbank_interest_payment_message_board_read;
	int FLAME_bank_centralbank_debt_payment_message_board_write;
	int FLAME_bank_centralbank_debt_payment_message_board_read;
	int FLAME_centralbank_government_profit_message_board_write;
	int FLAME_centralbank_government_profit_message_board_read;
	int FLAME_housing_price_message_board_write;
	int FLAME_housing_price_message_board_read;
	int FLAME_buy_housing_message_board_write;
	int FLAME_buy_housing_message_board_read;
	int FLAME_sell_housing_message_board_write;
	int FLAME_sell_housing_message_board_read;
	int FLAME_bought_housing_message_board_write;
	int FLAME_bought_housing_message_board_read;
	int FLAME_sold_housing_message_board_write;
	int FLAME_sold_housing_message_board_read;
	int FLAME_mortgaging_capacity_message_board_write;
	int FLAME_mortgaging_capacity_message_board_read;
	int FLAME_mortgage_requests_message_board_write;
	int FLAME_mortgage_requests_message_board_read;
	int FLAME_mortgage_payment_from_sale_message_board_write;
	int FLAME_mortgage_payment_from_sale_message_board_read;
	int FLAME_mortgage_payment_message_board_write;
	int FLAME_mortgage_payment_message_board_read;
	int FLAME_mortgage_writeoff_message_board_write;
	int FLAME_mortgage_writeoff_message_board_read;
	int FLAME_housing_transactions_summary_message_board_write;
	int FLAME_housing_transactions_summary_message_board_read;

	/* Particle cloud data */
	double cloud_data[6] = {0.0,0.0,0.0,0.0,0.0,0.0};
	/* Count to debug function branches */
	int FLAME_debug_count;

/* For partition method. Makes geometric (-g flag) the default but may be overridden with -r for round-robin */
	int partition_method=1;



	/* Output frequency is 1 as default */
	output_frequency = 1;
	/* Set random seed */
/*	srand(time(NULL)); */

	

	rc = MB_Env_Init();
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Failed to initialise Message Board environment\n");
	   switch(rc) {
	       case MB_ERR_MPI:
	           fprintf(stderr, "\t reason: MPI library not initialised\n");
	           break;
	       case MB_ERR_MEMALLOC:
	           fprintf(stderr, "\t reason: out of memory\n");
	           break;
           default:
               fprintf(stderr, "\t MB_Env_Init returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }

	   
       exit(rc);

	}
	#endif
    
	/* For backwards compatabilty allocate current_xmachine */
	current_xmachine = (xmachine *)malloc(sizeof(xmachine));
	if(current_xmachine == NULL) {printf("**** ERROR in Memory check current_xmachine\n");exit(EXIT_FAILURE);}
	/*CHECK_POINTER(current_xmachine);*/

	/* Initialise pointers */
	initialise_pointers();


	printf("FLAME Application: ICEACE \n");


	printf("Debug mode enabled \n");
FLAME_debug_count = 0;
/* Use to stop compiler warnings if not used */
if(FLAME_debug_count == 0) {}




if(argc < 2)
	{

		printf("Usage: %s <number of iterations> [<states_directory>]/<init_state> <partitions> [-f # | -f #+#]\n",argv[0]);
		printf("\t-f\tOutput frequency, 1st # is frequency, 2nd # is the offset if required\n");



		exit(0);
	}
	iteration_total = atoi(argv[1]);
printf("Iterations: %i\n", iteration_total);

	/* Read initial states of x-machines */
	if(argc < 3)
	{
		printf("Need two parameters\n");
		exit(0);
	}
	strcpy(inputpath, argv[2]);
/*printf("Initial states: %s\n", inputpath);*/

	i = 0;
	lastd = -1;
	while(inputpath[i] != '\0')
	{
		/* For windows directories */
		if(inputpath[i] == '\\') lastd=i;
		/* For unix directories */
		if(inputpath[i] == '/') lastd=i;
		i++;
	}
	strcpy(outputpath, inputpath);
	outputpath[lastd+1] = '\0';

/*printf("Ouput dir: %s\n", outputpath);*/


	/* Read number of space partitions (1 by default) */
	totalnodes = 1;
	if(argc > 3)
	{
		totalnodes = atoi(argv[3]);
	}


	i = 3;
	while(argc > i)
	{
		if(strcmp(argv[i],"-f") == 0)
		{
			if(argc > (i+1))
			{
				output_offset = 0;
				/* Find offset, separated by the char '+' */
				c = strchr(argv[(i+1)], '+');
				if(c == NULL)
				{
					output_frequency = atoi(argv[(i+1)]);
					printf("Using output frequency of: %d\n", output_frequency);
				}
				else
				{
					output_offset = atoi(argv[(i+1)]+(c-argv[(i+1)])+1);
					argv[(i+1)][c-argv[(i+1)]] = '\0';
					output_frequency = atoi(argv[(i+1)]);
					printf("Using output frequency of: %d with offset %d\n", output_frequency, output_offset);
				}

				if(output_frequency == 0)
				{
					printf("Output frequency cannot be zero\n");
					exit(0);
				}

				i++;
			}
			else
			{
				printf("Output frequency number not defined\n");
				exit(0);
			}
		}
		/* Partitioning method: -g = geometric, -r = round-robin */
		if(strcmp(argv[i],"-g") == 0) partition_method = 1;
		if(strcmp(argv[i],"-r") == 0) partition_method = 2;
		i++;
	}


	    /* Read initial data into p_xmachine  */

       //agent_list = p_xmachine;
       readinitialstates(inputpath, outputpath, p_iteration_number, cloud_data, partition_method, 0);
       /* Generate partitions */
       generate_partitions(cloud_data,totalnodes,partition_method);
       save_partition_data();





    /* Partition data */
    /* stc: no partitions in serial */
	//partition_data(totalnodes, agent_list, cloud_data, partition_method);



/* Use MB_IndexMap routines from libmboard v0.2 */
/* For each agent constant (that is used in a filter(?))
 * declare an index map handle */



		/*i = 0;
		current_node = *p_node_info;
		while(current_node)
		{
			printf("No of agents on partition %d: %d\n", current_node->node_id, current_node->agent_total);
			i += current_node->agent_total;
			current_node = current_node->next;
		}
		printf("Agent total check: %d\n", i);*/

        /* restore current_node pointer */
		//current_node = *p_node_info;



	/* Start log file (now so that xvisualiser can read straight away) */

	/* Write log file */
	sprintf(logfilepath, "%slog.xml", outputpath);
	if((file = fopen(logfilepath, "w"))==NULL)
	{
		printf("Error: cannot open file '%s' for writing\n", logfilepath);
		exit(0);
	}
	(void)fputs("<model_run>\n", file);
	(void)fputs("<codetype>", file);
	(void)fputs("serial", file);

	(void)fputs("</codetype>\n", file);
	(void)fputs("<nodes>", file);
	sprintf(data, "%i", totalnodes);
	(void)fputs(data, file);
	(void)fputs("</nodes>\n", file);

	/* print timer into */
	(void)fputs("<!-- <time> unit: milliseconds -->\n", file);

	sprintf(data, "unspecified");
	
	(void)fputs("<!-- <time> timer resolution: ", file);
	(void)fputs(data, file);
	(void)fputs(")-->\n", file);

	start = get_time();
	stop = get_time();
	sprintf(data, "%.2e ms", (stop - start) * 1000.0);
	(void)fputs("<!-- <time> timer overhead: ~", file);
	(void)fputs(data, file);
	(void)fputs(")-->\n", file);


	(void)fclose(file);


	/* For each message check if their exists agents that input/output the message */
	FLAME_firm_bank_update_deposit_message_board_write = 0;
	FLAME_firm_bank_update_deposit_message_board_read = 0;
	/* Sending agents */
	if(firm_start_state->agents != NULL) FLAME_firm_bank_update_deposit_message_board_write = 1;
	
	/* Reading agents */
	if(bank_start_state->agents != NULL) FLAME_firm_bank_update_deposit_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_firm_bank_update_deposit_message_board_write == 0 &&
		FLAME_firm_bank_update_deposit_message_board_read == 0)
			rc = MB_SetAccessMode(b_firm_bank_update_deposit, MB_MODE_IDLE);
	if(FLAME_firm_bank_update_deposit_message_board_write == 1 &&
		FLAME_firm_bank_update_deposit_message_board_read == 0)
			rc = MB_SetAccessMode(b_firm_bank_update_deposit, MB_MODE_WRITEONLY);
	if(FLAME_firm_bank_update_deposit_message_board_write == 0 &&
		FLAME_firm_bank_update_deposit_message_board_read == 1)
			rc = MB_SetAccessMode(b_firm_bank_update_deposit, MB_MODE_READONLY);
	if(FLAME_firm_bank_update_deposit_message_board_write == 1 &&
		FLAME_firm_bank_update_deposit_message_board_read == 1)
			rc = MB_SetAccessMode(b_firm_bank_update_deposit, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'firm_bank_update_deposit' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_household_bank_update_deposit_message_board_write = 0;
	FLAME_household_bank_update_deposit_message_board_read = 0;
	/* Sending agents */
	if(household_start_state->agents != NULL) FLAME_household_bank_update_deposit_message_board_write = 1;
	
	/* Reading agents */
	if(bank_start_state->agents != NULL) FLAME_household_bank_update_deposit_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_household_bank_update_deposit_message_board_write == 0 &&
		FLAME_household_bank_update_deposit_message_board_read == 0)
			rc = MB_SetAccessMode(b_household_bank_update_deposit, MB_MODE_IDLE);
	if(FLAME_household_bank_update_deposit_message_board_write == 1 &&
		FLAME_household_bank_update_deposit_message_board_read == 0)
			rc = MB_SetAccessMode(b_household_bank_update_deposit, MB_MODE_WRITEONLY);
	if(FLAME_household_bank_update_deposit_message_board_write == 0 &&
		FLAME_household_bank_update_deposit_message_board_read == 1)
			rc = MB_SetAccessMode(b_household_bank_update_deposit, MB_MODE_READONLY);
	if(FLAME_household_bank_update_deposit_message_board_write == 1 &&
		FLAME_household_bank_update_deposit_message_board_read == 1)
			rc = MB_SetAccessMode(b_household_bank_update_deposit, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'household_bank_update_deposit' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'household_bank_update_deposit' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'household_bank_update_deposit' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_interest_rate_message_board_write = 0;
	FLAME_interest_rate_message_board_read = 0;
	/* Sending agents */
	if(centralbank_start_state->agents != NULL) FLAME_interest_rate_message_board_write = 1;
	
	/* Reading agents */
	if(firm_start_state->agents != NULL) FLAME_interest_rate_message_board_read = 1;
	if(household_start_state->agents != NULL) FLAME_interest_rate_message_board_read = 1;
	if(bank_start_state->agents != NULL) FLAME_interest_rate_message_board_read = 1;
	if(reagency_start_state->agents != NULL) FLAME_interest_rate_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_interest_rate_message_board_write == 0 &&
		FLAME_interest_rate_message_board_read == 0)
			rc = MB_SetAccessMode(b_interest_rate, MB_MODE_IDLE);
	if(FLAME_interest_rate_message_board_write == 1 &&
		FLAME_interest_rate_message_board_read == 0)
			rc = MB_SetAccessMode(b_interest_rate, MB_MODE_WRITEONLY);
	if(FLAME_interest_rate_message_board_write == 0 &&
		FLAME_interest_rate_message_board_read == 1)
			rc = MB_SetAccessMode(b_interest_rate, MB_MODE_READONLY);
	if(FLAME_interest_rate_message_board_write == 1 &&
		FLAME_interest_rate_message_board_read == 1)
			rc = MB_SetAccessMode(b_interest_rate, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'interest_rate' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'interest_rate' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'interest_rate' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_tax_rate_message_board_write = 0;
	FLAME_tax_rate_message_board_read = 0;
	/* Sending agents */
	if(government_start_state->agents != NULL) FLAME_tax_rate_message_board_write = 1;
	
	/* Reading agents */
	if(firm_start_state->agents != NULL) FLAME_tax_rate_message_board_read = 1;
	if(household_start_state->agents != NULL) FLAME_tax_rate_message_board_read = 1;
	if(equityfund_start_state->agents != NULL) FLAME_tax_rate_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_tax_rate_message_board_write == 0 &&
		FLAME_tax_rate_message_board_read == 0)
			rc = MB_SetAccessMode(b_tax_rate, MB_MODE_IDLE);
	if(FLAME_tax_rate_message_board_write == 1 &&
		FLAME_tax_rate_message_board_read == 0)
			rc = MB_SetAccessMode(b_tax_rate, MB_MODE_WRITEONLY);
	if(FLAME_tax_rate_message_board_write == 0 &&
		FLAME_tax_rate_message_board_read == 1)
			rc = MB_SetAccessMode(b_tax_rate, MB_MODE_READONLY);
	if(FLAME_tax_rate_message_board_write == 1 &&
		FLAME_tax_rate_message_board_read == 1)
			rc = MB_SetAccessMode(b_tax_rate, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'tax_rate' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'tax_rate' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'tax_rate' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_buy_message_board_write = 0;
	FLAME_buy_message_board_read = 0;
	/* Sending agents */
	if(household_start_state->agents != NULL) FLAME_buy_message_board_write = 1;
	
	/* Reading agents */
	if(mall_start_state->agents != NULL) FLAME_buy_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_buy_message_board_write == 0 &&
		FLAME_buy_message_board_read == 0)
			rc = MB_SetAccessMode(b_buy, MB_MODE_IDLE);
	if(FLAME_buy_message_board_write == 1 &&
		FLAME_buy_message_board_read == 0)
			rc = MB_SetAccessMode(b_buy, MB_MODE_WRITEONLY);
	if(FLAME_buy_message_board_write == 0 &&
		FLAME_buy_message_board_read == 1)
			rc = MB_SetAccessMode(b_buy, MB_MODE_READONLY);
	if(FLAME_buy_message_board_write == 1 &&
		FLAME_buy_message_board_read == 1)
			rc = MB_SetAccessMode(b_buy, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'buy' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'buy' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'buy' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_bought_message_board_write = 0;
	FLAME_bought_message_board_read = 0;
	/* Sending agents */
	if(mall_start_state->agents != NULL) FLAME_bought_message_board_write = 1;
	
	/* Reading agents */
	if(household_start_state->agents != NULL) FLAME_bought_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_bought_message_board_write == 0 &&
		FLAME_bought_message_board_read == 0)
			rc = MB_SetAccessMode(b_bought, MB_MODE_IDLE);
	if(FLAME_bought_message_board_write == 1 &&
		FLAME_bought_message_board_read == 0)
			rc = MB_SetAccessMode(b_bought, MB_MODE_WRITEONLY);
	if(FLAME_bought_message_board_write == 0 &&
		FLAME_bought_message_board_read == 1)
			rc = MB_SetAccessMode(b_bought, MB_MODE_READONLY);
	if(FLAME_bought_message_board_write == 1 &&
		FLAME_bought_message_board_read == 1)
			rc = MB_SetAccessMode(b_bought, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'bought' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'bought' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'bought' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_sell_message_board_write = 0;
	FLAME_sell_message_board_read = 0;
	/* Sending agents */
	if(firm_start_state->agents != NULL) FLAME_sell_message_board_write = 1;
	
	/* Reading agents */
	if(mall_start_state->agents != NULL) FLAME_sell_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_sell_message_board_write == 0 &&
		FLAME_sell_message_board_read == 0)
			rc = MB_SetAccessMode(b_sell, MB_MODE_IDLE);
	if(FLAME_sell_message_board_write == 1 &&
		FLAME_sell_message_board_read == 0)
			rc = MB_SetAccessMode(b_sell, MB_MODE_WRITEONLY);
	if(FLAME_sell_message_board_write == 0 &&
		FLAME_sell_message_board_read == 1)
			rc = MB_SetAccessMode(b_sell, MB_MODE_READONLY);
	if(FLAME_sell_message_board_write == 1 &&
		FLAME_sell_message_board_read == 1)
			rc = MB_SetAccessMode(b_sell, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'sell' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'sell' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'sell' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_sold_message_board_write = 0;
	FLAME_sold_message_board_read = 0;
	/* Sending agents */
	if(mall_start_state->agents != NULL) FLAME_sold_message_board_write = 1;
	
	/* Reading agents */
	if(firm_start_state->agents != NULL) FLAME_sold_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_sold_message_board_write == 0 &&
		FLAME_sold_message_board_read == 0)
			rc = MB_SetAccessMode(b_sold, MB_MODE_IDLE);
	if(FLAME_sold_message_board_write == 1 &&
		FLAME_sold_message_board_read == 0)
			rc = MB_SetAccessMode(b_sold, MB_MODE_WRITEONLY);
	if(FLAME_sold_message_board_write == 0 &&
		FLAME_sold_message_board_read == 1)
			rc = MB_SetAccessMode(b_sold, MB_MODE_READONLY);
	if(FLAME_sold_message_board_write == 1 &&
		FLAME_sold_message_board_read == 1)
			rc = MB_SetAccessMode(b_sold, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'sold' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'sold' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'sold' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_goods_transactions_summary_message_board_write = 0;
	FLAME_goods_transactions_summary_message_board_read = 0;
	/* Sending agents */
	if(mall_start_state->agents != NULL) FLAME_goods_transactions_summary_message_board_write = 1;
	
	/* Reading agents */
	if(firm_start_state->agents != NULL) FLAME_goods_transactions_summary_message_board_read = 1;
	if(centralbank_start_state->agents != NULL) FLAME_goods_transactions_summary_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_goods_transactions_summary_message_board_write == 0 &&
		FLAME_goods_transactions_summary_message_board_read == 0)
			rc = MB_SetAccessMode(b_goods_transactions_summary, MB_MODE_IDLE);
	if(FLAME_goods_transactions_summary_message_board_write == 1 &&
		FLAME_goods_transactions_summary_message_board_read == 0)
			rc = MB_SetAccessMode(b_goods_transactions_summary, MB_MODE_WRITEONLY);
	if(FLAME_goods_transactions_summary_message_board_write == 0 &&
		FLAME_goods_transactions_summary_message_board_read == 1)
			rc = MB_SetAccessMode(b_goods_transactions_summary, MB_MODE_READONLY);
	if(FLAME_goods_transactions_summary_message_board_write == 1 &&
		FLAME_goods_transactions_summary_message_board_read == 1)
			rc = MB_SetAccessMode(b_goods_transactions_summary, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'goods_transactions_summary' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'goods_transactions_summary' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'goods_transactions_summary' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_fired_message_board_write = 0;
	FLAME_fired_message_board_read = 0;
	/* Sending agents */
	if(firm_start_state->agents != NULL) FLAME_fired_message_board_write = 1;
	
	/* Reading agents */
	if(household_start_state->agents != NULL) FLAME_fired_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_fired_message_board_write == 0 &&
		FLAME_fired_message_board_read == 0)
			rc = MB_SetAccessMode(b_fired, MB_MODE_IDLE);
	if(FLAME_fired_message_board_write == 1 &&
		FLAME_fired_message_board_read == 0)
			rc = MB_SetAccessMode(b_fired, MB_MODE_WRITEONLY);
	if(FLAME_fired_message_board_write == 0 &&
		FLAME_fired_message_board_read == 1)
			rc = MB_SetAccessMode(b_fired, MB_MODE_READONLY);
	if(FLAME_fired_message_board_write == 1 &&
		FLAME_fired_message_board_read == 1)
			rc = MB_SetAccessMode(b_fired, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'fired' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'fired' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'fired' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_vacancy_stage1_message_board_write = 0;
	FLAME_vacancy_stage1_message_board_read = 0;
	/* Sending agents */
	if(firm_start_state->agents != NULL) FLAME_vacancy_stage1_message_board_write = 1;
	
	/* Reading agents */
	if(jpoffice_start_state->agents != NULL) FLAME_vacancy_stage1_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_vacancy_stage1_message_board_write == 0 &&
		FLAME_vacancy_stage1_message_board_read == 0)
			rc = MB_SetAccessMode(b_vacancy_stage1, MB_MODE_IDLE);
	if(FLAME_vacancy_stage1_message_board_write == 1 &&
		FLAME_vacancy_stage1_message_board_read == 0)
			rc = MB_SetAccessMode(b_vacancy_stage1, MB_MODE_WRITEONLY);
	if(FLAME_vacancy_stage1_message_board_write == 0 &&
		FLAME_vacancy_stage1_message_board_read == 1)
			rc = MB_SetAccessMode(b_vacancy_stage1, MB_MODE_READONLY);
	if(FLAME_vacancy_stage1_message_board_write == 1 &&
		FLAME_vacancy_stage1_message_board_read == 1)
			rc = MB_SetAccessMode(b_vacancy_stage1, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'vacancy_stage1' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'vacancy_stage1' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'vacancy_stage1' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_job_application_stage2_message_board_write = 0;
	FLAME_job_application_stage2_message_board_read = 0;
	/* Sending agents */
	if(household_start_state->agents != NULL) FLAME_job_application_stage2_message_board_write = 1;
	
	/* Reading agents */
	if(jpoffice_start_state->agents != NULL) FLAME_job_application_stage2_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_job_application_stage2_message_board_write == 0 &&
		FLAME_job_application_stage2_message_board_read == 0)
			rc = MB_SetAccessMode(b_job_application_stage2, MB_MODE_IDLE);
	if(FLAME_job_application_stage2_message_board_write == 1 &&
		FLAME_job_application_stage2_message_board_read == 0)
			rc = MB_SetAccessMode(b_job_application_stage2, MB_MODE_WRITEONLY);
	if(FLAME_job_application_stage2_message_board_write == 0 &&
		FLAME_job_application_stage2_message_board_read == 1)
			rc = MB_SetAccessMode(b_job_application_stage2, MB_MODE_READONLY);
	if(FLAME_job_application_stage2_message_board_write == 1 &&
		FLAME_job_application_stage2_message_board_read == 1)
			rc = MB_SetAccessMode(b_job_application_stage2, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'job_application_stage2' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'job_application_stage2' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'job_application_stage2' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_job_application_stage1_message_board_write = 0;
	FLAME_job_application_stage1_message_board_read = 0;
	/* Sending agents */
	if(household_start_state->agents != NULL) FLAME_job_application_stage1_message_board_write = 1;
	
	/* Reading agents */
	if(jpoffice_start_state->agents != NULL) FLAME_job_application_stage1_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_job_application_stage1_message_board_write == 0 &&
		FLAME_job_application_stage1_message_board_read == 0)
			rc = MB_SetAccessMode(b_job_application_stage1, MB_MODE_IDLE);
	if(FLAME_job_application_stage1_message_board_write == 1 &&
		FLAME_job_application_stage1_message_board_read == 0)
			rc = MB_SetAccessMode(b_job_application_stage1, MB_MODE_WRITEONLY);
	if(FLAME_job_application_stage1_message_board_write == 0 &&
		FLAME_job_application_stage1_message_board_read == 1)
			rc = MB_SetAccessMode(b_job_application_stage1, MB_MODE_READONLY);
	if(FLAME_job_application_stage1_message_board_write == 1 &&
		FLAME_job_application_stage1_message_board_read == 1)
			rc = MB_SetAccessMode(b_job_application_stage1, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'job_application_stage1' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'job_application_stage1' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'job_application_stage1' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_job_match_stage1_message_board_write = 0;
	FLAME_job_match_stage1_message_board_read = 0;
	/* Sending agents */
	if(jpoffice_start_state->agents != NULL) FLAME_job_match_stage1_message_board_write = 1;
	
	/* Reading agents */
	if(firm_start_state->agents != NULL) FLAME_job_match_stage1_message_board_read = 1;
	if(household_start_state->agents != NULL) FLAME_job_match_stage1_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_job_match_stage1_message_board_write == 0 &&
		FLAME_job_match_stage1_message_board_read == 0)
			rc = MB_SetAccessMode(b_job_match_stage1, MB_MODE_IDLE);
	if(FLAME_job_match_stage1_message_board_write == 1 &&
		FLAME_job_match_stage1_message_board_read == 0)
			rc = MB_SetAccessMode(b_job_match_stage1, MB_MODE_WRITEONLY);
	if(FLAME_job_match_stage1_message_board_write == 0 &&
		FLAME_job_match_stage1_message_board_read == 1)
			rc = MB_SetAccessMode(b_job_match_stage1, MB_MODE_READONLY);
	if(FLAME_job_match_stage1_message_board_write == 1 &&
		FLAME_job_match_stage1_message_board_read == 1)
			rc = MB_SetAccessMode(b_job_match_stage1, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'job_match_stage1' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'job_match_stage1' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'job_match_stage1' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_job_change_message_board_write = 0;
	FLAME_job_change_message_board_read = 0;
	/* Sending agents */
	if(household_start_state->agents != NULL) FLAME_job_change_message_board_write = 1;
	
	/* Reading agents */
	if(firm_start_state->agents != NULL) FLAME_job_change_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_job_change_message_board_write == 0 &&
		FLAME_job_change_message_board_read == 0)
			rc = MB_SetAccessMode(b_job_change, MB_MODE_IDLE);
	if(FLAME_job_change_message_board_write == 1 &&
		FLAME_job_change_message_board_read == 0)
			rc = MB_SetAccessMode(b_job_change, MB_MODE_WRITEONLY);
	if(FLAME_job_change_message_board_write == 0 &&
		FLAME_job_change_message_board_read == 1)
			rc = MB_SetAccessMode(b_job_change, MB_MODE_READONLY);
	if(FLAME_job_change_message_board_write == 1 &&
		FLAME_job_change_message_board_read == 1)
			rc = MB_SetAccessMode(b_job_change, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'job_change' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'job_change' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'job_change' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_vacancy_stage2_message_board_write = 0;
	FLAME_vacancy_stage2_message_board_read = 0;
	/* Sending agents */
	if(firm_start_state->agents != NULL) FLAME_vacancy_stage2_message_board_write = 1;
	
	/* Reading agents */
	if(jpoffice_start_state->agents != NULL) FLAME_vacancy_stage2_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_vacancy_stage2_message_board_write == 0 &&
		FLAME_vacancy_stage2_message_board_read == 0)
			rc = MB_SetAccessMode(b_vacancy_stage2, MB_MODE_IDLE);
	if(FLAME_vacancy_stage2_message_board_write == 1 &&
		FLAME_vacancy_stage2_message_board_read == 0)
			rc = MB_SetAccessMode(b_vacancy_stage2, MB_MODE_WRITEONLY);
	if(FLAME_vacancy_stage2_message_board_write == 0 &&
		FLAME_vacancy_stage2_message_board_read == 1)
			rc = MB_SetAccessMode(b_vacancy_stage2, MB_MODE_READONLY);
	if(FLAME_vacancy_stage2_message_board_write == 1 &&
		FLAME_vacancy_stage2_message_board_read == 1)
			rc = MB_SetAccessMode(b_vacancy_stage2, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'vacancy_stage2' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'vacancy_stage2' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'vacancy_stage2' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_job_match_stage2_message_board_write = 0;
	FLAME_job_match_stage2_message_board_read = 0;
	/* Sending agents */
	if(jpoffice_start_state->agents != NULL) FLAME_job_match_stage2_message_board_write = 1;
	
	/* Reading agents */
	if(firm_start_state->agents != NULL) FLAME_job_match_stage2_message_board_read = 1;
	if(household_start_state->agents != NULL) FLAME_job_match_stage2_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_job_match_stage2_message_board_write == 0 &&
		FLAME_job_match_stage2_message_board_read == 0)
			rc = MB_SetAccessMode(b_job_match_stage2, MB_MODE_IDLE);
	if(FLAME_job_match_stage2_message_board_write == 1 &&
		FLAME_job_match_stage2_message_board_read == 0)
			rc = MB_SetAccessMode(b_job_match_stage2, MB_MODE_WRITEONLY);
	if(FLAME_job_match_stage2_message_board_write == 0 &&
		FLAME_job_match_stage2_message_board_read == 1)
			rc = MB_SetAccessMode(b_job_match_stage2, MB_MODE_READONLY);
	if(FLAME_job_match_stage2_message_board_write == 1 &&
		FLAME_job_match_stage2_message_board_read == 1)
			rc = MB_SetAccessMode(b_job_match_stage2, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'job_match_stage2' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'job_match_stage2' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'job_match_stage2' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_employment_status_message_board_write = 0;
	FLAME_employment_status_message_board_read = 0;
	/* Sending agents */
	if(household_start_state->agents != NULL) FLAME_employment_status_message_board_write = 1;
	
	/* Reading agents */
	if(equityfund_start_state->agents != NULL) FLAME_employment_status_message_board_read = 1;
	if(government_start_state->agents != NULL) FLAME_employment_status_message_board_read = 1;
	if(centralbank_start_state->agents != NULL) FLAME_employment_status_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_employment_status_message_board_write == 0 &&
		FLAME_employment_status_message_board_read == 0)
			rc = MB_SetAccessMode(b_employment_status, MB_MODE_IDLE);
	if(FLAME_employment_status_message_board_write == 1 &&
		FLAME_employment_status_message_board_read == 0)
			rc = MB_SetAccessMode(b_employment_status, MB_MODE_WRITEONLY);
	if(FLAME_employment_status_message_board_write == 0 &&
		FLAME_employment_status_message_board_read == 1)
			rc = MB_SetAccessMode(b_employment_status, MB_MODE_READONLY);
	if(FLAME_employment_status_message_board_write == 1 &&
		FLAME_employment_status_message_board_read == 1)
			rc = MB_SetAccessMode(b_employment_status, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'employment_status' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'employment_status' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'employment_status' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_loan_request_1_message_board_write = 0;
	FLAME_loan_request_1_message_board_read = 0;
	/* Sending agents */
	if(firm_start_state->agents != NULL) FLAME_loan_request_1_message_board_write = 1;
	
	/* Reading agents */
	if(bank_start_state->agents != NULL) FLAME_loan_request_1_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_loan_request_1_message_board_write == 0 &&
		FLAME_loan_request_1_message_board_read == 0)
			rc = MB_SetAccessMode(b_loan_request_1, MB_MODE_IDLE);
	if(FLAME_loan_request_1_message_board_write == 1 &&
		FLAME_loan_request_1_message_board_read == 0)
			rc = MB_SetAccessMode(b_loan_request_1, MB_MODE_WRITEONLY);
	if(FLAME_loan_request_1_message_board_write == 0 &&
		FLAME_loan_request_1_message_board_read == 1)
			rc = MB_SetAccessMode(b_loan_request_1, MB_MODE_READONLY);
	if(FLAME_loan_request_1_message_board_write == 1 &&
		FLAME_loan_request_1_message_board_read == 1)
			rc = MB_SetAccessMode(b_loan_request_1, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'loan_request_1' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'loan_request_1' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'loan_request_1' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_loan_request_2_message_board_write = 0;
	FLAME_loan_request_2_message_board_read = 0;
	/* Sending agents */
	if(firm_start_state->agents != NULL) FLAME_loan_request_2_message_board_write = 1;
	
	/* Reading agents */
	if(bank_start_state->agents != NULL) FLAME_loan_request_2_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_loan_request_2_message_board_write == 0 &&
		FLAME_loan_request_2_message_board_read == 0)
			rc = MB_SetAccessMode(b_loan_request_2, MB_MODE_IDLE);
	if(FLAME_loan_request_2_message_board_write == 1 &&
		FLAME_loan_request_2_message_board_read == 0)
			rc = MB_SetAccessMode(b_loan_request_2, MB_MODE_WRITEONLY);
	if(FLAME_loan_request_2_message_board_write == 0 &&
		FLAME_loan_request_2_message_board_read == 1)
			rc = MB_SetAccessMode(b_loan_request_2, MB_MODE_READONLY);
	if(FLAME_loan_request_2_message_board_write == 1 &&
		FLAME_loan_request_2_message_board_read == 1)
			rc = MB_SetAccessMode(b_loan_request_2, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'loan_request_2' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'loan_request_2' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'loan_request_2' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_loan_acknowledge_1_message_board_write = 0;
	FLAME_loan_acknowledge_1_message_board_read = 0;
	/* Sending agents */
	if(bank_start_state->agents != NULL) FLAME_loan_acknowledge_1_message_board_write = 1;
	
	/* Reading agents */
	if(firm_start_state->agents != NULL) FLAME_loan_acknowledge_1_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_loan_acknowledge_1_message_board_write == 0 &&
		FLAME_loan_acknowledge_1_message_board_read == 0)
			rc = MB_SetAccessMode(b_loan_acknowledge_1, MB_MODE_IDLE);
	if(FLAME_loan_acknowledge_1_message_board_write == 1 &&
		FLAME_loan_acknowledge_1_message_board_read == 0)
			rc = MB_SetAccessMode(b_loan_acknowledge_1, MB_MODE_WRITEONLY);
	if(FLAME_loan_acknowledge_1_message_board_write == 0 &&
		FLAME_loan_acknowledge_1_message_board_read == 1)
			rc = MB_SetAccessMode(b_loan_acknowledge_1, MB_MODE_READONLY);
	if(FLAME_loan_acknowledge_1_message_board_write == 1 &&
		FLAME_loan_acknowledge_1_message_board_read == 1)
			rc = MB_SetAccessMode(b_loan_acknowledge_1, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'loan_acknowledge_1' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'loan_acknowledge_1' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'loan_acknowledge_1' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_loan_acknowledge_2_message_board_write = 0;
	FLAME_loan_acknowledge_2_message_board_read = 0;
	/* Sending agents */
	if(bank_start_state->agents != NULL) FLAME_loan_acknowledge_2_message_board_write = 1;
	
	/* Reading agents */
	if(firm_start_state->agents != NULL) FLAME_loan_acknowledge_2_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_loan_acknowledge_2_message_board_write == 0 &&
		FLAME_loan_acknowledge_2_message_board_read == 0)
			rc = MB_SetAccessMode(b_loan_acknowledge_2, MB_MODE_IDLE);
	if(FLAME_loan_acknowledge_2_message_board_write == 1 &&
		FLAME_loan_acknowledge_2_message_board_read == 0)
			rc = MB_SetAccessMode(b_loan_acknowledge_2, MB_MODE_WRITEONLY);
	if(FLAME_loan_acknowledge_2_message_board_write == 0 &&
		FLAME_loan_acknowledge_2_message_board_read == 1)
			rc = MB_SetAccessMode(b_loan_acknowledge_2, MB_MODE_READONLY);
	if(FLAME_loan_acknowledge_2_message_board_write == 1 &&
		FLAME_loan_acknowledge_2_message_board_read == 1)
			rc = MB_SetAccessMode(b_loan_acknowledge_2, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'loan_acknowledge_2' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'loan_acknowledge_2' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'loan_acknowledge_2' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_debt_request_message_board_write = 0;
	FLAME_debt_request_message_board_read = 0;
	/* Sending agents */
	if(bank_start_state->agents != NULL) FLAME_debt_request_message_board_write = 1;
	
	/* Reading agents */
	if(centralbank_start_state->agents != NULL) FLAME_debt_request_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_debt_request_message_board_write == 0 &&
		FLAME_debt_request_message_board_read == 0)
			rc = MB_SetAccessMode(b_debt_request, MB_MODE_IDLE);
	if(FLAME_debt_request_message_board_write == 1 &&
		FLAME_debt_request_message_board_read == 0)
			rc = MB_SetAccessMode(b_debt_request, MB_MODE_WRITEONLY);
	if(FLAME_debt_request_message_board_write == 0 &&
		FLAME_debt_request_message_board_read == 1)
			rc = MB_SetAccessMode(b_debt_request, MB_MODE_READONLY);
	if(FLAME_debt_request_message_board_write == 1 &&
		FLAME_debt_request_message_board_read == 1)
			rc = MB_SetAccessMode(b_debt_request, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'debt_request' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'debt_request' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'debt_request' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_household_share_message_board_write = 0;
	FLAME_household_share_message_board_read = 0;
	/* Sending agents */
	if(equityfund_start_state->agents != NULL) FLAME_household_share_message_board_write = 1;
	
	/* Reading agents */
	if(household_start_state->agents != NULL) FLAME_household_share_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_household_share_message_board_write == 0 &&
		FLAME_household_share_message_board_read == 0)
			rc = MB_SetAccessMode(b_household_share, MB_MODE_IDLE);
	if(FLAME_household_share_message_board_write == 1 &&
		FLAME_household_share_message_board_read == 0)
			rc = MB_SetAccessMode(b_household_share, MB_MODE_WRITEONLY);
	if(FLAME_household_share_message_board_write == 0 &&
		FLAME_household_share_message_board_read == 1)
			rc = MB_SetAccessMode(b_household_share, MB_MODE_READONLY);
	if(FLAME_household_share_message_board_write == 1 &&
		FLAME_household_share_message_board_read == 1)
			rc = MB_SetAccessMode(b_household_share, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'household_share' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'household_share' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'household_share' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_capital_tax_message_board_write = 0;
	FLAME_capital_tax_message_board_read = 0;
	/* Sending agents */
	if(equityfund_start_state->agents != NULL) FLAME_capital_tax_message_board_write = 1;
	
	/* Reading agents */
	if(government_start_state->agents != NULL) FLAME_capital_tax_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_capital_tax_message_board_write == 0 &&
		FLAME_capital_tax_message_board_read == 0)
			rc = MB_SetAccessMode(b_capital_tax, MB_MODE_IDLE);
	if(FLAME_capital_tax_message_board_write == 1 &&
		FLAME_capital_tax_message_board_read == 0)
			rc = MB_SetAccessMode(b_capital_tax, MB_MODE_WRITEONLY);
	if(FLAME_capital_tax_message_board_write == 0 &&
		FLAME_capital_tax_message_board_read == 1)
			rc = MB_SetAccessMode(b_capital_tax, MB_MODE_READONLY);
	if(FLAME_capital_tax_message_board_write == 1 &&
		FLAME_capital_tax_message_board_read == 1)
			rc = MB_SetAccessMode(b_capital_tax, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'capital_tax' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'capital_tax' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'capital_tax' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_labour_tax_message_board_write = 0;
	FLAME_labour_tax_message_board_read = 0;
	/* Sending agents */
	if(firm_start_state->agents != NULL) FLAME_labour_tax_message_board_write = 1;
	
	/* Reading agents */
	if(government_start_state->agents != NULL) FLAME_labour_tax_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_labour_tax_message_board_write == 0 &&
		FLAME_labour_tax_message_board_read == 0)
			rc = MB_SetAccessMode(b_labour_tax, MB_MODE_IDLE);
	if(FLAME_labour_tax_message_board_write == 1 &&
		FLAME_labour_tax_message_board_read == 0)
			rc = MB_SetAccessMode(b_labour_tax, MB_MODE_WRITEONLY);
	if(FLAME_labour_tax_message_board_write == 0 &&
		FLAME_labour_tax_message_board_read == 1)
			rc = MB_SetAccessMode(b_labour_tax, MB_MODE_READONLY);
	if(FLAME_labour_tax_message_board_write == 1 &&
		FLAME_labour_tax_message_board_read == 1)
			rc = MB_SetAccessMode(b_labour_tax, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'labour_tax' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'labour_tax' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'labour_tax' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_unemployment_benefit_message_board_write = 0;
	FLAME_unemployment_benefit_message_board_read = 0;
	/* Sending agents */
	if(government_start_state->agents != NULL) FLAME_unemployment_benefit_message_board_write = 1;
	
	/* Reading agents */
	if(household_start_state->agents != NULL) FLAME_unemployment_benefit_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_unemployment_benefit_message_board_write == 0 &&
		FLAME_unemployment_benefit_message_board_read == 0)
			rc = MB_SetAccessMode(b_unemployment_benefit, MB_MODE_IDLE);
	if(FLAME_unemployment_benefit_message_board_write == 1 &&
		FLAME_unemployment_benefit_message_board_read == 0)
			rc = MB_SetAccessMode(b_unemployment_benefit, MB_MODE_WRITEONLY);
	if(FLAME_unemployment_benefit_message_board_write == 0 &&
		FLAME_unemployment_benefit_message_board_read == 1)
			rc = MB_SetAccessMode(b_unemployment_benefit, MB_MODE_READONLY);
	if(FLAME_unemployment_benefit_message_board_write == 1 &&
		FLAME_unemployment_benefit_message_board_read == 1)
			rc = MB_SetAccessMode(b_unemployment_benefit, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'unemployment_benefit' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'unemployment_benefit' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'unemployment_benefit' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_general_benefit_message_board_write = 0;
	FLAME_general_benefit_message_board_read = 0;
	/* Sending agents */
	if(government_start_state->agents != NULL) FLAME_general_benefit_message_board_write = 1;
	
	/* Reading agents */
	if(household_start_state->agents != NULL) FLAME_general_benefit_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_general_benefit_message_board_write == 0 &&
		FLAME_general_benefit_message_board_read == 0)
			rc = MB_SetAccessMode(b_general_benefit, MB_MODE_IDLE);
	if(FLAME_general_benefit_message_board_write == 1 &&
		FLAME_general_benefit_message_board_read == 0)
			rc = MB_SetAccessMode(b_general_benefit, MB_MODE_WRITEONLY);
	if(FLAME_general_benefit_message_board_write == 0 &&
		FLAME_general_benefit_message_board_read == 1)
			rc = MB_SetAccessMode(b_general_benefit, MB_MODE_READONLY);
	if(FLAME_general_benefit_message_board_write == 1 &&
		FLAME_general_benefit_message_board_read == 1)
			rc = MB_SetAccessMode(b_general_benefit, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'general_benefit' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'general_benefit' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'general_benefit' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_fund_request_message_board_write = 0;
	FLAME_fund_request_message_board_read = 0;
	/* Sending agents */
	if(firm_start_state->agents != NULL) FLAME_fund_request_message_board_write = 1;
	
	/* Reading agents */
	if(equityfund_start_state->agents != NULL) FLAME_fund_request_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_fund_request_message_board_write == 0 &&
		FLAME_fund_request_message_board_read == 0)
			rc = MB_SetAccessMode(b_fund_request, MB_MODE_IDLE);
	if(FLAME_fund_request_message_board_write == 1 &&
		FLAME_fund_request_message_board_read == 0)
			rc = MB_SetAccessMode(b_fund_request, MB_MODE_WRITEONLY);
	if(FLAME_fund_request_message_board_write == 0 &&
		FLAME_fund_request_message_board_read == 1)
			rc = MB_SetAccessMode(b_fund_request, MB_MODE_READONLY);
	if(FLAME_fund_request_message_board_write == 1 &&
		FLAME_fund_request_message_board_read == 1)
			rc = MB_SetAccessMode(b_fund_request, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'fund_request' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'fund_request' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'fund_request' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_fund_request_ack_message_board_write = 0;
	FLAME_fund_request_ack_message_board_read = 0;
	/* Sending agents */
	if(equityfund_start_state->agents != NULL) FLAME_fund_request_ack_message_board_write = 1;
	
	/* Reading agents */
	if(firm_start_state->agents != NULL) FLAME_fund_request_ack_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_fund_request_ack_message_board_write == 0 &&
		FLAME_fund_request_ack_message_board_read == 0)
			rc = MB_SetAccessMode(b_fund_request_ack, MB_MODE_IDLE);
	if(FLAME_fund_request_ack_message_board_write == 1 &&
		FLAME_fund_request_ack_message_board_read == 0)
			rc = MB_SetAccessMode(b_fund_request_ack, MB_MODE_WRITEONLY);
	if(FLAME_fund_request_ack_message_board_write == 0 &&
		FLAME_fund_request_ack_message_board_read == 1)
			rc = MB_SetAccessMode(b_fund_request_ack, MB_MODE_READONLY);
	if(FLAME_fund_request_ack_message_board_write == 1 &&
		FLAME_fund_request_ack_message_board_read == 1)
			rc = MB_SetAccessMode(b_fund_request_ack, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'fund_request_ack' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'fund_request_ack' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'fund_request_ack' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_new_entrant_loan_message_board_write = 0;
	FLAME_new_entrant_loan_message_board_read = 0;
	/* Sending agents */
	if(firm_start_state->agents != NULL) FLAME_new_entrant_loan_message_board_write = 1;
	
	/* Reading agents */
	if(bank_start_state->agents != NULL) FLAME_new_entrant_loan_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_new_entrant_loan_message_board_write == 0 &&
		FLAME_new_entrant_loan_message_board_read == 0)
			rc = MB_SetAccessMode(b_new_entrant_loan, MB_MODE_IDLE);
	if(FLAME_new_entrant_loan_message_board_write == 1 &&
		FLAME_new_entrant_loan_message_board_read == 0)
			rc = MB_SetAccessMode(b_new_entrant_loan, MB_MODE_WRITEONLY);
	if(FLAME_new_entrant_loan_message_board_write == 0 &&
		FLAME_new_entrant_loan_message_board_read == 1)
			rc = MB_SetAccessMode(b_new_entrant_loan, MB_MODE_READONLY);
	if(FLAME_new_entrant_loan_message_board_write == 1 &&
		FLAME_new_entrant_loan_message_board_read == 1)
			rc = MB_SetAccessMode(b_new_entrant_loan, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'new_entrant_loan' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'new_entrant_loan' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'new_entrant_loan' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_interest_on_loan_message_board_write = 0;
	FLAME_interest_on_loan_message_board_read = 0;
	/* Sending agents */
	if(firm_start_state->agents != NULL) FLAME_interest_on_loan_message_board_write = 1;
	
	/* Reading agents */
	if(bank_start_state->agents != NULL) FLAME_interest_on_loan_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_interest_on_loan_message_board_write == 0 &&
		FLAME_interest_on_loan_message_board_read == 0)
			rc = MB_SetAccessMode(b_interest_on_loan, MB_MODE_IDLE);
	if(FLAME_interest_on_loan_message_board_write == 1 &&
		FLAME_interest_on_loan_message_board_read == 0)
			rc = MB_SetAccessMode(b_interest_on_loan, MB_MODE_WRITEONLY);
	if(FLAME_interest_on_loan_message_board_write == 0 &&
		FLAME_interest_on_loan_message_board_read == 1)
			rc = MB_SetAccessMode(b_interest_on_loan, MB_MODE_READONLY);
	if(FLAME_interest_on_loan_message_board_write == 1 &&
		FLAME_interest_on_loan_message_board_read == 1)
			rc = MB_SetAccessMode(b_interest_on_loan, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'interest_on_loan' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'interest_on_loan' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'interest_on_loan' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_loan_writeoff_message_board_write = 0;
	FLAME_loan_writeoff_message_board_read = 0;
	/* Sending agents */
	if(firm_start_state->agents != NULL) FLAME_loan_writeoff_message_board_write = 1;
	
	/* Reading agents */
	if(bank_start_state->agents != NULL) FLAME_loan_writeoff_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_loan_writeoff_message_board_write == 0 &&
		FLAME_loan_writeoff_message_board_read == 0)
			rc = MB_SetAccessMode(b_loan_writeoff, MB_MODE_IDLE);
	if(FLAME_loan_writeoff_message_board_write == 1 &&
		FLAME_loan_writeoff_message_board_read == 0)
			rc = MB_SetAccessMode(b_loan_writeoff, MB_MODE_WRITEONLY);
	if(FLAME_loan_writeoff_message_board_write == 0 &&
		FLAME_loan_writeoff_message_board_read == 1)
			rc = MB_SetAccessMode(b_loan_writeoff, MB_MODE_READONLY);
	if(FLAME_loan_writeoff_message_board_write == 1 &&
		FLAME_loan_writeoff_message_board_read == 1)
			rc = MB_SetAccessMode(b_loan_writeoff, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'loan_writeoff' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'loan_writeoff' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'loan_writeoff' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_firm_net_profit_message_board_write = 0;
	FLAME_firm_net_profit_message_board_read = 0;
	/* Sending agents */
	if(firm_start_state->agents != NULL) FLAME_firm_net_profit_message_board_write = 1;
	
	/* Reading agents */
	if(equityfund_start_state->agents != NULL) FLAME_firm_net_profit_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_firm_net_profit_message_board_write == 0 &&
		FLAME_firm_net_profit_message_board_read == 0)
			rc = MB_SetAccessMode(b_firm_net_profit, MB_MODE_IDLE);
	if(FLAME_firm_net_profit_message_board_write == 1 &&
		FLAME_firm_net_profit_message_board_read == 0)
			rc = MB_SetAccessMode(b_firm_net_profit, MB_MODE_WRITEONLY);
	if(FLAME_firm_net_profit_message_board_write == 0 &&
		FLAME_firm_net_profit_message_board_read == 1)
			rc = MB_SetAccessMode(b_firm_net_profit, MB_MODE_READONLY);
	if(FLAME_firm_net_profit_message_board_write == 1 &&
		FLAME_firm_net_profit_message_board_read == 1)
			rc = MB_SetAccessMode(b_firm_net_profit, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'firm_net_profit' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'firm_net_profit' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'firm_net_profit' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_bank_net_profit_message_board_write = 0;
	FLAME_bank_net_profit_message_board_read = 0;
	/* Sending agents */
	if(bank_start_state->agents != NULL) FLAME_bank_net_profit_message_board_write = 1;
	
	/* Reading agents */
	if(equityfund_start_state->agents != NULL) FLAME_bank_net_profit_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_bank_net_profit_message_board_write == 0 &&
		FLAME_bank_net_profit_message_board_read == 0)
			rc = MB_SetAccessMode(b_bank_net_profit, MB_MODE_IDLE);
	if(FLAME_bank_net_profit_message_board_write == 1 &&
		FLAME_bank_net_profit_message_board_read == 0)
			rc = MB_SetAccessMode(b_bank_net_profit, MB_MODE_WRITEONLY);
	if(FLAME_bank_net_profit_message_board_write == 0 &&
		FLAME_bank_net_profit_message_board_read == 1)
			rc = MB_SetAccessMode(b_bank_net_profit, MB_MODE_READONLY);
	if(FLAME_bank_net_profit_message_board_write == 1 &&
		FLAME_bank_net_profit_message_board_read == 1)
			rc = MB_SetAccessMode(b_bank_net_profit, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'bank_net_profit' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'bank_net_profit' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'bank_net_profit' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_bank_centralbank_interest_payment_message_board_write = 0;
	FLAME_bank_centralbank_interest_payment_message_board_read = 0;
	/* Sending agents */
	if(bank_start_state->agents != NULL) FLAME_bank_centralbank_interest_payment_message_board_write = 1;
	
	/* Reading agents */
	if(centralbank_start_state->agents != NULL) FLAME_bank_centralbank_interest_payment_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_bank_centralbank_interest_payment_message_board_write == 0 &&
		FLAME_bank_centralbank_interest_payment_message_board_read == 0)
			rc = MB_SetAccessMode(b_bank_centralbank_interest_payment, MB_MODE_IDLE);
	if(FLAME_bank_centralbank_interest_payment_message_board_write == 1 &&
		FLAME_bank_centralbank_interest_payment_message_board_read == 0)
			rc = MB_SetAccessMode(b_bank_centralbank_interest_payment, MB_MODE_WRITEONLY);
	if(FLAME_bank_centralbank_interest_payment_message_board_write == 0 &&
		FLAME_bank_centralbank_interest_payment_message_board_read == 1)
			rc = MB_SetAccessMode(b_bank_centralbank_interest_payment, MB_MODE_READONLY);
	if(FLAME_bank_centralbank_interest_payment_message_board_write == 1 &&
		FLAME_bank_centralbank_interest_payment_message_board_read == 1)
			rc = MB_SetAccessMode(b_bank_centralbank_interest_payment, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'bank_centralbank_interest_payment' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_bank_centralbank_debt_payment_message_board_write = 0;
	FLAME_bank_centralbank_debt_payment_message_board_read = 0;
	/* Sending agents */
	if(bank_start_state->agents != NULL) FLAME_bank_centralbank_debt_payment_message_board_write = 1;
	
	/* Reading agents */
	if(centralbank_start_state->agents != NULL) FLAME_bank_centralbank_debt_payment_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_bank_centralbank_debt_payment_message_board_write == 0 &&
		FLAME_bank_centralbank_debt_payment_message_board_read == 0)
			rc = MB_SetAccessMode(b_bank_centralbank_debt_payment, MB_MODE_IDLE);
	if(FLAME_bank_centralbank_debt_payment_message_board_write == 1 &&
		FLAME_bank_centralbank_debt_payment_message_board_read == 0)
			rc = MB_SetAccessMode(b_bank_centralbank_debt_payment, MB_MODE_WRITEONLY);
	if(FLAME_bank_centralbank_debt_payment_message_board_write == 0 &&
		FLAME_bank_centralbank_debt_payment_message_board_read == 1)
			rc = MB_SetAccessMode(b_bank_centralbank_debt_payment, MB_MODE_READONLY);
	if(FLAME_bank_centralbank_debt_payment_message_board_write == 1 &&
		FLAME_bank_centralbank_debt_payment_message_board_read == 1)
			rc = MB_SetAccessMode(b_bank_centralbank_debt_payment, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'bank_centralbank_debt_payment' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_centralbank_government_profit_message_board_write = 0;
	FLAME_centralbank_government_profit_message_board_read = 0;
	/* Sending agents */
	if(centralbank_start_state->agents != NULL) FLAME_centralbank_government_profit_message_board_write = 1;
	
	/* Reading agents */
	if(government_start_state->agents != NULL) FLAME_centralbank_government_profit_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_centralbank_government_profit_message_board_write == 0 &&
		FLAME_centralbank_government_profit_message_board_read == 0)
			rc = MB_SetAccessMode(b_centralbank_government_profit, MB_MODE_IDLE);
	if(FLAME_centralbank_government_profit_message_board_write == 1 &&
		FLAME_centralbank_government_profit_message_board_read == 0)
			rc = MB_SetAccessMode(b_centralbank_government_profit, MB_MODE_WRITEONLY);
	if(FLAME_centralbank_government_profit_message_board_write == 0 &&
		FLAME_centralbank_government_profit_message_board_read == 1)
			rc = MB_SetAccessMode(b_centralbank_government_profit, MB_MODE_READONLY);
	if(FLAME_centralbank_government_profit_message_board_write == 1 &&
		FLAME_centralbank_government_profit_message_board_read == 1)
			rc = MB_SetAccessMode(b_centralbank_government_profit, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'centralbank_government_profit' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'centralbank_government_profit' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'centralbank_government_profit' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_housing_price_message_board_write = 0;
	FLAME_housing_price_message_board_read = 0;
	/* Sending agents */
	if(reagency_start_state->agents != NULL) FLAME_housing_price_message_board_write = 1;
	
	/* Reading agents */
	if(firm_start_state->agents != NULL) FLAME_housing_price_message_board_read = 1;
	if(household_start_state->agents != NULL) FLAME_housing_price_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_housing_price_message_board_write == 0 &&
		FLAME_housing_price_message_board_read == 0)
			rc = MB_SetAccessMode(b_housing_price, MB_MODE_IDLE);
	if(FLAME_housing_price_message_board_write == 1 &&
		FLAME_housing_price_message_board_read == 0)
			rc = MB_SetAccessMode(b_housing_price, MB_MODE_WRITEONLY);
	if(FLAME_housing_price_message_board_write == 0 &&
		FLAME_housing_price_message_board_read == 1)
			rc = MB_SetAccessMode(b_housing_price, MB_MODE_READONLY);
	if(FLAME_housing_price_message_board_write == 1 &&
		FLAME_housing_price_message_board_read == 1)
			rc = MB_SetAccessMode(b_housing_price, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'housing_price' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'housing_price' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'housing_price' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_buy_housing_message_board_write = 0;
	FLAME_buy_housing_message_board_read = 0;
	/* Sending agents */
	if(household_start_state->agents != NULL) FLAME_buy_housing_message_board_write = 1;
	
	/* Reading agents */
	if(reagency_start_state->agents != NULL) FLAME_buy_housing_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_buy_housing_message_board_write == 0 &&
		FLAME_buy_housing_message_board_read == 0)
			rc = MB_SetAccessMode(b_buy_housing, MB_MODE_IDLE);
	if(FLAME_buy_housing_message_board_write == 1 &&
		FLAME_buy_housing_message_board_read == 0)
			rc = MB_SetAccessMode(b_buy_housing, MB_MODE_WRITEONLY);
	if(FLAME_buy_housing_message_board_write == 0 &&
		FLAME_buy_housing_message_board_read == 1)
			rc = MB_SetAccessMode(b_buy_housing, MB_MODE_READONLY);
	if(FLAME_buy_housing_message_board_write == 1 &&
		FLAME_buy_housing_message_board_read == 1)
			rc = MB_SetAccessMode(b_buy_housing, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'buy_housing' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'buy_housing' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'buy_housing' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_sell_housing_message_board_write = 0;
	FLAME_sell_housing_message_board_read = 0;
	/* Sending agents */
	if(firm_start_state->agents != NULL) FLAME_sell_housing_message_board_write = 1;
	if(household_start_state->agents != NULL) FLAME_sell_housing_message_board_write = 1;
	
	/* Reading agents */
	if(reagency_start_state->agents != NULL) FLAME_sell_housing_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_sell_housing_message_board_write == 0 &&
		FLAME_sell_housing_message_board_read == 0)
			rc = MB_SetAccessMode(b_sell_housing, MB_MODE_IDLE);
	if(FLAME_sell_housing_message_board_write == 1 &&
		FLAME_sell_housing_message_board_read == 0)
			rc = MB_SetAccessMode(b_sell_housing, MB_MODE_WRITEONLY);
	if(FLAME_sell_housing_message_board_write == 0 &&
		FLAME_sell_housing_message_board_read == 1)
			rc = MB_SetAccessMode(b_sell_housing, MB_MODE_READONLY);
	if(FLAME_sell_housing_message_board_write == 1 &&
		FLAME_sell_housing_message_board_read == 1)
			rc = MB_SetAccessMode(b_sell_housing, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'sell_housing' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'sell_housing' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'sell_housing' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_bought_housing_message_board_write = 0;
	FLAME_bought_housing_message_board_read = 0;
	/* Sending agents */
	if(reagency_start_state->agents != NULL) FLAME_bought_housing_message_board_write = 1;
	
	/* Reading agents */
	if(household_start_state->agents != NULL) FLAME_bought_housing_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_bought_housing_message_board_write == 0 &&
		FLAME_bought_housing_message_board_read == 0)
			rc = MB_SetAccessMode(b_bought_housing, MB_MODE_IDLE);
	if(FLAME_bought_housing_message_board_write == 1 &&
		FLAME_bought_housing_message_board_read == 0)
			rc = MB_SetAccessMode(b_bought_housing, MB_MODE_WRITEONLY);
	if(FLAME_bought_housing_message_board_write == 0 &&
		FLAME_bought_housing_message_board_read == 1)
			rc = MB_SetAccessMode(b_bought_housing, MB_MODE_READONLY);
	if(FLAME_bought_housing_message_board_write == 1 &&
		FLAME_bought_housing_message_board_read == 1)
			rc = MB_SetAccessMode(b_bought_housing, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'bought_housing' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'bought_housing' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'bought_housing' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_sold_housing_message_board_write = 0;
	FLAME_sold_housing_message_board_read = 0;
	/* Sending agents */
	if(reagency_start_state->agents != NULL) FLAME_sold_housing_message_board_write = 1;
	
	/* Reading agents */
	if(firm_start_state->agents != NULL) FLAME_sold_housing_message_board_read = 1;
	if(household_start_state->agents != NULL) FLAME_sold_housing_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_sold_housing_message_board_write == 0 &&
		FLAME_sold_housing_message_board_read == 0)
			rc = MB_SetAccessMode(b_sold_housing, MB_MODE_IDLE);
	if(FLAME_sold_housing_message_board_write == 1 &&
		FLAME_sold_housing_message_board_read == 0)
			rc = MB_SetAccessMode(b_sold_housing, MB_MODE_WRITEONLY);
	if(FLAME_sold_housing_message_board_write == 0 &&
		FLAME_sold_housing_message_board_read == 1)
			rc = MB_SetAccessMode(b_sold_housing, MB_MODE_READONLY);
	if(FLAME_sold_housing_message_board_write == 1 &&
		FLAME_sold_housing_message_board_read == 1)
			rc = MB_SetAccessMode(b_sold_housing, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'sold_housing' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'sold_housing' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'sold_housing' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_mortgaging_capacity_message_board_write = 0;
	FLAME_mortgaging_capacity_message_board_read = 0;
	/* Sending agents */
	if(bank_start_state->agents != NULL) FLAME_mortgaging_capacity_message_board_write = 1;
	
	/* Reading agents */
	if(reagency_start_state->agents != NULL) FLAME_mortgaging_capacity_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_mortgaging_capacity_message_board_write == 0 &&
		FLAME_mortgaging_capacity_message_board_read == 0)
			rc = MB_SetAccessMode(b_mortgaging_capacity, MB_MODE_IDLE);
	if(FLAME_mortgaging_capacity_message_board_write == 1 &&
		FLAME_mortgaging_capacity_message_board_read == 0)
			rc = MB_SetAccessMode(b_mortgaging_capacity, MB_MODE_WRITEONLY);
	if(FLAME_mortgaging_capacity_message_board_write == 0 &&
		FLAME_mortgaging_capacity_message_board_read == 1)
			rc = MB_SetAccessMode(b_mortgaging_capacity, MB_MODE_READONLY);
	if(FLAME_mortgaging_capacity_message_board_write == 1 &&
		FLAME_mortgaging_capacity_message_board_read == 1)
			rc = MB_SetAccessMode(b_mortgaging_capacity, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'mortgaging_capacity' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'mortgaging_capacity' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'mortgaging_capacity' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_mortgage_requests_message_board_write = 0;
	FLAME_mortgage_requests_message_board_read = 0;
	/* Sending agents */
	if(reagency_start_state->agents != NULL) FLAME_mortgage_requests_message_board_write = 1;
	
	/* Reading agents */
	if(bank_start_state->agents != NULL) FLAME_mortgage_requests_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_mortgage_requests_message_board_write == 0 &&
		FLAME_mortgage_requests_message_board_read == 0)
			rc = MB_SetAccessMode(b_mortgage_requests, MB_MODE_IDLE);
	if(FLAME_mortgage_requests_message_board_write == 1 &&
		FLAME_mortgage_requests_message_board_read == 0)
			rc = MB_SetAccessMode(b_mortgage_requests, MB_MODE_WRITEONLY);
	if(FLAME_mortgage_requests_message_board_write == 0 &&
		FLAME_mortgage_requests_message_board_read == 1)
			rc = MB_SetAccessMode(b_mortgage_requests, MB_MODE_READONLY);
	if(FLAME_mortgage_requests_message_board_write == 1 &&
		FLAME_mortgage_requests_message_board_read == 1)
			rc = MB_SetAccessMode(b_mortgage_requests, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'mortgage_requests' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'mortgage_requests' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'mortgage_requests' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_mortgage_payment_from_sale_message_board_write = 0;
	FLAME_mortgage_payment_from_sale_message_board_read = 0;
	/* Sending agents */
	if(household_start_state->agents != NULL) FLAME_mortgage_payment_from_sale_message_board_write = 1;
	
	/* Reading agents */
	if(bank_start_state->agents != NULL) FLAME_mortgage_payment_from_sale_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_mortgage_payment_from_sale_message_board_write == 0 &&
		FLAME_mortgage_payment_from_sale_message_board_read == 0)
			rc = MB_SetAccessMode(b_mortgage_payment_from_sale, MB_MODE_IDLE);
	if(FLAME_mortgage_payment_from_sale_message_board_write == 1 &&
		FLAME_mortgage_payment_from_sale_message_board_read == 0)
			rc = MB_SetAccessMode(b_mortgage_payment_from_sale, MB_MODE_WRITEONLY);
	if(FLAME_mortgage_payment_from_sale_message_board_write == 0 &&
		FLAME_mortgage_payment_from_sale_message_board_read == 1)
			rc = MB_SetAccessMode(b_mortgage_payment_from_sale, MB_MODE_READONLY);
	if(FLAME_mortgage_payment_from_sale_message_board_write == 1 &&
		FLAME_mortgage_payment_from_sale_message_board_read == 1)
			rc = MB_SetAccessMode(b_mortgage_payment_from_sale, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'mortgage_payment_from_sale' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_mortgage_payment_message_board_write = 0;
	FLAME_mortgage_payment_message_board_read = 0;
	/* Sending agents */
	if(household_start_state->agents != NULL) FLAME_mortgage_payment_message_board_write = 1;
	
	/* Reading agents */
	if(bank_start_state->agents != NULL) FLAME_mortgage_payment_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_mortgage_payment_message_board_write == 0 &&
		FLAME_mortgage_payment_message_board_read == 0)
			rc = MB_SetAccessMode(b_mortgage_payment, MB_MODE_IDLE);
	if(FLAME_mortgage_payment_message_board_write == 1 &&
		FLAME_mortgage_payment_message_board_read == 0)
			rc = MB_SetAccessMode(b_mortgage_payment, MB_MODE_WRITEONLY);
	if(FLAME_mortgage_payment_message_board_write == 0 &&
		FLAME_mortgage_payment_message_board_read == 1)
			rc = MB_SetAccessMode(b_mortgage_payment, MB_MODE_READONLY);
	if(FLAME_mortgage_payment_message_board_write == 1 &&
		FLAME_mortgage_payment_message_board_read == 1)
			rc = MB_SetAccessMode(b_mortgage_payment, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'mortgage_payment' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'mortgage_payment' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'mortgage_payment' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_mortgage_writeoff_message_board_write = 0;
	FLAME_mortgage_writeoff_message_board_read = 0;
	/* Sending agents */
	if(household_start_state->agents != NULL) FLAME_mortgage_writeoff_message_board_write = 1;
	
	/* Reading agents */
	if(bank_start_state->agents != NULL) FLAME_mortgage_writeoff_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_mortgage_writeoff_message_board_write == 0 &&
		FLAME_mortgage_writeoff_message_board_read == 0)
			rc = MB_SetAccessMode(b_mortgage_writeoff, MB_MODE_IDLE);
	if(FLAME_mortgage_writeoff_message_board_write == 1 &&
		FLAME_mortgage_writeoff_message_board_read == 0)
			rc = MB_SetAccessMode(b_mortgage_writeoff, MB_MODE_WRITEONLY);
	if(FLAME_mortgage_writeoff_message_board_write == 0 &&
		FLAME_mortgage_writeoff_message_board_read == 1)
			rc = MB_SetAccessMode(b_mortgage_writeoff, MB_MODE_READONLY);
	if(FLAME_mortgage_writeoff_message_board_write == 1 &&
		FLAME_mortgage_writeoff_message_board_read == 1)
			rc = MB_SetAccessMode(b_mortgage_writeoff, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'mortgage_writeoff' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'mortgage_writeoff' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'mortgage_writeoff' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_housing_transactions_summary_message_board_write = 0;
	FLAME_housing_transactions_summary_message_board_read = 0;
	/* Sending agents */
	if(reagency_start_state->agents != NULL) FLAME_housing_transactions_summary_message_board_write = 1;
	
	/* Reading agents */
	if(centralbank_start_state->agents != NULL) FLAME_housing_transactions_summary_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_housing_transactions_summary_message_board_write == 0 &&
		FLAME_housing_transactions_summary_message_board_read == 0)
			rc = MB_SetAccessMode(b_housing_transactions_summary, MB_MODE_IDLE);
	if(FLAME_housing_transactions_summary_message_board_write == 1 &&
		FLAME_housing_transactions_summary_message_board_read == 0)
			rc = MB_SetAccessMode(b_housing_transactions_summary, MB_MODE_WRITEONLY);
	if(FLAME_housing_transactions_summary_message_board_write == 0 &&
		FLAME_housing_transactions_summary_message_board_read == 1)
			rc = MB_SetAccessMode(b_housing_transactions_summary, MB_MODE_READONLY);
	if(FLAME_housing_transactions_summary_message_board_write == 1 &&
		FLAME_housing_transactions_summary_message_board_read == 1)
			rc = MB_SetAccessMode(b_housing_transactions_summary, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'housing_transactions_summary' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'housing_transactions_summary' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'housing_transactions_summary' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	
	
	/* Start timing */
	start = get_time();

	for(iteration_loop=iteration_number+1; iteration_loop < iteration_number+iteration_total+1; iteration_loop++)
	{
		interval = get_time();

		/* Print out iteration number */
		
		fprintf(stdout, "Iteration - %d\n", iteration_loop);
		(void)fflush(stdout);
        
		/* START OF ITERATION */
		
		/* Start sync message boards that don't write */
		if(FLAME_firm_bank_update_deposit_message_board_write == 0)
		{
			/*printf("%d> firm_bank_update_deposit message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_firm_bank_update_deposit)\n");
			rc = MB_SyncStart(b_firm_bank_update_deposit);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_firm_bank_update_deposit)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'firm_bank_update_deposit' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_household_bank_update_deposit_message_board_write == 0)
		{
			/*printf("%d> household_bank_update_deposit message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_household_bank_update_deposit)\n");
			rc = MB_SyncStart(b_household_bank_update_deposit);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_household_bank_update_deposit)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'household_bank_update_deposit' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'household_bank_update_deposit' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'household_bank_update_deposit' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_interest_rate_message_board_write == 0)
		{
			/*printf("%d> interest_rate message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_interest_rate)\n");
			rc = MB_SyncStart(b_interest_rate);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_interest_rate)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'interest_rate' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'interest_rate' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'interest_rate' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_tax_rate_message_board_write == 0)
		{
			/*printf("%d> tax_rate message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_tax_rate)\n");
			rc = MB_SyncStart(b_tax_rate);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_tax_rate)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'tax_rate' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'tax_rate' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'tax_rate' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_buy_message_board_write == 0)
		{
			/*printf("%d> buy message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_buy)\n");
			rc = MB_SyncStart(b_buy);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_buy)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'buy' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'buy' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'buy' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_bought_message_board_write == 0)
		{
			/*printf("%d> bought message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bought)\n");
			rc = MB_SyncStart(b_bought);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bought)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'bought' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'bought' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'bought' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_sell_message_board_write == 0)
		{
			/*printf("%d> sell message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_sell)\n");
			rc = MB_SyncStart(b_sell);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_sell)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'sell' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'sell' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'sell' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_sold_message_board_write == 0)
		{
			/*printf("%d> sold message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_sold)\n");
			rc = MB_SyncStart(b_sold);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_sold)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'sold' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'sold' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'sold' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_goods_transactions_summary_message_board_write == 0)
		{
			/*printf("%d> goods_transactions_summary message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_goods_transactions_summary)\n");
			rc = MB_SyncStart(b_goods_transactions_summary);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_goods_transactions_summary)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'goods_transactions_summary' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'goods_transactions_summary' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'goods_transactions_summary' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_fired_message_board_write == 0)
		{
			/*printf("%d> fired message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_fired)\n");
			rc = MB_SyncStart(b_fired);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_fired)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'fired' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'fired' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'fired' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_vacancy_stage1_message_board_write == 0)
		{
			/*printf("%d> vacancy_stage1 message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_vacancy_stage1)\n");
			rc = MB_SyncStart(b_vacancy_stage1);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_vacancy_stage1)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'vacancy_stage1' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'vacancy_stage1' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'vacancy_stage1' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_job_application_stage2_message_board_write == 0)
		{
			/*printf("%d> job_application_stage2 message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_application_stage2)\n");
			rc = MB_SyncStart(b_job_application_stage2);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_application_stage2)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'job_application_stage2' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'job_application_stage2' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'job_application_stage2' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_job_application_stage1_message_board_write == 0)
		{
			/*printf("%d> job_application_stage1 message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_application_stage1)\n");
			rc = MB_SyncStart(b_job_application_stage1);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_application_stage1)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'job_application_stage1' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'job_application_stage1' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'job_application_stage1' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_job_match_stage1_message_board_write == 0)
		{
			/*printf("%d> job_match_stage1 message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_match_stage1)\n");
			rc = MB_SyncStart(b_job_match_stage1);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_match_stage1)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'job_match_stage1' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'job_match_stage1' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'job_match_stage1' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_job_change_message_board_write == 0)
		{
			/*printf("%d> job_change message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_change)\n");
			rc = MB_SyncStart(b_job_change);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_change)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'job_change' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'job_change' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'job_change' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_vacancy_stage2_message_board_write == 0)
		{
			/*printf("%d> vacancy_stage2 message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_vacancy_stage2)\n");
			rc = MB_SyncStart(b_vacancy_stage2);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_vacancy_stage2)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'vacancy_stage2' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'vacancy_stage2' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'vacancy_stage2' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_job_match_stage2_message_board_write == 0)
		{
			/*printf("%d> job_match_stage2 message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_match_stage2)\n");
			rc = MB_SyncStart(b_job_match_stage2);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_match_stage2)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'job_match_stage2' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'job_match_stage2' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'job_match_stage2' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_employment_status_message_board_write == 0)
		{
			/*printf("%d> employment_status message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_employment_status)\n");
			rc = MB_SyncStart(b_employment_status);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_employment_status)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'employment_status' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'employment_status' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'employment_status' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_loan_request_1_message_board_write == 0)
		{
			/*printf("%d> loan_request_1 message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_loan_request_1)\n");
			rc = MB_SyncStart(b_loan_request_1);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_loan_request_1)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'loan_request_1' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'loan_request_1' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'loan_request_1' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_loan_request_2_message_board_write == 0)
		{
			/*printf("%d> loan_request_2 message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_loan_request_2)\n");
			rc = MB_SyncStart(b_loan_request_2);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_loan_request_2)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'loan_request_2' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'loan_request_2' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'loan_request_2' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_loan_acknowledge_1_message_board_write == 0)
		{
			/*printf("%d> loan_acknowledge_1 message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_loan_acknowledge_1)\n");
			rc = MB_SyncStart(b_loan_acknowledge_1);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_loan_acknowledge_1)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'loan_acknowledge_1' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'loan_acknowledge_1' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'loan_acknowledge_1' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_loan_acknowledge_2_message_board_write == 0)
		{
			/*printf("%d> loan_acknowledge_2 message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_loan_acknowledge_2)\n");
			rc = MB_SyncStart(b_loan_acknowledge_2);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_loan_acknowledge_2)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'loan_acknowledge_2' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'loan_acknowledge_2' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'loan_acknowledge_2' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_debt_request_message_board_write == 0)
		{
			/*printf("%d> debt_request message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_debt_request)\n");
			rc = MB_SyncStart(b_debt_request);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_debt_request)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'debt_request' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'debt_request' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'debt_request' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_household_share_message_board_write == 0)
		{
			/*printf("%d> household_share message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_household_share)\n");
			rc = MB_SyncStart(b_household_share);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_household_share)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'household_share' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'household_share' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'household_share' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_capital_tax_message_board_write == 0)
		{
			/*printf("%d> capital_tax message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_capital_tax)\n");
			rc = MB_SyncStart(b_capital_tax);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_capital_tax)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'capital_tax' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'capital_tax' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'capital_tax' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_labour_tax_message_board_write == 0)
		{
			/*printf("%d> labour_tax message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_labour_tax)\n");
			rc = MB_SyncStart(b_labour_tax);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_labour_tax)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'labour_tax' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'labour_tax' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'labour_tax' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_unemployment_benefit_message_board_write == 0)
		{
			/*printf("%d> unemployment_benefit message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_unemployment_benefit)\n");
			rc = MB_SyncStart(b_unemployment_benefit);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_unemployment_benefit)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'unemployment_benefit' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'unemployment_benefit' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'unemployment_benefit' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_general_benefit_message_board_write == 0)
		{
			/*printf("%d> general_benefit message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_general_benefit)\n");
			rc = MB_SyncStart(b_general_benefit);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_general_benefit)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'general_benefit' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'general_benefit' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'general_benefit' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_fund_request_message_board_write == 0)
		{
			/*printf("%d> fund_request message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_fund_request)\n");
			rc = MB_SyncStart(b_fund_request);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_fund_request)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'fund_request' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'fund_request' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'fund_request' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_fund_request_ack_message_board_write == 0)
		{
			/*printf("%d> fund_request_ack message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_fund_request_ack)\n");
			rc = MB_SyncStart(b_fund_request_ack);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_fund_request_ack)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'fund_request_ack' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'fund_request_ack' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'fund_request_ack' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_new_entrant_loan_message_board_write == 0)
		{
			/*printf("%d> new_entrant_loan message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_new_entrant_loan)\n");
			rc = MB_SyncStart(b_new_entrant_loan);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_new_entrant_loan)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'new_entrant_loan' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'new_entrant_loan' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'new_entrant_loan' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_interest_on_loan_message_board_write == 0)
		{
			/*printf("%d> interest_on_loan message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_interest_on_loan)\n");
			rc = MB_SyncStart(b_interest_on_loan);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_interest_on_loan)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'interest_on_loan' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'interest_on_loan' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'interest_on_loan' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_loan_writeoff_message_board_write == 0)
		{
			/*printf("%d> loan_writeoff message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_loan_writeoff)\n");
			rc = MB_SyncStart(b_loan_writeoff);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_loan_writeoff)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'loan_writeoff' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'loan_writeoff' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'loan_writeoff' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_firm_net_profit_message_board_write == 0)
		{
			/*printf("%d> firm_net_profit message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_firm_net_profit)\n");
			rc = MB_SyncStart(b_firm_net_profit);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_firm_net_profit)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'firm_net_profit' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'firm_net_profit' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'firm_net_profit' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_bank_net_profit_message_board_write == 0)
		{
			/*printf("%d> bank_net_profit message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bank_net_profit)\n");
			rc = MB_SyncStart(b_bank_net_profit);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bank_net_profit)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'bank_net_profit' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'bank_net_profit' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'bank_net_profit' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_bank_centralbank_interest_payment_message_board_write == 0)
		{
			/*printf("%d> bank_centralbank_interest_payment message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bank_centralbank_interest_payment)\n");
			rc = MB_SyncStart(b_bank_centralbank_interest_payment);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bank_centralbank_interest_payment)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'bank_centralbank_interest_payment' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_bank_centralbank_debt_payment_message_board_write == 0)
		{
			/*printf("%d> bank_centralbank_debt_payment message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bank_centralbank_debt_payment)\n");
			rc = MB_SyncStart(b_bank_centralbank_debt_payment);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bank_centralbank_debt_payment)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'bank_centralbank_debt_payment' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_centralbank_government_profit_message_board_write == 0)
		{
			/*printf("%d> centralbank_government_profit message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_centralbank_government_profit)\n");
			rc = MB_SyncStart(b_centralbank_government_profit);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_centralbank_government_profit)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'centralbank_government_profit' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'centralbank_government_profit' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'centralbank_government_profit' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_housing_price_message_board_write == 0)
		{
			/*printf("%d> housing_price message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_housing_price)\n");
			rc = MB_SyncStart(b_housing_price);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_housing_price)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'housing_price' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'housing_price' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'housing_price' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_buy_housing_message_board_write == 0)
		{
			/*printf("%d> buy_housing message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_buy_housing)\n");
			rc = MB_SyncStart(b_buy_housing);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_buy_housing)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'buy_housing' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'buy_housing' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'buy_housing' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_sell_housing_message_board_write == 0)
		{
			/*printf("%d> sell_housing message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_sell_housing)\n");
			rc = MB_SyncStart(b_sell_housing);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_sell_housing)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'sell_housing' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'sell_housing' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'sell_housing' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_bought_housing_message_board_write == 0)
		{
			/*printf("%d> bought_housing message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bought_housing)\n");
			rc = MB_SyncStart(b_bought_housing);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bought_housing)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'bought_housing' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'bought_housing' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'bought_housing' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_sold_housing_message_board_write == 0)
		{
			/*printf("%d> sold_housing message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_sold_housing)\n");
			rc = MB_SyncStart(b_sold_housing);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_sold_housing)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'sold_housing' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'sold_housing' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'sold_housing' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_mortgaging_capacity_message_board_write == 0)
		{
			/*printf("%d> mortgaging_capacity message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_mortgaging_capacity)\n");
			rc = MB_SyncStart(b_mortgaging_capacity);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_mortgaging_capacity)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'mortgaging_capacity' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'mortgaging_capacity' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'mortgaging_capacity' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_mortgage_requests_message_board_write == 0)
		{
			/*printf("%d> mortgage_requests message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_mortgage_requests)\n");
			rc = MB_SyncStart(b_mortgage_requests);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_mortgage_requests)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'mortgage_requests' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'mortgage_requests' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'mortgage_requests' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_mortgage_payment_from_sale_message_board_write == 0)
		{
			/*printf("%d> mortgage_payment_from_sale message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_mortgage_payment_from_sale)\n");
			rc = MB_SyncStart(b_mortgage_payment_from_sale);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_mortgage_payment_from_sale)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'mortgage_payment_from_sale' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_mortgage_payment_message_board_write == 0)
		{
			/*printf("%d> mortgage_payment message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_mortgage_payment)\n");
			rc = MB_SyncStart(b_mortgage_payment);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_mortgage_payment)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'mortgage_payment' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'mortgage_payment' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'mortgage_payment' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_mortgage_writeoff_message_board_write == 0)
		{
			/*printf("%d> mortgage_writeoff message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_mortgage_writeoff)\n");
			rc = MB_SyncStart(b_mortgage_writeoff);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_mortgage_writeoff)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'mortgage_writeoff' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'mortgage_writeoff' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'mortgage_writeoff' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_housing_transactions_summary_message_board_write == 0)
		{
			/*printf("%d> housing_transactions_summary message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_housing_transactions_summary)\n");
			rc = MB_SyncStart(b_housing_transactions_summary);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_housing_transactions_summary)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'housing_transactions_summary' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'housing_transactions_summary' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'housing_transactions_summary' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		

	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start reagency_init\n");
	current_xmachine_reagency_holder = reagency_start_state->agents;
	while(current_xmachine_reagency_holder)
	{
		temp_xmachine_reagency_holder = current_xmachine_reagency_holder->next;
		current_xmachine_reagency = current_xmachine_reagency_holder->agent;
		current_xmachine_reagency_next_state = reagency_REAgencyHousingMarket_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_reagency = current_xmachine_reagency;

		

		

			i = reagency_init();

		

			if(i == 1)
			{
				free_reagency_agent(current_xmachine_reagency_holder, reagency_start_state);
			}
			else
			{
				transition_reagency_agent(current_xmachine_reagency_holder, reagency_start_state, reagency_REAgencyHousingMarket_state);
			}
		

		current_xmachine_reagency = NULL;

		current_xmachine_reagency_holder = temp_xmachine_reagency_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish reagency_init\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start mall_init\n");
	current_xmachine_mall_holder = mall_start_state->agents;
	while(current_xmachine_mall_holder)
	{
		temp_xmachine_mall_holder = current_xmachine_mall_holder->next;
		current_xmachine_mall = current_xmachine_mall_holder->agent;
		current_xmachine_mall_next_state = mall_MallConsumptionMarket_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_mall = current_xmachine_mall;

		

		

			i = mall_init();

		

			if(i == 1)
			{
				free_mall_agent(current_xmachine_mall_holder, mall_start_state);
			}
			else
			{
				transition_mall_agent(current_xmachine_mall_holder, mall_start_state, mall_MallConsumptionMarket_state);
			}
		

		current_xmachine_mall = NULL;

		current_xmachine_mall_holder = temp_xmachine_mall_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish mall_init\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start jpoffice_init\n");
	current_xmachine_jpoffice_holder = jpoffice_start_state->agents;
	while(current_xmachine_jpoffice_holder)
	{
		temp_xmachine_jpoffice_holder = current_xmachine_jpoffice_holder->next;
		current_xmachine_jpoffice = current_xmachine_jpoffice_holder->agent;
		current_xmachine_jpoffice_next_state = jpoffice_JPOLabourMarket_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_jpoffice = current_xmachine_jpoffice;

		

		

			i = jpoffice_init();

		

			if(i == 1)
			{
				free_jpoffice_agent(current_xmachine_jpoffice_holder, jpoffice_start_state);
			}
			else
			{
				transition_jpoffice_agent(current_xmachine_jpoffice_holder, jpoffice_start_state, jpoffice_JPOLabourMarket_state);
			}
		

		current_xmachine_jpoffice = NULL;

		current_xmachine_jpoffice_holder = temp_xmachine_jpoffice_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish jpoffice_init\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start centralbank_init\n");
	current_xmachine_centralbank_holder = centralbank_start_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		current_xmachine_centralbank = current_xmachine_centralbank_holder->agent;
		current_xmachine_centralbank_next_state = centralbank_CentralBankCredit_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_centralbank = current_xmachine_centralbank;

		

		

			i = centralbank_init();

		

			if(i == 1)
			{
				free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_start_state);
			}
			else
			{
				transition_centralbank_agent(current_xmachine_centralbank_holder, centralbank_start_state, centralbank_CentralBankCredit_state);
			}
		

		current_xmachine_centralbank = NULL;

		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish centralbank_init\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start government_init\n");
	current_xmachine_government_holder = government_start_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		current_xmachine_government = current_xmachine_government_holder->agent;
		current_xmachine_government_next_state = government_GovernmentStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_government = current_xmachine_government;

		

		

			i = government_init();

		

			if(i == 1)
			{
				free_government_agent(current_xmachine_government_holder, government_start_state);
			}
			else
			{
				transition_government_agent(current_xmachine_government_holder, government_start_state, government_GovernmentStart_state);
			}
		

		current_xmachine_government = NULL;

		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish government_init\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_init\n");
	current_xmachine_bank_holder = bank_start_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankCreditStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		

		

			i = bank_init();

		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_start_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_start_state, bank_BankCreditStart_state);
			}
		

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_init\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start equityfund_init\n");
	current_xmachine_equityfund_holder = equityfund_start_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		current_xmachine_equityfund = current_xmachine_equityfund_holder->agent;
		current_xmachine_equityfund_next_state = equityfund_EquityFundStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_equityfund = current_xmachine_equityfund;

		

		

			i = equityfund_init();

		

			if(i == 1)
			{
				free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_start_state);
			}
			else
			{
				transition_equityfund_agent(current_xmachine_equityfund_holder, equityfund_start_state, equityfund_EquityFundStart_state);
			}
		

		current_xmachine_equityfund = NULL;

		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish equityfund_init\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_init\n");
	current_xmachine_household_holder = household_start_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHCreditStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		

		

			i = household_init();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_start_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_start_state, household_HHCreditStart_state);
			}
		

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_init\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_init\n");
	current_xmachine_firm_holder = firm_start_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		

			i = firm_init();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_start_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_start_state, firm_FirmCreditStart_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_init\n");


/* End of layer number 0 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmCreditStart_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: firm_credit_compute_income_statement */
			if(FLAME_condition_firm_firm_credit_compute_income_statement_FirmCreditStart_FirmCreditInterestRate(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_firm_idle_FirmCreditStart_FirmProductionStart(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmCreditStart'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_household_holder = household_HHCreditStart_state->agents;
		while(current_xmachine_household_holder)
		{
			FLAME_debug_count = 0;
			/* Function: household_credit_check_interest_rate */
			if(FLAME_condition_household_household_credit_check_interest_rate_HHCreditStart_HHCreditCheckTax(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_household_idle_HHCreditStart_HHCreditMonthly(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'household' leaving state 'HHCreditStart'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_household_holder = current_xmachine_household_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_equityfund_holder = equityfund_EquityFundStart_state->agents;
		while(current_xmachine_equityfund_holder)
		{
			FLAME_debug_count = 0;
			/* Function: equityfund_credit_check_tax_rate */
			if(FLAME_condition_equityfund_equityfund_credit_check_tax_rate_EquityFundStart_EFIlliquidInvestment(current_xmachine_equityfund_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_equityfund_idle_EquityFundStart_EFLabourMarket(current_xmachine_equityfund_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'equityfund' leaving state 'EquityFundStart'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_bank_holder = bank_BankCreditStart_state->agents;
		while(current_xmachine_bank_holder)
		{
			FLAME_debug_count = 0;
			/* Function: bank_credit_check_interest_rate */
			if(FLAME_condition_bank_bank_credit_check_interest_rate_BankCreditStart_BankCreditIncomeStatement(current_xmachine_bank_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_bank_idle_BankCreditStart_BankHousingMarket(current_xmachine_bank_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'bank' leaving state 'BankCreditStart'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_bank_holder = current_xmachine_bank_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_government_holder = government_GovernmentStart_state->agents;
		while(current_xmachine_government_holder)
		{
			FLAME_debug_count = 0;
			/* Function: government_compute_income_statement */
			if(FLAME_condition_government_government_compute_income_statement_GovernmentStart_GovernmentBalanceSheet(current_xmachine_government_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_government_idle_GovernmentStart_GovernmentMonthly(current_xmachine_government_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'government' leaving state 'GovernmentStart'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_government_holder = current_xmachine_government_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_centralbank_holder = centralbank_CentralBankCredit_state->agents;
		while(current_xmachine_centralbank_holder)
		{
			FLAME_debug_count = 0;
			/* Function: centralbank_set_interest_rate */
			if(FLAME_condition_centralbank_centralbank_set_interest_rate_CentralBankCredit_CentralBankInterestPayments(current_xmachine_centralbank_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_centralbank_idle_CentralBankCredit_CentralBankLabour(current_xmachine_centralbank_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'centralbank' leaving state 'CentralBankCredit'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_jpoffice_holder = jpoffice_JPOLabourMarket_state->agents;
		while(current_xmachine_jpoffice_holder)
		{
			FLAME_debug_count = 0;
			/* Function: jpoffice_labour_stage1 */
			if(FLAME_condition_jpoffice_jpoffice_labour_stage1_JPOLabourMarket_JPOLabourStage2(current_xmachine_jpoffice_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_jpoffice_idle_JPOLabourMarket_end(current_xmachine_jpoffice_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'jpoffice' leaving state 'JPOLabourMarket'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_jpoffice_holder = current_xmachine_jpoffice_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_mall_holder = mall_MallConsumptionMarket_state->agents;
		while(current_xmachine_mall_holder)
		{
			FLAME_debug_count = 0;
			/* Function: mall_consumption_shopping */
			if(FLAME_condition_mall_mall_consumption_shopping_MallConsumptionMarket_MallConsumptionSummary(current_xmachine_mall_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_mall_idle_MallConsumptionMarket_end(current_xmachine_mall_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'mall' leaving state 'MallConsumptionMarket'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_mall_holder = current_xmachine_mall_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_reagency_holder = reagency_REAgencyHousingMarket_state->agents;
		while(current_xmachine_reagency_holder)
		{
			FLAME_debug_count = 0;
			/* Function: reagency_housing_check_interest_rate */
			if(FLAME_condition_reagency_reagency_housing_check_interest_rate_REAgencyHousingMarket_REAgencyHousingProcess(current_xmachine_reagency_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_reagency_idle_REAgencyHousingMarket_end(current_xmachine_reagency_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'reagency' leaving state 'REAgencyHousingMarket'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_reagency_holder = current_xmachine_reagency_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start centralbank_set_interest_rate\n");
	current_xmachine_centralbank_holder = centralbank_CentralBankCredit_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		current_xmachine_centralbank = current_xmachine_centralbank_holder->agent;
		current_xmachine_centralbank_next_state = centralbank_CentralBankInterestPayments_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_centralbank = current_xmachine_centralbank;

		if(FLAME_condition_centralbank_centralbank_set_interest_rate_CentralBankCredit_CentralBankInterestPayments(current_xmachine_centralbank)==1)
		{

		

			i = centralbank_set_interest_rate();

		

			if(i == 1)
			{
				free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankCredit_state);
			}
			else
			{
				transition_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankCredit_state, centralbank_CentralBankInterestPayments_state);
			}
		}

		current_xmachine_centralbank = NULL;

		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish centralbank_set_interest_rate\n");

	if(FLAME_interest_rate_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_interest_rate)\n");
		rc = MB_SyncStart(b_interest_rate);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_interest_rate)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'interest_rate' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'interest_rate' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'interest_rate' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_reagency_holder = reagency_REAgencyHousingMarket_state->agents;
	while(current_xmachine_reagency_holder)
	{
		temp_xmachine_reagency_holder = current_xmachine_reagency_holder->next;
		current_xmachine_reagency = current_xmachine_reagency_holder->agent;
		current_xmachine_reagency_next_state = reagency_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_reagency = current_xmachine_reagency;

		if(FLAME_condition_reagency_idle_REAgencyHousingMarket_end(current_xmachine_reagency)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_reagency_agent(current_xmachine_reagency_holder, reagency_REAgencyHousingMarket_state);
			}
			else
			{
				transition_reagency_agent(current_xmachine_reagency_holder, reagency_REAgencyHousingMarket_state, reagency_end_state);
			}
		}

		current_xmachine_reagency = NULL;

		current_xmachine_reagency_holder = temp_xmachine_reagency_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_mall_holder = mall_MallConsumptionMarket_state->agents;
	while(current_xmachine_mall_holder)
	{
		temp_xmachine_mall_holder = current_xmachine_mall_holder->next;
		current_xmachine_mall = current_xmachine_mall_holder->agent;
		current_xmachine_mall_next_state = mall_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_mall = current_xmachine_mall;

		if(FLAME_condition_mall_idle_MallConsumptionMarket_end(current_xmachine_mall)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_mall_agent(current_xmachine_mall_holder, mall_MallConsumptionMarket_state);
			}
			else
			{
				transition_mall_agent(current_xmachine_mall_holder, mall_MallConsumptionMarket_state, mall_end_state);
			}
		}

		current_xmachine_mall = NULL;

		current_xmachine_mall_holder = temp_xmachine_mall_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_jpoffice_holder = jpoffice_JPOLabourMarket_state->agents;
	while(current_xmachine_jpoffice_holder)
	{
		temp_xmachine_jpoffice_holder = current_xmachine_jpoffice_holder->next;
		current_xmachine_jpoffice = current_xmachine_jpoffice_holder->agent;
		current_xmachine_jpoffice_next_state = jpoffice_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_jpoffice = current_xmachine_jpoffice;

		if(FLAME_condition_jpoffice_idle_JPOLabourMarket_end(current_xmachine_jpoffice)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_jpoffice_agent(current_xmachine_jpoffice_holder, jpoffice_JPOLabourMarket_state);
			}
			else
			{
				transition_jpoffice_agent(current_xmachine_jpoffice_holder, jpoffice_JPOLabourMarket_state, jpoffice_end_state);
			}
		}

		current_xmachine_jpoffice = NULL;

		current_xmachine_jpoffice_holder = temp_xmachine_jpoffice_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_centralbank_holder = centralbank_CentralBankCredit_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		current_xmachine_centralbank = current_xmachine_centralbank_holder->agent;
		current_xmachine_centralbank_next_state = centralbank_CentralBankLabour_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_centralbank = current_xmachine_centralbank;

		if(FLAME_condition_centralbank_idle_CentralBankCredit_CentralBankLabour(current_xmachine_centralbank)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankCredit_state);
			}
			else
			{
				transition_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankCredit_state, centralbank_CentralBankLabour_state);
			}
		}

		current_xmachine_centralbank = NULL;

		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start government_compute_income_statement\n");
	current_xmachine_government_holder = government_GovernmentStart_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		current_xmachine_government = current_xmachine_government_holder->agent;
		current_xmachine_government_next_state = government_GovernmentBalanceSheet_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_government = current_xmachine_government;

		if(FLAME_condition_government_government_compute_income_statement_GovernmentStart_GovernmentBalanceSheet(current_xmachine_government)==1)
		{

		

			i = government_compute_income_statement();

		

			if(i == 1)
			{
				free_government_agent(current_xmachine_government_holder, government_GovernmentStart_state);
			}
			else
			{
				transition_government_agent(current_xmachine_government_holder, government_GovernmentStart_state, government_GovernmentBalanceSheet_state);
			}
		}

		current_xmachine_government = NULL;

		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish government_compute_income_statement\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_government_holder = government_GovernmentStart_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		current_xmachine_government = current_xmachine_government_holder->agent;
		current_xmachine_government_next_state = government_GovernmentMonthly_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_government = current_xmachine_government;

		if(FLAME_condition_government_idle_GovernmentStart_GovernmentMonthly(current_xmachine_government)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_government_agent(current_xmachine_government_holder, government_GovernmentStart_state);
			}
			else
			{
				transition_government_agent(current_xmachine_government_holder, government_GovernmentStart_state, government_GovernmentMonthly_state);
			}
		}

		current_xmachine_government = NULL;

		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_bank_holder = bank_BankCreditStart_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankHousingMarket_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		if(FLAME_condition_bank_idle_BankCreditStart_BankHousingMarket(current_xmachine_bank)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankCreditStart_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankCreditStart_state, bank_BankHousingMarket_state);
			}
		}

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_equityfund_holder = equityfund_EquityFundStart_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		current_xmachine_equityfund = current_xmachine_equityfund_holder->agent;
		current_xmachine_equityfund_next_state = equityfund_EFLabourMarket_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_equityfund = current_xmachine_equityfund;

		if(FLAME_condition_equityfund_idle_EquityFundStart_EFLabourMarket(current_xmachine_equityfund)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EquityFundStart_state);
			}
			else
			{
				transition_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EquityFundStart_state, equityfund_EFLabourMarket_state);
			}
		}

		current_xmachine_equityfund = NULL;

		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_household_holder = household_HHCreditStart_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHCreditMonthly_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_idle_HHCreditStart_HHCreditMonthly(current_xmachine_household)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHCreditStart_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHCreditStart_state, household_HHCreditMonthly_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_compute_income_statement\n");
	current_xmachine_firm_holder = firm_FirmCreditStart_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditInterestRate_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_credit_compute_income_statement_FirmCreditStart_FirmCreditInterestRate(current_xmachine_firm)==1)
		{

		

			i = firm_credit_compute_income_statement();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditStart_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditStart_state, firm_FirmCreditInterestRate_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_compute_income_statement\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmCreditStart_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmProductionStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmCreditStart_FirmProductionStart(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditStart_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditStart_state, firm_FirmProductionStart_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


/* End of layer number 1 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start government_do_balance_sheet\n");
	current_xmachine_government_holder = government_GovernmentBalanceSheet_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		current_xmachine_government = current_xmachine_government_holder->agent;
		current_xmachine_government_next_state = government_GovernmentFiscalPolicy_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_government = current_xmachine_government;

		

		

			i = government_do_balance_sheet();

		

			if(i == 1)
			{
				free_government_agent(current_xmachine_government_holder, government_GovernmentBalanceSheet_state);
			}
			else
			{
				transition_government_agent(current_xmachine_government_holder, government_GovernmentBalanceSheet_state, government_GovernmentFiscalPolicy_state);
			}
		

		current_xmachine_government = NULL;

		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish government_do_balance_sheet\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_interest_rate_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_interest_rate)\n");
		rc = MB_SyncComplete(b_interest_rate);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_interest_rate)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'interest_rate' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'interest_rate' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_check_interest_rate\n");
	current_xmachine_firm_holder = firm_FirmCreditInterestRate_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditTaxRate_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		
		
		
		  rc = MB_Iterator_Create(b_interest_rate, &i_interest_rate);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'interest_rate'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'interest_rate' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'interest_rate' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = firm_credit_check_interest_rate();

		
		    rc = MB_Iterator_Delete(&i_interest_rate);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'interest_rate' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'interest_rate' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditInterestRate_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditInterestRate_state, firm_FirmCreditTaxRate_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_check_interest_rate\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_credit_check_interest_rate\n");
	current_xmachine_household_holder = household_HHCreditStart_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHCreditCheckTax_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_household_credit_check_interest_rate_HHCreditStart_HHCreditCheckTax(current_xmachine_household)==1)
		{

		
		
		
		  rc = MB_Iterator_Create(b_interest_rate, &i_interest_rate);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'interest_rate'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'interest_rate' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'interest_rate' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = household_credit_check_interest_rate();

		
		    rc = MB_Iterator_Delete(&i_interest_rate);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'interest_rate' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'interest_rate' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHCreditStart_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHCreditStart_state, household_HHCreditCheckTax_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_credit_check_interest_rate\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_credit_check_interest_rate\n");
	current_xmachine_bank_holder = bank_BankCreditStart_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankCreditIncomeStatement_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		if(FLAME_condition_bank_bank_credit_check_interest_rate_BankCreditStart_BankCreditIncomeStatement(current_xmachine_bank)==1)
		{

		
		
		
		  rc = MB_Iterator_Create(b_interest_rate, &i_interest_rate);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'interest_rate'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'interest_rate' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'interest_rate' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = bank_credit_check_interest_rate();

		
		    rc = MB_Iterator_Delete(&i_interest_rate);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'interest_rate' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'interest_rate' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankCreditStart_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankCreditStart_state, bank_BankCreditIncomeStatement_state);
			}
		}

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_credit_check_interest_rate\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start reagency_housing_check_interest_rate\n");
	current_xmachine_reagency_holder = reagency_REAgencyHousingMarket_state->agents;
	while(current_xmachine_reagency_holder)
	{
		temp_xmachine_reagency_holder = current_xmachine_reagency_holder->next;
		current_xmachine_reagency = current_xmachine_reagency_holder->agent;
		current_xmachine_reagency_next_state = reagency_REAgencyHousingProcess_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_reagency = current_xmachine_reagency;

		if(FLAME_condition_reagency_reagency_housing_check_interest_rate_REAgencyHousingMarket_REAgencyHousingProcess(current_xmachine_reagency)==1)
		{

		
		
		
		  rc = MB_Iterator_Create(b_interest_rate, &i_interest_rate);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'interest_rate'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'interest_rate' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'interest_rate' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = reagency_housing_check_interest_rate();

		
		    rc = MB_Iterator_Delete(&i_interest_rate);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'interest_rate' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'interest_rate' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_reagency_agent(current_xmachine_reagency_holder, reagency_REAgencyHousingMarket_state);
			}
			else
			{
				transition_reagency_agent(current_xmachine_reagency_holder, reagency_REAgencyHousingMarket_state, reagency_REAgencyHousingProcess_state);
			}
		}

		current_xmachine_reagency = NULL;

		current_xmachine_reagency_holder = temp_xmachine_reagency_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish reagency_housing_check_interest_rate\n");


/* End of layer number 2 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_interest_rate_message_board_read == 0)
{
	/*printf("%d> interest_rate message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_interest_rate)\n");
	rc = MB_SyncComplete(b_interest_rate);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_interest_rate)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'interest_rate' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'interest_rate' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_interest_rate);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'interest_rate' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'interest_rate' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'interest_rate' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_credit_compute_income_statement\n");
	current_xmachine_bank_holder = bank_BankCreditIncomeStatement_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankCreditDividends_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		

		

			i = bank_credit_compute_income_statement();

		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankCreditIncomeStatement_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankCreditIncomeStatement_state, bank_BankCreditDividends_state);
			}
		

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_credit_compute_income_statement\n");

	if(FLAME_bank_centralbank_interest_payment_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bank_centralbank_interest_payment)\n");
		rc = MB_SyncStart(b_bank_centralbank_interest_payment);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bank_centralbank_interest_payment)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'bank_centralbank_interest_payment' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start government_update_fiscal_policy\n");
	current_xmachine_government_holder = government_GovernmentFiscalPolicy_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		current_xmachine_government = current_xmachine_government_holder->agent;
		current_xmachine_government_next_state = government_GovernmentCapitalTax_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_government = current_xmachine_government;

		

		

			i = government_update_fiscal_policy();

		

			if(i == 1)
			{
				free_government_agent(current_xmachine_government_holder, government_GovernmentFiscalPolicy_state);
			}
			else
			{
				transition_government_agent(current_xmachine_government_holder, government_GovernmentFiscalPolicy_state, government_GovernmentCapitalTax_state);
			}
		

		current_xmachine_government = NULL;

		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish government_update_fiscal_policy\n");

	if(FLAME_tax_rate_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_tax_rate)\n");
		rc = MB_SyncStart(b_tax_rate);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_tax_rate)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'tax_rate' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'tax_rate' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'tax_rate' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


/* End of layer number 3 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_credit_compute_dividends\n");
	current_xmachine_bank_holder = bank_BankCreditDividends_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankCreditBalanceSheet_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		

		

			i = bank_credit_compute_dividends();

		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankCreditDividends_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankCreditDividends_state, bank_BankCreditBalanceSheet_state);
			}
		

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_credit_compute_dividends\n");

	if(FLAME_bank_net_profit_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bank_net_profit)\n");
		rc = MB_SyncStart(b_bank_net_profit);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bank_net_profit)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'bank_net_profit' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'bank_net_profit' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'bank_net_profit' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_tax_rate_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_tax_rate)\n");
		rc = MB_SyncComplete(b_tax_rate);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_tax_rate)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'tax_rate' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'tax_rate' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_check_tax_rate\n");
	current_xmachine_firm_holder = firm_FirmCreditTaxRate_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditInvestment_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		
		
		
		  rc = MB_Iterator_Create(b_tax_rate, &i_tax_rate);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'tax_rate'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'tax_rate' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'tax_rate' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = firm_credit_check_tax_rate();

		
		    rc = MB_Iterator_Delete(&i_tax_rate);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'tax_rate' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'tax_rate' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditTaxRate_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditTaxRate_state, firm_FirmCreditInvestment_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_check_tax_rate\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_credit_check_tax_rate\n");
	current_xmachine_household_holder = household_HHCreditCheckTax_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHCreditUpdateMortgages_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		

		
		
		
		  rc = MB_Iterator_Create(b_tax_rate, &i_tax_rate);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'tax_rate'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'tax_rate' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'tax_rate' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = household_credit_check_tax_rate();

		
		    rc = MB_Iterator_Delete(&i_tax_rate);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'tax_rate' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'tax_rate' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHCreditCheckTax_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHCreditCheckTax_state, household_HHCreditUpdateMortgages_state);
			}
		

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_credit_check_tax_rate\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start equityfund_credit_check_tax_rate\n");
	current_xmachine_equityfund_holder = equityfund_EquityFundStart_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		current_xmachine_equityfund = current_xmachine_equityfund_holder->agent;
		current_xmachine_equityfund_next_state = equityfund_EFIlliquidInvestment_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_equityfund = current_xmachine_equityfund;

		if(FLAME_condition_equityfund_equityfund_credit_check_tax_rate_EquityFundStart_EFIlliquidInvestment(current_xmachine_equityfund)==1)
		{

		
		
		
		  rc = MB_Iterator_Create(b_tax_rate, &i_tax_rate);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'tax_rate'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'tax_rate' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'tax_rate' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = equityfund_credit_check_tax_rate();

		
		    rc = MB_Iterator_Delete(&i_tax_rate);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'tax_rate' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'tax_rate' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EquityFundStart_state);
			}
			else
			{
				transition_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EquityFundStart_state, equityfund_EFIlliquidInvestment_state);
			}
		}

		current_xmachine_equityfund = NULL;

		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish equityfund_credit_check_tax_rate\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_bank_centralbank_interest_payment_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bank_centralbank_interest_payment)\n");
		rc = MB_SyncComplete(b_bank_centralbank_interest_payment);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bank_centralbank_interest_payment)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'bank_centralbank_interest_payment' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start centralbank_collect_interest_payments\n");
	current_xmachine_centralbank_holder = centralbank_CentralBankInterestPayments_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		current_xmachine_centralbank = current_xmachine_centralbank_holder->agent;
		current_xmachine_centralbank_next_state = centralbank_CentralBankDebtRequests_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_centralbank = current_xmachine_centralbank;

		

		
		
		
		  rc = MB_Iterator_Create(b_bank_centralbank_interest_payment, &i_bank_centralbank_interest_payment);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'bank_centralbank_interest_payment'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = centralbank_collect_interest_payments();

		
		    rc = MB_Iterator_Delete(&i_bank_centralbank_interest_payment);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'bank_centralbank_interest_payment' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankInterestPayments_state);
			}
			else
			{
				transition_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankInterestPayments_state, centralbank_CentralBankDebtRequests_state);
			}
		

		current_xmachine_centralbank = NULL;

		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish centralbank_collect_interest_payments\n");


/* End of layer number 4 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_tax_rate_message_board_read == 0)
{
	/*printf("%d> tax_rate message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_tax_rate)\n");
	rc = MB_SyncComplete(b_tax_rate);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_tax_rate)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'tax_rate' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'tax_rate' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_tax_rate);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'tax_rate' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'tax_rate' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'tax_rate' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_bank_centralbank_interest_payment_message_board_read == 0)
{
	/*printf("%d> bank_centralbank_interest_payment message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bank_centralbank_interest_payment)\n");
	rc = MB_SyncComplete(b_bank_centralbank_interest_payment);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bank_centralbank_interest_payment)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'bank_centralbank_interest_payment' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_bank_centralbank_interest_payment);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'bank_centralbank_interest_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_credit_do_balance_sheet\n");
	current_xmachine_bank_holder = bank_BankCreditBalanceSheet_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankCreditRequest1_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		

		

			i = bank_credit_do_balance_sheet();

		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankCreditBalanceSheet_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankCreditBalanceSheet_state, bank_BankCreditRequest1_state);
			}
		

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_credit_do_balance_sheet\n");

	if(FLAME_bank_centralbank_debt_payment_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bank_centralbank_debt_payment)\n");
		rc = MB_SyncStart(b_bank_centralbank_debt_payment);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bank_centralbank_debt_payment)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'bank_centralbank_debt_payment' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    

	if(FLAME_debt_request_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_debt_request)\n");
		rc = MB_SyncStart(b_debt_request);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_debt_request)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'debt_request' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'debt_request' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'debt_request' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_credit_update_mortgage_rates\n");
	current_xmachine_household_holder = household_HHCreditUpdateMortgages_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHCreditIsCapitalist_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		

		

			i = household_credit_update_mortgage_rates();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHCreditUpdateMortgages_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHCreditUpdateMortgages_state, household_HHCreditIsCapitalist_state);
			}
		

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_credit_update_mortgage_rates\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_investment_decisions\n");
	current_xmachine_firm_holder = firm_FirmCreditInvestment_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditComputeDividends_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		

			i = firm_credit_investment_decisions();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditInvestment_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditInvestment_state, firm_FirmCreditComputeDividends_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_investment_decisions\n");


/* End of layer number 5 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

	/* DEBUG: States with branching functions */
		current_xmachine_household_holder = household_HHCreditIsCapitalist_state->agents;
		while(current_xmachine_household_holder)
		{
			FLAME_debug_count = 0;
			/* Function: household_credit_collect_shares */
			if(FLAME_condition_household_household_credit_collect_shares_HHCreditIsCapitalist_HHCreditBalanceSheet(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_household_idle_HHCreditIsCapitalist_HHCreditBalanceSheet(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'household' leaving state 'HHCreditIsCapitalist'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_household_holder = current_xmachine_household_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_household_holder = household_HHCreditIsCapitalist_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHCreditBalanceSheet_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_idle_HHCreditIsCapitalist_HHCreditBalanceSheet(current_xmachine_household)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHCreditIsCapitalist_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHCreditIsCapitalist_state, household_HHCreditBalanceSheet_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_compute_dividends\n");
	current_xmachine_firm_holder = firm_FirmCreditComputeDividends_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditLiquidityNeed_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		

			i = firm_credit_compute_dividends();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditComputeDividends_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditComputeDividends_state, firm_FirmCreditLiquidityNeed_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_compute_dividends\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_bank_centralbank_debt_payment_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bank_centralbank_debt_payment)\n");
		rc = MB_SyncComplete(b_bank_centralbank_debt_payment);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bank_centralbank_debt_payment)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'bank_centralbank_debt_payment' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_debt_request_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_debt_request)\n");
		rc = MB_SyncComplete(b_debt_request);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_debt_request)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'debt_request' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'debt_request' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start centralbank_process_debt_requests\n");
	current_xmachine_centralbank_holder = centralbank_CentralBankDebtRequests_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		current_xmachine_centralbank = current_xmachine_centralbank_holder->agent;
		current_xmachine_centralbank_next_state = centralbank_CentralBankIncomeStatement_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_centralbank = current_xmachine_centralbank;

		

		
		
		
		  rc = MB_Iterator_Create(b_debt_request, &i_debt_request);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'debt_request'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'debt_request' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'debt_request' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		
		
		
		  rc = MB_Iterator_Create(b_bank_centralbank_debt_payment, &i_bank_centralbank_debt_payment);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'bank_centralbank_debt_payment'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = centralbank_process_debt_requests();

		
		    rc = MB_Iterator_Delete(&i_debt_request);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'debt_request' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'debt_request' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		
		    rc = MB_Iterator_Delete(&i_bank_centralbank_debt_payment);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'bank_centralbank_debt_payment' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankDebtRequests_state);
			}
			else
			{
				transition_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankDebtRequests_state, centralbank_CentralBankIncomeStatement_state);
			}
		

		current_xmachine_centralbank = NULL;

		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish centralbank_process_debt_requests\n");


/* End of layer number 6 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_debt_request_message_board_read == 0)
{
	/*printf("%d> debt_request message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_debt_request)\n");
	rc = MB_SyncComplete(b_debt_request);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_debt_request)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'debt_request' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'debt_request' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_debt_request);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'debt_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'debt_request' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'debt_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_bank_centralbank_debt_payment_message_board_read == 0)
{
	/*printf("%d> bank_centralbank_debt_payment message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bank_centralbank_debt_payment)\n");
	rc = MB_SyncComplete(b_bank_centralbank_debt_payment);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bank_centralbank_debt_payment)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'bank_centralbank_debt_payment' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_bank_centralbank_debt_payment);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'bank_centralbank_debt_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start centralbank_compute_income_statement\n");
	current_xmachine_centralbank_holder = centralbank_CentralBankIncomeStatement_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		current_xmachine_centralbank = current_xmachine_centralbank_holder->agent;
		current_xmachine_centralbank_next_state = centralbank_CentralBankBalanceSheet_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_centralbank = current_xmachine_centralbank;

		

		

			i = centralbank_compute_income_statement();

		

			if(i == 1)
			{
				free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankIncomeStatement_state);
			}
			else
			{
				transition_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankIncomeStatement_state, centralbank_CentralBankBalanceSheet_state);
			}
		

		current_xmachine_centralbank = NULL;

		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish centralbank_compute_income_statement\n");

	if(FLAME_centralbank_government_profit_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_centralbank_government_profit)\n");
		rc = MB_SyncStart(b_centralbank_government_profit);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_centralbank_government_profit)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'centralbank_government_profit' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'centralbank_government_profit' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'centralbank_government_profit' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_check_liquidity_need\n");
	current_xmachine_firm_holder = firm_FirmCreditLiquidityNeed_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditStatus_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		

			i = firm_credit_check_liquidity_need();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditLiquidityNeed_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditLiquidityNeed_state, firm_FirmCreditStatus_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_check_liquidity_need\n");


/* End of layer number 7 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmCreditStatus_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: firm_credit_demand_loans_1 */
			if(FLAME_condition_firm_firm_credit_demand_loans_1_FirmCreditStatus_FirmCreditLoanBorrow1(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_firm_idle_FirmCreditStatus_FirmCreditPayments(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmCreditStatus'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_demand_loans_1\n");
	current_xmachine_firm_holder = firm_FirmCreditStatus_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditLoanBorrow1_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_credit_demand_loans_1_FirmCreditStatus_FirmCreditLoanBorrow1(current_xmachine_firm)==1)
		{

		

			i = firm_credit_demand_loans_1();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditStatus_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditStatus_state, firm_FirmCreditLoanBorrow1_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_demand_loans_1\n");

	if(FLAME_loan_request_1_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_loan_request_1)\n");
		rc = MB_SyncStart(b_loan_request_1);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_loan_request_1)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'loan_request_1' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'loan_request_1' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'loan_request_1' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start centralbank_do_balance_sheet\n");
	current_xmachine_centralbank_holder = centralbank_CentralBankBalanceSheet_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		current_xmachine_centralbank = current_xmachine_centralbank_holder->agent;
		current_xmachine_centralbank_next_state = centralbank_CentralBankLabour_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_centralbank = current_xmachine_centralbank;

		

		

			i = centralbank_do_balance_sheet();

		

			if(i == 1)
			{
				free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankBalanceSheet_state);
			}
			else
			{
				transition_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankBalanceSheet_state, centralbank_CentralBankLabour_state);
			}
		

		current_xmachine_centralbank = NULL;

		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish centralbank_do_balance_sheet\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmCreditStatus_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditPayments_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmCreditStatus_FirmCreditPayments(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditStatus_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditStatus_state, firm_FirmCreditPayments_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


/* End of layer number 8 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

	/* DEBUG: States with branching functions */
		current_xmachine_centralbank_holder = centralbank_CentralBankLabour_state->agents;
		while(current_xmachine_centralbank_holder)
		{
			FLAME_debug_count = 0;
			/* Function: centralbank_trace_unemployment_status */
			if(FLAME_condition_centralbank_centralbank_trace_unemployment_status_CentralBankLabour_CentralBankConsumption(current_xmachine_centralbank_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_centralbank_idle_CentralBankLabour_CentralBankConsumption(current_xmachine_centralbank_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'centralbank' leaving state 'CentralBankLabour'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_centralbank_holder = centralbank_CentralBankLabour_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		current_xmachine_centralbank = current_xmachine_centralbank_holder->agent;
		current_xmachine_centralbank_next_state = centralbank_CentralBankConsumption_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_centralbank = current_xmachine_centralbank;

		if(FLAME_condition_centralbank_idle_CentralBankLabour_CentralBankConsumption(current_xmachine_centralbank)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankLabour_state);
			}
			else
			{
				transition_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankLabour_state, centralbank_CentralBankConsumption_state);
			}
		}

		current_xmachine_centralbank = NULL;

		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_loan_request_1_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_loan_request_1)\n");
		rc = MB_SyncComplete(b_loan_request_1);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_loan_request_1)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'loan_request_1' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'loan_request_1' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_credit_process_loan_requests_1\n");
	current_xmachine_bank_holder = bank_BankCreditRequest1_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankCreditRequest2_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_loan_request_1, &i_loan_request_1, &FLAME_filter_bank_bank_credit_process_loan_requests_1_BankCreditRequest1_BankCreditRequest2_loan_request_1, current_xmachine_bank);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'loan_request_1'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'loan_request_1' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'loan_request_1' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = bank_credit_process_loan_requests_1();

		
		    rc = MB_Iterator_Delete(&i_loan_request_1);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'loan_request_1' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'loan_request_1' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankCreditRequest1_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankCreditRequest1_state, bank_BankCreditRequest2_state);
			}
		

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_credit_process_loan_requests_1\n");

	if(FLAME_loan_acknowledge_1_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_loan_acknowledge_1)\n");
		rc = MB_SyncStart(b_loan_acknowledge_1);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_loan_acknowledge_1)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'loan_acknowledge_1' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'loan_acknowledge_1' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'loan_acknowledge_1' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


/* End of layer number 9 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_loan_request_1_message_board_read == 0)
{
	/*printf("%d> loan_request_1 message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_loan_request_1)\n");
	rc = MB_SyncComplete(b_loan_request_1);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_loan_request_1)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'loan_request_1' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'loan_request_1' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_loan_request_1);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'loan_request_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_request_1' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_request_1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_loan_acknowledge_1_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_loan_acknowledge_1)\n");
		rc = MB_SyncComplete(b_loan_acknowledge_1);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_loan_acknowledge_1)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'loan_acknowledge_1' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'loan_acknowledge_1' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_borrow_loans_1\n");
	current_xmachine_firm_holder = firm_FirmCreditLoanBorrow1_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditLoanBorrow2_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_loan_acknowledge_1, &i_loan_acknowledge_1, &FLAME_filter_firm_firm_credit_borrow_loans_1_FirmCreditLoanBorrow1_FirmCreditLoanBorrow2_loan_acknowledge_1, current_xmachine_firm);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'loan_acknowledge_1'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'loan_acknowledge_1' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'loan_acknowledge_1' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = firm_credit_borrow_loans_1();

		
		    rc = MB_Iterator_Delete(&i_loan_acknowledge_1);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'loan_acknowledge_1' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'loan_acknowledge_1' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditLoanBorrow1_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditLoanBorrow1_state, firm_FirmCreditLoanBorrow2_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_borrow_loans_1\n");

	if(FLAME_loan_request_2_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_loan_request_2)\n");
		rc = MB_SyncStart(b_loan_request_2);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_loan_request_2)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'loan_request_2' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'loan_request_2' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'loan_request_2' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


/* End of layer number 10 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_loan_acknowledge_1_message_board_read == 0)
{
	/*printf("%d> loan_acknowledge_1 message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_loan_acknowledge_1)\n");
	rc = MB_SyncComplete(b_loan_acknowledge_1);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_loan_acknowledge_1)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'loan_acknowledge_1' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'loan_acknowledge_1' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_loan_acknowledge_1);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'loan_acknowledge_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_acknowledge_1' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_acknowledge_1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmCreditLoanBorrow2_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: firm_credit_borrow_loans_2 */
			if(FLAME_condition_firm_firm_credit_borrow_loans_2_FirmCreditLoanBorrow2_FirmCreditIlliquidityStatus(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_firm_idle_FirmCreditLoanBorrow2_FirmCreditPayments(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmCreditLoanBorrow2'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
	
	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_loan_request_2_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_loan_request_2)\n");
		rc = MB_SyncComplete(b_loan_request_2);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_loan_request_2)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'loan_request_2' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'loan_request_2' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_credit_process_loan_requests_2\n");
	current_xmachine_bank_holder = bank_BankCreditRequest2_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankCreditLoanWriteOffs_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		

		
		
		
		  rc = MB_Iterator_Create(b_loan_request_2, &i_loan_request_2);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'loan_request_2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'loan_request_2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'loan_request_2' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = bank_credit_process_loan_requests_2();

		
		    rc = MB_Iterator_Delete(&i_loan_request_2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'loan_request_2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'loan_request_2' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankCreditRequest2_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankCreditRequest2_state, bank_BankCreditLoanWriteOffs_state);
			}
		

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_credit_process_loan_requests_2\n");

	if(FLAME_loan_acknowledge_2_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_loan_acknowledge_2)\n");
		rc = MB_SyncStart(b_loan_acknowledge_2);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_loan_acknowledge_2)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'loan_acknowledge_2' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'loan_acknowledge_2' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'loan_acknowledge_2' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmCreditLoanBorrow2_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditPayments_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmCreditLoanBorrow2_FirmCreditPayments(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditLoanBorrow2_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditLoanBorrow2_state, firm_FirmCreditPayments_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


/* End of layer number 11 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_loan_request_2_message_board_read == 0)
{
	/*printf("%d> loan_request_2 message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_loan_request_2)\n");
	rc = MB_SyncComplete(b_loan_request_2);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_loan_request_2)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'loan_request_2' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'loan_request_2' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_loan_request_2);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'loan_request_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_request_2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_request_2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_loan_acknowledge_2_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_loan_acknowledge_2)\n");
		rc = MB_SyncComplete(b_loan_acknowledge_2);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_loan_acknowledge_2)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'loan_acknowledge_2' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'loan_acknowledge_2' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_borrow_loans_2\n");
	current_xmachine_firm_holder = firm_FirmCreditLoanBorrow2_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditIlliquidityStatus_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_credit_borrow_loans_2_FirmCreditLoanBorrow2_FirmCreditIlliquidityStatus(current_xmachine_firm)==1)
		{

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_loan_acknowledge_2, &i_loan_acknowledge_2, &FLAME_filter_firm_firm_credit_borrow_loans_2_FirmCreditLoanBorrow2_FirmCreditIlliquidityStatus_loan_acknowledge_2, current_xmachine_firm);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'loan_acknowledge_2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'loan_acknowledge_2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'loan_acknowledge_2' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = firm_credit_borrow_loans_2();

		
		    rc = MB_Iterator_Delete(&i_loan_acknowledge_2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'loan_acknowledge_2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'loan_acknowledge_2' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditLoanBorrow2_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditLoanBorrow2_state, firm_FirmCreditIlliquidityStatus_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_borrow_loans_2\n");


/* End of layer number 12 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_loan_acknowledge_2_message_board_read == 0)
{
	/*printf("%d> loan_acknowledge_2 message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_loan_acknowledge_2)\n");
	rc = MB_SyncComplete(b_loan_acknowledge_2);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_loan_acknowledge_2)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'loan_acknowledge_2' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'loan_acknowledge_2' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_loan_acknowledge_2);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'loan_acknowledge_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_acknowledge_2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_acknowledge_2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmCreditIlliquidityStatus_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: firm_credit_request_equityfund_investment */
			if(FLAME_condition_firm_firm_credit_request_equityfund_investment_FirmCreditIlliquidityStatus_FirmCreditLiquidityRecheck(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_firm_idle_FirmCreditIlliquidityStatus_FirmCreditPayments(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmCreditIlliquidityStatus'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_request_equityfund_investment\n");
	current_xmachine_firm_holder = firm_FirmCreditIlliquidityStatus_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditLiquidityRecheck_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_credit_request_equityfund_investment_FirmCreditIlliquidityStatus_FirmCreditLiquidityRecheck(current_xmachine_firm)==1)
		{

		

			i = firm_credit_request_equityfund_investment();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditIlliquidityStatus_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditIlliquidityStatus_state, firm_FirmCreditLiquidityRecheck_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_request_equityfund_investment\n");

	if(FLAME_fund_request_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_fund_request)\n");
		rc = MB_SyncStart(b_fund_request);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_fund_request)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'fund_request' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'fund_request' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'fund_request' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmCreditIlliquidityStatus_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditPayments_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmCreditIlliquidityStatus_FirmCreditPayments(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditIlliquidityStatus_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditIlliquidityStatus_state, firm_FirmCreditPayments_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


/* End of layer number 13 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmCreditLiquidityRecheck_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: firm_credit_check_equityfund_investment */
			if(FLAME_condition_firm_firm_credit_check_equityfund_investment_FirmCreditLiquidityRecheck_FirmCreditBankruptcy(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_firm_idle_FirmCreditLiquidityRecheck_FirmCreditPayments(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmCreditLiquidityRecheck'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
	
	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_fund_request_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_fund_request)\n");
		rc = MB_SyncComplete(b_fund_request);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_fund_request)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'fund_request' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'fund_request' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start equityfund_credit_invest_illiquids\n");
	current_xmachine_equityfund_holder = equityfund_EFIlliquidInvestment_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		current_xmachine_equityfund = current_xmachine_equityfund_holder->agent;
		current_xmachine_equityfund_next_state = equityfund_EFCreditDistributeShares_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_equityfund = current_xmachine_equityfund;

		

		
		
		
		  rc = MB_Iterator_Create(b_fund_request, &i_fund_request);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'fund_request'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'fund_request' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'fund_request' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_fund_request);
		

			i = equityfund_credit_invest_illiquids();

		
		    rc = MB_Iterator_Delete(&i_fund_request);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'fund_request' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'fund_request' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFIlliquidInvestment_state);
			}
			else
			{
				transition_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFIlliquidInvestment_state, equityfund_EFCreditDistributeShares_state);
			}
		

		current_xmachine_equityfund = NULL;

		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish equityfund_credit_invest_illiquids\n");

	if(FLAME_fund_request_ack_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_fund_request_ack)\n");
		rc = MB_SyncStart(b_fund_request_ack);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_fund_request_ack)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'fund_request_ack' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'fund_request_ack' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'fund_request_ack' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmCreditLiquidityRecheck_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditPayments_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmCreditLiquidityRecheck_FirmCreditPayments(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditLiquidityRecheck_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditLiquidityRecheck_state, firm_FirmCreditPayments_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


/* End of layer number 14 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_fund_request_message_board_read == 0)
{
	/*printf("%d> fund_request message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_fund_request)\n");
	rc = MB_SyncComplete(b_fund_request);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_fund_request)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'fund_request' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'fund_request' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_fund_request);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'fund_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fund_request' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fund_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start equityfund_credit_distribute_shares\n");
	current_xmachine_equityfund_holder = equityfund_EFCreditDistributeShares_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		current_xmachine_equityfund = current_xmachine_equityfund_holder->agent;
		current_xmachine_equityfund_next_state = equityfund_EFCreditShareCollectionBanks_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_equityfund = current_xmachine_equityfund;

		

		

			i = equityfund_credit_distribute_shares();

		

			if(i == 1)
			{
				free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFCreditDistributeShares_state);
			}
			else
			{
				transition_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFCreditDistributeShares_state, equityfund_EFCreditShareCollectionBanks_state);
			}
		

		current_xmachine_equityfund = NULL;

		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish equityfund_credit_distribute_shares\n");

	if(FLAME_capital_tax_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_capital_tax)\n");
		rc = MB_SyncStart(b_capital_tax);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_capital_tax)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'capital_tax' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'capital_tax' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'capital_tax' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    

	if(FLAME_household_share_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_household_share)\n");
		rc = MB_SyncStart(b_household_share);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_household_share)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'household_share' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'household_share' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'household_share' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_fund_request_ack_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_fund_request_ack)\n");
		rc = MB_SyncComplete(b_fund_request_ack);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_fund_request_ack)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'fund_request_ack' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'fund_request_ack' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_check_equityfund_investment\n");
	current_xmachine_firm_holder = firm_FirmCreditLiquidityRecheck_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditBankruptcy_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_credit_check_equityfund_investment_FirmCreditLiquidityRecheck_FirmCreditBankruptcy(current_xmachine_firm)==1)
		{

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_fund_request_ack, &i_fund_request_ack, &FLAME_filter_firm_firm_credit_check_equityfund_investment_FirmCreditLiquidityRecheck_FirmCreditBankruptcy_fund_request_ack, current_xmachine_firm);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'fund_request_ack'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'fund_request_ack' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'fund_request_ack' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = firm_credit_check_equityfund_investment();

		
		    rc = MB_Iterator_Delete(&i_fund_request_ack);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'fund_request_ack' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'fund_request_ack' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditLiquidityRecheck_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditLiquidityRecheck_state, firm_FirmCreditBankruptcy_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_check_equityfund_investment\n");


/* End of layer number 15 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_fund_request_ack_message_board_read == 0)
{
	/*printf("%d> fund_request_ack message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_fund_request_ack)\n");
	rc = MB_SyncComplete(b_fund_request_ack);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_fund_request_ack)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'fund_request_ack' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'fund_request_ack' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_fund_request_ack);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'fund_request_ack' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fund_request_ack' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fund_request_ack' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmCreditBankruptcy_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: firm_credit_illiquidity_bankrupt */
			if(FLAME_condition_firm_firm_credit_illiquidity_bankrupt_FirmCreditBankruptcy_FirmCreditBalanceSheet(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_firm_idle_FirmCreditBankruptcy_FirmCreditPayments(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmCreditBankruptcy'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_illiquidity_bankrupt\n");
	current_xmachine_firm_holder = firm_FirmCreditBankruptcy_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditBalanceSheet_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_credit_illiquidity_bankrupt_FirmCreditBankruptcy_FirmCreditBalanceSheet(current_xmachine_firm)==1)
		{

		

			i = firm_credit_illiquidity_bankrupt();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditBankruptcy_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditBankruptcy_state, firm_FirmCreditBalanceSheet_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_illiquidity_bankrupt\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmCreditBankruptcy_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditPayments_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmCreditBankruptcy_FirmCreditPayments(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditBankruptcy_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditBankruptcy_state, firm_FirmCreditPayments_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_bank_net_profit_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bank_net_profit)\n");
		rc = MB_SyncComplete(b_bank_net_profit);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bank_net_profit)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'bank_net_profit' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'bank_net_profit' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start equityfund_credit_collect_bank_shares\n");
	current_xmachine_equityfund_holder = equityfund_EFCreditShareCollectionBanks_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		current_xmachine_equityfund = current_xmachine_equityfund_holder->agent;
		current_xmachine_equityfund_next_state = equityfund_EFCreditShareCollectionFirms_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_equityfund = current_xmachine_equityfund;

		

		
		
		
		  rc = MB_Iterator_Create(b_bank_net_profit, &i_bank_net_profit);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'bank_net_profit'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'bank_net_profit' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bank_net_profit' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = equityfund_credit_collect_bank_shares();

		
		    rc = MB_Iterator_Delete(&i_bank_net_profit);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'bank_net_profit' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'bank_net_profit' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFCreditShareCollectionBanks_state);
			}
			else
			{
				transition_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFCreditShareCollectionBanks_state, equityfund_EFCreditShareCollectionFirms_state);
			}
		

		current_xmachine_equityfund = NULL;

		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish equityfund_credit_collect_bank_shares\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_household_share_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_household_share)\n");
		rc = MB_SyncComplete(b_household_share);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_household_share)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'household_share' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'household_share' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_credit_collect_shares\n");
	current_xmachine_household_holder = household_HHCreditIsCapitalist_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHCreditBalanceSheet_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_household_credit_collect_shares_HHCreditIsCapitalist_HHCreditBalanceSheet(current_xmachine_household)==1)
		{

		
		
		
		  rc = MB_Iterator_Create(b_household_share, &i_household_share);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'household_share'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'household_share' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'household_share' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = household_credit_collect_shares();

		
		    rc = MB_Iterator_Delete(&i_household_share);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'household_share' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'household_share' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHCreditIsCapitalist_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHCreditIsCapitalist_state, household_HHCreditBalanceSheet_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_credit_collect_shares\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_capital_tax_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_capital_tax)\n");
		rc = MB_SyncComplete(b_capital_tax);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_capital_tax)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'capital_tax' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'capital_tax' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start government_collect_capital_tax\n");
	current_xmachine_government_holder = government_GovernmentCapitalTax_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		current_xmachine_government = current_xmachine_government_holder->agent;
		current_xmachine_government_next_state = government_GovernmentCentralbankProfits_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_government = current_xmachine_government;

		

		
		
		
		  rc = MB_Iterator_Create(b_capital_tax, &i_capital_tax);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'capital_tax'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'capital_tax' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'capital_tax' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = government_collect_capital_tax();

		
		    rc = MB_Iterator_Delete(&i_capital_tax);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'capital_tax' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'capital_tax' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_government_agent(current_xmachine_government_holder, government_GovernmentCapitalTax_state);
			}
			else
			{
				transition_government_agent(current_xmachine_government_holder, government_GovernmentCapitalTax_state, government_GovernmentCentralbankProfits_state);
			}
		

		current_xmachine_government = NULL;

		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish government_collect_capital_tax\n");


/* End of layer number 16 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_household_share_message_board_read == 0)
{
	/*printf("%d> household_share message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_household_share)\n");
	rc = MB_SyncComplete(b_household_share);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_household_share)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'household_share' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'household_share' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_household_share);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'household_share' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_share' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_share' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_capital_tax_message_board_read == 0)
{
	/*printf("%d> capital_tax message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_capital_tax)\n");
	rc = MB_SyncComplete(b_capital_tax);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_capital_tax)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'capital_tax' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'capital_tax' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_capital_tax);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'capital_tax' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_tax' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_tax' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_bank_net_profit_message_board_read == 0)
{
	/*printf("%d> bank_net_profit message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bank_net_profit)\n");
	rc = MB_SyncComplete(b_bank_net_profit);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bank_net_profit)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'bank_net_profit' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'bank_net_profit' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_bank_net_profit);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'bank_net_profit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_net_profit' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_net_profit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_pay_interest_on_loans\n");
	current_xmachine_firm_holder = firm_FirmCreditPayments_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditDividendPayments_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		

			i = firm_credit_pay_interest_on_loans();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditPayments_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditPayments_state, firm_FirmCreditDividendPayments_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_pay_interest_on_loans\n");

	if(FLAME_interest_on_loan_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_interest_on_loan)\n");
		rc = MB_SyncStart(b_interest_on_loan);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_interest_on_loan)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'interest_on_loan' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'interest_on_loan' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'interest_on_loan' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_credit_do_balance_sheet\n");
	current_xmachine_household_holder = household_HHCreditBalanceSheet_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHCreditMonthly_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		

		

			i = household_credit_do_balance_sheet();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHCreditBalanceSheet_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHCreditBalanceSheet_state, household_HHCreditMonthly_state);
			}
		

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_credit_do_balance_sheet\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_centralbank_government_profit_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_centralbank_government_profit)\n");
		rc = MB_SyncComplete(b_centralbank_government_profit);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_centralbank_government_profit)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'centralbank_government_profit' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'centralbank_government_profit' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start government_collect_centralbank_profit\n");
	current_xmachine_government_holder = government_GovernmentCentralbankProfits_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		current_xmachine_government = current_xmachine_government_holder->agent;
		current_xmachine_government_next_state = government_GovernmentMonthly_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_government = current_xmachine_government;

		

		
		
		
		  rc = MB_Iterator_Create(b_centralbank_government_profit, &i_centralbank_government_profit);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'centralbank_government_profit'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'centralbank_government_profit' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'centralbank_government_profit' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = government_collect_centralbank_profit();

		
		    rc = MB_Iterator_Delete(&i_centralbank_government_profit);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'centralbank_government_profit' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'centralbank_government_profit' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_government_agent(current_xmachine_government_holder, government_GovernmentCentralbankProfits_state);
			}
			else
			{
				transition_government_agent(current_xmachine_government_holder, government_GovernmentCentralbankProfits_state, government_GovernmentMonthly_state);
			}
		

		current_xmachine_government = NULL;

		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish government_collect_centralbank_profit\n");


/* End of layer number 17 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_centralbank_government_profit_message_board_read == 0)
{
	/*printf("%d> centralbank_government_profit message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_centralbank_government_profit)\n");
	rc = MB_SyncComplete(b_centralbank_government_profit);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_centralbank_government_profit)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'centralbank_government_profit' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'centralbank_government_profit' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_centralbank_government_profit);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'centralbank_government_profit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'centralbank_government_profit' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'centralbank_government_profit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_household_holder = household_HHCreditMonthly_state->agents;
		while(current_xmachine_household_holder)
		{
			FLAME_debug_count = 0;
			/* Function: household_credit_collect_benefits */
			if(FLAME_condition_household_household_credit_collect_benefits_HHCreditMonthly_HHCreditEmployment(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_household_idle_HHCreditMonthly_HHLabourStart(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'household' leaving state 'HHCreditMonthly'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_household_holder = current_xmachine_household_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_government_holder = government_GovernmentMonthly_state->agents;
		while(current_xmachine_government_holder)
		{
			FLAME_debug_count = 0;
			/* Function: government_distribute_general_benefits */
			if(FLAME_condition_government_government_distribute_general_benefits_GovernmentMonthly_GovernmentUnemploymentBenefits(current_xmachine_government_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_government_idle_GovernmentMonthly_end(current_xmachine_government_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'government' leaving state 'GovernmentMonthly'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_government_holder = current_xmachine_government_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_pay_dividends\n");
	current_xmachine_firm_holder = firm_FirmCreditDividendPayments_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditBalanceSheet_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		

			i = firm_credit_pay_dividends();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditDividendPayments_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditDividendPayments_state, firm_FirmCreditBalanceSheet_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_pay_dividends\n");

	if(FLAME_firm_net_profit_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_firm_net_profit)\n");
		rc = MB_SyncStart(b_firm_net_profit);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_firm_net_profit)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'firm_net_profit' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'firm_net_profit' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'firm_net_profit' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start government_distribute_general_benefits\n");
	current_xmachine_government_holder = government_GovernmentMonthly_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		current_xmachine_government = current_xmachine_government_holder->agent;
		current_xmachine_government_next_state = government_GovernmentUnemploymentBenefits_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_government = current_xmachine_government;

		if(FLAME_condition_government_government_distribute_general_benefits_GovernmentMonthly_GovernmentUnemploymentBenefits(current_xmachine_government)==1)
		{

		

			i = government_distribute_general_benefits();

		

			if(i == 1)
			{
				free_government_agent(current_xmachine_government_holder, government_GovernmentMonthly_state);
			}
			else
			{
				transition_government_agent(current_xmachine_government_holder, government_GovernmentMonthly_state, government_GovernmentUnemploymentBenefits_state);
			}
		}

		current_xmachine_government = NULL;

		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish government_distribute_general_benefits\n");

	if(FLAME_general_benefit_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_general_benefit)\n");
		rc = MB_SyncStart(b_general_benefit);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_general_benefit)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'general_benefit' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'general_benefit' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'general_benefit' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_government_holder = government_GovernmentMonthly_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		current_xmachine_government = current_xmachine_government_holder->agent;
		current_xmachine_government_next_state = government_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_government = current_xmachine_government;

		if(FLAME_condition_government_idle_GovernmentMonthly_end(current_xmachine_government)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_government_agent(current_xmachine_government_holder, government_GovernmentMonthly_state);
			}
			else
			{
				transition_government_agent(current_xmachine_government_holder, government_GovernmentMonthly_state, government_end_state);
			}
		}

		current_xmachine_government = NULL;

		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_household_holder = household_HHCreditMonthly_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHLabourStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_idle_HHCreditMonthly_HHLabourStart(current_xmachine_household)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHCreditMonthly_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHCreditMonthly_state, household_HHLabourStart_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


/* End of layer number 18 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start government_distribute_unemployment_benefits\n");
	current_xmachine_government_holder = government_GovernmentUnemploymentBenefits_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		current_xmachine_government = current_xmachine_government_holder->agent;
		current_xmachine_government_next_state = government_GovernmentLabourTax_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_government = current_xmachine_government;

		

		

			i = government_distribute_unemployment_benefits();

		

			if(i == 1)
			{
				free_government_agent(current_xmachine_government_holder, government_GovernmentUnemploymentBenefits_state);
			}
			else
			{
				transition_government_agent(current_xmachine_government_holder, government_GovernmentUnemploymentBenefits_state, government_GovernmentLabourTax_state);
			}
		

		current_xmachine_government = NULL;

		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish government_distribute_unemployment_benefits\n");

	if(FLAME_unemployment_benefit_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_unemployment_benefit)\n");
		rc = MB_SyncStart(b_unemployment_benefit);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_unemployment_benefit)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'unemployment_benefit' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'unemployment_benefit' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'unemployment_benefit' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_do_balance_sheet\n");
	current_xmachine_firm_holder = firm_FirmCreditBalanceSheet_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmCreditInsolvencyCheck_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		

			i = firm_credit_do_balance_sheet();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditBalanceSheet_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditBalanceSheet_state, firm_FirmCreditInsolvencyCheck_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_do_balance_sheet\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_general_benefit_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_general_benefit)\n");
		rc = MB_SyncComplete(b_general_benefit);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_general_benefit)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'general_benefit' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'general_benefit' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_credit_collect_benefits\n");
	current_xmachine_household_holder = household_HHCreditMonthly_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHCreditEmployment_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_household_credit_collect_benefits_HHCreditMonthly_HHCreditEmployment(current_xmachine_household)==1)
		{

		
		
		
		  rc = MB_Iterator_Create(b_general_benefit, &i_general_benefit);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'general_benefit'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'general_benefit' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'general_benefit' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = household_credit_collect_benefits();

		
		    rc = MB_Iterator_Delete(&i_general_benefit);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'general_benefit' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'general_benefit' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHCreditMonthly_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHCreditMonthly_state, household_HHCreditEmployment_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_credit_collect_benefits\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_firm_net_profit_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_firm_net_profit)\n");
		rc = MB_SyncComplete(b_firm_net_profit);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_firm_net_profit)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'firm_net_profit' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'firm_net_profit' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start equityfund_credit_collect_firm_shares\n");
	current_xmachine_equityfund_holder = equityfund_EFCreditShareCollectionFirms_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		current_xmachine_equityfund = current_xmachine_equityfund_holder->agent;
		current_xmachine_equityfund_next_state = equityfund_EFCreditBalanceSheet_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_equityfund = current_xmachine_equityfund;

		

		
		
		
		  rc = MB_Iterator_Create(b_firm_net_profit, &i_firm_net_profit);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'firm_net_profit'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'firm_net_profit' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'firm_net_profit' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = equityfund_credit_collect_firm_shares();

		
		    rc = MB_Iterator_Delete(&i_firm_net_profit);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'firm_net_profit' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'firm_net_profit' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFCreditShareCollectionFirms_state);
			}
			else
			{
				transition_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFCreditShareCollectionFirms_state, equityfund_EFCreditBalanceSheet_state);
			}
		

		current_xmachine_equityfund = NULL;

		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish equityfund_credit_collect_firm_shares\n");


/* End of layer number 19 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_general_benefit_message_board_read == 0)
{
	/*printf("%d> general_benefit message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_general_benefit)\n");
	rc = MB_SyncComplete(b_general_benefit);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_general_benefit)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'general_benefit' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'general_benefit' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_general_benefit);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'general_benefit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'general_benefit' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'general_benefit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_firm_net_profit_message_board_read == 0)
{
	/*printf("%d> firm_net_profit message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_firm_net_profit)\n");
	rc = MB_SyncComplete(b_firm_net_profit);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_firm_net_profit)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'firm_net_profit' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'firm_net_profit' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_firm_net_profit);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'firm_net_profit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_net_profit' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_net_profit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmCreditInsolvencyCheck_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: firm_credit_insolvency_bankruptcy */
			if(FLAME_condition_firm_firm_credit_insolvency_bankruptcy_FirmCreditInsolvencyCheck_FirmProductionStart(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_firm_idle_FirmCreditInsolvencyCheck_FirmProductionStart(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmCreditInsolvencyCheck'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_household_holder = household_HHCreditEmployment_state->agents;
		while(current_xmachine_household_holder)
		{
			FLAME_debug_count = 0;
			/* Function: idle */
			if(FLAME_condition_household_idle_HHCreditEmployment_HHLabourStart(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: household_credit_collect_unemployment */
			if(FLAME_condition_household_household_credit_collect_unemployment_HHCreditEmployment_HHLabourStart(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'household' leaving state 'HHCreditEmployment'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_household_holder = current_xmachine_household_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_credit_insolvency_bankruptcy\n");
	current_xmachine_firm_holder = firm_FirmCreditInsolvencyCheck_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmProductionStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_credit_insolvency_bankruptcy_FirmCreditInsolvencyCheck_FirmProductionStart(current_xmachine_firm)==1)
		{

		

			i = firm_credit_insolvency_bankruptcy();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditInsolvencyCheck_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditInsolvencyCheck_state, firm_FirmProductionStart_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_credit_insolvency_bankruptcy\n");

	if(FLAME_loan_writeoff_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_loan_writeoff)\n");
		rc = MB_SyncStart(b_loan_writeoff);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_loan_writeoff)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'loan_writeoff' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'loan_writeoff' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'loan_writeoff' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    

	if(FLAME_new_entrant_loan_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_new_entrant_loan)\n");
		rc = MB_SyncStart(b_new_entrant_loan);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_new_entrant_loan)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'new_entrant_loan' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'new_entrant_loan' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'new_entrant_loan' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start equityfund_credit_do_balance_sheet\n");
	current_xmachine_equityfund_holder = equityfund_EFCreditBalanceSheet_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		current_xmachine_equityfund = current_xmachine_equityfund_holder->agent;
		current_xmachine_equityfund_next_state = equityfund_EFLabourMarket_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_equityfund = current_xmachine_equityfund;

		

		

			i = equityfund_credit_do_balance_sheet();

		

			if(i == 1)
			{
				free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFCreditBalanceSheet_state);
			}
			else
			{
				transition_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFCreditBalanceSheet_state, equityfund_EFLabourMarket_state);
			}
		

		current_xmachine_equityfund = NULL;

		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish equityfund_credit_do_balance_sheet\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_household_holder = household_HHCreditEmployment_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHLabourStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_idle_HHCreditEmployment_HHLabourStart(current_xmachine_household)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHCreditEmployment_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHCreditEmployment_state, household_HHLabourStart_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmCreditInsolvencyCheck_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmProductionStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmCreditInsolvencyCheck_FirmProductionStart(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditInsolvencyCheck_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmCreditInsolvencyCheck_state, firm_FirmProductionStart_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_unemployment_benefit_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_unemployment_benefit)\n");
		rc = MB_SyncComplete(b_unemployment_benefit);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_unemployment_benefit)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'unemployment_benefit' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'unemployment_benefit' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_credit_collect_unemployment\n");
	current_xmachine_household_holder = household_HHCreditEmployment_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHLabourStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_household_credit_collect_unemployment_HHCreditEmployment_HHLabourStart(current_xmachine_household)==1)
		{

		
		
		
		  rc = MB_Iterator_Create(b_unemployment_benefit, &i_unemployment_benefit);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'unemployment_benefit'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'unemployment_benefit' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'unemployment_benefit' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = household_credit_collect_unemployment();

		
		    rc = MB_Iterator_Delete(&i_unemployment_benefit);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'unemployment_benefit' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'unemployment_benefit' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHCreditEmployment_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHCreditEmployment_state, household_HHLabourStart_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_credit_collect_unemployment\n");


/* End of layer number 20 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_unemployment_benefit_message_board_read == 0)
{
	/*printf("%d> unemployment_benefit message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_unemployment_benefit)\n");
	rc = MB_SyncComplete(b_unemployment_benefit);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_unemployment_benefit)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'unemployment_benefit' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'unemployment_benefit' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_unemployment_benefit);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'unemployment_benefit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'unemployment_benefit' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'unemployment_benefit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_household_holder = household_HHLabourStart_state->agents;
		while(current_xmachine_household_holder)
		{
			FLAME_debug_count = 0;
			/* Function: household_labour_check_fired */
			if(FLAME_condition_household_household_labour_check_fired_HHLabourStart_HHLabourStage1(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_household_idle_HHLabourStart_HHLabourEmploymentStatus(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'household' leaving state 'HHLabourStart'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_household_holder = current_xmachine_household_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_equityfund_holder = equityfund_EFLabourMarket_state->agents;
		while(current_xmachine_equityfund_holder)
		{
			FLAME_debug_count = 0;
			/* Function: equityfund_audit_dividends */
			if(FLAME_condition_equityfund_equityfund_audit_dividends_EFLabourMarket_end(current_xmachine_equityfund_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_equityfund_idle_EFLabourMarket_end(current_xmachine_equityfund_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'equityfund' leaving state 'EFLabourMarket'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_equityfund_holder = equityfund_EFLabourMarket_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		current_xmachine_equityfund = current_xmachine_equityfund_holder->agent;
		current_xmachine_equityfund_next_state = equityfund_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_equityfund = current_xmachine_equityfund;

		if(FLAME_condition_equityfund_idle_EFLabourMarket_end(current_xmachine_equityfund)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFLabourMarket_state);
			}
			else
			{
				transition_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFLabourMarket_state, equityfund_end_state);
			}
		}

		current_xmachine_equityfund = NULL;

		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_household_holder = household_HHLabourStart_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHLabourEmploymentStatus_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_idle_HHLabourStart_HHLabourEmploymentStatus(current_xmachine_household)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHLabourStart_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHLabourStart_state, household_HHLabourEmploymentStatus_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmProductionStart_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmProductionSkip_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmProductionStart_FirmProductionSkip(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionStart_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmProductionStart_state, firm_FirmProductionSkip_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmProductionStart_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmProductionStart_FirmLabourStart(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionStart_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmProductionStart_state, firm_FirmLabourStart_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_loan_writeoff_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_loan_writeoff)\n");
		rc = MB_SyncComplete(b_loan_writeoff);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_loan_writeoff)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'loan_writeoff' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'loan_writeoff' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_credit_recieve_loan_writeoffs\n");
	current_xmachine_bank_holder = bank_BankCreditLoanWriteOffs_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankCreditNewEntrants_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_loan_writeoff, &i_loan_writeoff, &FLAME_filter_bank_bank_credit_recieve_loan_writeoffs_BankCreditLoanWriteOffs_BankCreditNewEntrants_loan_writeoff, current_xmachine_bank);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'loan_writeoff'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'loan_writeoff' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'loan_writeoff' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = bank_credit_recieve_loan_writeoffs();

		
		    rc = MB_Iterator_Delete(&i_loan_writeoff);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'loan_writeoff' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'loan_writeoff' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankCreditLoanWriteOffs_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankCreditLoanWriteOffs_state, bank_BankCreditNewEntrants_state);
			}
		

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_credit_recieve_loan_writeoffs\n");


/* End of layer number 21 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_loan_writeoff_message_board_read == 0)
{
	/*printf("%d> loan_writeoff message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_loan_writeoff)\n");
	rc = MB_SyncComplete(b_loan_writeoff);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_loan_writeoff)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'loan_writeoff' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'loan_writeoff' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_loan_writeoff);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'loan_writeoff' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_writeoff' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_writeoff' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmProductionSkip_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: idle */
			if(FLAME_condition_firm_idle_FirmProductionSkip_FirmProductionRoleCheck(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: firm_production_skip */
			if(FLAME_condition_firm_firm_production_skip_FirmProductionSkip_FirmLabourStart(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmProductionSkip'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmProductionSkip_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmProductionRoleCheck_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmProductionSkip_FirmProductionRoleCheck(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionSkip_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmProductionSkip_state, firm_FirmProductionRoleCheck_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_production_skip\n");
	current_xmachine_firm_holder = firm_FirmProductionSkip_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_production_skip_FirmProductionSkip_FirmLabourStart(current_xmachine_firm)==1)
		{

		

			i = firm_production_skip();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionSkip_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmProductionSkip_state, firm_FirmLabourStart_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_production_skip\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_new_entrant_loan_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_new_entrant_loan)\n");
		rc = MB_SyncComplete(b_new_entrant_loan);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_new_entrant_loan)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'new_entrant_loan' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'new_entrant_loan' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_credit_recieve_new_entrant_loan_requests\n");
	current_xmachine_bank_holder = bank_BankCreditNewEntrants_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankCreditLoanInterests_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_new_entrant_loan, &i_new_entrant_loan, &FLAME_filter_bank_bank_credit_recieve_new_entrant_loan_requests_BankCreditNewEntrants_BankCreditLoanInterests_new_entrant_loan, current_xmachine_bank);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'new_entrant_loan'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'new_entrant_loan' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'new_entrant_loan' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = bank_credit_recieve_new_entrant_loan_requests();

		
		    rc = MB_Iterator_Delete(&i_new_entrant_loan);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'new_entrant_loan' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'new_entrant_loan' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankCreditNewEntrants_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankCreditNewEntrants_state, bank_BankCreditLoanInterests_state);
			}
		

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_credit_recieve_new_entrant_loan_requests\n");


/* End of layer number 22 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_new_entrant_loan_message_board_read == 0)
{
	/*printf("%d> new_entrant_loan message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_new_entrant_loan)\n");
	rc = MB_SyncComplete(b_new_entrant_loan);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_new_entrant_loan)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'new_entrant_loan' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'new_entrant_loan' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_new_entrant_loan);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'new_entrant_loan' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'new_entrant_loan' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'new_entrant_loan' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmProductionRoleCheck_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmProductionConstructor_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmProductionRoleCheck_FirmProductionConstructor(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionRoleCheck_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmProductionRoleCheck_state, firm_FirmProductionConstructor_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmProductionRoleCheck_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmProductionRegular_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmProductionRoleCheck_FirmProductionRegular(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionRoleCheck_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmProductionRoleCheck_state, firm_FirmProductionRegular_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_interest_on_loan_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_interest_on_loan)\n");
		rc = MB_SyncComplete(b_interest_on_loan);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_interest_on_loan)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'interest_on_loan' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'interest_on_loan' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_credit_collect_loan_interests\n");
	current_xmachine_bank_holder = bank_BankCreditLoanInterests_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankHousingMarket_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_interest_on_loan, &i_interest_on_loan, &FLAME_filter_bank_bank_credit_collect_loan_interests_BankCreditLoanInterests_BankHousingMarket_interest_on_loan, current_xmachine_bank);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'interest_on_loan'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'interest_on_loan' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'interest_on_loan' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = bank_credit_collect_loan_interests();

		
		    rc = MB_Iterator_Delete(&i_interest_on_loan);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'interest_on_loan' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'interest_on_loan' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankCreditLoanInterests_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankCreditLoanInterests_state, bank_BankHousingMarket_state);
			}
		

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_credit_collect_loan_interests\n");


/* End of layer number 23 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_interest_on_loan_message_board_read == 0)
{
	/*printf("%d> interest_on_loan message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_interest_on_loan)\n");
	rc = MB_SyncComplete(b_interest_on_loan);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_interest_on_loan)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'interest_on_loan' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'interest_on_loan' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_interest_on_loan);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'interest_on_loan' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'interest_on_loan' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'interest_on_loan' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmProductionRegular_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: firm_production_set_price */
			if(FLAME_condition_firm_firm_production_set_price_FirmProductionRegular_FirmProductionPlanning(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: firm_production_produce_goods */
			if(FLAME_condition_firm_firm_production_produce_goods_FirmProductionRegular_FirmLabourStart(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmProductionRegular'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmProductionConstructor_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: firm_production_construction_plan */
			if(FLAME_condition_firm_firm_production_construction_plan_FirmProductionConstructor_FirmConstructionLabourDemand(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: firm_production_construct_houses */
			if(FLAME_condition_firm_firm_production_construct_houses_FirmProductionConstructor_FirmLabourStart(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmProductionConstructor'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_bank_holder = bank_BankHousingMarket_state->agents;
		while(current_xmachine_bank_holder)
		{
			FLAME_debug_count = 0;
			/* Function: bank_housing_compute_capital_status */
			if(FLAME_condition_bank_bank_housing_compute_capital_status_BankHousingMarket_BankHousingCrediting(current_xmachine_bank_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_bank_idle_BankHousingMarket_BankUpdateDeposits(current_xmachine_bank_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'bank' leaving state 'BankHousingMarket'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_bank_holder = current_xmachine_bank_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_housing_compute_capital_status\n");
	current_xmachine_bank_holder = bank_BankHousingMarket_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankHousingCrediting_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		if(FLAME_condition_bank_bank_housing_compute_capital_status_BankHousingMarket_BankHousingCrediting(current_xmachine_bank)==1)
		{

		

			i = bank_housing_compute_capital_status();

		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankHousingMarket_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankHousingMarket_state, bank_BankHousingCrediting_state);
			}
		}

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_housing_compute_capital_status\n");

	if(FLAME_mortgaging_capacity_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_mortgaging_capacity)\n");
		rc = MB_SyncStart(b_mortgaging_capacity);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_mortgaging_capacity)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'mortgaging_capacity' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'mortgaging_capacity' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'mortgaging_capacity' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_bank_holder = bank_BankHousingMarket_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankUpdateDeposits_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		if(FLAME_condition_bank_idle_BankHousingMarket_BankUpdateDeposits(current_xmachine_bank)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankHousingMarket_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankHousingMarket_state, bank_BankUpdateDeposits_state);
			}
		}

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_production_construction_plan\n");
	current_xmachine_firm_holder = firm_FirmProductionConstructor_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmConstructionLabourDemand_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_production_construction_plan_FirmProductionConstructor_FirmConstructionLabourDemand(current_xmachine_firm)==1)
		{

		

			i = firm_production_construction_plan();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionConstructor_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmProductionConstructor_state, firm_FirmConstructionLabourDemand_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_production_construction_plan\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_production_construct_houses\n");
	current_xmachine_firm_holder = firm_FirmProductionConstructor_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_production_construct_houses_FirmProductionConstructor_FirmLabourStart(current_xmachine_firm)==1)
		{

		

			i = firm_production_construct_houses();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionConstructor_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmProductionConstructor_state, firm_FirmLabourStart_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_production_construct_houses\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_production_set_price\n");
	current_xmachine_firm_holder = firm_FirmProductionRegular_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmProductionPlanning_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_production_set_price_FirmProductionRegular_FirmProductionPlanning(current_xmachine_firm)==1)
		{

		

			i = firm_production_set_price();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionRegular_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmProductionRegular_state, firm_FirmProductionPlanning_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_production_set_price\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_production_produce_goods\n");
	current_xmachine_firm_holder = firm_FirmProductionRegular_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_production_produce_goods_FirmProductionRegular_FirmLabourStart(current_xmachine_firm)==1)
		{

		

			i = firm_production_produce_goods();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionRegular_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmProductionRegular_state, firm_FirmLabourStart_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_production_produce_goods\n");


/* End of layer number 24 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_production_construction_labour_demand\n");
	current_xmachine_firm_holder = firm_FirmConstructionLabourDemand_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		

			i = firm_production_construction_labour_demand();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmConstructionLabourDemand_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmConstructionLabourDemand_state, firm_FirmLabourStart_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_production_construction_labour_demand\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_production_plan\n");
	current_xmachine_firm_holder = firm_FirmProductionPlanning_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmProductionLabourDemand_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		

			i = firm_production_plan();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionPlanning_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmProductionPlanning_state, firm_FirmProductionLabourDemand_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_production_plan\n");


/* End of layer number 25 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_production_compute_labour_demand\n");
	current_xmachine_firm_holder = firm_FirmProductionLabourDemand_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		

			i = firm_production_compute_labour_demand();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionLabourDemand_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmProductionLabourDemand_state, firm_FirmLabourStart_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_production_compute_labour_demand\n");


/* End of layer number 26 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmLabourStart_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: firm_labour_workforce_needed */
			if(FLAME_condition_firm_firm_labour_workforce_needed_FirmLabourStart_FirmLabourStage1(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_firm_idle_FirmLabourStart_FirmLabourPayWages(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmLabourStart'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_labour_workforce_needed\n");
	current_xmachine_firm_holder = firm_FirmLabourStart_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourStage1_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_labour_workforce_needed_FirmLabourStart_FirmLabourStage1(current_xmachine_firm)==1)
		{

		

			i = firm_labour_workforce_needed();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStart_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStart_state, firm_FirmLabourStage1_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_labour_workforce_needed\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmLabourStart_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourPayWages_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmLabourStart_FirmLabourPayWages(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStart_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStart_state, firm_FirmLabourPayWages_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


/* End of layer number 27 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmLabourStage1_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: firm_labour_job_announcement_stage1 */
			if(FLAME_condition_firm_firm_labour_job_announcement_stage1_FirmLabourStage1_FirmLabourStage1Application(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: firm_labour_fire */
			if(FLAME_condition_firm_firm_labour_fire_FirmLabourStage1_FirmLabourStage1End(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_firm_idle_FirmLabourStage1_FirmLabourStage1End(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmLabourStage1'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_labour_fire\n");
	current_xmachine_firm_holder = firm_FirmLabourStage1_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourStage1End_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_labour_fire_FirmLabourStage1_FirmLabourStage1End(current_xmachine_firm)==1)
		{

		

			i = firm_labour_fire();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage1_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage1_state, firm_FirmLabourStage1End_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_labour_fire\n");

	if(FLAME_fired_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_fired)\n");
		rc = MB_SyncStart(b_fired);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_fired)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'fired' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'fired' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'fired' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_labour_job_announcement_stage1\n");
	current_xmachine_firm_holder = firm_FirmLabourStage1_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourStage1Application_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_labour_job_announcement_stage1_FirmLabourStage1_FirmLabourStage1Application(current_xmachine_firm)==1)
		{

		

			i = firm_labour_job_announcement_stage1();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage1_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage1_state, firm_FirmLabourStage1Application_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_labour_job_announcement_stage1\n");

	if(FLAME_vacancy_stage1_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_vacancy_stage1)\n");
		rc = MB_SyncStart(b_vacancy_stage1);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_vacancy_stage1)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'vacancy_stage1' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'vacancy_stage1' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'vacancy_stage1' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmLabourStage1_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourStage1End_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmLabourStage1_FirmLabourStage1End(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage1_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage1_state, firm_FirmLabourStage1End_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


/* End of layer number 28 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_fired_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_fired)\n");
		rc = MB_SyncComplete(b_fired);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_fired)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'fired' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'fired' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_labour_check_fired\n");
	current_xmachine_household_holder = household_HHLabourStart_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHLabourStage1_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_household_labour_check_fired_HHLabourStart_HHLabourStage1(current_xmachine_household)==1)
		{

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_fired, &i_fired, &FLAME_filter_household_household_labour_check_fired_HHLabourStart_HHLabourStage1_fired, current_xmachine_household);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'fired'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'fired' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'fired' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = household_labour_check_fired();

		
		    rc = MB_Iterator_Delete(&i_fired);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'fired' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'fired' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHLabourStart_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHLabourStart_state, household_HHLabourStage1_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_labour_check_fired\n");


/* End of layer number 29 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_fired_message_board_read == 0)
{
	/*printf("%d> fired message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_fired)\n");
	rc = MB_SyncComplete(b_fired);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_fired)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'fired' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'fired' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_fired);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'fired' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fired' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fired' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_household_holder = household_HHLabourStage1_state->agents;
		while(current_xmachine_household_holder)
		{
			FLAME_debug_count = 0;
			/* Function: idle */
			if(FLAME_condition_household_idle_HHLabourStage1_HHLabourStage1Applications(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: household_labour_reemployment_application */
			if(FLAME_condition_household_household_labour_reemployment_application_HHLabourStage1_HHLabourStage2(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'household' leaving state 'HHLabourStage1'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_household_holder = current_xmachine_household_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_labour_reemployment_application\n");
	current_xmachine_household_holder = household_HHLabourStage1_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHLabourStage2_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_household_labour_reemployment_application_HHLabourStage1_HHLabourStage2(current_xmachine_household)==1)
		{

		

			i = household_labour_reemployment_application();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHLabourStage1_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHLabourStage1_state, household_HHLabourStage2_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_labour_reemployment_application\n");

	if(FLAME_job_application_stage1_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_application_stage1)\n");
		rc = MB_SyncStart(b_job_application_stage1);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_application_stage1)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'job_application_stage1' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'job_application_stage1' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'job_application_stage1' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_household_holder = household_HHLabourStage1_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHLabourStage1Applications_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_idle_HHLabourStage1_HHLabourStage1Applications(current_xmachine_household)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHLabourStage1_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHLabourStage1_state, household_HHLabourStage1Applications_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


/* End of layer number 30 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_labour_employment_application\n");
	current_xmachine_household_holder = household_HHLabourStage1Applications_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHLabourStage1Placement_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		

		

			i = household_labour_employment_application();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHLabourStage1Applications_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHLabourStage1Applications_state, household_HHLabourStage1Placement_state);
			}
		

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_labour_employment_application\n");

	if(FLAME_job_application_stage2_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_application_stage2)\n");
		rc = MB_SyncStart(b_job_application_stage2);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_application_stage2)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'job_application_stage2' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'job_application_stage2' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'job_application_stage2' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_job_application_stage1_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_application_stage1)\n");
		rc = MB_SyncComplete(b_job_application_stage1);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_application_stage1)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'job_application_stage1' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'job_application_stage1' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_vacancy_stage1_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_vacancy_stage1)\n");
		rc = MB_SyncComplete(b_vacancy_stage1);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_vacancy_stage1)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'vacancy_stage1' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'vacancy_stage1' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start jpoffice_labour_stage1\n");
	current_xmachine_jpoffice_holder = jpoffice_JPOLabourMarket_state->agents;
	while(current_xmachine_jpoffice_holder)
	{
		temp_xmachine_jpoffice_holder = current_xmachine_jpoffice_holder->next;
		current_xmachine_jpoffice = current_xmachine_jpoffice_holder->agent;
		current_xmachine_jpoffice_next_state = jpoffice_JPOLabourStage2_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_jpoffice = current_xmachine_jpoffice;

		if(FLAME_condition_jpoffice_jpoffice_labour_stage1_JPOLabourMarket_JPOLabourStage2(current_xmachine_jpoffice)==1)
		{

		
		
		
		  
		  rc = MB_Iterator_CreateSorted(b_vacancy_stage1, &i_vacancy_stage1, &FLAME_sort_jpoffice_jpoffice_labour_stage1_JPOLabourMarket_JPOLabourStage2_vacancy_stage1);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'vacancy_stage1'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'vacancy_stage1' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'vacancy_stage1' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		
		
		
		  
		  rc = MB_Iterator_CreateSorted(b_job_application_stage1, &i_job_application_stage1, &FLAME_sort_jpoffice_jpoffice_labour_stage1_JPOLabourMarket_JPOLabourStage2_job_application_stage1);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'job_application_stage1'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'job_application_stage1' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_application_stage1' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = jpoffice_labour_stage1();

		
		    rc = MB_Iterator_Delete(&i_vacancy_stage1);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'vacancy_stage1' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'vacancy_stage1' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		
		    rc = MB_Iterator_Delete(&i_job_application_stage1);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'job_application_stage1' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'job_application_stage1' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_jpoffice_agent(current_xmachine_jpoffice_holder, jpoffice_JPOLabourMarket_state);
			}
			else
			{
				transition_jpoffice_agent(current_xmachine_jpoffice_holder, jpoffice_JPOLabourMarket_state, jpoffice_JPOLabourStage2_state);
			}
		}

		current_xmachine_jpoffice = NULL;

		current_xmachine_jpoffice_holder = temp_xmachine_jpoffice_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish jpoffice_labour_stage1\n");

	if(FLAME_job_match_stage1_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_match_stage1)\n");
		rc = MB_SyncStart(b_job_match_stage1);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_match_stage1)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'job_match_stage1' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'job_match_stage1' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'job_match_stage1' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


/* End of layer number 31 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_vacancy_stage1_message_board_read == 0)
{
	/*printf("%d> vacancy_stage1 message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_vacancy_stage1)\n");
	rc = MB_SyncComplete(b_vacancy_stage1);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_vacancy_stage1)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'vacancy_stage1' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'vacancy_stage1' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_vacancy_stage1);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'vacancy_stage1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancy_stage1' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancy_stage1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_job_application_stage1_message_board_read == 0)
{
	/*printf("%d> job_application_stage1 message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_application_stage1)\n");
	rc = MB_SyncComplete(b_job_application_stage1);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_application_stage1)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'job_application_stage1' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'job_application_stage1' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_job_application_stage1);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'job_application_stage1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application_stage1' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application_stage1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_job_match_stage1_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_match_stage1)\n");
		rc = MB_SyncComplete(b_job_match_stage1);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_match_stage1)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'job_match_stage1' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'job_match_stage1' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_labour_turnover\n");
	current_xmachine_household_holder = household_HHLabourStage2_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHLabourEmploymentStatus_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_job_match_stage1, &i_job_match_stage1, &FLAME_filter_household_household_labour_turnover_HHLabourStage2_HHLabourEmploymentStatus_job_match_stage1, current_xmachine_household);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'job_match_stage1'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'job_match_stage1' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_match_stage1' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = household_labour_turnover();

		
		    rc = MB_Iterator_Delete(&i_job_match_stage1);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'job_match_stage1' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'job_match_stage1' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHLabourStage2_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHLabourStage2_state, household_HHLabourEmploymentStatus_state);
			}
		

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_labour_turnover\n");

	if(FLAME_job_change_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_change)\n");
		rc = MB_SyncStart(b_job_change);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_change)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'job_change' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'job_change' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'job_change' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_labour_job_offer_stage1\n");
	current_xmachine_firm_holder = firm_FirmLabourStage1Application_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourStage1End_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_job_match_stage1, &i_job_match_stage1, &FLAME_filter_firm_firm_labour_job_offer_stage1_FirmLabourStage1Application_FirmLabourStage1End_job_match_stage1, current_xmachine_firm);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'job_match_stage1'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'job_match_stage1' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_match_stage1' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = firm_labour_job_offer_stage1();

		
		    rc = MB_Iterator_Delete(&i_job_match_stage1);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'job_match_stage1' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'job_match_stage1' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage1Application_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage1Application_state, firm_FirmLabourStage1End_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_labour_job_offer_stage1\n");


/* End of layer number 32 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_job_match_stage1_message_board_read == 0)
{
	/*printf("%d> job_match_stage1 message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_match_stage1)\n");
	rc = MB_SyncComplete(b_job_match_stage1);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_match_stage1)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'job_match_stage1' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'job_match_stage1' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_job_match_stage1);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'job_match_stage1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_match_stage1' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_match_stage1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_job_change_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_change)\n");
		rc = MB_SyncComplete(b_job_change);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_change)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'job_change' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'job_change' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_labour_update\n");
	current_xmachine_firm_holder = firm_FirmLabourStage1End_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourStage2_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_job_change, &i_job_change, &FLAME_filter_firm_firm_labour_update_FirmLabourStage1End_FirmLabourStage2_job_change, current_xmachine_firm);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'job_change'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'job_change' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_change' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = firm_labour_update();

		
		    rc = MB_Iterator_Delete(&i_job_change);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'job_change' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'job_change' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage1End_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage1End_state, firm_FirmLabourStage2_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_labour_update\n");


/* End of layer number 33 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_job_change_message_board_read == 0)
{
	/*printf("%d> job_change message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_change)\n");
	rc = MB_SyncComplete(b_job_change);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_change)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'job_change' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'job_change' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_job_change);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'job_change' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_change' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_change' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmLabourStage2_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: idle */
			if(FLAME_condition_firm_idle_FirmLabourStage2_FirmLabourPayWages(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: firm_labour_job_announcement_stage2 */
			if(FLAME_condition_firm_firm_labour_job_announcement_stage2_FirmLabourStage2_FirmLabourStage2End(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmLabourStage2'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_labour_job_announcement_stage2\n");
	current_xmachine_firm_holder = firm_FirmLabourStage2_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourStage2End_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_labour_job_announcement_stage2_FirmLabourStage2_FirmLabourStage2End(current_xmachine_firm)==1)
		{

		

			i = firm_labour_job_announcement_stage2();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage2_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage2_state, firm_FirmLabourStage2End_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_labour_job_announcement_stage2\n");

	if(FLAME_vacancy_stage2_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_vacancy_stage2)\n");
		rc = MB_SyncStart(b_vacancy_stage2);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_vacancy_stage2)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'vacancy_stage2' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'vacancy_stage2' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'vacancy_stage2' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmLabourStage2_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourPayWages_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmLabourStage2_FirmLabourPayWages(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage2_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage2_state, firm_FirmLabourPayWages_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


/* End of layer number 34 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_vacancy_stage2_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_vacancy_stage2)\n");
		rc = MB_SyncComplete(b_vacancy_stage2);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_vacancy_stage2)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'vacancy_stage2' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'vacancy_stage2' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_job_application_stage2_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_application_stage2)\n");
		rc = MB_SyncComplete(b_job_application_stage2);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_application_stage2)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'job_application_stage2' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'job_application_stage2' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start jpoffice_labour_stage2\n");
	current_xmachine_jpoffice_holder = jpoffice_JPOLabourStage2_state->agents;
	while(current_xmachine_jpoffice_holder)
	{
		temp_xmachine_jpoffice_holder = current_xmachine_jpoffice_holder->next;
		current_xmachine_jpoffice = current_xmachine_jpoffice_holder->agent;
		current_xmachine_jpoffice_next_state = jpoffice_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_jpoffice = current_xmachine_jpoffice;

		

		
		
		
		  
		  rc = MB_Iterator_CreateSorted(b_vacancy_stage2, &i_vacancy_stage2, &FLAME_sort_jpoffice_jpoffice_labour_stage2_JPOLabourStage2_end_vacancy_stage2);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'vacancy_stage2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'vacancy_stage2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'vacancy_stage2' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		
		
		
		  
		  rc = MB_Iterator_CreateSorted(b_job_application_stage2, &i_job_application_stage2, &FLAME_sort_jpoffice_jpoffice_labour_stage2_JPOLabourStage2_end_job_application_stage2);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'job_application_stage2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'job_application_stage2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_application_stage2' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = jpoffice_labour_stage2();

		
		    rc = MB_Iterator_Delete(&i_vacancy_stage2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'vacancy_stage2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'vacancy_stage2' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		
		    rc = MB_Iterator_Delete(&i_job_application_stage2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'job_application_stage2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'job_application_stage2' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_jpoffice_agent(current_xmachine_jpoffice_holder, jpoffice_JPOLabourStage2_state);
			}
			else
			{
				transition_jpoffice_agent(current_xmachine_jpoffice_holder, jpoffice_JPOLabourStage2_state, jpoffice_end_state);
			}
		

		current_xmachine_jpoffice = NULL;

		current_xmachine_jpoffice_holder = temp_xmachine_jpoffice_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish jpoffice_labour_stage2\n");

	if(FLAME_job_match_stage2_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_match_stage2)\n");
		rc = MB_SyncStart(b_job_match_stage2);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_match_stage2)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'job_match_stage2' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'job_match_stage2' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'job_match_stage2' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


/* End of layer number 35 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_job_application_stage2_message_board_read == 0)
{
	/*printf("%d> job_application_stage2 message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_application_stage2)\n");
	rc = MB_SyncComplete(b_job_application_stage2);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_application_stage2)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'job_application_stage2' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'job_application_stage2' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_job_application_stage2);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'job_application_stage2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application_stage2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application_stage2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_vacancy_stage2_message_board_read == 0)
{
	/*printf("%d> vacancy_stage2 message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_vacancy_stage2)\n");
	rc = MB_SyncComplete(b_vacancy_stage2);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_vacancy_stage2)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'vacancy_stage2' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'vacancy_stage2' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_vacancy_stage2);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'vacancy_stage2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancy_stage2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancy_stage2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_job_match_stage2_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_match_stage2)\n");
		rc = MB_SyncComplete(b_job_match_stage2);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_match_stage2)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'job_match_stage2' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'job_match_stage2' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_labour_job_offer_stage2\n");
	current_xmachine_firm_holder = firm_FirmLabourStage2End_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourPayWages_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_job_match_stage2, &i_job_match_stage2, &FLAME_filter_firm_firm_labour_job_offer_stage2_FirmLabourStage2End_FirmLabourPayWages_job_match_stage2, current_xmachine_firm);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'job_match_stage2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'job_match_stage2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_match_stage2' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = firm_labour_job_offer_stage2();

		
		    rc = MB_Iterator_Delete(&i_job_match_stage2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'job_match_stage2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'job_match_stage2' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage2End_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage2End_state, firm_FirmLabourPayWages_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_labour_job_offer_stage2\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_labour_employment\n");
	current_xmachine_household_holder = household_HHLabourStage1Placement_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHLabourEmploymentStatus_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_job_match_stage2, &i_job_match_stage2, &FLAME_filter_household_household_labour_employment_HHLabourStage1Placement_HHLabourEmploymentStatus_job_match_stage2, current_xmachine_household);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'job_match_stage2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'job_match_stage2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_match_stage2' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = household_labour_employment();

		
		    rc = MB_Iterator_Delete(&i_job_match_stage2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'job_match_stage2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'job_match_stage2' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHLabourStage1Placement_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHLabourStage1Placement_state, household_HHLabourEmploymentStatus_state);
			}
		

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_labour_employment\n");


/* End of layer number 36 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_job_match_stage2_message_board_read == 0)
{
	/*printf("%d> job_match_stage2 message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_match_stage2)\n");
	rc = MB_SyncComplete(b_job_match_stage2);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_match_stage2)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'job_match_stage2' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'job_match_stage2' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_job_match_stage2);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'job_match_stage2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_match_stage2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_match_stage2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmLabourPayWages_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: firm_labour_pay_wages */
			if(FLAME_condition_firm_firm_labour_pay_wages_FirmLabourPayWages_FirmLabourWageAdjustment(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_firm_idle_FirmLabourPayWages_FirmConsumptionStart(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmLabourPayWages'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_labour_report_status\n");
	current_xmachine_household_holder = household_HHLabourEmploymentStatus_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHLabourPayroll_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		

		

			i = household_labour_report_status();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHLabourEmploymentStatus_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHLabourEmploymentStatus_state, household_HHLabourPayroll_state);
			}
		

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_labour_report_status\n");

	if(FLAME_employment_status_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_employment_status)\n");
		rc = MB_SyncStart(b_employment_status);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_employment_status)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'employment_status' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'employment_status' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'employment_status' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_labour_pay_wages\n");
	current_xmachine_firm_holder = firm_FirmLabourPayWages_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmLabourWageAdjustment_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_labour_pay_wages_FirmLabourPayWages_FirmLabourWageAdjustment(current_xmachine_firm)==1)
		{

		

			i = firm_labour_pay_wages();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourPayWages_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmLabourPayWages_state, firm_FirmLabourWageAdjustment_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_labour_pay_wages\n");

	if(FLAME_labour_tax_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_labour_tax)\n");
		rc = MB_SyncStart(b_labour_tax);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_labour_tax)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'labour_tax' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'labour_tax' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'labour_tax' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmLabourPayWages_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmConsumptionStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmLabourPayWages_FirmConsumptionStart(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourPayWages_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmLabourPayWages_state, firm_FirmConsumptionStart_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


/* End of layer number 37 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

	/* DEBUG: States with branching functions */
		current_xmachine_household_holder = household_HHLabourPayroll_state->agents;
		while(current_xmachine_household_holder)
		{
			FLAME_debug_count = 0;
			/* Function: household_labour_recieve_wage */
			if(FLAME_condition_household_household_labour_recieve_wage_HHLabourPayroll_HHConsumptionStart(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_household_idle_HHLabourPayroll_HHConsumptionStart(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'household' leaving state 'HHLabourPayroll'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_household_holder = current_xmachine_household_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_labour_recieve_wage\n");
	current_xmachine_household_holder = household_HHLabourPayroll_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHConsumptionStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_household_labour_recieve_wage_HHLabourPayroll_HHConsumptionStart(current_xmachine_household)==1)
		{

		

			i = household_labour_recieve_wage();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHLabourPayroll_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHLabourPayroll_state, household_HHConsumptionStart_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_labour_recieve_wage\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_household_holder = household_HHLabourPayroll_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHConsumptionStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_idle_HHLabourPayroll_HHConsumptionStart(current_xmachine_household)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHLabourPayroll_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHLabourPayroll_state, household_HHConsumptionStart_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_labour_trace_wages\n");
	current_xmachine_firm_holder = firm_FirmLabourWageAdjustment_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmConsumptionStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		

			i = firm_labour_trace_wages();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourWageAdjustment_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmLabourWageAdjustment_state, firm_FirmConsumptionStart_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_labour_trace_wages\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_employment_status_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_employment_status)\n");
		rc = MB_SyncComplete(b_employment_status);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_employment_status)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'employment_status' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'employment_status' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start equityfund_audit_dividends\n");
	current_xmachine_equityfund_holder = equityfund_EFLabourMarket_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		current_xmachine_equityfund = current_xmachine_equityfund_holder->agent;
		current_xmachine_equityfund_next_state = equityfund_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_equityfund = current_xmachine_equityfund;

		if(FLAME_condition_equityfund_equityfund_audit_dividends_EFLabourMarket_end(current_xmachine_equityfund)==1)
		{

		
		
		
		  rc = MB_Iterator_Create(b_employment_status, &i_employment_status);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'employment_status'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'employment_status' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'employment_status' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = equityfund_audit_dividends();

		
		    rc = MB_Iterator_Delete(&i_employment_status);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'employment_status' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'employment_status' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFLabourMarket_state);
			}
			else
			{
				transition_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFLabourMarket_state, equityfund_end_state);
			}
		}

		current_xmachine_equityfund = NULL;

		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish equityfund_audit_dividends\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start centralbank_trace_unemployment_status\n");
	current_xmachine_centralbank_holder = centralbank_CentralBankLabour_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		current_xmachine_centralbank = current_xmachine_centralbank_holder->agent;
		current_xmachine_centralbank_next_state = centralbank_CentralBankConsumption_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_centralbank = current_xmachine_centralbank;

		if(FLAME_condition_centralbank_centralbank_trace_unemployment_status_CentralBankLabour_CentralBankConsumption(current_xmachine_centralbank)==1)
		{

		
		
		
		  rc = MB_Iterator_Create(b_employment_status, &i_employment_status);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'employment_status'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'employment_status' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'employment_status' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = centralbank_trace_unemployment_status();

		
		    rc = MB_Iterator_Delete(&i_employment_status);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'employment_status' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'employment_status' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankLabour_state);
			}
			else
			{
				transition_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankLabour_state, centralbank_CentralBankConsumption_state);
			}
		}

		current_xmachine_centralbank = NULL;

		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish centralbank_trace_unemployment_status\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_labour_tax_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_labour_tax)\n");
		rc = MB_SyncComplete(b_labour_tax);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_labour_tax)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'labour_tax' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'labour_tax' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start government_collect_labour_tax\n");
	current_xmachine_government_holder = government_GovernmentLabourTax_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		current_xmachine_government = current_xmachine_government_holder->agent;
		current_xmachine_government_next_state = government_GovernmentLabourStatus_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_government = current_xmachine_government;

		

		
		
		
		  rc = MB_Iterator_Create(b_labour_tax, &i_labour_tax);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'labour_tax'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'labour_tax' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'labour_tax' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = government_collect_labour_tax();

		
		    rc = MB_Iterator_Delete(&i_labour_tax);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'labour_tax' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'labour_tax' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_government_agent(current_xmachine_government_holder, government_GovernmentLabourTax_state);
			}
			else
			{
				transition_government_agent(current_xmachine_government_holder, government_GovernmentLabourTax_state, government_GovernmentLabourStatus_state);
			}
		

		current_xmachine_government = NULL;

		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish government_collect_labour_tax\n");


/* End of layer number 38 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_labour_tax_message_board_read == 0)
{
	/*printf("%d> labour_tax message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_labour_tax)\n");
	rc = MB_SyncComplete(b_labour_tax);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_labour_tax)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'labour_tax' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'labour_tax' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_labour_tax);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'labour_tax' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'labour_tax' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'labour_tax' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmConsumptionStart_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: firm_consumption_supply */
			if(FLAME_condition_firm_firm_consumption_supply_FirmConsumptionStart_FirmRecieveSales(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_firm_idle_FirmConsumptionStart_FirmHousingStart(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmConsumptionStart'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_household_holder = household_HHConsumptionStart_state->agents;
		while(current_xmachine_household_holder)
		{
			FLAME_debug_count = 0;
			/* Function: household_consumption_compute_budget */
			if(FLAME_condition_household_household_consumption_compute_budget_HHConsumptionStart_HHConsumptionWeekly(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_household_idle_HHConsumptionStart_HHConsumptionWeekly(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'household' leaving state 'HHConsumptionStart'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_household_holder = current_xmachine_household_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_centralbank_holder = centralbank_CentralBankConsumption_state->agents;
		while(current_xmachine_centralbank_holder)
		{
			FLAME_debug_count = 0;
			/* Function: centralbank_trace_goods_prices */
			if(FLAME_condition_centralbank_centralbank_trace_goods_prices_CentralBankConsumption_CentralBankHousing(current_xmachine_centralbank_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_centralbank_idle_CentralBankConsumption_CentralBankHousing(current_xmachine_centralbank_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'centralbank' leaving state 'CentralBankConsumption'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_consumption_supply\n");
	current_xmachine_firm_holder = firm_FirmConsumptionStart_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmRecieveSales_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_consumption_supply_FirmConsumptionStart_FirmRecieveSales(current_xmachine_firm)==1)
		{

		

			i = firm_consumption_supply();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmConsumptionStart_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmConsumptionStart_state, firm_FirmRecieveSales_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_consumption_supply\n");

	if(FLAME_sell_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_sell)\n");
		rc = MB_SyncStart(b_sell);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_sell)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'sell' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'sell' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'sell' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_centralbank_holder = centralbank_CentralBankConsumption_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		current_xmachine_centralbank = current_xmachine_centralbank_holder->agent;
		current_xmachine_centralbank_next_state = centralbank_CentralBankHousing_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_centralbank = current_xmachine_centralbank;

		if(FLAME_condition_centralbank_idle_CentralBankConsumption_CentralBankHousing(current_xmachine_centralbank)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankConsumption_state);
			}
			else
			{
				transition_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankConsumption_state, centralbank_CentralBankHousing_state);
			}
		}

		current_xmachine_centralbank = NULL;

		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_consumption_compute_budget\n");
	current_xmachine_household_holder = household_HHConsumptionStart_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHConsumptionWeekly_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_household_consumption_compute_budget_HHConsumptionStart_HHConsumptionWeekly(current_xmachine_household)==1)
		{

		

			i = household_consumption_compute_budget();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHConsumptionStart_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHConsumptionStart_state, household_HHConsumptionWeekly_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_consumption_compute_budget\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_household_holder = household_HHConsumptionStart_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHConsumptionWeekly_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_idle_HHConsumptionStart_HHConsumptionWeekly(current_xmachine_household)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHConsumptionStart_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHConsumptionStart_state, household_HHConsumptionWeekly_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmConsumptionStart_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmHousingStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmConsumptionStart_FirmHousingStart(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmConsumptionStart_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmConsumptionStart_state, firm_FirmHousingStart_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start government_trace_unemployment_status\n");
	current_xmachine_government_holder = government_GovernmentLabourStatus_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		current_xmachine_government = current_xmachine_government_holder->agent;
		current_xmachine_government_next_state = government_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_government = current_xmachine_government;

		

		
		
		
		  rc = MB_Iterator_Create(b_employment_status, &i_employment_status);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'employment_status'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'employment_status' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'employment_status' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = government_trace_unemployment_status();

		
		    rc = MB_Iterator_Delete(&i_employment_status);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'employment_status' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'employment_status' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_government_agent(current_xmachine_government_holder, government_GovernmentLabourStatus_state);
			}
			else
			{
				transition_government_agent(current_xmachine_government_holder, government_GovernmentLabourStatus_state, government_end_state);
			}
		

		current_xmachine_government = NULL;

		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish government_trace_unemployment_status\n");


/* End of layer number 39 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_employment_status_message_board_read == 0)
{
	/*printf("%d> employment_status message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_employment_status)\n");
	rc = MB_SyncComplete(b_employment_status);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_employment_status)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'employment_status' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'employment_status' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_employment_status);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'employment_status' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'employment_status' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'employment_status' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_household_holder = household_HHConsumptionWeekly_state->agents;
		while(current_xmachine_household_holder)
		{
			FLAME_debug_count = 0;
			/* Function: household_consumption_demand */
			if(FLAME_condition_household_household_consumption_demand_HHConsumptionWeekly_HHConsumptionRecieveGoods(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_household_idle_HHConsumptionWeekly_HHHousingStart(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'household' leaving state 'HHConsumptionWeekly'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_household_holder = current_xmachine_household_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_consumption_demand\n");
	current_xmachine_household_holder = household_HHConsumptionWeekly_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHConsumptionRecieveGoods_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_household_consumption_demand_HHConsumptionWeekly_HHConsumptionRecieveGoods(current_xmachine_household)==1)
		{

		

			i = household_consumption_demand();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHConsumptionWeekly_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHConsumptionWeekly_state, household_HHConsumptionRecieveGoods_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_consumption_demand\n");

	if(FLAME_buy_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_buy)\n");
		rc = MB_SyncStart(b_buy);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_buy)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'buy' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'buy' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'buy' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_household_holder = household_HHConsumptionWeekly_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHHousingStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_idle_HHConsumptionWeekly_HHHousingStart(current_xmachine_household)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHConsumptionWeekly_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHConsumptionWeekly_state, household_HHHousingStart_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


/* End of layer number 40 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_sell_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_sell)\n");
		rc = MB_SyncComplete(b_sell);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_sell)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'sell' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'sell' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_buy_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_buy)\n");
		rc = MB_SyncComplete(b_buy);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_buy)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'buy' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'buy' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start mall_consumption_shopping\n");
	current_xmachine_mall_holder = mall_MallConsumptionMarket_state->agents;
	while(current_xmachine_mall_holder)
	{
		temp_xmachine_mall_holder = current_xmachine_mall_holder->next;
		current_xmachine_mall = current_xmachine_mall_holder->agent;
		current_xmachine_mall_next_state = mall_MallConsumptionSummary_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_mall = current_xmachine_mall;

		if(FLAME_condition_mall_mall_consumption_shopping_MallConsumptionMarket_MallConsumptionSummary(current_xmachine_mall)==1)
		{

		
		
		
		  
		  rc = MB_Iterator_CreateSorted(b_sell, &i_sell, &FLAME_sort_mall_mall_consumption_shopping_MallConsumptionMarket_MallConsumptionSummary_sell);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'sell'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'sell' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'sell' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		
		
		
		  rc = MB_Iterator_Create(b_buy, &i_buy);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'buy'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'buy' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'buy' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_buy);
		

			i = mall_consumption_shopping();

		
		    rc = MB_Iterator_Delete(&i_sell);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'sell' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'sell' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		
		    rc = MB_Iterator_Delete(&i_buy);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'buy' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'buy' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_mall_agent(current_xmachine_mall_holder, mall_MallConsumptionMarket_state);
			}
			else
			{
				transition_mall_agent(current_xmachine_mall_holder, mall_MallConsumptionMarket_state, mall_MallConsumptionSummary_state);
			}
		}

		current_xmachine_mall = NULL;

		current_xmachine_mall_holder = temp_xmachine_mall_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish mall_consumption_shopping\n");

	if(FLAME_sold_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_sold)\n");
		rc = MB_SyncStart(b_sold);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_sold)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'sold' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'sold' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'sold' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    

	if(FLAME_bought_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bought)\n");
		rc = MB_SyncStart(b_bought);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bought)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'bought' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'bought' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'bought' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


/* End of layer number 41 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_buy_message_board_read == 0)
{
	/*printf("%d> buy message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_buy)\n");
	rc = MB_SyncComplete(b_buy);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_buy)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'buy' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'buy' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_buy);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'buy' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'buy' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'buy' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_sell_message_board_read == 0)
{
	/*printf("%d> sell message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_sell)\n");
	rc = MB_SyncComplete(b_sell);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_sell)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'sell' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'sell' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_sell);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'sell' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sell' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sell' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start mall_consumption_summary\n");
	current_xmachine_mall_holder = mall_MallConsumptionSummary_state->agents;
	while(current_xmachine_mall_holder)
	{
		temp_xmachine_mall_holder = current_xmachine_mall_holder->next;
		current_xmachine_mall = current_xmachine_mall_holder->agent;
		current_xmachine_mall_next_state = mall_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_mall = current_xmachine_mall;

		

		

			i = mall_consumption_summary();

		

			if(i == 1)
			{
				free_mall_agent(current_xmachine_mall_holder, mall_MallConsumptionSummary_state);
			}
			else
			{
				transition_mall_agent(current_xmachine_mall_holder, mall_MallConsumptionSummary_state, mall_end_state);
			}
		

		current_xmachine_mall = NULL;

		current_xmachine_mall_holder = temp_xmachine_mall_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish mall_consumption_summary\n");

	if(FLAME_goods_transactions_summary_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_goods_transactions_summary)\n");
		rc = MB_SyncStart(b_goods_transactions_summary);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_goods_transactions_summary)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'goods_transactions_summary' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'goods_transactions_summary' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'goods_transactions_summary' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_sold_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_sold)\n");
		rc = MB_SyncComplete(b_sold);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_sold)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'sold' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'sold' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_consumption_recieve_sales\n");
	current_xmachine_firm_holder = firm_FirmRecieveSales_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmConsumptionPrice_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_sold, &i_sold, &FLAME_filter_firm_firm_consumption_recieve_sales_FirmRecieveSales_FirmConsumptionPrice_sold, current_xmachine_firm);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'sold'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'sold' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'sold' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = firm_consumption_recieve_sales();

		
		    rc = MB_Iterator_Delete(&i_sold);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'sold' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'sold' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmRecieveSales_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmRecieveSales_state, firm_FirmConsumptionPrice_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_consumption_recieve_sales\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_bought_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bought)\n");
		rc = MB_SyncComplete(b_bought);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bought)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'bought' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'bought' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_consumption_recieve_goods\n");
	current_xmachine_household_holder = household_HHConsumptionRecieveGoods_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHHousingStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_bought, &i_bought, &FLAME_filter_household_household_consumption_recieve_goods_HHConsumptionRecieveGoods_HHHousingStart_bought, current_xmachine_household);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'bought'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'bought' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bought' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = household_consumption_recieve_goods();

		
		    rc = MB_Iterator_Delete(&i_bought);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'bought' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'bought' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHConsumptionRecieveGoods_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHConsumptionRecieveGoods_state, household_HHHousingStart_state);
			}
		

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_consumption_recieve_goods\n");


/* End of layer number 42 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_bought_message_board_read == 0)
{
	/*printf("%d> bought message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bought)\n");
	rc = MB_SyncComplete(b_bought);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bought)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'bought' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'bought' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_bought);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'bought' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bought' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bought' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_sold_message_board_read == 0)
{
	/*printf("%d> sold message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_sold)\n");
	rc = MB_SyncComplete(b_sold);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_sold)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'sold' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'sold' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_sold);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'sold' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sold' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sold' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_household_holder = household_HHHousingStart_state->agents;
		while(current_xmachine_household_holder)
		{
			FLAME_debug_count = 0;
			/* Function: household_housing_market_role */
			if(FLAME_condition_household_household_housing_market_role_HHHousingStart_HHHousingRole(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_household_idle_HHHousingStart_HouseholdUpdateDeposits(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'household' leaving state 'HHHousingStart'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_household_holder = current_xmachine_household_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_housing_market_role\n");
	current_xmachine_household_holder = household_HHHousingStart_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHHousingRole_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_household_housing_market_role_HHHousingStart_HHHousingRole(current_xmachine_household)==1)
		{

		

			i = household_housing_market_role();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHHousingStart_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHHousingStart_state, household_HHHousingRole_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_housing_market_role\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_household_holder = household_HHHousingStart_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HouseholdUpdateDeposits_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_idle_HHHousingStart_HouseholdUpdateDeposits(current_xmachine_household)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHHousingStart_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHHousingStart_state, household_HouseholdUpdateDeposits_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_goods_transactions_summary_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_goods_transactions_summary)\n");
		rc = MB_SyncComplete(b_goods_transactions_summary);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_goods_transactions_summary)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'goods_transactions_summary' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'goods_transactions_summary' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_consumption_update_market_price\n");
	current_xmachine_firm_holder = firm_FirmConsumptionPrice_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmHousingStart_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		
		
		
		  rc = MB_Iterator_Create(b_goods_transactions_summary, &i_goods_transactions_summary);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'goods_transactions_summary'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'goods_transactions_summary' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'goods_transactions_summary' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = firm_consumption_update_market_price();

		
		    rc = MB_Iterator_Delete(&i_goods_transactions_summary);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'goods_transactions_summary' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'goods_transactions_summary' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmConsumptionPrice_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmConsumptionPrice_state, firm_FirmHousingStart_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_consumption_update_market_price\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start centralbank_trace_goods_prices\n");
	current_xmachine_centralbank_holder = centralbank_CentralBankConsumption_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		current_xmachine_centralbank = current_xmachine_centralbank_holder->agent;
		current_xmachine_centralbank_next_state = centralbank_CentralBankHousing_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_centralbank = current_xmachine_centralbank;

		if(FLAME_condition_centralbank_centralbank_trace_goods_prices_CentralBankConsumption_CentralBankHousing(current_xmachine_centralbank)==1)
		{

		
		
		
		  rc = MB_Iterator_Create(b_goods_transactions_summary, &i_goods_transactions_summary);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'goods_transactions_summary'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'goods_transactions_summary' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'goods_transactions_summary' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = centralbank_trace_goods_prices();

		
		    rc = MB_Iterator_Delete(&i_goods_transactions_summary);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'goods_transactions_summary' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'goods_transactions_summary' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankConsumption_state);
			}
			else
			{
				transition_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankConsumption_state, centralbank_CentralBankHousing_state);
			}
		}

		current_xmachine_centralbank = NULL;

		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish centralbank_trace_goods_prices\n");


/* End of layer number 43 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_goods_transactions_summary_message_board_read == 0)
{
	/*printf("%d> goods_transactions_summary message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_goods_transactions_summary)\n");
	rc = MB_SyncComplete(b_goods_transactions_summary);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_goods_transactions_summary)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'goods_transactions_summary' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'goods_transactions_summary' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_goods_transactions_summary);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'goods_transactions_summary' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'goods_transactions_summary' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'goods_transactions_summary' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_household_holder = household_HHHousingRole_state->agents;
		while(current_xmachine_household_holder)
		{
			FLAME_debug_count = 0;
			/* Function: household_housing_fire_sell */
			if(FLAME_condition_household_household_housing_fire_sell_HHHousingRole_HHHousingRevenue(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: household_housing_sell */
			if(FLAME_condition_household_household_housing_sell_HHHousingRole_HHHousingRevenue(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: household_housing_check_wealth */
			if(FLAME_condition_household_household_housing_check_wealth_HHHousingRole_HHHousingCheckWealth(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_household_idle_HHHousingRole_HHHousingPrice(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'household' leaving state 'HHHousingRole'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_household_holder = current_xmachine_household_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_centralbank_holder = centralbank_CentralBankHousing_state->agents;
		while(current_xmachine_centralbank_holder)
		{
			FLAME_debug_count = 0;
			/* Function: centralbank_trace_housing_prices */
			if(FLAME_condition_centralbank_centralbank_trace_housing_prices_CentralBankHousing_end(current_xmachine_centralbank_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_centralbank_idle_CentralBankHousing_end(current_xmachine_centralbank_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'centralbank' leaving state 'CentralBankHousing'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_housing_sell\n");
	current_xmachine_household_holder = household_HHHousingRole_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHHousingRevenue_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_household_housing_sell_HHHousingRole_HHHousingRevenue(current_xmachine_household)==1)
		{

		

			i = household_housing_sell();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHHousingRole_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHHousingRole_state, household_HHHousingRevenue_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_housing_sell\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_housing_fire_sell\n");
	current_xmachine_household_holder = household_HHHousingRole_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHHousingRevenue_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_household_housing_fire_sell_HHHousingRole_HHHousingRevenue(current_xmachine_household)==1)
		{

		

			i = household_housing_fire_sell();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHHousingRole_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHHousingRole_state, household_HHHousingRevenue_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_housing_fire_sell\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_centralbank_holder = centralbank_CentralBankHousing_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		current_xmachine_centralbank = current_xmachine_centralbank_holder->agent;
		current_xmachine_centralbank_next_state = centralbank_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_centralbank = current_xmachine_centralbank;

		if(FLAME_condition_centralbank_idle_CentralBankHousing_end(current_xmachine_centralbank)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankHousing_state);
			}
			else
			{
				transition_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankHousing_state, centralbank_end_state);
			}
		}

		current_xmachine_centralbank = NULL;

		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_housing_check_wealth\n");
	current_xmachine_household_holder = household_HHHousingRole_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHHousingCheckWealth_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_household_housing_check_wealth_HHHousingRole_HHHousingCheckWealth(current_xmachine_household)==1)
		{

		

			i = household_housing_check_wealth();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHHousingRole_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHHousingRole_state, household_HHHousingCheckWealth_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_housing_check_wealth\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_household_holder = household_HHHousingRole_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHHousingPrice_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_idle_HHHousingRole_HHHousingPrice(current_xmachine_household)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHHousingRole_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHHousingRole_state, household_HHHousingPrice_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmHousingStart_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmHousingMarket_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmHousingStart_FirmHousingMarket(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmHousingStart_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmHousingStart_state, firm_FirmHousingMarket_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmHousingStart_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmUpdateDeposits_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmHousingStart_FirmUpdateDeposits(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmHousingStart_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmHousingStart_state, firm_FirmUpdateDeposits_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


/* End of layer number 44 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmHousingMarket_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: firm_housing_enter_market */
			if(FLAME_condition_firm_firm_housing_enter_market_FirmHousingMarket_FirmHousingSell(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_firm_idle_FirmHousingMarket_FirmUpdateDeposits(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmHousingMarket'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
		/* DEBUG: States with branching functions */
		current_xmachine_household_holder = household_HHHousingCheckWealth_state->agents;
		while(current_xmachine_household_holder)
		{
			FLAME_debug_count = 0;
			/* Function: household_housing_enter_market */
			if(FLAME_condition_household_household_housing_enter_market_HHHousingCheckWealth_HHHousingBargain(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_household_idle_HHHousingCheckWealth_HHHousingPrice(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'household' leaving state 'HHHousingCheckWealth'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_household_holder = current_xmachine_household_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_housing_enter_market\n");
	current_xmachine_firm_holder = firm_FirmHousingMarket_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmHousingSell_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_housing_enter_market_FirmHousingMarket_FirmHousingSell(current_xmachine_firm)==1)
		{

		

			i = firm_housing_enter_market();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmHousingMarket_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmHousingMarket_state, firm_FirmHousingSell_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_housing_enter_market\n");

	if(FLAME_sell_housing_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_sell_housing)\n");
		rc = MB_SyncStart(b_sell_housing);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_sell_housing)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'sell_housing' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'sell_housing' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'sell_housing' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_housing_enter_market\n");
	current_xmachine_household_holder = household_HHHousingCheckWealth_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHHousingBargain_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_household_housing_enter_market_HHHousingCheckWealth_HHHousingBargain(current_xmachine_household)==1)
		{

		

			i = household_housing_enter_market();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHHousingCheckWealth_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHHousingCheckWealth_state, household_HHHousingBargain_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_housing_enter_market\n");

	if(FLAME_buy_housing_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_buy_housing)\n");
		rc = MB_SyncStart(b_buy_housing);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_buy_housing)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'buy_housing' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'buy_housing' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'buy_housing' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_household_holder = household_HHHousingCheckWealth_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHHousingPrice_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_idle_HHHousingCheckWealth_HHHousingPrice(current_xmachine_household)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHHousingCheckWealth_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHHousingCheckWealth_state, household_HHHousingPrice_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmHousingMarket_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmUpdateDeposits_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmHousingMarket_FirmUpdateDeposits(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmHousingMarket_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmHousingMarket_state, firm_FirmUpdateDeposits_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


/* End of layer number 45 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_mortgaging_capacity_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_mortgaging_capacity)\n");
		rc = MB_SyncComplete(b_mortgaging_capacity);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_mortgaging_capacity)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'mortgaging_capacity' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'mortgaging_capacity' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_sell_housing_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_sell_housing)\n");
		rc = MB_SyncComplete(b_sell_housing);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_sell_housing)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'sell_housing' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'sell_housing' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_buy_housing_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_buy_housing)\n");
		rc = MB_SyncComplete(b_buy_housing);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_buy_housing)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'buy_housing' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'buy_housing' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start reagency_housing_process\n");
	current_xmachine_reagency_holder = reagency_REAgencyHousingProcess_state->agents;
	while(current_xmachine_reagency_holder)
	{
		temp_xmachine_reagency_holder = current_xmachine_reagency_holder->next;
		current_xmachine_reagency = current_xmachine_reagency_holder->agent;
		current_xmachine_reagency_next_state = reagency_REAgencyHousingSummary_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_reagency = current_xmachine_reagency;

		

		
		
		
		  rc = MB_Iterator_Create(b_buy_housing, &i_buy_housing);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'buy_housing'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'buy_housing' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'buy_housing' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_buy_housing);
		
		
		
		  
		  rc = MB_Iterator_CreateSorted(b_sell_housing, &i_sell_housing, &FLAME_sort_reagency_reagency_housing_process_REAgencyHousingProcess_REAgencyHousingSummary_sell_housing);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'sell_housing'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'sell_housing' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'sell_housing' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		
		
		
		  
		  rc = MB_Iterator_CreateSorted(b_mortgaging_capacity, &i_mortgaging_capacity, &FLAME_sort_reagency_reagency_housing_process_REAgencyHousingProcess_REAgencyHousingSummary_mortgaging_capacity);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'mortgaging_capacity'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'mortgaging_capacity' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'mortgaging_capacity' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = reagency_housing_process();

		
		    rc = MB_Iterator_Delete(&i_buy_housing);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'buy_housing' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'buy_housing' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		
		    rc = MB_Iterator_Delete(&i_sell_housing);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'sell_housing' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'sell_housing' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		
		    rc = MB_Iterator_Delete(&i_mortgaging_capacity);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'mortgaging_capacity' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'mortgaging_capacity' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_reagency_agent(current_xmachine_reagency_holder, reagency_REAgencyHousingProcess_state);
			}
			else
			{
				transition_reagency_agent(current_xmachine_reagency_holder, reagency_REAgencyHousingProcess_state, reagency_REAgencyHousingSummary_state);
			}
		

		current_xmachine_reagency = NULL;

		current_xmachine_reagency_holder = temp_xmachine_reagency_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish reagency_housing_process\n");

	if(FLAME_mortgage_requests_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_mortgage_requests)\n");
		rc = MB_SyncStart(b_mortgage_requests);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_mortgage_requests)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'mortgage_requests' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'mortgage_requests' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'mortgage_requests' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    

	if(FLAME_sold_housing_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_sold_housing)\n");
		rc = MB_SyncStart(b_sold_housing);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_sold_housing)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'sold_housing' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'sold_housing' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'sold_housing' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    

	if(FLAME_bought_housing_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bought_housing)\n");
		rc = MB_SyncStart(b_bought_housing);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bought_housing)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'bought_housing' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'bought_housing' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'bought_housing' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


/* End of layer number 46 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_buy_housing_message_board_read == 0)
{
	/*printf("%d> buy_housing message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_buy_housing)\n");
	rc = MB_SyncComplete(b_buy_housing);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_buy_housing)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'buy_housing' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'buy_housing' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_buy_housing);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'buy_housing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'buy_housing' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'buy_housing' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_sell_housing_message_board_read == 0)
{
	/*printf("%d> sell_housing message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_sell_housing)\n");
	rc = MB_SyncComplete(b_sell_housing);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_sell_housing)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'sell_housing' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'sell_housing' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_sell_housing);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'sell_housing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sell_housing' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sell_housing' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_mortgaging_capacity_message_board_read == 0)
{
	/*printf("%d> mortgaging_capacity message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_mortgaging_capacity)\n");
	rc = MB_SyncComplete(b_mortgaging_capacity);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_mortgaging_capacity)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'mortgaging_capacity' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'mortgaging_capacity' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_mortgaging_capacity);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'mortgaging_capacity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgaging_capacity' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mortgaging_capacity' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start reagency_housing_summary\n");
	current_xmachine_reagency_holder = reagency_REAgencyHousingSummary_state->agents;
	while(current_xmachine_reagency_holder)
	{
		temp_xmachine_reagency_holder = current_xmachine_reagency_holder->next;
		current_xmachine_reagency = current_xmachine_reagency_holder->agent;
		current_xmachine_reagency_next_state = reagency_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_reagency = current_xmachine_reagency;

		

		

			i = reagency_housing_summary();

		

			if(i == 1)
			{
				free_reagency_agent(current_xmachine_reagency_holder, reagency_REAgencyHousingSummary_state);
			}
			else
			{
				transition_reagency_agent(current_xmachine_reagency_holder, reagency_REAgencyHousingSummary_state, reagency_end_state);
			}
		

		current_xmachine_reagency = NULL;

		current_xmachine_reagency_holder = temp_xmachine_reagency_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish reagency_housing_summary\n");

	if(FLAME_housing_transactions_summary_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_housing_transactions_summary)\n");
		rc = MB_SyncStart(b_housing_transactions_summary);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_housing_transactions_summary)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'housing_transactions_summary' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'housing_transactions_summary' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'housing_transactions_summary' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    

	if(FLAME_housing_price_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_housing_price)\n");
		rc = MB_SyncStart(b_housing_price);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_housing_price)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'housing_price' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'housing_price' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'housing_price' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_sold_housing_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_sold_housing)\n");
		rc = MB_SyncComplete(b_sold_housing);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_sold_housing)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'sold_housing' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'sold_housing' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_housing_collect_sale_revenues\n");
	current_xmachine_firm_holder = firm_FirmHousingSell_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmHousingPrice_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_sold_housing, &i_sold_housing, &FLAME_filter_firm_firm_housing_collect_sale_revenues_FirmHousingSell_FirmHousingPrice_sold_housing, current_xmachine_firm);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'sold_housing'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'sold_housing' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'sold_housing' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = firm_housing_collect_sale_revenues();

		
		    rc = MB_Iterator_Delete(&i_sold_housing);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'sold_housing' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'sold_housing' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmHousingSell_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmHousingSell_state, firm_FirmHousingPrice_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_housing_collect_sale_revenues\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_housing_collect_sale_revenue\n");
	current_xmachine_household_holder = household_HHHousingRevenue_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHHousingPrice_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_sold_housing, &i_sold_housing, &FLAME_filter_household_household_housing_collect_sale_revenue_HHHousingRevenue_HHHousingPrice_sold_housing, current_xmachine_household);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'sold_housing'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'sold_housing' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'sold_housing' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = household_housing_collect_sale_revenue();

		
		    rc = MB_Iterator_Delete(&i_sold_housing);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'sold_housing' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'sold_housing' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHHousingRevenue_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHHousingRevenue_state, household_HHHousingPrice_state);
			}
		

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_housing_collect_sale_revenue\n");

	if(FLAME_mortgage_payment_from_sale_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_mortgage_payment_from_sale)\n");
		rc = MB_SyncStart(b_mortgage_payment_from_sale);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_mortgage_payment_from_sale)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'mortgage_payment_from_sale' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_bought_housing_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bought_housing)\n");
		rc = MB_SyncComplete(b_bought_housing);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bought_housing)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'bought_housing' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'bought_housing' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_housing_buy\n");
	current_xmachine_household_holder = household_HHHousingBargain_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHHousingPrice_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_bought_housing, &i_bought_housing, &FLAME_filter_household_household_housing_buy_HHHousingBargain_HHHousingPrice_bought_housing, current_xmachine_household);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'bought_housing'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'bought_housing' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bought_housing' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = household_housing_buy();

		
		    rc = MB_Iterator_Delete(&i_bought_housing);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'bought_housing' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'bought_housing' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHHousingBargain_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHHousingBargain_state, household_HHHousingPrice_state);
			}
		

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_housing_buy\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_mortgage_requests_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_mortgage_requests)\n");
		rc = MB_SyncComplete(b_mortgage_requests);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_mortgage_requests)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'mortgage_requests' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'mortgage_requests' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_housing_deliver_mortages\n");
	current_xmachine_bank_holder = bank_BankHousingCrediting_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankHousingSales_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_mortgage_requests, &i_mortgage_requests, &FLAME_filter_bank_bank_housing_deliver_mortages_BankHousingCrediting_BankHousingSales_mortgage_requests, current_xmachine_bank);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'mortgage_requests'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'mortgage_requests' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'mortgage_requests' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = bank_housing_deliver_mortages();

		
		    rc = MB_Iterator_Delete(&i_mortgage_requests);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'mortgage_requests' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'mortgage_requests' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankHousingCrediting_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankHousingCrediting_state, bank_BankHousingSales_state);
			}
		

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_housing_deliver_mortages\n");


/* End of layer number 47 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_bought_housing_message_board_read == 0)
{
	/*printf("%d> bought_housing message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bought_housing)\n");
	rc = MB_SyncComplete(b_bought_housing);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bought_housing)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'bought_housing' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'bought_housing' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_bought_housing);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'bought_housing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bought_housing' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bought_housing' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_sold_housing_message_board_read == 0)
{
	/*printf("%d> sold_housing message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_sold_housing)\n");
	rc = MB_SyncComplete(b_sold_housing);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_sold_housing)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'sold_housing' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'sold_housing' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_sold_housing);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'sold_housing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sold_housing' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sold_housing' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_mortgage_requests_message_board_read == 0)
{
	/*printf("%d> mortgage_requests message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_mortgage_requests)\n");
	rc = MB_SyncComplete(b_mortgage_requests);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_mortgage_requests)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'mortgage_requests' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'mortgage_requests' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_mortgage_requests);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'mortgage_requests' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_requests' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mortgage_requests' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_housing_price_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_housing_price)\n");
		rc = MB_SyncComplete(b_housing_price);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_housing_price)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'housing_price' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'housing_price' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_housing_update_market_price\n");
	current_xmachine_firm_holder = firm_FirmHousingPrice_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_FirmUpdateDeposits_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		
		
		
		  rc = MB_Iterator_Create(b_housing_price, &i_housing_price);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'housing_price'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'housing_price' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'housing_price' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = firm_housing_update_market_price();

		
		    rc = MB_Iterator_Delete(&i_housing_price);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'housing_price' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'housing_price' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmHousingPrice_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmHousingPrice_state, firm_FirmUpdateDeposits_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_housing_update_market_price\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_housing_update_market_price\n");
	current_xmachine_household_holder = household_HHHousingPrice_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHHousingPayments_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		

		
		
		
		  rc = MB_Iterator_Create(b_housing_price, &i_housing_price);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'housing_price'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'housing_price' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'housing_price' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = household_housing_update_market_price();

		
		    rc = MB_Iterator_Delete(&i_housing_price);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'housing_price' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'housing_price' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHHousingPrice_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHHousingPrice_state, household_HHHousingPayments_state);
			}
		

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_housing_update_market_price\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_housing_transactions_summary_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_housing_transactions_summary)\n");
		rc = MB_SyncComplete(b_housing_transactions_summary);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_housing_transactions_summary)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'housing_transactions_summary' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'housing_transactions_summary' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start centralbank_trace_housing_prices\n");
	current_xmachine_centralbank_holder = centralbank_CentralBankHousing_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		current_xmachine_centralbank = current_xmachine_centralbank_holder->agent;
		current_xmachine_centralbank_next_state = centralbank_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_centralbank = current_xmachine_centralbank;

		if(FLAME_condition_centralbank_centralbank_trace_housing_prices_CentralBankHousing_end(current_xmachine_centralbank)==1)
		{

		
		
		
		  rc = MB_Iterator_Create(b_housing_transactions_summary, &i_housing_transactions_summary);
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'housing_transactions_summary'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'housing_transactions_summary' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'housing_transactions_summary' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = centralbank_trace_housing_prices();

		
		    rc = MB_Iterator_Delete(&i_housing_transactions_summary);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'housing_transactions_summary' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'housing_transactions_summary' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankHousing_state);
			}
			else
			{
				transition_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankHousing_state, centralbank_end_state);
			}
		}

		current_xmachine_centralbank = NULL;

		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish centralbank_trace_housing_prices\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_mortgage_payment_from_sale_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_mortgage_payment_from_sale)\n");
		rc = MB_SyncComplete(b_mortgage_payment_from_sale);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_mortgage_payment_from_sale)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'mortgage_payment_from_sale' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_housing_recieve_mortgage_principals\n");
	current_xmachine_bank_holder = bank_BankHousingSales_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankHousingMortgages_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_mortgage_payment_from_sale, &i_mortgage_payment_from_sale, &FLAME_filter_bank_bank_housing_recieve_mortgage_principals_BankHousingSales_BankHousingMortgages_mortgage_payment_from_sale, current_xmachine_bank);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'mortgage_payment_from_sale'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = bank_housing_recieve_mortgage_principals();

		
		    rc = MB_Iterator_Delete(&i_mortgage_payment_from_sale);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'mortgage_payment_from_sale' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankHousingSales_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankHousingSales_state, bank_BankHousingMortgages_state);
			}
		

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_housing_recieve_mortgage_principals\n");


/* End of layer number 48 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_housing_price_message_board_read == 0)
{
	/*printf("%d> housing_price message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_housing_price)\n");
	rc = MB_SyncComplete(b_housing_price);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_housing_price)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'housing_price' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'housing_price' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_housing_price);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'housing_price' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'housing_price' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'housing_price' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_mortgage_payment_from_sale_message_board_read == 0)
{
	/*printf("%d> mortgage_payment_from_sale message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_mortgage_payment_from_sale)\n");
	rc = MB_SyncComplete(b_mortgage_payment_from_sale);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_mortgage_payment_from_sale)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'mortgage_payment_from_sale' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_mortgage_payment_from_sale);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'mortgage_payment_from_sale' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_housing_transactions_summary_message_board_read == 0)
{
	/*printf("%d> housing_transactions_summary message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_housing_transactions_summary)\n");
	rc = MB_SyncComplete(b_housing_transactions_summary);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_housing_transactions_summary)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'housing_transactions_summary' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'housing_transactions_summary' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_housing_transactions_summary);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'housing_transactions_summary' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'housing_transactions_summary' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'housing_transactions_summary' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_firm_holder = firm_FirmUpdateDeposits_state->agents;
		while(current_xmachine_firm_holder)
		{
			FLAME_debug_count = 0;
			/* Function: firm_update_bank_account */
			if(FLAME_condition_firm_firm_update_bank_account_FirmUpdateDeposits_end(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_firm_idle_FirmUpdateDeposits_end(current_xmachine_firm_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'firm' leaving state 'FirmUpdateDeposits'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_firm_holder = current_xmachine_firm_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_housing_pay_mortgages\n");
	current_xmachine_household_holder = household_HHHousingPayments_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HHHousingWriteOff_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		

		

			i = household_housing_pay_mortgages();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHHousingPayments_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHHousingPayments_state, household_HHHousingWriteOff_state);
			}
		

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_housing_pay_mortgages\n");

	if(FLAME_mortgage_payment_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_mortgage_payment)\n");
		rc = MB_SyncStart(b_mortgage_payment);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_mortgage_payment)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'mortgage_payment' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'mortgage_payment' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'mortgage_payment' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start firm_update_bank_account\n");
	current_xmachine_firm_holder = firm_FirmUpdateDeposits_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_firm_update_bank_account_FirmUpdateDeposits_end(current_xmachine_firm)==1)
		{

		

			i = firm_update_bank_account();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmUpdateDeposits_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmUpdateDeposits_state, firm_end_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish firm_update_bank_account\n");

	if(FLAME_firm_bank_update_deposit_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_firm_bank_update_deposit)\n");
		rc = MB_SyncStart(b_firm_bank_update_deposit);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_firm_bank_update_deposit)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'firm_bank_update_deposit' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_firm_holder = firm_FirmUpdateDeposits_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		if(FLAME_condition_firm_idle_FirmUpdateDeposits_end(current_xmachine_firm)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_FirmUpdateDeposits_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_FirmUpdateDeposits_state, firm_end_state);
			}
		}

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


/* End of layer number 49 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_housing_debt_writeoff\n");
	current_xmachine_household_holder = household_HHHousingWriteOff_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_HouseholdUpdateDeposits_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		

		

			i = household_housing_debt_writeoff();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HHHousingWriteOff_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HHHousingWriteOff_state, household_HouseholdUpdateDeposits_state);
			}
		

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_housing_debt_writeoff\n");

	if(FLAME_mortgage_writeoff_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_mortgage_writeoff)\n");
		rc = MB_SyncStart(b_mortgage_writeoff);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_mortgage_writeoff)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'mortgage_writeoff' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'mortgage_writeoff' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'mortgage_writeoff' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_mortgage_payment_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_mortgage_payment)\n");
		rc = MB_SyncComplete(b_mortgage_payment);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_mortgage_payment)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'mortgage_payment' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'mortgage_payment' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_housing_recieve_mortgages\n");
	current_xmachine_bank_holder = bank_BankHousingMortgages_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankHousingWriteOff_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_mortgage_payment, &i_mortgage_payment, &FLAME_filter_bank_bank_housing_recieve_mortgages_BankHousingMortgages_BankHousingWriteOff_mortgage_payment, current_xmachine_bank);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'mortgage_payment'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'mortgage_payment' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'mortgage_payment' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = bank_housing_recieve_mortgages();

		
		    rc = MB_Iterator_Delete(&i_mortgage_payment);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'mortgage_payment' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'mortgage_payment' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankHousingMortgages_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankHousingMortgages_state, bank_BankHousingWriteOff_state);
			}
		

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_housing_recieve_mortgages\n");


/* End of layer number 50 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_mortgage_payment_message_board_read == 0)
{
	/*printf("%d> mortgage_payment message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_mortgage_payment)\n");
	rc = MB_SyncComplete(b_mortgage_payment);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_mortgage_payment)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'mortgage_payment' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'mortgage_payment' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_mortgage_payment);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'mortgage_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_payment' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mortgage_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_household_holder = household_HouseholdUpdateDeposits_state->agents;
		while(current_xmachine_household_holder)
		{
			FLAME_debug_count = 0;
			/* Function: household_update_bank_account */
			if(FLAME_condition_household_household_update_bank_account_HouseholdUpdateDeposits_end(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_household_idle_HouseholdUpdateDeposits_end(current_xmachine_household_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'household' leaving state 'HouseholdUpdateDeposits'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_household_holder = current_xmachine_household_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start household_update_bank_account\n");
	current_xmachine_household_holder = household_HouseholdUpdateDeposits_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_household_update_bank_account_HouseholdUpdateDeposits_end(current_xmachine_household)==1)
		{

		

			i = household_update_bank_account();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HouseholdUpdateDeposits_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HouseholdUpdateDeposits_state, household_end_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish household_update_bank_account\n");

	if(FLAME_household_bank_update_deposit_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_household_bank_update_deposit)\n");
		rc = MB_SyncStart(b_household_bank_update_deposit);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_household_bank_update_deposit)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'household_bank_update_deposit' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'household_bank_update_deposit' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'household_bank_update_deposit' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_household_holder = household_HouseholdUpdateDeposits_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		current_xmachine_household = current_xmachine_household_holder->agent;
		current_xmachine_household_next_state = household_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_household = current_xmachine_household;

		if(FLAME_condition_household_idle_HouseholdUpdateDeposits_end(current_xmachine_household)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_household_agent(current_xmachine_household_holder, household_HouseholdUpdateDeposits_state);
			}
			else
			{
				transition_household_agent(current_xmachine_household_holder, household_HouseholdUpdateDeposits_state, household_end_state);
			}
		}

		current_xmachine_household = NULL;

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_mortgage_writeoff_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_mortgage_writeoff)\n");
		rc = MB_SyncComplete(b_mortgage_writeoff);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_mortgage_writeoff)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'mortgage_writeoff' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'mortgage_writeoff' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_housing_debt_writeoff\n");
	current_xmachine_bank_holder = bank_BankHousingWriteOff_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_BankUpdateDeposits_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_mortgage_writeoff, &i_mortgage_writeoff, &FLAME_filter_bank_bank_housing_debt_writeoff_BankHousingWriteOff_BankUpdateDeposits_mortgage_writeoff, current_xmachine_bank);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'mortgage_writeoff'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'mortgage_writeoff' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'mortgage_writeoff' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = bank_housing_debt_writeoff();

		
		    rc = MB_Iterator_Delete(&i_mortgage_writeoff);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'mortgage_writeoff' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'mortgage_writeoff' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankHousingWriteOff_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankHousingWriteOff_state, bank_BankUpdateDeposits_state);
			}
		

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_housing_debt_writeoff\n");


/* End of layer number 51 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_mortgage_writeoff_message_board_read == 0)
{
	/*printf("%d> mortgage_writeoff message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_mortgage_writeoff)\n");
	rc = MB_SyncComplete(b_mortgage_writeoff);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_mortgage_writeoff)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'mortgage_writeoff' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'mortgage_writeoff' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_mortgage_writeoff);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'mortgage_writeoff' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_writeoff' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mortgage_writeoff' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

	/* DEBUG: States with branching functions */
		current_xmachine_bank_holder = bank_BankUpdateDeposits_state->agents;
		while(current_xmachine_bank_holder)
		{
			FLAME_debug_count = 0;
			/* Function: bank_update_deposits */
			if(FLAME_condition_bank_bank_update_deposits_BankUpdateDeposits_end(current_xmachine_bank_holder->agent)==1)
			{ FLAME_debug_count++; }
			/* Function: idle */
			if(FLAME_condition_bank_idle_BankUpdateDeposits_end(current_xmachine_bank_holder->agent)==1)
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'bank' leaving state 'BankUpdateDeposits'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_bank_holder = current_xmachine_bank_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_bank_holder = bank_BankUpdateDeposits_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		if(FLAME_condition_bank_idle_BankUpdateDeposits_end(current_xmachine_bank)==1)
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankUpdateDeposits_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankUpdateDeposits_state, bank_end_state);
			}
		}

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_household_bank_update_deposit_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_household_bank_update_deposit)\n");
		rc = MB_SyncComplete(b_household_bank_update_deposit);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_household_bank_update_deposit)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'household_bank_update_deposit' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'household_bank_update_deposit' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_firm_bank_update_deposit_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_firm_bank_update_deposit)\n");
		rc = MB_SyncComplete(b_firm_bank_update_deposit);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_firm_bank_update_deposit)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'firm_bank_update_deposit' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start bank_update_deposits\n");
	current_xmachine_bank_holder = bank_BankUpdateDeposits_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		current_xmachine_bank = current_xmachine_bank_holder->agent;
		current_xmachine_bank_next_state = bank_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_household = NULL;
		current_xmachine->xmachine_equityfund = NULL;
		current_xmachine->xmachine_bank = NULL;
		current_xmachine->xmachine_government = NULL;
		current_xmachine->xmachine_centralbank = NULL;
		current_xmachine->xmachine_jpoffice = NULL;
		current_xmachine->xmachine_mall = NULL;
		current_xmachine->xmachine_reagency = NULL;
		current_xmachine->xmachine_bank = current_xmachine_bank;

		if(FLAME_condition_bank_bank_update_deposits_BankUpdateDeposits_end(current_xmachine_bank)==1)
		{

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_household_bank_update_deposit, &i_household_bank_update_deposit, &FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_end_household_bank_update_deposit, current_xmachine_bank);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'household_bank_update_deposit'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'household_bank_update_deposit' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'household_bank_update_deposit' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_firm_bank_update_deposit, &i_firm_bank_update_deposit, &FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_end_firm_bank_update_deposit, current_xmachine_bank);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'firm_bank_update_deposit'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = bank_update_deposits();

		
		    rc = MB_Iterator_Delete(&i_household_bank_update_deposit);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'household_bank_update_deposit' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'household_bank_update_deposit' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		
		    rc = MB_Iterator_Delete(&i_firm_bank_update_deposit);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'firm_bank_update_deposit' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'firm_bank_update_deposit' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_bank_agent(current_xmachine_bank_holder, bank_BankUpdateDeposits_state);
			}
			else
			{
				transition_bank_agent(current_xmachine_bank_holder, bank_BankUpdateDeposits_state, bank_end_state);
			}
		}

		current_xmachine_bank = NULL;

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish bank_update_deposits\n");


/* End of layer number 52 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_firm_bank_update_deposit_message_board_read == 0)
{
	/*printf("%d> firm_bank_update_deposit message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_firm_bank_update_deposit)\n");
	rc = MB_SyncComplete(b_firm_bank_update_deposit);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_firm_bank_update_deposit)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'firm_bank_update_deposit' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_firm_bank_update_deposit);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'firm_bank_update_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

if(FLAME_household_bank_update_deposit_message_board_read == 0)
{
	/*printf("%d> household_bank_update_deposit message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_household_bank_update_deposit)\n");
	rc = MB_SyncComplete(b_household_bank_update_deposit);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_household_bank_update_deposit)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'household_bank_update_deposit' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'household_bank_update_deposit' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_household_bank_update_deposit);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'household_bank_update_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_bank_update_deposit' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_bank_update_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif



	/*printf("firm_FirmHousingPrice_state->count = %d\n", firm_FirmHousingPrice_state->count);*/
	firm_FirmHousingPrice_state->count = 0;

	/*printf("firm_FirmHousingSell_state->count = %d\n", firm_FirmHousingSell_state->count);*/
	firm_FirmHousingSell_state->count = 0;

	/*printf("firm_FirmHousingMarket_state->count = %d\n", firm_FirmHousingMarket_state->count);*/
	firm_FirmHousingMarket_state->count = 0;

	/*printf("firm_FirmCreditInsolvencyCheck_state->count = %d\n", firm_FirmCreditInsolvencyCheck_state->count);*/
	firm_FirmCreditInsolvencyCheck_state->count = 0;

	/*printf("firm_FirmCreditDividendPayments_state->count = %d\n", firm_FirmCreditDividendPayments_state->count);*/
	firm_FirmCreditDividendPayments_state->count = 0;

	/*printf("firm_FirmCreditBalanceSheet_state->count = %d\n", firm_FirmCreditBalanceSheet_state->count);*/
	firm_FirmCreditBalanceSheet_state->count = 0;

	/*printf("firm_FirmCreditBankruptcy_state->count = %d\n", firm_FirmCreditBankruptcy_state->count);*/
	firm_FirmCreditBankruptcy_state->count = 0;

	/*printf("firm_FirmCreditLiquidityRecheck_state->count = %d\n", firm_FirmCreditLiquidityRecheck_state->count);*/
	firm_FirmCreditLiquidityRecheck_state->count = 0;

	/*printf("firm_FirmCreditIlliquidityStatus_state->count = %d\n", firm_FirmCreditIlliquidityStatus_state->count);*/
	firm_FirmCreditIlliquidityStatus_state->count = 0;

	/*printf("firm_FirmCreditLoanBorrow2_state->count = %d\n", firm_FirmCreditLoanBorrow2_state->count);*/
	firm_FirmCreditLoanBorrow2_state->count = 0;

	/*printf("firm_FirmCreditLoanBorrow1_state->count = %d\n", firm_FirmCreditLoanBorrow1_state->count);*/
	firm_FirmCreditLoanBorrow1_state->count = 0;

	/*printf("firm_FirmCreditPayments_state->count = %d\n", firm_FirmCreditPayments_state->count);*/
	firm_FirmCreditPayments_state->count = 0;

	/*printf("firm_FirmCreditStatus_state->count = %d\n", firm_FirmCreditStatus_state->count);*/
	firm_FirmCreditStatus_state->count = 0;

	/*printf("firm_FirmCreditLiquidityNeed_state->count = %d\n", firm_FirmCreditLiquidityNeed_state->count);*/
	firm_FirmCreditLiquidityNeed_state->count = 0;

	/*printf("firm_FirmCreditComputeDividends_state->count = %d\n", firm_FirmCreditComputeDividends_state->count);*/
	firm_FirmCreditComputeDividends_state->count = 0;

	/*printf("firm_FirmCreditInvestment_state->count = %d\n", firm_FirmCreditInvestment_state->count);*/
	firm_FirmCreditInvestment_state->count = 0;

	/*printf("firm_FirmCreditTaxRate_state->count = %d\n", firm_FirmCreditTaxRate_state->count);*/
	firm_FirmCreditTaxRate_state->count = 0;

	/*printf("firm_FirmCreditInterestRate_state->count = %d\n", firm_FirmCreditInterestRate_state->count);*/
	firm_FirmCreditInterestRate_state->count = 0;

	/*printf("firm_FirmConstructionLabourDemand_state->count = %d\n", firm_FirmConstructionLabourDemand_state->count);*/
	firm_FirmConstructionLabourDemand_state->count = 0;

	/*printf("firm_FirmProductionLabourDemand_state->count = %d\n", firm_FirmProductionLabourDemand_state->count);*/
	firm_FirmProductionLabourDemand_state->count = 0;

	/*printf("firm_FirmProductionPlanning_state->count = %d\n", firm_FirmProductionPlanning_state->count);*/
	firm_FirmProductionPlanning_state->count = 0;

	/*printf("firm_FirmProductionConstructor_state->count = %d\n", firm_FirmProductionConstructor_state->count);*/
	firm_FirmProductionConstructor_state->count = 0;

	/*printf("firm_FirmProductionRegular_state->count = %d\n", firm_FirmProductionRegular_state->count);*/
	firm_FirmProductionRegular_state->count = 0;

	/*printf("firm_FirmProductionRoleCheck_state->count = %d\n", firm_FirmProductionRoleCheck_state->count);*/
	firm_FirmProductionRoleCheck_state->count = 0;

	/*printf("firm_FirmProductionSkip_state->count = %d\n", firm_FirmProductionSkip_state->count);*/
	firm_FirmProductionSkip_state->count = 0;

	/*printf("firm_FirmProductionStart_state->count = %d\n", firm_FirmProductionStart_state->count);*/
	firm_FirmProductionStart_state->count = 0;

	/*printf("firm_FirmLabourWageAdjustment_state->count = %d\n", firm_FirmLabourWageAdjustment_state->count);*/
	firm_FirmLabourWageAdjustment_state->count = 0;

	/*printf("firm_FirmLabourStage2End_state->count = %d\n", firm_FirmLabourStage2End_state->count);*/
	firm_FirmLabourStage2End_state->count = 0;

	/*printf("firm_FirmLabourStage2_state->count = %d\n", firm_FirmLabourStage2_state->count);*/
	firm_FirmLabourStage2_state->count = 0;

	/*printf("firm_FirmLabourStage1Application_state->count = %d\n", firm_FirmLabourStage1Application_state->count);*/
	firm_FirmLabourStage1Application_state->count = 0;

	/*printf("firm_FirmLabourStage1End_state->count = %d\n", firm_FirmLabourStage1End_state->count);*/
	firm_FirmLabourStage1End_state->count = 0;

	/*printf("firm_FirmLabourStage1_state->count = %d\n", firm_FirmLabourStage1_state->count);*/
	firm_FirmLabourStage1_state->count = 0;

	/*printf("firm_FirmLabourPayWages_state->count = %d\n", firm_FirmLabourPayWages_state->count);*/
	firm_FirmLabourPayWages_state->count = 0;

	/*printf("firm_FirmLabourStart_state->count = %d\n", firm_FirmLabourStart_state->count);*/
	firm_FirmLabourStart_state->count = 0;

	/*printf("firm_FirmConsumptionPrice_state->count = %d\n", firm_FirmConsumptionPrice_state->count);*/
	firm_FirmConsumptionPrice_state->count = 0;

	/*printf("firm_FirmRecieveSales_state->count = %d\n", firm_FirmRecieveSales_state->count);*/
	firm_FirmRecieveSales_state->count = 0;

	/*printf("firm_FirmHousingStart_state->count = %d\n", firm_FirmHousingStart_state->count);*/
	firm_FirmHousingStart_state->count = 0;

	/*printf("firm_FirmConsumptionStart_state->count = %d\n", firm_FirmConsumptionStart_state->count);*/
	firm_FirmConsumptionStart_state->count = 0;

	/*printf("firm_end_state->count = %d\n", firm_end_state->count);*/
	firm_end_state->count = 0;

	/*printf("firm_FirmUpdateDeposits_state->count = %d\n", firm_FirmUpdateDeposits_state->count);*/
	firm_FirmUpdateDeposits_state->count = 0;

	/*printf("firm_FirmCreditStart_state->count = %d\n", firm_FirmCreditStart_state->count);*/
	firm_FirmCreditStart_state->count = 0;

	/*printf("firm_start_state->count = %d\n", firm_start_state->count);*/
	firm_start_state->count = 0;

	/*printf("household_HHHousingWriteOff_state->count = %d\n", household_HHHousingWriteOff_state->count);*/
	household_HHHousingWriteOff_state->count = 0;

	/*printf("household_HHHousingPayments_state->count = %d\n", household_HHHousingPayments_state->count);*/
	household_HHHousingPayments_state->count = 0;

	/*printf("household_HHHousingBargain_state->count = %d\n", household_HHHousingBargain_state->count);*/
	household_HHHousingBargain_state->count = 0;

	/*printf("household_HHHousingRevenue_state->count = %d\n", household_HHHousingRevenue_state->count);*/
	household_HHHousingRevenue_state->count = 0;

	/*printf("household_HHHousingCheckWealth_state->count = %d\n", household_HHHousingCheckWealth_state->count);*/
	household_HHHousingCheckWealth_state->count = 0;

	/*printf("household_HHHousingPrice_state->count = %d\n", household_HHHousingPrice_state->count);*/
	household_HHHousingPrice_state->count = 0;

	/*printf("household_HHHousingRole_state->count = %d\n", household_HHHousingRole_state->count);*/
	household_HHHousingRole_state->count = 0;

	/*printf("household_HHCreditEmployment_state->count = %d\n", household_HHCreditEmployment_state->count);*/
	household_HHCreditEmployment_state->count = 0;

	/*printf("household_HHCreditBalanceSheet_state->count = %d\n", household_HHCreditBalanceSheet_state->count);*/
	household_HHCreditBalanceSheet_state->count = 0;

	/*printf("household_HHCreditIsCapitalist_state->count = %d\n", household_HHCreditIsCapitalist_state->count);*/
	household_HHCreditIsCapitalist_state->count = 0;

	/*printf("household_HHCreditUpdateMortgages_state->count = %d\n", household_HHCreditUpdateMortgages_state->count);*/
	household_HHCreditUpdateMortgages_state->count = 0;

	/*printf("household_HHCreditCheckTax_state->count = %d\n", household_HHCreditCheckTax_state->count);*/
	household_HHCreditCheckTax_state->count = 0;

	/*printf("household_HHCreditMonthly_state->count = %d\n", household_HHCreditMonthly_state->count);*/
	household_HHCreditMonthly_state->count = 0;

	/*printf("household_HHLabourPayroll_state->count = %d\n", household_HHLabourPayroll_state->count);*/
	household_HHLabourPayroll_state->count = 0;

	/*printf("household_HHLabourStage1Placement_state->count = %d\n", household_HHLabourStage1Placement_state->count);*/
	household_HHLabourStage1Placement_state->count = 0;

	/*printf("household_HHLabourStage1Applications_state->count = %d\n", household_HHLabourStage1Applications_state->count);*/
	household_HHLabourStage1Applications_state->count = 0;

	/*printf("household_HHLabourStage2_state->count = %d\n", household_HHLabourStage2_state->count);*/
	household_HHLabourStage2_state->count = 0;

	/*printf("household_HHLabourStage1_state->count = %d\n", household_HHLabourStage1_state->count);*/
	household_HHLabourStage1_state->count = 0;

	/*printf("household_HHLabourEmploymentStatus_state->count = %d\n", household_HHLabourEmploymentStatus_state->count);*/
	household_HHLabourEmploymentStatus_state->count = 0;

	/*printf("household_HHLabourStart_state->count = %d\n", household_HHLabourStart_state->count);*/
	household_HHLabourStart_state->count = 0;

	/*printf("household_HHConsumptionRecieveGoods_state->count = %d\n", household_HHConsumptionRecieveGoods_state->count);*/
	household_HHConsumptionRecieveGoods_state->count = 0;

	/*printf("household_HHHousingStart_state->count = %d\n", household_HHHousingStart_state->count);*/
	household_HHHousingStart_state->count = 0;

	/*printf("household_HHConsumptionWeekly_state->count = %d\n", household_HHConsumptionWeekly_state->count);*/
	household_HHConsumptionWeekly_state->count = 0;

	/*printf("household_HHConsumptionStart_state->count = %d\n", household_HHConsumptionStart_state->count);*/
	household_HHConsumptionStart_state->count = 0;

	/*printf("household_end_state->count = %d\n", household_end_state->count);*/
	household_end_state->count = 0;

	/*printf("household_HouseholdUpdateDeposits_state->count = %d\n", household_HouseholdUpdateDeposits_state->count);*/
	household_HouseholdUpdateDeposits_state->count = 0;

	/*printf("household_HHCreditStart_state->count = %d\n", household_HHCreditStart_state->count);*/
	household_HHCreditStart_state->count = 0;

	/*printf("household_start_state->count = %d\n", household_start_state->count);*/
	household_start_state->count = 0;

	/*printf("equityfund_EFCreditBalanceSheet_state->count = %d\n", equityfund_EFCreditBalanceSheet_state->count);*/
	equityfund_EFCreditBalanceSheet_state->count = 0;

	/*printf("equityfund_EFCreditShareCollectionFirms_state->count = %d\n", equityfund_EFCreditShareCollectionFirms_state->count);*/
	equityfund_EFCreditShareCollectionFirms_state->count = 0;

	/*printf("equityfund_EFCreditShareCollectionBanks_state->count = %d\n", equityfund_EFCreditShareCollectionBanks_state->count);*/
	equityfund_EFCreditShareCollectionBanks_state->count = 0;

	/*printf("equityfund_EFCreditDistributeShares_state->count = %d\n", equityfund_EFCreditDistributeShares_state->count);*/
	equityfund_EFCreditDistributeShares_state->count = 0;

	/*printf("equityfund_EFIlliquidInvestment_state->count = %d\n", equityfund_EFIlliquidInvestment_state->count);*/
	equityfund_EFIlliquidInvestment_state->count = 0;

	/*printf("equityfund_end_state->count = %d\n", equityfund_end_state->count);*/
	equityfund_end_state->count = 0;

	/*printf("equityfund_EFLabourMarket_state->count = %d\n", equityfund_EFLabourMarket_state->count);*/
	equityfund_EFLabourMarket_state->count = 0;

	/*printf("equityfund_EquityFundStart_state->count = %d\n", equityfund_EquityFundStart_state->count);*/
	equityfund_EquityFundStart_state->count = 0;

	/*printf("equityfund_start_state->count = %d\n", equityfund_start_state->count);*/
	equityfund_start_state->count = 0;

	/*printf("bank_BankHousingWriteOff_state->count = %d\n", bank_BankHousingWriteOff_state->count);*/
	bank_BankHousingWriteOff_state->count = 0;

	/*printf("bank_BankHousingMortgages_state->count = %d\n", bank_BankHousingMortgages_state->count);*/
	bank_BankHousingMortgages_state->count = 0;

	/*printf("bank_BankHousingSales_state->count = %d\n", bank_BankHousingSales_state->count);*/
	bank_BankHousingSales_state->count = 0;

	/*printf("bank_BankHousingCrediting_state->count = %d\n", bank_BankHousingCrediting_state->count);*/
	bank_BankHousingCrediting_state->count = 0;

	/*printf("bank_BankCreditLoanInterests_state->count = %d\n", bank_BankCreditLoanInterests_state->count);*/
	bank_BankCreditLoanInterests_state->count = 0;

	/*printf("bank_BankCreditNewEntrants_state->count = %d\n", bank_BankCreditNewEntrants_state->count);*/
	bank_BankCreditNewEntrants_state->count = 0;

	/*printf("bank_BankCreditLoanWriteOffs_state->count = %d\n", bank_BankCreditLoanWriteOffs_state->count);*/
	bank_BankCreditLoanWriteOffs_state->count = 0;

	/*printf("bank_BankCreditRequest2_state->count = %d\n", bank_BankCreditRequest2_state->count);*/
	bank_BankCreditRequest2_state->count = 0;

	/*printf("bank_BankCreditRequest1_state->count = %d\n", bank_BankCreditRequest1_state->count);*/
	bank_BankCreditRequest1_state->count = 0;

	/*printf("bank_BankCreditBalanceSheet_state->count = %d\n", bank_BankCreditBalanceSheet_state->count);*/
	bank_BankCreditBalanceSheet_state->count = 0;

	/*printf("bank_BankCreditDividends_state->count = %d\n", bank_BankCreditDividends_state->count);*/
	bank_BankCreditDividends_state->count = 0;

	/*printf("bank_BankCreditIncomeStatement_state->count = %d\n", bank_BankCreditIncomeStatement_state->count);*/
	bank_BankCreditIncomeStatement_state->count = 0;

	/*printf("bank_BankHousingMarket_state->count = %d\n", bank_BankHousingMarket_state->count);*/
	bank_BankHousingMarket_state->count = 0;

	/*printf("bank_end_state->count = %d\n", bank_end_state->count);*/
	bank_end_state->count = 0;

	/*printf("bank_BankUpdateDeposits_state->count = %d\n", bank_BankUpdateDeposits_state->count);*/
	bank_BankUpdateDeposits_state->count = 0;

	/*printf("bank_BankCreditStart_state->count = %d\n", bank_BankCreditStart_state->count);*/
	bank_BankCreditStart_state->count = 0;

	/*printf("bank_start_state->count = %d\n", bank_start_state->count);*/
	bank_start_state->count = 0;

	/*printf("government_GovernmentLabourTax_state->count = %d\n", government_GovernmentLabourTax_state->count);*/
	government_GovernmentLabourTax_state->count = 0;

	/*printf("government_GovernmentUnemploymentBenefits_state->count = %d\n", government_GovernmentUnemploymentBenefits_state->count);*/
	government_GovernmentUnemploymentBenefits_state->count = 0;

	/*printf("government_GovernmentCentralbankProfits_state->count = %d\n", government_GovernmentCentralbankProfits_state->count);*/
	government_GovernmentCentralbankProfits_state->count = 0;

	/*printf("government_GovernmentCapitalTax_state->count = %d\n", government_GovernmentCapitalTax_state->count);*/
	government_GovernmentCapitalTax_state->count = 0;

	/*printf("government_GovernmentFiscalPolicy_state->count = %d\n", government_GovernmentFiscalPolicy_state->count);*/
	government_GovernmentFiscalPolicy_state->count = 0;

	/*printf("government_GovernmentBalanceSheet_state->count = %d\n", government_GovernmentBalanceSheet_state->count);*/
	government_GovernmentBalanceSheet_state->count = 0;

	/*printf("government_GovernmentMonthly_state->count = %d\n", government_GovernmentMonthly_state->count);*/
	government_GovernmentMonthly_state->count = 0;

	/*printf("government_end_state->count = %d\n", government_end_state->count);*/
	government_end_state->count = 0;

	/*printf("government_GovernmentLabourStatus_state->count = %d\n", government_GovernmentLabourStatus_state->count);*/
	government_GovernmentLabourStatus_state->count = 0;

	/*printf("government_GovernmentStart_state->count = %d\n", government_GovernmentStart_state->count);*/
	government_GovernmentStart_state->count = 0;

	/*printf("government_start_state->count = %d\n", government_start_state->count);*/
	government_start_state->count = 0;

	/*printf("centralbank_end_state->count = %d\n", centralbank_end_state->count);*/
	centralbank_end_state->count = 0;

	/*printf("centralbank_CentralBankBalanceSheet_state->count = %d\n", centralbank_CentralBankBalanceSheet_state->count);*/
	centralbank_CentralBankBalanceSheet_state->count = 0;

	/*printf("centralbank_CentralBankIncomeStatement_state->count = %d\n", centralbank_CentralBankIncomeStatement_state->count);*/
	centralbank_CentralBankIncomeStatement_state->count = 0;

	/*printf("centralbank_CentralBankDebtRequests_state->count = %d\n", centralbank_CentralBankDebtRequests_state->count);*/
	centralbank_CentralBankDebtRequests_state->count = 0;

	/*printf("centralbank_CentralBankInterestPayments_state->count = %d\n", centralbank_CentralBankInterestPayments_state->count);*/
	centralbank_CentralBankInterestPayments_state->count = 0;

	/*printf("centralbank_CentralBankLabour_state->count = %d\n", centralbank_CentralBankLabour_state->count);*/
	centralbank_CentralBankLabour_state->count = 0;

	/*printf("centralbank_CentralBankHousing_state->count = %d\n", centralbank_CentralBankHousing_state->count);*/
	centralbank_CentralBankHousing_state->count = 0;

	/*printf("centralbank_CentralBankConsumption_state->count = %d\n", centralbank_CentralBankConsumption_state->count);*/
	centralbank_CentralBankConsumption_state->count = 0;

	/*printf("centralbank_CentralBankCredit_state->count = %d\n", centralbank_CentralBankCredit_state->count);*/
	centralbank_CentralBankCredit_state->count = 0;

	/*printf("centralbank_start_state->count = %d\n", centralbank_start_state->count);*/
	centralbank_start_state->count = 0;

	/*printf("jpoffice_JPOLabourStage2_state->count = %d\n", jpoffice_JPOLabourStage2_state->count);*/
	jpoffice_JPOLabourStage2_state->count = 0;

	/*printf("jpoffice_end_state->count = %d\n", jpoffice_end_state->count);*/
	jpoffice_end_state->count = 0;

	/*printf("jpoffice_JPOLabourMarket_state->count = %d\n", jpoffice_JPOLabourMarket_state->count);*/
	jpoffice_JPOLabourMarket_state->count = 0;

	/*printf("jpoffice_start_state->count = %d\n", jpoffice_start_state->count);*/
	jpoffice_start_state->count = 0;

	/*printf("mall_MallConsumptionSummary_state->count = %d\n", mall_MallConsumptionSummary_state->count);*/
	mall_MallConsumptionSummary_state->count = 0;

	/*printf("mall_end_state->count = %d\n", mall_end_state->count);*/
	mall_end_state->count = 0;

	/*printf("mall_MallConsumptionMarket_state->count = %d\n", mall_MallConsumptionMarket_state->count);*/
	mall_MallConsumptionMarket_state->count = 0;

	/*printf("mall_start_state->count = %d\n", mall_start_state->count);*/
	mall_start_state->count = 0;

	/*printf("reagency_REAgencyHousingSummary_state->count = %d\n", reagency_REAgencyHousingSummary_state->count);*/
	reagency_REAgencyHousingSummary_state->count = 0;

	/*printf("reagency_REAgencyHousingProcess_state->count = %d\n", reagency_REAgencyHousingProcess_state->count);*/
	reagency_REAgencyHousingProcess_state->count = 0;

	/*printf("reagency_end_state->count = %d\n", reagency_end_state->count);*/
	reagency_end_state->count = 0;

	/*printf("reagency_REAgencyHousingMarket_state->count = %d\n", reagency_REAgencyHousingMarket_state->count);*/
	reagency_REAgencyHousingMarket_state->count = 0;

	/*printf("reagency_start_state->count = %d\n", reagency_start_state->count);*/
	reagency_start_state->count = 0;

	/* Move agents to their start states */

	current_xmachine_firm_holder = firm_end_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		transition_firm_agent(current_xmachine_firm_holder, firm_end_state, firm_start_state);

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}

	current_xmachine_household_holder = household_end_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		transition_household_agent(current_xmachine_household_holder, household_end_state, household_start_state);

		current_xmachine_household_holder = temp_xmachine_household_holder;
	}

	current_xmachine_equityfund_holder = equityfund_end_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		transition_equityfund_agent(current_xmachine_equityfund_holder, equityfund_end_state, equityfund_start_state);

		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}

	current_xmachine_bank_holder = bank_end_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		transition_bank_agent(current_xmachine_bank_holder, bank_end_state, bank_start_state);

		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}

	current_xmachine_government_holder = government_end_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		transition_government_agent(current_xmachine_government_holder, government_end_state, government_start_state);

		current_xmachine_government_holder = temp_xmachine_government_holder;
	}

	current_xmachine_centralbank_holder = centralbank_end_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		transition_centralbank_agent(current_xmachine_centralbank_holder, centralbank_end_state, centralbank_start_state);

		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}

	current_xmachine_jpoffice_holder = jpoffice_end_state->agents;
	while(current_xmachine_jpoffice_holder)
	{
		temp_xmachine_jpoffice_holder = current_xmachine_jpoffice_holder->next;
		transition_jpoffice_agent(current_xmachine_jpoffice_holder, jpoffice_end_state, jpoffice_start_state);

		current_xmachine_jpoffice_holder = temp_xmachine_jpoffice_holder;
	}

	current_xmachine_mall_holder = mall_end_state->agents;
	while(current_xmachine_mall_holder)
	{
		temp_xmachine_mall_holder = current_xmachine_mall_holder->next;
		transition_mall_agent(current_xmachine_mall_holder, mall_end_state, mall_start_state);

		current_xmachine_mall_holder = temp_xmachine_mall_holder;
	}

	current_xmachine_reagency_holder = reagency_end_state->agents;
	while(current_xmachine_reagency_holder)
	{
		temp_xmachine_reagency_holder = current_xmachine_reagency_holder->next;
		transition_reagency_agent(current_xmachine_reagency_holder, reagency_end_state, reagency_start_state);

		current_xmachine_reagency_holder = temp_xmachine_reagency_holder;
	}

    if(iteration_loop%output_frequency == output_offset)
    {
        saveiterationdata(iteration_loop);
    }

		/* Calculate if any agents need to jump S.P. */
		/* propagate_agents(); */
	/* Save iteration time to log file */

		if((file = fopen(logfilepath, "a"))==NULL)
		{
			printf("Error: cannot open file '%s' for writing\n", logfilepath);
			exit(0);
		}
		(void)fputs("<iteration><no>", file);
		sprintf(data, "%i", iteration_loop);
		(void)fputs(data, file);
		(void)fputs("</no><time>", file);
		sprintf(data, "%d", (int)((get_time() - interval) * 1000) );
		(void)fputs(data, file);
		(void)fputs("</time></iteration>\n", file);
		(void)fclose(file);

	}

    

	/* Stop timing and print total time */
	stop = get_time();
	total_time = stop - start;
	printf("Execution time - %d:%02d:%03d [mins:secs:msecs]\n",
       (int)(total_time/60), ((int)total_time)%60, (((int)(total_time * 1000.0)) % 1000));

	clean_up(0);

	/* Exit successfully by returning zero to Operating System */
	return 0;
}
