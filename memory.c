/**
 * \file  memory.c
 * \brief Holds memory functions.
 */

#include "header.h"


void unittest_firm_init_start_FirmCreditStart()
{
	
	
	//return firm_init();
}

void unittest_idle_FirmUpdateDeposits_end()
{
	
	
	//return idle();
}

void unittest_firm_update_bank_account_FirmUpdateDeposits_end()
{
	
	
	//return firm_update_bank_account();
}

void unittest_idle_FirmConsumptionStart_FirmHousingStart()
{
	
	
	//return idle();
}

void unittest_firm_consumption_supply_FirmConsumptionStart_FirmRecieveSales()
{
	
	
	//return firm_consumption_supply();
}

void unittest_firm_consumption_recieve_sales_FirmRecieveSales_FirmConsumptionPrice()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return firm_consumption_recieve_sales();
}

void unittest_firm_consumption_update_market_price_FirmConsumptionPrice_FirmHousingStart()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return firm_consumption_update_market_price();
}

void unittest_idle_FirmLabourStart_FirmLabourPayWages()
{
	
	
	//return idle();
}

void unittest_firm_labour_workforce_needed_FirmLabourStart_FirmLabourStage1()
{
	
	
	//return firm_labour_workforce_needed();
}

void unittest_idle_FirmLabourStage1_FirmLabourStage1End()
{
	
	
	//return idle();
}

void unittest_firm_labour_fire_FirmLabourStage1_FirmLabourStage1End()
{
	
	
	//return firm_labour_fire();
}

void unittest_firm_labour_job_announcement_stage1_FirmLabourStage1_FirmLabourStage1Application()
{
	
	
	//return firm_labour_job_announcement_stage1();
}

void unittest_firm_labour_job_offer_stage1_FirmLabourStage1Application_FirmLabourStage1End()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return firm_labour_job_offer_stage1();
}

void unittest_firm_labour_update_FirmLabourStage1End_FirmLabourStage2()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return firm_labour_update();
}

void unittest_firm_labour_job_announcement_stage2_FirmLabourStage2_FirmLabourStage2End()
{
	
	
	//return firm_labour_job_announcement_stage2();
}

void unittest_idle_FirmLabourStage2_FirmLabourPayWages()
{
	
	
	//return idle();
}

void unittest_firm_labour_job_offer_stage2_FirmLabourStage2End_FirmLabourPayWages()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return firm_labour_job_offer_stage2();
}

void unittest_idle_FirmLabourPayWages_FirmConsumptionStart()
{
	
	
	//return idle();
}

void unittest_firm_labour_pay_wages_FirmLabourPayWages_FirmLabourWageAdjustment()
{
	
	
	//return firm_labour_pay_wages();
}

void unittest_firm_labour_trace_wages_FirmLabourWageAdjustment_FirmConsumptionStart()
{
	
	
	//return firm_labour_trace_wages();
}

void unittest_idle_FirmProductionStart_FirmLabourStart()
{
	
	
	//return idle();
}

void unittest_idle_FirmProductionStart_FirmProductionSkip()
{
	
	
	//return idle();
}

void unittest_firm_production_skip_FirmProductionSkip_FirmLabourStart()
{
	
	
	//return firm_production_skip();
}

void unittest_idle_FirmProductionSkip_FirmProductionRoleCheck()
{
	
	
	//return idle();
}

void unittest_idle_FirmProductionRoleCheck_FirmProductionRegular()
{
	
	
	//return idle();
}

void unittest_idle_FirmProductionRoleCheck_FirmProductionConstructor()
{
	
	
	//return idle();
}

void unittest_firm_production_produce_goods_FirmProductionRegular_FirmLabourStart()
{
	
	
	//return firm_production_produce_goods();
}

void unittest_firm_production_set_price_FirmProductionRegular_FirmProductionPlanning()
{
	
	
	//return firm_production_set_price();
}

void unittest_firm_production_plan_FirmProductionPlanning_FirmProductionLabourDemand()
{
	
	
	//return firm_production_plan();
}

void unittest_firm_production_compute_labour_demand_FirmProductionLabourDemand_FirmLabourStart()
{
	
	
	//return firm_production_compute_labour_demand();
}

void unittest_firm_production_construct_houses_FirmProductionConstructor_FirmLabourStart()
{
	
	
	//return firm_production_construct_houses();
}

void unittest_firm_production_construction_plan_FirmProductionConstructor_FirmConstructionLabourDemand()
{
	
	
	//return firm_production_construction_plan();
}

void unittest_firm_production_construction_labour_demand_FirmConstructionLabourDemand_FirmLabourStart()
{
	
	
	//return firm_production_construction_labour_demand();
}

void unittest_idle_FirmCreditStart_FirmProductionStart()
{
	
	
	//return idle();
}

void unittest_firm_credit_compute_income_statement_FirmCreditStart_FirmCreditInterestRate()
{
	
	
	//return firm_credit_compute_income_statement();
}

void unittest_firm_credit_check_interest_rate_FirmCreditInterestRate_FirmCreditInvestment()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return firm_credit_check_interest_rate();
}

void unittest_firm_credit_investment_decisions_FirmCreditInvestment_FirmCreditComputeDividends()
{
	
	
	//return firm_credit_investment_decisions();
}

void unittest_firm_credit_compute_dividends_FirmCreditComputeDividends_FirmCreditLiquidityNeed()
{
	
	
	//return firm_credit_compute_dividends();
}

void unittest_firm_credit_check_liquidity_need_FirmCreditLiquidityNeed_FirmCreditStatus()
{
	
	
	//return firm_credit_check_liquidity_need();
}

void unittest_idle_FirmCreditStatus_FirmCreditPayments()
{
	
	
	//return idle();
}

void unittest_firm_credit_demand_loans_1_FirmCreditStatus_FirmCreditLoanBorrow1()
{
	
	
	//return firm_credit_demand_loans_1();
}

void unittest_firm_credit_borrow_loans_1_FirmCreditLoanBorrow1_FirmCreditLoanBorrow2()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return firm_credit_borrow_loans_1();
}

void unittest_idle_FirmCreditLoanBorrow2_FirmCreditPayments()
{
	
	
	//return idle();
}

void unittest_firm_credit_borrow_loans_2_FirmCreditLoanBorrow2_FirmCreditIlliquidityStatus()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return firm_credit_borrow_loans_2();
}

void unittest_idle_FirmCreditIlliquidityStatus_FirmCreditPayments()
{
	
	
	//return idle();
}

void unittest_firm_credit_request_equityfund_investment_FirmCreditIlliquidityStatus_FirmCreditCheckFundInvestment()
{
	
	
	//return firm_credit_request_equityfund_investment();
}

void unittest_firm_credit_check_equityfund_investment_FirmCreditCheckFundInvestment_FirmCreditBankruptcy()
{
	int rc;
	
	rc = MB_Iterator_CreateFiltered(b_fund_request_ack, &i_fund_request_ack, &FLAME_filter_firm_firm_credit_check_equityfund_investment_FirmCreditCheckFundInvestment_FirmCreditBankruptcy_fund_request_ack, current_xmachine_firm);
	
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
	   }
	}
	#endif
	
	//return firm_credit_check_equityfund_investment();
}

void unittest_idle_FirmCreditBankruptcy_FirmCreditPayments()
{
	
	
	//return idle();
}

void unittest_firm_credit_illiquidity_bankrupt_FirmCreditBankruptcy_FirmCreditBalanceSheet()
{
	
	
	//return firm_credit_illiquidity_bankrupt();
}

void unittest_firm_credit_pay_interest_on_loans_FirmCreditPayments_FirmCreditDividendPayments()
{
	
	
	//return firm_credit_pay_interest_on_loans();
}

void unittest_firm_credit_pay_dividends_FirmCreditDividendPayments_FirmCreditBalanceSheet()
{
	
	
	//return firm_credit_pay_dividends();
}

void unittest_firm_credit_do_balance_sheet_FirmCreditBalanceSheet_FirmCreditInsolvency()
{
	
	
	//return firm_credit_do_balance_sheet();
}

void unittest_firm_credit_exit_market_FirmCreditInsolvency_FirmProductionStart()
{
	
	
	//return firm_credit_exit_market();
}

void unittest_idle_FirmHousingStart_FirmUpdateDeposits()
{
	
	
	//return idle();
}

void unittest_idle_FirmHousingStart_FirmHousingMarket()
{
	
	
	//return idle();
}

void unittest_idle_FirmHousingMarket_FirmUpdateDeposits()
{
	
	
	//return idle();
}

void unittest_firm_housing_enter_market_FirmHousingMarket_FirmHousingSell()
{
	
	
	//return firm_housing_enter_market();
}

void unittest_firm_housing_collect_sale_revenues_FirmHousingSell_FirmHousingPrice()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return firm_housing_collect_sale_revenues();
}

void unittest_firm_housing_update_market_price_FirmHousingPrice_FirmUpdateDeposits()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return firm_housing_update_market_price();
}

void unittest_household_init_start_HHCreditStart()
{
	
	
	//return household_init();
}

void unittest_idle_HouseholdUpdateDeposits_end()
{
	
	
	//return idle();
}

void unittest_household_update_bank_account_HouseholdUpdateDeposits_end()
{
	
	
	//return household_update_bank_account();
}

void unittest_idle_HHConsumptionStart_HHConsumptionWeekly()
{
	
	
	//return idle();
}

void unittest_household_consumption_compute_budget_HHConsumptionStart_HHConsumptionWeekly()
{
	
	
	//return household_consumption_compute_budget();
}

void unittest_idle_HHConsumptionWeekly_HHHousingStart()
{
	
	
	//return idle();
}

void unittest_household_consumption_demand_HHConsumptionWeekly_HHConsumptionRecieveGoods()
{
	
	
	//return household_consumption_demand();
}

void unittest_household_consumption_recieve_goods_HHConsumptionRecieveGoods_HHHousingStart()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return household_consumption_recieve_goods();
}

void unittest_idle_HHLabourStart_HHLabourEmploymentStatus()
{
	
	
	//return idle();
}

void unittest_household_labour_check_fired_HHLabourStart_HHLabourStage1()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return household_labour_check_fired();
}

void unittest_household_labour_reemployment_application_HHLabourStage1_HHLabourStage2()
{
	
	
	//return household_labour_reemployment_application();
}

void unittest_idle_HHLabourStage1_HHLabourStage1Applications()
{
	
	
	//return idle();
}

void unittest_household_labour_turnover_HHLabourStage2_HHLabourEmploymentStatus()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return household_labour_turnover();
}

void unittest_household_labour_employment_application_HHLabourStage1Applications_HHLabourStage1Placement()
{
	
	
	//return household_labour_employment_application();
}

void unittest_household_labour_employment_HHLabourStage1Placement_HHLabourEmploymentStatus()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return household_labour_employment();
}

void unittest_household_labour_report_status_HHLabourEmploymentStatus_HHLabourPayroll()
{
	
	
	//return household_labour_report_status();
}

void unittest_idle_HHLabourPayroll_HHConsumptionStart()
{
	
	
	//return idle();
}

void unittest_household_labour_recieve_wage_HHLabourPayroll_HHConsumptionStart()
{
	
	
	//return household_labour_recieve_wage();
}

void unittest_idle_HHCreditStart_HHCreditMonthly()
{
	
	
	//return idle();
}

void unittest_household_credit_check_interest_rate_HHCreditStart_HHCreditCheckTax()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return household_credit_check_interest_rate();
}

void unittest_household_credit_check_tax_rate_HHCreditCheckTax_HHCreditUpdateMortgages()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return household_credit_check_tax_rate();
}

void unittest_household_credit_update_mortgage_rates_HHCreditUpdateMortgages_HHCreditIsCapitalist()
{
	
	
	//return household_credit_update_mortgage_rates();
}

void unittest_idle_HHCreditIsCapitalist_HHCreditBalanceSheet()
{
	
	
	//return idle();
}

void unittest_household_credit_collect_shares_HHCreditIsCapitalist_HHCreditCapitalTax()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return household_credit_collect_shares();
}

void unittest_household_credit_pay_capital_tax_HHCreditCapitalTax_HHCreditBalanceSheet()
{
	
	
	//return household_credit_pay_capital_tax();
}

void unittest_household_credit_do_balance_sheet_HHCreditBalanceSheet_HHCreditMonthly()
{
	
	
	//return household_credit_do_balance_sheet();
}

void unittest_idle_HHCreditMonthly_HHLabourStart()
{
	
	
	//return idle();
}

void unittest_household_credit_collect_benefits_HHCreditMonthly_HHCreditEmployment()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return household_credit_collect_benefits();
}

void unittest_household_credit_collect_unemployment_HHCreditEmployment_HHLabourStart()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return household_credit_collect_unemployment();
}

void unittest_household_credit_pay_labour_tax_HHCreditEmployment_HHLabourStart()
{
	
	
	//return household_credit_pay_labour_tax();
}

void unittest_idle_HHHousingStart_HouseholdUpdateDeposits()
{
	
	
	//return idle();
}

void unittest_household_housing_market_role_HHHousingStart_HHHousingRole()
{
	
	
	//return household_housing_market_role();
}

void unittest_idle_HHHousingRole_HHHousingPrice()
{
	
	
	//return idle();
}

void unittest_household_housing_check_wealth_HHHousingRole_HHHousingCheckWealth()
{
	
	
	//return household_housing_check_wealth();
}

void unittest_household_housing_sell_HHHousingRole_HHHousingRevenue()
{
	
	
	//return household_housing_sell();
}

void unittest_household_housing_fire_sell_HHHousingRole_HHHousingRevenue()
{
	
	
	//return household_housing_fire_sell();
}

void unittest_household_housing_collect_sale_revenue_HHHousingRevenue_HHHousingPrice()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return household_housing_collect_sale_revenue();
}

void unittest_idle_HHHousingCheckWealth_HHHousingPrice()
{
	
	
	//return idle();
}

void unittest_household_housing_enter_market_HHHousingCheckWealth_HHHousingBargain()
{
	
	
	//return household_housing_enter_market();
}

void unittest_household_housing_buy_HHHousingBargain_HHHousingPrice()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return household_housing_buy();
}

void unittest_household_housing_update_market_price_HHHousingPrice_HHHousingPayments()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return household_housing_update_market_price();
}

void unittest_household_housing_pay_mortgages_HHHousingPayments_HHHousingWriteOff()
{
	
	
	//return household_housing_pay_mortgages();
}

void unittest_household_housing_debt_writeoff_HHHousingWriteOff_HouseholdUpdateDeposits()
{
	
	
	//return household_housing_debt_writeoff();
}

void unittest_equityfund_init_start_EquityFundStart()
{
	
	
	//return equityfund_init();
}

void unittest_idle_EFLabourMarket_end()
{
	
	
	//return idle();
}

void unittest_equityfund_audit_dividends_EFLabourMarket_end()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return equityfund_audit_dividends();
}

void unittest_idle_EquityFundStart_EFLabourMarket()
{
	
	
	//return idle();
}

void unittest_equityfund_credit_invest_illiquids_EquityFundStart_EFCreditDistributeShares()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return equityfund_credit_invest_illiquids();
}

void unittest_equityfund_credit_distribute_shares_EFCreditDistributeShares_EFCreditShareCollectionBanks()
{
	
	
	//return equityfund_credit_distribute_shares();
}

void unittest_equityfund_credit_collect_bank_shares_EFCreditShareCollectionBanks_EFCreditShareCollectionFirms()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return equityfund_credit_collect_bank_shares();
}

void unittest_equityfund_credit_collect_firm_shares_EFCreditShareCollectionFirms_EFCreditBalanceSheet()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return equityfund_credit_collect_firm_shares();
}

void unittest_equityfund_credit_do_balance_sheet_EFCreditBalanceSheet_EFLabourMarket()
{
	
	
	//return equityfund_credit_do_balance_sheet();
}

void unittest_bank_init_start_BankCreditStart()
{
	
	
	//return bank_init();
}

void unittest_idle_BankUpdateDeposits_end()
{
	
	
	//return idle();
}

void unittest_bank_update_deposits_BankUpdateDeposits_end()
{
	int rc;
	
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
	   }
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
	   }
	}
	#endif
	
	//return bank_update_deposits();
}

void unittest_idle_BankCreditStart_BankHousingMarket()
{
	
	
	//return idle();
}

void unittest_bank_credit_process_loan_requests_1_BankCreditStart_BankCreditRequest2()
{
	int rc;
	
	rc = MB_Iterator_CreateFiltered(b_loan_request_1, &i_loan_request_1, &FLAME_filter_bank_bank_credit_process_loan_requests_1_BankCreditStart_BankCreditRequest2_loan_request_1, current_xmachine_bank);
	
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
	   }
	}
	#endif
	
	//return bank_credit_process_loan_requests_1();
}

void unittest_bank_credit_process_loan_requests_2_BankCreditRequest2_BankCreditLoanWriteOffs()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return bank_credit_process_loan_requests_2();
}

void unittest_bank_credit_recieve_loan_writeoffs_BankCreditLoanWriteOffs_BankCreditNewEntrants()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return bank_credit_recieve_loan_writeoffs();
}

void unittest_bank_credit_recieve_new_entrant_loan_requests_BankCreditNewEntrants_BankCreditLoanInterests()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return bank_credit_recieve_new_entrant_loan_requests();
}

void unittest_bank_credit_collect_loan_interests_BankCreditLoanInterests_BankCreditLiquidityNeed()
{
	int rc;
	
	rc = MB_Iterator_CreateFiltered(b_interest_on_loan, &i_interest_on_loan, &FLAME_filter_bank_bank_credit_collect_loan_interests_BankCreditLoanInterests_BankCreditLiquidityNeed_interest_on_loan, current_xmachine_bank);
	
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
	   }
	}
	#endif
	
	//return bank_credit_collect_loan_interests();
}

void unittest_idle_BankCreditLiquidityNeed_BankCreditIncomeStatement()
{
	
	
	//return idle();
}

void unittest_bank_credit_request_liquidity_BankCreditLiquidityNeed_BankCreditLiquidtyRecieve()
{
	
	
	//return bank_credit_request_liquidity();
}

void unittest_bank_credit_recieve_liquidity_BankCreditLiquidtyRecieve_BankCreditIncomeStatement()
{
	int rc;
	
	rc = MB_Iterator_CreateFiltered(b_debt_ack, &i_debt_ack, &FLAME_filter_bank_bank_credit_recieve_liquidity_BankCreditLiquidtyRecieve_BankCreditIncomeStatement_debt_ack, current_xmachine_bank);
	
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'debt_ack'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'debt_ack' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'debt_ack' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return bank_credit_recieve_liquidity();
}

void unittest_bank_credit_compute_income_statement_BankCreditIncomeStatement_BankCreditDividends()
{
	
	
	//return bank_credit_compute_income_statement();
}

void unittest_bank_credit_compute_dividends_BankCreditDividends_BankCreditBalanceSheet()
{
	
	
	//return bank_credit_compute_dividends();
}

void unittest_bank_credit_do_balance_sheet_BankCreditBalanceSheet_BankHousingMarket()
{
	
	
	//return bank_credit_do_balance_sheet();
}

void unittest_idle_BankHousingMarket_BankUpdateDeposits()
{
	
	
	//return idle();
}

void unittest_bank_housing_compute_capital_status_BankHousingMarket_BankHousingCrediting()
{
	
	
	//return bank_housing_compute_capital_status();
}

void unittest_bank_housing_deliver_mortages_BankHousingCrediting_BankHousingSales()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return bank_housing_deliver_mortages();
}

void unittest_bank_housing_recieve_mortgage_principals_BankHousingSales_BankHousingMortgages()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return bank_housing_recieve_mortgage_principals();
}

void unittest_bank_housing_recieve_mortgages_BankHousingMortgages_BankHousingWriteOff()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return bank_housing_recieve_mortgages();
}

void unittest_bank_housing_debt_writeoff_BankHousingWriteOff_BankUpdateDeposits()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return bank_housing_debt_writeoff();
}

void unittest_government_init_start_GovernmentStart()
{
	
	
	//return government_init();
}

void unittest_government_trace_unemployment_status_GovernmentLabourStatus_end()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return government_trace_unemployment_status();
}

void unittest_idle_GovernmentStart_GovernmentMonthly()
{
	
	
	//return idle();
}

void unittest_government_update_fiscal_policy_GovernmentStart_GovernmentCapitalTax()
{
	
	
	//return government_update_fiscal_policy();
}

void unittest_government_collect_capital_tax_GovernmentCapitalTax_GovernmentIncomeStatement()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return government_collect_capital_tax();
}

void unittest_government_compute_income_statement_GovernmentIncomeStatement_GovernmentBalanceSheet()
{
	
	
	//return government_compute_income_statement();
}

void unittest_government_do_balance_sheet_GovernmentBalanceSheet_GovernmentMonthly()
{
	
	
	//return government_do_balance_sheet();
}

void unittest_idle_GovernmentMonthly_end()
{
	
	
	//return idle();
}

void unittest_government_distribute_general_benefits_GovernmentMonthly_GovernmentUnemploymentBenefits()
{
	
	
	//return government_distribute_general_benefits();
}

void unittest_government_distribute_unemployment_benefits_GovernmentUnemploymentBenefits_GovernmentLabourTax()
{
	
	
	//return government_distribute_unemployment_benefits();
}

void unittest_government_collect_labour_tax_GovernmentLabourTax_GovernmentLabourStatus()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return government_collect_labour_tax();
}

void unittest_centralbank_init_start_CentralBankCredit()
{
	
	
	//return centralbank_init();
}

void unittest_idle_CentralBankConsumption_CentralBankHousing()
{
	
	
	//return idle();
}

void unittest_centralbank_trace_goods_prices_CentralBankConsumption_CentralBankHousing()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return centralbank_trace_goods_prices();
}

void unittest_idle_CentralBankLabour_CentralBankConsumption()
{
	
	
	//return idle();
}

void unittest_centralbank_trace_unemployment_status_CentralBankLabour_CentralBankConsumption()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return centralbank_trace_unemployment_status();
}

void unittest_idle_CentralBankCredit_CentralBankLabour()
{
	
	
	//return idle();
}

void unittest_centralbank_set_interest_rate_CentralBankCredit_CentralBankDebtRequests()
{
	
	
	//return centralbank_set_interest_rate();
}

void unittest_centralbank_process_debt_requests_CentralBankDebtRequests_CentralBankIncomeStatement()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return centralbank_process_debt_requests();
}

void unittest_centralbank_compute_income_statement_CentralBankIncomeStatement_CentralBankBalanceSheet()
{
	
	
	//return centralbank_compute_income_statement();
}

void unittest_centralbank_do_balance_sheet_CentralBankBalanceSheet_CentralBankLabour()
{
	
	
	//return centralbank_do_balance_sheet();
}

void unittest_idle_CentralBankHousing_end()
{
	
	
	//return idle();
}

void unittest_centralbank_trace_housing_prices_CentralBankHousing_end()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return centralbank_trace_housing_prices();
}

void unittest_jpoffice_init_start_JPOLabourMarket()
{
	
	
	//return jpoffice_init();
}

void unittest_idle_JPOLabourMarket_end()
{
	
	
	//return idle();
}

void unittest_jpoffice_labour_stage1_JPOLabourMarket_JPOLabourStage2()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_vacancy_stage1, &i_vacancy_stage1);
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
	   }
	}
	#endif
	
	
	rc = MB_Iterator_Create(b_job_application_stage1, &i_job_application_stage1);
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
	   }
	}
	#endif
	
	//return jpoffice_labour_stage1();
}

void unittest_jpoffice_labour_stage2_JPOLabourStage2_end()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_vacancy_stage2, &i_vacancy_stage2);
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
	   }
	}
	#endif
	
	
	rc = MB_Iterator_Create(b_job_application_stage2, &i_job_application_stage2);
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
	   }
	}
	#endif
	
	//return jpoffice_labour_stage2();
}

void unittest_mall_init_start_MallConsumptionMarket()
{
	
	
	//return mall_init();
}

void unittest_idle_MallConsumptionMarket_end()
{
	
	
	//return idle();
}

void unittest_mall_consumption_shopping_MallConsumptionMarket_MallConsumptionSummary()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_sell, &i_sell);
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
	   }
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
	   }
	}
	#endif
	
	//return mall_consumption_shopping();
}

void unittest_mall_consumption_summary_MallConsumptionSummary_end()
{
	
	
	//return mall_consumption_summary();
}

void unittest_reagency_init_start_REAgencyHousingMarket()
{
	
	
	//return reagency_init();
}

void unittest_idle_REAgencyHousingMarket_end()
{
	
	
	//return idle();
}

void unittest_reagency_housing_check_interest_rate_REAgencyHousingMarket_REAgencyHousingProcess()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	//return reagency_housing_check_interest_rate();
}

void unittest_reagency_housing_process_REAgencyHousingProcess_REAgencyHousingSummary()
{
	int rc;
	
	
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
	   }
	}
	#endif
	
	
	rc = MB_Iterator_Create(b_sell_housing, &i_sell_housing);
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
	   }
	}
	#endif
	
	
	rc = MB_Iterator_Create(b_mortgaging_capacity, &i_mortgaging_capacity);
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
	   }
	}
	#endif
	
	//return reagency_housing_process();
}

void unittest_reagency_housing_summary_REAgencyHousingSummary_end()
{
	
	
	//return reagency_housing_summary();
}


void free_messages()
{
	int rc;
	
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
	
	    rc = MB_Clear(b_debt_ack);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'debt_ack' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'debt_ack' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'debt_ack' board is locked\n");
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
	
}

/** \fn void initialise_pointers()
 * \brief Initialises pointers to xmachine, message, and node lists.
 */
