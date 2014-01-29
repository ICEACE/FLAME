/**
 * \file rules.c
 * \brief Functions created from tagged condition and filter rules.
 */

#include "header.h"

/** \fn int FLAME_integer_in_array(int a, int * b, int size)
 * \brief Returns 1 if an integer is a member of an integer array, else 0
 * \param a The integer to check.
 * \param b Pointer to the integer array.
 * \param size The size of the array
 * \return 1 for true, 0 for false.
 */
int FLAME_integer_in_array(int a, int * b, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		if(a == b[i]) return 1;
	}
	
	return 0;
}

/** \fn void* cparams_create(int agent_number, int * agent_count, size_t * agent_struct_size, size_t * cparam_size)
 * \brief Create memory to hold agent filter variables for every agent using the filter on the current node.
 * \param agent_number The number of agent types.
 * \param agent_count List of the number of agents of each agent type.
 * \param agent_struct_size The struct size needed for each agent type.
 * \param cparam_size The size of the memory created.
 * \return Pointer to the created memory.
 */
void* cparams_create(int agent_number, int * agent_count, size_t * agent_struct_size, size_t * cparam_size)
{
	/* Pointer to the memory created that is going to be returned */
	void *data;
	/* Variable used in for loops */
	int i;
	/* Variable to hold total size of memory required for agent structures */
	size_t total_param_size = 0;

	/* For each agent type add required memory for agent structures */
	for(i = 0; i < agent_number; i++)
	{
		total_param_size += agent_count[i] * agent_struct_size[i];
	}

	//assert(count > 0);
	//assert(total_param_size > 0);
	/* Does libmboard free this memory? */
	
	/* Allocate required memory, where memory holds the number
	 * of each agent type, in order, and the total required
	 * memory for agent structures */
	data = malloc(agent_number*sizeof(int) + total_param_size);
	/* Make the memory size parameter equal to the actual memory size */
	*cparam_size = agent_number*sizeof(int) + total_param_size;
	/* Assert that the created memory was successfully created and not null */
	assert(data != NULL);

	/* Return the pointer to the created memory */
	return data;
}


