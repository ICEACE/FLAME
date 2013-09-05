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


/** \fn int FLAME_condition_firm_idle_FirmUpdateDeposits_end(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmUpdateDeposits_end(xmachine_memory_firm *a)
{
	if(!(iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_update_bank_account_FirmUpdateDeposits_end(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_update_bank_account_FirmUpdateDeposits_end(xmachine_memory_firm *a)
{
	if((iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmConsumptionStart_FirmHousingStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmConsumptionStart_FirmHousingStart(xmachine_memory_firm *a)
{
	if(!(iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_consumption_supply_FirmConsumptionStart_FirmRecieveSales(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_consumption_supply_FirmConsumptionStart_FirmRecieveSales(xmachine_memory_firm *a)
{
	if((iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmLabourStart_FirmLabourPayWages(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmLabourStart_FirmLabourPayWages(xmachine_memory_firm *a)
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
	if((a->no_employees == a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_labour_fire_FirmLabourStage1_FirmLabourStage1End(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_labour_fire_FirmLabourStage1_FirmLabourStage1End(xmachine_memory_firm *a)
{
	if((a->no_employees > a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_labour_job_announcement_stage1_FirmLabourStage1_FirmLabourStage1Application(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_labour_job_announcement_stage1_FirmLabourStage1_FirmLabourStage1Application(xmachine_memory_firm *a)
{
	if((a->no_employees < a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_labour_job_announcement_stage2_FirmLabourStage2_FirmLabourStage2End(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_labour_job_announcement_stage2_FirmLabourStage2_FirmLabourStage2End(xmachine_memory_firm *a)
{
	if((a->no_employees < a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmLabourStage2_FirmLabourPayWages(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmLabourStage2_FirmLabourPayWages(xmachine_memory_firm *a)
{
	if((a->no_employees >= a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmLabourPayWages_FirmConsumptionStart(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmLabourPayWages_FirmConsumptionStart(xmachine_memory_firm *a)
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
	if((a->isconstructor == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmProductionRoleCheck_FirmProductionConstructor(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmProductionRoleCheck_FirmProductionConstructor(xmachine_memory_firm *a)
{
	if((a->isconstructor != 0)) return 1;
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


/** \fn int FLAME_condition_firm_firm_credit_check_interest_rate_FirmCreditStart_FirmCreditLiquidityNeed(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_credit_check_interest_rate_FirmCreditStart_FirmCreditLiquidityNeed(xmachine_memory_firm *a)
{
	if((iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmCreditStatus_FirmCreditDividendPayments(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmCreditStatus_FirmCreditDividendPayments(xmachine_memory_firm *a)
{
	if((a->liquidity_need == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmCreditStatus_FirmCreditLoanRequest(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmCreditStatus_FirmCreditLoanRequest(xmachine_memory_firm *a)
{
	if((a->liquidity_need != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmCreditLoanRequest_FirmCreditInsolvency(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmCreditLoanRequest_FirmCreditInsolvency(xmachine_memory_firm *a)
{
	if((a->equity < 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_credit_demand_loans_1_FirmCreditLoanRequest_FirmCreditLoanBorrow1(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_credit_demand_loans_1_FirmCreditLoanRequest_FirmCreditLoanBorrow1(xmachine_memory_firm *a)
{
	if((a->equity >= 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmCreditLoanBorrow2_FirmCreditDividendPayments(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmCreditLoanBorrow2_FirmCreditDividendPayments(xmachine_memory_firm *a)
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


/** \fn int FLAME_condition_firm_idle_FirmCreditIlliquidityStatus_FirmCreditDividendPayments(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmCreditIlliquidityStatus_FirmCreditDividendPayments(xmachine_memory_firm *a)
{
	if((a->hasloan != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_credit_request_investment_FirmCreditIlliquidityStatus_FirmCreditCheckInvestment(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_credit_request_investment_FirmCreditIlliquidityStatus_FirmCreditCheckInvestment(xmachine_memory_firm *a)
{
	if((a->hasloan == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmCreditBankruptcy_FirmCreditLoanPayment(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmCreditBankruptcy_FirmCreditLoanPayment(xmachine_memory_firm *a)
{
	if((a->hasinvestment != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_firm_credit_illiquidity_bankrupt_FirmCreditBankruptcy_FirmCreditIncomeStatement(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_firm_credit_illiquidity_bankrupt_FirmCreditBankruptcy_FirmCreditIncomeStatement(xmachine_memory_firm *a)
{
	if((a->hasinvestment == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmHousingStart_FirmUpdateDeposits(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmHousingStart_FirmUpdateDeposits(xmachine_memory_firm *a)
{
	if((a->isconstructor == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmHousingStart_FirmHousingMarket(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmHousingStart_FirmHousingMarket(xmachine_memory_firm *a)
{
	if((a->isconstructor != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_firm_idle_FirmHousingMarket_FirmUpdateDeposits(xmachine_memory_firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_firm_idle_FirmHousingMarket_FirmUpdateDeposits(xmachine_memory_firm *a)
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


/** \fn int FLAME_condition_household_idle_HouseholdUpdateDeposits_end(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HouseholdUpdateDeposits_end(xmachine_memory_household *a)
{
	if(!(iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_update_bank_account_HouseholdUpdateDeposits_end(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_update_bank_account_HouseholdUpdateDeposits_end(xmachine_memory_household *a)
{
	if((iteration_loop%5 == a->day_of_week_to_act)) return 1;
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


/** \fn int FLAME_condition_household_household_consumption_monthly_budget_HHConsumptionStart_HHConsumptionWeekly(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_consumption_monthly_budget_HHConsumptionStart_HHConsumptionWeekly(xmachine_memory_household *a)
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


/** \fn int FLAME_condition_household_idle_HHLabourStart_HHLabourEmploymentStatus(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHLabourStart_HHLabourEmploymentStatus(xmachine_memory_household *a)
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


/** \fn int FLAME_condition_household_idle_HHLabourPayroll_HHConsumptionStart(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHLabourPayroll_HHConsumptionStart(xmachine_memory_household *a)
{
	if(!(iteration_loop%20 == a->day_of_month_wage_recieved)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_labour_recieve_wage_HHLabourPayroll_HHConsumptionStart(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_labour_recieve_wage_HHLabourPayroll_HHConsumptionStart(xmachine_memory_household *a)
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


/** \fn int FLAME_condition_household_household_credit_check_interest_rate_HHCreditStart_HHCreditCheckTax(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_credit_check_interest_rate_HHCreditStart_HHCreditCheckTax(xmachine_memory_household *a)
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
	if((a->dividends == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_credit_collect_shares_HHCreditIsCapitalist_HHCreditCapitalTax(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_credit_collect_shares_HHCreditIsCapitalist_HHCreditCapitalTax(xmachine_memory_household *a)
{
	if((a->dividends > 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HHCreditMonthly_HHLabourStart(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHCreditMonthly_HHLabourStart(xmachine_memory_household *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_credit_collect_benefits_HHCreditMonthly_HHCreditEmployment(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_credit_collect_benefits_HHCreditMonthly_HHCreditEmployment(xmachine_memory_household *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_credit_collect_unemployment_HHCreditEmployment_HHLabourStart(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_credit_collect_unemployment_HHCreditEmployment_HHLabourStart(xmachine_memory_household *a)
{
	if((a->my_employer_id == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_household_credit_pay_labour_tax_HHCreditEmployment_HHLabourStart(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_household_credit_pay_labour_tax_HHCreditEmployment_HHLabourStart(xmachine_memory_household *a)
{
	if((a->my_employer_id != 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_household_idle_HHHousingStart_HouseholdUpdateDeposits(xmachine_memory_household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_household_idle_HHHousingStart_HouseholdUpdateDeposits(xmachine_memory_household *a)
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


/** \fn int FLAME_condition_equityfund_idle_EFLabourMarket_end(xmachine_memory_equityfund *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_equityfund_idle_EFLabourMarket_end(xmachine_memory_equityfund *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_equityfund_equityfund_audit_dividends_EFLabourMarket_end(xmachine_memory_equityfund *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_equityfund_equityfund_audit_dividends_EFLabourMarket_end(xmachine_memory_equityfund *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_equityfund_idle_EquityFundStart_EFLabourMarket(xmachine_memory_equityfund *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_equityfund_idle_EquityFundStart_EFLabourMarket(xmachine_memory_equityfund *a)
{
	if(!(iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_equityfund_equityfund_credit_invest_illiquids_EquityFundStart_EFCreditDistributeShares(xmachine_memory_equityfund *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_equityfund_equityfund_credit_invest_illiquids_EquityFundStart_EFCreditDistributeShares(xmachine_memory_equityfund *a)
{
	if((iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_bank_idle_BankUpdateDeposits_end(xmachine_memory_bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_bank_idle_BankUpdateDeposits_end(xmachine_memory_bank *a)
{
	if(!(iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_bank_bank_update_deposits_BankUpdateDeposits_end(xmachine_memory_bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_bank_bank_update_deposits_BankUpdateDeposits_end(xmachine_memory_bank *a)
{
	if((iteration_loop%5 == a->day_of_week_to_act)) return 1;
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


/** \fn int FLAME_condition_bank_bank_credit_process_loan_requests_1_BankCreditStart_BankCreditRequest2(xmachine_memory_bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_bank_bank_credit_process_loan_requests_1_BankCreditStart_BankCreditRequest2(xmachine_memory_bank *a)
{
	if((iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_bank_idle_BankCreditLiquidityNeed_BankCreditIncomeStatement(xmachine_memory_bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_bank_idle_BankCreditLiquidityNeed_BankCreditIncomeStatement(xmachine_memory_bank *a)
{
	if((a->liquidity > 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_bank_bank_credit_request_liquidity_BankCreditLiquidityNeed_BankCreditLiquidtyRecieve(xmachine_memory_bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_bank_bank_credit_request_liquidity_BankCreditLiquidityNeed_BankCreditLiquidtyRecieve(xmachine_memory_bank *a)
{
	if((a->liquidity <= 0)) return 1;
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


/** \fn int FLAME_condition_government_idle_GovernmentStart_GovernmentMonthly(xmachine_memory_government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_government_idle_GovernmentStart_GovernmentMonthly(xmachine_memory_government *a)
{
	if(!(iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_government_government_update_fiscal_policy_GovernmentStart_GovernmentCapitalTax(xmachine_memory_government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_government_government_update_fiscal_policy_GovernmentStart_GovernmentCapitalTax(xmachine_memory_government *a)
{
	if((iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_government_idle_GovernmentMonthly_end(xmachine_memory_government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_government_idle_GovernmentMonthly_end(xmachine_memory_government *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_government_government_distribute_general_benefits_GovernmentMonthly_GovernmentUnemploymentBenefits(xmachine_memory_government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_government_government_distribute_general_benefits_GovernmentMonthly_GovernmentUnemploymentBenefits(xmachine_memory_government *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_idle_CentralBankConsumption_CentralBankHousing(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_idle_CentralBankConsumption_CentralBankHousing(xmachine_memory_centralbank *a)
{
	if(!(iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_centralbank_trace_goods_prices_CentralBankConsumption_CentralBankHousing(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_centralbank_trace_goods_prices_CentralBankConsumption_CentralBankHousing(xmachine_memory_centralbank *a)
{
	if((iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_idle_CentralBankLabour_CentralBankConsumption(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_idle_CentralBankLabour_CentralBankConsumption(xmachine_memory_centralbank *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_centralbank_trace_unemployment_status_CentralBankLabour_CentralBankConsumption(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_centralbank_trace_unemployment_status_CentralBankLabour_CentralBankConsumption(xmachine_memory_centralbank *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_idle_CentralBankCredit_CentralBankLabour(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_idle_CentralBankCredit_CentralBankLabour(xmachine_memory_centralbank *a)
{
	if(!(iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_centralbank_set_interest_rate_CentralBankCredit_CentralBankDebtRequests(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_centralbank_set_interest_rate_CentralBankCredit_CentralBankDebtRequests(xmachine_memory_centralbank *a)
{
	if((iteration_loop%60 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_idle_CentralBankHousing_end(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_idle_CentralBankHousing_end(xmachine_memory_centralbank *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_centralbank_centralbank_trace_housing_prices_CentralBankHousing_end(xmachine_memory_centralbank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_centralbank_centralbank_trace_housing_prices_CentralBankHousing_end(xmachine_memory_centralbank *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
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


/** \fn int FLAME_condition_reagency_idle_REAgencyHousingMarket_end(xmachine_memory_reagency *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_reagency_idle_REAgencyHousingMarket_end(xmachine_memory_reagency *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_reagency_reagency_housing_check_interest_rate_REAgencyHousingMarket_REAgencyHousingProcess(xmachine_memory_reagency *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_reagency_reagency_housing_check_interest_rate_REAgencyHousingMarket_REAgencyHousingProcess(xmachine_memory_reagency *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}



/** \fn int FLAME_filter_firm_firm_consumption_recieve_sales_FirmRecieveSales_FirmConsumptionPrice_sold(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_firm_consumption_recieve_sales_FirmRecieveSales_FirmConsumptionPrice_sold(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_firm_consumption_recieve_sales_FirmRecieveSales_FirmConsumptionPrice_sold(const void *msg, const void *params)\n");
	
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

/** \fn int FLAME_filter_firm_firm_labour_job_offer_stage2_FirmLabourStage2End_FirmLabourPayWages_job_match_stage2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_firm_labour_job_offer_stage2_FirmLabourStage2End_FirmLabourPayWages_job_match_stage2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_firm_labour_job_offer_stage2_FirmLabourStage2End_FirmLabourPayWages_job_match_stage2(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_job_match_stage2 *m = (m_job_match_stage2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_firm *a = (xmachine_memory_firm *)params;

	/* The filter */
	if((a->id == m->employer_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_firm_firm_credit_borrow_loans_1_FirmCreditLoanBorrow1_FirmCreditLoanBorrow2_loan_acknowledge_1(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_firm_credit_borrow_loans_1_FirmCreditLoanBorrow1_FirmCreditLoanBorrow2_loan_acknowledge_1(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_firm_credit_borrow_loans_1_FirmCreditLoanBorrow1_FirmCreditLoanBorrow2_loan_acknowledge_1(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_loan_acknowledge_1 *m = (m_loan_acknowledge_1*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_firm *a = (xmachine_memory_firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_firm_firm_credit_borrow_loans_2_FirmCreditLoanBorrow2_FirmCreditIlliquidityStatus_loan_acknowledge_2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_firm_credit_borrow_loans_2_FirmCreditLoanBorrow2_FirmCreditIlliquidityStatus_loan_acknowledge_2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_firm_credit_borrow_loans_2_FirmCreditLoanBorrow2_FirmCreditIlliquidityStatus_loan_acknowledge_2(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_loan_acknowledge_2 *m = (m_loan_acknowledge_2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_firm *a = (xmachine_memory_firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_firm_firm_credit_check_investment_FirmCreditCheckInvestment_FirmCreditBankruptcy_fund_request_ack(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_firm_credit_check_investment_FirmCreditCheckInvestment_FirmCreditBankruptcy_fund_request_ack(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_firm_credit_check_investment_FirmCreditCheckInvestment_FirmCreditBankruptcy_fund_request_ack(const void *msg, const void *params)\n");
	
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

/** \fn int FLAME_filter_household_household_labour_turnover_HHLabourStage2_HHLabourEmploymentStatus_job_match_stage1(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_household_household_labour_turnover_HHLabourStage2_HHLabourEmploymentStatus_job_match_stage1(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_household_household_labour_turnover_HHLabourStage2_HHLabourEmploymentStatus_job_match_stage1(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_job_match_stage1 *m = (m_job_match_stage1*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_household *a = (xmachine_memory_household *)params;

	/* The filter */
	if((a->id == m->employee_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_household_household_labour_employment_HHLabourStage1Placement_HHLabourEmploymentStatus_job_match_stage2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_household_household_labour_employment_HHLabourStage1Placement_HHLabourEmploymentStatus_job_match_stage2(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_household_household_labour_employment_HHLabourStage1Placement_HHLabourEmploymentStatus_job_match_stage2(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_job_match_stage2 *m = (m_job_match_stage2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_household *a = (xmachine_memory_household *)params;

	/* The filter */
	if((a->id == m->employee_id)) return 1;
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

/** \fn int FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_end_household_bank_update_deposit(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_end_household_bank_update_deposit(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_end_household_bank_update_deposit(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_household_bank_update_deposit *m = (m_household_bank_update_deposit*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_end_firm_bank_update_deposit(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_end_firm_bank_update_deposit(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_end_firm_bank_update_deposit(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_firm_bank_update_deposit *m = (m_firm_bank_update_deposit*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_credit_process_loan_requests_1_BankCreditStart_BankCreditRequest2_loan_request_1(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_credit_process_loan_requests_1_BankCreditStart_BankCreditRequest2_loan_request_1(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_credit_process_loan_requests_1_BankCreditStart_BankCreditRequest2_loan_request_1(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_loan_request_1 *m = (m_loan_request_1*)msg;
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

/** \fn int FLAME_filter_bank_bank_credit_collect_loan_interests_BankCreditLoanInterests_BankCreditLiquidityNeed_interest_on_loan(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_credit_collect_loan_interests_BankCreditLoanInterests_BankCreditLiquidityNeed_interest_on_loan(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_credit_collect_loan_interests_BankCreditLoanInterests_BankCreditLiquidityNeed_interest_on_loan(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_interest_on_loan *m = (m_interest_on_loan*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_bank *a = (xmachine_memory_bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_bank_bank_credit_recieve_liquidity_BankCreditLiquidtyRecieve_BankCreditIncomeStatement_debt_ack(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_bank_bank_credit_recieve_liquidity_BankCreditLiquidtyRecieve_BankCreditIncomeStatement_debt_ack(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_bank_bank_credit_recieve_liquidity_BankCreditLiquidtyRecieve_BankCreditIncomeStatement_debt_ack(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_debt_ack *m = (m_debt_ack*)msg;
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
int FLAME_sort_reagency_reagency_housing_process_REAgencyHousingProcess_REAgencyHousingSummary_sell_housing(const void *x, const void *y)
{
	if( ((m_sell_housing *)x)->price < ((m_sell_housing *)y)->price ) return -1;
	else if( ((m_sell_housing *)x)->price > ((m_sell_housing *)y)->price ) return 1;
	else return 0;
}
int FLAME_sort_reagency_reagency_housing_process_REAgencyHousingProcess_REAgencyHousingSummary_mortgaging_capacity(const void *x, const void *y)
{
	if( ((m_mortgaging_capacity *)x)->bank_id < ((m_mortgaging_capacity *)y)->bank_id ) return -1;
	else if( ((m_mortgaging_capacity *)x)->bank_id > ((m_mortgaging_capacity *)y)->bank_id ) return 1;
	else return 0;
}