void initialise_pointers()
{
int rc;

	/* Initialise message sync composite params as NULL */
	FLAME_m_firm_bank_update_deposit_composite_params = NULL;

	    rc = MB_Create(&b_firm_bank_update_deposit, sizeof(m_firm_bank_update_deposit));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'firm_bank_update_deposit' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_household_bank_update_deposit_composite_params = NULL;

	    rc = MB_Create(&b_household_bank_update_deposit, sizeof(m_household_bank_update_deposit));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'household_bank_update_deposit' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_interest_rate_composite_params = NULL;

	    rc = MB_Create(&b_interest_rate, sizeof(m_interest_rate));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'interest_rate' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_buy_composite_params = NULL;

	    rc = MB_Create(&b_buy, sizeof(m_buy));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'buy' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_bought_composite_params = NULL;

	    rc = MB_Create(&b_bought, sizeof(m_bought));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'bought' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_sell_composite_params = NULL;

	    rc = MB_Create(&b_sell, sizeof(m_sell));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'sell' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_sold_composite_params = NULL;

	    rc = MB_Create(&b_sold, sizeof(m_sold));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'sold' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_goods_transactions_summary_composite_params = NULL;

	    rc = MB_Create(&b_goods_transactions_summary, sizeof(m_goods_transactions_summary));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'goods_transactions_summary' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_fired_composite_params = NULL;

	    rc = MB_Create(&b_fired, sizeof(m_fired));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'fired' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_vacancy_stage1_composite_params = NULL;

	    rc = MB_Create(&b_vacancy_stage1, sizeof(m_vacancy_stage1));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'vacancy_stage1' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_job_application_stage2_composite_params = NULL;

	    rc = MB_Create(&b_job_application_stage2, sizeof(m_job_application_stage2));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'job_application_stage2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_job_application_stage1_composite_params = NULL;

	    rc = MB_Create(&b_job_application_stage1, sizeof(m_job_application_stage1));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'job_application_stage1' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_job_match_stage1_composite_params = NULL;

	    rc = MB_Create(&b_job_match_stage1, sizeof(m_job_match_stage1));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'job_match_stage1' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_job_change_composite_params = NULL;

	    rc = MB_Create(&b_job_change, sizeof(m_job_change));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'job_change' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_vacancy_stage2_composite_params = NULL;

	    rc = MB_Create(&b_vacancy_stage2, sizeof(m_vacancy_stage2));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'vacancy_stage2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_job_match_stage2_composite_params = NULL;

	    rc = MB_Create(&b_job_match_stage2, sizeof(m_job_match_stage2));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'job_match_stage2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_employment_status_composite_params = NULL;

	    rc = MB_Create(&b_employment_status, sizeof(m_employment_status));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'employment_status' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_loan_request_1_composite_params = NULL;

	    rc = MB_Create(&b_loan_request_1, sizeof(m_loan_request_1));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'loan_request_1' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_loan_request_2_composite_params = NULL;

	    rc = MB_Create(&b_loan_request_2, sizeof(m_loan_request_2));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'loan_request_2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_loan_acknowledge_1_composite_params = NULL;

	    rc = MB_Create(&b_loan_acknowledge_1, sizeof(m_loan_acknowledge_1));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'loan_acknowledge_1' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_loan_acknowledge_2_composite_params = NULL;

	    rc = MB_Create(&b_loan_acknowledge_2, sizeof(m_loan_acknowledge_2));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'loan_acknowledge_2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_debt_request_composite_params = NULL;

	    rc = MB_Create(&b_debt_request, sizeof(m_debt_request));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'debt_request' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_debt_ack_composite_params = NULL;

	    rc = MB_Create(&b_debt_ack, sizeof(m_debt_ack));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'debt_ack' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_household_share_composite_params = NULL;

	    rc = MB_Create(&b_household_share, sizeof(m_household_share));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'household_share' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_capital_tax_composite_params = NULL;

	    rc = MB_Create(&b_capital_tax, sizeof(m_capital_tax));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'capital_tax' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_labour_tax_composite_params = NULL;

	    rc = MB_Create(&b_labour_tax, sizeof(m_labour_tax));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'labour_tax' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_unemployment_benefit_composite_params = NULL;

	    rc = MB_Create(&b_unemployment_benefit, sizeof(m_unemployment_benefit));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'unemployment_benefit' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_general_benefit_composite_params = NULL;

	    rc = MB_Create(&b_general_benefit, sizeof(m_general_benefit));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'general_benefit' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_tax_rate_composite_params = NULL;

	    rc = MB_Create(&b_tax_rate, sizeof(m_tax_rate));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'tax_rate' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_fund_request_composite_params = NULL;

	    rc = MB_Create(&b_fund_request, sizeof(m_fund_request));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'fund_request' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_fund_request_ack_composite_params = NULL;

	    rc = MB_Create(&b_fund_request_ack, sizeof(m_fund_request_ack));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'fund_request_ack' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_new_entrant_loan_composite_params = NULL;

	    rc = MB_Create(&b_new_entrant_loan, sizeof(m_new_entrant_loan));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'new_entrant_loan' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_interest_on_loan_composite_params = NULL;

	    rc = MB_Create(&b_interest_on_loan, sizeof(m_interest_on_loan));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'interest_on_loan' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_loan_writeoff_composite_params = NULL;

	    rc = MB_Create(&b_loan_writeoff, sizeof(m_loan_writeoff));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'loan_writeoff' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_firm_net_profit_composite_params = NULL;

	    rc = MB_Create(&b_firm_net_profit, sizeof(m_firm_net_profit));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'firm_net_profit' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_bank_net_profit_composite_params = NULL;

	    rc = MB_Create(&b_bank_net_profit, sizeof(m_bank_net_profit));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'bank_net_profit' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_housing_price_composite_params = NULL;

	    rc = MB_Create(&b_housing_price, sizeof(m_housing_price));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'housing_price' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_buy_housing_composite_params = NULL;

	    rc = MB_Create(&b_buy_housing, sizeof(m_buy_housing));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'buy_housing' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_sell_housing_composite_params = NULL;

	    rc = MB_Create(&b_sell_housing, sizeof(m_sell_housing));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'sell_housing' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_bought_housing_composite_params = NULL;

	    rc = MB_Create(&b_bought_housing, sizeof(m_bought_housing));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'bought_housing' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_sold_housing_composite_params = NULL;

	    rc = MB_Create(&b_sold_housing, sizeof(m_sold_housing));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'sold_housing' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_mortgaging_capacity_composite_params = NULL;

	    rc = MB_Create(&b_mortgaging_capacity, sizeof(m_mortgaging_capacity));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'mortgaging_capacity' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_mortgage_requests_composite_params = NULL;

	    rc = MB_Create(&b_mortgage_requests, sizeof(m_mortgage_requests));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'mortgage_requests' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_mortgage_payment_from_sale_composite_params = NULL;

	    rc = MB_Create(&b_mortgage_payment_from_sale, sizeof(m_mortgage_payment_from_sale));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'mortgage_payment_from_sale' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_mortgage_payment_composite_params = NULL;

	    rc = MB_Create(&b_mortgage_payment, sizeof(m_mortgage_payment));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'mortgage_payment' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_mortgage_writeoff_composite_params = NULL;

	    rc = MB_Create(&b_mortgage_writeoff, sizeof(m_mortgage_writeoff));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'mortgage_writeoff' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_housing_transactions_summary_composite_params = NULL;

	    rc = MB_Create(&b_housing_transactions_summary, sizeof(m_housing_transactions_summary));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'housing_transactions_summary' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	firm_FirmHousingPrice_state = init_firm_state();

	firm_FirmHousingSell_state = init_firm_state();

	firm_FirmHousingMarket_state = init_firm_state();

	firm_FirmCreditInsolvency_state = init_firm_state();

	firm_FirmCreditDividendPayments_state = init_firm_state();

	firm_FirmCreditBalanceSheet_state = init_firm_state();

	firm_FirmCreditBankruptcy_state = init_firm_state();

	firm_FirmCreditCheckFundInvestment_state = init_firm_state();

	firm_FirmCreditIlliquidityStatus_state = init_firm_state();

	firm_FirmCreditLoanBorrow2_state = init_firm_state();

	firm_FirmCreditLoanBorrow1_state = init_firm_state();

	firm_FirmCreditPayments_state = init_firm_state();

	firm_FirmCreditStatus_state = init_firm_state();

	firm_FirmCreditLiquidityNeed_state = init_firm_state();

	firm_FirmCreditComputeDividends_state = init_firm_state();

	firm_FirmCreditInvestment_state = init_firm_state();

	firm_FirmCreditInterestRate_state = init_firm_state();

	firm_FirmConstructionLabourDemand_state = init_firm_state();

	firm_FirmProductionLabourDemand_state = init_firm_state();

	firm_FirmProductionPlanning_state = init_firm_state();

	firm_FirmProductionConstructor_state = init_firm_state();

	firm_FirmProductionRegular_state = init_firm_state();

	firm_FirmProductionRoleCheck_state = init_firm_state();

	firm_FirmProductionSkip_state = init_firm_state();

	firm_FirmProductionStart_state = init_firm_state();

	firm_FirmLabourWageAdjustment_state = init_firm_state();

	firm_FirmLabourStage2End_state = init_firm_state();

	firm_FirmLabourStage2_state = init_firm_state();

	firm_FirmLabourStage1Application_state = init_firm_state();

	firm_FirmLabourStage1End_state = init_firm_state();

	firm_FirmLabourStage1_state = init_firm_state();

	firm_FirmLabourPayWages_state = init_firm_state();

	firm_FirmLabourStart_state = init_firm_state();

	firm_FirmConsumptionPrice_state = init_firm_state();

	firm_FirmRecieveSales_state = init_firm_state();

	firm_FirmHousingStart_state = init_firm_state();

	firm_FirmConsumptionStart_state = init_firm_state();

	firm_end_state = init_firm_state();

	firm_FirmUpdateDeposits_state = init_firm_state();

	firm_FirmCreditStart_state = init_firm_state();

	firm_start_state = init_firm_state();

	household_HHHousingWriteOff_state = init_household_state();

	household_HHHousingPayments_state = init_household_state();

	household_HHHousingBargain_state = init_household_state();

	household_HHHousingRevenue_state = init_household_state();

	household_HHHousingCheckWealth_state = init_household_state();

	household_HHHousingPrice_state = init_household_state();

	household_HHHousingRole_state = init_household_state();

	household_HHCreditEmployment_state = init_household_state();

	household_HHCreditCapitalTax_state = init_household_state();

	household_HHCreditBalanceSheet_state = init_household_state();

	household_HHCreditIsCapitalist_state = init_household_state();

	household_HHCreditUpdateMortgages_state = init_household_state();

	household_HHCreditCheckTax_state = init_household_state();

	household_HHCreditMonthly_state = init_household_state();

	household_HHLabourPayroll_state = init_household_state();

	household_HHLabourStage1Placement_state = init_household_state();

	household_HHLabourStage1Applications_state = init_household_state();

	household_HHLabourStage2_state = init_household_state();

	household_HHLabourStage1_state = init_household_state();

	household_HHLabourEmploymentStatus_state = init_household_state();

	household_HHLabourStart_state = init_household_state();

	household_HHConsumptionRecieveGoods_state = init_household_state();

	household_HHHousingStart_state = init_household_state();

	household_HHConsumptionWeekly_state = init_household_state();

	household_HHConsumptionStart_state = init_household_state();

	household_end_state = init_household_state();

	household_HouseholdUpdateDeposits_state = init_household_state();

	household_HHCreditStart_state = init_household_state();

	household_start_state = init_household_state();

	equityfund_EFCreditBalanceSheet_state = init_equityfund_state();

	equityfund_EFCreditShareCollectionFirms_state = init_equityfund_state();

	equityfund_EFCreditShareCollectionBanks_state = init_equityfund_state();

	equityfund_EFCreditDistributeShares_state = init_equityfund_state();

	equityfund_end_state = init_equityfund_state();

	equityfund_EFLabourMarket_state = init_equityfund_state();

	equityfund_EquityFundStart_state = init_equityfund_state();

	equityfund_start_state = init_equityfund_state();

	bank_BankHousingWriteOff_state = init_bank_state();

	bank_BankHousingMortgages_state = init_bank_state();

	bank_BankHousingSales_state = init_bank_state();

	bank_BankHousingCrediting_state = init_bank_state();

	bank_BankCreditBalanceSheet_state = init_bank_state();

	bank_BankCreditDividends_state = init_bank_state();

	bank_BankCreditLiquidtyRecieve_state = init_bank_state();

	bank_BankCreditIncomeStatement_state = init_bank_state();

	bank_BankCreditLiquidityNeed_state = init_bank_state();

	bank_BankCreditLoanInterests_state = init_bank_state();

	bank_BankCreditNewEntrants_state = init_bank_state();

	bank_BankCreditLoanWriteOffs_state = init_bank_state();

	bank_BankCreditRequest2_state = init_bank_state();

	bank_BankHousingMarket_state = init_bank_state();

	bank_end_state = init_bank_state();

	bank_BankUpdateDeposits_state = init_bank_state();

	bank_BankCreditStart_state = init_bank_state();

	bank_start_state = init_bank_state();

	government_GovernmentLabourTax_state = init_government_state();

	government_GovernmentUnemploymentBenefits_state = init_government_state();

	government_GovernmentBalanceSheet_state = init_government_state();

	government_GovernmentIncomeStatement_state = init_government_state();

	government_GovernmentCapitalTax_state = init_government_state();

	government_GovernmentMonthly_state = init_government_state();

	government_end_state = init_government_state();

	government_GovernmentLabourStatus_state = init_government_state();

	government_GovernmentStart_state = init_government_state();

	government_start_state = init_government_state();

	centralbank_end_state = init_centralbank_state();

	centralbank_CentralBankBalanceSheet_state = init_centralbank_state();

	centralbank_CentralBankIncomeStatement_state = init_centralbank_state();

	centralbank_CentralBankDebtRequests_state = init_centralbank_state();

	centralbank_CentralBankLabour_state = init_centralbank_state();

	centralbank_CentralBankHousing_state = init_centralbank_state();

	centralbank_CentralBankConsumption_state = init_centralbank_state();

	centralbank_CentralBankCredit_state = init_centralbank_state();

	centralbank_start_state = init_centralbank_state();

	jpoffice_JPOLabourStage2_state = init_jpoffice_state();

	jpoffice_end_state = init_jpoffice_state();

	jpoffice_JPOLabourMarket_state = init_jpoffice_state();

	jpoffice_start_state = init_jpoffice_state();

	mall_MallConsumptionSummary_state = init_mall_state();

	mall_end_state = init_mall_state();

	mall_MallConsumptionMarket_state = init_mall_state();

	mall_start_state = init_mall_state();

	reagency_REAgencyHousingSummary_state = init_reagency_state();

	reagency_REAgencyHousingProcess_state = init_reagency_state();

	reagency_end_state = init_reagency_state();

	reagency_REAgencyHousingMarket_state = init_reagency_state();

	reagency_start_state = init_reagency_state();

	temp_node_info = NULL;
	p_node_info = &temp_node_info;
}

/** \fn void initialise_unit_testing()
 * \brief Initialises framework for unit testing.
 */
void initialise_unit_testing()
{
	int rc;

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

	initialise_pointers();
}

FLAME_output * add_FLAME_output(FLAME_output ** outputs)
{
	FLAME_output * current;

	current = (FLAME_output *)malloc(sizeof(FLAME_output));
	CHECK_POINTER(current);
	current->next = *outputs;
	*outputs = current;

	current->type = -1;
	current->format = -1;
	current->location = NULL;
	current->period = -1;
	current->phase = -1;
	current->flag = 0;

	return current;
}

void free_FLAME_outputs(FLAME_output ** outputs)
{
	FLAME_output * current, * next;

	current = *outputs;
	while(current)
	{
		next = current->next;
		free(current->location);
		free(current);
		current = next;
	}
	*outputs = NULL;
}

/* add_location */
/** \fn void add_location(double point, location ** p_location)
 * \brief Adds a location in order into the location list.
 * \param point Position of an agent.
 * \param p_location Pointer Pointer to the location list.
 */
void add_location(double point, location ** p_location)
{
	location * current = *p_location;
	location * tmp = NULL;
	location * newlocation = NULL;
	int found = 0;

	while(found == 0)
	{
		if(current == NULL) found = 1;
		else if(point > current->point) found = 1;
		else
		{
			tmp = current;
			current = current->next;
		}
	}

	newlocation = (location *)malloc(sizeof(location));
	CHECK_POINTER(newlocation);
	if(tmp)
	{
		tmp->next = newlocation;
	}
	else
	{
		*p_location = newlocation;
	}

	newlocation->next = current;
	newlocation->point = point;
}

/* freelocations */
/** \fn void freelocations(location ** p_location)
 * \brief Free locations from the location list.
 * \param p_location Pointer Pointer to the location list.
 */
void freelocations(location ** p_location)
{
	location * head = *p_location;
	location * tmp = NULL;

	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}

	*p_location = NULL;
}

void init_int_static_array(/*@out@*/ int * array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = 0;
}

void init_float_static_array(/*@out@*/ float * array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = 0.0;
}

void init_double_static_array(/*@out@*/ double* array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = 0.0;
}

void init_char_static_array(/*@out@*/ char * array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = '\0';
}



void init_transaction(/*@out@*/ transaction * temp)
{
	(*temp).quantity = 0;
	(*temp).avg_price = 0.0;

}

void init_transaction_static_array(/*@out@*/ transaction * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_transaction(&array[i]);
}

void free_transaction(transaction * temp)
{

}

void free_transaction_static_array(transaction * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_transaction(&array[i]);
}

void copy_transaction(transaction * from, transaction * to)
{
	(*to).quantity = (*from).quantity;
	(*to).avg_price = (*from).avg_price;
}

void copy_transaction_static_array(transaction * from, transaction * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_transaction(&from[i], &to[i]);
	}
}


void init_buyer(/*@out@*/ buyer * temp)
{
	(*temp).id = 0;
	(*temp).budget = 0.0;
	(*temp).recieved_quantity = 0;

}

void init_buyer_static_array(/*@out@*/ buyer * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_buyer(&array[i]);
}

void free_buyer(buyer * temp)
{

}

void free_buyer_static_array(buyer * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_buyer(&array[i]);
}

void copy_buyer(buyer * from, buyer * to)
{
	(*to).id = (*from).id;
	(*to).budget = (*from).budget;
	(*to).recieved_quantity = (*from).recieved_quantity;
}

void copy_buyer_static_array(buyer * from, buyer * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_buyer(&from[i], &to[i]);
	}
}


void init_seller(/*@out@*/ seller * temp)
{
	(*temp).id = 0;
	(*temp).price = 0.0;
	(*temp).inventory = 0;

}

void init_seller_static_array(/*@out@*/ seller * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_seller(&array[i]);
}

void free_seller(seller * temp)
{

}

void free_seller_static_array(seller * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_seller(&array[i]);
}

void copy_seller(seller * from, seller * to)
{
	(*to).id = (*from).id;
	(*to).price = (*from).price;
	(*to).inventory = (*from).inventory;
}

void copy_seller_static_array(seller * from, seller * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_seller(&from[i], &to[i]);
	}
}


void init_vacancy(/*@out@*/ vacancy * temp)
{
	(*temp).id = 0;
	(*temp).wage = 0.0;

}

void init_vacancy_static_array(/*@out@*/ vacancy * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_vacancy(&array[i]);
}

void free_vacancy(vacancy * temp)
{

}

void free_vacancy_static_array(vacancy * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_vacancy(&array[i]);
}

void copy_vacancy(vacancy * from, vacancy * to)
{
	(*to).id = (*from).id;
	(*to).wage = (*from).wage;
}

void copy_vacancy_static_array(vacancy * from, vacancy * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_vacancy(&from[i], &to[i]);
	}
}


void init_employee(/*@out@*/ employee * temp)
{
	(*temp).id = 0;
	(*temp).wage = 0.0;

}

void init_employee_static_array(/*@out@*/ employee * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_employee(&array[i]);
}

void free_employee(employee * temp)
{

}

void free_employee_static_array(employee * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_employee(&array[i]);
}

void copy_employee(employee * from, employee * to)
{
	(*to).id = (*from).id;
	(*to).wage = (*from).wage;
}

void copy_employee_static_array(employee * from, employee * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_employee(&from[i], &to[i]);
	}
}


void init_mortgage(/*@out@*/ mortgage * temp)
{
	(*temp).bank_id = 0;
	(*temp).principal = 0.0;
	(*temp).quarters_left = 0;
	(*temp).quarterly_interest = 0.0;
	(*temp).quarterly_principal = 0.0;

}

void init_mortgage_static_array(/*@out@*/ mortgage * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_mortgage(&array[i]);
}

void free_mortgage(mortgage * temp)
{

}

void free_mortgage_static_array(mortgage * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_mortgage(&array[i]);
}

void copy_mortgage(mortgage * from, mortgage * to)
{
	(*to).bank_id = (*from).bank_id;
	(*to).principal = (*from).principal;
	(*to).quarters_left = (*from).quarters_left;
	(*to).quarterly_interest = (*from).quarterly_interest;
	(*to).quarterly_principal = (*from).quarterly_principal;
}

void copy_mortgage_static_array(mortgage * from, mortgage * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_mortgage(&from[i], &to[i]);
	}
}


void init_loan(/*@out@*/ loan * temp)
{
	(*temp).bank_id = 0;
	(*temp).amount = 0.0;
	(*temp).to_be_paid = 0.0;

}

void init_loan_static_array(/*@out@*/ loan * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_loan(&array[i]);
}

void free_loan(loan * temp)
{

}

void free_loan_static_array(loan * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_loan(&array[i]);
}

void copy_loan(loan * from, loan * to)
{
	(*to).bank_id = (*from).bank_id;
	(*to).amount = (*from).amount;
	(*to).to_be_paid = (*from).to_be_paid;
}

void copy_loan_static_array(loan * from, loan * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_loan(&from[i], &to[i]);
	}
}


void init_hbuyer(/*@out@*/ hbuyer * temp)
{
	(*temp).buyer_id = 0;
	(*temp).bank_id = 0;
	(*temp).liquidity = 0.0;
	(*temp).quarterly_income = 0.0;
	(*temp).quarterly_mortgage_paid = 0.0;

}

void init_hbuyer_static_array(/*@out@*/ hbuyer * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_hbuyer(&array[i]);
}

void free_hbuyer(hbuyer * temp)
{

}

void free_hbuyer_static_array(hbuyer * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_hbuyer(&array[i]);
}

void copy_hbuyer(hbuyer * from, hbuyer * to)
{
	(*to).buyer_id = (*from).buyer_id;
	(*to).bank_id = (*from).bank_id;
	(*to).liquidity = (*from).liquidity;
	(*to).quarterly_income = (*from).quarterly_income;
	(*to).quarterly_mortgage_paid = (*from).quarterly_mortgage_paid;
}

void copy_hbuyer_static_array(hbuyer * from, hbuyer * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_hbuyer(&from[i], &to[i]);
	}
}


void init_hseller(/*@out@*/ hseller * temp)
{
	(*temp).seller_id = 0;
	(*temp).price = 0.0;
	(*temp).quantity = 0;

}

void init_hseller_static_array(/*@out@*/ hseller * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_hseller(&array[i]);
}

void free_hseller(hseller * temp)
{

}

void free_hseller_static_array(hseller * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_hseller(&array[i]);
}

void copy_hseller(hseller * from, hseller * to)
{
	(*to).seller_id = (*from).seller_id;
	(*to).price = (*from).price;
	(*to).quantity = (*from).quantity;
}

void copy_hseller_static_array(hseller * from, hseller * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_hseller(&from[i], &to[i]);
	}
}


void init_hbank(/*@out@*/ hbank * temp)
{
	(*temp).id = 0;
	(*temp).equity = 0.0;
	(*temp).risky_assets = 0.0;
	(*temp).amount_mortgaged = 0.0;

}

void init_hbank_static_array(/*@out@*/ hbank * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_hbank(&array[i]);
}

void free_hbank(hbank * temp)
{

}

void free_hbank_static_array(hbank * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_hbank(&array[i]);
}

void copy_hbank(hbank * from, hbank * to)
{
	(*to).id = (*from).id;
	(*to).equity = (*from).equity;
	(*to).risky_assets = (*from).risky_assets;
	(*to).amount_mortgaged = (*from).amount_mortgaged;
}

void copy_hbank_static_array(hbank * from, hbank * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_hbank(&from[i], &to[i]);
	}
}