/** \fn int FLAME_condition_firm_idle_start_FirmInitPostId(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_start_FirmInitPostId(xmachine_memory_firm *a)
{
	if((a->it_no == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_start_FirmLoop(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_start_FirmLoop(xmachine_memory_firm *a)
{
	if((a->it_no != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmUpdateDeposits_FirmCreditPolicyChecks(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmUpdateDeposits_FirmCreditPolicyChecks(xmachine_memory_firm *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_update_bank_account_FirmUpdateDeposits_FirmCreditPolicyChecks(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_update_bank_account_FirmUpdateDeposits_FirmCreditPolicyChecks(xmachine_memory_firm *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmConsumptionStart_FirmExportStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmConsumptionStart_FirmExportStart(xmachine_memory_firm *a)
{
	if((a->firmtype != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmConsumptionStart_FirmConsumptionMarket(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmConsumptionStart_FirmConsumptionMarket(xmachine_memory_firm *a)
{
	if((a->firmtype == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmConsumptionMarket_FirmExportStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmConsumptionMarket_FirmExportStart(xmachine_memory_firm *a)
{
	if(!(iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_consumption_supply_FirmConsumptionMarket_FirmReceiveSales(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_consumption_supply_FirmConsumptionMarket_FirmReceiveSales(xmachine_memory_firm *a)
{
	if((iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmLabourStart_FirmConsumptionStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmLabourStart_FirmConsumptionStart(xmachine_memory_firm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_labour_workforce_needed_FirmLabourStart_FirmLabourStage1(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_labour_workforce_needed_FirmLabourStart_FirmLabourStage1(xmachine_memory_firm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmLabourStage1_FirmLabourStage1End(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmLabourStage1_FirmLabourStage1End(xmachine_memory_firm *a)
{
	if((a->vacancies == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_labour_fire_FirmLabourStage1_FirmLabourStage1End(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_labour_fire_FirmLabourStage1_FirmLabourStage1End(xmachine_memory_firm *a)
{
	if((a->vacancies < 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_labour_job_announcement_stage1_FirmLabourStage1_FirmLabourStage1Application(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_labour_job_announcement_stage1_FirmLabourStage1_FirmLabourStage1Application(xmachine_memory_firm *a)
{
	if((a->vacancies > 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_labour_job_announcement_stage2_FirmLabourStage2_FirmLabourStage2End(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_labour_job_announcement_stage2_FirmLabourStage2_FirmLabourStage2End(xmachine_memory_firm *a)
{
	if((a->vacancies >= 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmLabourStage2_FirmConsumptionStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmLabourStage2_FirmConsumptionStart(xmachine_memory_firm *a)
{
	if((a->vacancies < 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmLabourPayWages_FirmUpdateDeposits(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmLabourPayWages_FirmUpdateDeposits(xmachine_memory_firm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_wages_paid)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_labour_pay_wages_FirmLabourPayWages_FirmLabourWageAdjustment(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_labour_pay_wages_FirmLabourPayWages_FirmLabourWageAdjustment(xmachine_memory_firm *a)
{
	if((iteration_loop%20 == a->day_of_month_wages_paid)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmProductionStart_FirmLabourStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmProductionStart_FirmLabourStart(xmachine_memory_firm *a)
{
	if(!((iteration_loop%20 == a->day_of_month_to_act) || (iteration_loop%20 == a->day_of_month_production_completed))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmProductionStart_FirmProductionSkip(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmProductionStart_FirmProductionSkip(xmachine_memory_firm *a)
{
	if(((iteration_loop%20 == a->day_of_month_to_act) || (iteration_loop%20 == a->day_of_month_production_completed))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_production_skip_FirmProductionSkip_FirmLabourStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_production_skip_FirmProductionSkip_FirmLabourStart(xmachine_memory_firm *a)
{
	if((a->isinsolvent == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmProductionSkip_FirmProductionRoleCheck(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmProductionSkip_FirmProductionRoleCheck(xmachine_memory_firm *a)
{
	if((a->isinsolvent != 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmProductionRoleCheck_FirmProductionRegular(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmProductionRoleCheck_FirmProductionRegular(xmachine_memory_firm *a)
{
	if((a->firmtype == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmProductionRoleCheck_FirmProductionConstructor(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmProductionRoleCheck_FirmProductionConstructor(xmachine_memory_firm *a)
{
	if((a->firmtype == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmProductionRoleCheck_FirmProductionExport(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmProductionRoleCheck_FirmProductionExport(xmachine_memory_firm *a)
{
	if((a->firmtype == 2)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_production_produce_goods_FirmProductionRegular_FirmLabourStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_production_produce_goods_FirmProductionRegular_FirmLabourStart(xmachine_memory_firm *a)
{
	if((iteration_loop%20 == a->day_of_month_production_completed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_production_set_price_FirmProductionRegular_FirmProductionPlanning(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_production_set_price_FirmProductionRegular_FirmProductionPlanning(xmachine_memory_firm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_production_construct_houses_FirmProductionConstructor_FirmLabourStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_production_construct_houses_FirmProductionConstructor_FirmLabourStart(xmachine_memory_firm *a)
{
	if((iteration_loop%20 == a->day_of_month_production_completed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_production_construction_plan_FirmProductionConstructor_FirmConstructionLabourDemand(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_production_construction_plan_FirmProductionConstructor_FirmConstructionLabourDemand(xmachine_memory_firm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_production_produce_export_goods_FirmProductionExport_FirmLabourStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_production_produce_export_goods_FirmProductionExport_FirmLabourStart(xmachine_memory_firm *a)
{
	if((iteration_loop%20 == a->day_of_month_production_completed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_production_export_plan_FirmProductionExport_FirmExportLabourDemand(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_production_export_plan_FirmProductionExport_FirmExportLabourDemand(xmachine_memory_firm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmCreditStart_FirmProductionStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmCreditStart_FirmProductionStart(xmachine_memory_firm *a)
{
	if(!(iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_credit_compute_income_statement_FirmCreditStart_FirmCreditInvestment(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_credit_compute_income_statement_FirmCreditStart_FirmCreditInvestment(xmachine_memory_firm *a)
{
	if((iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmCreditStatus_FirmCreditPayments(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmCreditStatus_FirmCreditPayments(xmachine_memory_firm *a)
{
	if((a->isliquidshort == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_credit_demand_loans_1_FirmCreditStatus_FirmCreditLoanBorrow1(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_credit_demand_loans_1_FirmCreditStatus_FirmCreditLoanBorrow1(xmachine_memory_firm *a)
{
	if((a->isliquidshort != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmCreditLoanBorrow2_FirmCreditPayments(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmCreditLoanBorrow2_FirmCreditPayments(xmachine_memory_firm *a)
{
	if((a->hasloan == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_credit_borrow_loans_2_FirmCreditLoanBorrow2_FirmCreditIlliquidityStatus(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_credit_borrow_loans_2_FirmCreditLoanBorrow2_FirmCreditIlliquidityStatus(xmachine_memory_firm *a)
{
	if((a->hasloan != 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmCreditIlliquidityStatus_FirmCreditPayments(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmCreditIlliquidityStatus_FirmCreditPayments(xmachine_memory_firm *a)
{
	if((a->hasloan == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_credit_request_equityfund_investment_FirmCreditIlliquidityStatus_FirmCreditLiquidityRecheck(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_credit_request_equityfund_investment_FirmCreditIlliquidityStatus_FirmCreditLiquidityRecheck(xmachine_memory_firm *a)
{
	if((a->hasloan != 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmCreditLiquidityRecheck_FirmCreditPayments(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmCreditLiquidityRecheck_FirmCreditPayments(xmachine_memory_firm *a)
{
	if((a->liquidity_need == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_credit_check_equityfund_investment_FirmCreditLiquidityRecheck_FirmCreditBankruptcy(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_credit_check_equityfund_investment_FirmCreditLiquidityRecheck_FirmCreditBankruptcy(xmachine_memory_firm *a)
{
	if((a->liquidity_need != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmCreditBankruptcy_FirmCreditPayments(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmCreditBankruptcy_FirmCreditPayments(xmachine_memory_firm *a)
{
	if((a->hasinvestment == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_credit_illiquidity_bankrupt_FirmCreditBankruptcy_FirmCreditBalanceSheet(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_credit_illiquidity_bankrupt_FirmCreditBankruptcy_FirmCreditBalanceSheet(xmachine_memory_firm *a)
{
	if((a->hasinvestment != 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmCreditInsolvencyCheck_FirmProductionStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmCreditInsolvencyCheck_FirmProductionStart(xmachine_memory_firm *a)
{
	if((a->isinsolvent != 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_credit_insolvency_bankruptcy_FirmCreditInsolvencyCheck_FirmProductionStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_credit_insolvency_bankruptcy_FirmCreditInsolvencyCheck_FirmProductionStart(xmachine_memory_firm *a)
{
	if((a->isinsolvent == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmCreditPolicyChecks_end(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmCreditPolicyChecks_end(xmachine_memory_firm *a)
{
	if(!(iteration_loop%60 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_credit_check_interest_rate_FirmCreditPolicyChecks_FirmCreditCheckTaxRate(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_credit_check_interest_rate_FirmCreditPolicyChecks_FirmCreditCheckTaxRate(xmachine_memory_firm *a)
{
	if((iteration_loop%60 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmHousingStart_FirmLabourPayWages(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmHousingStart_FirmLabourPayWages(xmachine_memory_firm *a)
{
	if((a->firmtype != 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmHousingStart_FirmHousingMarket(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmHousingStart_FirmHousingMarket(xmachine_memory_firm *a)
{
	if((a->firmtype == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmHousingMarket_FirmLabourPayWages(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmHousingMarket_FirmLabourPayWages(xmachine_memory_firm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_housing_enter_market_FirmHousingMarket_FirmHousingSell(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_housing_enter_market_FirmHousingMarket_FirmHousingSell(xmachine_memory_firm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmExportStart_FirmHousingStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmExportStart_FirmHousingStart(xmachine_memory_firm *a)
{
	if((a->firmtype != 2)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmExportStart_FirmExportMarket(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmExportStart_FirmExportMarket(xmachine_memory_firm *a)
{
	if((a->firmtype == 2)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmExportMarket_FirmHousingStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmExportMarket_FirmHousingStart(xmachine_memory_firm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_export_sell_FirmExportMarket_FirmExportReceiveSales(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_export_sell_FirmExportMarket_FirmExportReceiveSales(xmachine_memory_firm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_start_HouseholdInitPostId(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_start_HouseholdInitPostId(xmachine_memory_household *a)
{
	if((a->it_no == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_start_HouseholdLoop(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_start_HouseholdLoop(xmachine_memory_household *a)
{
	if((a->it_no != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HouseholdUpdateDeposits_HHCreditPolicyChecks(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HouseholdUpdateDeposits_HHCreditPolicyChecks(xmachine_memory_household *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_update_bank_account_HouseholdUpdateDeposits_HHCreditPolicyChecks(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_update_bank_account_HouseholdUpdateDeposits_HHCreditPolicyChecks(xmachine_memory_household *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HHConsumptionStart_HHConsumptionWeekly(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHConsumptionStart_HHConsumptionWeekly(xmachine_memory_household *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_consumption_compute_budget_HHConsumptionStart_HHConsumptionWeekly(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_consumption_compute_budget_HHConsumptionStart_HHConsumptionWeekly(xmachine_memory_household *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HHConsumptionWeekly_HHHousingStart(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHConsumptionWeekly_HHHousingStart(xmachine_memory_household *a)
{
	if(!(iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_consumption_demand_HHConsumptionWeekly_HHConsumptionRecieveGoods(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_consumption_demand_HHConsumptionWeekly_HHConsumptionRecieveGoods(xmachine_memory_household *a)
{
	if((iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HHLabourStart_HHConsumptionStart(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHLabourStart_HHConsumptionStart(xmachine_memory_household *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_labour_check_fired_HHLabourStart_HHLabourStage1(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_labour_check_fired_HHLabourStart_HHLabourStage1(xmachine_memory_household *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_labour_reemployment_application_HHLabourStage1_HHLabourStage2(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_labour_reemployment_application_HHLabourStage1_HHLabourStage2(xmachine_memory_household *a)
{
	if((a->my_employer_id > 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HHLabourStage1_HHLabourStage1Applications(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHLabourStage1_HHLabourStage1Applications(xmachine_memory_household *a)
{
	if(!(a->my_employer_id > 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HHLabourPayroll_HouseholdUpdateDeposits(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHLabourPayroll_HouseholdUpdateDeposits(xmachine_memory_household *a)
{
	if(!(iteration_loop%20 == a->day_of_month_wage_recieved)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_labour_receive_wage_HHLabourPayroll_HHLabourEmploymentStatus(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_labour_receive_wage_HHLabourPayroll_HHLabourEmploymentStatus(xmachine_memory_household *a)
{
	if((iteration_loop%20 == a->day_of_month_wage_recieved)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HHCreditStart_HHCreditMonthly(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHCreditStart_HHCreditMonthly(xmachine_memory_household *a)
{
	if(!(iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HHCreditStart_HHCreditIsCapitalist(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHCreditStart_HHCreditIsCapitalist(xmachine_memory_household *a)
{
	if((iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HHCreditIsCapitalist_HHCreditBalanceSheet(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHCreditIsCapitalist_HHCreditBalanceSheet(xmachine_memory_household *a)
{
	if((a->n_shares == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_credit_collect_shares_HHCreditIsCapitalist_HHCreditBalanceSheet(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_credit_collect_shares_HHCreditIsCapitalist_HHCreditBalanceSheet(xmachine_memory_household *a)
{
	if((a->n_shares > 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HHCreditMonthly_HHLabourStart(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHCreditMonthly_HHLabourStart(xmachine_memory_household *a)
{
	if(!(iteration_loop%20 == a->day_of_month_wage_recieved)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_credit_collect_benefits_HHCreditMonthly_HHLabourStart(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_credit_collect_benefits_HHCreditMonthly_HHLabourStart(xmachine_memory_household *a)
{
	if((iteration_loop%20 == a->day_of_month_wage_recieved)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HHCreditPolicyChecks_end(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHCreditPolicyChecks_end(xmachine_memory_household *a)
{
	if(!(iteration_loop%60 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_credit_check_interest_rate_HHCreditPolicyChecks_HHCreditUpdateAnnuity(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_credit_check_interest_rate_HHCreditPolicyChecks_HHCreditUpdateAnnuity(xmachine_memory_household *a)
{
	if((iteration_loop%60 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HHHousingStart_HHLabourPayroll(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHHousingStart_HHLabourPayroll(xmachine_memory_household *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_housing_market_role_HHHousingStart_HHHousingRole(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_housing_market_role_HHHousingStart_HHHousingRole(xmachine_memory_household *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HHHousingRole_HHHousingPrice(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHHousingRole_HHHousingPrice(xmachine_memory_household *a)
{
	if((a->hmarket_role == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_housing_check_wealth_HHHousingRole_HHHousingCheckWealth(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_housing_check_wealth_HHHousingRole_HHHousingCheckWealth(xmachine_memory_household *a)
{
	if((a->hmarket_role == 3)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_housing_sell_HHHousingRole_HHHousingRevenue(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_housing_sell_HHHousingRole_HHHousingRevenue(xmachine_memory_household *a)
{
	if((a->hmarket_role == 2)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_housing_fire_sell_HHHousingRole_HHHousingRevenue(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_housing_fire_sell_HHHousingRole_HHHousingRevenue(xmachine_memory_household *a)
{
	if((a->hmarket_role == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HHHousingCheckWealth_HHHousingPrice(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHHousingCheckWealth_HHHousingPrice(xmachine_memory_household *a)
{
	if((a->equity_ratio < a->minimum_equity_ratio)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_housing_enter_market_HHHousingCheckWealth_HHHousingBargain(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_housing_enter_market_HHHousingCheckWealth_HHHousingBargain(xmachine_memory_household *a)
{
	if((a->equity_ratio >= a->minimum_equity_ratio)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_equityfund_equityfund_init_start_EquityFundLoop(xmachine_memory_equityfund *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_equityfund_equityfund_init_start_EquityFundLoop(xmachine_memory_equityfund *a)
{
	if((a->it_no == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_equityfund_idle_start_EquityFundLoop(xmachine_memory_equityfund *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_equityfund_idle_start_EquityFundLoop(xmachine_memory_equityfund *a)
{
	if((a->it_no != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_equityfund_idle_EFLabourMarket_EFCreditIncomeStatement(xmachine_memory_equityfund *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_equityfund_idle_EFLabourMarket_EFCreditIncomeStatement(xmachine_memory_equityfund *a)
{
	if(!(iteration_loop%20 == a->day_of_month_wages_paid)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_equityfund_equityfund_audit_dividends_EFLabourMarket_EFCreditIncomeStatement(xmachine_memory_equityfund *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_equityfund_equityfund_audit_dividends_EFLabourMarket_EFCreditIncomeStatement(xmachine_memory_equityfund *a)
{
	if((iteration_loop%20 == a->day_of_month_wages_paid)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_equityfund_idle_EquityFundCredit_EFLabourMarket(xmachine_memory_equityfund *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_equityfund_idle_EquityFundCredit_EFLabourMarket(xmachine_memory_equityfund *a)
{
	if(!(iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_equityfund_equityfund_credit_invest_illiquids_EquityFundCredit_EFCreditShareCollectionBanks(xmachine_memory_equityfund *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_equityfund_equityfund_credit_invest_illiquids_EquityFundCredit_EFCreditShareCollectionBanks(xmachine_memory_equityfund *a)
{
	if((iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_equityfund_idle_EFCreditIncomeStatement_end(xmachine_memory_equityfund *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_equityfund_idle_EFCreditIncomeStatement_end(xmachine_memory_equityfund *a)
{
	if(!(iteration_loop%60 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_equityfund_equityfund_credit_compute_income_statement_EFCreditIncomeStatement_EFCreditBalanceSheet(xmachine_memory_equityfund *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_equityfund_equityfund_credit_compute_income_statement_EFCreditIncomeStatement_EFCreditBalanceSheet(xmachine_memory_equityfund *a)
{
	if((iteration_loop%60 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_bank_idle_start_BankInitLoans(xmachine_memory_bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_bank_idle_start_BankInitLoans(xmachine_memory_bank *a)
{
	if((a->it_no == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_bank_idle_start_BankLoop(xmachine_memory_bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_bank_idle_start_BankLoop(xmachine_memory_bank *a)
{
	if((a->it_no != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_bank_idle_BankUpdateDeposits_BankCreditPolicyChecks(xmachine_memory_bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_bank_idle_BankUpdateDeposits_BankCreditPolicyChecks(xmachine_memory_bank *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_bank_bank_update_deposits_BankUpdateDeposits_BankCreditPolicyChecks(xmachine_memory_bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_bank_bank_update_deposits_BankUpdateDeposits_BankCreditPolicyChecks(xmachine_memory_bank *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_bank_idle_BankCreditStart_BankHousingMarket(xmachine_memory_bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_bank_idle_BankCreditStart_BankHousingMarket(xmachine_memory_bank *a)
{
	if(!(iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_bank_bank_credit_compute_income_statement_BankCreditStart_BankCreditDividends(xmachine_memory_bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_bank_bank_credit_compute_income_statement_BankCreditStart_BankCreditDividends(xmachine_memory_bank *a)
{
	if((iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_bank_idle_BankCreditPolicyChecks_end(xmachine_memory_bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_bank_idle_BankCreditPolicyChecks_end(xmachine_memory_bank *a)
{
	if(!(iteration_loop%60 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_bank_bank_credit_check_interest_rate_BankCreditPolicyChecks_end(xmachine_memory_bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_bank_bank_credit_check_interest_rate_BankCreditPolicyChecks_end(xmachine_memory_bank *a)
{
	if((iteration_loop%60 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_bank_idle_BankHousingMarket_BankUpdateDeposits(xmachine_memory_bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_bank_idle_BankHousingMarket_BankUpdateDeposits(xmachine_memory_bank *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_bank_bank_housing_compute_capital_status_BankHousingMarket_BankHousingCrediting(xmachine_memory_bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_bank_bank_housing_compute_capital_status_BankHousingMarket_BankHousingCrediting(xmachine_memory_bank *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_government_government_init_start_GovernmentLoop(xmachine_memory_government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_government_government_init_start_GovernmentLoop(xmachine_memory_government *a)
{
	if((a->it_no == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_government_idle_start_GovernmentLoop(xmachine_memory_government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_government_idle_start_GovernmentLoop(xmachine_memory_government *a)
{
	if((a->it_no != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_government_idle_GovernmentCredit_GovernmentMonthly(xmachine_memory_government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_government_idle_GovernmentCredit_GovernmentMonthly(xmachine_memory_government *a)
{
	if(!(iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_government_government_collect_capital_tax_GovernmentCredit_GovernmentMonthly(xmachine_memory_government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_government_government_collect_capital_tax_GovernmentCredit_GovernmentMonthly(xmachine_memory_government *a)
{
	if((iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_government_idle_GovernmentMonthly_GovernmentFiscalPolicy(xmachine_memory_government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_government_idle_GovernmentMonthly_GovernmentFiscalPolicy(xmachine_memory_government *a)
{
	if(!(iteration_loop%20 == a->day_of_month_wages_paid)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_government_government_distribute_general_benefits_GovernmentMonthly_GovernmentUnemploymentBenefits(xmachine_memory_government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_government_government_distribute_general_benefits_GovernmentMonthly_GovernmentUnemploymentBenefits(xmachine_memory_government *a)
{
	if((iteration_loop%20 == a->day_of_month_wages_paid)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_government_idle_GovernmentFiscalPolicy_end(xmachine_memory_government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_government_idle_GovernmentFiscalPolicy_end(xmachine_memory_government *a)
{
	if(!(iteration_loop%60 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_government_government_collect_centralbank_profit_GovernmentFiscalPolicy_GovernmentIncomeStatement(xmachine_memory_government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_government_government_collect_centralbank_profit_GovernmentFiscalPolicy_GovernmentIncomeStatement(xmachine_memory_government *a)
{
	if((iteration_loop%60 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_idle_start_CentralBankInitBalanceSheet(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_idle_start_CentralBankInitBalanceSheet(xmachine_memory_centralbank *a)
{
	if((a->it_no == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_idle_start_CentralBankLoop(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_idle_start_CentralBankLoop(xmachine_memory_centralbank *a)
{
	if((a->it_no != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_idle_CentralBankConsumption_CentralBankConsumptionPrices(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_idle_CentralBankConsumption_CentralBankConsumptionPrices(xmachine_memory_centralbank *a)
{
	if(!(iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_centralbank_trace_goods_prices_CentralBankConsumption_CentralBankConsumptionPrices(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_centralbank_trace_goods_prices_CentralBankConsumption_CentralBankConsumptionPrices(xmachine_memory_centralbank *a)
{
	if((iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_idle_CentralBankConsumptionPrices_CentralBankExport(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_idle_CentralBankConsumptionPrices_CentralBankExport(xmachine_memory_centralbank *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_centralbank_update_price_indices_CentralBankConsumptionPrices_CentralBankExport(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_centralbank_update_price_indices_CentralBankConsumptionPrices_CentralBankExport(xmachine_memory_centralbank *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_idle_CentralBankLabour_CentralBankPolicy(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_idle_CentralBankLabour_CentralBankPolicy(xmachine_memory_centralbank *a)
{
	if(!(iteration_loop%20 == a->day_of_month_wages_paid)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_centralbank_trace_unemployment_status_CentralBankLabour_CentralBankPolicy(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_centralbank_trace_unemployment_status_CentralBankLabour_CentralBankPolicy(xmachine_memory_centralbank *a)
{
	if((iteration_loop%20 == a->day_of_month_wages_paid)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_idle_CentralBankCredit_CentralBankConsumption(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_idle_CentralBankCredit_CentralBankConsumption(xmachine_memory_centralbank *a)
{
	if(!(iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_centralbank_collect_interest_payments_CentralBankCredit_CentralBankDebtRequests(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_centralbank_collect_interest_payments_CentralBankCredit_CentralBankDebtRequests(xmachine_memory_centralbank *a)
{
	if((iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_idle_CentralBankPolicy_end(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_idle_CentralBankPolicy_end(xmachine_memory_centralbank *a)
{
	if(!(iteration_loop%60 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_centralbank_compute_income_statement_CentralBankPolicy_CentralBankGovernmentRequests(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_centralbank_compute_income_statement_CentralBankPolicy_CentralBankGovernmentRequests(xmachine_memory_centralbank *a)
{
	if((iteration_loop%60 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_idle_CentralBankHousing_CentralBankLabour(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_idle_CentralBankHousing_CentralBankLabour(xmachine_memory_centralbank *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_centralbank_trace_housing_prices_CentralBankHousing_CentralBankLabour(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_centralbank_trace_housing_prices_CentralBankHousing_CentralBankLabour(xmachine_memory_centralbank *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_centralbank_export_transactions_CentralBankExport_CentralBankHousing(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_centralbank_export_transactions_CentralBankExport_CentralBankHousing(xmachine_memory_centralbank *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_idle_CentralBankExport_CentralBankHousing(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_idle_CentralBankExport_CentralBankHousing(xmachine_memory_centralbank *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_foreignsector_foreignsector_init_start_ForeignsectorLoop(xmachine_memory_foreignsector *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_foreignsector_foreignsector_init_start_ForeignsectorLoop(xmachine_memory_foreignsector *a)
{
	if((a->it_no == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_foreignsector_idle_start_ForeignsectorLoop(xmachine_memory_foreignsector *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_foreignsector_idle_start_ForeignsectorLoop(xmachine_memory_foreignsector *a)
{
	if((a->it_no != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_foreignsector_foreignsector_export_buy_ForeignSectorExportsStart_ForeignSectorExportsPricing(xmachine_memory_foreignsector *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_foreignsector_foreignsector_export_buy_ForeignSectorExportsStart_ForeignSectorExportsPricing(xmachine_memory_foreignsector *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_foreignsector_idle_ForeignSectorExportsStart_end(xmachine_memory_foreignsector *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_foreignsector_idle_ForeignSectorExportsStart_end(xmachine_memory_foreignsector *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_jpoffice_idle_start_JPOfficeInitEmployment(xmachine_memory_jpoffice *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_jpoffice_idle_start_JPOfficeInitEmployment(xmachine_memory_jpoffice *a)
{
	if((a->it_no == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_jpoffice_idle_start_JPOfficeLoop(xmachine_memory_jpoffice *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_jpoffice_idle_start_JPOfficeLoop(xmachine_memory_jpoffice *a)
{
	if((a->it_no != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_jpoffice_idle_JPOLabourMarket_end(xmachine_memory_jpoffice *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_jpoffice_idle_JPOLabourMarket_end(xmachine_memory_jpoffice *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_jpoffice_jpoffice_labour_stage1_JPOLabourMarket_JPOLabourStage2(xmachine_memory_jpoffice *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_jpoffice_jpoffice_labour_stage1_JPOLabourMarket_JPOLabourStage2(xmachine_memory_jpoffice *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_mall_idle_MallConsumptionMarket_end(xmachine_memory_mall *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_mall_idle_MallConsumptionMarket_end(xmachine_memory_mall *a)
{
	if(!(iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_mall_mall_consumption_shopping_MallConsumptionMarket_MallConsumptionSummary(xmachine_memory_mall *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_mall_mall_consumption_shopping_MallConsumptionMarket_MallConsumptionSummary(xmachine_memory_mall *a)
{
	if((iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_reagency_idle_REAgencyCreditPolicyChecks_end(xmachine_memory_reagency *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_reagency_idle_REAgencyCreditPolicyChecks_end(xmachine_memory_reagency *a)
{
	if(!(iteration_loop%60 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_reagency_reagency_check_interest_rate_REAgencyCreditPolicyChecks_end(xmachine_memory_reagency *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_reagency_reagency_check_interest_rate_REAgencyCreditPolicyChecks_end(xmachine_memory_reagency *a)
{
	if((iteration_loop%60 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_reagency_idle_REAgencyHousingMarket_REAgencyCreditPolicyChecks(xmachine_memory_reagency *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_reagency_idle_REAgencyHousingMarket_REAgencyCreditPolicyChecks(xmachine_memory_reagency *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_reagency_reagency_housing_process_REAgencyHousingMarket_REAgencyHousingSummary(xmachine_memory_reagency *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_reagency_reagency_housing_process_REAgencyHousingMarket_REAgencyHousingSummary(xmachine_memory_reagency *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}



/** \fn int FLAME_filter_firm_firm_init_employment_FirmInitEmployment_FirmInitBalanceSheet_jpoffice_firm_employee(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_firm_init_employment_FirmInitEmployment_FirmInitBalanceSheet_jpoffice_firm_employee(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_firm_init_employment_FirmInitEmployment_FirmInitBalanceSheet_jpoffice_firm_employee(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_jpoffice_firm_employee *m = (m_jpoffice_firm_employee*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_firm *a = (xmachine_memory_firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_firm_firm_consumption_receive_sales_FirmReceiveSales_FirmConsumptionPrice_sold(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_firm_consumption_receive_sales_FirmReceiveSales_FirmConsumptionPrice_sold(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_firm_consumption_receive_sales_FirmReceiveSales_FirmConsumptionPrice_sold(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_sold *m = (m_sold*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_firm *a = (xmachine_memory_firm *)params;

	/* The filter */
	if((a->id == m->id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_firm_firm_labour_job_offer_stage1_FirmLabourStage1Application_FirmLabourStage1End_job_match_stage1(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_firm_labour_job_offer_stage1_FirmLabourStage1Application_FirmLabourStage1End_job_match_stage1(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_firm_labour_job_offer_stage1_FirmLabourStage1Application_FirmLabourStage1End_job_match_stage1(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_job_match_stage1 *m = (m_job_match_stage1*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_firm *a = (xmachine_memory_firm *)params;

	/* The filter */
	if((a->id == m->employer_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_firm_firm_labour_update_FirmLabourStage1End_FirmLabourStage2_job_change(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_firm_labour_update_FirmLabourStage1End_FirmLabourStage2_job_change(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_firm_labour_update_FirmLabourStage1End_FirmLabourStage2_job_change(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_job_change *m = (m_job_change*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_firm *a = (xmachine_memory_firm *)params;

	/* The filter */
	if((a->id == m->employer_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_firm_firm_labour_job_offer_stage2_FirmLabourStage2End_FirmConsumptionStart_job_match_stage2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_firm_labour_job_offer_stage2_FirmLabourStage2End_FirmConsumptionStart_job_match_stage2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_firm_labour_job_offer_stage2_FirmLabourStage2End_FirmConsumptionStart_job_match_stage2(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_job_match_stage2 *m = (m_job_match_stage2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_firm *a = (xmachine_memory_firm *)params;

	/* The filter */
	if((a->id == m->employer_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_firm_firm_credit_borrow_loans_1_FirmCreditLoanBorrow1_FirmCreditLoanBorrow2_bank_firm_loan_acknowledge_1(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_firm_credit_borrow_loans_1_FirmCreditLoanBorrow1_FirmCreditLoanBorrow2_bank_firm_loan_acknowledge_1(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_firm_credit_borrow_loans_1_FirmCreditLoanBorrow1_FirmCreditLoanBorrow2_bank_firm_loan_acknowledge_1(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_bank_firm_loan_acknowledge_1 *m = (m_bank_firm_loan_acknowledge_1*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_firm *a = (xmachine_memory_firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_firm_firm_credit_borrow_loans_2_FirmCreditLoanBorrow2_FirmCreditIlliquidityStatus_bank_firm_loan_acknowledge_2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_firm_credit_borrow_loans_2_FirmCreditLoanBorrow2_FirmCreditIlliquidityStatus_bank_firm_loan_acknowledge_2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_firm_credit_borrow_loans_2_FirmCreditLoanBorrow2_FirmCreditIlliquidityStatus_bank_firm_loan_acknowledge_2(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_bank_firm_loan_acknowledge_2 *m = (m_bank_firm_loan_acknowledge_2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_firm *a = (xmachine_memory_firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_firm_firm_credit_check_equityfund_investment_FirmCreditLiquidityRecheck_FirmCreditBankruptcy_fund_request_ack(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_firm_credit_check_equityfund_investment_FirmCreditLiquidityRecheck_FirmCreditBankruptcy_fund_request_ack(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_firm_credit_check_equityfund_investment_FirmCreditLiquidityRecheck_FirmCreditBankruptcy_fund_request_ack(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_fund_request_ack *m = (m_fund_request_ack*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_firm *a = (xmachine_memory_firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_firm_firm_housing_collect_sale_revenues_FirmHousingSell_FirmHousingPrice_sold_housing(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_firm_housing_collect_sale_revenues_FirmHousingSell_FirmHousingPrice_sold_housing(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_firm_housing_collect_sale_revenues_FirmHousingSell_FirmHousingPrice_sold_housing(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_sold_housing *m = (m_sold_housing*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_firm *a = (xmachine_memory_firm *)params;

	/* The filter */
	if((a->id == m->seller_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_firm_firm_export_receive_sales_FirmExportReceiveSales_FirmHousingStart_centralbank_firm_revenues(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_firm_export_receive_sales_FirmExportReceiveSales_FirmHousingStart_centralbank_firm_revenues(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_firm_export_receive_sales_FirmExportReceiveSales_FirmHousingStart_centralbank_firm_revenues(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_centralbank_firm_revenues *m = (m_centralbank_firm_revenues*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_firm *a = (xmachine_memory_firm *)params;

	/* The filter */
	if((a->id == m->id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_household_household_init_employment_HouseholdInitEmployment_HouseholdInitBalanceSheet_jpoffice_household_employer(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_household_household_init_employment_HouseholdInitEmployment_HouseholdInitBalanceSheet_jpoffice_household_employer(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_household_household_init_employment_HouseholdInitEmployment_HouseholdInitBalanceSheet_jpoffice_household_employer(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_jpoffice_household_employer *m = (m_jpoffice_household_employer*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_household *a = (xmachine_memory_household *)params;

	/* The filter */
	if((a->id == m->household_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_household_household_consumption_recieve_goods_HHConsumptionRecieveGoods_HHHousingStart_bought(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_household_household_consumption_recieve_goods_HHConsumptionRecieveGoods_HHHousingStart_bought(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_household_household_consumption_recieve_goods_HHConsumptionRecieveGoods_HHHousingStart_bought(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_bought *m = (m_bought*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_household *a = (xmachine_memory_household *)params;

	/* The filter */
	if((a->id == m->id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_household_household_labour_check_fired_HHLabourStart_HHLabourStage1_fired(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_household_household_labour_check_fired_HHLabourStart_HHLabourStage1_fired(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_household_household_labour_check_fired_HHLabourStart_HHLabourStage1_fired(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_fired *m = (m_fired*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_household *a = (xmachine_memory_household *)params;

	/* The filter */
	if((a->id == m->employee_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_household_household_labour_turnover_HHLabourStage2_HHConsumptionStart_job_match_stage1(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_household_household_labour_turnover_HHLabourStage2_HHConsumptionStart_job_match_stage1(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_household_household_labour_turnover_HHLabourStage2_HHConsumptionStart_job_match_stage1(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_job_match_stage1 *m = (m_job_match_stage1*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_household *a = (xmachine_memory_household *)params;

	/* The filter */
	if((a->id == m->employee_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_household_household_labour_employment_HHLabourStage1Placement_HHConsumptionStart_job_match_stage2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_household_household_labour_employment_HHLabourStage1Placement_HHConsumptionStart_job_match_stage2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_household_household_labour_employment_HHLabourStage1Placement_HHConsumptionStart_job_match_stage2(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_job_match_stage2 *m = (m_job_match_stage2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_household *a = (xmachine_memory_household *)params;

	/* The filter */
	if((a->id == m->employee_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_household_household_labour_receive_wage_HHLabourPayroll_HHLabourEmploymentStatus_firm_household_wage_payment(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_household_household_labour_receive_wage_HHLabourPayroll_HHLabourEmploymentStatus_firm_household_wage_payment(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_household_household_labour_receive_wage_HHLabourPayroll_HHLabourEmploymentStatus_firm_household_wage_payment(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_firm_household_wage_payment *m = (m_firm_household_wage_payment*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_household *a = (xmachine_memory_household *)params;

	/* The filter */
	if((a->my_employer_id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_household_household_housing_collect_sale_revenue_HHHousingRevenue_HHHousingPrice_sold_housing(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_household_household_housing_collect_sale_revenue_HHHousingRevenue_HHHousingPrice_sold_housing(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_household_household_housing_collect_sale_revenue_HHHousingRevenue_HHHousingPrice_sold_housing(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_sold_housing *m = (m_sold_housing*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_household *a = (xmachine_memory_household *)params;

	/* The filter */
	if((a->id == m->seller_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_household_household_housing_buy_HHHousingBargain_HHHousingPrice_bought_housing(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_household_household_housing_buy_HHHousingBargain_HHHousingPrice_bought_housing(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_household_household_housing_buy_HHHousingBargain_HHHousingPrice_bought_housing(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_bought_housing *m = (m_bought_housing*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_household *a = (xmachine_memory_household *)params;

	/* The filter */
	if((a->id == m->buyer_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_init_loans_BankInitLoans_BankInitMortgages_firm_bank_init_loans(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_init_loans_BankInitLoans_BankInitMortgages_firm_bank_init_loans(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_init_loans_BankInitLoans_BankInitMortgages_firm_bank_init_loans(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_firm_bank_init_loans *m = (m_firm_bank_init_loans*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_init_mortgages_BankInitMortgages_BankInitDeposits_household_bank_init_mortgages(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_init_mortgages_BankInitMortgages_BankInitDeposits_household_bank_init_mortgages(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_init_mortgages_BankInitMortgages_BankInitDeposits_household_bank_init_mortgages(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_household_bank_init_mortgages *m = (m_household_bank_init_mortgages*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_init_deposits_BankInitDeposits_BankInitBalanceSheet_household_bank_init_deposit(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_init_deposits_BankInitDeposits_BankInitBalanceSheet_household_bank_init_deposit(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_init_deposits_BankInitDeposits_BankInitBalanceSheet_household_bank_init_deposit(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_household_bank_init_deposit *m = (m_household_bank_init_deposit*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_init_deposits_BankInitDeposits_BankInitBalanceSheet_firm_bank_init_deposit(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_init_deposits_BankInitDeposits_BankInitBalanceSheet_firm_bank_init_deposit(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_init_deposits_BankInitDeposits_BankInitBalanceSheet_firm_bank_init_deposit(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_firm_bank_init_deposit *m = (m_firm_bank_init_deposit*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_BankCreditPolicyChecks_household_bank_update_deposit(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_BankCreditPolicyChecks_household_bank_update_deposit(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_BankCreditPolicyChecks_household_bank_update_deposit(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_household_bank_update_deposit *m = (m_household_bank_update_deposit*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_BankCreditPolicyChecks_firm_bank_update_deposit(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_BankCreditPolicyChecks_firm_bank_update_deposit(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_BankCreditPolicyChecks_firm_bank_update_deposit(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_firm_bank_update_deposit *m = (m_firm_bank_update_deposit*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_credit_process_loan_requests_1_BankCreditRequest1_BankCreditRequest2_firm_bank_loan_request_1(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_credit_process_loan_requests_1_BankCreditRequest1_BankCreditRequest2_firm_bank_loan_request_1(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_credit_process_loan_requests_1_BankCreditRequest1_BankCreditRequest2_firm_bank_loan_request_1(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_firm_bank_loan_request_1 *m = (m_firm_bank_loan_request_1*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_credit_process_loan_requests_2_BankCreditRequest2_BankCreditLoanWriteOffs_firm_bank_loan_request_2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_credit_process_loan_requests_2_BankCreditRequest2_BankCreditLoanWriteOffs_firm_bank_loan_request_2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_credit_process_loan_requests_2_BankCreditRequest2_BankCreditLoanWriteOffs_firm_bank_loan_request_2(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_firm_bank_loan_request_2 *m = (m_firm_bank_loan_request_2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_credit_recieve_loan_writeoffs_BankCreditLoanWriteOffs_BankCreditNewEntrants_loan_writeoff(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_credit_recieve_loan_writeoffs_BankCreditLoanWriteOffs_BankCreditNewEntrants_loan_writeoff(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_credit_recieve_loan_writeoffs_BankCreditLoanWriteOffs_BankCreditNewEntrants_loan_writeoff(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_loan_writeoff *m = (m_loan_writeoff*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_credit_recieve_loan_writeoffs_BankCreditLoanWriteOffs_BankCreditNewEntrants_firm_bank_insolvent_account(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_credit_recieve_loan_writeoffs_BankCreditLoanWriteOffs_BankCreditNewEntrants_firm_bank_insolvent_account(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_credit_recieve_loan_writeoffs_BankCreditLoanWriteOffs_BankCreditNewEntrants_firm_bank_insolvent_account(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_firm_bank_insolvent_account *m = (m_firm_bank_insolvent_account*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_credit_recieve_new_entrant_loan_requests_BankCreditNewEntrants_BankCreditLoanInterests_new_entrant_loan(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_credit_recieve_new_entrant_loan_requests_BankCreditNewEntrants_BankCreditLoanInterests_new_entrant_loan(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_credit_recieve_new_entrant_loan_requests_BankCreditNewEntrants_BankCreditLoanInterests_new_entrant_loan(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_new_entrant_loan *m = (m_new_entrant_loan*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_credit_collect_loan_interests_BankCreditLoanInterests_BankHousingMarket_firm_bank_interest_on_loan(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_credit_collect_loan_interests_BankCreditLoanInterests_BankHousingMarket_firm_bank_interest_on_loan(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_credit_collect_loan_interests_BankCreditLoanInterests_BankHousingMarket_firm_bank_interest_on_loan(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_firm_bank_interest_on_loan *m = (m_firm_bank_interest_on_loan*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_housing_deliver_mortages_BankHousingCrediting_BankHousingSales_mortgage_requests(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_housing_deliver_mortages_BankHousingCrediting_BankHousingSales_mortgage_requests(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_housing_deliver_mortages_BankHousingCrediting_BankHousingSales_mortgage_requests(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_mortgage_requests *m = (m_mortgage_requests*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_housing_recieve_mortgage_principals_BankHousingSales_BankHousingMortgages_mortgage_payment_from_sale(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_housing_recieve_mortgage_principals_BankHousingSales_BankHousingMortgages_mortgage_payment_from_sale(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_housing_recieve_mortgage_principals_BankHousingSales_BankHousingMortgages_mortgage_payment_from_sale(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_mortgage_payment_from_sale *m = (m_mortgage_payment_from_sale*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_housing_recieve_mortgages_BankHousingMortgages_BankHousingWriteOff_mortgage_payment(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_housing_recieve_mortgages_BankHousingMortgages_BankHousingWriteOff_mortgage_payment(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_housing_recieve_mortgages_BankHousingMortgages_BankHousingWriteOff_mortgage_payment(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_mortgage_payment *m = (m_mortgage_payment*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_housing_debt_writeoff_BankHousingWriteOff_BankUpdateDeposits_mortgage_writeoff(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_housing_debt_writeoff_BankHousingWriteOff_BankUpdateDeposits_mortgage_writeoff(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_housing_debt_writeoff_BankHousingWriteOff_BankUpdateDeposits_mortgage_writeoff(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_mortgage_writeoff *m = (m_mortgage_writeoff*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}


int FLAME_sort_jpoffice_jpoffice_init_employment_JPOfficeInitEmployment_JPOfficeLoop_household_jpoffice_id(const void *x, const void *y)
{
	if( ((m_household_jpoffice_id *)x)->household_id < ((m_household_jpoffice_id *)y)->household_id ) return -1;
	else if( ((m_household_jpoffice_id *)x)->household_id > ((m_household_jpoffice_id *)y)->household_id ) return 1;
	else return 0;
}
int FLAME_sort_jpoffice_jpoffice_init_employment_JPOfficeInitEmployment_JPOfficeLoop_firm_jpoffice_id(const void *x, const void *y)
{
	if( ((m_firm_jpoffice_id *)x)->firm_id < ((m_firm_jpoffice_id *)y)->firm_id ) return -1;
	else if( ((m_firm_jpoffice_id *)x)->firm_id > ((m_firm_jpoffice_id *)y)->firm_id ) return 1;
	else return 0;
}
int FLAME_sort_jpoffice_jpoffice_labour_stage1_JPOLabourMarket_JPOLabourStage2_vacancy_stage1(const void *x, const void *y)
{
	if( ((m_vacancy_stage1 *)x)->wage > ((m_vacancy_stage1 *)y)->wage ) return -1;
	else if( ((m_vacancy_stage1 *)x)->wage < ((m_vacancy_stage1 *)y)->wage ) return 1;
	else return 0;
}
int FLAME_sort_jpoffice_jpoffice_labour_stage1_JPOLabourMarket_JPOLabourStage2_job_application_stage1(const void *x, const void *y)
{
	if( ((m_job_application_stage1 *)x)->employee_id < ((m_job_application_stage1 *)y)->employee_id ) return -1;
	else if( ((m_job_application_stage1 *)x)->employee_id > ((m_job_application_stage1 *)y)->employee_id ) return 1;
	else return 0;
}
int FLAME_sort_jpoffice_jpoffice_labour_stage2_JPOLabourStage2_end_vacancy_stage2(const void *x, const void *y)
{
	if( ((m_vacancy_stage2 *)x)->wage > ((m_vacancy_stage2 *)y)->wage ) return -1;
	else if( ((m_vacancy_stage2 *)x)->wage < ((m_vacancy_stage2 *)y)->wage ) return 1;
	else return 0;
}
int FLAME_sort_jpoffice_jpoffice_labour_stage2_JPOLabourStage2_end_job_application_stage2(const void *x, const void *y)
{
	if( ((m_job_application_stage2 *)x)->employee_id < ((m_job_application_stage2 *)y)->employee_id ) return -1;
	else if( ((m_job_application_stage2 *)x)->employee_id > ((m_job_application_stage2 *)y)->employee_id ) return 1;
	else return 0;
}
int FLAME_sort_mall_mall_consumption_shopping_MallConsumptionMarket_MallConsumptionSummary_sell(const void *x, const void *y)
{
	if( ((m_sell *)x)->price < ((m_sell *)y)->price ) return -1;
	else if( ((m_sell *)x)->price > ((m_sell *)y)->price ) return 1;
	else return 0;
}
int FLAME_sort_reagency_reagency_housing_process_REAgencyHousingMarket_REAgencyHousingSummary_sell_housing(const void *x, const void *y)
{
	if( ((m_sell_housing *)x)->price < ((m_sell_housing *)y)->price ) return -1;
	else if( ((m_sell_housing *)x)->price > ((m_sell_housing *)y)->price ) return 1;
	else return 0;
}