xmachine_memory_firm_state * init_firm_state()
{
	xmachine_memory_firm_state * current = (xmachine_memory_firm_state *)malloc(sizeof(xmachine_memory_firm_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_firm * init_firm_agent()
{
	xmachine_memory_firm * current = (xmachine_memory_firm *)malloc(sizeof(xmachine_memory_firm));
	CHECK_POINTER(current);

	current->id = 0;
	current->bank_id = 0;
	current->isconstructor = 0;
	current->day_of_month_to_act = 0;
	current->isinsolvent = 0;
	current->it_no = 0;
	current->day_of_week_to_act = 0;
	current->average_goods_price = 0.0;
	init_int_array(&current->employees);
	current->wage_offer = 0.0;
	current->average_wage = 0.0;
	current->no_employees = 0;
	current->vacancies = 0;
	current->employees_needed = 0;
	current->day_of_month_wages_paid = 0;
	current->labour_productivity = 0.0;
	current->production_current = 0;
	current->production_estimate = 0;
	current->production_plan = 0;
	current->unit_goods_price = 0.0;
	current->day_of_month_production_completed = 0;
	current->unit_house_price = 0.0;
	current->labour_productivity_construction = 0.0;
	current->capital_productivity_construction = 0.0;
	current->capital_construction = 0.0;
	current->physical_capital = 0.0;
	init_int_static_array(current->projects, 13);
	current->loans_interest_rate = 0.0;
	current->debt = 0.0;
	current->inventory = 0;
	current->sales = 0;
	current->revenues = 0.0;
	current->total_assets = 0.0;
	current->operating_costs = 0.0;
	current->labour_costs = 0.0;
	current->total_interest_payments = 0.0;
	current->dividends_paid = 0.0;
	current->dividends_to_be_paid = 0.0;
	current->retained_earnings = 0.0;
	current->net_earnings = 0.0;
	current->ebit = 0.0;
	current->equity = 0.0;
	current->liquidity = 0.0;
	current->capital_goods = 0.0;
	current->hasloan = 0;
	current->hasinvestment = 0;
	current->planned_investment_costs = 0.0;
	current->liquidity_need = 0.0;
	init_loan_static_array(current->loan_list, 2);
	current->delta_housing_price = 0.0;

	return current;
}

void free_firm_agent(xmachine_memory_firm_holder * tmp, xmachine_memory_firm_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	free_int_array(&tmp->agent->employees);
	free_loan_static_array(tmp->agent->loan_list, 2);
	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_firm_agent()
{
	current_xmachine_firm = (xmachine_memory_firm *)malloc(sizeof(xmachine_memory_firm));
	CHECK_POINTER(current);

		current_xmachine_firm->id = 0;
		current_xmachine_firm->bank_id = 0;
		current_xmachine_firm->isconstructor = 0;
		current_xmachine_firm->day_of_month_to_act = 0;
		current_xmachine_firm->isinsolvent = 0;
		current_xmachine_firm->it_no = 0;
		current_xmachine_firm->day_of_week_to_act = 0;
		current_xmachine_firm->average_goods_price = 0.0;
		init_int_array(&current_xmachine_firm->employees);
		current_xmachine_firm->wage_offer = 0.0;
		current_xmachine_firm->average_wage = 0.0;
		current_xmachine_firm->no_employees = 0;
		current_xmachine_firm->vacancies = 0;
		current_xmachine_firm->employees_needed = 0;
		current_xmachine_firm->day_of_month_wages_paid = 0;
		current_xmachine_firm->labour_productivity = 0.0;
		current_xmachine_firm->production_current = 0;
		current_xmachine_firm->production_estimate = 0;
		current_xmachine_firm->production_plan = 0;
		current_xmachine_firm->unit_goods_price = 0.0;
		current_xmachine_firm->day_of_month_production_completed = 0;
		current_xmachine_firm->unit_house_price = 0.0;
		current_xmachine_firm->labour_productivity_construction = 0.0;
		current_xmachine_firm->capital_productivity_construction = 0.0;
		current_xmachine_firm->capital_construction = 0.0;
		current_xmachine_firm->physical_capital = 0.0;
		init_int_static_array(current_xmachine_firm->projects, 13);
		current_xmachine_firm->loans_interest_rate = 0.0;
		current_xmachine_firm->debt = 0.0;
		current_xmachine_firm->inventory = 0;
		current_xmachine_firm->sales = 0;
		current_xmachine_firm->revenues = 0.0;
		current_xmachine_firm->total_assets = 0.0;
		current_xmachine_firm->operating_costs = 0.0;
		current_xmachine_firm->labour_costs = 0.0;
		current_xmachine_firm->total_interest_payments = 0.0;
		current_xmachine_firm->dividends_paid = 0.0;
		current_xmachine_firm->dividends_to_be_paid = 0.0;
		current_xmachine_firm->retained_earnings = 0.0;
		current_xmachine_firm->net_earnings = 0.0;
		current_xmachine_firm->ebit = 0.0;
		current_xmachine_firm->equity = 0.0;
		current_xmachine_firm->liquidity = 0.0;
		current_xmachine_firm->capital_goods = 0.0;
		current_xmachine_firm->hasloan = 0;
		current_xmachine_firm->hasinvestment = 0;
		current_xmachine_firm->planned_investment_costs = 0.0;
		current_xmachine_firm->liquidity_need = 0.0;
		init_loan_static_array(current_xmachine_firm->loan_list, 2);
		current_xmachine_firm->delta_housing_price = 0.0;
	
}

void unittest_free_firm_agent()
{
	free_int_array(&current_xmachine_firm->employees);
	free_loan_static_array(current_xmachine_firm->loan_list, 2);
	
	free(current_xmachine_firm);
}

void free_firm_agents()
{
	current_xmachine_firm_holder = firm_FirmHousingPrice_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmHousingPrice_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmHousingPrice_state->count = 0;
	current_xmachine_firm_holder = firm_FirmHousingSell_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmHousingSell_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmHousingSell_state->count = 0;
	current_xmachine_firm_holder = firm_FirmHousingMarket_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmHousingMarket_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmHousingMarket_state->count = 0;
	current_xmachine_firm_holder = firm_FirmCreditInsolvency_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditInsolvency_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmCreditInsolvency_state->count = 0;
	current_xmachine_firm_holder = firm_FirmCreditDividendPayments_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditDividendPayments_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmCreditDividendPayments_state->count = 0;
	current_xmachine_firm_holder = firm_FirmCreditBalanceSheet_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditBalanceSheet_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmCreditBalanceSheet_state->count = 0;
	current_xmachine_firm_holder = firm_FirmCreditBankruptcy_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditBankruptcy_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmCreditBankruptcy_state->count = 0;
	current_xmachine_firm_holder = firm_FirmCreditCheckFundInvestment_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditCheckFundInvestment_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmCreditCheckFundInvestment_state->count = 0;
	current_xmachine_firm_holder = firm_FirmCreditIlliquidityStatus_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditIlliquidityStatus_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmCreditIlliquidityStatus_state->count = 0;
	current_xmachine_firm_holder = firm_FirmCreditLoanBorrow2_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditLoanBorrow2_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmCreditLoanBorrow2_state->count = 0;
	current_xmachine_firm_holder = firm_FirmCreditLoanBorrow1_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditLoanBorrow1_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmCreditLoanBorrow1_state->count = 0;
	current_xmachine_firm_holder = firm_FirmCreditPayments_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditPayments_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmCreditPayments_state->count = 0;
	current_xmachine_firm_holder = firm_FirmCreditStatus_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditStatus_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmCreditStatus_state->count = 0;
	current_xmachine_firm_holder = firm_FirmCreditLiquidityNeed_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditLiquidityNeed_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmCreditLiquidityNeed_state->count = 0;
	current_xmachine_firm_holder = firm_FirmCreditComputeDividends_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditComputeDividends_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmCreditComputeDividends_state->count = 0;
	current_xmachine_firm_holder = firm_FirmCreditInvestment_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditInvestment_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmCreditInvestment_state->count = 0;
	current_xmachine_firm_holder = firm_FirmCreditInterestRate_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditInterestRate_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmCreditInterestRate_state->count = 0;
	current_xmachine_firm_holder = firm_FirmConstructionLabourDemand_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmConstructionLabourDemand_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmConstructionLabourDemand_state->count = 0;
	current_xmachine_firm_holder = firm_FirmProductionLabourDemand_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionLabourDemand_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmProductionLabourDemand_state->count = 0;
	current_xmachine_firm_holder = firm_FirmProductionPlanning_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionPlanning_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmProductionPlanning_state->count = 0;
	current_xmachine_firm_holder = firm_FirmProductionConstructor_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionConstructor_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmProductionConstructor_state->count = 0;
	current_xmachine_firm_holder = firm_FirmProductionRegular_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionRegular_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmProductionRegular_state->count = 0;
	current_xmachine_firm_holder = firm_FirmProductionRoleCheck_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionRoleCheck_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmProductionRoleCheck_state->count = 0;
	current_xmachine_firm_holder = firm_FirmProductionSkip_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionSkip_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmProductionSkip_state->count = 0;
	current_xmachine_firm_holder = firm_FirmProductionStart_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmProductionStart_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmProductionStart_state->count = 0;
	current_xmachine_firm_holder = firm_FirmLabourWageAdjustment_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourWageAdjustment_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmLabourWageAdjustment_state->count = 0;
	current_xmachine_firm_holder = firm_FirmLabourStage2End_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage2End_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmLabourStage2End_state->count = 0;
	current_xmachine_firm_holder = firm_FirmLabourStage2_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage2_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmLabourStage2_state->count = 0;
	current_xmachine_firm_holder = firm_FirmLabourStage1Application_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage1Application_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmLabourStage1Application_state->count = 0;
	current_xmachine_firm_holder = firm_FirmLabourStage1End_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage1End_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmLabourStage1End_state->count = 0;
	current_xmachine_firm_holder = firm_FirmLabourStage1_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStage1_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmLabourStage1_state->count = 0;
	current_xmachine_firm_holder = firm_FirmLabourPayWages_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourPayWages_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmLabourPayWages_state->count = 0;
	current_xmachine_firm_holder = firm_FirmLabourStart_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmLabourStart_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmLabourStart_state->count = 0;
	current_xmachine_firm_holder = firm_FirmConsumptionPrice_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmConsumptionPrice_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmConsumptionPrice_state->count = 0;
	current_xmachine_firm_holder = firm_FirmRecieveSales_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmRecieveSales_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmRecieveSales_state->count = 0;
	current_xmachine_firm_holder = firm_FirmHousingStart_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmHousingStart_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmHousingStart_state->count = 0;
	current_xmachine_firm_holder = firm_FirmConsumptionStart_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmConsumptionStart_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmConsumptionStart_state->count = 0;
	current_xmachine_firm_holder = firm_end_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_end_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_end_state->count = 0;
	current_xmachine_firm_holder = firm_FirmUpdateDeposits_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmUpdateDeposits_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmUpdateDeposits_state->count = 0;
	current_xmachine_firm_holder = firm_FirmCreditStart_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_FirmCreditStart_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_FirmCreditStart_state->count = 0;
	current_xmachine_firm_holder = firm_start_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_start_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_start_state->count = 0;
}

void free_firm_states()
{
	free(firm_FirmHousingPrice_state);
	free(firm_FirmHousingSell_state);
	free(firm_FirmHousingMarket_state);
	free(firm_FirmCreditInsolvency_state);
	free(firm_FirmCreditDividendPayments_state);
	free(firm_FirmCreditBalanceSheet_state);
	free(firm_FirmCreditBankruptcy_state);
	free(firm_FirmCreditCheckFundInvestment_state);
	free(firm_FirmCreditIlliquidityStatus_state);
	free(firm_FirmCreditLoanBorrow2_state);
	free(firm_FirmCreditLoanBorrow1_state);
	free(firm_FirmCreditPayments_state);
	free(firm_FirmCreditStatus_state);
	free(firm_FirmCreditLiquidityNeed_state);
	free(firm_FirmCreditComputeDividends_state);
	free(firm_FirmCreditInvestment_state);
	free(firm_FirmCreditInterestRate_state);
	free(firm_FirmConstructionLabourDemand_state);
	free(firm_FirmProductionLabourDemand_state);
	free(firm_FirmProductionPlanning_state);
	free(firm_FirmProductionConstructor_state);
	free(firm_FirmProductionRegular_state);
	free(firm_FirmProductionRoleCheck_state);
	free(firm_FirmProductionSkip_state);
	free(firm_FirmProductionStart_state);
	free(firm_FirmLabourWageAdjustment_state);
	free(firm_FirmLabourStage2End_state);
	free(firm_FirmLabourStage2_state);
	free(firm_FirmLabourStage1Application_state);
	free(firm_FirmLabourStage1End_state);
	free(firm_FirmLabourStage1_state);
	free(firm_FirmLabourPayWages_state);
	free(firm_FirmLabourStart_state);
	free(firm_FirmConsumptionPrice_state);
	free(firm_FirmRecieveSales_state);
	free(firm_FirmHousingStart_state);
	free(firm_FirmConsumptionStart_state);
	free(firm_end_state);
	free(firm_FirmUpdateDeposits_state);
	free(firm_FirmCreditStart_state);
	free(firm_start_state);
}

void transition_firm_agent(xmachine_memory_firm_holder * tmp, xmachine_memory_firm_state * from_state, xmachine_memory_firm_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_firm_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_firm_agent_internal(xmachine_memory_firm * agent, xmachine_memory_firm_state * state)
{
	xmachine_memory_firm_holder * current = (xmachine_memory_firm_holder *)malloc(sizeof(xmachine_memory_firm_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_firm_agent(int id, int bank_id, int isconstructor, int day_of_month_to_act, int isinsolvent, int it_no, int day_of_week_to_act, double average_goods_price, int_array * employees, double wage_offer, double average_wage, int no_employees, int vacancies, int employees_needed, int day_of_month_wages_paid, double labour_productivity, int production_current, int production_estimate, int production_plan, double unit_goods_price, int day_of_month_production_completed, double unit_house_price, double labour_productivity_construction, double capital_productivity_construction, double capital_construction, double physical_capital, int projects[], double loans_interest_rate, double debt, int inventory, int sales, double revenues, double total_assets, double operating_costs, double labour_costs, double total_interest_payments, double dividends_paid, double dividends_to_be_paid, double retained_earnings, double net_earnings, double ebit, double equity, double liquidity, double capital_goods, int hasloan, int hasinvestment, double planned_investment_costs, double liquidity_need, loan ** loan_list, double delta_housing_price)
 * \brief Add firm X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param bank_id Variable for the X-machine memory.
 * \param isconstructor Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param isinsolvent Variable for the X-machine memory.
 * \param it_no Variable for the X-machine memory.
 * \param day_of_week_to_act Variable for the X-machine memory.
 * \param average_goods_price Variable for the X-machine memory.
 * \param employees Variable for the X-machine memory.
 * \param wage_offer Variable for the X-machine memory.
 * \param average_wage Variable for the X-machine memory.
 * \param no_employees Variable for the X-machine memory.
 * \param vacancies Variable for the X-machine memory.
 * \param employees_needed Variable for the X-machine memory.
 * \param day_of_month_wages_paid Variable for the X-machine memory.
 * \param labour_productivity Variable for the X-machine memory.
 * \param production_current Variable for the X-machine memory.
 * \param production_estimate Variable for the X-machine memory.
 * \param production_plan Variable for the X-machine memory.
 * \param unit_goods_price Variable for the X-machine memory.
 * \param day_of_month_production_completed Variable for the X-machine memory.
 * \param unit_house_price Variable for the X-machine memory.
 * \param labour_productivity_construction Variable for the X-machine memory.
 * \param capital_productivity_construction Variable for the X-machine memory.
 * \param capital_construction Variable for the X-machine memory.
 * \param physical_capital Variable for the X-machine memory.
 * \param projects Variable for the X-machine memory.
 * \param loans_interest_rate Variable for the X-machine memory.
 * \param debt Variable for the X-machine memory.
 * \param inventory Variable for the X-machine memory.
 * \param sales Variable for the X-machine memory.
 * \param revenues Variable for the X-machine memory.
 * \param total_assets Variable for the X-machine memory.
 * \param operating_costs Variable for the X-machine memory.
 * \param labour_costs Variable for the X-machine memory.
 * \param total_interest_payments Variable for the X-machine memory.
 * \param dividends_paid Variable for the X-machine memory.
 * \param dividends_to_be_paid Variable for the X-machine memory.
 * \param retained_earnings Variable for the X-machine memory.
 * \param net_earnings Variable for the X-machine memory.
 * \param ebit Variable for the X-machine memory.
 * \param equity Variable for the X-machine memory.
 * \param liquidity Variable for the X-machine memory.
 * \param capital_goods Variable for the X-machine memory.
 * \param hasloan Variable for the X-machine memory.
 * \param hasinvestment Variable for the X-machine memory.
 * \param planned_investment_costs Variable for the X-machine memory.
 * \param liquidity_need Variable for the X-machine memory.
 * \param loan_list Variable for the X-machine memory.
 * \param delta_housing_price Variable for the X-machine memory.
 */
void add_firm_agent(int id, int bank_id, int isconstructor, int day_of_month_to_act, int isinsolvent, int it_no, int day_of_week_to_act, double average_goods_price, int_array * employees, double wage_offer, double average_wage, int no_employees, int vacancies, int employees_needed, int day_of_month_wages_paid, double labour_productivity, int production_current, int production_estimate, int production_plan, double unit_goods_price, int day_of_month_production_completed, double unit_house_price, double labour_productivity_construction, double capital_productivity_construction, double capital_construction, double physical_capital, int projects[], double loans_interest_rate, double debt, int inventory, int sales, double revenues, double total_assets, double operating_costs, double labour_costs, double total_interest_payments, double dividends_paid, double dividends_to_be_paid, double retained_earnings, double net_earnings, double ebit, double equity, double liquidity, double capital_goods, int hasloan, int hasinvestment, double planned_investment_costs, double liquidity_need, loan loan_list[], double delta_housing_price)
{
	xmachine_memory_firm * current;

	current = init_firm_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_firm_next_state = firm_start_state;
	add_firm_agent_internal(current, current_xmachine_firm_next_state);

	current->id = id;
	current->bank_id = bank_id;
	current->isconstructor = isconstructor;
	current->day_of_month_to_act = day_of_month_to_act;
	current->isinsolvent = isinsolvent;
	current->it_no = it_no;
	current->day_of_week_to_act = day_of_week_to_act;
	current->average_goods_price = average_goods_price;
	copy_int_array(employees, &current->employees);
	current->wage_offer = wage_offer;
	current->average_wage = average_wage;
	current->no_employees = no_employees;
	current->vacancies = vacancies;
	current->employees_needed = employees_needed;
	current->day_of_month_wages_paid = day_of_month_wages_paid;
	current->labour_productivity = labour_productivity;
	current->production_current = production_current;
	current->production_estimate = production_estimate;
	current->production_plan = production_plan;
	current->unit_goods_price = unit_goods_price;
	current->day_of_month_production_completed = day_of_month_production_completed;
	current->unit_house_price = unit_house_price;
	current->labour_productivity_construction = labour_productivity_construction;
	current->capital_productivity_construction = capital_productivity_construction;
	current->capital_construction = capital_construction;
	current->physical_capital = physical_capital;
	memcpy(current->projects, projects, 13*sizeof(int));
	current->loans_interest_rate = loans_interest_rate;
	current->debt = debt;
	current->inventory = inventory;
	current->sales = sales;
	current->revenues = revenues;
	current->total_assets = total_assets;
	current->operating_costs = operating_costs;
	current->labour_costs = labour_costs;
	current->total_interest_payments = total_interest_payments;
	current->dividends_paid = dividends_paid;
	current->dividends_to_be_paid = dividends_to_be_paid;
	current->retained_earnings = retained_earnings;
	current->net_earnings = net_earnings;
	current->ebit = ebit;
	current->equity = equity;
	current->liquidity = liquidity;
	current->capital_goods = capital_goods;
	current->hasloan = hasloan;
	current->hasinvestment = hasinvestment;
	current->planned_investment_costs = planned_investment_costs;
	current->liquidity_need = liquidity_need;
	copy_loan_static_array(loan_list, current->loan_list, 2);
	current->delta_housing_price = delta_housing_price;
}

xmachine_memory_household_state * init_household_state()
{
	xmachine_memory_household_state * current = (xmachine_memory_household_state *)malloc(sizeof(xmachine_memory_household_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_household * init_household_agent()
{
	xmachine_memory_household * current = (xmachine_memory_household *)malloc(sizeof(xmachine_memory_household));
	CHECK_POINTER(current);

	current->id = 0;
	current->bank_id = 0;
	current->day_of_week_to_act = 0;
	current->weekly_consumption_budget = 0.0;
	current->planned_consumption_budget = 0.0;
	current->my_employer_id = 0;
	current->wage = 0.0;
	current->day_of_month_to_act = 0;
	current->day_of_month_wage_recieved = 0;
	current->mortgages_interest_rate = 0.0;
	current->tax_rate = 0.0;
	init_mortgage_array(&current->mortgages_list);
	current->mortgages = 0.0;
	current->housing_payment = 0.0;
	current->equity = 0.0;
	current->housing_price = 0.0;
	current->housing_units = 0;
	current->n_shares = 0;
	current->liquidity = 0.0;
	current->capital_income = 0.0;
	init_int_static_array(current->previous_wages, 3);
	current->labour_income = 0.0;
	current->total_assets = 0.0;
	current->housing_value = 0.0;
	current->delta_housing_value = 0.0;
	current->hmarket_role = 0;
	current->equity_ratio = 0.0;
	current->minimum_equity_ratio = 0.0;
	init_double_static_array(current->mortgage_costs, 3);

	return current;
}

void free_household_agent(xmachine_memory_household_holder * tmp, xmachine_memory_household_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	free_mortgage_array(&tmp->agent->mortgages_list);
	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_household_agent()
{
	current_xmachine_household = (xmachine_memory_household *)malloc(sizeof(xmachine_memory_household));
	CHECK_POINTER(current);

		current_xmachine_household->id = 0;
		current_xmachine_household->bank_id = 0;
		current_xmachine_household->day_of_week_to_act = 0;
		current_xmachine_household->weekly_consumption_budget = 0.0;
		current_xmachine_household->planned_consumption_budget = 0.0;
		current_xmachine_household->my_employer_id = 0;
		current_xmachine_household->wage = 0.0;
		current_xmachine_household->day_of_month_to_act = 0;
		current_xmachine_household->day_of_month_wage_recieved = 0;
		current_xmachine_household->mortgages_interest_rate = 0.0;
		current_xmachine_household->tax_rate = 0.0;
		init_mortgage_array(&current_xmachine_household->mortgages_list);
		current_xmachine_household->mortgages = 0.0;
		current_xmachine_household->housing_payment = 0.0;
		current_xmachine_household->equity = 0.0;
		current_xmachine_household->housing_price = 0.0;
		current_xmachine_household->housing_units = 0;
		current_xmachine_household->n_shares = 0;
		current_xmachine_household->liquidity = 0.0;
		current_xmachine_household->capital_income = 0.0;
		init_int_static_array(current_xmachine_household->previous_wages, 3);
		current_xmachine_household->labour_income = 0.0;
		current_xmachine_household->total_assets = 0.0;
		current_xmachine_household->housing_value = 0.0;
		current_xmachine_household->delta_housing_value = 0.0;
		current_xmachine_household->hmarket_role = 0;
		current_xmachine_household->equity_ratio = 0.0;
		current_xmachine_household->minimum_equity_ratio = 0.0;
		init_double_static_array(current_xmachine_household->mortgage_costs, 3);
	
}

void unittest_free_household_agent()
{
	free_mortgage_array(&current_xmachine_household->mortgages_list);
	
	free(current_xmachine_household);
}

void free_household_agents()
{
	current_xmachine_household_holder = household_HHHousingWriteOff_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHHousingWriteOff_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHHousingWriteOff_state->count = 0;
	current_xmachine_household_holder = household_HHHousingPayments_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHHousingPayments_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHHousingPayments_state->count = 0;
	current_xmachine_household_holder = household_HHHousingBargain_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHHousingBargain_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHHousingBargain_state->count = 0;
	current_xmachine_household_holder = household_HHHousingRevenue_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHHousingRevenue_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHHousingRevenue_state->count = 0;
	current_xmachine_household_holder = household_HHHousingCheckWealth_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHHousingCheckWealth_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHHousingCheckWealth_state->count = 0;
	current_xmachine_household_holder = household_HHHousingPrice_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHHousingPrice_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHHousingPrice_state->count = 0;
	current_xmachine_household_holder = household_HHHousingRole_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHHousingRole_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHHousingRole_state->count = 0;
	current_xmachine_household_holder = household_HHCreditEmployment_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHCreditEmployment_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHCreditEmployment_state->count = 0;
	current_xmachine_household_holder = household_HHCreditCapitalTax_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHCreditCapitalTax_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHCreditCapitalTax_state->count = 0;
	current_xmachine_household_holder = household_HHCreditBalanceSheet_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHCreditBalanceSheet_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHCreditBalanceSheet_state->count = 0;
	current_xmachine_household_holder = household_HHCreditIsCapitalist_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHCreditIsCapitalist_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHCreditIsCapitalist_state->count = 0;
	current_xmachine_household_holder = household_HHCreditUpdateMortgages_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHCreditUpdateMortgages_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHCreditUpdateMortgages_state->count = 0;
	current_xmachine_household_holder = household_HHCreditCheckTax_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHCreditCheckTax_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHCreditCheckTax_state->count = 0;
	current_xmachine_household_holder = household_HHCreditMonthly_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHCreditMonthly_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHCreditMonthly_state->count = 0;
	current_xmachine_household_holder = household_HHLabourPayroll_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHLabourPayroll_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHLabourPayroll_state->count = 0;
	current_xmachine_household_holder = household_HHLabourStage1Placement_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHLabourStage1Placement_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHLabourStage1Placement_state->count = 0;
	current_xmachine_household_holder = household_HHLabourStage1Applications_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHLabourStage1Applications_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHLabourStage1Applications_state->count = 0;
	current_xmachine_household_holder = household_HHLabourStage2_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHLabourStage2_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHLabourStage2_state->count = 0;
	current_xmachine_household_holder = household_HHLabourStage1_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHLabourStage1_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHLabourStage1_state->count = 0;
	current_xmachine_household_holder = household_HHLabourEmploymentStatus_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHLabourEmploymentStatus_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHLabourEmploymentStatus_state->count = 0;
	current_xmachine_household_holder = household_HHLabourStart_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHLabourStart_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHLabourStart_state->count = 0;
	current_xmachine_household_holder = household_HHConsumptionRecieveGoods_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHConsumptionRecieveGoods_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHConsumptionRecieveGoods_state->count = 0;
	current_xmachine_household_holder = household_HHHousingStart_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHHousingStart_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHHousingStart_state->count = 0;
	current_xmachine_household_holder = household_HHConsumptionWeekly_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHConsumptionWeekly_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHConsumptionWeekly_state->count = 0;
	current_xmachine_household_holder = household_HHConsumptionStart_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHConsumptionStart_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHConsumptionStart_state->count = 0;
	current_xmachine_household_holder = household_end_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_end_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_end_state->count = 0;
	current_xmachine_household_holder = household_HouseholdUpdateDeposits_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HouseholdUpdateDeposits_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HouseholdUpdateDeposits_state->count = 0;
	current_xmachine_household_holder = household_HHCreditStart_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_HHCreditStart_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_HHCreditStart_state->count = 0;
	current_xmachine_household_holder = household_start_state->agents;
	while(current_xmachine_household_holder)
	{
		temp_xmachine_household_holder = current_xmachine_household_holder->next;
		free_household_agent(current_xmachine_household_holder, household_start_state);
		current_xmachine_household_holder = temp_xmachine_household_holder;
	}
	household_start_state->count = 0;
}

void free_household_states()
{
	free(household_HHHousingWriteOff_state);
	free(household_HHHousingPayments_state);
	free(household_HHHousingBargain_state);
	free(household_HHHousingRevenue_state);
	free(household_HHHousingCheckWealth_state);
	free(household_HHHousingPrice_state);
	free(household_HHHousingRole_state);
	free(household_HHCreditEmployment_state);
	free(household_HHCreditCapitalTax_state);
	free(household_HHCreditBalanceSheet_state);
	free(household_HHCreditIsCapitalist_state);
	free(household_HHCreditUpdateMortgages_state);
	free(household_HHCreditCheckTax_state);
	free(household_HHCreditMonthly_state);
	free(household_HHLabourPayroll_state);
	free(household_HHLabourStage1Placement_state);
	free(household_HHLabourStage1Applications_state);
	free(household_HHLabourStage2_state);
	free(household_HHLabourStage1_state);
	free(household_HHLabourEmploymentStatus_state);
	free(household_HHLabourStart_state);
	free(household_HHConsumptionRecieveGoods_state);
	free(household_HHHousingStart_state);
	free(household_HHConsumptionWeekly_state);
	free(household_HHConsumptionStart_state);
	free(household_end_state);
	free(household_HouseholdUpdateDeposits_state);
	free(household_HHCreditStart_state);
	free(household_start_state);
}

void transition_household_agent(xmachine_memory_household_holder * tmp, xmachine_memory_household_state * from_state, xmachine_memory_household_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_household_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_household_agent_internal(xmachine_memory_household * agent, xmachine_memory_household_state * state)
{
	xmachine_memory_household_holder * current = (xmachine_memory_household_holder *)malloc(sizeof(xmachine_memory_household_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_household_agent(int id, int bank_id, int day_of_week_to_act, double weekly_consumption_budget, double planned_consumption_budget, int my_employer_id, double wage, int day_of_month_to_act, int day_of_month_wage_recieved, double mortgages_interest_rate, double tax_rate, mortgage_array * mortgages_list, double mortgages, double housing_payment, double equity, double housing_price, int housing_units, int n_shares, double liquidity, double capital_income, int previous_wages[], double labour_income, double total_assets, double housing_value, double delta_housing_value, int hmarket_role, double equity_ratio, double minimum_equity_ratio, double mortgage_costs[])
 * \brief Add household X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param bank_id Variable for the X-machine memory.
 * \param day_of_week_to_act Variable for the X-machine memory.
 * \param weekly_consumption_budget Variable for the X-machine memory.
 * \param planned_consumption_budget Variable for the X-machine memory.
 * \param my_employer_id Variable for the X-machine memory.
 * \param wage Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param day_of_month_wage_recieved Variable for the X-machine memory.
 * \param mortgages_interest_rate Variable for the X-machine memory.
 * \param tax_rate Variable for the X-machine memory.
 * \param mortgages_list Variable for the X-machine memory.
 * \param mortgages Variable for the X-machine memory.
 * \param housing_payment Variable for the X-machine memory.
 * \param equity Variable for the X-machine memory.
 * \param housing_price Variable for the X-machine memory.
 * \param housing_units Variable for the X-machine memory.
 * \param n_shares Variable for the X-machine memory.
 * \param liquidity Variable for the X-machine memory.
 * \param capital_income Variable for the X-machine memory.
 * \param previous_wages Variable for the X-machine memory.
 * \param labour_income Variable for the X-machine memory.
 * \param total_assets Variable for the X-machine memory.
 * \param housing_value Variable for the X-machine memory.
 * \param delta_housing_value Variable for the X-machine memory.
 * \param hmarket_role Variable for the X-machine memory.
 * \param equity_ratio Variable for the X-machine memory.
 * \param minimum_equity_ratio Variable for the X-machine memory.
 * \param mortgage_costs Variable for the X-machine memory.
 */
void add_household_agent(int id, int bank_id, int day_of_week_to_act, double weekly_consumption_budget, double planned_consumption_budget, int my_employer_id, double wage, int day_of_month_to_act, int day_of_month_wage_recieved, double mortgages_interest_rate, double tax_rate, mortgage_array * mortgages_list, double mortgages, double housing_payment, double equity, double housing_price, int housing_units, int n_shares, double liquidity, double capital_income, int previous_wages[], double labour_income, double total_assets, double housing_value, double delta_housing_value, int hmarket_role, double equity_ratio, double minimum_equity_ratio, double mortgage_costs[])
{
	xmachine_memory_household * current;

	current = init_household_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_household_next_state = household_start_state;
	add_household_agent_internal(current, current_xmachine_household_next_state);

	current->id = id;
	current->bank_id = bank_id;
	current->day_of_week_to_act = day_of_week_to_act;
	current->weekly_consumption_budget = weekly_consumption_budget;
	current->planned_consumption_budget = planned_consumption_budget;
	current->my_employer_id = my_employer_id;
	current->wage = wage;
	current->day_of_month_to_act = day_of_month_to_act;
	current->day_of_month_wage_recieved = day_of_month_wage_recieved;
	current->mortgages_interest_rate = mortgages_interest_rate;
	current->tax_rate = tax_rate;
	copy_mortgage_array(mortgages_list, &current->mortgages_list);
	current->mortgages = mortgages;
	current->housing_payment = housing_payment;
	current->equity = equity;
	current->housing_price = housing_price;
	current->housing_units = housing_units;
	current->n_shares = n_shares;
	current->liquidity = liquidity;
	current->capital_income = capital_income;
	memcpy(current->previous_wages, previous_wages, 3*sizeof(int));
	current->labour_income = labour_income;
	current->total_assets = total_assets;
	current->housing_value = housing_value;
	current->delta_housing_value = delta_housing_value;
	current->hmarket_role = hmarket_role;
	current->equity_ratio = equity_ratio;
	current->minimum_equity_ratio = minimum_equity_ratio;
	memcpy(current->mortgage_costs, mortgage_costs, 3*sizeof(double));
}

xmachine_memory_equityfund_state * init_equityfund_state()
{
	xmachine_memory_equityfund_state * current = (xmachine_memory_equityfund_state *)malloc(sizeof(xmachine_memory_equityfund_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_equityfund * init_equityfund_agent()
{
	xmachine_memory_equityfund * current = (xmachine_memory_equityfund *)malloc(sizeof(xmachine_memory_equityfund));
	CHECK_POINTER(current);

	current->id = 0;
	current->day_of_month_to_act = 0;
	current->share_firms = 0.0;
	current->share_construction_firms = 0.0;
	current->share_banks = 0.0;
	current->equity = 0.0;
	current->liquidity = 0.0;
	current->n_shares = 0;
	current->dividends_recieved = 0.0;
	current->dividends_retained = 0.0;
	current->dividends_paid = 0.0;
	current->firm_investment = 0.0;

	return current;
}

void free_equityfund_agent(xmachine_memory_equityfund_holder * tmp, xmachine_memory_equityfund_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_equityfund_agent()
{
	current_xmachine_equityfund = (xmachine_memory_equityfund *)malloc(sizeof(xmachine_memory_equityfund));
	CHECK_POINTER(current);

		current_xmachine_equityfund->id = 0;
		current_xmachine_equityfund->day_of_month_to_act = 0;
		current_xmachine_equityfund->share_firms = 0.0;
		current_xmachine_equityfund->share_construction_firms = 0.0;
		current_xmachine_equityfund->share_banks = 0.0;
		current_xmachine_equityfund->equity = 0.0;
		current_xmachine_equityfund->liquidity = 0.0;
		current_xmachine_equityfund->n_shares = 0;
		current_xmachine_equityfund->dividends_recieved = 0.0;
		current_xmachine_equityfund->dividends_retained = 0.0;
		current_xmachine_equityfund->dividends_paid = 0.0;
		current_xmachine_equityfund->firm_investment = 0.0;
	
}

void unittest_free_equityfund_agent()
{
	
	free(current_xmachine_equityfund);
}

void free_equityfund_agents()
{
	current_xmachine_equityfund_holder = equityfund_EFCreditBalanceSheet_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFCreditBalanceSheet_state);
		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	equityfund_EFCreditBalanceSheet_state->count = 0;
	current_xmachine_equityfund_holder = equityfund_EFCreditShareCollectionFirms_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFCreditShareCollectionFirms_state);
		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	equityfund_EFCreditShareCollectionFirms_state->count = 0;
	current_xmachine_equityfund_holder = equityfund_EFCreditShareCollectionBanks_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFCreditShareCollectionBanks_state);
		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	equityfund_EFCreditShareCollectionBanks_state->count = 0;
	current_xmachine_equityfund_holder = equityfund_EFCreditDistributeShares_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFCreditDistributeShares_state);
		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	equityfund_EFCreditDistributeShares_state->count = 0;
	current_xmachine_equityfund_holder = equityfund_end_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_end_state);
		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	equityfund_end_state->count = 0;
	current_xmachine_equityfund_holder = equityfund_EFLabourMarket_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EFLabourMarket_state);
		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	equityfund_EFLabourMarket_state->count = 0;
	current_xmachine_equityfund_holder = equityfund_EquityFundStart_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_EquityFundStart_state);
		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	equityfund_EquityFundStart_state->count = 0;
	current_xmachine_equityfund_holder = equityfund_start_state->agents;
	while(current_xmachine_equityfund_holder)
	{
		temp_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
		free_equityfund_agent(current_xmachine_equityfund_holder, equityfund_start_state);
		current_xmachine_equityfund_holder = temp_xmachine_equityfund_holder;
	}
	equityfund_start_state->count = 0;
}

void free_equityfund_states()
{
	free(equityfund_EFCreditBalanceSheet_state);
	free(equityfund_EFCreditShareCollectionFirms_state);
	free(equityfund_EFCreditShareCollectionBanks_state);
	free(equityfund_EFCreditDistributeShares_state);
	free(equityfund_end_state);
	free(equityfund_EFLabourMarket_state);
	free(equityfund_EquityFundStart_state);
	free(equityfund_start_state);
}

void transition_equityfund_agent(xmachine_memory_equityfund_holder * tmp, xmachine_memory_equityfund_state * from_state, xmachine_memory_equityfund_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_equityfund_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_equityfund_agent_internal(xmachine_memory_equityfund * agent, xmachine_memory_equityfund_state * state)
{
	xmachine_memory_equityfund_holder * current = (xmachine_memory_equityfund_holder *)malloc(sizeof(xmachine_memory_equityfund_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_equityfund_agent(int id, int day_of_month_to_act, double share_firms, double share_construction_firms, double share_banks, double equity, double liquidity, int n_shares, double dividends_recieved, double dividends_retained, double dividends_paid, double firm_investment)
 * \brief Add equityfund X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param share_firms Variable for the X-machine memory.
 * \param share_construction_firms Variable for the X-machine memory.
 * \param share_banks Variable for the X-machine memory.
 * \param equity Variable for the X-machine memory.
 * \param liquidity Variable for the X-machine memory.
 * \param n_shares Variable for the X-machine memory.
 * \param dividends_recieved Variable for the X-machine memory.
 * \param dividends_retained Variable for the X-machine memory.
 * \param dividends_paid Variable for the X-machine memory.
 * \param firm_investment Variable for the X-machine memory.
 */
void add_equityfund_agent(int id, int day_of_month_to_act, double share_firms, double share_construction_firms, double share_banks, double equity, double liquidity, int n_shares, double dividends_recieved, double dividends_retained, double dividends_paid, double firm_investment)
{
	xmachine_memory_equityfund * current;

	current = init_equityfund_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_equityfund_next_state = equityfund_start_state;
	add_equityfund_agent_internal(current, current_xmachine_equityfund_next_state);

	current->id = id;
	current->day_of_month_to_act = day_of_month_to_act;
	current->share_firms = share_firms;
	current->share_construction_firms = share_construction_firms;
	current->share_banks = share_banks;
	current->equity = equity;
	current->liquidity = liquidity;
	current->n_shares = n_shares;
	current->dividends_recieved = dividends_recieved;
	current->dividends_retained = dividends_retained;
	current->dividends_paid = dividends_paid;
	current->firm_investment = firm_investment;
}

xmachine_memory_bank_state * init_bank_state()
{
	xmachine_memory_bank_state * current = (xmachine_memory_bank_state *)malloc(sizeof(xmachine_memory_bank_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_bank * init_bank_agent()
{
	xmachine_memory_bank * current = (xmachine_memory_bank *)malloc(sizeof(xmachine_memory_bank));
	CHECK_POINTER(current);

	current->id = 0;
	current->day_of_month_to_act = 0;
	current->day_of_week_to_act = 0;
	current->total_assets = 0.0;
	current->loans = 0.0;
	current->mortgages = 0.0;
	current->deposits = 0.0;
	current->centralbank_debt = 0.0;
	current->equity = 0.0;
	current->liquidity = 0.0;
	current->revenues = 0.0;
	current->total_writeoffs = 0.0;
	current->interests_accrued = 0.0;
	current->interests_paid = 0.0;
	current->dividends_paid = 0.0;
	current->total_dividends = 0.0;
	current->retained_earnings = 0.0;
	current->net_earnings = 0.0;
	current->total_costs = 0.0;

	return current;
}

void free_bank_agent(xmachine_memory_bank_holder * tmp, xmachine_memory_bank_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_bank_agent()
{
	current_xmachine_bank = (xmachine_memory_bank *)malloc(sizeof(xmachine_memory_bank));
	CHECK_POINTER(current);

		current_xmachine_bank->id = 0;
		current_xmachine_bank->day_of_month_to_act = 0;
		current_xmachine_bank->day_of_week_to_act = 0;
		current_xmachine_bank->total_assets = 0.0;
		current_xmachine_bank->loans = 0.0;
		current_xmachine_bank->mortgages = 0.0;
		current_xmachine_bank->deposits = 0.0;
		current_xmachine_bank->centralbank_debt = 0.0;
		current_xmachine_bank->equity = 0.0;
		current_xmachine_bank->liquidity = 0.0;
		current_xmachine_bank->revenues = 0.0;
		current_xmachine_bank->total_writeoffs = 0.0;
		current_xmachine_bank->interests_accrued = 0.0;
		current_xmachine_bank->interests_paid = 0.0;
		current_xmachine_bank->dividends_paid = 0.0;
		current_xmachine_bank->total_dividends = 0.0;
		current_xmachine_bank->retained_earnings = 0.0;
		current_xmachine_bank->net_earnings = 0.0;
		current_xmachine_bank->total_costs = 0.0;
	
}

void unittest_free_bank_agent()
{
	
	free(current_xmachine_bank);
}

void free_bank_agents()
{
	current_xmachine_bank_holder = bank_BankHousingWriteOff_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankHousingWriteOff_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankHousingWriteOff_state->count = 0;
	current_xmachine_bank_holder = bank_BankHousingMortgages_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankHousingMortgages_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankHousingMortgages_state->count = 0;
	current_xmachine_bank_holder = bank_BankHousingSales_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankHousingSales_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankHousingSales_state->count = 0;
	current_xmachine_bank_holder = bank_BankHousingCrediting_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankHousingCrediting_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankHousingCrediting_state->count = 0;
	current_xmachine_bank_holder = bank_BankCreditBalanceSheet_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankCreditBalanceSheet_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankCreditBalanceSheet_state->count = 0;
	current_xmachine_bank_holder = bank_BankCreditDividends_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankCreditDividends_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankCreditDividends_state->count = 0;
	current_xmachine_bank_holder = bank_BankCreditLiquidtyRecieve_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankCreditLiquidtyRecieve_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankCreditLiquidtyRecieve_state->count = 0;
	current_xmachine_bank_holder = bank_BankCreditIncomeStatement_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankCreditIncomeStatement_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankCreditIncomeStatement_state->count = 0;
	current_xmachine_bank_holder = bank_BankCreditLiquidityNeed_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankCreditLiquidityNeed_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankCreditLiquidityNeed_state->count = 0;
	current_xmachine_bank_holder = bank_BankCreditLoanInterests_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankCreditLoanInterests_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankCreditLoanInterests_state->count = 0;
	current_xmachine_bank_holder = bank_BankCreditNewEntrants_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankCreditNewEntrants_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankCreditNewEntrants_state->count = 0;
	current_xmachine_bank_holder = bank_BankCreditLoanWriteOffs_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankCreditLoanWriteOffs_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankCreditLoanWriteOffs_state->count = 0;
	current_xmachine_bank_holder = bank_BankCreditRequest2_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankCreditRequest2_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankCreditRequest2_state->count = 0;
	current_xmachine_bank_holder = bank_BankHousingMarket_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankHousingMarket_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankHousingMarket_state->count = 0;
	current_xmachine_bank_holder = bank_end_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_end_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_end_state->count = 0;
	current_xmachine_bank_holder = bank_BankUpdateDeposits_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankUpdateDeposits_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankUpdateDeposits_state->count = 0;
	current_xmachine_bank_holder = bank_BankCreditStart_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_BankCreditStart_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_BankCreditStart_state->count = 0;
	current_xmachine_bank_holder = bank_start_state->agents;
	while(current_xmachine_bank_holder)
	{
		temp_xmachine_bank_holder = current_xmachine_bank_holder->next;
		free_bank_agent(current_xmachine_bank_holder, bank_start_state);
		current_xmachine_bank_holder = temp_xmachine_bank_holder;
	}
	bank_start_state->count = 0;
}

void free_bank_states()
{
	free(bank_BankHousingWriteOff_state);
	free(bank_BankHousingMortgages_state);
	free(bank_BankHousingSales_state);
	free(bank_BankHousingCrediting_state);
	free(bank_BankCreditBalanceSheet_state);
	free(bank_BankCreditDividends_state);
	free(bank_BankCreditLiquidtyRecieve_state);
	free(bank_BankCreditIncomeStatement_state);
	free(bank_BankCreditLiquidityNeed_state);
	free(bank_BankCreditLoanInterests_state);
	free(bank_BankCreditNewEntrants_state);
	free(bank_BankCreditLoanWriteOffs_state);
	free(bank_BankCreditRequest2_state);
	free(bank_BankHousingMarket_state);
	free(bank_end_state);
	free(bank_BankUpdateDeposits_state);
	free(bank_BankCreditStart_state);
	free(bank_start_state);
}

void transition_bank_agent(xmachine_memory_bank_holder * tmp, xmachine_memory_bank_state * from_state, xmachine_memory_bank_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_bank_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_bank_agent_internal(xmachine_memory_bank * agent, xmachine_memory_bank_state * state)
{
	xmachine_memory_bank_holder * current = (xmachine_memory_bank_holder *)malloc(sizeof(xmachine_memory_bank_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_bank_agent(int id, int day_of_month_to_act, int day_of_week_to_act, double total_assets, double loans, double mortgages, double deposits, double centralbank_debt, double equity, double liquidity, double revenues, double total_writeoffs, double interests_accrued, double interests_paid, double dividends_paid, double total_dividends, double retained_earnings, double net_earnings, double total_costs)
 * \brief Add bank X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param day_of_week_to_act Variable for the X-machine memory.
 * \param total_assets Variable for the X-machine memory.
 * \param loans Variable for the X-machine memory.
 * \param mortgages Variable for the X-machine memory.
 * \param deposits Variable for the X-machine memory.
 * \param centralbank_debt Variable for the X-machine memory.
 * \param equity Variable for the X-machine memory.
 * \param liquidity Variable for the X-machine memory.
 * \param revenues Variable for the X-machine memory.
 * \param total_writeoffs Variable for the X-machine memory.
 * \param interests_accrued Variable for the X-machine memory.
 * \param interests_paid Variable for the X-machine memory.
 * \param dividends_paid Variable for the X-machine memory.
 * \param total_dividends Variable for the X-machine memory.
 * \param retained_earnings Variable for the X-machine memory.
 * \param net_earnings Variable for the X-machine memory.
 * \param total_costs Variable for the X-machine memory.
 */
void add_bank_agent(int id, int day_of_month_to_act, int day_of_week_to_act, double total_assets, double loans, double mortgages, double deposits, double centralbank_debt, double equity, double liquidity, double revenues, double total_writeoffs, double interests_accrued, double interests_paid, double dividends_paid, double total_dividends, double retained_earnings, double net_earnings, double total_costs)
{
	xmachine_memory_bank * current;

	current = init_bank_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_bank_next_state = bank_start_state;
	add_bank_agent_internal(current, current_xmachine_bank_next_state);

	current->id = id;
	current->day_of_month_to_act = day_of_month_to_act;
	current->day_of_week_to_act = day_of_week_to_act;
	current->total_assets = total_assets;
	current->loans = loans;
	current->mortgages = mortgages;
	current->deposits = deposits;
	current->centralbank_debt = centralbank_debt;
	current->equity = equity;
	current->liquidity = liquidity;
	current->revenues = revenues;
	current->total_writeoffs = total_writeoffs;
	current->interests_accrued = interests_accrued;
	current->interests_paid = interests_paid;
	current->dividends_paid = dividends_paid;
	current->total_dividends = total_dividends;
	current->retained_earnings = retained_earnings;
	current->net_earnings = net_earnings;
	current->total_costs = total_costs;
}

xmachine_memory_government_state * init_government_state()
{
	xmachine_memory_government_state * current = (xmachine_memory_government_state *)malloc(sizeof(xmachine_memory_government_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_government * init_government_agent()
{
	xmachine_memory_government * current = (xmachine_memory_government *)malloc(sizeof(xmachine_memory_government));
	CHECK_POINTER(current);

	current->id = 0;
	current->average_wage = 0.0;
	current->unemployment_rate = 0.0;
	current->population_size = 0;
	current->debt = 0.0;
	current->equity = 0.0;
	current->liquidity = 0.0;
	current->day_of_month_to_act = 0;
	current->gov_tax_rate = 0.0;
	current->labour_tax_income = 0.0;
	current->capital_tax_income = 0.0;
	current->gov_general_benefit_rate = 0.0;
	current->gov_unemployment_rate = 0.0;
	current->general_benefits = 0.0;
	current->unemployment_benefits = 0.0;
	current->earnings = 0.0;
	current->expenditures = 0.0;

	return current;
}

void free_government_agent(xmachine_memory_government_holder * tmp, xmachine_memory_government_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_government_agent()
{
	current_xmachine_government = (xmachine_memory_government *)malloc(sizeof(xmachine_memory_government));
	CHECK_POINTER(current);

		current_xmachine_government->id = 0;
		current_xmachine_government->average_wage = 0.0;
		current_xmachine_government->unemployment_rate = 0.0;
		current_xmachine_government->population_size = 0;
		current_xmachine_government->debt = 0.0;
		current_xmachine_government->equity = 0.0;
		current_xmachine_government->liquidity = 0.0;
		current_xmachine_government->day_of_month_to_act = 0;
		current_xmachine_government->gov_tax_rate = 0.0;
		current_xmachine_government->labour_tax_income = 0.0;
		current_xmachine_government->capital_tax_income = 0.0;
		current_xmachine_government->gov_general_benefit_rate = 0.0;
		current_xmachine_government->gov_unemployment_rate = 0.0;
		current_xmachine_government->general_benefits = 0.0;
		current_xmachine_government->unemployment_benefits = 0.0;
		current_xmachine_government->earnings = 0.0;
		current_xmachine_government->expenditures = 0.0;
	
}

void unittest_free_government_agent()
{
	
	free(current_xmachine_government);
}

void free_government_agents()
{
	current_xmachine_government_holder = government_GovernmentLabourTax_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		free_government_agent(current_xmachine_government_holder, government_GovernmentLabourTax_state);
		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	government_GovernmentLabourTax_state->count = 0;
	current_xmachine_government_holder = government_GovernmentUnemploymentBenefits_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		free_government_agent(current_xmachine_government_holder, government_GovernmentUnemploymentBenefits_state);
		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	government_GovernmentUnemploymentBenefits_state->count = 0;
	current_xmachine_government_holder = government_GovernmentBalanceSheet_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		free_government_agent(current_xmachine_government_holder, government_GovernmentBalanceSheet_state);
		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	government_GovernmentBalanceSheet_state->count = 0;
	current_xmachine_government_holder = government_GovernmentIncomeStatement_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		free_government_agent(current_xmachine_government_holder, government_GovernmentIncomeStatement_state);
		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	government_GovernmentIncomeStatement_state->count = 0;
	current_xmachine_government_holder = government_GovernmentCapitalTax_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		free_government_agent(current_xmachine_government_holder, government_GovernmentCapitalTax_state);
		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	government_GovernmentCapitalTax_state->count = 0;
	current_xmachine_government_holder = government_GovernmentMonthly_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		free_government_agent(current_xmachine_government_holder, government_GovernmentMonthly_state);
		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	government_GovernmentMonthly_state->count = 0;
	current_xmachine_government_holder = government_end_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		free_government_agent(current_xmachine_government_holder, government_end_state);
		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	government_end_state->count = 0;
	current_xmachine_government_holder = government_GovernmentLabourStatus_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		free_government_agent(current_xmachine_government_holder, government_GovernmentLabourStatus_state);
		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	government_GovernmentLabourStatus_state->count = 0;
	current_xmachine_government_holder = government_GovernmentStart_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		free_government_agent(current_xmachine_government_holder, government_GovernmentStart_state);
		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	government_GovernmentStart_state->count = 0;
	current_xmachine_government_holder = government_start_state->agents;
	while(current_xmachine_government_holder)
	{
		temp_xmachine_government_holder = current_xmachine_government_holder->next;
		free_government_agent(current_xmachine_government_holder, government_start_state);
		current_xmachine_government_holder = temp_xmachine_government_holder;
	}
	government_start_state->count = 0;
}

void free_government_states()
{
	free(government_GovernmentLabourTax_state);
	free(government_GovernmentUnemploymentBenefits_state);
	free(government_GovernmentBalanceSheet_state);
	free(government_GovernmentIncomeStatement_state);
	free(government_GovernmentCapitalTax_state);
	free(government_GovernmentMonthly_state);
	free(government_end_state);
	free(government_GovernmentLabourStatus_state);
	free(government_GovernmentStart_state);
	free(government_start_state);
}

void transition_government_agent(xmachine_memory_government_holder * tmp, xmachine_memory_government_state * from_state, xmachine_memory_government_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_government_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_government_agent_internal(xmachine_memory_government * agent, xmachine_memory_government_state * state)
{
	xmachine_memory_government_holder * current = (xmachine_memory_government_holder *)malloc(sizeof(xmachine_memory_government_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_government_agent(int id, double average_wage, double unemployment_rate, int population_size, double debt, double equity, double liquidity, int day_of_month_to_act, double gov_tax_rate, double labour_tax_income, double capital_tax_income, double gov_general_benefit_rate, double gov_unemployment_rate, double general_benefits, double unemployment_benefits, double earnings, double expenditures)
 * \brief Add government X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param average_wage Variable for the X-machine memory.
 * \param unemployment_rate Variable for the X-machine memory.
 * \param population_size Variable for the X-machine memory.
 * \param debt Variable for the X-machine memory.
 * \param equity Variable for the X-machine memory.
 * \param liquidity Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param gov_tax_rate Variable for the X-machine memory.
 * \param labour_tax_income Variable for the X-machine memory.
 * \param capital_tax_income Variable for the X-machine memory.
 * \param gov_general_benefit_rate Variable for the X-machine memory.
 * \param gov_unemployment_rate Variable for the X-machine memory.
 * \param general_benefits Variable for the X-machine memory.
 * \param unemployment_benefits Variable for the X-machine memory.
 * \param earnings Variable for the X-machine memory.
 * \param expenditures Variable for the X-machine memory.
 */
void add_government_agent(int id, double average_wage, double unemployment_rate, int population_size, double debt, double equity, double liquidity, int day_of_month_to_act, double gov_tax_rate, double labour_tax_income, double capital_tax_income, double gov_general_benefit_rate, double gov_unemployment_rate, double general_benefits, double unemployment_benefits, double earnings, double expenditures)
{
	xmachine_memory_government * current;

	current = init_government_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_government_next_state = government_start_state;
	add_government_agent_internal(current, current_xmachine_government_next_state);

	current->id = id;
	current->average_wage = average_wage;
	current->unemployment_rate = unemployment_rate;
	current->population_size = population_size;
	current->debt = debt;
	current->equity = equity;
	current->liquidity = liquidity;
	current->day_of_month_to_act = day_of_month_to_act;
	current->gov_tax_rate = gov_tax_rate;
	current->labour_tax_income = labour_tax_income;
	current->capital_tax_income = capital_tax_income;
	current->gov_general_benefit_rate = gov_general_benefit_rate;
	current->gov_unemployment_rate = gov_unemployment_rate;
	current->general_benefits = general_benefits;
	current->unemployment_benefits = unemployment_benefits;
	current->earnings = earnings;
	current->expenditures = expenditures;
}

xmachine_memory_centralbank_state * init_centralbank_state()
{
	xmachine_memory_centralbank_state * current = (xmachine_memory_centralbank_state *)malloc(sizeof(xmachine_memory_centralbank_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_centralbank * init_centralbank_agent()
{
	xmachine_memory_centralbank * current = (xmachine_memory_centralbank *)malloc(sizeof(xmachine_memory_centralbank));
	CHECK_POINTER(current);

	current->id = 0;
	current->day_of_month_to_act = 0;
	current->unemployment_rate = 0.0;
	init_double_static_array(current->consumption_goods_prices, 12);
	current->day_of_week_to_act = 0;
	init_transaction(&current->goods);
	init_double_static_array(current->weekly_price_averages, 4);
	current->interest_rate = 0.0;
	current->liquidity = 0.0;
	current->loans_banks = 0.0;
	current->loans_government = 0.0;
	current->fiat_money = 0.0;
	current->equity = 0.0;
	current->liquidity_banks = 0.0;
	current->liquidity_government = 0.0;
	current->total_assets = 0.0;
	current->total_writeoffs = 0.0;
	current->interests_accrued = 0.0;
	current->revenues = 0.0;
	current->net_earnings = 0.0;
	current->total_costs = 0.0;
	init_transaction(&current->houses);

	return current;
}

void free_centralbank_agent(xmachine_memory_centralbank_holder * tmp, xmachine_memory_centralbank_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	free_transaction(&tmp->agent->goods);
	free_transaction(&tmp->agent->houses);
	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_centralbank_agent()
{
	current_xmachine_centralbank = (xmachine_memory_centralbank *)malloc(sizeof(xmachine_memory_centralbank));
	CHECK_POINTER(current);

		current_xmachine_centralbank->id = 0;
		current_xmachine_centralbank->day_of_month_to_act = 0;
		current_xmachine_centralbank->unemployment_rate = 0.0;
		init_double_static_array(current_xmachine_centralbank->consumption_goods_prices, 12);
		current_xmachine_centralbank->day_of_week_to_act = 0;
		init_transaction(&current_xmachine_centralbank->goods);
		init_double_static_array(current_xmachine_centralbank->weekly_price_averages, 4);
		current_xmachine_centralbank->interest_rate = 0.0;
		current_xmachine_centralbank->liquidity = 0.0;
		current_xmachine_centralbank->loans_banks = 0.0;
		current_xmachine_centralbank->loans_government = 0.0;
		current_xmachine_centralbank->fiat_money = 0.0;
		current_xmachine_centralbank->equity = 0.0;
		current_xmachine_centralbank->liquidity_banks = 0.0;
		current_xmachine_centralbank->liquidity_government = 0.0;
		current_xmachine_centralbank->total_assets = 0.0;
		current_xmachine_centralbank->total_writeoffs = 0.0;
		current_xmachine_centralbank->interests_accrued = 0.0;
		current_xmachine_centralbank->revenues = 0.0;
		current_xmachine_centralbank->net_earnings = 0.0;
		current_xmachine_centralbank->total_costs = 0.0;
		init_transaction(&current_xmachine_centralbank->houses);
	
}

void unittest_free_centralbank_agent()
{
	free_transaction(&current_xmachine_centralbank->goods);
	free_transaction(&current_xmachine_centralbank->houses);
	
	free(current_xmachine_centralbank);
}

void free_centralbank_agents()
{
	current_xmachine_centralbank_holder = centralbank_end_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_end_state);
		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	centralbank_end_state->count = 0;
	current_xmachine_centralbank_holder = centralbank_CentralBankBalanceSheet_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankBalanceSheet_state);
		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	centralbank_CentralBankBalanceSheet_state->count = 0;
	current_xmachine_centralbank_holder = centralbank_CentralBankIncomeStatement_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankIncomeStatement_state);
		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	centralbank_CentralBankIncomeStatement_state->count = 0;
	current_xmachine_centralbank_holder = centralbank_CentralBankDebtRequests_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankDebtRequests_state);
		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	centralbank_CentralBankDebtRequests_state->count = 0;
	current_xmachine_centralbank_holder = centralbank_CentralBankLabour_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankLabour_state);
		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	centralbank_CentralBankLabour_state->count = 0;
	current_xmachine_centralbank_holder = centralbank_CentralBankHousing_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankHousing_state);
		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	centralbank_CentralBankHousing_state->count = 0;
	current_xmachine_centralbank_holder = centralbank_CentralBankConsumption_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankConsumption_state);
		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	centralbank_CentralBankConsumption_state->count = 0;
	current_xmachine_centralbank_holder = centralbank_CentralBankCredit_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_CentralBankCredit_state);
		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	centralbank_CentralBankCredit_state->count = 0;
	current_xmachine_centralbank_holder = centralbank_start_state->agents;
	while(current_xmachine_centralbank_holder)
	{
		temp_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
		free_centralbank_agent(current_xmachine_centralbank_holder, centralbank_start_state);
		current_xmachine_centralbank_holder = temp_xmachine_centralbank_holder;
	}
	centralbank_start_state->count = 0;
}

void free_centralbank_states()
{
	free(centralbank_end_state);
	free(centralbank_CentralBankBalanceSheet_state);
	free(centralbank_CentralBankIncomeStatement_state);
	free(centralbank_CentralBankDebtRequests_state);
	free(centralbank_CentralBankLabour_state);
	free(centralbank_CentralBankHousing_state);
	free(centralbank_CentralBankConsumption_state);
	free(centralbank_CentralBankCredit_state);
	free(centralbank_start_state);
}

void transition_centralbank_agent(xmachine_memory_centralbank_holder * tmp, xmachine_memory_centralbank_state * from_state, xmachine_memory_centralbank_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_centralbank_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_centralbank_agent_internal(xmachine_memory_centralbank * agent, xmachine_memory_centralbank_state * state)
{
	xmachine_memory_centralbank_holder * current = (xmachine_memory_centralbank_holder *)malloc(sizeof(xmachine_memory_centralbank_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_centralbank_agent(int id, int day_of_month_to_act, double unemployment_rate, double consumption_goods_prices[], int day_of_week_to_act, transaction * goods, double weekly_price_averages[], double interest_rate, double liquidity, double loans_banks, double loans_government, double fiat_money, double equity, double liquidity_banks, double liquidity_government, double total_assets, double total_writeoffs, double interests_accrued, double revenues, double net_earnings, double total_costs, transaction * houses)
 * \brief Add centralbank X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param unemployment_rate Variable for the X-machine memory.
 * \param consumption_goods_prices Variable for the X-machine memory.
 * \param day_of_week_to_act Variable for the X-machine memory.
 * \param goods Variable for the X-machine memory.
 * \param weekly_price_averages Variable for the X-machine memory.
 * \param interest_rate Variable for the X-machine memory.
 * \param liquidity Variable for the X-machine memory.
 * \param loans_banks Variable for the X-machine memory.
 * \param loans_government Variable for the X-machine memory.
 * \param fiat_money Variable for the X-machine memory.
 * \param equity Variable for the X-machine memory.
 * \param liquidity_banks Variable for the X-machine memory.
 * \param liquidity_government Variable for the X-machine memory.
 * \param total_assets Variable for the X-machine memory.
 * \param total_writeoffs Variable for the X-machine memory.
 * \param interests_accrued Variable for the X-machine memory.
 * \param revenues Variable for the X-machine memory.
 * \param net_earnings Variable for the X-machine memory.
 * \param total_costs Variable for the X-machine memory.
 * \param houses Variable for the X-machine memory.
 */
void add_centralbank_agent(int id, int day_of_month_to_act, double unemployment_rate, double consumption_goods_prices[], int day_of_week_to_act, transaction goods, double weekly_price_averages[], double interest_rate, double liquidity, double loans_banks, double loans_government, double fiat_money, double equity, double liquidity_banks, double liquidity_government, double total_assets, double total_writeoffs, double interests_accrued, double revenues, double net_earnings, double total_costs, transaction houses)
{
	xmachine_memory_centralbank * current;

	current = init_centralbank_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_centralbank_next_state = centralbank_start_state;
	add_centralbank_agent_internal(current, current_xmachine_centralbank_next_state);

	current->id = id;
	current->day_of_month_to_act = day_of_month_to_act;
	current->unemployment_rate = unemployment_rate;
	memcpy(current->consumption_goods_prices, consumption_goods_prices, 12*sizeof(double));
	current->day_of_week_to_act = day_of_week_to_act;
	copy_transaction(&goods, &current->goods);
	memcpy(current->weekly_price_averages, weekly_price_averages, 4*sizeof(double));
	current->interest_rate = interest_rate;
	current->liquidity = liquidity;
	current->loans_banks = loans_banks;
	current->loans_government = loans_government;
	current->fiat_money = fiat_money;
	current->equity = equity;
	current->liquidity_banks = liquidity_banks;
	current->liquidity_government = liquidity_government;
	current->total_assets = total_assets;
	current->total_writeoffs = total_writeoffs;
	current->interests_accrued = interests_accrued;
	current->revenues = revenues;
	current->net_earnings = net_earnings;
	current->total_costs = total_costs;
	copy_transaction(&houses, &current->houses);
}

xmachine_memory_jpoffice_state * init_jpoffice_state()
{
	xmachine_memory_jpoffice_state * current = (xmachine_memory_jpoffice_state *)malloc(sizeof(xmachine_memory_jpoffice_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_jpoffice * init_jpoffice_agent()
{
	xmachine_memory_jpoffice * current = (xmachine_memory_jpoffice *)malloc(sizeof(xmachine_memory_jpoffice));
	CHECK_POINTER(current);

	current->id = 0;
	current->day_of_month_to_act = 0;

	return current;
}

void free_jpoffice_agent(xmachine_memory_jpoffice_holder * tmp, xmachine_memory_jpoffice_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_jpoffice_agent()
{
	current_xmachine_jpoffice = (xmachine_memory_jpoffice *)malloc(sizeof(xmachine_memory_jpoffice));
	CHECK_POINTER(current);

		current_xmachine_jpoffice->id = 0;
		current_xmachine_jpoffice->day_of_month_to_act = 0;
	
}

void unittest_free_jpoffice_agent()
{
	
	free(current_xmachine_jpoffice);
}

void free_jpoffice_agents()
{
	current_xmachine_jpoffice_holder = jpoffice_JPOLabourStage2_state->agents;
	while(current_xmachine_jpoffice_holder)
	{
		temp_xmachine_jpoffice_holder = current_xmachine_jpoffice_holder->next;
		free_jpoffice_agent(current_xmachine_jpoffice_holder, jpoffice_JPOLabourStage2_state);
		current_xmachine_jpoffice_holder = temp_xmachine_jpoffice_holder;
	}
	jpoffice_JPOLabourStage2_state->count = 0;
	current_xmachine_jpoffice_holder = jpoffice_end_state->agents;
	while(current_xmachine_jpoffice_holder)
	{
		temp_xmachine_jpoffice_holder = current_xmachine_jpoffice_holder->next;
		free_jpoffice_agent(current_xmachine_jpoffice_holder, jpoffice_end_state);
		current_xmachine_jpoffice_holder = temp_xmachine_jpoffice_holder;
	}
	jpoffice_end_state->count = 0;
	current_xmachine_jpoffice_holder = jpoffice_JPOLabourMarket_state->agents;
	while(current_xmachine_jpoffice_holder)
	{
		temp_xmachine_jpoffice_holder = current_xmachine_jpoffice_holder->next;
		free_jpoffice_agent(current_xmachine_jpoffice_holder, jpoffice_JPOLabourMarket_state);
		current_xmachine_jpoffice_holder = temp_xmachine_jpoffice_holder;
	}
	jpoffice_JPOLabourMarket_state->count = 0;
	current_xmachine_jpoffice_holder = jpoffice_start_state->agents;
	while(current_xmachine_jpoffice_holder)
	{
		temp_xmachine_jpoffice_holder = current_xmachine_jpoffice_holder->next;
		free_jpoffice_agent(current_xmachine_jpoffice_holder, jpoffice_start_state);
		current_xmachine_jpoffice_holder = temp_xmachine_jpoffice_holder;
	}
	jpoffice_start_state->count = 0;
}

void free_jpoffice_states()
{
	free(jpoffice_JPOLabourStage2_state);
	free(jpoffice_end_state);
	free(jpoffice_JPOLabourMarket_state);
	free(jpoffice_start_state);
}

void transition_jpoffice_agent(xmachine_memory_jpoffice_holder * tmp, xmachine_memory_jpoffice_state * from_state, xmachine_memory_jpoffice_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_jpoffice_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_jpoffice_agent_internal(xmachine_memory_jpoffice * agent, xmachine_memory_jpoffice_state * state)
{
	xmachine_memory_jpoffice_holder * current = (xmachine_memory_jpoffice_holder *)malloc(sizeof(xmachine_memory_jpoffice_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_jpoffice_agent(int id, int day_of_month_to_act)
 * \brief Add jpoffice X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 */
void add_jpoffice_agent(int id, int day_of_month_to_act)
{
	xmachine_memory_jpoffice * current;

	current = init_jpoffice_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_jpoffice_next_state = jpoffice_start_state;
	add_jpoffice_agent_internal(current, current_xmachine_jpoffice_next_state);

	current->id = id;
	current->day_of_month_to_act = day_of_month_to_act;
}

xmachine_memory_mall_state * init_mall_state()
{
	xmachine_memory_mall_state * current = (xmachine_memory_mall_state *)malloc(sizeof(xmachine_memory_mall_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_mall * init_mall_agent()
{
	xmachine_memory_mall * current = (xmachine_memory_mall *)malloc(sizeof(xmachine_memory_mall));
	CHECK_POINTER(current);

	current->id = 0;
	current->day_of_week_to_act = 0;
	init_transaction(&current->goods_transactions);

	return current;
}

void free_mall_agent(xmachine_memory_mall_holder * tmp, xmachine_memory_mall_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	free_transaction(&tmp->agent->goods_transactions);
	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_mall_agent()
{
	current_xmachine_mall = (xmachine_memory_mall *)malloc(sizeof(xmachine_memory_mall));
	CHECK_POINTER(current);

		current_xmachine_mall->id = 0;
		current_xmachine_mall->day_of_week_to_act = 0;
		init_transaction(&current_xmachine_mall->goods_transactions);
	
}

void unittest_free_mall_agent()
{
	free_transaction(&current_xmachine_mall->goods_transactions);
	
	free(current_xmachine_mall);
}

void free_mall_agents()
{
	current_xmachine_mall_holder = mall_MallConsumptionSummary_state->agents;
	while(current_xmachine_mall_holder)
	{
		temp_xmachine_mall_holder = current_xmachine_mall_holder->next;
		free_mall_agent(current_xmachine_mall_holder, mall_MallConsumptionSummary_state);
		current_xmachine_mall_holder = temp_xmachine_mall_holder;
	}
	mall_MallConsumptionSummary_state->count = 0;
	current_xmachine_mall_holder = mall_end_state->agents;
	while(current_xmachine_mall_holder)
	{
		temp_xmachine_mall_holder = current_xmachine_mall_holder->next;
		free_mall_agent(current_xmachine_mall_holder, mall_end_state);
		current_xmachine_mall_holder = temp_xmachine_mall_holder;
	}
	mall_end_state->count = 0;
	current_xmachine_mall_holder = mall_MallConsumptionMarket_state->agents;
	while(current_xmachine_mall_holder)
	{
		temp_xmachine_mall_holder = current_xmachine_mall_holder->next;
		free_mall_agent(current_xmachine_mall_holder, mall_MallConsumptionMarket_state);
		current_xmachine_mall_holder = temp_xmachine_mall_holder;
	}
	mall_MallConsumptionMarket_state->count = 0;
	current_xmachine_mall_holder = mall_start_state->agents;
	while(current_xmachine_mall_holder)
	{
		temp_xmachine_mall_holder = current_xmachine_mall_holder->next;
		free_mall_agent(current_xmachine_mall_holder, mall_start_state);
		current_xmachine_mall_holder = temp_xmachine_mall_holder;
	}
	mall_start_state->count = 0;
}

void free_mall_states()
{
	free(mall_MallConsumptionSummary_state);
	free(mall_end_state);
	free(mall_MallConsumptionMarket_state);
	free(mall_start_state);
}

void transition_mall_agent(xmachine_memory_mall_holder * tmp, xmachine_memory_mall_state * from_state, xmachine_memory_mall_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_mall_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_mall_agent_internal(xmachine_memory_mall * agent, xmachine_memory_mall_state * state)
{
	xmachine_memory_mall_holder * current = (xmachine_memory_mall_holder *)malloc(sizeof(xmachine_memory_mall_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_mall_agent(int id, int day_of_week_to_act, transaction * goods_transactions)
 * \brief Add mall X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param day_of_week_to_act Variable for the X-machine memory.
 * \param goods_transactions Variable for the X-machine memory.
 */
void add_mall_agent(int id, int day_of_week_to_act, transaction goods_transactions)
{
	xmachine_memory_mall * current;

	current = init_mall_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_mall_next_state = mall_start_state;
	add_mall_agent_internal(current, current_xmachine_mall_next_state);

	current->id = id;
	current->day_of_week_to_act = day_of_week_to_act;
	copy_transaction(&goods_transactions, &current->goods_transactions);
}

xmachine_memory_reagency_state * init_reagency_state()
{
	xmachine_memory_reagency_state * current = (xmachine_memory_reagency_state *)malloc(sizeof(xmachine_memory_reagency_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_reagency * init_reagency_agent()
{
	xmachine_memory_reagency * current = (xmachine_memory_reagency *)malloc(sizeof(xmachine_memory_reagency));
	CHECK_POINTER(current);

	current->id = 0;
	current->day_of_month_to_act = 0;
	current->mortgages_interest_rate = 0.0;
	init_transaction(&current->housing_transactions);

	return current;
}

void free_reagency_agent(xmachine_memory_reagency_holder * tmp, xmachine_memory_reagency_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	free_transaction(&tmp->agent->housing_transactions);
	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_reagency_agent()
{
	current_xmachine_reagency = (xmachine_memory_reagency *)malloc(sizeof(xmachine_memory_reagency));
	CHECK_POINTER(current);

		current_xmachine_reagency->id = 0;
		current_xmachine_reagency->day_of_month_to_act = 0;
		current_xmachine_reagency->mortgages_interest_rate = 0.0;
		init_transaction(&current_xmachine_reagency->housing_transactions);
	
}

void unittest_free_reagency_agent()
{
	free_transaction(&current_xmachine_reagency->housing_transactions);
	
	free(current_xmachine_reagency);
}

void free_reagency_agents()
{
	current_xmachine_reagency_holder = reagency_REAgencyHousingSummary_state->agents;
	while(current_xmachine_reagency_holder)
	{
		temp_xmachine_reagency_holder = current_xmachine_reagency_holder->next;
		free_reagency_agent(current_xmachine_reagency_holder, reagency_REAgencyHousingSummary_state);
		current_xmachine_reagency_holder = temp_xmachine_reagency_holder;
	}
	reagency_REAgencyHousingSummary_state->count = 0;
	current_xmachine_reagency_holder = reagency_REAgencyHousingProcess_state->agents;
	while(current_xmachine_reagency_holder)
	{
		temp_xmachine_reagency_holder = current_xmachine_reagency_holder->next;
		free_reagency_agent(current_xmachine_reagency_holder, reagency_REAgencyHousingProcess_state);
		current_xmachine_reagency_holder = temp_xmachine_reagency_holder;
	}
	reagency_REAgencyHousingProcess_state->count = 0;
	current_xmachine_reagency_holder = reagency_end_state->agents;
	while(current_xmachine_reagency_holder)
	{
		temp_xmachine_reagency_holder = current_xmachine_reagency_holder->next;
		free_reagency_agent(current_xmachine_reagency_holder, reagency_end_state);
		current_xmachine_reagency_holder = temp_xmachine_reagency_holder;
	}
	reagency_end_state->count = 0;
	current_xmachine_reagency_holder = reagency_REAgencyHousingMarket_state->agents;
	while(current_xmachine_reagency_holder)
	{
		temp_xmachine_reagency_holder = current_xmachine_reagency_holder->next;
		free_reagency_agent(current_xmachine_reagency_holder, reagency_REAgencyHousingMarket_state);
		current_xmachine_reagency_holder = temp_xmachine_reagency_holder;
	}
	reagency_REAgencyHousingMarket_state->count = 0;
	current_xmachine_reagency_holder = reagency_start_state->agents;
	while(current_xmachine_reagency_holder)
	{
		temp_xmachine_reagency_holder = current_xmachine_reagency_holder->next;
		free_reagency_agent(current_xmachine_reagency_holder, reagency_start_state);
		current_xmachine_reagency_holder = temp_xmachine_reagency_holder;
	}
	reagency_start_state->count = 0;
}

void free_reagency_states()
{
	free(reagency_REAgencyHousingSummary_state);
	free(reagency_REAgencyHousingProcess_state);
	free(reagency_end_state);
	free(reagency_REAgencyHousingMarket_state);
	free(reagency_start_state);
}

void transition_reagency_agent(xmachine_memory_reagency_holder * tmp, xmachine_memory_reagency_state * from_state, xmachine_memory_reagency_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_reagency_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_reagency_agent_internal(xmachine_memory_reagency * agent, xmachine_memory_reagency_state * state)
{
	xmachine_memory_reagency_holder * current = (xmachine_memory_reagency_holder *)malloc(sizeof(xmachine_memory_reagency_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_reagency_agent(int id, int day_of_month_to_act, double mortgages_interest_rate, transaction * housing_transactions)
 * \brief Add reagency X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param mortgages_interest_rate Variable for the X-machine memory.
 * \param housing_transactions Variable for the X-machine memory.
 */
void add_reagency_agent(int id, int day_of_month_to_act, double mortgages_interest_rate, transaction housing_transactions)
{
	xmachine_memory_reagency * current;

	current = init_reagency_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_reagency_next_state = reagency_start_state;
	add_reagency_agent_internal(current, current_xmachine_reagency_next_state);

	current->id = id;
	current->day_of_month_to_act = day_of_month_to_act;
	current->mortgages_interest_rate = mortgages_interest_rate;
	copy_transaction(&housing_transactions, &current->housing_transactions);
}


/* freexmachines */
/** \fn void freexmachines()
 * \brief Free the currently being used X-machine list.
 */
void freexmachines()
{
	free_firm_agents();
	free_household_agents();
	free_equityfund_agents();
	free_bank_agents();
	free_government_agents();
	free_centralbank_agents();
	free_jpoffice_agents();
	free_mall_agents();
	free_reagency_agents();
	
}


/** \fn void set_id(int id)
 * \brief Set id memory variable for current X-machine.
 * \param id New value for variable.
 */
void set_id(int id)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).id = id;
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).id = id;
	if(current_xmachine->xmachine_equityfund) (*current_xmachine->xmachine_equityfund).id = id;
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).id = id;
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).id = id;
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).id = id;
	if(current_xmachine->xmachine_jpoffice) (*current_xmachine->xmachine_jpoffice).id = id;
	if(current_xmachine->xmachine_mall) (*current_xmachine->xmachine_mall).id = id;
	if(current_xmachine->xmachine_reagency) (*current_xmachine->xmachine_reagency).id = id;
}

/** \fn int get_id()
 * \brief Get id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_id()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).id;
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).id;
	if(current_xmachine->xmachine_equityfund) return (*current_xmachine->xmachine_equityfund).id;
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).id;
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).id;
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).id;
	if(current_xmachine->xmachine_jpoffice) return (*current_xmachine->xmachine_jpoffice).id;
	if(current_xmachine->xmachine_mall) return (*current_xmachine->xmachine_mall).id;
	if(current_xmachine->xmachine_reagency) return (*current_xmachine->xmachine_reagency).id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_bank_id(int bank_id)
 * \brief Set bank_id memory variable for current X-machine.
 * \param bank_id New value for variable.
 */
void set_bank_id(int bank_id)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).bank_id = bank_id;
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).bank_id = bank_id;
}

/** \fn int get_bank_id()
 * \brief Get bank_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_bank_id()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).bank_id;
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).bank_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_isconstructor(int isconstructor)
 * \brief Set isconstructor memory variable for current X-machine.
 * \param isconstructor New value for variable.
 */
void set_isconstructor(int isconstructor)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).isconstructor = isconstructor;
}

/** \fn int get_isconstructor()
 * \brief Get isconstructor memory variable from current X-machine.
 * \return Value for variable.
 */
int get_isconstructor()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).isconstructor;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_day_of_month_to_act(int day_of_month_to_act)
 * \brief Set day_of_month_to_act memory variable for current X-machine.
 * \param day_of_month_to_act New value for variable.
 */
void set_day_of_month_to_act(int day_of_month_to_act)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).day_of_month_to_act = day_of_month_to_act;
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).day_of_month_to_act = day_of_month_to_act;
	if(current_xmachine->xmachine_equityfund) (*current_xmachine->xmachine_equityfund).day_of_month_to_act = day_of_month_to_act;
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).day_of_month_to_act = day_of_month_to_act;
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).day_of_month_to_act = day_of_month_to_act;
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).day_of_month_to_act = day_of_month_to_act;
	if(current_xmachine->xmachine_jpoffice) (*current_xmachine->xmachine_jpoffice).day_of_month_to_act = day_of_month_to_act;
	if(current_xmachine->xmachine_reagency) (*current_xmachine->xmachine_reagency).day_of_month_to_act = day_of_month_to_act;
}

/** \fn int get_day_of_month_to_act()
 * \brief Get day_of_month_to_act memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_month_to_act()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).day_of_month_to_act;
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).day_of_month_to_act;
	if(current_xmachine->xmachine_equityfund) return (*current_xmachine->xmachine_equityfund).day_of_month_to_act;
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).day_of_month_to_act;
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).day_of_month_to_act;
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).day_of_month_to_act;
	if(current_xmachine->xmachine_jpoffice) return (*current_xmachine->xmachine_jpoffice).day_of_month_to_act;
	if(current_xmachine->xmachine_reagency) return (*current_xmachine->xmachine_reagency).day_of_month_to_act;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_isinsolvent(int isinsolvent)
 * \brief Set isinsolvent memory variable for current X-machine.
 * \param isinsolvent New value for variable.
 */
void set_isinsolvent(int isinsolvent)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).isinsolvent = isinsolvent;
}

/** \fn int get_isinsolvent()
 * \brief Get isinsolvent memory variable from current X-machine.
 * \return Value for variable.
 */
int get_isinsolvent()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).isinsolvent;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_it_no(int it_no)
 * \brief Set it_no memory variable for current X-machine.
 * \param it_no New value for variable.
 */
void set_it_no(int it_no)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).it_no = it_no;
}

/** \fn int get_it_no()
 * \brief Get it_no memory variable from current X-machine.
 * \return Value for variable.
 */
int get_it_no()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).it_no;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_day_of_week_to_act(int day_of_week_to_act)
 * \brief Set day_of_week_to_act memory variable for current X-machine.
 * \param day_of_week_to_act New value for variable.
 */
void set_day_of_week_to_act(int day_of_week_to_act)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).day_of_week_to_act = day_of_week_to_act;
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).day_of_week_to_act = day_of_week_to_act;
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).day_of_week_to_act = day_of_week_to_act;
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).day_of_week_to_act = day_of_week_to_act;
	if(current_xmachine->xmachine_mall) (*current_xmachine->xmachine_mall).day_of_week_to_act = day_of_week_to_act;
}

/** \fn int get_day_of_week_to_act()
 * \brief Get day_of_week_to_act memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_week_to_act()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).day_of_week_to_act;
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).day_of_week_to_act;
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).day_of_week_to_act;
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).day_of_week_to_act;
	if(current_xmachine->xmachine_mall) return (*current_xmachine->xmachine_mall).day_of_week_to_act;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_average_goods_price(double average_goods_price)
 * \brief Set average_goods_price memory variable for current X-machine.
 * \param average_goods_price New value for variable.
 */
void set_average_goods_price(double average_goods_price)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).average_goods_price = average_goods_price;
}

/** \fn double get_average_goods_price()
 * \brief Get average_goods_price memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_goods_price()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).average_goods_price;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn int_array get_employees()
 * \brief Get employees memory variable from current X-machine.
 * \return Value for variable.
 */
int_array * get_employees()
{
	if(current_xmachine->xmachine_firm) return &(*current_xmachine->xmachine_firm).employees;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_wage_offer(double wage_offer)
 * \brief Set wage_offer memory variable for current X-machine.
 * \param wage_offer New value for variable.
 */
void set_wage_offer(double wage_offer)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).wage_offer = wage_offer;
}

/** \fn double get_wage_offer()
 * \brief Get wage_offer memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage_offer()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).wage_offer;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_wage(double average_wage)
 * \brief Set average_wage memory variable for current X-machine.
 * \param average_wage New value for variable.
 */
void set_average_wage(double average_wage)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).average_wage = average_wage;
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).average_wage = average_wage;
}

/** \fn double get_average_wage()
 * \brief Get average_wage memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_wage()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).average_wage;
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).average_wage;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_no_employees(int no_employees)
 * \brief Set no_employees memory variable for current X-machine.
 * \param no_employees New value for variable.
 */
void set_no_employees(int no_employees)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).no_employees = no_employees;
}

/** \fn int get_no_employees()
 * \brief Get no_employees memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_employees()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).no_employees;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_vacancies(int vacancies)
 * \brief Set vacancies memory variable for current X-machine.
 * \param vacancies New value for variable.
 */
void set_vacancies(int vacancies)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).vacancies = vacancies;
}

/** \fn int get_vacancies()
 * \brief Get vacancies memory variable from current X-machine.
 * \return Value for variable.
 */
int get_vacancies()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).vacancies;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_employees_needed(int employees_needed)
 * \brief Set employees_needed memory variable for current X-machine.
 * \param employees_needed New value for variable.
 */
void set_employees_needed(int employees_needed)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).employees_needed = employees_needed;
}

/** \fn int get_employees_needed()
 * \brief Get employees_needed memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employees_needed()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).employees_needed;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_day_of_month_wages_paid(int day_of_month_wages_paid)
 * \brief Set day_of_month_wages_paid memory variable for current X-machine.
 * \param day_of_month_wages_paid New value for variable.
 */
void set_day_of_month_wages_paid(int day_of_month_wages_paid)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).day_of_month_wages_paid = day_of_month_wages_paid;
}

/** \fn int get_day_of_month_wages_paid()
 * \brief Get day_of_month_wages_paid memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_month_wages_paid()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).day_of_month_wages_paid;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_labour_productivity(double labour_productivity)
 * \brief Set labour_productivity memory variable for current X-machine.
 * \param labour_productivity New value for variable.
 */
void set_labour_productivity(double labour_productivity)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).labour_productivity = labour_productivity;
}

/** \fn double get_labour_productivity()
 * \brief Get labour_productivity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_labour_productivity()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).labour_productivity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_production_current(int production_current)
 * \brief Set production_current memory variable for current X-machine.
 * \param production_current New value for variable.
 */
void set_production_current(int production_current)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).production_current = production_current;
}

/** \fn int get_production_current()
 * \brief Get production_current memory variable from current X-machine.
 * \return Value for variable.
 */
int get_production_current()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).production_current;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_production_estimate(int production_estimate)
 * \brief Set production_estimate memory variable for current X-machine.
 * \param production_estimate New value for variable.
 */
void set_production_estimate(int production_estimate)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).production_estimate = production_estimate;
}

/** \fn int get_production_estimate()
 * \brief Get production_estimate memory variable from current X-machine.
 * \return Value for variable.
 */
int get_production_estimate()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).production_estimate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_production_plan(int production_plan)
 * \brief Set production_plan memory variable for current X-machine.
 * \param production_plan New value for variable.
 */
void set_production_plan(int production_plan)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).production_plan = production_plan;
}

/** \fn int get_production_plan()
 * \brief Get production_plan memory variable from current X-machine.
 * \return Value for variable.
 */
int get_production_plan()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).production_plan;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_unit_goods_price(double unit_goods_price)
 * \brief Set unit_goods_price memory variable for current X-machine.
 * \param unit_goods_price New value for variable.
 */
void set_unit_goods_price(double unit_goods_price)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).unit_goods_price = unit_goods_price;
}

/** \fn double get_unit_goods_price()
 * \brief Get unit_goods_price memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unit_goods_price()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).unit_goods_price;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_day_of_month_production_completed(int day_of_month_production_completed)
 * \brief Set day_of_month_production_completed memory variable for current X-machine.
 * \param day_of_month_production_completed New value for variable.
 */
void set_day_of_month_production_completed(int day_of_month_production_completed)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).day_of_month_production_completed = day_of_month_production_completed;
}

/** \fn int get_day_of_month_production_completed()
 * \brief Get day_of_month_production_completed memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_month_production_completed()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).day_of_month_production_completed;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_unit_house_price(double unit_house_price)
 * \brief Set unit_house_price memory variable for current X-machine.
 * \param unit_house_price New value for variable.
 */
void set_unit_house_price(double unit_house_price)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).unit_house_price = unit_house_price;
}

/** \fn double get_unit_house_price()
 * \brief Get unit_house_price memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unit_house_price()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).unit_house_price;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_labour_productivity_construction(double labour_productivity_construction)
 * \brief Set labour_productivity_construction memory variable for current X-machine.
 * \param labour_productivity_construction New value for variable.
 */
void set_labour_productivity_construction(double labour_productivity_construction)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).labour_productivity_construction = labour_productivity_construction;
}

/** \fn double get_labour_productivity_construction()
 * \brief Get labour_productivity_construction memory variable from current X-machine.
 * \return Value for variable.
 */
double get_labour_productivity_construction()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).labour_productivity_construction;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_capital_productivity_construction(double capital_productivity_construction)
 * \brief Set capital_productivity_construction memory variable for current X-machine.
 * \param capital_productivity_construction New value for variable.
 */
void set_capital_productivity_construction(double capital_productivity_construction)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).capital_productivity_construction = capital_productivity_construction;
}

/** \fn double get_capital_productivity_construction()
 * \brief Get capital_productivity_construction memory variable from current X-machine.
 * \return Value for variable.
 */
double get_capital_productivity_construction()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).capital_productivity_construction;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_capital_construction(double capital_construction)
 * \brief Set capital_construction memory variable for current X-machine.
 * \param capital_construction New value for variable.
 */
void set_capital_construction(double capital_construction)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).capital_construction = capital_construction;
}

/** \fn double get_capital_construction()
 * \brief Get capital_construction memory variable from current X-machine.
 * \return Value for variable.
 */
double get_capital_construction()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).capital_construction;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_physical_capital(double physical_capital)
 * \brief Set physical_capital memory variable for current X-machine.
 * \param physical_capital New value for variable.
 */
void set_physical_capital(double physical_capital)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).physical_capital = physical_capital;
}

/** \fn double get_physical_capital()
 * \brief Get physical_capital memory variable from current X-machine.
 * \return Value for variable.
 */
double get_physical_capital()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).physical_capital;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn int get_projects()
 * \brief Get projects memory variable from current X-machine.
 * \return Value for variable.
 */
int * get_projects()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).projects;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_loans_interest_rate(double loans_interest_rate)
 * \brief Set loans_interest_rate memory variable for current X-machine.
 * \param loans_interest_rate New value for variable.
 */
void set_loans_interest_rate(double loans_interest_rate)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).loans_interest_rate = loans_interest_rate;
}

/** \fn double get_loans_interest_rate()
 * \brief Get loans_interest_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_loans_interest_rate()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).loans_interest_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_debt(double debt)
 * \brief Set debt memory variable for current X-machine.
 * \param debt New value for variable.
 */
void set_debt(double debt)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).debt = debt;
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).debt = debt;
}

/** \fn double get_debt()
 * \brief Get debt memory variable from current X-machine.
 * \return Value for variable.
 */
double get_debt()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).debt;
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).debt;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_inventory(int inventory)
 * \brief Set inventory memory variable for current X-machine.
 * \param inventory New value for variable.
 */
void set_inventory(int inventory)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).inventory = inventory;
}

/** \fn int get_inventory()
 * \brief Get inventory memory variable from current X-machine.
 * \return Value for variable.
 */
int get_inventory()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).inventory;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_sales(int sales)
 * \brief Set sales memory variable for current X-machine.
 * \param sales New value for variable.
 */
void set_sales(int sales)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).sales = sales;
}

/** \fn int get_sales()
 * \brief Get sales memory variable from current X-machine.
 * \return Value for variable.
 */
int get_sales()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).sales;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_revenues(double revenues)
 * \brief Set revenues memory variable for current X-machine.
 * \param revenues New value for variable.
 */
void set_revenues(double revenues)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).revenues = revenues;
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).revenues = revenues;
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).revenues = revenues;
}

/** \fn double get_revenues()
 * \brief Get revenues memory variable from current X-machine.
 * \return Value for variable.
 */
double get_revenues()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).revenues;
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).revenues;
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).revenues;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_assets(double total_assets)
 * \brief Set total_assets memory variable for current X-machine.
 * \param total_assets New value for variable.
 */
void set_total_assets(double total_assets)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).total_assets = total_assets;
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).total_assets = total_assets;
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).total_assets = total_assets;
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).total_assets = total_assets;
}

/** \fn double get_total_assets()
 * \brief Get total_assets memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_assets()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).total_assets;
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).total_assets;
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).total_assets;
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).total_assets;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_operating_costs(double operating_costs)
 * \brief Set operating_costs memory variable for current X-machine.
 * \param operating_costs New value for variable.
 */
void set_operating_costs(double operating_costs)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).operating_costs = operating_costs;
}

/** \fn double get_operating_costs()
 * \brief Get operating_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_operating_costs()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).operating_costs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_labour_costs(double labour_costs)
 * \brief Set labour_costs memory variable for current X-machine.
 * \param labour_costs New value for variable.
 */
void set_labour_costs(double labour_costs)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).labour_costs = labour_costs;
}

/** \fn double get_labour_costs()
 * \brief Get labour_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_labour_costs()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).labour_costs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_interest_payments(double total_interest_payments)
 * \brief Set total_interest_payments memory variable for current X-machine.
 * \param total_interest_payments New value for variable.
 */
void set_total_interest_payments(double total_interest_payments)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).total_interest_payments = total_interest_payments;
}

/** \fn double get_total_interest_payments()
 * \brief Get total_interest_payments memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_interest_payments()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).total_interest_payments;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_dividends_paid(double dividends_paid)
 * \brief Set dividends_paid memory variable for current X-machine.
 * \param dividends_paid New value for variable.
 */
void set_dividends_paid(double dividends_paid)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).dividends_paid = dividends_paid;
	if(current_xmachine->xmachine_equityfund) (*current_xmachine->xmachine_equityfund).dividends_paid = dividends_paid;
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).dividends_paid = dividends_paid;
}

/** \fn double get_dividends_paid()
 * \brief Get dividends_paid memory variable from current X-machine.
 * \return Value for variable.
 */
double get_dividends_paid()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).dividends_paid;
	if(current_xmachine->xmachine_equityfund) return (*current_xmachine->xmachine_equityfund).dividends_paid;
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).dividends_paid;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_dividends_to_be_paid(double dividends_to_be_paid)
 * \brief Set dividends_to_be_paid memory variable for current X-machine.
 * \param dividends_to_be_paid New value for variable.
 */
void set_dividends_to_be_paid(double dividends_to_be_paid)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).dividends_to_be_paid = dividends_to_be_paid;
}

/** \fn double get_dividends_to_be_paid()
 * \brief Get dividends_to_be_paid memory variable from current X-machine.
 * \return Value for variable.
 */
double get_dividends_to_be_paid()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).dividends_to_be_paid;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_retained_earnings(double retained_earnings)
 * \brief Set retained_earnings memory variable for current X-machine.
 * \param retained_earnings New value for variable.
 */
void set_retained_earnings(double retained_earnings)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).retained_earnings = retained_earnings;
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).retained_earnings = retained_earnings;
}

/** \fn double get_retained_earnings()
 * \brief Get retained_earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_retained_earnings()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).retained_earnings;
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).retained_earnings;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_net_earnings(double net_earnings)
 * \brief Set net_earnings memory variable for current X-machine.
 * \param net_earnings New value for variable.
 */
void set_net_earnings(double net_earnings)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).net_earnings = net_earnings;
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).net_earnings = net_earnings;
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).net_earnings = net_earnings;
}

/** \fn double get_net_earnings()
 * \brief Get net_earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_net_earnings()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).net_earnings;
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).net_earnings;
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).net_earnings;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_ebit(double ebit)
 * \brief Set ebit memory variable for current X-machine.
 * \param ebit New value for variable.
 */
void set_ebit(double ebit)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).ebit = ebit;
}

/** \fn double get_ebit()
 * \brief Get ebit memory variable from current X-machine.
 * \return Value for variable.
 */
double get_ebit()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).ebit;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_equity(double equity)
 * \brief Set equity memory variable for current X-machine.
 * \param equity New value for variable.
 */
void set_equity(double equity)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).equity = equity;
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).equity = equity;
	if(current_xmachine->xmachine_equityfund) (*current_xmachine->xmachine_equityfund).equity = equity;
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).equity = equity;
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).equity = equity;
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).equity = equity;
}

/** \fn double get_equity()
 * \brief Get equity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_equity()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).equity;
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).equity;
	if(current_xmachine->xmachine_equityfund) return (*current_xmachine->xmachine_equityfund).equity;
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).equity;
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).equity;
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).equity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_liquidity(double liquidity)
 * \brief Set liquidity memory variable for current X-machine.
 * \param liquidity New value for variable.
 */
void set_liquidity(double liquidity)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).liquidity = liquidity;
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).liquidity = liquidity;
	if(current_xmachine->xmachine_equityfund) (*current_xmachine->xmachine_equityfund).liquidity = liquidity;
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).liquidity = liquidity;
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).liquidity = liquidity;
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).liquidity = liquidity;
}

/** \fn double get_liquidity()
 * \brief Get liquidity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_liquidity()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).liquidity;
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).liquidity;
	if(current_xmachine->xmachine_equityfund) return (*current_xmachine->xmachine_equityfund).liquidity;
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).liquidity;
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).liquidity;
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).liquidity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_capital_goods(double capital_goods)
 * \brief Set capital_goods memory variable for current X-machine.
 * \param capital_goods New value for variable.
 */
void set_capital_goods(double capital_goods)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).capital_goods = capital_goods;
}

/** \fn double get_capital_goods()
 * \brief Get capital_goods memory variable from current X-machine.
 * \return Value for variable.
 */
double get_capital_goods()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).capital_goods;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_hasloan(int hasloan)
 * \brief Set hasloan memory variable for current X-machine.
 * \param hasloan New value for variable.
 */
void set_hasloan(int hasloan)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).hasloan = hasloan;
}

/** \fn int get_hasloan()
 * \brief Get hasloan memory variable from current X-machine.
 * \return Value for variable.
 */
int get_hasloan()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).hasloan;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_hasinvestment(int hasinvestment)
 * \brief Set hasinvestment memory variable for current X-machine.
 * \param hasinvestment New value for variable.
 */
void set_hasinvestment(int hasinvestment)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).hasinvestment = hasinvestment;
}

/** \fn int get_hasinvestment()
 * \brief Get hasinvestment memory variable from current X-machine.
 * \return Value for variable.
 */
int get_hasinvestment()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).hasinvestment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_planned_investment_costs(double planned_investment_costs)
 * \brief Set planned_investment_costs memory variable for current X-machine.
 * \param planned_investment_costs New value for variable.
 */
void set_planned_investment_costs(double planned_investment_costs)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).planned_investment_costs = planned_investment_costs;
}

/** \fn double get_planned_investment_costs()
 * \brief Get planned_investment_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_planned_investment_costs()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).planned_investment_costs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_liquidity_need(double liquidity_need)
 * \brief Set liquidity_need memory variable for current X-machine.
 * \param liquidity_need New value for variable.
 */
void set_liquidity_need(double liquidity_need)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).liquidity_need = liquidity_need;
}

/** \fn double get_liquidity_need()
 * \brief Get liquidity_need memory variable from current X-machine.
 * \return Value for variable.
 */
double get_liquidity_need()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).liquidity_need;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn loan get_loan_list()
 * \brief Get loan_list memory variable from current X-machine.
 * \return Value for variable.
 */
loan * get_loan_list()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).loan_list;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_delta_housing_price(double delta_housing_price)
 * \brief Set delta_housing_price memory variable for current X-machine.
 * \param delta_housing_price New value for variable.
 */
void set_delta_housing_price(double delta_housing_price)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).delta_housing_price = delta_housing_price;
}

/** \fn double get_delta_housing_price()
 * \brief Get delta_housing_price memory variable from current X-machine.
 * \return Value for variable.
 */
double get_delta_housing_price()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).delta_housing_price;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_weekly_consumption_budget(double weekly_consumption_budget)
 * \brief Set weekly_consumption_budget memory variable for current X-machine.
 * \param weekly_consumption_budget New value for variable.
 */
void set_weekly_consumption_budget(double weekly_consumption_budget)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).weekly_consumption_budget = weekly_consumption_budget;
}

/** \fn double get_weekly_consumption_budget()
 * \brief Get weekly_consumption_budget memory variable from current X-machine.
 * \return Value for variable.
 */
double get_weekly_consumption_budget()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).weekly_consumption_budget;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_planned_consumption_budget(double planned_consumption_budget)
 * \brief Set planned_consumption_budget memory variable for current X-machine.
 * \param planned_consumption_budget New value for variable.
 */
void set_planned_consumption_budget(double planned_consumption_budget)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).planned_consumption_budget = planned_consumption_budget;
}

/** \fn double get_planned_consumption_budget()
 * \brief Get planned_consumption_budget memory variable from current X-machine.
 * \return Value for variable.
 */
double get_planned_consumption_budget()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).planned_consumption_budget;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_my_employer_id(int my_employer_id)
 * \brief Set my_employer_id memory variable for current X-machine.
 * \param my_employer_id New value for variable.
 */
void set_my_employer_id(int my_employer_id)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).my_employer_id = my_employer_id;
}

/** \fn int get_my_employer_id()
 * \brief Get my_employer_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_my_employer_id()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).my_employer_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_wage(double wage)
 * \brief Set wage memory variable for current X-machine.
 * \param wage New value for variable.
 */
void set_wage(double wage)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).wage = wage;
}

/** \fn double get_wage()
 * \brief Get wage memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).wage;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_day_of_month_wage_recieved(int day_of_month_wage_recieved)
 * \brief Set day_of_month_wage_recieved memory variable for current X-machine.
 * \param day_of_month_wage_recieved New value for variable.
 */
void set_day_of_month_wage_recieved(int day_of_month_wage_recieved)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).day_of_month_wage_recieved = day_of_month_wage_recieved;
}

/** \fn int get_day_of_month_wage_recieved()
 * \brief Get day_of_month_wage_recieved memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_month_wage_recieved()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).day_of_month_wage_recieved;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_mortgages_interest_rate(double mortgages_interest_rate)
 * \brief Set mortgages_interest_rate memory variable for current X-machine.
 * \param mortgages_interest_rate New value for variable.
 */
void set_mortgages_interest_rate(double mortgages_interest_rate)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).mortgages_interest_rate = mortgages_interest_rate;
	if(current_xmachine->xmachine_reagency) (*current_xmachine->xmachine_reagency).mortgages_interest_rate = mortgages_interest_rate;
}

/** \fn double get_mortgages_interest_rate()
 * \brief Get mortgages_interest_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_mortgages_interest_rate()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).mortgages_interest_rate;
	if(current_xmachine->xmachine_reagency) return (*current_xmachine->xmachine_reagency).mortgages_interest_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_tax_rate(double tax_rate)
 * \brief Set tax_rate memory variable for current X-machine.
 * \param tax_rate New value for variable.
 */
void set_tax_rate(double tax_rate)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).tax_rate = tax_rate;
}

/** \fn double get_tax_rate()
 * \brief Get tax_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_rate()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).tax_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn mortgage_array get_mortgages_list()
 * \brief Get mortgages_list memory variable from current X-machine.
 * \return Value for variable.
 */
mortgage_array * get_mortgages_list()
{
	if(current_xmachine->xmachine_household) return &(*current_xmachine->xmachine_household).mortgages_list;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_mortgages(double mortgages)
 * \brief Set mortgages memory variable for current X-machine.
 * \param mortgages New value for variable.
 */
void set_mortgages(double mortgages)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).mortgages = mortgages;
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).mortgages = mortgages;
}

/** \fn double get_mortgages()
 * \brief Get mortgages memory variable from current X-machine.
 * \return Value for variable.
 */
double get_mortgages()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).mortgages;
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).mortgages;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_housing_payment(double housing_payment)
 * \brief Set housing_payment memory variable for current X-machine.
 * \param housing_payment New value for variable.
 */
void set_housing_payment(double housing_payment)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).housing_payment = housing_payment;
}

/** \fn double get_housing_payment()
 * \brief Get housing_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_housing_payment()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).housing_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_housing_price(double housing_price)
 * \brief Set housing_price memory variable for current X-machine.
 * \param housing_price New value for variable.
 */
void set_housing_price(double housing_price)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).housing_price = housing_price;
}

/** \fn double get_housing_price()
 * \brief Get housing_price memory variable from current X-machine.
 * \return Value for variable.
 */
double get_housing_price()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).housing_price;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_housing_units(int housing_units)
 * \brief Set housing_units memory variable for current X-machine.
 * \param housing_units New value for variable.
 */
void set_housing_units(int housing_units)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).housing_units = housing_units;
}

/** \fn int get_housing_units()
 * \brief Get housing_units memory variable from current X-machine.
 * \return Value for variable.
 */
int get_housing_units()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).housing_units;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_n_shares(int n_shares)
 * \brief Set n_shares memory variable for current X-machine.
 * \param n_shares New value for variable.
 */
void set_n_shares(int n_shares)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).n_shares = n_shares;
	if(current_xmachine->xmachine_equityfund) (*current_xmachine->xmachine_equityfund).n_shares = n_shares;
}

/** \fn int get_n_shares()
 * \brief Get n_shares memory variable from current X-machine.
 * \return Value for variable.
 */
int get_n_shares()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).n_shares;
	if(current_xmachine->xmachine_equityfund) return (*current_xmachine->xmachine_equityfund).n_shares;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_capital_income(double capital_income)
 * \brief Set capital_income memory variable for current X-machine.
 * \param capital_income New value for variable.
 */
void set_capital_income(double capital_income)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).capital_income = capital_income;
}

/** \fn double get_capital_income()
 * \brief Get capital_income memory variable from current X-machine.
 * \return Value for variable.
 */
double get_capital_income()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).capital_income;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn int get_previous_wages()
 * \brief Get previous_wages memory variable from current X-machine.
 * \return Value for variable.
 */
int * get_previous_wages()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).previous_wages;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_labour_income(double labour_income)
 * \brief Set labour_income memory variable for current X-machine.
 * \param labour_income New value for variable.
 */
void set_labour_income(double labour_income)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).labour_income = labour_income;
}

/** \fn double get_labour_income()
 * \brief Get labour_income memory variable from current X-machine.
 * \return Value for variable.
 */
double get_labour_income()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).labour_income;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_housing_value(double housing_value)
 * \brief Set housing_value memory variable for current X-machine.
 * \param housing_value New value for variable.
 */
void set_housing_value(double housing_value)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).housing_value = housing_value;
}

/** \fn double get_housing_value()
 * \brief Get housing_value memory variable from current X-machine.
 * \return Value for variable.
 */
double get_housing_value()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).housing_value;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_delta_housing_value(double delta_housing_value)
 * \brief Set delta_housing_value memory variable for current X-machine.
 * \param delta_housing_value New value for variable.
 */
void set_delta_housing_value(double delta_housing_value)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).delta_housing_value = delta_housing_value;
}

/** \fn double get_delta_housing_value()
 * \brief Get delta_housing_value memory variable from current X-machine.
 * \return Value for variable.
 */
double get_delta_housing_value()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).delta_housing_value;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_hmarket_role(int hmarket_role)
 * \brief Set hmarket_role memory variable for current X-machine.
 * \param hmarket_role New value for variable.
 */
void set_hmarket_role(int hmarket_role)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).hmarket_role = hmarket_role;
}

/** \fn int get_hmarket_role()
 * \brief Get hmarket_role memory variable from current X-machine.
 * \return Value for variable.
 */
int get_hmarket_role()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).hmarket_role;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_equity_ratio(double equity_ratio)
 * \brief Set equity_ratio memory variable for current X-machine.
 * \param equity_ratio New value for variable.
 */
void set_equity_ratio(double equity_ratio)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).equity_ratio = equity_ratio;
}

/** \fn double get_equity_ratio()
 * \brief Get equity_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_equity_ratio()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).equity_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_minimum_equity_ratio(double minimum_equity_ratio)
 * \brief Set minimum_equity_ratio memory variable for current X-machine.
 * \param minimum_equity_ratio New value for variable.
 */
void set_minimum_equity_ratio(double minimum_equity_ratio)
{
	if(current_xmachine->xmachine_household) (*current_xmachine->xmachine_household).minimum_equity_ratio = minimum_equity_ratio;
}

/** \fn double get_minimum_equity_ratio()
 * \brief Get minimum_equity_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_minimum_equity_ratio()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).minimum_equity_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn double get_mortgage_costs()
 * \brief Get mortgage_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_mortgage_costs()
{
	if(current_xmachine->xmachine_household) return (*current_xmachine->xmachine_household).mortgage_costs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_share_firms(double share_firms)
 * \brief Set share_firms memory variable for current X-machine.
 * \param share_firms New value for variable.
 */
void set_share_firms(double share_firms)
{
	if(current_xmachine->xmachine_equityfund) (*current_xmachine->xmachine_equityfund).share_firms = share_firms;
}

/** \fn double get_share_firms()
 * \brief Get share_firms memory variable from current X-machine.
 * \return Value for variable.
 */
double get_share_firms()
{
	if(current_xmachine->xmachine_equityfund) return (*current_xmachine->xmachine_equityfund).share_firms;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_share_construction_firms(double share_construction_firms)
 * \brief Set share_construction_firms memory variable for current X-machine.
 * \param share_construction_firms New value for variable.
 */
void set_share_construction_firms(double share_construction_firms)
{
	if(current_xmachine->xmachine_equityfund) (*current_xmachine->xmachine_equityfund).share_construction_firms = share_construction_firms;
}

/** \fn double get_share_construction_firms()
 * \brief Get share_construction_firms memory variable from current X-machine.
 * \return Value for variable.
 */
double get_share_construction_firms()
{
	if(current_xmachine->xmachine_equityfund) return (*current_xmachine->xmachine_equityfund).share_construction_firms;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_share_banks(double share_banks)
 * \brief Set share_banks memory variable for current X-machine.
 * \param share_banks New value for variable.
 */
void set_share_banks(double share_banks)
{
	if(current_xmachine->xmachine_equityfund) (*current_xmachine->xmachine_equityfund).share_banks = share_banks;
}

/** \fn double get_share_banks()
 * \brief Get share_banks memory variable from current X-machine.
 * \return Value for variable.
 */
double get_share_banks()
{
	if(current_xmachine->xmachine_equityfund) return (*current_xmachine->xmachine_equityfund).share_banks;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_dividends_recieved(double dividends_recieved)
 * \brief Set dividends_recieved memory variable for current X-machine.
 * \param dividends_recieved New value for variable.
 */
void set_dividends_recieved(double dividends_recieved)
{
	if(current_xmachine->xmachine_equityfund) (*current_xmachine->xmachine_equityfund).dividends_recieved = dividends_recieved;
}

/** \fn double get_dividends_recieved()
 * \brief Get dividends_recieved memory variable from current X-machine.
 * \return Value for variable.
 */
double get_dividends_recieved()
{
	if(current_xmachine->xmachine_equityfund) return (*current_xmachine->xmachine_equityfund).dividends_recieved;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_dividends_retained(double dividends_retained)
 * \brief Set dividends_retained memory variable for current X-machine.
 * \param dividends_retained New value for variable.
 */
void set_dividends_retained(double dividends_retained)
{
	if(current_xmachine->xmachine_equityfund) (*current_xmachine->xmachine_equityfund).dividends_retained = dividends_retained;
}

/** \fn double get_dividends_retained()
 * \brief Get dividends_retained memory variable from current X-machine.
 * \return Value for variable.
 */
double get_dividends_retained()
{
	if(current_xmachine->xmachine_equityfund) return (*current_xmachine->xmachine_equityfund).dividends_retained;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_investment(double firm_investment)
 * \brief Set firm_investment memory variable for current X-machine.
 * \param firm_investment New value for variable.
 */
void set_firm_investment(double firm_investment)
{
	if(current_xmachine->xmachine_equityfund) (*current_xmachine->xmachine_equityfund).firm_investment = firm_investment;
}

/** \fn double get_firm_investment()
 * \brief Get firm_investment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_investment()
{
	if(current_xmachine->xmachine_equityfund) return (*current_xmachine->xmachine_equityfund).firm_investment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_loans(double loans)
 * \brief Set loans memory variable for current X-machine.
 * \param loans New value for variable.
 */
void set_loans(double loans)
{
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).loans = loans;
}

/** \fn double get_loans()
 * \brief Get loans memory variable from current X-machine.
 * \return Value for variable.
 */
double get_loans()
{
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).loans;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_deposits(double deposits)
 * \brief Set deposits memory variable for current X-machine.
 * \param deposits New value for variable.
 */
void set_deposits(double deposits)
{
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).deposits = deposits;
}

/** \fn double get_deposits()
 * \brief Get deposits memory variable from current X-machine.
 * \return Value for variable.
 */
double get_deposits()
{
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).deposits;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_centralbank_debt(double centralbank_debt)
 * \brief Set centralbank_debt memory variable for current X-machine.
 * \param centralbank_debt New value for variable.
 */
void set_centralbank_debt(double centralbank_debt)
{
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).centralbank_debt = centralbank_debt;
}

/** \fn double get_centralbank_debt()
 * \brief Get centralbank_debt memory variable from current X-machine.
 * \return Value for variable.
 */
double get_centralbank_debt()
{
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).centralbank_debt;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_writeoffs(double total_writeoffs)
 * \brief Set total_writeoffs memory variable for current X-machine.
 * \param total_writeoffs New value for variable.
 */
void set_total_writeoffs(double total_writeoffs)
{
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).total_writeoffs = total_writeoffs;
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).total_writeoffs = total_writeoffs;
}

/** \fn double get_total_writeoffs()
 * \brief Get total_writeoffs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_writeoffs()
{
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).total_writeoffs;
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).total_writeoffs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_interests_accrued(double interests_accrued)
 * \brief Set interests_accrued memory variable for current X-machine.
 * \param interests_accrued New value for variable.
 */
void set_interests_accrued(double interests_accrued)
{
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).interests_accrued = interests_accrued;
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).interests_accrued = interests_accrued;
}

/** \fn double get_interests_accrued()
 * \brief Get interests_accrued memory variable from current X-machine.
 * \return Value for variable.
 */
double get_interests_accrued()
{
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).interests_accrued;
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).interests_accrued;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_interests_paid(double interests_paid)
 * \brief Set interests_paid memory variable for current X-machine.
 * \param interests_paid New value for variable.
 */
void set_interests_paid(double interests_paid)
{
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).interests_paid = interests_paid;
}

/** \fn double get_interests_paid()
 * \brief Get interests_paid memory variable from current X-machine.
 * \return Value for variable.
 */
double get_interests_paid()
{
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).interests_paid;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_dividends(double total_dividends)
 * \brief Set total_dividends memory variable for current X-machine.
 * \param total_dividends New value for variable.
 */
void set_total_dividends(double total_dividends)
{
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).total_dividends = total_dividends;
}

/** \fn double get_total_dividends()
 * \brief Get total_dividends memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_dividends()
{
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).total_dividends;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_costs(double total_costs)
 * \brief Set total_costs memory variable for current X-machine.
 * \param total_costs New value for variable.
 */
void set_total_costs(double total_costs)
{
	if(current_xmachine->xmachine_bank) (*current_xmachine->xmachine_bank).total_costs = total_costs;
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).total_costs = total_costs;
}

/** \fn double get_total_costs()
 * \brief Get total_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_costs()
{
	if(current_xmachine->xmachine_bank) return (*current_xmachine->xmachine_bank).total_costs;
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).total_costs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_unemployment_rate(double unemployment_rate)
 * \brief Set unemployment_rate memory variable for current X-machine.
 * \param unemployment_rate New value for variable.
 */
void set_unemployment_rate(double unemployment_rate)
{
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).unemployment_rate = unemployment_rate;
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).unemployment_rate = unemployment_rate;
}

/** \fn double get_unemployment_rate()
 * \brief Get unemployment_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_rate()
{
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).unemployment_rate;
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).unemployment_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_population_size(int population_size)
 * \brief Set population_size memory variable for current X-machine.
 * \param population_size New value for variable.
 */
void set_population_size(int population_size)
{
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).population_size = population_size;
}

/** \fn int get_population_size()
 * \brief Get population_size memory variable from current X-machine.
 * \return Value for variable.
 */
int get_population_size()
{
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).population_size;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_gov_tax_rate(double gov_tax_rate)
 * \brief Set gov_tax_rate memory variable for current X-machine.
 * \param gov_tax_rate New value for variable.
 */
void set_gov_tax_rate(double gov_tax_rate)
{
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).gov_tax_rate = gov_tax_rate;
}

/** \fn double get_gov_tax_rate()
 * \brief Get gov_tax_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_gov_tax_rate()
{
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).gov_tax_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_labour_tax_income(double labour_tax_income)
 * \brief Set labour_tax_income memory variable for current X-machine.
 * \param labour_tax_income New value for variable.
 */
void set_labour_tax_income(double labour_tax_income)
{
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).labour_tax_income = labour_tax_income;
}

/** \fn double get_labour_tax_income()
 * \brief Get labour_tax_income memory variable from current X-machine.
 * \return Value for variable.
 */
double get_labour_tax_income()
{
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).labour_tax_income;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_capital_tax_income(double capital_tax_income)
 * \brief Set capital_tax_income memory variable for current X-machine.
 * \param capital_tax_income New value for variable.
 */
void set_capital_tax_income(double capital_tax_income)
{
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).capital_tax_income = capital_tax_income;
}

/** \fn double get_capital_tax_income()
 * \brief Get capital_tax_income memory variable from current X-machine.
 * \return Value for variable.
 */
double get_capital_tax_income()
{
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).capital_tax_income;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_gov_general_benefit_rate(double gov_general_benefit_rate)
 * \brief Set gov_general_benefit_rate memory variable for current X-machine.
 * \param gov_general_benefit_rate New value for variable.
 */
void set_gov_general_benefit_rate(double gov_general_benefit_rate)
{
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).gov_general_benefit_rate = gov_general_benefit_rate;
}

/** \fn double get_gov_general_benefit_rate()
 * \brief Get gov_general_benefit_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_gov_general_benefit_rate()
{
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).gov_general_benefit_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_gov_unemployment_rate(double gov_unemployment_rate)
 * \brief Set gov_unemployment_rate memory variable for current X-machine.
 * \param gov_unemployment_rate New value for variable.
 */
void set_gov_unemployment_rate(double gov_unemployment_rate)
{
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).gov_unemployment_rate = gov_unemployment_rate;
}

/** \fn double get_gov_unemployment_rate()
 * \brief Get gov_unemployment_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_gov_unemployment_rate()
{
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).gov_unemployment_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_general_benefits(double general_benefits)
 * \brief Set general_benefits memory variable for current X-machine.
 * \param general_benefits New value for variable.
 */
void set_general_benefits(double general_benefits)
{
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).general_benefits = general_benefits;
}

/** \fn double get_general_benefits()
 * \brief Get general_benefits memory variable from current X-machine.
 * \return Value for variable.
 */
double get_general_benefits()
{
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).general_benefits;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_unemployment_benefits(double unemployment_benefits)
 * \brief Set unemployment_benefits memory variable for current X-machine.
 * \param unemployment_benefits New value for variable.
 */
void set_unemployment_benefits(double unemployment_benefits)
{
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).unemployment_benefits = unemployment_benefits;
}

/** \fn double get_unemployment_benefits()
 * \brief Get unemployment_benefits memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_benefits()
{
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).unemployment_benefits;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_earnings(double earnings)
 * \brief Set earnings memory variable for current X-machine.
 * \param earnings New value for variable.
 */
void set_earnings(double earnings)
{
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).earnings = earnings;
}

/** \fn double get_earnings()
 * \brief Get earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_earnings()
{
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).earnings;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_expenditures(double expenditures)
 * \brief Set expenditures memory variable for current X-machine.
 * \param expenditures New value for variable.
 */
void set_expenditures(double expenditures)
{
	if(current_xmachine->xmachine_government) (*current_xmachine->xmachine_government).expenditures = expenditures;
}

/** \fn double get_expenditures()
 * \brief Get expenditures memory variable from current X-machine.
 * \return Value for variable.
 */
double get_expenditures()
{
	if(current_xmachine->xmachine_government) return (*current_xmachine->xmachine_government).expenditures;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn double get_consumption_goods_prices()
 * \brief Get consumption_goods_prices memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_consumption_goods_prices()
{
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).consumption_goods_prices;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn transaction get_goods()
 * \brief Get goods memory variable from current X-machine.
 * \return Value for variable.
 */
transaction * get_goods()
{
	if(current_xmachine->xmachine_centralbank) return &(*current_xmachine->xmachine_centralbank).goods;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double get_weekly_price_averages()
 * \brief Get weekly_price_averages memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_weekly_price_averages()
{
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).weekly_price_averages;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_interest_rate(double interest_rate)
 * \brief Set interest_rate memory variable for current X-machine.
 * \param interest_rate New value for variable.
 */
void set_interest_rate(double interest_rate)
{
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).interest_rate = interest_rate;
}

/** \fn double get_interest_rate()
 * \brief Get interest_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_interest_rate()
{
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).interest_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_loans_banks(double loans_banks)
 * \brief Set loans_banks memory variable for current X-machine.
 * \param loans_banks New value for variable.
 */
void set_loans_banks(double loans_banks)
{
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).loans_banks = loans_banks;
}

/** \fn double get_loans_banks()
 * \brief Get loans_banks memory variable from current X-machine.
 * \return Value for variable.
 */
double get_loans_banks()
{
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).loans_banks;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_loans_government(double loans_government)
 * \brief Set loans_government memory variable for current X-machine.
 * \param loans_government New value for variable.
 */
void set_loans_government(double loans_government)
{
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).loans_government = loans_government;
}

/** \fn double get_loans_government()
 * \brief Get loans_government memory variable from current X-machine.
 * \return Value for variable.
 */
double get_loans_government()
{
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).loans_government;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_fiat_money(double fiat_money)
 * \brief Set fiat_money memory variable for current X-machine.
 * \param fiat_money New value for variable.
 */
void set_fiat_money(double fiat_money)
{
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).fiat_money = fiat_money;
}

/** \fn double get_fiat_money()
 * \brief Get fiat_money memory variable from current X-machine.
 * \return Value for variable.
 */
double get_fiat_money()
{
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).fiat_money;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_liquidity_banks(double liquidity_banks)
 * \brief Set liquidity_banks memory variable for current X-machine.
 * \param liquidity_banks New value for variable.
 */
void set_liquidity_banks(double liquidity_banks)
{
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).liquidity_banks = liquidity_banks;
}

/** \fn double get_liquidity_banks()
 * \brief Get liquidity_banks memory variable from current X-machine.
 * \return Value for variable.
 */
double get_liquidity_banks()
{
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).liquidity_banks;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_liquidity_government(double liquidity_government)
 * \brief Set liquidity_government memory variable for current X-machine.
 * \param liquidity_government New value for variable.
 */
void set_liquidity_government(double liquidity_government)
{
	if(current_xmachine->xmachine_centralbank) (*current_xmachine->xmachine_centralbank).liquidity_government = liquidity_government;
}

/** \fn double get_liquidity_government()
 * \brief Get liquidity_government memory variable from current X-machine.
 * \return Value for variable.
 */
double get_liquidity_government()
{
	if(current_xmachine->xmachine_centralbank) return (*current_xmachine->xmachine_centralbank).liquidity_government;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn transaction get_houses()
 * \brief Get houses memory variable from current X-machine.
 * \return Value for variable.
 */
transaction * get_houses()
{
	if(current_xmachine->xmachine_centralbank) return &(*current_xmachine->xmachine_centralbank).houses;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn transaction get_goods_transactions()
 * \brief Get goods_transactions memory variable from current X-machine.
 * \return Value for variable.
 */
transaction * get_goods_transactions()
{
	if(current_xmachine->xmachine_mall) return &(*current_xmachine->xmachine_mall).goods_transactions;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn transaction get_housing_transactions()
 * \brief Get housing_transactions memory variable from current X-machine.
 * \return Value for variable.
 */
transaction * get_housing_transactions()
{
	if(current_xmachine->xmachine_reagency) return &(*current_xmachine->xmachine_reagency).housing_transactions;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}


/** \fn double agent_get_range()
 * \brief Fixed routine to get the range from current X-machine
  * \return Value of range
  */
double agent_get_range()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_firm) value = current_xmachine->xmachine_firm->;*/
    /*if (current_xmachine->xmachine_household) value = current_xmachine->xmachine_household->;*/
    /*if (current_xmachine->xmachine_equityfund) value = current_xmachine->xmachine_equityfund->;*/
    /*if (current_xmachine->xmachine_bank) value = current_xmachine->xmachine_bank->;*/
    /*if (current_xmachine->xmachine_government) value = current_xmachine->xmachine_government->;*/
    /*if (current_xmachine->xmachine_centralbank) value = current_xmachine->xmachine_centralbank->;*/
    /*if (current_xmachine->xmachine_jpoffice) value = current_xmachine->xmachine_jpoffice->;*/
    /*if (current_xmachine->xmachine_mall) value = current_xmachine->xmachine_mall->;*/
    /*if (current_xmachine->xmachine_reagency) value = current_xmachine->xmachine_reagency->;*/

    return value;
}

/** \fn int agent_get_id()
 * \brief Fixed routine to get the id for the current X-machine
  * \return Value of agent id
  */
int agent_get_id()
{
    int value = 0;
    /*if (current_xmachine->xmachine_firm) value = current_xmachine->xmachine_firm->id;*/
    /*if (current_xmachine->xmachine_household) value = current_xmachine->xmachine_household->id;*/
    /*if (current_xmachine->xmachine_equityfund) value = current_xmachine->xmachine_equityfund->id;*/
    /*if (current_xmachine->xmachine_bank) value = current_xmachine->xmachine_bank->id;*/
    /*if (current_xmachine->xmachine_government) value = current_xmachine->xmachine_government->id;*/
    /*if (current_xmachine->xmachine_centralbank) value = current_xmachine->xmachine_centralbank->id;*/
    /*if (current_xmachine->xmachine_jpoffice) value = current_xmachine->xmachine_jpoffice->id;*/
    /*if (current_xmachine->xmachine_mall) value = current_xmachine->xmachine_mall->id;*/
    /*if (current_xmachine->xmachine_reagency) value = current_xmachine->xmachine_reagency->id;*/

    return value;
}

/** \fn double agent_get_x()
 * \brief Fixed routine to get the x coordinate from current X-machine
  * \return Value of x coordinate
  */
double agent_get_x()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_firm) value = current_xmachine->xmachine_firm->0.0;*/
    /*if (current_xmachine->xmachine_household) value = current_xmachine->xmachine_household->0.0;*/
    /*if (current_xmachine->xmachine_equityfund) value = current_xmachine->xmachine_equityfund->0.0;*/
    /*if (current_xmachine->xmachine_bank) value = current_xmachine->xmachine_bank->0.0;*/
    /*if (current_xmachine->xmachine_government) value = current_xmachine->xmachine_government->0.0;*/
    /*if (current_xmachine->xmachine_centralbank) value = current_xmachine->xmachine_centralbank->0.0;*/
    /*if (current_xmachine->xmachine_jpoffice) value = current_xmachine->xmachine_jpoffice->0.0;*/
    /*if (current_xmachine->xmachine_mall) value = current_xmachine->xmachine_mall->0.0;*/
    /*if (current_xmachine->xmachine_reagency) value = current_xmachine->xmachine_reagency->0.0;*/

    return value;
}
/** \fn double agent_get_y()
 * \brief Fixed routine to get the y coordinate from current X-machine
  * \return Value of y coordinate
  */
double agent_get_y()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_firm) value = current_xmachine->xmachine_firm->0.0;*/
    /*if (current_xmachine->xmachine_household) value = current_xmachine->xmachine_household->0.0;*/
    /*if (current_xmachine->xmachine_equityfund) value = current_xmachine->xmachine_equityfund->0.0;*/
    /*if (current_xmachine->xmachine_bank) value = current_xmachine->xmachine_bank->0.0;*/
    /*if (current_xmachine->xmachine_government) value = current_xmachine->xmachine_government->0.0;*/
    /*if (current_xmachine->xmachine_centralbank) value = current_xmachine->xmachine_centralbank->0.0;*/
    /*if (current_xmachine->xmachine_jpoffice) value = current_xmachine->xmachine_jpoffice->0.0;*/
    /*if (current_xmachine->xmachine_mall) value = current_xmachine->xmachine_mall->0.0;*/
    /*if (current_xmachine->xmachine_reagency) value = current_xmachine->xmachine_reagency->0.0;*/

    return value;
}
/** \fn double agent_get_z()
 * \brief Fixed routine to get the z coordinate from current X-machine
  * \return Value of z coordinate
  */
double agent_get_z()
{
    double value = 0.0;

    return value;
}

/** \fn void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
 * \brief Add a node to the node list.
 * \param node_id The node ID.
 * \param minx The minumum value on the x-axis of the bounding volume.
 * \param maxx The maximum value on the x-axis of the bounding volume.
 * \param miny The minumum value on the y-axis of the bounding volume.
 * \param maxy The maximum value on the y-axis of the bounding volume.
 * \param minz The minumum value on the z-axis of the bounding volume.
 * \param maxz The maximum value on the z-axis of the bounding volume.
 */
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
{
	node_information * current = *p_node_info;
	node_information * tmp = NULL;

	while(current)
	{
		tmp = current;
		current = current->next;
	}

	current = (node_information *)malloc(sizeof(node_information));
		CHECK_POINTER(current);

	if(tmp)
	{
		tmp->next = current;
	}
	else
	{
		*p_node_info = current;
	}

	current->next = NULL;
	current->node_id = node_id;
	current->agents_in_halo = 0;
	current->agent_total = 0;
	current->agents = NULL;
	current->firm_bank_update_deposit_messages = NULL;
	current->household_bank_update_deposit_messages = NULL;
	current->interest_rate_messages = NULL;
	current->buy_messages = NULL;
	current->bought_messages = NULL;
	current->sell_messages = NULL;
	current->sold_messages = NULL;
	current->goods_transactions_summary_messages = NULL;
	current->fired_messages = NULL;
	current->vacancy_stage1_messages = NULL;
	current->job_application_stage2_messages = NULL;
	current->job_application_stage1_messages = NULL;
	current->job_match_stage1_messages = NULL;
	current->job_change_messages = NULL;
	current->vacancy_stage2_messages = NULL;
	current->job_match_stage2_messages = NULL;
	current->employment_status_messages = NULL;
	current->loan_request_1_messages = NULL;
	current->loan_request_2_messages = NULL;
	current->loan_acknowledge_1_messages = NULL;
	current->loan_acknowledge_2_messages = NULL;
	current->debt_request_messages = NULL;
	current->debt_ack_messages = NULL;
	current->household_share_messages = NULL;
	current->capital_tax_messages = NULL;
	current->labour_tax_messages = NULL;
	current->unemployment_benefit_messages = NULL;
	current->general_benefit_messages = NULL;
	current->tax_rate_messages = NULL;
	current->fund_request_messages = NULL;
	current->fund_request_ack_messages = NULL;
	current->new_entrant_loan_messages = NULL;
	current->interest_on_loan_messages = NULL;
	current->loan_writeoff_messages = NULL;
	current->firm_net_profit_messages = NULL;
	current->bank_net_profit_messages = NULL;
	current->housing_price_messages = NULL;
	current->buy_housing_messages = NULL;
	current->sell_housing_messages = NULL;
	current->bought_housing_messages = NULL;
	current->sold_housing_messages = NULL;
	current->mortgaging_capacity_messages = NULL;
	current->mortgage_requests_messages = NULL;
	current->mortgage_payment_from_sale_messages = NULL;
	current->mortgage_payment_messages = NULL;
	current->mortgage_writeoff_messages = NULL;
	current->housing_transactions_summary_messages = NULL;


	current->partition_data[0] = minx;
	current->partition_data[1] = maxx;
	current->partition_data[2] = miny;
	current->partition_data[3] = maxy;
	current->partition_data[4] = minz;
	current->partition_data[5] = maxz;
}

/**\fn void free_node_info()
 * \brief Free the node list.
 */
void free_node_info()
{
	node_information * tmp, * head;
	head = *p_node_info;

	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}

	*p_node_info = NULL;
}

/** \fn void clean_up(int code)
 * \brief Add a node to the node list.
 * \param code The error code (zero is no error).
 */
void clean_up(int code)
{
    int rc;
	FILE *file;
	char data[100];

	free(current_xmachine);
	/* Free x-machine memory */
	freexmachines();
	/* Free space partitions linked list */
	free_node_info();
	/* Free output list */
	free_FLAME_outputs(&FLAME_outputs);
	/* Free agent states */
	free_firm_states();
	free_household_states();
	free_equityfund_states();
	free_bank_states();
	free_government_states();
	free_centralbank_states();
	free_jpoffice_states();
	free_mall_states();
	free_reagency_states();


	/* Free index maps */


	/* Free message boards */

	rc = MB_Delete(&b_firm_bank_update_deposit);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'firm_bank_update_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_household_bank_update_deposit);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'household_bank_update_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_bank_update_deposit' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_bank_update_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_interest_rate);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'interest_rate' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'interest_rate' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'interest_rate' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_buy);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'buy' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'buy' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'buy' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_bought);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'bought' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bought' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bought' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_sell);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'sell' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sell' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sell' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_sold);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'sold' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sold' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sold' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_goods_transactions_summary);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'goods_transactions_summary' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'goods_transactions_summary' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'goods_transactions_summary' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_fired);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'fired' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fired' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fired' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_vacancy_stage1);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'vacancy_stage1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancy_stage1' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancy_stage1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_job_application_stage2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'job_application_stage2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application_stage2' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application_stage2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_job_application_stage1);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'job_application_stage1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application_stage1' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application_stage1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_job_match_stage1);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'job_match_stage1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_match_stage1' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_match_stage1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_job_change);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'job_change' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_change' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_change' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_vacancy_stage2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'vacancy_stage2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancy_stage2' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancy_stage2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_job_match_stage2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'job_match_stage2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_match_stage2' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_match_stage2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_employment_status);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'employment_status' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'employment_status' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'employment_status' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_loan_request_1);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'loan_request_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_request_1' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_request_1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_loan_request_2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'loan_request_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_request_2' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_request_2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_loan_acknowledge_1);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'loan_acknowledge_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_acknowledge_1' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_acknowledge_1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_loan_acknowledge_2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'loan_acknowledge_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_acknowledge_2' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_acknowledge_2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_debt_request);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'debt_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'debt_request' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'debt_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_debt_ack);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'debt_ack' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'debt_ack' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'debt_ack' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_household_share);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'household_share' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_share' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_share' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_capital_tax);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'capital_tax' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_tax' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_tax' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_labour_tax);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'labour_tax' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'labour_tax' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'labour_tax' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_unemployment_benefit);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'unemployment_benefit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'unemployment_benefit' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'unemployment_benefit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_general_benefit);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'general_benefit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'general_benefit' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'general_benefit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_tax_rate);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'tax_rate' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'tax_rate' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'tax_rate' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_fund_request);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'fund_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fund_request' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fund_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_fund_request_ack);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'fund_request_ack' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fund_request_ack' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fund_request_ack' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_new_entrant_loan);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'new_entrant_loan' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'new_entrant_loan' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'new_entrant_loan' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_interest_on_loan);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'interest_on_loan' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'interest_on_loan' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'interest_on_loan' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_loan_writeoff);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'loan_writeoff' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_writeoff' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_writeoff' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_firm_net_profit);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'firm_net_profit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_net_profit' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_net_profit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_bank_net_profit);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'bank_net_profit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_net_profit' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_net_profit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_housing_price);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'housing_price' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'housing_price' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'housing_price' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_buy_housing);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'buy_housing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'buy_housing' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'buy_housing' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_sell_housing);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'sell_housing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sell_housing' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sell_housing' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_bought_housing);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'bought_housing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bought_housing' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bought_housing' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_sold_housing);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'sold_housing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sold_housing' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sold_housing' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_mortgaging_capacity);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'mortgaging_capacity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgaging_capacity' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mortgaging_capacity' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_mortgage_requests);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'mortgage_requests' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_requests' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mortgage_requests' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_mortgage_payment_from_sale);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'mortgage_payment_from_sale' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_mortgage_payment);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'mortgage_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_payment' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mortgage_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_mortgage_writeoff);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'mortgage_writeoff' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_writeoff' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mortgage_writeoff' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_housing_transactions_summary);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'housing_transactions_summary' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'housing_transactions_summary' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'housing_transactions_summary' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif


    rc = MB_Env_Finalise();
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not finalise MB environment\n");
       switch(rc) {
           case MB_ERR_ENV:
               fprintf(stderr, "\t reason: MB environment not yet started?\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Env_Finalise returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif



	/* Write log file */
	sprintf(data, "%slog.xml", outputpath);
	file = fopen(data, "a");
	fputs("<!-- <totaltime> unit: seconds -->\n", file);
	fputs("<totaltime>", file);
	sprintf(data, "%.3f", total_time);
	fputs(data, file);
	fputs("</totaltime>\n", file);
	/*fputs("<totalmessages>", file);
	sprintf(data, "%i", total_messages);
	fputs(data, file);
	fputs("</totalmessages>", file);*/
	fputs("</model_run>", file);
	fclose(file);


	if(code != 0)
	{
		printf("*** Error: ");
		if(code == 100) printf("cannot handle specified number of space partitions");
		if(code == 101) printf("could not find number of space partitions config in file");

		printf(" ***");
		exit(0);
	}
}


/** \fn void propagate_agents()
 * \brief Check agent positions to see if any need to be moved to a another node.
 */
void propagate_agents()
{
/*	node_information * node_info;
	xmachine * before_xmachine, * temp_xmachine;
	xmachine ** p_temp_xmachine;
	double x_xmachine, y_xmachine, z_xmachine;
	current_xmachine = *p_xmachine;
	before_xmachine = NULL;
	while(current_xmachine)
	{
		if(current_xmachine->xmachine_firm != NULL)
		{
			x_xmachine = current_xmachine->xmachine_firm->0.0;
			y_xmachine = current_xmachine->xmachine_firm->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_household != NULL)
		{
			x_xmachine = current_xmachine->xmachine_household->0.0;
			y_xmachine = current_xmachine->xmachine_household->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_equityfund != NULL)
		{
			x_xmachine = current_xmachine->xmachine_equityfund->0.0;
			y_xmachine = current_xmachine->xmachine_equityfund->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_bank != NULL)
		{
			x_xmachine = current_xmachine->xmachine_bank->0.0;
			y_xmachine = current_xmachine->xmachine_bank->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_government != NULL)
		{
			x_xmachine = current_xmachine->xmachine_government->0.0;
			y_xmachine = current_xmachine->xmachine_government->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_centralbank != NULL)
		{
			x_xmachine = current_xmachine->xmachine_centralbank->0.0;
			y_xmachine = current_xmachine->xmachine_centralbank->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_jpoffice != NULL)
		{
			x_xmachine = current_xmachine->xmachine_jpoffice->0.0;
			y_xmachine = current_xmachine->xmachine_jpoffice->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_mall != NULL)
		{
			x_xmachine = current_xmachine->xmachine_mall->0.0;
			y_xmachine = current_xmachine->xmachine_mall->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_reagency != NULL)
		{
			x_xmachine = current_xmachine->xmachine_reagency->0.0;
			y_xmachine = current_xmachine->xmachine_reagency->0.0;
			z_xmachine = 0.0;
		}

		if(x_xmachine < current_node->partition_data[0] ||
		   x_xmachine > current_node->partition_data[1] ||
		   y_xmachine < current_node->partition_data[2] ||
		   y_xmachine > current_node->partition_data[3] ||
		   z_xmachine < current_node->partition_data[4] ||
		   z_xmachine > current_node->partition_data[5])
		{
			node_info = *p_node_info;
			while(node_info)
			{
				if(node_info->node_id != current_node->node_id &&
				node_info->partition_data[0] < x_xmachine && node_info->partition_data[1] > x_xmachine &&
				node_info->partition_data[2] < y_xmachine && node_info->partition_data[3] > y_xmachine &&
				node_info->partition_data[4] < z_xmachine && node_info->partition_data[5] > z_xmachine)
				{
                    // Remove agent
                    if(before_xmachine) before_xmachine->next = current_xmachine->next;
                    else *p_xmachine = current_xmachine->next;
                    current_node->agent_total--;
                    // Add agent
                    p_temp_xmachine = &node_info->agents;
                    temp_xmachine = *p_temp_xmachine;
                    current_xmachine->next = temp_xmachine;
                    *p_temp_xmachine = current_xmachine;
                    node_info->agent_total++;
                    node_info = NULL;
				}
				else node_info = node_info->next;
				}
			}
			else before_xmachine = current_xmachine;

			if(before_xmachine) current_xmachine = before_xmachine->next;
			else current_xmachine = NULL;
		}*/
}


/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
void init_int_array(int_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (int *)malloc(ARRAY_BLOCK_SIZE * sizeof(int));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_int_array(int_array * array)
{
	(*array).size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_int_array(int_array * array)
{
	free((*array).array);
}

void copy_int_array(int_array * from, int_array * to)
{
	int i;
	//to = init_int_array();

	for (i = 0; i < (*from).size; i++)
	{
		add_int(to, (*from).array[i]);
	}
}

/** \fn void sort_int_array(int_array * array)
* \brief Sort the elements of a dynamic integer array with smallest first.
* \param array Pointer to the dynamic integer array.
*/
/*void sort_int_array(int_array * array)
{
	int i, j, temp;

	for(i=0; i<((*array).size-1); i++)
	{
		for(j=0; j<((*array).size-1)-i; j++)
		{
			if(*((*array).array+j+1) < *((*array).array+j))
			{
                temp = *((*array).(*array)+j);
                *((*array).array+j) = *((*array).array+j+1);
                *((*array).array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_int(int *array, int elements)
 *  \brief Sorts the elements of the integer array in ascending order.
 *  \param Pointer to integer array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_int(int array, int elements)
{
	#define  LEVEL  1000
	int  pivot, begin[LEVEL], end[LEVEL], i=0, left, right ;
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_int(int_array * array, int new_int)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (int *)realloc((*array).array, ((*array).total_size * sizeof(int)));
	}
	(*array).array[(*array).size] = new_int;
	(*array).size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_int(int_array * array, int index)
{
	int i;

	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_int_array(int_array * array)
 * \brief Print the elements of a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 */
void print_int_array(int_array * array)
{
	int i;

	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %d", i, (*array).array[i]);
	}
}

/** \fn float_array * init_float_array()
 * \brief Allocate memory for a dynamic float array.
 * \return float_array Pointer to the new dynamic float array.
 */
void init_float_array(float_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (float *)malloc(ARRAY_BLOCK_SIZE * sizeof(float));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_float_array(float_array * array)
* \brief Reset the float array to hold nothing.
* \param array Pointer to the dynamic float array.
*/
void reset_float_array(float_array * array)
{
	(*array).size = 0;
}

/** \fn void free_float_array(float_array * array)
* \brief Free the memory of a dynamic float array.
* \param array Pointer to the dynamic float array.
*/
void free_float_array(float_array * array)
{
	free((*array).array);
}

void copy_float_array(float_array * from, float_array * to)
{
	int i;
	//to = init_float_array();

	for (i = 0; i < (*from).size; i++)
	{
		add_float(to, (*from).array[i]);
	}
}

/** \fn void sort_float_array(float_array * array)
* \brief Sort the elements of a dynamic float array with smallest first.
* \param array Pointer to the dynamic float array.
*/
/*void sort_float_array(float_array array)
{
	int i, j;
	float temp;
	// Using bubble sorts nested loops //
	for(i=0; i<(array.size-1); i++)
	{
		for(j=0; j<(array.size-1)-i; j++)
		{
			// Comparing the values between neighbours //
			if(*(array.array+j+1) < *(array.array+j))
			{
                // Swap neighbours //
                temp = *(array.array+j);
                *(array.array+j) = *(array.array+j+1);
                *(array.array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_float(float *array, int elements)
 *  \brief Sorts the elements of the float array in ascending order.
 *  \param Pointer to float array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_float(float array, int elements)
{
	#define  LEVEL  1000
	int i=0, left, right ;
	float pivot, begin[LEVEL], end[LEVEL];
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_float(float_array * array, float new_float)
* \brief Add an floateger to the dynamic float array.
* \param array Pointer to the dynamic float array.
* \param new_float The float to add
*/
void add_float(float_array * array, float new_float)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (float *)realloc((*array).array, ((*array).total_size * sizeof(float)));
	}
	(*array).array[(*array).size] = new_float;
	(*array).size++;
}

/** \fn void remove_float(float_array * array, int index)
 * \brief Remove an floateger from a dynamic float array.
 * \param array Pointer to the dynamic float array.
 * \param index The index of the float to remove.
 */
void remove_float(float_array * array, int index)
{
	int i;

	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_float_array(float_array * array)
 * \brief Print the elements of a dynamic float array.
 * \param array Pointer to the dynamic float array.
 */
void print_float_array(float_array * array)
{
	int i;
	/* printf(""); // compiler does not like empty prfloats */
	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %f", i, (*array).array[i]);
	}
}

/** \fn double_array * init_double_array()
 * \brief Allocate memory for a dynamic double array.
 * \return double_array Pointer to the new dynamic double array.
 */
void init_double_array(double_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (double *)malloc(ARRAY_BLOCK_SIZE * sizeof(double));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_double_array(double_array * array)
* \brief Reset the double array to hold nothing.
* \param array Pointer to the dynamic double array.
*/
void reset_double_array(double_array * array)
{
	(*array).size = 0;
}

/** \fn void free_double_array(double_array * array)
 * \brief Free the memory of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void free_double_array(double_array * array)
{
	free((*array).array);
}

void copy_double_array(double_array * from, double_array * to)
{
	int i;
	//to = init_double_array();

	for (i = 0; i < (*from).size; i++)
	{
		add_double(to, (*from).array[i]);
	}
}

/** \fn void sort_double_array(double_array * array)
 * \brief Sort the elements of a dynamic double array with smallest first.
 * \param array Pointer to the dynamic double array.
 */
/*void sort_double_array(double_array array)
{
	int i, j;
	double temp;

	// Using bubble sorts nested loops //
	for(i=0; i<(array.size-1); i++)
	{
		for(j=0; j<(array.size-1)-i; j++)
		{
			// Comparing the values between neighbours //
			if(*(array.array+j+1) < *(array.array+j))
			{
                // Swap neighbours //
                temp = *(array.array+j);
                *(array.array+j) = *(array.array+j+1);
                *(array.array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_double(double *array, int elements)
 *  \brief Sorts the elements of the double array in ascending order.
 *  \param Pointer to double array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_double(double array, int elements)
{
	#define  LEVEL  1000
	double pivot, begin[LEVEL], end[LEVEL];
	int  i=0, left, right ;
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_double(double_array * array, double new_double)
 * \brief Add an double to the dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param new_double The double to add
 */
void add_double(double_array * array, double new_double)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (double *)realloc((*array).array, ((*array).total_size * sizeof(double)));
	}
	(*array).array[(*array).size] = new_double;
	(*array).size++;
}

/** \fn void remove_double(double_array * array, int index)
 * \brief Remove an double from a dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param index The index of the double to remove.
 */
void remove_double(double_array * array, int index)
{
	int i;
	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_double_array(double_array * array)
 * \brief Print the elements of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void print_double_array(double_array * array)
{
	int i;

	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %f", i, (*array).array[i]);
	}
}

/** \fn char_array * init_char_array()
 * \brief Allocate memory for a dynamic char array.
 * \return char_array Pointer to the new dynamic char array.
 */
void init_char_array(char_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (char *)malloc(ARRAY_BLOCK_SIZE * sizeof(char));
	CHECK_POINTER((*array).array);
	(*array).array[0] = '\0';
}

/** \fn void reset_char_array(char_array * array)
* \brief Reset the char array to hold nothing.
* \param array Pointer to the dynamic char array.
*/
void reset_char_array(char_array * array)
{
	(*array).size = 0;
}

/** \fn void free_char_array(char_array * array)
 * \brief Free the memory of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void free_char_array(char_array * array)
{
	free((*array).array);
}

void copy_char_array(char_array * from, char_array * to)
{
	int i;

	for (i = 0; i < (*from).size; i++)
	{
		add_char(to, (*from).array[i]);
	}
}

/** \fn void add_char(char_array * array, char new_char)
 * \brief Add an char to the dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param new_char The char to add
 */
void add_char(char_array * array, char new_char)
{
	if((*array).size + 1 == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (char *)realloc((*array).array, ((*array).total_size * sizeof(char)));
	}
	(*array).array[(*array).size] = new_char;
	(*array).array[(*array).size + 1] = '\0';
	(*array).size++;
}

/** \fn void remove_char(char_array * array, int index)
 * \brief Remove an char from a dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param index The index of the char to remove.
 */
void remove_char(char_array * array, int index)
{
	int i;
	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn char * copy_array_to_str(char_array * array)
 * \brief Return pointer to string from a char_array.
 * \param array Pointer to the dynamic integer array.
 * \return char Pointer to the new string.
 */
char * copy_array_to_str(char_array * array)
{
	char * new_string = (char *)malloc( ((*array).size + 1) * sizeof(char));
	CHECK_POINTER(new_string);
	return strcpy(new_string, (*array).array);
}

/** \fn void print_char_array(char_array * array)
 * \brief Print the elements of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void print_char_array(char_array * array)
{
	printf("%s", (*array).array);
}

/* Functions for the transaction datatype */
/** \fn transaction_array * init_transaction_array()
 * \brief Allocate memory for a dynamic transaction array.
 * \return transaction_array Pointer to the new dynamic transaction array.
 */
void init_transaction_array(transaction_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (transaction *)malloc(ARRAY_BLOCK_SIZE * sizeof(transaction));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_transaction_array(transaction_array* array)
* \brief Reset the transaction array to hold nothing.
* \param array Pointer to the dynamic transaction array.
*/
void reset_transaction_array(transaction_array * array)
{
	(*array).size = 0;
}

/** \fn void free_transaction_array(transaction_array * array)
* \brief Free the memory of a dynamic transaction array.
* \param array Pointer to the dynamic transaction array.
*/
void free_transaction_array(transaction_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_transaction(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_transaction_array(transaction_array * from, transaction_array * to)
{
	int i;

	//to = init_transaction_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_transaction(to, (*from).array[i].quantity, (*from).array[i].avg_price);
	}
}

/** \fn void add_transaction(transaction_array * array, int quantity, double avg_price)
* \brief Add an transaction to the dynamic transaction array.
* \param array Pointer to the dynamic transaction array.
* \param new_int The transaction to add
*/
void add_transaction(transaction_array * array,  int quantity,  double avg_price)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (transaction *)realloc((*array).array, ((*array).total_size * sizeof(transaction)));
	}
	init_transaction(&(*array).array[(*array).size]);
	(*array).array[(*array).size].quantity = quantity;
	(*array).array[(*array).size].avg_price = avg_price;

	(*array).size++;
}

/** \fn void remove_transaction(transaction_array * array, int index)
 * \brief Remove an transaction from a dynamic transaction array.
 * \param array Pointer to the dynamic transaction array.
 * \param index The index of the transaction to remove.
 */
void remove_transaction(transaction_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_transaction(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_transaction(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the buyer datatype */
/** \fn buyer_array * init_buyer_array()
 * \brief Allocate memory for a dynamic buyer array.
 * \return buyer_array Pointer to the new dynamic buyer array.
 */
void init_buyer_array(buyer_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (buyer *)malloc(ARRAY_BLOCK_SIZE * sizeof(buyer));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_buyer_array(buyer_array* array)
* \brief Reset the buyer array to hold nothing.
* \param array Pointer to the dynamic buyer array.
*/
void reset_buyer_array(buyer_array * array)
{
	(*array).size = 0;
}

/** \fn void free_buyer_array(buyer_array * array)
* \brief Free the memory of a dynamic buyer array.
* \param array Pointer to the dynamic buyer array.
*/
void free_buyer_array(buyer_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_buyer(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_buyer_array(buyer_array * from, buyer_array * to)
{
	int i;

	//to = init_buyer_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_buyer(to, (*from).array[i].id, (*from).array[i].budget, (*from).array[i].recieved_quantity);
	}
}

/** \fn void add_buyer(buyer_array * array, int id, double budget, int recieved_quantity)
* \brief Add an buyer to the dynamic buyer array.
* \param array Pointer to the dynamic buyer array.
* \param new_int The buyer to add
*/
void add_buyer(buyer_array * array,  int id,  double budget,  int recieved_quantity)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (buyer *)realloc((*array).array, ((*array).total_size * sizeof(buyer)));
	}
	init_buyer(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].budget = budget;
	(*array).array[(*array).size].recieved_quantity = recieved_quantity;

	(*array).size++;
}

/** \fn void remove_buyer(buyer_array * array, int index)
 * \brief Remove an buyer from a dynamic buyer array.
 * \param array Pointer to the dynamic buyer array.
 * \param index The index of the buyer to remove.
 */
void remove_buyer(buyer_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_buyer(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_buyer(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the seller datatype */
/** \fn seller_array * init_seller_array()
 * \brief Allocate memory for a dynamic seller array.
 * \return seller_array Pointer to the new dynamic seller array.
 */
void init_seller_array(seller_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (seller *)malloc(ARRAY_BLOCK_SIZE * sizeof(seller));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_seller_array(seller_array* array)
* \brief Reset the seller array to hold nothing.
* \param array Pointer to the dynamic seller array.
*/
void reset_seller_array(seller_array * array)
{
	(*array).size = 0;
}

/** \fn void free_seller_array(seller_array * array)
* \brief Free the memory of a dynamic seller array.
* \param array Pointer to the dynamic seller array.
*/
void free_seller_array(seller_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_seller(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_seller_array(seller_array * from, seller_array * to)
{
	int i;

	//to = init_seller_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_seller(to, (*from).array[i].id, (*from).array[i].price, (*from).array[i].inventory);
	}
}

/** \fn void add_seller(seller_array * array, int id, double price, int inventory)
* \brief Add an seller to the dynamic seller array.
* \param array Pointer to the dynamic seller array.
* \param new_int The seller to add
*/
void add_seller(seller_array * array,  int id,  double price,  int inventory)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (seller *)realloc((*array).array, ((*array).total_size * sizeof(seller)));
	}
	init_seller(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].price = price;
	(*array).array[(*array).size].inventory = inventory;

	(*array).size++;
}

/** \fn void remove_seller(seller_array * array, int index)
 * \brief Remove an seller from a dynamic seller array.
 * \param array Pointer to the dynamic seller array.
 * \param index The index of the seller to remove.
 */
void remove_seller(seller_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_seller(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_seller(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the vacancy datatype */
/** \fn vacancy_array * init_vacancy_array()
 * \brief Allocate memory for a dynamic vacancy array.
 * \return vacancy_array Pointer to the new dynamic vacancy array.
 */
void init_vacancy_array(vacancy_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (vacancy *)malloc(ARRAY_BLOCK_SIZE * sizeof(vacancy));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_vacancy_array(vacancy_array* array)
* \brief Reset the vacancy array to hold nothing.
* \param array Pointer to the dynamic vacancy array.
*/
void reset_vacancy_array(vacancy_array * array)
{
	(*array).size = 0;
}

/** \fn void free_vacancy_array(vacancy_array * array)
* \brief Free the memory of a dynamic vacancy array.
* \param array Pointer to the dynamic vacancy array.
*/
void free_vacancy_array(vacancy_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_vacancy(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_vacancy_array(vacancy_array * from, vacancy_array * to)
{
	int i;

	//to = init_vacancy_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_vacancy(to, (*from).array[i].id, (*from).array[i].wage);
	}
}

/** \fn void add_vacancy(vacancy_array * array, int id, double wage)
* \brief Add an vacancy to the dynamic vacancy array.
* \param array Pointer to the dynamic vacancy array.
* \param new_int The vacancy to add
*/
void add_vacancy(vacancy_array * array,  int id,  double wage)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (vacancy *)realloc((*array).array, ((*array).total_size * sizeof(vacancy)));
	}
	init_vacancy(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].wage = wage;

	(*array).size++;
}

/** \fn void remove_vacancy(vacancy_array * array, int index)
 * \brief Remove an vacancy from a dynamic vacancy array.
 * \param array Pointer to the dynamic vacancy array.
 * \param index The index of the vacancy to remove.
 */
void remove_vacancy(vacancy_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_vacancy(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_vacancy(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the employee datatype */
/** \fn employee_array * init_employee_array()
 * \brief Allocate memory for a dynamic employee array.
 * \return employee_array Pointer to the new dynamic employee array.
 */
void init_employee_array(employee_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (employee *)malloc(ARRAY_BLOCK_SIZE * sizeof(employee));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_employee_array(employee_array* array)
* \brief Reset the employee array to hold nothing.
* \param array Pointer to the dynamic employee array.
*/
void reset_employee_array(employee_array * array)
{
	(*array).size = 0;
}

/** \fn void free_employee_array(employee_array * array)
* \brief Free the memory of a dynamic employee array.
* \param array Pointer to the dynamic employee array.
*/
void free_employee_array(employee_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_employee(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_employee_array(employee_array * from, employee_array * to)
{
	int i;

	//to = init_employee_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_employee(to, (*from).array[i].id, (*from).array[i].wage);
	}
}

/** \fn void add_employee(employee_array * array, int id, double wage)
* \brief Add an employee to the dynamic employee array.
* \param array Pointer to the dynamic employee array.
* \param new_int The employee to add
*/
void add_employee(employee_array * array,  int id,  double wage)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (employee *)realloc((*array).array, ((*array).total_size * sizeof(employee)));
	}
	init_employee(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].wage = wage;

	(*array).size++;
}

/** \fn void remove_employee(employee_array * array, int index)
 * \brief Remove an employee from a dynamic employee array.
 * \param array Pointer to the dynamic employee array.
 * \param index The index of the employee to remove.
 */
void remove_employee(employee_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_employee(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_employee(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the mortgage datatype */
/** \fn mortgage_array * init_mortgage_array()
 * \brief Allocate memory for a dynamic mortgage array.
 * \return mortgage_array Pointer to the new dynamic mortgage array.
 */
void init_mortgage_array(mortgage_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (mortgage *)malloc(ARRAY_BLOCK_SIZE * sizeof(mortgage));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_mortgage_array(mortgage_array* array)
* \brief Reset the mortgage array to hold nothing.
* \param array Pointer to the dynamic mortgage array.
*/
void reset_mortgage_array(mortgage_array * array)
{
	(*array).size = 0;
}

/** \fn void free_mortgage_array(mortgage_array * array)
* \brief Free the memory of a dynamic mortgage array.
* \param array Pointer to the dynamic mortgage array.
*/
void free_mortgage_array(mortgage_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_mortgage(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_mortgage_array(mortgage_array * from, mortgage_array * to)
{
	int i;

	//to = init_mortgage_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_mortgage(to, (*from).array[i].bank_id, (*from).array[i].principal, (*from).array[i].quarters_left, (*from).array[i].quarterly_interest, (*from).array[i].quarterly_principal);
	}
}

/** \fn void add_mortgage(mortgage_array * array, int bank_id, double principal, int quarters_left, double quarterly_interest, double quarterly_principal)
* \brief Add an mortgage to the dynamic mortgage array.
* \param array Pointer to the dynamic mortgage array.
* \param new_int The mortgage to add
*/
void add_mortgage(mortgage_array * array,  int bank_id,  double principal,  int quarters_left,  double quarterly_interest,  double quarterly_principal)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (mortgage *)realloc((*array).array, ((*array).total_size * sizeof(mortgage)));
	}
	init_mortgage(&(*array).array[(*array).size]);
	(*array).array[(*array).size].bank_id = bank_id;
	(*array).array[(*array).size].principal = principal;
	(*array).array[(*array).size].quarters_left = quarters_left;
	(*array).array[(*array).size].quarterly_interest = quarterly_interest;
	(*array).array[(*array).size].quarterly_principal = quarterly_principal;

	(*array).size++;
}

/** \fn void remove_mortgage(mortgage_array * array, int index)
 * \brief Remove an mortgage from a dynamic mortgage array.
 * \param array Pointer to the dynamic mortgage array.
 * \param index The index of the mortgage to remove.
 */
void remove_mortgage(mortgage_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_mortgage(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_mortgage(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the loan datatype */
/** \fn loan_array * init_loan_array()
 * \brief Allocate memory for a dynamic loan array.
 * \return loan_array Pointer to the new dynamic loan array.
 */
void init_loan_array(loan_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (loan *)malloc(ARRAY_BLOCK_SIZE * sizeof(loan));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_loan_array(loan_array* array)
* \brief Reset the loan array to hold nothing.
* \param array Pointer to the dynamic loan array.
*/
void reset_loan_array(loan_array * array)
{
	(*array).size = 0;
}

/** \fn void free_loan_array(loan_array * array)
* \brief Free the memory of a dynamic loan array.
* \param array Pointer to the dynamic loan array.
*/
void free_loan_array(loan_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_loan(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_loan_array(loan_array * from, loan_array * to)
{
	int i;

	//to = init_loan_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_loan(to, (*from).array[i].bank_id, (*from).array[i].amount, (*from).array[i].to_be_paid);
	}
}

/** \fn void add_loan(loan_array * array, int bank_id, double amount, double to_be_paid)
* \brief Add an loan to the dynamic loan array.
* \param array Pointer to the dynamic loan array.
* \param new_int The loan to add
*/
void add_loan(loan_array * array,  int bank_id,  double amount,  double to_be_paid)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (loan *)realloc((*array).array, ((*array).total_size * sizeof(loan)));
	}
	init_loan(&(*array).array[(*array).size]);
	(*array).array[(*array).size].bank_id = bank_id;
	(*array).array[(*array).size].amount = amount;
	(*array).array[(*array).size].to_be_paid = to_be_paid;

	(*array).size++;
}

/** \fn void remove_loan(loan_array * array, int index)
 * \brief Remove an loan from a dynamic loan array.
 * \param array Pointer to the dynamic loan array.
 * \param index The index of the loan to remove.
 */
void remove_loan(loan_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_loan(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_loan(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the hbuyer datatype */
/** \fn hbuyer_array * init_hbuyer_array()
 * \brief Allocate memory for a dynamic hbuyer array.
 * \return hbuyer_array Pointer to the new dynamic hbuyer array.
 */
void init_hbuyer_array(hbuyer_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (hbuyer *)malloc(ARRAY_BLOCK_SIZE * sizeof(hbuyer));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_hbuyer_array(hbuyer_array* array)
* \brief Reset the hbuyer array to hold nothing.
* \param array Pointer to the dynamic hbuyer array.
*/
void reset_hbuyer_array(hbuyer_array * array)
{
	(*array).size = 0;
}

/** \fn void free_hbuyer_array(hbuyer_array * array)
* \brief Free the memory of a dynamic hbuyer array.
* \param array Pointer to the dynamic hbuyer array.
*/
void free_hbuyer_array(hbuyer_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_hbuyer(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_hbuyer_array(hbuyer_array * from, hbuyer_array * to)
{
	int i;

	//to = init_hbuyer_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_hbuyer(to, (*from).array[i].buyer_id, (*from).array[i].bank_id, (*from).array[i].liquidity, (*from).array[i].quarterly_income, (*from).array[i].quarterly_mortgage_paid);
	}
}

/** \fn void add_hbuyer(hbuyer_array * array, int buyer_id, int bank_id, double liquidity, double quarterly_income, double quarterly_mortgage_paid)
* \brief Add an hbuyer to the dynamic hbuyer array.
* \param array Pointer to the dynamic hbuyer array.
* \param new_int The hbuyer to add
*/
void add_hbuyer(hbuyer_array * array,  int buyer_id,  int bank_id,  double liquidity,  double quarterly_income,  double quarterly_mortgage_paid)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (hbuyer *)realloc((*array).array, ((*array).total_size * sizeof(hbuyer)));
	}
	init_hbuyer(&(*array).array[(*array).size]);
	(*array).array[(*array).size].buyer_id = buyer_id;
	(*array).array[(*array).size].bank_id = bank_id;
	(*array).array[(*array).size].liquidity = liquidity;
	(*array).array[(*array).size].quarterly_income = quarterly_income;
	(*array).array[(*array).size].quarterly_mortgage_paid = quarterly_mortgage_paid;

	(*array).size++;
}

/** \fn void remove_hbuyer(hbuyer_array * array, int index)
 * \brief Remove an hbuyer from a dynamic hbuyer array.
 * \param array Pointer to the dynamic hbuyer array.
 * \param index The index of the hbuyer to remove.
 */
void remove_hbuyer(hbuyer_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_hbuyer(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_hbuyer(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the hseller datatype */
/** \fn hseller_array * init_hseller_array()
 * \brief Allocate memory for a dynamic hseller array.
 * \return hseller_array Pointer to the new dynamic hseller array.
 */
void init_hseller_array(hseller_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (hseller *)malloc(ARRAY_BLOCK_SIZE * sizeof(hseller));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_hseller_array(hseller_array* array)
* \brief Reset the hseller array to hold nothing.
* \param array Pointer to the dynamic hseller array.
*/
void reset_hseller_array(hseller_array * array)
{
	(*array).size = 0;
}

/** \fn void free_hseller_array(hseller_array * array)
* \brief Free the memory of a dynamic hseller array.
* \param array Pointer to the dynamic hseller array.
*/
void free_hseller_array(hseller_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_hseller(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_hseller_array(hseller_array * from, hseller_array * to)
{
	int i;

	//to = init_hseller_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_hseller(to, (*from).array[i].seller_id, (*from).array[i].price, (*from).array[i].quantity);
	}
}

/** \fn void add_hseller(hseller_array * array, int seller_id, double price, int quantity)
* \brief Add an hseller to the dynamic hseller array.
* \param array Pointer to the dynamic hseller array.
* \param new_int The hseller to add
*/
void add_hseller(hseller_array * array,  int seller_id,  double price,  int quantity)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (hseller *)realloc((*array).array, ((*array).total_size * sizeof(hseller)));
	}
	init_hseller(&(*array).array[(*array).size]);
	(*array).array[(*array).size].seller_id = seller_id;
	(*array).array[(*array).size].price = price;
	(*array).array[(*array).size].quantity = quantity;

	(*array).size++;
}

/** \fn void remove_hseller(hseller_array * array, int index)
 * \brief Remove an hseller from a dynamic hseller array.
 * \param array Pointer to the dynamic hseller array.
 * \param index The index of the hseller to remove.
 */
void remove_hseller(hseller_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_hseller(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_hseller(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the hbank datatype */
/** \fn hbank_array * init_hbank_array()
 * \brief Allocate memory for a dynamic hbank array.
 * \return hbank_array Pointer to the new dynamic hbank array.
 */
void init_hbank_array(hbank_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (hbank *)malloc(ARRAY_BLOCK_SIZE * sizeof(hbank));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_hbank_array(hbank_array* array)
* \brief Reset the hbank array to hold nothing.
* \param array Pointer to the dynamic hbank array.
*/
void reset_hbank_array(hbank_array * array)
{
	(*array).size = 0;
}

/** \fn void free_hbank_array(hbank_array * array)
* \brief Free the memory of a dynamic hbank array.
* \param array Pointer to the dynamic hbank array.
*/
void free_hbank_array(hbank_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_hbank(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_hbank_array(hbank_array * from, hbank_array * to)
{
	int i;

	//to = init_hbank_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_hbank(to, (*from).array[i].id, (*from).array[i].equity, (*from).array[i].risky_assets, (*from).array[i].amount_mortgaged);
	}
}

/** \fn void add_hbank(hbank_array * array, int id, double equity, double risky_assets, double amount_mortgaged)
* \brief Add an hbank to the dynamic hbank array.
* \param array Pointer to the dynamic hbank array.
* \param new_int The hbank to add
*/
void add_hbank(hbank_array * array,  int id,  double equity,  double risky_assets,  double amount_mortgaged)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (hbank *)realloc((*array).array, ((*array).total_size * sizeof(hbank)));
	}
	init_hbank(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].equity = equity;
	(*array).array[(*array).size].risky_assets = risky_assets;
	(*array).array[(*array).size].amount_mortgaged = amount_mortgaged;

	(*array).size++;
}

/** \fn void remove_hbank(hbank_array * array, int index)
 * \brief Remove an hbank from a dynamic hbank array.
 * \param array Pointer to the dynamic hbank array.
 * \param index The index of the hbank to remove.
 */
void remove_hbank(hbank_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_hbank(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_hbank(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}

/** \fn int idle()
 * \brief an idle function for use by agents.
 */
int idle()
{
	return 0;
}

double FLAME_get_environment_variable_ratio_liquidity()
{
	return FLAME_environment_variable_ratio_liquidity;
}
double FLAME_get_environment_variable_consumption_adjustment_speed()
{
	return FLAME_environment_variable_consumption_adjustment_speed;
}
double FLAME_get_environment_variable_wealth_effect()
{
	return FLAME_environment_variable_wealth_effect;
}
double FLAME_get_environment_variable_turnover_probability()
{
	return FLAME_environment_variable_turnover_probability;
}
double FLAME_get_environment_variable_production_markup()
{
	return FLAME_environment_variable_production_markup;
}
double FLAME_get_environment_variable_price_markup()
{
	return FLAME_environment_variable_price_markup;
}
double FLAME_get_environment_variable_firm_memory_persistance()
{
	return FLAME_environment_variable_firm_memory_persistance;
}
double FLAME_get_environment_variable_ratio_debt_firm()
{
	return FLAME_environment_variable_ratio_debt_firm;
}
double FLAME_get_environment_variable_ratio_fiscal_policy()
{
	return FLAME_environment_variable_ratio_fiscal_policy;
}
double FLAME_get_environment_variable_ratio_capitalist_households()
{
	return FLAME_environment_variable_ratio_capitalist_households;
}
double FLAME_get_environment_variable_inflation_target()
{
	return FLAME_environment_variable_inflation_target;
}
double FLAME_get_environment_variable_firms_minimum_equity_ratio()
{
	return FLAME_environment_variable_firms_minimum_equity_ratio;
}
double FLAME_get_environment_variable_firm_startup_leverage()
{
	return FLAME_environment_variable_firm_startup_leverage;
}
double FLAME_get_environment_variable_household_startup_leverage()
{
	return FLAME_environment_variable_household_startup_leverage;
}
double FLAME_get_environment_variable_car_buffer_threshold()
{
	return FLAME_environment_variable_car_buffer_threshold;
}
double FLAME_get_environment_variable_housing_market_entrance_prob()
{
	return FLAME_environment_variable_housing_market_entrance_prob;
}
double FLAME_get_environment_variable_fire_sale_threshold()
{
	return FLAME_environment_variable_fire_sale_threshold;
}
double FLAME_get_environment_variable_household_budget_constraint()
{
	return FLAME_environment_variable_household_budget_constraint;
}
double FLAME_get_environment_variable_capital_adequecy_ratio()
{
	return FLAME_environment_variable_capital_adequecy_ratio;
}
double FLAME_get_environment_variable_housing_price_up_rate()
{
	return FLAME_environment_variable_housing_price_up_rate;
}
double FLAME_get_environment_variable_housing_price_down_rate()
{
	return FLAME_environment_variable_housing_price_down_rate;
}
double FLAME_get_environment_variable_household_mortgage_writeoff_high()
{
	return FLAME_environment_variable_household_mortgage_writeoff_high;
}
double FLAME_get_environment_variable_household_mortgage_writeoff_low()
{
	return FLAME_environment_variable_household_mortgage_writeoff_low;
}


