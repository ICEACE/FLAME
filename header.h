/**
 * \file  header.h
 * \brief Header for xmachine data structures and transition functions.
 */
#ifndef _HEADER_H
#define _HEADER_H

#ifdef _DEBUG_MODE
    #define ERRCHECK
#else
    #define NDEBUG
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "mboard.h"

#define FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS 0
#define FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS 0
#define FLAME_USE_FILTERS_IN_SYNC 1


/* Checking macros */
#ifdef CHECK_MEMORY
#define CHECK_POINTER(PT) if(PT==NULL){printf("**** ERROR in Memory check 1\n");exit(1);}
#else
#define CHECK_POINTER(PT)
#endif


/** \def RATIO_LIQUIDITY
 * \brief Provide access to environment variables in uppercase. */
#define RATIO_LIQUIDITY (FLAME_get_environment_variable_ratio_liquidity())
/** \def CONSUMPTION_ADJUSTMENT_SPEED
 * \brief Provide access to environment variables in uppercase. */
#define CONSUMPTION_ADJUSTMENT_SPEED (FLAME_get_environment_variable_consumption_adjustment_speed())
/** \def WEALTH_EFFECT
 * \brief Provide access to environment variables in uppercase. */
#define WEALTH_EFFECT (FLAME_get_environment_variable_wealth_effect())
/** \def TURNOVER_PROBABILITY
 * \brief Provide access to environment variables in uppercase. */
#define TURNOVER_PROBABILITY (FLAME_get_environment_variable_turnover_probability())
/** \def PRODUCTION_MARKUP
 * \brief Provide access to environment variables in uppercase. */
#define PRODUCTION_MARKUP (FLAME_get_environment_variable_production_markup())
/** \def PRICE_MARKUP
 * \brief Provide access to environment variables in uppercase. */
#define PRICE_MARKUP (FLAME_get_environment_variable_price_markup())
/** \def FIRM_MEMORY_PERSISTANCE
 * \brief Provide access to environment variables in uppercase. */
#define FIRM_MEMORY_PERSISTANCE (FLAME_get_environment_variable_firm_memory_persistance())
/** \def RATIO_DEBT_FIRM
 * \brief Provide access to environment variables in uppercase. */
#define RATIO_DEBT_FIRM (FLAME_get_environment_variable_ratio_debt_firm())
/** \def RATIO_FISCAL_POLICY
 * \brief Provide access to environment variables in uppercase. */
#define RATIO_FISCAL_POLICY (FLAME_get_environment_variable_ratio_fiscal_policy())
/** \def RATIO_CAPITALIST_HOUSEHOLDS
 * \brief Provide access to environment variables in uppercase. */
#define RATIO_CAPITALIST_HOUSEHOLDS (FLAME_get_environment_variable_ratio_capitalist_households())
/** \def INFLATION_TARGET
 * \brief Provide access to environment variables in uppercase. */
#define INFLATION_TARGET (FLAME_get_environment_variable_inflation_target())
/** \def FIRMS_MINIMUM_EQUITY_RATIO
 * \brief Provide access to environment variables in uppercase. */
#define FIRMS_MINIMUM_EQUITY_RATIO (FLAME_get_environment_variable_firms_minimum_equity_ratio())
/** \def FIRM_STARTUP_LEVERAGE
 * \brief Provide access to environment variables in uppercase. */
#define FIRM_STARTUP_LEVERAGE (FLAME_get_environment_variable_firm_startup_leverage())
/** \def HOUSEHOLD_STARTUP_LEVERAGE
 * \brief Provide access to environment variables in uppercase. */
#define HOUSEHOLD_STARTUP_LEVERAGE (FLAME_get_environment_variable_household_startup_leverage())
/** \def CAR_BUFFER_THRESHOLD
 * \brief Provide access to environment variables in uppercase. */
#define CAR_BUFFER_THRESHOLD (FLAME_get_environment_variable_car_buffer_threshold())
/** \def HOUSING_MARKET_ENTRANCE_PROB
 * \brief Provide access to environment variables in uppercase. */
#define HOUSING_MARKET_ENTRANCE_PROB (FLAME_get_environment_variable_housing_market_entrance_prob())
/** \def FIRE_SALE_THRESHOLD
 * \brief Provide access to environment variables in uppercase. */
#define FIRE_SALE_THRESHOLD (FLAME_get_environment_variable_fire_sale_threshold())
/** \def HOUSEHOLD_BUDGET_CONSTRAINT
 * \brief Provide access to environment variables in uppercase. */
#define HOUSEHOLD_BUDGET_CONSTRAINT (FLAME_get_environment_variable_household_budget_constraint())
/** \def CAPITAL_ADEQUECY_RATIO
 * \brief Provide access to environment variables in uppercase. */
#define CAPITAL_ADEQUECY_RATIO (FLAME_get_environment_variable_capital_adequecy_ratio())
/** \def HOUSING_PRICE_UP_RATE
 * \brief Provide access to environment variables in uppercase. */
#define HOUSING_PRICE_UP_RATE (FLAME_get_environment_variable_housing_price_up_rate())
/** \def HOUSING_PRICE_DOWN_RATE
 * \brief Provide access to environment variables in uppercase. */
#define HOUSING_PRICE_DOWN_RATE (FLAME_get_environment_variable_housing_price_down_rate())
/** \def HOUSEHOLD_MORTGAGE_WRITEOFF_HIGH
 * \brief Provide access to environment variables in uppercase. */
#define HOUSEHOLD_MORTGAGE_WRITEOFF_HIGH (FLAME_get_environment_variable_household_mortgage_writeoff_high())
/** \def HOUSEHOLD_MORTGAGE_WRITEOFF_LOW
 * \brief Provide access to environment variables in uppercase. */
#define HOUSEHOLD_MORTGAGE_WRITEOFF_LOW (FLAME_get_environment_variable_household_mortgage_writeoff_low())
/** \def ARRAY_BLOCK_SIZE
 * \brief The block size to allocate to dynamic arrays. */
#define ARRAY_BLOCK_SIZE 10
/** \def ARRAY_GROWTH_RATE
 * \brief Growth ratio to scale size of dynamic arrays. 
 * Use golden ratio. This makes for a Fibonacci sequence, so the next allocation size 
 * is the sum of the current size and the previous size thus improving the chance of 
 * memory block reuse. It also allows for moderate rate of growth.
 */
#define ARRAY_GROWTH_RATE 1.618034
/** \def START_FIRM_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP
 * \brief Start of loop to process firm_bank_update_deposit messages. */
#define START_FIRM_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP  for(firm_bank_update_deposit_message = get_first_firm_bank_update_deposit_message(); firm_bank_update_deposit_message != NULL; firm_bank_update_deposit_message = get_next_firm_bank_update_deposit_message(firm_bank_update_deposit_message)) {
/** \def FINISH_FIRM_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP
 * \brief Finish of loop to process firm_bank_update_deposit messages. */
#define FINISH_FIRM_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP }
/** \def START_HOUSEHOLD_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP
 * \brief Start of loop to process household_bank_update_deposit messages. */
#define START_HOUSEHOLD_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP  for(household_bank_update_deposit_message = get_first_household_bank_update_deposit_message(); household_bank_update_deposit_message != NULL; household_bank_update_deposit_message = get_next_household_bank_update_deposit_message(household_bank_update_deposit_message)) {
/** \def FINISH_HOUSEHOLD_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP
 * \brief Finish of loop to process household_bank_update_deposit messages. */
#define FINISH_HOUSEHOLD_BANK_UPDATE_DEPOSIT_MESSAGE_LOOP }
/** \def START_INTEREST_RATE_MESSAGE_LOOP
 * \brief Start of loop to process interest_rate messages. */
#define START_INTEREST_RATE_MESSAGE_LOOP  for(interest_rate_message = get_first_interest_rate_message(); interest_rate_message != NULL; interest_rate_message = get_next_interest_rate_message(interest_rate_message)) {
/** \def FINISH_INTEREST_RATE_MESSAGE_LOOP
 * \brief Finish of loop to process interest_rate messages. */
#define FINISH_INTEREST_RATE_MESSAGE_LOOP }
/** \def START_BUY_MESSAGE_LOOP
 * \brief Start of loop to process buy messages. */
#define START_BUY_MESSAGE_LOOP  for(buy_message = get_first_buy_message(); buy_message != NULL; buy_message = get_next_buy_message(buy_message)) {
/** \def FINISH_BUY_MESSAGE_LOOP
 * \brief Finish of loop to process buy messages. */
#define FINISH_BUY_MESSAGE_LOOP }
/** \def START_BOUGHT_MESSAGE_LOOP
 * \brief Start of loop to process bought messages. */
#define START_BOUGHT_MESSAGE_LOOP  for(bought_message = get_first_bought_message(); bought_message != NULL; bought_message = get_next_bought_message(bought_message)) {
/** \def FINISH_BOUGHT_MESSAGE_LOOP
 * \brief Finish of loop to process bought messages. */
#define FINISH_BOUGHT_MESSAGE_LOOP }
/** \def START_SELL_MESSAGE_LOOP
 * \brief Start of loop to process sell messages. */
#define START_SELL_MESSAGE_LOOP  for(sell_message = get_first_sell_message(); sell_message != NULL; sell_message = get_next_sell_message(sell_message)) {
/** \def FINISH_SELL_MESSAGE_LOOP
 * \brief Finish of loop to process sell messages. */
#define FINISH_SELL_MESSAGE_LOOP }
/** \def START_SOLD_MESSAGE_LOOP
 * \brief Start of loop to process sold messages. */
#define START_SOLD_MESSAGE_LOOP  for(sold_message = get_first_sold_message(); sold_message != NULL; sold_message = get_next_sold_message(sold_message)) {
/** \def FINISH_SOLD_MESSAGE_LOOP
 * \brief Finish of loop to process sold messages. */
#define FINISH_SOLD_MESSAGE_LOOP }
/** \def START_GOODS_TRANSACTIONS_SUMMARY_MESSAGE_LOOP
 * \brief Start of loop to process goods_transactions_summary messages. */
#define START_GOODS_TRANSACTIONS_SUMMARY_MESSAGE_LOOP  for(goods_transactions_summary_message = get_first_goods_transactions_summary_message(); goods_transactions_summary_message != NULL; goods_transactions_summary_message = get_next_goods_transactions_summary_message(goods_transactions_summary_message)) {
/** \def FINISH_GOODS_TRANSACTIONS_SUMMARY_MESSAGE_LOOP
 * \brief Finish of loop to process goods_transactions_summary messages. */
#define FINISH_GOODS_TRANSACTIONS_SUMMARY_MESSAGE_LOOP }
/** \def START_FIRED_MESSAGE_LOOP
 * \brief Start of loop to process fired messages. */
#define START_FIRED_MESSAGE_LOOP  for(fired_message = get_first_fired_message(); fired_message != NULL; fired_message = get_next_fired_message(fired_message)) {
/** \def FINISH_FIRED_MESSAGE_LOOP
 * \brief Finish of loop to process fired messages. */
#define FINISH_FIRED_MESSAGE_LOOP }
/** \def START_VACANCY_STAGE1_MESSAGE_LOOP
 * \brief Start of loop to process vacancy_stage1 messages. */
#define START_VACANCY_STAGE1_MESSAGE_LOOP  for(vacancy_stage1_message = get_first_vacancy_stage1_message(); vacancy_stage1_message != NULL; vacancy_stage1_message = get_next_vacancy_stage1_message(vacancy_stage1_message)) {
/** \def FINISH_VACANCY_STAGE1_MESSAGE_LOOP
 * \brief Finish of loop to process vacancy_stage1 messages. */
#define FINISH_VACANCY_STAGE1_MESSAGE_LOOP }
/** \def START_JOB_APPLICATION_STAGE2_MESSAGE_LOOP
 * \brief Start of loop to process job_application_stage2 messages. */
#define START_JOB_APPLICATION_STAGE2_MESSAGE_LOOP  for(job_application_stage2_message = get_first_job_application_stage2_message(); job_application_stage2_message != NULL; job_application_stage2_message = get_next_job_application_stage2_message(job_application_stage2_message)) {
/** \def FINISH_JOB_APPLICATION_STAGE2_MESSAGE_LOOP
 * \brief Finish of loop to process job_application_stage2 messages. */
#define FINISH_JOB_APPLICATION_STAGE2_MESSAGE_LOOP }
/** \def START_JOB_APPLICATION_STAGE1_MESSAGE_LOOP
 * \brief Start of loop to process job_application_stage1 messages. */
#define START_JOB_APPLICATION_STAGE1_MESSAGE_LOOP  for(job_application_stage1_message = get_first_job_application_stage1_message(); job_application_stage1_message != NULL; job_application_stage1_message = get_next_job_application_stage1_message(job_application_stage1_message)) {
/** \def FINISH_JOB_APPLICATION_STAGE1_MESSAGE_LOOP
 * \brief Finish of loop to process job_application_stage1 messages. */
#define FINISH_JOB_APPLICATION_STAGE1_MESSAGE_LOOP }
/** \def START_JOB_MATCH_STAGE1_MESSAGE_LOOP
 * \brief Start of loop to process job_match_stage1 messages. */
#define START_JOB_MATCH_STAGE1_MESSAGE_LOOP  for(job_match_stage1_message = get_first_job_match_stage1_message(); job_match_stage1_message != NULL; job_match_stage1_message = get_next_job_match_stage1_message(job_match_stage1_message)) {
/** \def FINISH_JOB_MATCH_STAGE1_MESSAGE_LOOP
 * \brief Finish of loop to process job_match_stage1 messages. */
#define FINISH_JOB_MATCH_STAGE1_MESSAGE_LOOP }
/** \def START_JOB_CHANGE_MESSAGE_LOOP
 * \brief Start of loop to process job_change messages. */
#define START_JOB_CHANGE_MESSAGE_LOOP  for(job_change_message = get_first_job_change_message(); job_change_message != NULL; job_change_message = get_next_job_change_message(job_change_message)) {
/** \def FINISH_JOB_CHANGE_MESSAGE_LOOP
 * \brief Finish of loop to process job_change messages. */
#define FINISH_JOB_CHANGE_MESSAGE_LOOP }
/** \def START_VACANCY_STAGE2_MESSAGE_LOOP
 * \brief Start of loop to process vacancy_stage2 messages. */
#define START_VACANCY_STAGE2_MESSAGE_LOOP  for(vacancy_stage2_message = get_first_vacancy_stage2_message(); vacancy_stage2_message != NULL; vacancy_stage2_message = get_next_vacancy_stage2_message(vacancy_stage2_message)) {
/** \def FINISH_VACANCY_STAGE2_MESSAGE_LOOP
 * \brief Finish of loop to process vacancy_stage2 messages. */
#define FINISH_VACANCY_STAGE2_MESSAGE_LOOP }
/** \def START_JOB_MATCH_STAGE2_MESSAGE_LOOP
 * \brief Start of loop to process job_match_stage2 messages. */
#define START_JOB_MATCH_STAGE2_MESSAGE_LOOP  for(job_match_stage2_message = get_first_job_match_stage2_message(); job_match_stage2_message != NULL; job_match_stage2_message = get_next_job_match_stage2_message(job_match_stage2_message)) {
/** \def FINISH_JOB_MATCH_STAGE2_MESSAGE_LOOP
 * \brief Finish of loop to process job_match_stage2 messages. */
#define FINISH_JOB_MATCH_STAGE2_MESSAGE_LOOP }
/** \def START_EMPLOYMENT_STATUS_MESSAGE_LOOP
 * \brief Start of loop to process employment_status messages. */
#define START_EMPLOYMENT_STATUS_MESSAGE_LOOP  for(employment_status_message = get_first_employment_status_message(); employment_status_message != NULL; employment_status_message = get_next_employment_status_message(employment_status_message)) {
/** \def FINISH_EMPLOYMENT_STATUS_MESSAGE_LOOP
 * \brief Finish of loop to process employment_status messages. */
#define FINISH_EMPLOYMENT_STATUS_MESSAGE_LOOP }
/** \def START_LOAN_REQUEST_1_MESSAGE_LOOP
 * \brief Start of loop to process loan_request_1 messages. */
#define START_LOAN_REQUEST_1_MESSAGE_LOOP  for(loan_request_1_message = get_first_loan_request_1_message(); loan_request_1_message != NULL; loan_request_1_message = get_next_loan_request_1_message(loan_request_1_message)) {
/** \def FINISH_LOAN_REQUEST_1_MESSAGE_LOOP
 * \brief Finish of loop to process loan_request_1 messages. */
#define FINISH_LOAN_REQUEST_1_MESSAGE_LOOP }
/** \def START_LOAN_REQUEST_2_MESSAGE_LOOP
 * \brief Start of loop to process loan_request_2 messages. */
#define START_LOAN_REQUEST_2_MESSAGE_LOOP  for(loan_request_2_message = get_first_loan_request_2_message(); loan_request_2_message != NULL; loan_request_2_message = get_next_loan_request_2_message(loan_request_2_message)) {
/** \def FINISH_LOAN_REQUEST_2_MESSAGE_LOOP
 * \brief Finish of loop to process loan_request_2 messages. */
#define FINISH_LOAN_REQUEST_2_MESSAGE_LOOP }
/** \def START_LOAN_ACKNOWLEDGE_1_MESSAGE_LOOP
 * \brief Start of loop to process loan_acknowledge_1 messages. */
#define START_LOAN_ACKNOWLEDGE_1_MESSAGE_LOOP  for(loan_acknowledge_1_message = get_first_loan_acknowledge_1_message(); loan_acknowledge_1_message != NULL; loan_acknowledge_1_message = get_next_loan_acknowledge_1_message(loan_acknowledge_1_message)) {
/** \def FINISH_LOAN_ACKNOWLEDGE_1_MESSAGE_LOOP
 * \brief Finish of loop to process loan_acknowledge_1 messages. */
#define FINISH_LOAN_ACKNOWLEDGE_1_MESSAGE_LOOP }
/** \def START_LOAN_ACKNOWLEDGE_2_MESSAGE_LOOP
 * \brief Start of loop to process loan_acknowledge_2 messages. */
#define START_LOAN_ACKNOWLEDGE_2_MESSAGE_LOOP  for(loan_acknowledge_2_message = get_first_loan_acknowledge_2_message(); loan_acknowledge_2_message != NULL; loan_acknowledge_2_message = get_next_loan_acknowledge_2_message(loan_acknowledge_2_message)) {
/** \def FINISH_LOAN_ACKNOWLEDGE_2_MESSAGE_LOOP
 * \brief Finish of loop to process loan_acknowledge_2 messages. */
#define FINISH_LOAN_ACKNOWLEDGE_2_MESSAGE_LOOP }
/** \def START_DEBT_REQUEST_MESSAGE_LOOP
 * \brief Start of loop to process debt_request messages. */
#define START_DEBT_REQUEST_MESSAGE_LOOP  for(debt_request_message = get_first_debt_request_message(); debt_request_message != NULL; debt_request_message = get_next_debt_request_message(debt_request_message)) {
/** \def FINISH_DEBT_REQUEST_MESSAGE_LOOP
 * \brief Finish of loop to process debt_request messages. */
#define FINISH_DEBT_REQUEST_MESSAGE_LOOP }
/** \def START_DEBT_ACK_MESSAGE_LOOP
 * \brief Start of loop to process debt_ack messages. */
#define START_DEBT_ACK_MESSAGE_LOOP  for(debt_ack_message = get_first_debt_ack_message(); debt_ack_message != NULL; debt_ack_message = get_next_debt_ack_message(debt_ack_message)) {
/** \def FINISH_DEBT_ACK_MESSAGE_LOOP
 * \brief Finish of loop to process debt_ack messages. */
#define FINISH_DEBT_ACK_MESSAGE_LOOP }
/** \def START_HOUSEHOLD_SHARE_MESSAGE_LOOP
 * \brief Start of loop to process household_share messages. */
#define START_HOUSEHOLD_SHARE_MESSAGE_LOOP  for(household_share_message = get_first_household_share_message(); household_share_message != NULL; household_share_message = get_next_household_share_message(household_share_message)) {
/** \def FINISH_HOUSEHOLD_SHARE_MESSAGE_LOOP
 * \brief Finish of loop to process household_share messages. */
#define FINISH_HOUSEHOLD_SHARE_MESSAGE_LOOP }
/** \def START_CAPITAL_TAX_MESSAGE_LOOP
 * \brief Start of loop to process capital_tax messages. */
#define START_CAPITAL_TAX_MESSAGE_LOOP  for(capital_tax_message = get_first_capital_tax_message(); capital_tax_message != NULL; capital_tax_message = get_next_capital_tax_message(capital_tax_message)) {
/** \def FINISH_CAPITAL_TAX_MESSAGE_LOOP
 * \brief Finish of loop to process capital_tax messages. */
#define FINISH_CAPITAL_TAX_MESSAGE_LOOP }
/** \def START_LABOUR_TAX_MESSAGE_LOOP
 * \brief Start of loop to process labour_tax messages. */
#define START_LABOUR_TAX_MESSAGE_LOOP  for(labour_tax_message = get_first_labour_tax_message(); labour_tax_message != NULL; labour_tax_message = get_next_labour_tax_message(labour_tax_message)) {
/** \def FINISH_LABOUR_TAX_MESSAGE_LOOP
 * \brief Finish of loop to process labour_tax messages. */
#define FINISH_LABOUR_TAX_MESSAGE_LOOP }
/** \def START_UNEMPLOYMENT_BENEFIT_MESSAGE_LOOP
 * \brief Start of loop to process unemployment_benefit messages. */
#define START_UNEMPLOYMENT_BENEFIT_MESSAGE_LOOP  for(unemployment_benefit_message = get_first_unemployment_benefit_message(); unemployment_benefit_message != NULL; unemployment_benefit_message = get_next_unemployment_benefit_message(unemployment_benefit_message)) {
/** \def FINISH_UNEMPLOYMENT_BENEFIT_MESSAGE_LOOP
 * \brief Finish of loop to process unemployment_benefit messages. */
#define FINISH_UNEMPLOYMENT_BENEFIT_MESSAGE_LOOP }
/** \def START_GENERAL_BENEFIT_MESSAGE_LOOP
 * \brief Start of loop to process general_benefit messages. */
#define START_GENERAL_BENEFIT_MESSAGE_LOOP  for(general_benefit_message = get_first_general_benefit_message(); general_benefit_message != NULL; general_benefit_message = get_next_general_benefit_message(general_benefit_message)) {
/** \def FINISH_GENERAL_BENEFIT_MESSAGE_LOOP
 * \brief Finish of loop to process general_benefit messages. */
#define FINISH_GENERAL_BENEFIT_MESSAGE_LOOP }
/** \def START_TAX_RATE_MESSAGE_LOOP
 * \brief Start of loop to process tax_rate messages. */
#define START_TAX_RATE_MESSAGE_LOOP  for(tax_rate_message = get_first_tax_rate_message(); tax_rate_message != NULL; tax_rate_message = get_next_tax_rate_message(tax_rate_message)) {
/** \def FINISH_TAX_RATE_MESSAGE_LOOP
 * \brief Finish of loop to process tax_rate messages. */
#define FINISH_TAX_RATE_MESSAGE_LOOP }
/** \def START_FUND_REQUEST_MESSAGE_LOOP
 * \brief Start of loop to process fund_request messages. */
#define START_FUND_REQUEST_MESSAGE_LOOP  for(fund_request_message = get_first_fund_request_message(); fund_request_message != NULL; fund_request_message = get_next_fund_request_message(fund_request_message)) {
/** \def FINISH_FUND_REQUEST_MESSAGE_LOOP
 * \brief Finish of loop to process fund_request messages. */
#define FINISH_FUND_REQUEST_MESSAGE_LOOP }
/** \def START_FUND_REQUEST_ACK_MESSAGE_LOOP
 * \brief Start of loop to process fund_request_ack messages. */
#define START_FUND_REQUEST_ACK_MESSAGE_LOOP  for(fund_request_ack_message = get_first_fund_request_ack_message(); fund_request_ack_message != NULL; fund_request_ack_message = get_next_fund_request_ack_message(fund_request_ack_message)) {
/** \def FINISH_FUND_REQUEST_ACK_MESSAGE_LOOP
 * \brief Finish of loop to process fund_request_ack messages. */
#define FINISH_FUND_REQUEST_ACK_MESSAGE_LOOP }
/** \def START_NEW_ENTRANT_LOAN_MESSAGE_LOOP
 * \brief Start of loop to process new_entrant_loan messages. */
#define START_NEW_ENTRANT_LOAN_MESSAGE_LOOP  for(new_entrant_loan_message = get_first_new_entrant_loan_message(); new_entrant_loan_message != NULL; new_entrant_loan_message = get_next_new_entrant_loan_message(new_entrant_loan_message)) {
/** \def FINISH_NEW_ENTRANT_LOAN_MESSAGE_LOOP
 * \brief Finish of loop to process new_entrant_loan messages. */
#define FINISH_NEW_ENTRANT_LOAN_MESSAGE_LOOP }
/** \def START_INTEREST_ON_LOAN_MESSAGE_LOOP
 * \brief Start of loop to process interest_on_loan messages. */
#define START_INTEREST_ON_LOAN_MESSAGE_LOOP  for(interest_on_loan_message = get_first_interest_on_loan_message(); interest_on_loan_message != NULL; interest_on_loan_message = get_next_interest_on_loan_message(interest_on_loan_message)) {
/** \def FINISH_INTEREST_ON_LOAN_MESSAGE_LOOP
 * \brief Finish of loop to process interest_on_loan messages. */
#define FINISH_INTEREST_ON_LOAN_MESSAGE_LOOP }
/** \def START_LOAN_WRITEOFF_MESSAGE_LOOP
 * \brief Start of loop to process loan_writeoff messages. */
#define START_LOAN_WRITEOFF_MESSAGE_LOOP  for(loan_writeoff_message = get_first_loan_writeoff_message(); loan_writeoff_message != NULL; loan_writeoff_message = get_next_loan_writeoff_message(loan_writeoff_message)) {
/** \def FINISH_LOAN_WRITEOFF_MESSAGE_LOOP
 * \brief Finish of loop to process loan_writeoff messages. */
#define FINISH_LOAN_WRITEOFF_MESSAGE_LOOP }
/** \def START_FIRM_NET_PROFIT_MESSAGE_LOOP
 * \brief Start of loop to process firm_net_profit messages. */
#define START_FIRM_NET_PROFIT_MESSAGE_LOOP  for(firm_net_profit_message = get_first_firm_net_profit_message(); firm_net_profit_message != NULL; firm_net_profit_message = get_next_firm_net_profit_message(firm_net_profit_message)) {
/** \def FINISH_FIRM_NET_PROFIT_MESSAGE_LOOP
 * \brief Finish of loop to process firm_net_profit messages. */
#define FINISH_FIRM_NET_PROFIT_MESSAGE_LOOP }
/** \def START_BANK_NET_PROFIT_MESSAGE_LOOP
 * \brief Start of loop to process bank_net_profit messages. */
#define START_BANK_NET_PROFIT_MESSAGE_LOOP  for(bank_net_profit_message = get_first_bank_net_profit_message(); bank_net_profit_message != NULL; bank_net_profit_message = get_next_bank_net_profit_message(bank_net_profit_message)) {
/** \def FINISH_BANK_NET_PROFIT_MESSAGE_LOOP
 * \brief Finish of loop to process bank_net_profit messages. */
#define FINISH_BANK_NET_PROFIT_MESSAGE_LOOP }
/** \def START_HOUSING_PRICE_MESSAGE_LOOP
 * \brief Start of loop to process housing_price messages. */
#define START_HOUSING_PRICE_MESSAGE_LOOP  for(housing_price_message = get_first_housing_price_message(); housing_price_message != NULL; housing_price_message = get_next_housing_price_message(housing_price_message)) {
/** \def FINISH_HOUSING_PRICE_MESSAGE_LOOP
 * \brief Finish of loop to process housing_price messages. */
#define FINISH_HOUSING_PRICE_MESSAGE_LOOP }
/** \def START_BUY_HOUSING_MESSAGE_LOOP
 * \brief Start of loop to process buy_housing messages. */
#define START_BUY_HOUSING_MESSAGE_LOOP  for(buy_housing_message = get_first_buy_housing_message(); buy_housing_message != NULL; buy_housing_message = get_next_buy_housing_message(buy_housing_message)) {
/** \def FINISH_BUY_HOUSING_MESSAGE_LOOP
 * \brief Finish of loop to process buy_housing messages. */
#define FINISH_BUY_HOUSING_MESSAGE_LOOP }
/** \def START_SELL_HOUSING_MESSAGE_LOOP
 * \brief Start of loop to process sell_housing messages. */
#define START_SELL_HOUSING_MESSAGE_LOOP  for(sell_housing_message = get_first_sell_housing_message(); sell_housing_message != NULL; sell_housing_message = get_next_sell_housing_message(sell_housing_message)) {
/** \def FINISH_SELL_HOUSING_MESSAGE_LOOP
 * \brief Finish of loop to process sell_housing messages. */
#define FINISH_SELL_HOUSING_MESSAGE_LOOP }
/** \def START_BOUGHT_HOUSING_MESSAGE_LOOP
 * \brief Start of loop to process bought_housing messages. */
#define START_BOUGHT_HOUSING_MESSAGE_LOOP  for(bought_housing_message = get_first_bought_housing_message(); bought_housing_message != NULL; bought_housing_message = get_next_bought_housing_message(bought_housing_message)) {
/** \def FINISH_BOUGHT_HOUSING_MESSAGE_LOOP
 * \brief Finish of loop to process bought_housing messages. */
#define FINISH_BOUGHT_HOUSING_MESSAGE_LOOP }
/** \def START_SOLD_HOUSING_MESSAGE_LOOP
 * \brief Start of loop to process sold_housing messages. */
#define START_SOLD_HOUSING_MESSAGE_LOOP  for(sold_housing_message = get_first_sold_housing_message(); sold_housing_message != NULL; sold_housing_message = get_next_sold_housing_message(sold_housing_message)) {
/** \def FINISH_SOLD_HOUSING_MESSAGE_LOOP
 * \brief Finish of loop to process sold_housing messages. */
#define FINISH_SOLD_HOUSING_MESSAGE_LOOP }
/** \def START_MORTGAGING_CAPACITY_MESSAGE_LOOP
 * \brief Start of loop to process mortgaging_capacity messages. */
#define START_MORTGAGING_CAPACITY_MESSAGE_LOOP  for(mortgaging_capacity_message = get_first_mortgaging_capacity_message(); mortgaging_capacity_message != NULL; mortgaging_capacity_message = get_next_mortgaging_capacity_message(mortgaging_capacity_message)) {
/** \def FINISH_MORTGAGING_CAPACITY_MESSAGE_LOOP
 * \brief Finish of loop to process mortgaging_capacity messages. */
#define FINISH_MORTGAGING_CAPACITY_MESSAGE_LOOP }
/** \def START_MORTGAGE_REQUESTS_MESSAGE_LOOP
 * \brief Start of loop to process mortgage_requests messages. */
#define START_MORTGAGE_REQUESTS_MESSAGE_LOOP  for(mortgage_requests_message = get_first_mortgage_requests_message(); mortgage_requests_message != NULL; mortgage_requests_message = get_next_mortgage_requests_message(mortgage_requests_message)) {
/** \def FINISH_MORTGAGE_REQUESTS_MESSAGE_LOOP
 * \brief Finish of loop to process mortgage_requests messages. */
#define FINISH_MORTGAGE_REQUESTS_MESSAGE_LOOP }
/** \def START_MORTGAGE_PAYMENT_FROM_SALE_MESSAGE_LOOP
 * \brief Start of loop to process mortgage_payment_from_sale messages. */
#define START_MORTGAGE_PAYMENT_FROM_SALE_MESSAGE_LOOP  for(mortgage_payment_from_sale_message = get_first_mortgage_payment_from_sale_message(); mortgage_payment_from_sale_message != NULL; mortgage_payment_from_sale_message = get_next_mortgage_payment_from_sale_message(mortgage_payment_from_sale_message)) {
/** \def FINISH_MORTGAGE_PAYMENT_FROM_SALE_MESSAGE_LOOP
 * \brief Finish of loop to process mortgage_payment_from_sale messages. */
#define FINISH_MORTGAGE_PAYMENT_FROM_SALE_MESSAGE_LOOP }
/** \def START_MORTGAGE_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process mortgage_payment messages. */
#define START_MORTGAGE_PAYMENT_MESSAGE_LOOP  for(mortgage_payment_message = get_first_mortgage_payment_message(); mortgage_payment_message != NULL; mortgage_payment_message = get_next_mortgage_payment_message(mortgage_payment_message)) {
/** \def FINISH_MORTGAGE_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process mortgage_payment messages. */
#define FINISH_MORTGAGE_PAYMENT_MESSAGE_LOOP }
/** \def START_MORTGAGE_WRITEOFF_MESSAGE_LOOP
 * \brief Start of loop to process mortgage_writeoff messages. */
#define START_MORTGAGE_WRITEOFF_MESSAGE_LOOP  for(mortgage_writeoff_message = get_first_mortgage_writeoff_message(); mortgage_writeoff_message != NULL; mortgage_writeoff_message = get_next_mortgage_writeoff_message(mortgage_writeoff_message)) {
/** \def FINISH_MORTGAGE_WRITEOFF_MESSAGE_LOOP
 * \brief Finish of loop to process mortgage_writeoff messages. */
#define FINISH_MORTGAGE_WRITEOFF_MESSAGE_LOOP }
/** \def START_HOUSING_TRANSACTIONS_SUMMARY_MESSAGE_LOOP
 * \brief Start of loop to process housing_transactions_summary messages. */
#define START_HOUSING_TRANSACTIONS_SUMMARY_MESSAGE_LOOP  for(housing_transactions_summary_message = get_first_housing_transactions_summary_message(); housing_transactions_summary_message != NULL; housing_transactions_summary_message = get_next_housing_transactions_summary_message(housing_transactions_summary_message)) {
/** \def FINISH_HOUSING_TRANSACTIONS_SUMMARY_MESSAGE_LOOP
 * \brief Finish of loop to process housing_transactions_summary messages. */
#define FINISH_HOUSING_TRANSACTIONS_SUMMARY_MESSAGE_LOOP }


struct FLAME_output
{
	int type; /* 0=snapshot 1=firm 2=household 3=equityfund 4=bank 5=government 6=centralbank 7=jpoffice 8=mall 9=reagency */
	int format; /* 0=XML */
	char * location;
	int period;
	int phase;
	int flag; /* Used when outputting to show it has been used */

	struct FLAME_output * next;
};
typedef struct FLAME_output FLAME_output;

/** \struct int_array
 * \brief Dynamic array to hold integers.
 *
 * Holds a pointer to an integer array and values for size and memory size.
 */
struct int_array
{
	int size;
	int total_size;

	int * array;
};

/** \struct float_array
 * \brief Dynamic array to hold floats.
 *
 * Holds a pointer to an float array and values for size and memory size.
 */
struct float_array
{
	int size;
	int total_size;

	float * array;
};

/** \struct double_array
 * \brief Dynamic array to hold doubles.
 *
 * Holds a pointer to a double array and values for size and memory size.
 */
struct double_array
{
	int size;
	int total_size;

	double * array;
};

/** \struct char_array
 * \brief Dynamic array to hold chars.
 *
 * Holds a pointer to a char array and values for size and memory size.
 */
struct char_array
{
	int size;
	int total_size;

	char * array;
};

/** \typedef struct int_array int_array
 * \brief Typedef for int_array struct.
 */
typedef struct int_array int_array;
/** \typedef struct float_array float_array
 * \brief Typedef for float_array struct.
 */
typedef struct float_array float_array;
/** \typedef struct double_array double_array
 * \brief Typedef for double_array struct.
 */
typedef struct double_array double_array;
/** \typedef struct char_array char_array
 * \brief Typedef for char_array struct.
 */
typedef struct char_array char_array;

/** \struct transaction
 * \brief A generic transaction data structure..
 *
 * A generic transaction data structure..
 */
struct transaction
{
	int quantity;	/**< Datatype memory variable quantity of type int. */
	double avg_price;	/**< Datatype memory variable avg_price of type double. */
};

/** \struct transaction_array
 * \brief Dynamic array to hold transactions
 */
struct transaction_array
{
	int size;
	int total_size;

	struct transaction * array;
};

/** \var typedef transaction transaction
 * \brief Typedef for transaction struct.
 */
typedef struct transaction transaction;
/** \var typedef transaction_array transaction_array
 * \brief Typedef for transaction_array struct.
 */
typedef struct transaction_array transaction_array;
/** \struct buyer
 * \brief Consumer data..
 *
 * Consumer data..
 */
struct buyer
{
	int id;	/**< Datatype memory variable id of type int. */
	double budget;	/**< Datatype memory variable budget of type double. */
	int recieved_quantity;	/**< Datatype memory variable recieved_quantity of type int. */
};

/** \struct buyer_array
 * \brief Dynamic array to hold buyers
 */
struct buyer_array
{
	int size;
	int total_size;

	struct buyer * array;
};

/** \var typedef buyer buyer
 * \brief Typedef for buyer struct.
 */
typedef struct buyer buyer;
/** \var typedef buyer_array buyer_array
 * \brief Typedef for buyer_array struct.
 */
typedef struct buyer_array buyer_array;
/** \struct seller
 * \brief Seller data..
 *
 * Seller data..
 */
struct seller
{
	int id;	/**< Datatype memory variable id of type int. */
	double price;	/**< Datatype memory variable price of type double. */
	int inventory;	/**< Datatype memory variable inventory of type int. */
};

/** \struct seller_array
 * \brief Dynamic array to hold sellers
 */
struct seller_array
{
	int size;
	int total_size;

	struct seller * array;
};

/** \var typedef seller seller
 * \brief Typedef for seller struct.
 */
typedef struct seller seller;
/** \var typedef seller_array seller_array
 * \brief Typedef for seller_array struct.
 */
typedef struct seller_array seller_array;
/** \struct vacancy
 * \brief Firm vacancy information..
 *
 * Firm vacancy information..
 */
struct vacancy
{
	int id;	/**< Datatype memory variable id of type int. */
	double wage;	/**< Datatype memory variable wage of type double. */
};

/** \struct vacancy_array
 * \brief Dynamic array to hold vacancys
 */
struct vacancy_array
{
	int size;
	int total_size;

	struct vacancy * array;
};

/** \var typedef vacancy vacancy
 * \brief Typedef for vacancy struct.
 */
typedef struct vacancy vacancy;
/** \var typedef vacancy_array vacancy_array
 * \brief Typedef for vacancy_array struct.
 */
typedef struct vacancy_array vacancy_array;
/** \struct employee
 * \brief Job applicant data..
 *
 * Job applicant data..
 */
struct employee
{
	int id;	/**< Datatype memory variable id of type int. */
	double wage;	/**< Datatype memory variable wage of type double. */
};

/** \struct employee_array
 * \brief Dynamic array to hold employees
 */
struct employee_array
{
	int size;
	int total_size;

	struct employee * array;
};

/** \var typedef employee employee
 * \brief Typedef for employee struct.
 */
typedef struct employee employee;
/** \var typedef employee_array employee_array
 * \brief Typedef for employee_array struct.
 */
typedef struct employee_array employee_array;
/** \struct mortgage
 * \brief Household mortgage information..
 *
 * Household mortgage information..
 */
struct mortgage
{
	int bank_id;	/**< Datatype memory variable bank_id of type int. */
	double principal;	/**< Datatype memory variable principal of type double. */
	int quarters_left;	/**< Datatype memory variable quarters_left of type int. */
	double quarterly_interest;	/**< Datatype memory variable quarterly_interest of type double. */
	double quarterly_principal;	/**< Datatype memory variable quarterly_principal of type double. */
};

/** \struct mortgage_array
 * \brief Dynamic array to hold mortgages
 */
struct mortgage_array
{
	int size;
	int total_size;

	struct mortgage * array;
};

/** \var typedef mortgage mortgage
 * \brief Typedef for mortgage struct.
 */
typedef struct mortgage mortgage;
/** \var typedef mortgage_array mortgage_array
 * \brief Typedef for mortgage_array struct.
 */
typedef struct mortgage_array mortgage_array;
/** \struct loan
 * \brief Used by firm to hold loans they owe to each bank..
 *
 * Used by firm to hold loans they owe to each bank..
 */
struct loan
{
	int bank_id;	/**< Datatype memory variable bank_id of type int. */
	double amount;	/**< Datatype memory variable amount of type double. */
};

/** \struct loan_array
 * \brief Dynamic array to hold loans
 */
struct loan_array
{
	int size;
	int total_size;

	struct loan * array;
};

/** \var typedef loan loan
 * \brief Typedef for loan struct.
 */
typedef struct loan loan;
/** \var typedef loan_array loan_array
 * \brief Typedef for loan_array struct.
 */
typedef struct loan_array loan_array;
/** \struct hbuyer
 * \brief Buyer data at housing market..
 *
 * Buyer data at housing market..
 */
struct hbuyer
{
	int buyer_id;	/**< Datatype memory variable buyer_id of type int. */
	int bank_id;	/**< Datatype memory variable bank_id of type int. */
	double liquidity;	/**< Datatype memory variable liquidity of type double. */
	double quarterly_income;	/**< Datatype memory variable quarterly_income of type double. */
	double quarterly_mortgage_paid;	/**< Datatype memory variable quarterly_mortgage_paid of type double. */
};

/** \struct hbuyer_array
 * \brief Dynamic array to hold hbuyers
 */
struct hbuyer_array
{
	int size;
	int total_size;

	struct hbuyer * array;
};

/** \var typedef hbuyer hbuyer
 * \brief Typedef for hbuyer struct.
 */
typedef struct hbuyer hbuyer;
/** \var typedef hbuyer_array hbuyer_array
 * \brief Typedef for hbuyer_array struct.
 */
typedef struct hbuyer_array hbuyer_array;
/** \struct hseller
 * \brief Seller data at housing market. Sent either by a constructor firm or an household..
 *
 * Seller data at housing market. Sent either by a constructor firm or an household..
 */
struct hseller
{
	int seller_id;	/**< Datatype memory variable seller_id of type int. */
	double price;	/**< Datatype memory variable price of type double. */
	int quantity;	/**< Datatype memory variable quantity of type int. */
};

/** \struct hseller_array
 * \brief Dynamic array to hold hsellers
 */
struct hseller_array
{
	int size;
	int total_size;

	struct hseller * array;
};

/** \var typedef hseller hseller
 * \brief Typedef for hseller struct.
 */
typedef struct hseller hseller;
/** \var typedef hseller_array hseller_array
 * \brief Typedef for hseller_array struct.
 */
typedef struct hseller_array hseller_array;
/** \struct hbank
 * \brief Mortgaging data regarding the banks at the housing market..
 *
 * Mortgaging data regarding the banks at the housing market..
 */
struct hbank
{
	int id;	/**< Datatype memory variable id of type int. */
	double equity;	/**< Datatype memory variable equity of type double. */
	double risky_assets;	/**< Datatype memory variable risky_assets of type double. */
	double amount_mortgaged;	/**< Datatype memory variable amount_mortgaged of type double. */
};

/** \struct hbank_array
 * \brief Dynamic array to hold hbanks
 */
struct hbank_array
{
	int size;
	int total_size;

	struct hbank * array;
};

/** \var typedef hbank hbank
 * \brief Typedef for hbank struct.
 */
typedef struct hbank hbank;
/** \var typedef hbank_array hbank_array
 * \brief Typedef for hbank_array struct.
 */
typedef struct hbank_array hbank_array;

/** \struct xmachine_memory_firm
 * \brief Holds memory of xmachine firm.
 */
struct xmachine_memory_firm
{
	int id;	/**< X-machine memory variable id of type int. */
	int bank_id;	/**< X-machine memory variable bank_id of type int. */
	int isconstructor;	/**< X-machine memory variable isconstructor of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	int isinsolvent;	/**< X-machine memory variable isinsolvent of type int. */
	int it_no;	/**< X-machine memory variable it_no of type int. */
	int day_of_week_to_act;	/**< X-machine memory variable day_of_week_to_act of type int. */
	double average_goods_price;	/**< X-machine memory variable average_goods_price of type double. */
	int_array employees;	/**< X-machine memory variable employees of type int_array. */
	double wage_offer;	/**< X-machine memory variable wage_offer of type double. */
	double average_wage;	/**< X-machine memory variable average_wage of type double. */
	int no_employees;	/**< X-machine memory variable no_employees of type int. */
	int vacancies;	/**< X-machine memory variable vacancies of type int. */
	int employees_needed;	/**< X-machine memory variable employees_needed of type int. */
	int day_of_month_wages_paid;	/**< X-machine memory variable day_of_month_wages_paid of type int. */
	double labour_productivity;	/**< X-machine memory variable labour_productivity of type double. */
	int production_current;	/**< X-machine memory variable production_current of type int. */
	int production_estimate;	/**< X-machine memory variable production_estimate of type int. */
	int production_plan;	/**< X-machine memory variable production_plan of type int. */
	double unit_goods_price;	/**< X-machine memory variable unit_goods_price of type double. */
	int day_of_month_production_completed;	/**< X-machine memory variable day_of_month_production_completed of type int. */
	double unit_house_price;	/**< X-machine memory variable unit_house_price of type double. */
	double labour_productivity_construction;	/**< X-machine memory variable labour_productivity_construction of type double. */
	double capital_productivity_construction;	/**< X-machine memory variable capital_productivity_construction of type double. */
	double capital_construction;	/**< X-machine memory variable capital_construction of type double. */
	double physical_capital;	/**< X-machine memory variable physical_capital of type double. */
	int projects[13];	/**< X-machine memory variable projects of type int. */
	double loans_interest_rate;	/**< X-machine memory variable loans_interest_rate of type double. */
	double debt;	/**< X-machine memory variable debt of type double. */
	int inventory;	/**< X-machine memory variable inventory of type int. */
	int sales;	/**< X-machine memory variable sales of type int. */
	double revenue;	/**< X-machine memory variable revenue of type double. */
	double total_assets;	/**< X-machine memory variable total_assets of type double. */
	double costs;	/**< X-machine memory variable costs of type double. */
	double total_interest_payments;	/**< X-machine memory variable total_interest_payments of type double. */
	double dividends_paid;	/**< X-machine memory variable dividends_paid of type double. */
	double dividends_retained;	/**< X-machine memory variable dividends_retained of type double. */
	double earnings;	/**< X-machine memory variable earnings of type double. */
	double ebit;	/**< X-machine memory variable ebit of type double. */
	double equity;	/**< X-machine memory variable equity of type double. */
	double liquidity;	/**< X-machine memory variable liquidity of type double. */
	double capital_goods;	/**< X-machine memory variable capital_goods of type double. */
	int hasloan;	/**< X-machine memory variable hasloan of type int. */
	int hasinvestment;	/**< X-machine memory variable hasinvestment of type int. */
	double liquidity_need;	/**< X-machine memory variable liquidity_need of type double. */
	loan loan_list[2];	/**< X-machine memory variable loan_list of type loan. */
	double delta_housing_price;	/**< X-machine memory variable delta_housing_price of type double. */
};

/** \struct xmachine_memory_firm_holder
 * \brief Holds struct of memory of xmachine firm.
 */
struct xmachine_memory_firm_holder
{
	/*@dependent@*/ struct xmachine_memory_firm * agent;	/**< Pointer to X-machine memory firm. */

	/*@dependent@*/ struct xmachine_memory_firm_holder * prev;	/**< Pointer to previous firm agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_firm_holder * next;	/**< Pointer to next firm agent in the list.  */
};

/** \struct xmachine_memory_firm_holder
 * \brief Holds struct of memory of xmachine firm.
 */
struct xmachine_memory_firm_state
{
	/*@dependent@*/ struct xmachine_memory_firm_holder * agents;	/**< Pointer to X-machine memory firm. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_household
 * \brief Holds memory of xmachine household.
 */
struct xmachine_memory_household
{
	int id;	/**< X-machine memory variable id of type int. */
	int bank_id;	/**< X-machine memory variable bank_id of type int. */
	int day_of_week_to_act;	/**< X-machine memory variable day_of_week_to_act of type int. */
	double weekly_consumption_budget;	/**< X-machine memory variable weekly_consumption_budget of type double. */
	double consumption_budget;	/**< X-machine memory variable consumption_budget of type double. */
	int my_employer_id;	/**< X-machine memory variable my_employer_id of type int. */
	double wage;	/**< X-machine memory variable wage of type double. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	int day_of_month_wage_recieved;	/**< X-machine memory variable day_of_month_wage_recieved of type int. */
	double mortgages_interest_rate;	/**< X-machine memory variable mortgages_interest_rate of type double. */
	double tax_rate;	/**< X-machine memory variable tax_rate of type double. */
	mortgage_array mortgages_list;	/**< X-machine memory variable mortgages_list of type mortgage_array. */
	double mortgages;	/**< X-machine memory variable mortgages of type double. */
	double housing_payment;	/**< X-machine memory variable housing_payment of type double. */
	double equity;	/**< X-machine memory variable equity of type double. */
	double housing_price;	/**< X-machine memory variable housing_price of type double. */
	int housing_units;	/**< X-machine memory variable housing_units of type int. */
	int dividends;	/**< X-machine memory variable dividends of type int. */
	double liquidity;	/**< X-machine memory variable liquidity of type double. */
	double fund_shares;	/**< X-machine memory variable fund_shares of type double. */
	int previous_wages[3];	/**< X-machine memory variable previous_wages of type int. */
	int hmarket_role;	/**< X-machine memory variable hmarket_role of type int. */
	double equity_ratio;	/**< X-machine memory variable equity_ratio of type double. */
	double minimum_equity_ratio;	/**< X-machine memory variable minimum_equity_ratio of type double. */
	double mortgage_costs[3];	/**< X-machine memory variable mortgage_costs of type double. */
};

/** \struct xmachine_memory_household_holder
 * \brief Holds struct of memory of xmachine household.
 */
struct xmachine_memory_household_holder
{
	/*@dependent@*/ struct xmachine_memory_household * agent;	/**< Pointer to X-machine memory household. */

	/*@dependent@*/ struct xmachine_memory_household_holder * prev;	/**< Pointer to previous household agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_household_holder * next;	/**< Pointer to next household agent in the list.  */
};

/** \struct xmachine_memory_household_holder
 * \brief Holds struct of memory of xmachine household.
 */
struct xmachine_memory_household_state
{
	/*@dependent@*/ struct xmachine_memory_household_holder * agents;	/**< Pointer to X-machine memory household. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_equityfund
 * \brief Holds memory of xmachine equityfund.
 */
struct xmachine_memory_equityfund
{
	int id;	/**< X-machine memory variable id of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	double share_firms;	/**< X-machine memory variable share_firms of type double. */
	double share_construction_firms;	/**< X-machine memory variable share_construction_firms of type double. */
	double share_banks;	/**< X-machine memory variable share_banks of type double. */
	double equity;	/**< X-machine memory variable equity of type double. */
	double liquidity;	/**< X-machine memory variable liquidity of type double. */
	int n_dividends;	/**< X-machine memory variable n_dividends of type int. */
	double dividends_recieved;	/**< X-machine memory variable dividends_recieved of type double. */
	double dividends_retained;	/**< X-machine memory variable dividends_retained of type double. */
	double dividends_paid;	/**< X-machine memory variable dividends_paid of type double. */
	double firm_investment;	/**< X-machine memory variable firm_investment of type double. */
};

/** \struct xmachine_memory_equityfund_holder
 * \brief Holds struct of memory of xmachine equityfund.
 */
struct xmachine_memory_equityfund_holder
{
	/*@dependent@*/ struct xmachine_memory_equityfund * agent;	/**< Pointer to X-machine memory equityfund. */

	/*@dependent@*/ struct xmachine_memory_equityfund_holder * prev;	/**< Pointer to previous equityfund agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_equityfund_holder * next;	/**< Pointer to next equityfund agent in the list.  */
};

/** \struct xmachine_memory_equityfund_holder
 * \brief Holds struct of memory of xmachine equityfund.
 */
struct xmachine_memory_equityfund_state
{
	/*@dependent@*/ struct xmachine_memory_equityfund_holder * agents;	/**< Pointer to X-machine memory equityfund. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_bank
 * \brief Holds memory of xmachine bank.
 */
struct xmachine_memory_bank
{
	int id;	/**< X-machine memory variable id of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	int day_of_week_to_act;	/**< X-machine memory variable day_of_week_to_act of type int. */
	double total_assets;	/**< X-machine memory variable total_assets of type double. */
	double loans;	/**< X-machine memory variable loans of type double. */
	double mortgages;	/**< X-machine memory variable mortgages of type double. */
	double deposits;	/**< X-machine memory variable deposits of type double. */
	double centralbank_debt;	/**< X-machine memory variable centralbank_debt of type double. */
	double equity;	/**< X-machine memory variable equity of type double. */
	double liquidity;	/**< X-machine memory variable liquidity of type double. */
	double revenues;	/**< X-machine memory variable revenues of type double. */
	double total_writeoffs;	/**< X-machine memory variable total_writeoffs of type double. */
	double interests_accrued;	/**< X-machine memory variable interests_accrued of type double. */
	double interests_paid;	/**< X-machine memory variable interests_paid of type double. */
	double dividends_paid;	/**< X-machine memory variable dividends_paid of type double. */
	double total_dividends;	/**< X-machine memory variable total_dividends of type double. */
	double retained_earnings;	/**< X-machine memory variable retained_earnings of type double. */
	double net_earnings;	/**< X-machine memory variable net_earnings of type double. */
	double total_costs;	/**< X-machine memory variable total_costs of type double. */
};

/** \struct xmachine_memory_bank_holder
 * \brief Holds struct of memory of xmachine bank.
 */
struct xmachine_memory_bank_holder
{
	/*@dependent@*/ struct xmachine_memory_bank * agent;	/**< Pointer to X-machine memory bank. */

	/*@dependent@*/ struct xmachine_memory_bank_holder * prev;	/**< Pointer to previous bank agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_bank_holder * next;	/**< Pointer to next bank agent in the list.  */
};

/** \struct xmachine_memory_bank_holder
 * \brief Holds struct of memory of xmachine bank.
 */
struct xmachine_memory_bank_state
{
	/*@dependent@*/ struct xmachine_memory_bank_holder * agents;	/**< Pointer to X-machine memory bank. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_government
 * \brief Holds memory of xmachine government.
 */
struct xmachine_memory_government
{
	int id;	/**< X-machine memory variable id of type int. */
	double average_wage;	/**< X-machine memory variable average_wage of type double. */
	double unemployment_rate;	/**< X-machine memory variable unemployment_rate of type double. */
	int population_size;	/**< X-machine memory variable population_size of type int. */
	double debt;	/**< X-machine memory variable debt of type double. */
	double equity;	/**< X-machine memory variable equity of type double. */
	double liquidity;	/**< X-machine memory variable liquidity of type double. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	double gov_tax_rate;	/**< X-machine memory variable gov_tax_rate of type double. */
	double labour_tax_income;	/**< X-machine memory variable labour_tax_income of type double. */
	double capital_tax_income;	/**< X-machine memory variable capital_tax_income of type double. */
	double gov_general_benefit_rate;	/**< X-machine memory variable gov_general_benefit_rate of type double. */
	double gov_unemployment_rate;	/**< X-machine memory variable gov_unemployment_rate of type double. */
	double general_benefits;	/**< X-machine memory variable general_benefits of type double. */
	double unemployment_benefits;	/**< X-machine memory variable unemployment_benefits of type double. */
	double earnings;	/**< X-machine memory variable earnings of type double. */
	double expenditures;	/**< X-machine memory variable expenditures of type double. */
};

/** \struct xmachine_memory_government_holder
 * \brief Holds struct of memory of xmachine government.
 */
struct xmachine_memory_government_holder
{
	/*@dependent@*/ struct xmachine_memory_government * agent;	/**< Pointer to X-machine memory government. */

	/*@dependent@*/ struct xmachine_memory_government_holder * prev;	/**< Pointer to previous government agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_government_holder * next;	/**< Pointer to next government agent in the list.  */
};

/** \struct xmachine_memory_government_holder
 * \brief Holds struct of memory of xmachine government.
 */
struct xmachine_memory_government_state
{
	/*@dependent@*/ struct xmachine_memory_government_holder * agents;	/**< Pointer to X-machine memory government. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_centralbank
 * \brief Holds memory of xmachine centralbank.
 */
struct xmachine_memory_centralbank
{
	int id;	/**< X-machine memory variable id of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	double unemployment_rate;	/**< X-machine memory variable unemployment_rate of type double. */
	double consumption_goods_prices[12];	/**< X-machine memory variable consumption_goods_prices of type double. */
	int day_of_week_to_act;	/**< X-machine memory variable day_of_week_to_act of type int. */
	transaction goods;	/**< X-machine memory variable goods of type transaction. */
	double weekly_price_averages[4];	/**< X-machine memory variable weekly_price_averages of type double. */
	double interest_rate;	/**< X-machine memory variable interest_rate of type double. */
	double liquidity;	/**< X-machine memory variable liquidity of type double. */
	double loans_banks;	/**< X-machine memory variable loans_banks of type double. */
	double loans_government;	/**< X-machine memory variable loans_government of type double. */
	double fiat_money;	/**< X-machine memory variable fiat_money of type double. */
	double equity;	/**< X-machine memory variable equity of type double. */
	double liquidity_banks;	/**< X-machine memory variable liquidity_banks of type double. */
	double liquidity_government;	/**< X-machine memory variable liquidity_government of type double. */
	double total_assets;	/**< X-machine memory variable total_assets of type double. */
	double total_writeoffs;	/**< X-machine memory variable total_writeoffs of type double. */
	double interests_accrued;	/**< X-machine memory variable interests_accrued of type double. */
	double revenues;	/**< X-machine memory variable revenues of type double. */
	double net_earnings;	/**< X-machine memory variable net_earnings of type double. */
	double total_costs;	/**< X-machine memory variable total_costs of type double. */
	transaction houses;	/**< X-machine memory variable houses of type transaction. */
};

/** \struct xmachine_memory_centralbank_holder
 * \brief Holds struct of memory of xmachine centralbank.
 */
struct xmachine_memory_centralbank_holder
{
	/*@dependent@*/ struct xmachine_memory_centralbank * agent;	/**< Pointer to X-machine memory centralbank. */

	/*@dependent@*/ struct xmachine_memory_centralbank_holder * prev;	/**< Pointer to previous centralbank agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_centralbank_holder * next;	/**< Pointer to next centralbank agent in the list.  */
};

/** \struct xmachine_memory_centralbank_holder
 * \brief Holds struct of memory of xmachine centralbank.
 */
struct xmachine_memory_centralbank_state
{
	/*@dependent@*/ struct xmachine_memory_centralbank_holder * agents;	/**< Pointer to X-machine memory centralbank. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_jpoffice
 * \brief Holds memory of xmachine jpoffice.
 */
struct xmachine_memory_jpoffice
{
	int id;	/**< X-machine memory variable id of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
};

/** \struct xmachine_memory_jpoffice_holder
 * \brief Holds struct of memory of xmachine jpoffice.
 */
struct xmachine_memory_jpoffice_holder
{
	/*@dependent@*/ struct xmachine_memory_jpoffice * agent;	/**< Pointer to X-machine memory jpoffice. */

	/*@dependent@*/ struct xmachine_memory_jpoffice_holder * prev;	/**< Pointer to previous jpoffice agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_jpoffice_holder * next;	/**< Pointer to next jpoffice agent in the list.  */
};

/** \struct xmachine_memory_jpoffice_holder
 * \brief Holds struct of memory of xmachine jpoffice.
 */
struct xmachine_memory_jpoffice_state
{
	/*@dependent@*/ struct xmachine_memory_jpoffice_holder * agents;	/**< Pointer to X-machine memory jpoffice. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_mall
 * \brief Holds memory of xmachine mall.
 */
struct xmachine_memory_mall
{
	int id;	/**< X-machine memory variable id of type int. */
	int day_of_week_to_act;	/**< X-machine memory variable day_of_week_to_act of type int. */
	transaction goods_transactions;	/**< X-machine memory variable goods_transactions of type transaction. */
};

/** \struct xmachine_memory_mall_holder
 * \brief Holds struct of memory of xmachine mall.
 */
struct xmachine_memory_mall_holder
{
	/*@dependent@*/ struct xmachine_memory_mall * agent;	/**< Pointer to X-machine memory mall. */

	/*@dependent@*/ struct xmachine_memory_mall_holder * prev;	/**< Pointer to previous mall agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_mall_holder * next;	/**< Pointer to next mall agent in the list.  */
};

/** \struct xmachine_memory_mall_holder
 * \brief Holds struct of memory of xmachine mall.
 */
struct xmachine_memory_mall_state
{
	/*@dependent@*/ struct xmachine_memory_mall_holder * agents;	/**< Pointer to X-machine memory mall. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_reagency
 * \brief Holds memory of xmachine reagency.
 */
struct xmachine_memory_reagency
{
	int id;	/**< X-machine memory variable id of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	double mortgages_interest_rate;	/**< X-machine memory variable mortgages_interest_rate of type double. */
	transaction housing_transactions;	/**< X-machine memory variable housing_transactions of type transaction. */
};

/** \struct xmachine_memory_reagency_holder
 * \brief Holds struct of memory of xmachine reagency.
 */
struct xmachine_memory_reagency_holder
{
	/*@dependent@*/ struct xmachine_memory_reagency * agent;	/**< Pointer to X-machine memory reagency. */

	/*@dependent@*/ struct xmachine_memory_reagency_holder * prev;	/**< Pointer to previous reagency agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_reagency_holder * next;	/**< Pointer to next reagency agent in the list.  */
};

/** \struct xmachine_memory_reagency_holder
 * \brief Holds struct of memory of xmachine reagency.
 */
struct xmachine_memory_reagency_state
{
	/*@dependent@*/ struct xmachine_memory_reagency_holder * agents;	/**< Pointer to X-machine memory reagency. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine
 * \brief Holds xmachines.
 */
struct xmachine
{
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_firm * xmachine_firm;	/**< Pointer to X-machine memory of type firm.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_household * xmachine_household;	/**< Pointer to X-machine memory of type household.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_equityfund * xmachine_equityfund;	/**< Pointer to X-machine memory of type equityfund.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_bank * xmachine_bank;	/**< Pointer to X-machine memory of type bank.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_government * xmachine_government;	/**< Pointer to X-machine memory of type government.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_centralbank * xmachine_centralbank;	/**< Pointer to X-machine memory of type centralbank.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_jpoffice * xmachine_jpoffice;	/**< Pointer to X-machine memory of type jpoffice.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_mall * xmachine_mall;	/**< Pointer to X-machine memory of type mall.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_reagency * xmachine_reagency;	/**< Pointer to X-machine memory of type reagency.  */
};

/** \var void* FLAME_m_firm_bank_update_deposit_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_firm_bank_update_deposit_composite_params;

/** \struct m_firm_bank_update_deposit
 * \brief Holds message of type firm_bank_update_deposit_message.
 */
struct m_firm_bank_update_deposit
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_household_bank_update_deposit_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_household_bank_update_deposit_composite_params;

/** \struct m_household_bank_update_deposit
 * \brief Holds message of type household_bank_update_deposit_message.
 */
struct m_household_bank_update_deposit
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_interest_rate_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_interest_rate_composite_params;

/** \struct m_interest_rate
 * \brief Holds message of type interest_rate_message.
 */
struct m_interest_rate
{
	double rate;	/**< Message memory variable rate of type double. */
};

/** \var void* FLAME_m_buy_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_buy_composite_params;

/** \struct m_buy
 * \brief Holds message of type buy_message.
 */
struct m_buy
{
	int id;	/**< Message memory variable id of type int. */
	double budget;	/**< Message memory variable budget of type double. */
};

/** \var void* FLAME_m_bought_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_bought_composite_params;

/** \struct m_bought
 * \brief Holds message of type bought_message.
 */
struct m_bought
{
	int id;	/**< Message memory variable id of type int. */
	double money_left;	/**< Message memory variable money_left of type double. */
	int recieved_quantity;	/**< Message memory variable recieved_quantity of type int. */
};

/** \var void* FLAME_m_sell_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_sell_composite_params;

/** \struct m_sell
 * \brief Holds message of type sell_message.
 */
struct m_sell
{
	int id;	/**< Message memory variable id of type int. */
	double price;	/**< Message memory variable price of type double. */
	int inventory;	/**< Message memory variable inventory of type int. */
};

/** \var void* FLAME_m_sold_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_sold_composite_params;

/** \struct m_sold
 * \brief Holds message of type sold_message.
 */
struct m_sold
{
	int id;	/**< Message memory variable id of type int. */
	int unsold_quantities;	/**< Message memory variable unsold_quantities of type int. */
};

/** \var void* FLAME_m_goods_transactions_summary_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_goods_transactions_summary_composite_params;

/** \struct m_goods_transactions_summary
 * \brief Holds message of type goods_transactions_summary_message.
 */
struct m_goods_transactions_summary
{
	int quantity;	/**< Message memory variable quantity of type int. */
	double avg_price;	/**< Message memory variable avg_price of type double. */
};

/** \var void* FLAME_m_fired_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_fired_composite_params;

/** \struct m_fired
 * \brief Holds message of type fired_message.
 */
struct m_fired
{
	int employee_id;	/**< Message memory variable employee_id of type int. */
};

/** \var void* FLAME_m_vacancy_stage1_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_vacancy_stage1_composite_params;

/** \struct m_vacancy_stage1
 * \brief Holds message of type vacancy_stage1_message.
 */
struct m_vacancy_stage1
{
	int employer_id;	/**< Message memory variable employer_id of type int. */
	double wage;	/**< Message memory variable wage of type double. */
};

/** \var void* FLAME_m_job_application_stage2_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_job_application_stage2_composite_params;

/** \struct m_job_application_stage2
 * \brief Holds message of type job_application_stage2_message.
 */
struct m_job_application_stage2
{
	int employee_id;	/**< Message memory variable employee_id of type int. */
};

/** \var void* FLAME_m_job_application_stage1_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_job_application_stage1_composite_params;

/** \struct m_job_application_stage1
 * \brief Holds message of type job_application_stage1_message.
 */
struct m_job_application_stage1
{
	int employee_id;	/**< Message memory variable employee_id of type int. */
	double wage;	/**< Message memory variable wage of type double. */
};

/** \var void* FLAME_m_job_match_stage1_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_job_match_stage1_composite_params;

/** \struct m_job_match_stage1
 * \brief Holds message of type job_match_stage1_message.
 */
struct m_job_match_stage1
{
	int employer_id;	/**< Message memory variable employer_id of type int. */
	int employee_id;	/**< Message memory variable employee_id of type int. */
	double wage;	/**< Message memory variable wage of type double. */
};

/** \var void* FLAME_m_job_change_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_job_change_composite_params;

/** \struct m_job_change
 * \brief Holds message of type job_change_message.
 */
struct m_job_change
{
	int employer_id;	/**< Message memory variable employer_id of type int. */
	int employee_id;	/**< Message memory variable employee_id of type int. */
};

/** \var void* FLAME_m_vacancy_stage2_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_vacancy_stage2_composite_params;

/** \struct m_vacancy_stage2
 * \brief Holds message of type vacancy_stage2_message.
 */
struct m_vacancy_stage2
{
	int employer_id;	/**< Message memory variable employer_id of type int. */
	double wage;	/**< Message memory variable wage of type double. */
};

/** \var void* FLAME_m_job_match_stage2_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_job_match_stage2_composite_params;

/** \struct m_job_match_stage2
 * \brief Holds message of type job_match_stage2_message.
 */
struct m_job_match_stage2
{
	int employer_id;	/**< Message memory variable employer_id of type int. */
	int employee_id;	/**< Message memory variable employee_id of type int. */
	double wage;	/**< Message memory variable wage of type double. */
};

/** \var void* FLAME_m_employment_status_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_employment_status_composite_params;

/** \struct m_employment_status
 * \brief Holds message of type employment_status_message.
 */
struct m_employment_status
{
	int employer_id;	/**< Message memory variable employer_id of type int. */
	double wage;	/**< Message memory variable wage of type double. */
	int ndividends;	/**< Message memory variable ndividends of type int. */
};

/** \var void* FLAME_m_loan_request_1_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_loan_request_1_composite_params;

/** \struct m_loan_request_1
 * \brief Holds message of type loan_request_1_message.
 */
struct m_loan_request_1
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_loan_request_2_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_loan_request_2_composite_params;

/** \struct m_loan_request_2
 * \brief Holds message of type loan_request_2_message.
 */
struct m_loan_request_2
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_loan_acknowledge_1_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_loan_acknowledge_1_composite_params;

/** \struct m_loan_acknowledge_1
 * \brief Holds message of type loan_acknowledge_1_message.
 */
struct m_loan_acknowledge_1
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_loan_acknowledge_2_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_loan_acknowledge_2_composite_params;

/** \struct m_loan_acknowledge_2
 * \brief Holds message of type loan_acknowledge_2_message.
 */
struct m_loan_acknowledge_2
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_debt_request_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_debt_request_composite_params;

/** \struct m_debt_request
 * \brief Holds message of type debt_request_message.
 */
struct m_debt_request
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_debt_ack_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_debt_ack_composite_params;

/** \struct m_debt_ack
 * \brief Holds message of type debt_ack_message.
 */
struct m_debt_ack
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_household_share_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_household_share_composite_params;

/** \struct m_household_share
 * \brief Holds message of type household_share_message.
 */
struct m_household_share
{
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_capital_tax_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_capital_tax_composite_params;

/** \struct m_capital_tax
 * \brief Holds message of type capital_tax_message.
 */
struct m_capital_tax
{
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_labour_tax_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_labour_tax_composite_params;

/** \struct m_labour_tax
 * \brief Holds message of type labour_tax_message.
 */
struct m_labour_tax
{
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_unemployment_benefit_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_unemployment_benefit_composite_params;

/** \struct m_unemployment_benefit
 * \brief Holds message of type unemployment_benefit_message.
 */
struct m_unemployment_benefit
{
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_general_benefit_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_general_benefit_composite_params;

/** \struct m_general_benefit
 * \brief Holds message of type general_benefit_message.
 */
struct m_general_benefit
{
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_tax_rate_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_tax_rate_composite_params;

/** \struct m_tax_rate
 * \brief Holds message of type tax_rate_message.
 */
struct m_tax_rate
{
	double value;	/**< Message memory variable value of type double. */
};

/** \var void* FLAME_m_fund_request_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_fund_request_composite_params;

/** \struct m_fund_request
 * \brief Holds message of type fund_request_message.
 */
struct m_fund_request
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_fund_request_ack_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_fund_request_ack_composite_params;

/** \struct m_fund_request_ack
 * \brief Holds message of type fund_request_ack_message.
 */
struct m_fund_request_ack
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_new_entrant_loan_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_new_entrant_loan_composite_params;

/** \struct m_new_entrant_loan
 * \brief Holds message of type new_entrant_loan_message.
 */
struct m_new_entrant_loan
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_interest_on_loan_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_interest_on_loan_composite_params;

/** \struct m_interest_on_loan
 * \brief Holds message of type interest_on_loan_message.
 */
struct m_interest_on_loan
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_loan_writeoff_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_loan_writeoff_composite_params;

/** \struct m_loan_writeoff
 * \brief Holds message of type loan_writeoff_message.
 */
struct m_loan_writeoff
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_firm_net_profit_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_firm_net_profit_composite_params;

/** \struct m_firm_net_profit
 * \brief Holds message of type firm_net_profit_message.
 */
struct m_firm_net_profit
{
	int id;	/**< Message memory variable id of type int. */
	int isconstructor;	/**< Message memory variable isconstructor of type int. */
	double net_income;	/**< Message memory variable net_income of type double. */
};

/** \var void* FLAME_m_bank_net_profit_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_bank_net_profit_composite_params;

/** \struct m_bank_net_profit
 * \brief Holds message of type bank_net_profit_message.
 */
struct m_bank_net_profit
{
	int id;	/**< Message memory variable id of type int. */
	double net_income;	/**< Message memory variable net_income of type double. */
};

/** \var void* FLAME_m_housing_price_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_housing_price_composite_params;

/** \struct m_housing_price
 * \brief Holds message of type housing_price_message.
 */
struct m_housing_price
{
	double price;	/**< Message memory variable price of type double. */
};

/** \var void* FLAME_m_buy_housing_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_buy_housing_composite_params;

/** \struct m_buy_housing
 * \brief Holds message of type buy_housing_message.
 */
struct m_buy_housing
{
	int buyer_id;	/**< Message memory variable buyer_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double liquidity;	/**< Message memory variable liquidity of type double. */
	double quarterly_income;	/**< Message memory variable quarterly_income of type double. */
	double quarterly_mortgage_paid;	/**< Message memory variable quarterly_mortgage_paid of type double. */
};

/** \var void* FLAME_m_sell_housing_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_sell_housing_composite_params;

/** \struct m_sell_housing
 * \brief Holds message of type sell_housing_message.
 */
struct m_sell_housing
{
	int seller_id;	/**< Message memory variable seller_id of type int. */
	double price;	/**< Message memory variable price of type double. */
	int quantity;	/**< Message memory variable quantity of type int. */
};

/** \var void* FLAME_m_bought_housing_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_bought_housing_composite_params;

/** \struct m_bought_housing
 * \brief Holds message of type bought_housing_message.
 */
struct m_bought_housing
{
	int buyer_id;	/**< Message memory variable buyer_id of type int. */
	double liquidity_spent;	/**< Message memory variable liquidity_spent of type double. */
	double mortgage_used;	/**< Message memory variable mortgage_used of type double. */
	double annuity;	/**< Message memory variable annuity of type double. */
};

/** \var void* FLAME_m_sold_housing_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_sold_housing_composite_params;

/** \struct m_sold_housing
 * \brief Holds message of type sold_housing_message.
 */
struct m_sold_housing
{
	int seller_id;	/**< Message memory variable seller_id of type int. */
	int quantity_sold;	/**< Message memory variable quantity_sold of type int. */
	double price_sold;	/**< Message memory variable price_sold of type double. */
};

/** \var void* FLAME_m_mortgaging_capacity_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_mortgaging_capacity_composite_params;

/** \struct m_mortgaging_capacity
 * \brief Holds message of type mortgaging_capacity_message.
 */
struct m_mortgaging_capacity
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double equity;	/**< Message memory variable equity of type double. */
	double risky_assets;	/**< Message memory variable risky_assets of type double. */
};

/** \var void* FLAME_m_mortgage_requests_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_mortgage_requests_composite_params;

/** \struct m_mortgage_requests
 * \brief Holds message of type mortgage_requests_message.
 */
struct m_mortgage_requests
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_mortgage_payment_from_sale_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_mortgage_payment_from_sale_composite_params;

/** \struct m_mortgage_payment_from_sale
 * \brief Holds message of type mortgage_payment_from_sale_message.
 */
struct m_mortgage_payment_from_sale
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_mortgage_payment_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_mortgage_payment_composite_params;

/** \struct m_mortgage_payment
 * \brief Holds message of type mortgage_payment_message.
 */
struct m_mortgage_payment
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double interest;	/**< Message memory variable interest of type double. */
	double principal;	/**< Message memory variable principal of type double. */
};

/** \var void* FLAME_m_mortgage_writeoff_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_mortgage_writeoff_composite_params;

/** \struct m_mortgage_writeoff
 * \brief Holds message of type mortgage_writeoff_message.
 */
struct m_mortgage_writeoff
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double amount;	/**< Message memory variable amount of type double. */
};

/** \var void* FLAME_m_housing_transactions_summary_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_housing_transactions_summary_composite_params;

/** \struct m_housing_transactions_summary
 * \brief Holds message of type housing_transactions_summary_message.
 */
struct m_housing_transactions_summary
{
	int quantity;	/**< Message memory variable quantity of type int. */
	double avg_price;	/**< Message memory variable avg_price of type double. */
};

/** \typedef struct xmachine xmachine
 * \brief Typedef for xmachine struct.
 */
typedef struct xmachine xmachine;
/** \var typedef xmachine_memory_firm xmachine_memory_firm
 * \brief Typedef for xmachine_memory_firm struct.
 */
typedef struct xmachine_memory_firm xmachine_memory_firm;
/** \var typedef xmachine_memory_firm xmachine_memory_firm
 * \brief Typedef for xmachine_memory_firm struct.
 */
typedef struct xmachine_memory_firm_holder xmachine_memory_firm_holder;
/** \var typedef xmachine_memory_firm xmachine_memory_firm
 * \brief Typedef for xmachine_memory_firm struct.
 */
typedef struct xmachine_memory_firm_state xmachine_memory_firm_state;
/** \var typedef xmachine_memory_household xmachine_memory_household
 * \brief Typedef for xmachine_memory_household struct.
 */
typedef struct xmachine_memory_household xmachine_memory_household;
/** \var typedef xmachine_memory_household xmachine_memory_household
 * \brief Typedef for xmachine_memory_household struct.
 */
typedef struct xmachine_memory_household_holder xmachine_memory_household_holder;
/** \var typedef xmachine_memory_household xmachine_memory_household
 * \brief Typedef for xmachine_memory_household struct.
 */
typedef struct xmachine_memory_household_state xmachine_memory_household_state;
/** \var typedef xmachine_memory_equityfund xmachine_memory_equityfund
 * \brief Typedef for xmachine_memory_equityfund struct.
 */
typedef struct xmachine_memory_equityfund xmachine_memory_equityfund;
/** \var typedef xmachine_memory_equityfund xmachine_memory_equityfund
 * \brief Typedef for xmachine_memory_equityfund struct.
 */
typedef struct xmachine_memory_equityfund_holder xmachine_memory_equityfund_holder;
/** \var typedef xmachine_memory_equityfund xmachine_memory_equityfund
 * \brief Typedef for xmachine_memory_equityfund struct.
 */
typedef struct xmachine_memory_equityfund_state xmachine_memory_equityfund_state;
/** \var typedef xmachine_memory_bank xmachine_memory_bank
 * \brief Typedef for xmachine_memory_bank struct.
 */
typedef struct xmachine_memory_bank xmachine_memory_bank;
/** \var typedef xmachine_memory_bank xmachine_memory_bank
 * \brief Typedef for xmachine_memory_bank struct.
 */
typedef struct xmachine_memory_bank_holder xmachine_memory_bank_holder;
/** \var typedef xmachine_memory_bank xmachine_memory_bank
 * \brief Typedef for xmachine_memory_bank struct.
 */
typedef struct xmachine_memory_bank_state xmachine_memory_bank_state;
/** \var typedef xmachine_memory_government xmachine_memory_government
 * \brief Typedef for xmachine_memory_government struct.
 */
typedef struct xmachine_memory_government xmachine_memory_government;
/** \var typedef xmachine_memory_government xmachine_memory_government
 * \brief Typedef for xmachine_memory_government struct.
 */
typedef struct xmachine_memory_government_holder xmachine_memory_government_holder;
/** \var typedef xmachine_memory_government xmachine_memory_government
 * \brief Typedef for xmachine_memory_government struct.
 */
typedef struct xmachine_memory_government_state xmachine_memory_government_state;
/** \var typedef xmachine_memory_centralbank xmachine_memory_centralbank
 * \brief Typedef for xmachine_memory_centralbank struct.
 */
typedef struct xmachine_memory_centralbank xmachine_memory_centralbank;
/** \var typedef xmachine_memory_centralbank xmachine_memory_centralbank
 * \brief Typedef for xmachine_memory_centralbank struct.
 */
typedef struct xmachine_memory_centralbank_holder xmachine_memory_centralbank_holder;
/** \var typedef xmachine_memory_centralbank xmachine_memory_centralbank
 * \brief Typedef for xmachine_memory_centralbank struct.
 */
typedef struct xmachine_memory_centralbank_state xmachine_memory_centralbank_state;
/** \var typedef xmachine_memory_jpoffice xmachine_memory_jpoffice
 * \brief Typedef for xmachine_memory_jpoffice struct.
 */
typedef struct xmachine_memory_jpoffice xmachine_memory_jpoffice;
/** \var typedef xmachine_memory_jpoffice xmachine_memory_jpoffice
 * \brief Typedef for xmachine_memory_jpoffice struct.
 */
typedef struct xmachine_memory_jpoffice_holder xmachine_memory_jpoffice_holder;
/** \var typedef xmachine_memory_jpoffice xmachine_memory_jpoffice
 * \brief Typedef for xmachine_memory_jpoffice struct.
 */
typedef struct xmachine_memory_jpoffice_state xmachine_memory_jpoffice_state;
/** \var typedef xmachine_memory_mall xmachine_memory_mall
 * \brief Typedef for xmachine_memory_mall struct.
 */
typedef struct xmachine_memory_mall xmachine_memory_mall;
/** \var typedef xmachine_memory_mall xmachine_memory_mall
 * \brief Typedef for xmachine_memory_mall struct.
 */
typedef struct xmachine_memory_mall_holder xmachine_memory_mall_holder;
/** \var typedef xmachine_memory_mall xmachine_memory_mall
 * \brief Typedef for xmachine_memory_mall struct.
 */
typedef struct xmachine_memory_mall_state xmachine_memory_mall_state;
/** \var typedef xmachine_memory_reagency xmachine_memory_reagency
 * \brief Typedef for xmachine_memory_reagency struct.
 */
typedef struct xmachine_memory_reagency xmachine_memory_reagency;
/** \var typedef xmachine_memory_reagency xmachine_memory_reagency
 * \brief Typedef for xmachine_memory_reagency struct.
 */
typedef struct xmachine_memory_reagency_holder xmachine_memory_reagency_holder;
/** \var typedef xmachine_memory_reagency xmachine_memory_reagency
 * \brief Typedef for xmachine_memory_reagency struct.
 */
typedef struct xmachine_memory_reagency_state xmachine_memory_reagency_state;
/** \typedef m_firm_bank_update_deposit m_firm_bank_update_deposit
 * \brief Typedef for m_firm_bank_update_deposit struct.
 */
typedef struct m_firm_bank_update_deposit m_firm_bank_update_deposit;

/** \typedef m_household_bank_update_deposit m_household_bank_update_deposit
 * \brief Typedef for m_household_bank_update_deposit struct.
 */
typedef struct m_household_bank_update_deposit m_household_bank_update_deposit;

/** \typedef m_interest_rate m_interest_rate
 * \brief Typedef for m_interest_rate struct.
 */
typedef struct m_interest_rate m_interest_rate;

/** \typedef m_buy m_buy
 * \brief Typedef for m_buy struct.
 */
typedef struct m_buy m_buy;

/** \typedef m_bought m_bought
 * \brief Typedef for m_bought struct.
 */
typedef struct m_bought m_bought;

/** \typedef m_sell m_sell
 * \brief Typedef for m_sell struct.
 */
typedef struct m_sell m_sell;

/** \typedef m_sold m_sold
 * \brief Typedef for m_sold struct.
 */
typedef struct m_sold m_sold;

/** \typedef m_goods_transactions_summary m_goods_transactions_summary
 * \brief Typedef for m_goods_transactions_summary struct.
 */
typedef struct m_goods_transactions_summary m_goods_transactions_summary;

/** \typedef m_fired m_fired
 * \brief Typedef for m_fired struct.
 */
typedef struct m_fired m_fired;

/** \typedef m_vacancy_stage1 m_vacancy_stage1
 * \brief Typedef for m_vacancy_stage1 struct.
 */
typedef struct m_vacancy_stage1 m_vacancy_stage1;

/** \typedef m_job_application_stage2 m_job_application_stage2
 * \brief Typedef for m_job_application_stage2 struct.
 */
typedef struct m_job_application_stage2 m_job_application_stage2;

/** \typedef m_job_application_stage1 m_job_application_stage1
 * \brief Typedef for m_job_application_stage1 struct.
 */
typedef struct m_job_application_stage1 m_job_application_stage1;

/** \typedef m_job_match_stage1 m_job_match_stage1
 * \brief Typedef for m_job_match_stage1 struct.
 */
typedef struct m_job_match_stage1 m_job_match_stage1;

/** \typedef m_job_change m_job_change
 * \brief Typedef for m_job_change struct.
 */
typedef struct m_job_change m_job_change;

/** \typedef m_vacancy_stage2 m_vacancy_stage2
 * \brief Typedef for m_vacancy_stage2 struct.
 */
typedef struct m_vacancy_stage2 m_vacancy_stage2;

/** \typedef m_job_match_stage2 m_job_match_stage2
 * \brief Typedef for m_job_match_stage2 struct.
 */
typedef struct m_job_match_stage2 m_job_match_stage2;

/** \typedef m_employment_status m_employment_status
 * \brief Typedef for m_employment_status struct.
 */
typedef struct m_employment_status m_employment_status;

/** \typedef m_loan_request_1 m_loan_request_1
 * \brief Typedef for m_loan_request_1 struct.
 */
typedef struct m_loan_request_1 m_loan_request_1;

/** \typedef m_loan_request_2 m_loan_request_2
 * \brief Typedef for m_loan_request_2 struct.
 */
typedef struct m_loan_request_2 m_loan_request_2;

/** \typedef m_loan_acknowledge_1 m_loan_acknowledge_1
 * \brief Typedef for m_loan_acknowledge_1 struct.
 */
typedef struct m_loan_acknowledge_1 m_loan_acknowledge_1;

/** \typedef m_loan_acknowledge_2 m_loan_acknowledge_2
 * \brief Typedef for m_loan_acknowledge_2 struct.
 */
typedef struct m_loan_acknowledge_2 m_loan_acknowledge_2;

/** \typedef m_debt_request m_debt_request
 * \brief Typedef for m_debt_request struct.
 */
typedef struct m_debt_request m_debt_request;

/** \typedef m_debt_ack m_debt_ack
 * \brief Typedef for m_debt_ack struct.
 */
typedef struct m_debt_ack m_debt_ack;

/** \typedef m_household_share m_household_share
 * \brief Typedef for m_household_share struct.
 */
typedef struct m_household_share m_household_share;

/** \typedef m_capital_tax m_capital_tax
 * \brief Typedef for m_capital_tax struct.
 */
typedef struct m_capital_tax m_capital_tax;

/** \typedef m_labour_tax m_labour_tax
 * \brief Typedef for m_labour_tax struct.
 */
typedef struct m_labour_tax m_labour_tax;

/** \typedef m_unemployment_benefit m_unemployment_benefit
 * \brief Typedef for m_unemployment_benefit struct.
 */
typedef struct m_unemployment_benefit m_unemployment_benefit;

/** \typedef m_general_benefit m_general_benefit
 * \brief Typedef for m_general_benefit struct.
 */
typedef struct m_general_benefit m_general_benefit;

/** \typedef m_tax_rate m_tax_rate
 * \brief Typedef for m_tax_rate struct.
 */
typedef struct m_tax_rate m_tax_rate;

/** \typedef m_fund_request m_fund_request
 * \brief Typedef for m_fund_request struct.
 */
typedef struct m_fund_request m_fund_request;

/** \typedef m_fund_request_ack m_fund_request_ack
 * \brief Typedef for m_fund_request_ack struct.
 */
typedef struct m_fund_request_ack m_fund_request_ack;

/** \typedef m_new_entrant_loan m_new_entrant_loan
 * \brief Typedef for m_new_entrant_loan struct.
 */
typedef struct m_new_entrant_loan m_new_entrant_loan;

/** \typedef m_interest_on_loan m_interest_on_loan
 * \brief Typedef for m_interest_on_loan struct.
 */
typedef struct m_interest_on_loan m_interest_on_loan;

/** \typedef m_loan_writeoff m_loan_writeoff
 * \brief Typedef for m_loan_writeoff struct.
 */
typedef struct m_loan_writeoff m_loan_writeoff;

/** \typedef m_firm_net_profit m_firm_net_profit
 * \brief Typedef for m_firm_net_profit struct.
 */
typedef struct m_firm_net_profit m_firm_net_profit;

/** \typedef m_bank_net_profit m_bank_net_profit
 * \brief Typedef for m_bank_net_profit struct.
 */
typedef struct m_bank_net_profit m_bank_net_profit;

/** \typedef m_housing_price m_housing_price
 * \brief Typedef for m_housing_price struct.
 */
typedef struct m_housing_price m_housing_price;

/** \typedef m_buy_housing m_buy_housing
 * \brief Typedef for m_buy_housing struct.
 */
typedef struct m_buy_housing m_buy_housing;

/** \typedef m_sell_housing m_sell_housing
 * \brief Typedef for m_sell_housing struct.
 */
typedef struct m_sell_housing m_sell_housing;

/** \typedef m_bought_housing m_bought_housing
 * \brief Typedef for m_bought_housing struct.
 */
typedef struct m_bought_housing m_bought_housing;

/** \typedef m_sold_housing m_sold_housing
 * \brief Typedef for m_sold_housing struct.
 */
typedef struct m_sold_housing m_sold_housing;

/** \typedef m_mortgaging_capacity m_mortgaging_capacity
 * \brief Typedef for m_mortgaging_capacity struct.
 */
typedef struct m_mortgaging_capacity m_mortgaging_capacity;

/** \typedef m_mortgage_requests m_mortgage_requests
 * \brief Typedef for m_mortgage_requests struct.
 */
typedef struct m_mortgage_requests m_mortgage_requests;

/** \typedef m_mortgage_payment_from_sale m_mortgage_payment_from_sale
 * \brief Typedef for m_mortgage_payment_from_sale struct.
 */
typedef struct m_mortgage_payment_from_sale m_mortgage_payment_from_sale;

/** \typedef m_mortgage_payment m_mortgage_payment
 * \brief Typedef for m_mortgage_payment struct.
 */
typedef struct m_mortgage_payment m_mortgage_payment;

/** \typedef m_mortgage_writeoff m_mortgage_writeoff
 * \brief Typedef for m_mortgage_writeoff struct.
 */
typedef struct m_mortgage_writeoff m_mortgage_writeoff;

/** \typedef m_housing_transactions_summary m_housing_transactions_summary
 * \brief Typedef for m_housing_transactions_summary struct.
 */
typedef struct m_housing_transactions_summary m_housing_transactions_summary;


/** \struct location
 * \brief Holds location for calculating space partitioning .
 */
struct location
{
	double point;		/**< Point on an axis. */

	struct location * next;	/**< Pointer to next location on the list. */
};

/** \struct node_information
 * \brief Holds node information .
 */
struct node_information
{
	int node_id;	/**< Node ID. */
	double partition_data[6];	/**< Defines bounding box. */
	int agents_in_halo;	/**< Number of agents in the halo region. */
	int agent_total;	/**< Total number of agents on the node. */
	struct xmachine * agents;	/**< Pointer to list of X-machines. */
	struct m_firm_bank_update_deposit * firm_bank_update_deposit_messages;	/**< Pointer to firm_bank_update_deposit message list. */
	struct m_household_bank_update_deposit * household_bank_update_deposit_messages;	/**< Pointer to household_bank_update_deposit message list. */
	struct m_interest_rate * interest_rate_messages;	/**< Pointer to interest_rate message list. */
	struct m_buy * buy_messages;	/**< Pointer to buy message list. */
	struct m_bought * bought_messages;	/**< Pointer to bought message list. */
	struct m_sell * sell_messages;	/**< Pointer to sell message list. */
	struct m_sold * sold_messages;	/**< Pointer to sold message list. */
	struct m_goods_transactions_summary * goods_transactions_summary_messages;	/**< Pointer to goods_transactions_summary message list. */
	struct m_fired * fired_messages;	/**< Pointer to fired message list. */
	struct m_vacancy_stage1 * vacancy_stage1_messages;	/**< Pointer to vacancy_stage1 message list. */
	struct m_job_application_stage2 * job_application_stage2_messages;	/**< Pointer to job_application_stage2 message list. */
	struct m_job_application_stage1 * job_application_stage1_messages;	/**< Pointer to job_application_stage1 message list. */
	struct m_job_match_stage1 * job_match_stage1_messages;	/**< Pointer to job_match_stage1 message list. */
	struct m_job_change * job_change_messages;	/**< Pointer to job_change message list. */
	struct m_vacancy_stage2 * vacancy_stage2_messages;	/**< Pointer to vacancy_stage2 message list. */
	struct m_job_match_stage2 * job_match_stage2_messages;	/**< Pointer to job_match_stage2 message list. */
	struct m_employment_status * employment_status_messages;	/**< Pointer to employment_status message list. */
	struct m_loan_request_1 * loan_request_1_messages;	/**< Pointer to loan_request_1 message list. */
	struct m_loan_request_2 * loan_request_2_messages;	/**< Pointer to loan_request_2 message list. */
	struct m_loan_acknowledge_1 * loan_acknowledge_1_messages;	/**< Pointer to loan_acknowledge_1 message list. */
	struct m_loan_acknowledge_2 * loan_acknowledge_2_messages;	/**< Pointer to loan_acknowledge_2 message list. */
	struct m_debt_request * debt_request_messages;	/**< Pointer to debt_request message list. */
	struct m_debt_ack * debt_ack_messages;	/**< Pointer to debt_ack message list. */
	struct m_household_share * household_share_messages;	/**< Pointer to household_share message list. */
	struct m_capital_tax * capital_tax_messages;	/**< Pointer to capital_tax message list. */
	struct m_labour_tax * labour_tax_messages;	/**< Pointer to labour_tax message list. */
	struct m_unemployment_benefit * unemployment_benefit_messages;	/**< Pointer to unemployment_benefit message list. */
	struct m_general_benefit * general_benefit_messages;	/**< Pointer to general_benefit message list. */
	struct m_tax_rate * tax_rate_messages;	/**< Pointer to tax_rate message list. */
	struct m_fund_request * fund_request_messages;	/**< Pointer to fund_request message list. */
	struct m_fund_request_ack * fund_request_ack_messages;	/**< Pointer to fund_request_ack message list. */
	struct m_new_entrant_loan * new_entrant_loan_messages;	/**< Pointer to new_entrant_loan message list. */
	struct m_interest_on_loan * interest_on_loan_messages;	/**< Pointer to interest_on_loan message list. */
	struct m_loan_writeoff * loan_writeoff_messages;	/**< Pointer to loan_writeoff message list. */
	struct m_firm_net_profit * firm_net_profit_messages;	/**< Pointer to firm_net_profit message list. */
	struct m_bank_net_profit * bank_net_profit_messages;	/**< Pointer to bank_net_profit message list. */
	struct m_housing_price * housing_price_messages;	/**< Pointer to housing_price message list. */
	struct m_buy_housing * buy_housing_messages;	/**< Pointer to buy_housing message list. */
	struct m_sell_housing * sell_housing_messages;	/**< Pointer to sell_housing message list. */
	struct m_bought_housing * bought_housing_messages;	/**< Pointer to bought_housing message list. */
	struct m_sold_housing * sold_housing_messages;	/**< Pointer to sold_housing message list. */
	struct m_mortgaging_capacity * mortgaging_capacity_messages;	/**< Pointer to mortgaging_capacity message list. */
	struct m_mortgage_requests * mortgage_requests_messages;	/**< Pointer to mortgage_requests message list. */
	struct m_mortgage_payment_from_sale * mortgage_payment_from_sale_messages;	/**< Pointer to mortgage_payment_from_sale message list. */
	struct m_mortgage_payment * mortgage_payment_messages;	/**< Pointer to mortgage_payment message list. */
	struct m_mortgage_writeoff * mortgage_writeoff_messages;	/**< Pointer to mortgage_writeoff message list. */
	struct m_housing_transactions_summary * housing_transactions_summary_messages;	/**< Pointer to housing_transactions_summary message list. */

	struct node_information * next;	/**< Pointer to next node on the list. */
};


/** \typedef struct location location
 * \brief Typedef for location struct.
 */
typedef struct location location;
/** \typedef struct node_information node_information
 * \brief Typedef for node_information struct.
 */
typedef struct node_information node_information;

/** \var double ratio_liquidity
* \brief A constant variable from the environment. */
double FLAME_environment_variable_ratio_liquidity;
/** \var double consumption_adjustment_speed
* \brief A constant variable from the environment. */
double FLAME_environment_variable_consumption_adjustment_speed;
/** \var double wealth_effect
* \brief A constant variable from the environment. */
double FLAME_environment_variable_wealth_effect;
/** \var double turnover_probability
* \brief A constant variable from the environment. */
double FLAME_environment_variable_turnover_probability;
/** \var double production_markup
* \brief A constant variable from the environment. */
double FLAME_environment_variable_production_markup;
/** \var double price_markup
* \brief A constant variable from the environment. */
double FLAME_environment_variable_price_markup;
/** \var double firm_memory_persistance
* \brief A constant variable from the environment. */
double FLAME_environment_variable_firm_memory_persistance;
/** \var double ratio_debt_firm
* \brief A constant variable from the environment. */
double FLAME_environment_variable_ratio_debt_firm;
/** \var double ratio_fiscal_policy
* \brief A constant variable from the environment. */
double FLAME_environment_variable_ratio_fiscal_policy;
/** \var double ratio_capitalist_households
* \brief A constant variable from the environment. */
double FLAME_environment_variable_ratio_capitalist_households;
/** \var double inflation_target
* \brief A constant variable from the environment. */
double FLAME_environment_variable_inflation_target;
/** \var double firms_minimum_equity_ratio
* \brief A constant variable from the environment. */
double FLAME_environment_variable_firms_minimum_equity_ratio;
/** \var double firm_startup_leverage
* \brief A constant variable from the environment. */
double FLAME_environment_variable_firm_startup_leverage;
/** \var double household_startup_leverage
* \brief A constant variable from the environment. */
double FLAME_environment_variable_household_startup_leverage;
/** \var double car_buffer_threshold
* \brief A constant variable from the environment. */
double FLAME_environment_variable_car_buffer_threshold;
/** \var double housing_market_entrance_prob
* \brief A constant variable from the environment. */
double FLAME_environment_variable_housing_market_entrance_prob;
/** \var double fire_sale_threshold
* \brief A constant variable from the environment. */
double FLAME_environment_variable_fire_sale_threshold;
/** \var double household_budget_constraint
* \brief A constant variable from the environment. */
double FLAME_environment_variable_household_budget_constraint;
/** \var double capital_adequecy_ratio
* \brief A constant variable from the environment. */
double FLAME_environment_variable_capital_adequecy_ratio;
/** \var double housing_price_up_rate
* \brief A constant variable from the environment. */
double FLAME_environment_variable_housing_price_up_rate;
/** \var double housing_price_down_rate
* \brief A constant variable from the environment. */
double FLAME_environment_variable_housing_price_down_rate;
/** \var double household_mortgage_writeoff_high
* \brief A constant variable from the environment. */
double FLAME_environment_variable_household_mortgage_writeoff_high;
/** \var double household_mortgage_writeoff_low
* \brief A constant variable from the environment. */
double FLAME_environment_variable_household_mortgage_writeoff_low;
/** \var xmachine * temp_xmachine
* \brief Pointer to xmachine to initialise linked list. */
xmachine * temp_xmachine;

/** \var m_firm_bank_update_deposit * temp_firm_bank_update_deposit_message
* \brief Pointer to m_firm_bank_update_deposit to initialise linked list. */
m_firm_bank_update_deposit * temp_firm_bank_update_deposit_message;
/** \var m_household_bank_update_deposit * temp_household_bank_update_deposit_message
* \brief Pointer to m_household_bank_update_deposit to initialise linked list. */
m_household_bank_update_deposit * temp_household_bank_update_deposit_message;
/** \var m_interest_rate * temp_interest_rate_message
* \brief Pointer to m_interest_rate to initialise linked list. */
m_interest_rate * temp_interest_rate_message;
/** \var m_buy * temp_buy_message
* \brief Pointer to m_buy to initialise linked list. */
m_buy * temp_buy_message;
/** \var m_bought * temp_bought_message
* \brief Pointer to m_bought to initialise linked list. */
m_bought * temp_bought_message;
/** \var m_sell * temp_sell_message
* \brief Pointer to m_sell to initialise linked list. */
m_sell * temp_sell_message;
/** \var m_sold * temp_sold_message
* \brief Pointer to m_sold to initialise linked list. */
m_sold * temp_sold_message;
/** \var m_goods_transactions_summary * temp_goods_transactions_summary_message
* \brief Pointer to m_goods_transactions_summary to initialise linked list. */
m_goods_transactions_summary * temp_goods_transactions_summary_message;
/** \var m_fired * temp_fired_message
* \brief Pointer to m_fired to initialise linked list. */
m_fired * temp_fired_message;
/** \var m_vacancy_stage1 * temp_vacancy_stage1_message
* \brief Pointer to m_vacancy_stage1 to initialise linked list. */
m_vacancy_stage1 * temp_vacancy_stage1_message;
/** \var m_job_application_stage2 * temp_job_application_stage2_message
* \brief Pointer to m_job_application_stage2 to initialise linked list. */
m_job_application_stage2 * temp_job_application_stage2_message;
/** \var m_job_application_stage1 * temp_job_application_stage1_message
* \brief Pointer to m_job_application_stage1 to initialise linked list. */
m_job_application_stage1 * temp_job_application_stage1_message;
/** \var m_job_match_stage1 * temp_job_match_stage1_message
* \brief Pointer to m_job_match_stage1 to initialise linked list. */
m_job_match_stage1 * temp_job_match_stage1_message;
/** \var m_job_change * temp_job_change_message
* \brief Pointer to m_job_change to initialise linked list. */
m_job_change * temp_job_change_message;
/** \var m_vacancy_stage2 * temp_vacancy_stage2_message
* \brief Pointer to m_vacancy_stage2 to initialise linked list. */
m_vacancy_stage2 * temp_vacancy_stage2_message;
/** \var m_job_match_stage2 * temp_job_match_stage2_message
* \brief Pointer to m_job_match_stage2 to initialise linked list. */
m_job_match_stage2 * temp_job_match_stage2_message;
/** \var m_employment_status * temp_employment_status_message
* \brief Pointer to m_employment_status to initialise linked list. */
m_employment_status * temp_employment_status_message;
/** \var m_loan_request_1 * temp_loan_request_1_message
* \brief Pointer to m_loan_request_1 to initialise linked list. */
m_loan_request_1 * temp_loan_request_1_message;
/** \var m_loan_request_2 * temp_loan_request_2_message
* \brief Pointer to m_loan_request_2 to initialise linked list. */
m_loan_request_2 * temp_loan_request_2_message;
/** \var m_loan_acknowledge_1 * temp_loan_acknowledge_1_message
* \brief Pointer to m_loan_acknowledge_1 to initialise linked list. */
m_loan_acknowledge_1 * temp_loan_acknowledge_1_message;
/** \var m_loan_acknowledge_2 * temp_loan_acknowledge_2_message
* \brief Pointer to m_loan_acknowledge_2 to initialise linked list. */
m_loan_acknowledge_2 * temp_loan_acknowledge_2_message;
/** \var m_debt_request * temp_debt_request_message
* \brief Pointer to m_debt_request to initialise linked list. */
m_debt_request * temp_debt_request_message;
/** \var m_debt_ack * temp_debt_ack_message
* \brief Pointer to m_debt_ack to initialise linked list. */
m_debt_ack * temp_debt_ack_message;
/** \var m_household_share * temp_household_share_message
* \brief Pointer to m_household_share to initialise linked list. */
m_household_share * temp_household_share_message;
/** \var m_capital_tax * temp_capital_tax_message
* \brief Pointer to m_capital_tax to initialise linked list. */
m_capital_tax * temp_capital_tax_message;
/** \var m_labour_tax * temp_labour_tax_message
* \brief Pointer to m_labour_tax to initialise linked list. */
m_labour_tax * temp_labour_tax_message;
/** \var m_unemployment_benefit * temp_unemployment_benefit_message
* \brief Pointer to m_unemployment_benefit to initialise linked list. */
m_unemployment_benefit * temp_unemployment_benefit_message;
/** \var m_general_benefit * temp_general_benefit_message
* \brief Pointer to m_general_benefit to initialise linked list. */
m_general_benefit * temp_general_benefit_message;
/** \var m_tax_rate * temp_tax_rate_message
* \brief Pointer to m_tax_rate to initialise linked list. */
m_tax_rate * temp_tax_rate_message;
/** \var m_fund_request * temp_fund_request_message
* \brief Pointer to m_fund_request to initialise linked list. */
m_fund_request * temp_fund_request_message;
/** \var m_fund_request_ack * temp_fund_request_ack_message
* \brief Pointer to m_fund_request_ack to initialise linked list. */
m_fund_request_ack * temp_fund_request_ack_message;
/** \var m_new_entrant_loan * temp_new_entrant_loan_message
* \brief Pointer to m_new_entrant_loan to initialise linked list. */
m_new_entrant_loan * temp_new_entrant_loan_message;
/** \var m_interest_on_loan * temp_interest_on_loan_message
* \brief Pointer to m_interest_on_loan to initialise linked list. */
m_interest_on_loan * temp_interest_on_loan_message;
/** \var m_loan_writeoff * temp_loan_writeoff_message
* \brief Pointer to m_loan_writeoff to initialise linked list. */
m_loan_writeoff * temp_loan_writeoff_message;
/** \var m_firm_net_profit * temp_firm_net_profit_message
* \brief Pointer to m_firm_net_profit to initialise linked list. */
m_firm_net_profit * temp_firm_net_profit_message;
/** \var m_bank_net_profit * temp_bank_net_profit_message
* \brief Pointer to m_bank_net_profit to initialise linked list. */
m_bank_net_profit * temp_bank_net_profit_message;
/** \var m_housing_price * temp_housing_price_message
* \brief Pointer to m_housing_price to initialise linked list. */
m_housing_price * temp_housing_price_message;
/** \var m_buy_housing * temp_buy_housing_message
* \brief Pointer to m_buy_housing to initialise linked list. */
m_buy_housing * temp_buy_housing_message;
/** \var m_sell_housing * temp_sell_housing_message
* \brief Pointer to m_sell_housing to initialise linked list. */
m_sell_housing * temp_sell_housing_message;
/** \var m_bought_housing * temp_bought_housing_message
* \brief Pointer to m_bought_housing to initialise linked list. */
m_bought_housing * temp_bought_housing_message;
/** \var m_sold_housing * temp_sold_housing_message
* \brief Pointer to m_sold_housing to initialise linked list. */
m_sold_housing * temp_sold_housing_message;
/** \var m_mortgaging_capacity * temp_mortgaging_capacity_message
* \brief Pointer to m_mortgaging_capacity to initialise linked list. */
m_mortgaging_capacity * temp_mortgaging_capacity_message;
/** \var m_mortgage_requests * temp_mortgage_requests_message
* \brief Pointer to m_mortgage_requests to initialise linked list. */
m_mortgage_requests * temp_mortgage_requests_message;
/** \var m_mortgage_payment_from_sale * temp_mortgage_payment_from_sale_message
* \brief Pointer to m_mortgage_payment_from_sale to initialise linked list. */
m_mortgage_payment_from_sale * temp_mortgage_payment_from_sale_message;
/** \var m_mortgage_payment * temp_mortgage_payment_message
* \brief Pointer to m_mortgage_payment to initialise linked list. */
m_mortgage_payment * temp_mortgage_payment_message;
/** \var m_mortgage_writeoff * temp_mortgage_writeoff_message
* \brief Pointer to m_mortgage_writeoff to initialise linked list. */
m_mortgage_writeoff * temp_mortgage_writeoff_message;
/** \var m_housing_transactions_summary * temp_housing_transactions_summary_message
* \brief Pointer to m_housing_transactions_summary to initialise linked list. */
m_housing_transactions_summary * temp_housing_transactions_summary_message;
/** \var node_information * temp_node_info
* \brief Pointer to node_information to initialise linked list. */
node_information * temp_node_info;
/** \var char outputpath[1000]
* \brief Output path for files. */
char outputpath[1000];
/** \var long total_time
* \brief Total time for the simulation run (in seconds) */
double total_time;
/** \var int total_messages
* \brief Total messages sent between nodes for the simulation run */
int total_messages;
/** \var int totalnodes
* \brief Number of nodes */
int totalnodes;
/** \var xmachine ** p_xmachine
* \brief Pointer to first pointer of x-machine memory list */
//xmachine ** p_xmachine;
/** \var xmachine * current_xmachine
* \brief Pointer to current x-machine memory that is being processed */
xmachine * current_xmachine;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_firm * current_xmachine_firm;
/*@dependent@*/ xmachine_memory_firm_holder * temp_xmachine_firm_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_firm_holder * current_xmachine_firm_holder;
xmachine_memory_firm_state * current_xmachine_firm_next_state; /* New agents added to this state */
/* Pointer to list of firm agents in state FirmHousingPrice state */
//xmachine_memory_firm * temp_xmachine_firm_FirmHousingPrice;
xmachine_memory_firm_state * firm_FirmHousingPrice_state;
/* Pointer to list of firm agents in state FirmHousingSell state */
//xmachine_memory_firm * temp_xmachine_firm_FirmHousingSell;
xmachine_memory_firm_state * firm_FirmHousingSell_state;
/* Pointer to list of firm agents in state FirmHousingMarket state */
//xmachine_memory_firm * temp_xmachine_firm_FirmHousingMarket;
xmachine_memory_firm_state * firm_FirmHousingMarket_state;
/* Pointer to list of firm agents in state FirmCreditBalanceSheet state */
//xmachine_memory_firm * temp_xmachine_firm_FirmCreditBalanceSheet;
xmachine_memory_firm_state * firm_FirmCreditBalanceSheet_state;
/* Pointer to list of firm agents in state FirmCreditIncomeStatement state */
//xmachine_memory_firm * temp_xmachine_firm_FirmCreditIncomeStatement;
xmachine_memory_firm_state * firm_FirmCreditIncomeStatement_state;
/* Pointer to list of firm agents in state FirmCreditLoanPayment state */
//xmachine_memory_firm * temp_xmachine_firm_FirmCreditLoanPayment;
xmachine_memory_firm_state * firm_FirmCreditLoanPayment_state;
/* Pointer to list of firm agents in state FirmCreditBankruptcy state */
//xmachine_memory_firm * temp_xmachine_firm_FirmCreditBankruptcy;
xmachine_memory_firm_state * firm_FirmCreditBankruptcy_state;
/* Pointer to list of firm agents in state FirmCreditCheckInvestment state */
//xmachine_memory_firm * temp_xmachine_firm_FirmCreditCheckInvestment;
xmachine_memory_firm_state * firm_FirmCreditCheckInvestment_state;
/* Pointer to list of firm agents in state FirmCreditIlliquidityStatus state */
//xmachine_memory_firm * temp_xmachine_firm_FirmCreditIlliquidityStatus;
xmachine_memory_firm_state * firm_FirmCreditIlliquidityStatus_state;
/* Pointer to list of firm agents in state FirmCreditLoanBorrow2 state */
//xmachine_memory_firm * temp_xmachine_firm_FirmCreditLoanBorrow2;
xmachine_memory_firm_state * firm_FirmCreditLoanBorrow2_state;
/* Pointer to list of firm agents in state FirmCreditLoanBorrow1 state */
//xmachine_memory_firm * temp_xmachine_firm_FirmCreditLoanBorrow1;
xmachine_memory_firm_state * firm_FirmCreditLoanBorrow1_state;
/* Pointer to list of firm agents in state FirmCreditInsolvency state */
//xmachine_memory_firm * temp_xmachine_firm_FirmCreditInsolvency;
xmachine_memory_firm_state * firm_FirmCreditInsolvency_state;
/* Pointer to list of firm agents in state FirmCreditLoanRequest state */
//xmachine_memory_firm * temp_xmachine_firm_FirmCreditLoanRequest;
xmachine_memory_firm_state * firm_FirmCreditLoanRequest_state;
/* Pointer to list of firm agents in state FirmCreditDividendPayments state */
//xmachine_memory_firm * temp_xmachine_firm_FirmCreditDividendPayments;
xmachine_memory_firm_state * firm_FirmCreditDividendPayments_state;
/* Pointer to list of firm agents in state FirmCreditStatus state */
//xmachine_memory_firm * temp_xmachine_firm_FirmCreditStatus;
xmachine_memory_firm_state * firm_FirmCreditStatus_state;
/* Pointer to list of firm agents in state FirmCreditLiquidityNeed state */
//xmachine_memory_firm * temp_xmachine_firm_FirmCreditLiquidityNeed;
xmachine_memory_firm_state * firm_FirmCreditLiquidityNeed_state;
/* Pointer to list of firm agents in state FirmConstructionLabourDemand state */
//xmachine_memory_firm * temp_xmachine_firm_FirmConstructionLabourDemand;
xmachine_memory_firm_state * firm_FirmConstructionLabourDemand_state;
/* Pointer to list of firm agents in state FirmProductionLabourDemand state */
//xmachine_memory_firm * temp_xmachine_firm_FirmProductionLabourDemand;
xmachine_memory_firm_state * firm_FirmProductionLabourDemand_state;
/* Pointer to list of firm agents in state FirmProductionPlanning state */
//xmachine_memory_firm * temp_xmachine_firm_FirmProductionPlanning;
xmachine_memory_firm_state * firm_FirmProductionPlanning_state;
/* Pointer to list of firm agents in state FirmProductionConstructor state */
//xmachine_memory_firm * temp_xmachine_firm_FirmProductionConstructor;
xmachine_memory_firm_state * firm_FirmProductionConstructor_state;
/* Pointer to list of firm agents in state FirmProductionRegular state */
//xmachine_memory_firm * temp_xmachine_firm_FirmProductionRegular;
xmachine_memory_firm_state * firm_FirmProductionRegular_state;
/* Pointer to list of firm agents in state FirmProductionRoleCheck state */
//xmachine_memory_firm * temp_xmachine_firm_FirmProductionRoleCheck;
xmachine_memory_firm_state * firm_FirmProductionRoleCheck_state;
/* Pointer to list of firm agents in state FirmProductionSkip state */
//xmachine_memory_firm * temp_xmachine_firm_FirmProductionSkip;
xmachine_memory_firm_state * firm_FirmProductionSkip_state;
/* Pointer to list of firm agents in state FirmProductionStart state */
//xmachine_memory_firm * temp_xmachine_firm_FirmProductionStart;
xmachine_memory_firm_state * firm_FirmProductionStart_state;
/* Pointer to list of firm agents in state FirmLabourWageAdjustment state */
//xmachine_memory_firm * temp_xmachine_firm_FirmLabourWageAdjustment;
xmachine_memory_firm_state * firm_FirmLabourWageAdjustment_state;
/* Pointer to list of firm agents in state FirmLabourStage2End state */
//xmachine_memory_firm * temp_xmachine_firm_FirmLabourStage2End;
xmachine_memory_firm_state * firm_FirmLabourStage2End_state;
/* Pointer to list of firm agents in state FirmLabourStage2 state */
//xmachine_memory_firm * temp_xmachine_firm_FirmLabourStage2;
xmachine_memory_firm_state * firm_FirmLabourStage2_state;
/* Pointer to list of firm agents in state FirmLabourStage1Application state */
//xmachine_memory_firm * temp_xmachine_firm_FirmLabourStage1Application;
xmachine_memory_firm_state * firm_FirmLabourStage1Application_state;
/* Pointer to list of firm agents in state FirmLabourStage1End state */
//xmachine_memory_firm * temp_xmachine_firm_FirmLabourStage1End;
xmachine_memory_firm_state * firm_FirmLabourStage1End_state;
/* Pointer to list of firm agents in state FirmLabourStage1 state */
//xmachine_memory_firm * temp_xmachine_firm_FirmLabourStage1;
xmachine_memory_firm_state * firm_FirmLabourStage1_state;
/* Pointer to list of firm agents in state FirmLabourPayWages state */
//xmachine_memory_firm * temp_xmachine_firm_FirmLabourPayWages;
xmachine_memory_firm_state * firm_FirmLabourPayWages_state;
/* Pointer to list of firm agents in state FirmLabourStart state */
//xmachine_memory_firm * temp_xmachine_firm_FirmLabourStart;
xmachine_memory_firm_state * firm_FirmLabourStart_state;
/* Pointer to list of firm agents in state FirmConsumptionPrice state */
//xmachine_memory_firm * temp_xmachine_firm_FirmConsumptionPrice;
xmachine_memory_firm_state * firm_FirmConsumptionPrice_state;
/* Pointer to list of firm agents in state FirmRecieveSales state */
//xmachine_memory_firm * temp_xmachine_firm_FirmRecieveSales;
xmachine_memory_firm_state * firm_FirmRecieveSales_state;
/* Pointer to list of firm agents in state FirmHousingStart state */
//xmachine_memory_firm * temp_xmachine_firm_FirmHousingStart;
xmachine_memory_firm_state * firm_FirmHousingStart_state;
/* Pointer to list of firm agents in state FirmConsumptionStart state */
//xmachine_memory_firm * temp_xmachine_firm_FirmConsumptionStart;
xmachine_memory_firm_state * firm_FirmConsumptionStart_state;
/* Pointer to list of firm agents in state end state */
//xmachine_memory_firm * temp_xmachine_firm_end;
xmachine_memory_firm_state * firm_end_state;
/* Pointer to list of firm agents in state FirmUpdateDeposits state */
//xmachine_memory_firm * temp_xmachine_firm_FirmUpdateDeposits;
xmachine_memory_firm_state * firm_FirmUpdateDeposits_state;
/* Pointer to list of firm agents in state FirmCreditStart state */
//xmachine_memory_firm * temp_xmachine_firm_FirmCreditStart;
xmachine_memory_firm_state * firm_FirmCreditStart_state;
/* Pointer to list of firm agents in state start state */
//xmachine_memory_firm * temp_xmachine_firm_start;
xmachine_memory_firm_state * firm_start_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_household * current_xmachine_household;
/*@dependent@*/ xmachine_memory_household_holder * temp_xmachine_household_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_household_holder * current_xmachine_household_holder;
xmachine_memory_household_state * current_xmachine_household_next_state; /* New agents added to this state */
/* Pointer to list of household agents in state HHHousingWriteOff state */
//xmachine_memory_household * temp_xmachine_household_HHHousingWriteOff;
xmachine_memory_household_state * household_HHHousingWriteOff_state;
/* Pointer to list of household agents in state HHHousingPayments state */
//xmachine_memory_household * temp_xmachine_household_HHHousingPayments;
xmachine_memory_household_state * household_HHHousingPayments_state;
/* Pointer to list of household agents in state HHHousingBargain state */
//xmachine_memory_household * temp_xmachine_household_HHHousingBargain;
xmachine_memory_household_state * household_HHHousingBargain_state;
/* Pointer to list of household agents in state HHHousingRevenue state */
//xmachine_memory_household * temp_xmachine_household_HHHousingRevenue;
xmachine_memory_household_state * household_HHHousingRevenue_state;
/* Pointer to list of household agents in state HHHousingCheckWealth state */
//xmachine_memory_household * temp_xmachine_household_HHHousingCheckWealth;
xmachine_memory_household_state * household_HHHousingCheckWealth_state;
/* Pointer to list of household agents in state HHHousingPrice state */
//xmachine_memory_household * temp_xmachine_household_HHHousingPrice;
xmachine_memory_household_state * household_HHHousingPrice_state;
/* Pointer to list of household agents in state HHHousingRole state */
//xmachine_memory_household * temp_xmachine_household_HHHousingRole;
xmachine_memory_household_state * household_HHHousingRole_state;
/* Pointer to list of household agents in state HHCreditEmployment state */
//xmachine_memory_household * temp_xmachine_household_HHCreditEmployment;
xmachine_memory_household_state * household_HHCreditEmployment_state;
/* Pointer to list of household agents in state HHCreditCapitalTax state */
//xmachine_memory_household * temp_xmachine_household_HHCreditCapitalTax;
xmachine_memory_household_state * household_HHCreditCapitalTax_state;
/* Pointer to list of household agents in state HHCreditBalanceSheet state */
//xmachine_memory_household * temp_xmachine_household_HHCreditBalanceSheet;
xmachine_memory_household_state * household_HHCreditBalanceSheet_state;
/* Pointer to list of household agents in state HHCreditIsCapitalist state */
//xmachine_memory_household * temp_xmachine_household_HHCreditIsCapitalist;
xmachine_memory_household_state * household_HHCreditIsCapitalist_state;
/* Pointer to list of household agents in state HHCreditUpdateMortgages state */
//xmachine_memory_household * temp_xmachine_household_HHCreditUpdateMortgages;
xmachine_memory_household_state * household_HHCreditUpdateMortgages_state;
/* Pointer to list of household agents in state HHCreditCheckTax state */
//xmachine_memory_household * temp_xmachine_household_HHCreditCheckTax;
xmachine_memory_household_state * household_HHCreditCheckTax_state;
/* Pointer to list of household agents in state HHCreditMonthly state */
//xmachine_memory_household * temp_xmachine_household_HHCreditMonthly;
xmachine_memory_household_state * household_HHCreditMonthly_state;
/* Pointer to list of household agents in state HHLabourPayroll state */
//xmachine_memory_household * temp_xmachine_household_HHLabourPayroll;
xmachine_memory_household_state * household_HHLabourPayroll_state;
/* Pointer to list of household agents in state HHLabourStage1Placement state */
//xmachine_memory_household * temp_xmachine_household_HHLabourStage1Placement;
xmachine_memory_household_state * household_HHLabourStage1Placement_state;
/* Pointer to list of household agents in state HHLabourStage1Applications state */
//xmachine_memory_household * temp_xmachine_household_HHLabourStage1Applications;
xmachine_memory_household_state * household_HHLabourStage1Applications_state;
/* Pointer to list of household agents in state HHLabourStage2 state */
//xmachine_memory_household * temp_xmachine_household_HHLabourStage2;
xmachine_memory_household_state * household_HHLabourStage2_state;
/* Pointer to list of household agents in state HHLabourStage1 state */
//xmachine_memory_household * temp_xmachine_household_HHLabourStage1;
xmachine_memory_household_state * household_HHLabourStage1_state;
/* Pointer to list of household agents in state HHLabourEmploymentStatus state */
//xmachine_memory_household * temp_xmachine_household_HHLabourEmploymentStatus;
xmachine_memory_household_state * household_HHLabourEmploymentStatus_state;
/* Pointer to list of household agents in state HHLabourStart state */
//xmachine_memory_household * temp_xmachine_household_HHLabourStart;
xmachine_memory_household_state * household_HHLabourStart_state;
/* Pointer to list of household agents in state HHConsumptionRecieveGoods state */
//xmachine_memory_household * temp_xmachine_household_HHConsumptionRecieveGoods;
xmachine_memory_household_state * household_HHConsumptionRecieveGoods_state;
/* Pointer to list of household agents in state HHHousingStart state */
//xmachine_memory_household * temp_xmachine_household_HHHousingStart;
xmachine_memory_household_state * household_HHHousingStart_state;
/* Pointer to list of household agents in state HHConsumptionWeekly state */
//xmachine_memory_household * temp_xmachine_household_HHConsumptionWeekly;
xmachine_memory_household_state * household_HHConsumptionWeekly_state;
/* Pointer to list of household agents in state HHConsumptionStart state */
//xmachine_memory_household * temp_xmachine_household_HHConsumptionStart;
xmachine_memory_household_state * household_HHConsumptionStart_state;
/* Pointer to list of household agents in state end state */
//xmachine_memory_household * temp_xmachine_household_end;
xmachine_memory_household_state * household_end_state;
/* Pointer to list of household agents in state HouseholdUpdateDeposits state */
//xmachine_memory_household * temp_xmachine_household_HouseholdUpdateDeposits;
xmachine_memory_household_state * household_HouseholdUpdateDeposits_state;
/* Pointer to list of household agents in state HHCreditStart state */
//xmachine_memory_household * temp_xmachine_household_HHCreditStart;
xmachine_memory_household_state * household_HHCreditStart_state;
/* Pointer to list of household agents in state start state */
//xmachine_memory_household * temp_xmachine_household_start;
xmachine_memory_household_state * household_start_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_equityfund * current_xmachine_equityfund;
/*@dependent@*/ xmachine_memory_equityfund_holder * temp_xmachine_equityfund_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_equityfund_holder * current_xmachine_equityfund_holder;
xmachine_memory_equityfund_state * current_xmachine_equityfund_next_state; /* New agents added to this state */
/* Pointer to list of equityfund agents in state EFCreditBalanceSheet state */
//xmachine_memory_equityfund * temp_xmachine_equityfund_EFCreditBalanceSheet;
xmachine_memory_equityfund_state * equityfund_EFCreditBalanceSheet_state;
/* Pointer to list of equityfund agents in state EFCreditShareCollectionFirms state */
//xmachine_memory_equityfund * temp_xmachine_equityfund_EFCreditShareCollectionFirms;
xmachine_memory_equityfund_state * equityfund_EFCreditShareCollectionFirms_state;
/* Pointer to list of equityfund agents in state EFCreditShareCollectionBanks state */
//xmachine_memory_equityfund * temp_xmachine_equityfund_EFCreditShareCollectionBanks;
xmachine_memory_equityfund_state * equityfund_EFCreditShareCollectionBanks_state;
/* Pointer to list of equityfund agents in state EFCreditDistributeShares state */
//xmachine_memory_equityfund * temp_xmachine_equityfund_EFCreditDistributeShares;
xmachine_memory_equityfund_state * equityfund_EFCreditDistributeShares_state;
/* Pointer to list of equityfund agents in state end state */
//xmachine_memory_equityfund * temp_xmachine_equityfund_end;
xmachine_memory_equityfund_state * equityfund_end_state;
/* Pointer to list of equityfund agents in state EFLabourMarket state */
//xmachine_memory_equityfund * temp_xmachine_equityfund_EFLabourMarket;
xmachine_memory_equityfund_state * equityfund_EFLabourMarket_state;
/* Pointer to list of equityfund agents in state EquityFundStart state */
//xmachine_memory_equityfund * temp_xmachine_equityfund_EquityFundStart;
xmachine_memory_equityfund_state * equityfund_EquityFundStart_state;
/* Pointer to list of equityfund agents in state start state */
//xmachine_memory_equityfund * temp_xmachine_equityfund_start;
xmachine_memory_equityfund_state * equityfund_start_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_bank * current_xmachine_bank;
/*@dependent@*/ xmachine_memory_bank_holder * temp_xmachine_bank_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_bank_holder * current_xmachine_bank_holder;
xmachine_memory_bank_state * current_xmachine_bank_next_state; /* New agents added to this state */
/* Pointer to list of bank agents in state BankHousingWriteOff state */
//xmachine_memory_bank * temp_xmachine_bank_BankHousingWriteOff;
xmachine_memory_bank_state * bank_BankHousingWriteOff_state;
/* Pointer to list of bank agents in state BankHousingMortgages state */
//xmachine_memory_bank * temp_xmachine_bank_BankHousingMortgages;
xmachine_memory_bank_state * bank_BankHousingMortgages_state;
/* Pointer to list of bank agents in state BankHousingSales state */
//xmachine_memory_bank * temp_xmachine_bank_BankHousingSales;
xmachine_memory_bank_state * bank_BankHousingSales_state;
/* Pointer to list of bank agents in state BankHousingCrediting state */
//xmachine_memory_bank * temp_xmachine_bank_BankHousingCrediting;
xmachine_memory_bank_state * bank_BankHousingCrediting_state;
/* Pointer to list of bank agents in state BankCreditBalanceSheet state */
//xmachine_memory_bank * temp_xmachine_bank_BankCreditBalanceSheet;
xmachine_memory_bank_state * bank_BankCreditBalanceSheet_state;
/* Pointer to list of bank agents in state BankCreditDividends state */
//xmachine_memory_bank * temp_xmachine_bank_BankCreditDividends;
xmachine_memory_bank_state * bank_BankCreditDividends_state;
/* Pointer to list of bank agents in state BankCreditLiquidtyRecieve state */
//xmachine_memory_bank * temp_xmachine_bank_BankCreditLiquidtyRecieve;
xmachine_memory_bank_state * bank_BankCreditLiquidtyRecieve_state;
/* Pointer to list of bank agents in state BankCreditIncomeStatement state */
//xmachine_memory_bank * temp_xmachine_bank_BankCreditIncomeStatement;
xmachine_memory_bank_state * bank_BankCreditIncomeStatement_state;
/* Pointer to list of bank agents in state BankCreditLiquidityNeed state */
//xmachine_memory_bank * temp_xmachine_bank_BankCreditLiquidityNeed;
xmachine_memory_bank_state * bank_BankCreditLiquidityNeed_state;
/* Pointer to list of bank agents in state BankCreditLoanInterests state */
//xmachine_memory_bank * temp_xmachine_bank_BankCreditLoanInterests;
xmachine_memory_bank_state * bank_BankCreditLoanInterests_state;
/* Pointer to list of bank agents in state BankCreditNewEntrants state */
//xmachine_memory_bank * temp_xmachine_bank_BankCreditNewEntrants;
xmachine_memory_bank_state * bank_BankCreditNewEntrants_state;
/* Pointer to list of bank agents in state BankCreditLoanWriteOffs state */
//xmachine_memory_bank * temp_xmachine_bank_BankCreditLoanWriteOffs;
xmachine_memory_bank_state * bank_BankCreditLoanWriteOffs_state;
/* Pointer to list of bank agents in state BankCreditRequest2 state */
//xmachine_memory_bank * temp_xmachine_bank_BankCreditRequest2;
xmachine_memory_bank_state * bank_BankCreditRequest2_state;
/* Pointer to list of bank agents in state BankHousingMarket state */
//xmachine_memory_bank * temp_xmachine_bank_BankHousingMarket;
xmachine_memory_bank_state * bank_BankHousingMarket_state;
/* Pointer to list of bank agents in state end state */
//xmachine_memory_bank * temp_xmachine_bank_end;
xmachine_memory_bank_state * bank_end_state;
/* Pointer to list of bank agents in state BankUpdateDeposits state */
//xmachine_memory_bank * temp_xmachine_bank_BankUpdateDeposits;
xmachine_memory_bank_state * bank_BankUpdateDeposits_state;
/* Pointer to list of bank agents in state BankCreditStart state */
//xmachine_memory_bank * temp_xmachine_bank_BankCreditStart;
xmachine_memory_bank_state * bank_BankCreditStart_state;
/* Pointer to list of bank agents in state start state */
//xmachine_memory_bank * temp_xmachine_bank_start;
xmachine_memory_bank_state * bank_start_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_government * current_xmachine_government;
/*@dependent@*/ xmachine_memory_government_holder * temp_xmachine_government_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_government_holder * current_xmachine_government_holder;
xmachine_memory_government_state * current_xmachine_government_next_state; /* New agents added to this state */
/* Pointer to list of government agents in state GovernmentLabourTax state */
//xmachine_memory_government * temp_xmachine_government_GovernmentLabourTax;
xmachine_memory_government_state * government_GovernmentLabourTax_state;
/* Pointer to list of government agents in state GovernmentUnemploymentBenefits state */
//xmachine_memory_government * temp_xmachine_government_GovernmentUnemploymentBenefits;
xmachine_memory_government_state * government_GovernmentUnemploymentBenefits_state;
/* Pointer to list of government agents in state GovernmentBalanceSheet state */
//xmachine_memory_government * temp_xmachine_government_GovernmentBalanceSheet;
xmachine_memory_government_state * government_GovernmentBalanceSheet_state;
/* Pointer to list of government agents in state GovernmentIncomeStatement state */
//xmachine_memory_government * temp_xmachine_government_GovernmentIncomeStatement;
xmachine_memory_government_state * government_GovernmentIncomeStatement_state;
/* Pointer to list of government agents in state GovernmentCapitalTax state */
//xmachine_memory_government * temp_xmachine_government_GovernmentCapitalTax;
xmachine_memory_government_state * government_GovernmentCapitalTax_state;
/* Pointer to list of government agents in state GovernmentMonthly state */
//xmachine_memory_government * temp_xmachine_government_GovernmentMonthly;
xmachine_memory_government_state * government_GovernmentMonthly_state;
/* Pointer to list of government agents in state end state */
//xmachine_memory_government * temp_xmachine_government_end;
xmachine_memory_government_state * government_end_state;
/* Pointer to list of government agents in state GovernmentLabourStatus state */
//xmachine_memory_government * temp_xmachine_government_GovernmentLabourStatus;
xmachine_memory_government_state * government_GovernmentLabourStatus_state;
/* Pointer to list of government agents in state GovernmentStart state */
//xmachine_memory_government * temp_xmachine_government_GovernmentStart;
xmachine_memory_government_state * government_GovernmentStart_state;
/* Pointer to list of government agents in state start state */
//xmachine_memory_government * temp_xmachine_government_start;
xmachine_memory_government_state * government_start_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_centralbank * current_xmachine_centralbank;
/*@dependent@*/ xmachine_memory_centralbank_holder * temp_xmachine_centralbank_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_centralbank_holder * current_xmachine_centralbank_holder;
xmachine_memory_centralbank_state * current_xmachine_centralbank_next_state; /* New agents added to this state */
/* Pointer to list of centralbank agents in state end state */
//xmachine_memory_centralbank * temp_xmachine_centralbank_end;
xmachine_memory_centralbank_state * centralbank_end_state;
/* Pointer to list of centralbank agents in state CentralBankBalanceSheet state */
//xmachine_memory_centralbank * temp_xmachine_centralbank_CentralBankBalanceSheet;
xmachine_memory_centralbank_state * centralbank_CentralBankBalanceSheet_state;
/* Pointer to list of centralbank agents in state CentralBankIncomeStatement state */
//xmachine_memory_centralbank * temp_xmachine_centralbank_CentralBankIncomeStatement;
xmachine_memory_centralbank_state * centralbank_CentralBankIncomeStatement_state;
/* Pointer to list of centralbank agents in state CentralBankDebtRequests state */
//xmachine_memory_centralbank * temp_xmachine_centralbank_CentralBankDebtRequests;
xmachine_memory_centralbank_state * centralbank_CentralBankDebtRequests_state;
/* Pointer to list of centralbank agents in state CentralBankLabour state */
//xmachine_memory_centralbank * temp_xmachine_centralbank_CentralBankLabour;
xmachine_memory_centralbank_state * centralbank_CentralBankLabour_state;
/* Pointer to list of centralbank agents in state CentralBankHousing state */
//xmachine_memory_centralbank * temp_xmachine_centralbank_CentralBankHousing;
xmachine_memory_centralbank_state * centralbank_CentralBankHousing_state;
/* Pointer to list of centralbank agents in state CentralBankConsumption state */
//xmachine_memory_centralbank * temp_xmachine_centralbank_CentralBankConsumption;
xmachine_memory_centralbank_state * centralbank_CentralBankConsumption_state;
/* Pointer to list of centralbank agents in state CentralBankCredit state */
//xmachine_memory_centralbank * temp_xmachine_centralbank_CentralBankCredit;
xmachine_memory_centralbank_state * centralbank_CentralBankCredit_state;
/* Pointer to list of centralbank agents in state start state */
//xmachine_memory_centralbank * temp_xmachine_centralbank_start;
xmachine_memory_centralbank_state * centralbank_start_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_jpoffice * current_xmachine_jpoffice;
/*@dependent@*/ xmachine_memory_jpoffice_holder * temp_xmachine_jpoffice_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_jpoffice_holder * current_xmachine_jpoffice_holder;
xmachine_memory_jpoffice_state * current_xmachine_jpoffice_next_state; /* New agents added to this state */
/* Pointer to list of jpoffice agents in state JPOLabourStage2 state */
//xmachine_memory_jpoffice * temp_xmachine_jpoffice_JPOLabourStage2;
xmachine_memory_jpoffice_state * jpoffice_JPOLabourStage2_state;
/* Pointer to list of jpoffice agents in state end state */
//xmachine_memory_jpoffice * temp_xmachine_jpoffice_end;
xmachine_memory_jpoffice_state * jpoffice_end_state;
/* Pointer to list of jpoffice agents in state JPOLabourMarket state */
//xmachine_memory_jpoffice * temp_xmachine_jpoffice_JPOLabourMarket;
xmachine_memory_jpoffice_state * jpoffice_JPOLabourMarket_state;
/* Pointer to list of jpoffice agents in state start state */
//xmachine_memory_jpoffice * temp_xmachine_jpoffice_start;
xmachine_memory_jpoffice_state * jpoffice_start_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_mall * current_xmachine_mall;
/*@dependent@*/ xmachine_memory_mall_holder * temp_xmachine_mall_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_mall_holder * current_xmachine_mall_holder;
xmachine_memory_mall_state * current_xmachine_mall_next_state; /* New agents added to this state */
/* Pointer to list of mall agents in state MallConsumptionSummary state */
//xmachine_memory_mall * temp_xmachine_mall_MallConsumptionSummary;
xmachine_memory_mall_state * mall_MallConsumptionSummary_state;
/* Pointer to list of mall agents in state end state */
//xmachine_memory_mall * temp_xmachine_mall_end;
xmachine_memory_mall_state * mall_end_state;
/* Pointer to list of mall agents in state MallConsumptionMarket state */
//xmachine_memory_mall * temp_xmachine_mall_MallConsumptionMarket;
xmachine_memory_mall_state * mall_MallConsumptionMarket_state;
/* Pointer to list of mall agents in state start state */
//xmachine_memory_mall * temp_xmachine_mall_start;
xmachine_memory_mall_state * mall_start_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_reagency * current_xmachine_reagency;
/*@dependent@*/ xmachine_memory_reagency_holder * temp_xmachine_reagency_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_reagency_holder * current_xmachine_reagency_holder;
xmachine_memory_reagency_state * current_xmachine_reagency_next_state; /* New agents added to this state */
/* Pointer to list of reagency agents in state REAgencyHousingSummary state */
//xmachine_memory_reagency * temp_xmachine_reagency_REAgencyHousingSummary;
xmachine_memory_reagency_state * reagency_REAgencyHousingSummary_state;
/* Pointer to list of reagency agents in state REAgencyHousingProcess state */
//xmachine_memory_reagency * temp_xmachine_reagency_REAgencyHousingProcess;
xmachine_memory_reagency_state * reagency_REAgencyHousingProcess_state;
/* Pointer to list of reagency agents in state end state */
//xmachine_memory_reagency * temp_xmachine_reagency_end;
xmachine_memory_reagency_state * reagency_end_state;
/* Pointer to list of reagency agents in state REAgencyHousingMarket state */
//xmachine_memory_reagency * temp_xmachine_reagency_REAgencyHousingMarket;
xmachine_memory_reagency_state * reagency_REAgencyHousingMarket_state;
/* Pointer to list of reagency agents in state start state */
//xmachine_memory_reagency * temp_xmachine_reagency_start;
xmachine_memory_reagency_state * reagency_start_state;



MBt_Board b_firm_bank_update_deposit;
MBt_Iterator i_firm_bank_update_deposit;

MBt_Board b_household_bank_update_deposit;
MBt_Iterator i_household_bank_update_deposit;

MBt_Board b_interest_rate;
MBt_Iterator i_interest_rate;

MBt_Board b_buy;
MBt_Iterator i_buy;

MBt_Board b_bought;
MBt_Iterator i_bought;

MBt_Board b_sell;
MBt_Iterator i_sell;

MBt_Board b_sold;
MBt_Iterator i_sold;

MBt_Board b_goods_transactions_summary;
MBt_Iterator i_goods_transactions_summary;

MBt_Board b_fired;
MBt_Iterator i_fired;

MBt_Board b_vacancy_stage1;
MBt_Iterator i_vacancy_stage1;

MBt_Board b_job_application_stage2;
MBt_Iterator i_job_application_stage2;

MBt_Board b_job_application_stage1;
MBt_Iterator i_job_application_stage1;

MBt_Board b_job_match_stage1;
MBt_Iterator i_job_match_stage1;

MBt_Board b_job_change;
MBt_Iterator i_job_change;

MBt_Board b_vacancy_stage2;
MBt_Iterator i_vacancy_stage2;

MBt_Board b_job_match_stage2;
MBt_Iterator i_job_match_stage2;

MBt_Board b_employment_status;
MBt_Iterator i_employment_status;

MBt_Board b_loan_request_1;
MBt_Iterator i_loan_request_1;

MBt_Board b_loan_request_2;
MBt_Iterator i_loan_request_2;

MBt_Board b_loan_acknowledge_1;
MBt_Iterator i_loan_acknowledge_1;

MBt_Board b_loan_acknowledge_2;
MBt_Iterator i_loan_acknowledge_2;

MBt_Board b_debt_request;
MBt_Iterator i_debt_request;

MBt_Board b_debt_ack;
MBt_Iterator i_debt_ack;

MBt_Board b_household_share;
MBt_Iterator i_household_share;

MBt_Board b_capital_tax;
MBt_Iterator i_capital_tax;

MBt_Board b_labour_tax;
MBt_Iterator i_labour_tax;

MBt_Board b_unemployment_benefit;
MBt_Iterator i_unemployment_benefit;

MBt_Board b_general_benefit;
MBt_Iterator i_general_benefit;

MBt_Board b_tax_rate;
MBt_Iterator i_tax_rate;

MBt_Board b_fund_request;
MBt_Iterator i_fund_request;

MBt_Board b_fund_request_ack;
MBt_Iterator i_fund_request_ack;

MBt_Board b_new_entrant_loan;
MBt_Iterator i_new_entrant_loan;

MBt_Board b_interest_on_loan;
MBt_Iterator i_interest_on_loan;

MBt_Board b_loan_writeoff;
MBt_Iterator i_loan_writeoff;

MBt_Board b_firm_net_profit;
MBt_Iterator i_firm_net_profit;

MBt_Board b_bank_net_profit;
MBt_Iterator i_bank_net_profit;

MBt_Board b_housing_price;
MBt_Iterator i_housing_price;

MBt_Board b_buy_housing;
MBt_Iterator i_buy_housing;

MBt_Board b_sell_housing;
MBt_Iterator i_sell_housing;

MBt_Board b_bought_housing;
MBt_Iterator i_bought_housing;

MBt_Board b_sold_housing;
MBt_Iterator i_sold_housing;

MBt_Board b_mortgaging_capacity;
MBt_Iterator i_mortgaging_capacity;

MBt_Board b_mortgage_requests;
MBt_Iterator i_mortgage_requests;

MBt_Board b_mortgage_payment_from_sale;
MBt_Iterator i_mortgage_payment_from_sale;

MBt_Board b_mortgage_payment;
MBt_Iterator i_mortgage_payment;

MBt_Board b_mortgage_writeoff;
MBt_Iterator i_mortgage_writeoff;

MBt_Board b_housing_transactions_summary;
MBt_Iterator i_housing_transactions_summary;


/** \var m_firm_bank_update_deposit * firm_bank_update_deposit_message
* \brief Pointer to message struct for looping through firm_bank_update_deposit message list */
m_firm_bank_update_deposit * firm_bank_update_deposit_message;
/** \var m_household_bank_update_deposit * household_bank_update_deposit_message
* \brief Pointer to message struct for looping through household_bank_update_deposit message list */
m_household_bank_update_deposit * household_bank_update_deposit_message;
/** \var m_interest_rate * interest_rate_message
* \brief Pointer to message struct for looping through interest_rate message list */
m_interest_rate * interest_rate_message;
/** \var m_buy * buy_message
* \brief Pointer to message struct for looping through buy message list */
m_buy * buy_message;
/** \var m_bought * bought_message
* \brief Pointer to message struct for looping through bought message list */
m_bought * bought_message;
/** \var m_sell * sell_message
* \brief Pointer to message struct for looping through sell message list */
m_sell * sell_message;
/** \var m_sold * sold_message
* \brief Pointer to message struct for looping through sold message list */
m_sold * sold_message;
/** \var m_goods_transactions_summary * goods_transactions_summary_message
* \brief Pointer to message struct for looping through goods_transactions_summary message list */
m_goods_transactions_summary * goods_transactions_summary_message;
/** \var m_fired * fired_message
* \brief Pointer to message struct for looping through fired message list */
m_fired * fired_message;
/** \var m_vacancy_stage1 * vacancy_stage1_message
* \brief Pointer to message struct for looping through vacancy_stage1 message list */
m_vacancy_stage1 * vacancy_stage1_message;
/** \var m_job_application_stage2 * job_application_stage2_message
* \brief Pointer to message struct for looping through job_application_stage2 message list */
m_job_application_stage2 * job_application_stage2_message;
/** \var m_job_application_stage1 * job_application_stage1_message
* \brief Pointer to message struct for looping through job_application_stage1 message list */
m_job_application_stage1 * job_application_stage1_message;
/** \var m_job_match_stage1 * job_match_stage1_message
* \brief Pointer to message struct for looping through job_match_stage1 message list */
m_job_match_stage1 * job_match_stage1_message;
/** \var m_job_change * job_change_message
* \brief Pointer to message struct for looping through job_change message list */
m_job_change * job_change_message;
/** \var m_vacancy_stage2 * vacancy_stage2_message
* \brief Pointer to message struct for looping through vacancy_stage2 message list */
m_vacancy_stage2 * vacancy_stage2_message;
/** \var m_job_match_stage2 * job_match_stage2_message
* \brief Pointer to message struct for looping through job_match_stage2 message list */
m_job_match_stage2 * job_match_stage2_message;
/** \var m_employment_status * employment_status_message
* \brief Pointer to message struct for looping through employment_status message list */
m_employment_status * employment_status_message;
/** \var m_loan_request_1 * loan_request_1_message
* \brief Pointer to message struct for looping through loan_request_1 message list */
m_loan_request_1 * loan_request_1_message;
/** \var m_loan_request_2 * loan_request_2_message
* \brief Pointer to message struct for looping through loan_request_2 message list */
m_loan_request_2 * loan_request_2_message;
/** \var m_loan_acknowledge_1 * loan_acknowledge_1_message
* \brief Pointer to message struct for looping through loan_acknowledge_1 message list */
m_loan_acknowledge_1 * loan_acknowledge_1_message;
/** \var m_loan_acknowledge_2 * loan_acknowledge_2_message
* \brief Pointer to message struct for looping through loan_acknowledge_2 message list */
m_loan_acknowledge_2 * loan_acknowledge_2_message;
/** \var m_debt_request * debt_request_message
* \brief Pointer to message struct for looping through debt_request message list */
m_debt_request * debt_request_message;
/** \var m_debt_ack * debt_ack_message
* \brief Pointer to message struct for looping through debt_ack message list */
m_debt_ack * debt_ack_message;
/** \var m_household_share * household_share_message
* \brief Pointer to message struct for looping through household_share message list */
m_household_share * household_share_message;
/** \var m_capital_tax * capital_tax_message
* \brief Pointer to message struct for looping through capital_tax message list */
m_capital_tax * capital_tax_message;
/** \var m_labour_tax * labour_tax_message
* \brief Pointer to message struct for looping through labour_tax message list */
m_labour_tax * labour_tax_message;
/** \var m_unemployment_benefit * unemployment_benefit_message
* \brief Pointer to message struct for looping through unemployment_benefit message list */
m_unemployment_benefit * unemployment_benefit_message;
/** \var m_general_benefit * general_benefit_message
* \brief Pointer to message struct for looping through general_benefit message list */
m_general_benefit * general_benefit_message;
/** \var m_tax_rate * tax_rate_message
* \brief Pointer to message struct for looping through tax_rate message list */
m_tax_rate * tax_rate_message;
/** \var m_fund_request * fund_request_message
* \brief Pointer to message struct for looping through fund_request message list */
m_fund_request * fund_request_message;
/** \var m_fund_request_ack * fund_request_ack_message
* \brief Pointer to message struct for looping through fund_request_ack message list */
m_fund_request_ack * fund_request_ack_message;
/** \var m_new_entrant_loan * new_entrant_loan_message
* \brief Pointer to message struct for looping through new_entrant_loan message list */
m_new_entrant_loan * new_entrant_loan_message;
/** \var m_interest_on_loan * interest_on_loan_message
* \brief Pointer to message struct for looping through interest_on_loan message list */
m_interest_on_loan * interest_on_loan_message;
/** \var m_loan_writeoff * loan_writeoff_message
* \brief Pointer to message struct for looping through loan_writeoff message list */
m_loan_writeoff * loan_writeoff_message;
/** \var m_firm_net_profit * firm_net_profit_message
* \brief Pointer to message struct for looping through firm_net_profit message list */
m_firm_net_profit * firm_net_profit_message;
/** \var m_bank_net_profit * bank_net_profit_message
* \brief Pointer to message struct for looping through bank_net_profit message list */
m_bank_net_profit * bank_net_profit_message;
/** \var m_housing_price * housing_price_message
* \brief Pointer to message struct for looping through housing_price message list */
m_housing_price * housing_price_message;
/** \var m_buy_housing * buy_housing_message
* \brief Pointer to message struct for looping through buy_housing message list */
m_buy_housing * buy_housing_message;
/** \var m_sell_housing * sell_housing_message
* \brief Pointer to message struct for looping through sell_housing message list */
m_sell_housing * sell_housing_message;
/** \var m_bought_housing * bought_housing_message
* \brief Pointer to message struct for looping through bought_housing message list */
m_bought_housing * bought_housing_message;
/** \var m_sold_housing * sold_housing_message
* \brief Pointer to message struct for looping through sold_housing message list */
m_sold_housing * sold_housing_message;
/** \var m_mortgaging_capacity * mortgaging_capacity_message
* \brief Pointer to message struct for looping through mortgaging_capacity message list */
m_mortgaging_capacity * mortgaging_capacity_message;
/** \var m_mortgage_requests * mortgage_requests_message
* \brief Pointer to message struct for looping through mortgage_requests message list */
m_mortgage_requests * mortgage_requests_message;
/** \var m_mortgage_payment_from_sale * mortgage_payment_from_sale_message
* \brief Pointer to message struct for looping through mortgage_payment_from_sale message list */
m_mortgage_payment_from_sale * mortgage_payment_from_sale_message;
/** \var m_mortgage_payment * mortgage_payment_message
* \brief Pointer to message struct for looping through mortgage_payment message list */
m_mortgage_payment * mortgage_payment_message;
/** \var m_mortgage_writeoff * mortgage_writeoff_message
* \brief Pointer to message struct for looping through mortgage_writeoff message list */
m_mortgage_writeoff * mortgage_writeoff_message;
/** \var m_housing_transactions_summary * housing_transactions_summary_message
* \brief Pointer to message struct for looping through housing_transactions_summary message list */
m_housing_transactions_summary * housing_transactions_summary_message;
/** \var FLAME_output ** FLAME_outputs
* \brief Pointer to list of outputs */
FLAME_output * FLAME_outputs;
/** \var node_information * p_node_info
* \brief Pointer to first pointer of node list */
node_information ** p_node_info;
/** \var node_information * current_node
* \brief Pointer to current node */
node_information * current_node;

/** \var int iteration_loop
* \brief The current iteration number */
int iteration_loop;
/** \var int output_frequency
* \brief Frequency to output results */
int output_frequency;
/** \var int output_offset
* \brief Offset to output results */
int output_offset;

/** \def SPINF
* \brief Dummy inf value for space partition data. */
#define SPINF 999999.123456
/** \def RELEASE
* \brief Used to kill an agent via 'return RELEASE;'. */
#define RELEASE 1
/** \def kill_me_now
* \brief Used to kill an agent via 'kill_me_now'. */
#define kill_me_now return 1

void initialise_pointers(void);
void initialise_unit_testing(void);
FLAME_output * add_FLAME_output(FLAME_output ** outputs);
void free_FLAME_outputs(FLAME_output ** outputs);
void add_location(double point, location ** p_location);
void freelocations(location ** p_location);
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz);
void clean_up(int code);
void propagate_agents(void);
void propagate_messages_init(void);
void propagate_messages_complete(void);
void create_partitions(char * filename, int * itno);
void free_node_info(void);
void free_agent(void);
void freexmachines(void);
/* model datatypes */

void init_transaction_array(transaction_array * array);
void reset_transaction_array(transaction_array * array);
void free_transaction_array(transaction_array * array);
void copy_transaction_array(transaction_array * from, transaction_array * to);
void add_transaction(transaction_array * array,  int quantity,  double avg_price);
void remove_transaction(transaction_array * array, int index);

void init_buyer_array(buyer_array * array);
void reset_buyer_array(buyer_array * array);
void free_buyer_array(buyer_array * array);
void copy_buyer_array(buyer_array * from, buyer_array * to);
void add_buyer(buyer_array * array,  int id,  double budget,  int recieved_quantity);
void remove_buyer(buyer_array * array, int index);

void init_seller_array(seller_array * array);
void reset_seller_array(seller_array * array);
void free_seller_array(seller_array * array);
void copy_seller_array(seller_array * from, seller_array * to);
void add_seller(seller_array * array,  int id,  double price,  int inventory);
void remove_seller(seller_array * array, int index);

void init_vacancy_array(vacancy_array * array);
void reset_vacancy_array(vacancy_array * array);
void free_vacancy_array(vacancy_array * array);
void copy_vacancy_array(vacancy_array * from, vacancy_array * to);
void add_vacancy(vacancy_array * array,  int id,  double wage);
void remove_vacancy(vacancy_array * array, int index);

void init_employee_array(employee_array * array);
void reset_employee_array(employee_array * array);
void free_employee_array(employee_array * array);
void copy_employee_array(employee_array * from, employee_array * to);
void add_employee(employee_array * array,  int id,  double wage);
void remove_employee(employee_array * array, int index);

void init_mortgage_array(mortgage_array * array);
void reset_mortgage_array(mortgage_array * array);
void free_mortgage_array(mortgage_array * array);
void copy_mortgage_array(mortgage_array * from, mortgage_array * to);
void add_mortgage(mortgage_array * array,  int bank_id,  double principal,  int quarters_left,  double quarterly_interest,  double quarterly_principal);
void remove_mortgage(mortgage_array * array, int index);

void init_loan_array(loan_array * array);
void reset_loan_array(loan_array * array);
void free_loan_array(loan_array * array);
void copy_loan_array(loan_array * from, loan_array * to);
void add_loan(loan_array * array,  int bank_id,  double amount);
void remove_loan(loan_array * array, int index);

void init_hbuyer_array(hbuyer_array * array);
void reset_hbuyer_array(hbuyer_array * array);
void free_hbuyer_array(hbuyer_array * array);
void copy_hbuyer_array(hbuyer_array * from, hbuyer_array * to);
void add_hbuyer(hbuyer_array * array,  int buyer_id,  int bank_id,  double liquidity,  double quarterly_income,  double quarterly_mortgage_paid);
void remove_hbuyer(hbuyer_array * array, int index);

void init_hseller_array(hseller_array * array);
void reset_hseller_array(hseller_array * array);
void free_hseller_array(hseller_array * array);
void copy_hseller_array(hseller_array * from, hseller_array * to);
void add_hseller(hseller_array * array,  int seller_id,  double price,  int quantity);
void remove_hseller(hseller_array * array, int index);

void init_hbank_array(hbank_array * array);
void reset_hbank_array(hbank_array * array);
void free_hbank_array(hbank_array * array);
void copy_hbank_array(hbank_array * from, hbank_array * to);
void add_hbank(hbank_array * array,  int id,  double equity,  double risky_assets,  double amount_mortgaged);
void remove_hbank(hbank_array * array, int index);

void init_int_static_array(/*@out@*/ int * array, int size);
void init_int_array(int_array * array);
void reset_int_array(int_array * array);
void free_int_array(int_array * array);
void copy_int_array(int_array * from, int_array * to);
//void sort_int_array(int_array array);
//int quicksort_int(int array, int elements);
void add_int(int_array * array, int new_int);
void remove_int(int_array * array, int index);
void print_int_array(int_array * array);
void init_float_static_array(float * array, int size);
void init_float_array(float_array * array);
void reset_float_array(float_array * array);
void free_float_array(float_array * array);
void copy_float_array(float_array * from, float_array * to);
//void sort_float_array(float_array array);
//int quicksort_float(float array, int elements);
void add_float(float_array * array, float new_float);
void remove_float(float_array * array, int index);
void print_float_array(float_array * array);
void init_double_static_array(/*@out@*/ double* array, int size);
void init_double_array(double_array * array);
void reset_double_array(double_array * array);
void free_double_array(double_array * array);
void copy_double_array(double_array * from, double_array * to);
//void sort_double_array(double_array array);
//int quicksort_double(double array, int elements);
void add_double(double_array * array, double new_double);
void remove_double(double_array * array, int index);
void print_double_array(double_array * array);
void init_char_static_array(/*@out@*/ char * array, int size);
void init_char_array(char_array * array);
void reset_char_array(char_array * array);
void free_char_array(char_array * array);
void copy_char_array(char_array * from, char_array * to);
void add_char(char_array * array, char new_char);
void remove_char(char_array * array, int index);
char * copy_array_to_str(char_array * array);
void print_char_array(char_array * array);
int idle(void);
/* xml.c */
int read_int_static_array(char * buffer, int buffer_size, int * j, int * int_static_array, int size);
int read_float_static_array(char * buffer, int buffer_size, int * j, float * float_static_array, int size);
int read_double_static_array(char * buffer, int buffer_size, int * j, double * double_static_array, int size);
int read_char_static_array(char * buffer, int buffer_size, int * j, char * char_static_array, int size);
int read_int_dynamic_array(char * buffer, int buffer_size, int * j, int_array * int_dynamic_array);
int read_float_dynamic_array(char * buffer, int buffer_size, int * j, float_array * float_dynamic_array);
int read_double_dynamic_array(char * buffer, int buffer_size, int * j, double_array * double_dynamic_array);
int read_char_dynamic_array(char * buffer, int buffer_size, int * j, char_array * char_dynamic_array);

void init_transaction(/*@out@*/ transaction * temp);
void init_transaction_static_array(/*@out@*/ transaction * array, int size);
int read_transaction(char * buffer, int buffer_size, int * j, transaction * temp_datatype);
int read_transaction_dynamic_array(char * buffer, int buffer_size, int * j, transaction_array * temp_datatype_array);
int read_transaction_static_array(char * buffer, int buffer_size, int * j, transaction * temp_datatype_array, int size);
void write_transaction(FILE *file, transaction * temp_datatype);
void write_transaction_static_array(FILE *file, transaction * temp_datatype, int size);
void write_transaction_dynamic_array(FILE *file, transaction_array * temp_datatype);
void init_buyer(/*@out@*/ buyer * temp);
void init_buyer_static_array(/*@out@*/ buyer * array, int size);
int read_buyer(char * buffer, int buffer_size, int * j, buyer * temp_datatype);
int read_buyer_dynamic_array(char * buffer, int buffer_size, int * j, buyer_array * temp_datatype_array);
int read_buyer_static_array(char * buffer, int buffer_size, int * j, buyer * temp_datatype_array, int size);
void write_buyer(FILE *file, buyer * temp_datatype);
void write_buyer_static_array(FILE *file, buyer * temp_datatype, int size);
void write_buyer_dynamic_array(FILE *file, buyer_array * temp_datatype);
void init_seller(/*@out@*/ seller * temp);
void init_seller_static_array(/*@out@*/ seller * array, int size);
int read_seller(char * buffer, int buffer_size, int * j, seller * temp_datatype);
int read_seller_dynamic_array(char * buffer, int buffer_size, int * j, seller_array * temp_datatype_array);
int read_seller_static_array(char * buffer, int buffer_size, int * j, seller * temp_datatype_array, int size);
void write_seller(FILE *file, seller * temp_datatype);
void write_seller_static_array(FILE *file, seller * temp_datatype, int size);
void write_seller_dynamic_array(FILE *file, seller_array * temp_datatype);
void init_vacancy(/*@out@*/ vacancy * temp);
void init_vacancy_static_array(/*@out@*/ vacancy * array, int size);
int read_vacancy(char * buffer, int buffer_size, int * j, vacancy * temp_datatype);
int read_vacancy_dynamic_array(char * buffer, int buffer_size, int * j, vacancy_array * temp_datatype_array);
int read_vacancy_static_array(char * buffer, int buffer_size, int * j, vacancy * temp_datatype_array, int size);
void write_vacancy(FILE *file, vacancy * temp_datatype);
void write_vacancy_static_array(FILE *file, vacancy * temp_datatype, int size);
void write_vacancy_dynamic_array(FILE *file, vacancy_array * temp_datatype);
void init_employee(/*@out@*/ employee * temp);
void init_employee_static_array(/*@out@*/ employee * array, int size);
int read_employee(char * buffer, int buffer_size, int * j, employee * temp_datatype);
int read_employee_dynamic_array(char * buffer, int buffer_size, int * j, employee_array * temp_datatype_array);
int read_employee_static_array(char * buffer, int buffer_size, int * j, employee * temp_datatype_array, int size);
void write_employee(FILE *file, employee * temp_datatype);
void write_employee_static_array(FILE *file, employee * temp_datatype, int size);
void write_employee_dynamic_array(FILE *file, employee_array * temp_datatype);
void init_mortgage(/*@out@*/ mortgage * temp);
void init_mortgage_static_array(/*@out@*/ mortgage * array, int size);
int read_mortgage(char * buffer, int buffer_size, int * j, mortgage * temp_datatype);
int read_mortgage_dynamic_array(char * buffer, int buffer_size, int * j, mortgage_array * temp_datatype_array);
int read_mortgage_static_array(char * buffer, int buffer_size, int * j, mortgage * temp_datatype_array, int size);
void write_mortgage(FILE *file, mortgage * temp_datatype);
void write_mortgage_static_array(FILE *file, mortgage * temp_datatype, int size);
void write_mortgage_dynamic_array(FILE *file, mortgage_array * temp_datatype);
void init_loan(/*@out@*/ loan * temp);
void init_loan_static_array(/*@out@*/ loan * array, int size);
int read_loan(char * buffer, int buffer_size, int * j, loan * temp_datatype);
int read_loan_dynamic_array(char * buffer, int buffer_size, int * j, loan_array * temp_datatype_array);
int read_loan_static_array(char * buffer, int buffer_size, int * j, loan * temp_datatype_array, int size);
void write_loan(FILE *file, loan * temp_datatype);
void write_loan_static_array(FILE *file, loan * temp_datatype, int size);
void write_loan_dynamic_array(FILE *file, loan_array * temp_datatype);
void init_hbuyer(/*@out@*/ hbuyer * temp);
void init_hbuyer_static_array(/*@out@*/ hbuyer * array, int size);
int read_hbuyer(char * buffer, int buffer_size, int * j, hbuyer * temp_datatype);
int read_hbuyer_dynamic_array(char * buffer, int buffer_size, int * j, hbuyer_array * temp_datatype_array);
int read_hbuyer_static_array(char * buffer, int buffer_size, int * j, hbuyer * temp_datatype_array, int size);
void write_hbuyer(FILE *file, hbuyer * temp_datatype);
void write_hbuyer_static_array(FILE *file, hbuyer * temp_datatype, int size);
void write_hbuyer_dynamic_array(FILE *file, hbuyer_array * temp_datatype);
void init_hseller(/*@out@*/ hseller * temp);
void init_hseller_static_array(/*@out@*/ hseller * array, int size);
int read_hseller(char * buffer, int buffer_size, int * j, hseller * temp_datatype);
int read_hseller_dynamic_array(char * buffer, int buffer_size, int * j, hseller_array * temp_datatype_array);
int read_hseller_static_array(char * buffer, int buffer_size, int * j, hseller * temp_datatype_array, int size);
void write_hseller(FILE *file, hseller * temp_datatype);
void write_hseller_static_array(FILE *file, hseller * temp_datatype, int size);
void write_hseller_dynamic_array(FILE *file, hseller_array * temp_datatype);
void init_hbank(/*@out@*/ hbank * temp);
void init_hbank_static_array(/*@out@*/ hbank * array, int size);
int read_hbank(char * buffer, int buffer_size, int * j, hbank * temp_datatype);
int read_hbank_dynamic_array(char * buffer, int buffer_size, int * j, hbank_array * temp_datatype_array);
int read_hbank_static_array(char * buffer, int buffer_size, int * j, hbank * temp_datatype_array, int size);
void write_hbank(FILE *file, hbank * temp_datatype);
void write_hbank_static_array(FILE *file, hbank * temp_datatype, int size);
void write_hbank_dynamic_array(FILE *file, hbank_array * temp_datatype);

void readinitialstates(char * filename, char * filelocation, int * itno, double cloud_data[],
					   int partition_method, int flag);
void saveiterationdata(int iteration_number);

void free_transaction(transaction * temp);
void free_transaction_static_array(transaction * array, int size);
void copy_transaction(transaction * from, transaction * to);
void copy_transaction_static_array(transaction * from, transaction * to, int size);
void free_buyer(buyer * temp);
void free_buyer_static_array(buyer * array, int size);
void copy_buyer(buyer * from, buyer * to);
void copy_buyer_static_array(buyer * from, buyer * to, int size);
void free_seller(seller * temp);
void free_seller_static_array(seller * array, int size);
void copy_seller(seller * from, seller * to);
void copy_seller_static_array(seller * from, seller * to, int size);
void free_vacancy(vacancy * temp);
void free_vacancy_static_array(vacancy * array, int size);
void copy_vacancy(vacancy * from, vacancy * to);
void copy_vacancy_static_array(vacancy * from, vacancy * to, int size);
void free_employee(employee * temp);
void free_employee_static_array(employee * array, int size);
void copy_employee(employee * from, employee * to);
void copy_employee_static_array(employee * from, employee * to, int size);
void free_mortgage(mortgage * temp);
void free_mortgage_static_array(mortgage * array, int size);
void copy_mortgage(mortgage * from, mortgage * to);
void copy_mortgage_static_array(mortgage * from, mortgage * to, int size);
void free_loan(loan * temp);
void free_loan_static_array(loan * array, int size);
void copy_loan(loan * from, loan * to);
void copy_loan_static_array(loan * from, loan * to, int size);
void free_hbuyer(hbuyer * temp);
void free_hbuyer_static_array(hbuyer * array, int size);
void copy_hbuyer(hbuyer * from, hbuyer * to);
void copy_hbuyer_static_array(hbuyer * from, hbuyer * to, int size);
void free_hseller(hseller * temp);
void free_hseller_static_array(hseller * array, int size);
void copy_hseller(hseller * from, hseller * to);
void copy_hseller_static_array(hseller * from, hseller * to, int size);
void free_hbank(hbank * temp);
void free_hbank_static_array(hbank * array, int size);
void copy_hbank(hbank * from, hbank * to);
void copy_hbank_static_array(hbank * from, hbank * to, int size);

xmachine_memory_firm_state * init_firm_state();
xmachine_memory_firm * init_firm_agent();
void free_firm_agent(xmachine_memory_firm_holder * tmp, xmachine_memory_firm_state * state);
void transition_firm_agent(xmachine_memory_firm_holder * tmp, xmachine_memory_firm_state * from_state, xmachine_memory_firm_state * to_state);
void add_firm_agent_internal(xmachine_memory_firm * agent, xmachine_memory_firm_state * state);
void add_firm_agent(int id, int bank_id, int isconstructor, int day_of_month_to_act, int isinsolvent, int it_no, int day_of_week_to_act, double average_goods_price, int_array * employees, double wage_offer, double average_wage, int no_employees, int vacancies, int employees_needed, int day_of_month_wages_paid, double labour_productivity, int production_current, int production_estimate, int production_plan, double unit_goods_price, int day_of_month_production_completed, double unit_house_price, double labour_productivity_construction, double capital_productivity_construction, double capital_construction, double physical_capital, int projects[], double loans_interest_rate, double debt, int inventory, int sales, double revenue, double total_assets, double costs, double total_interest_payments, double dividends_paid, double dividends_retained, double earnings, double ebit, double equity, double liquidity, double capital_goods, int hasloan, int hasinvestment, double liquidity_need, loan loan_list[], double delta_housing_price);
void unittest_init_firm_agent();
void unittest_free_firm_agent();
xmachine_memory_household_state * init_household_state();
xmachine_memory_household * init_household_agent();
void free_household_agent(xmachine_memory_household_holder * tmp, xmachine_memory_household_state * state);
void transition_household_agent(xmachine_memory_household_holder * tmp, xmachine_memory_household_state * from_state, xmachine_memory_household_state * to_state);
void add_household_agent_internal(xmachine_memory_household * agent, xmachine_memory_household_state * state);
void add_household_agent(int id, int bank_id, int day_of_week_to_act, double weekly_consumption_budget, double consumption_budget, int my_employer_id, double wage, int day_of_month_to_act, int day_of_month_wage_recieved, double mortgages_interest_rate, double tax_rate, mortgage_array * mortgages_list, double mortgages, double housing_payment, double equity, double housing_price, int housing_units, int dividends, double liquidity, double fund_shares, int previous_wages[], int hmarket_role, double equity_ratio, double minimum_equity_ratio, double mortgage_costs[]);
void unittest_init_household_agent();
void unittest_free_household_agent();
xmachine_memory_equityfund_state * init_equityfund_state();
xmachine_memory_equityfund * init_equityfund_agent();
void free_equityfund_agent(xmachine_memory_equityfund_holder * tmp, xmachine_memory_equityfund_state * state);
void transition_equityfund_agent(xmachine_memory_equityfund_holder * tmp, xmachine_memory_equityfund_state * from_state, xmachine_memory_equityfund_state * to_state);
void add_equityfund_agent_internal(xmachine_memory_equityfund * agent, xmachine_memory_equityfund_state * state);
void add_equityfund_agent(int id, int day_of_month_to_act, double share_firms, double share_construction_firms, double share_banks, double equity, double liquidity, int n_dividends, double dividends_recieved, double dividends_retained, double dividends_paid, double firm_investment);
void unittest_init_equityfund_agent();
void unittest_free_equityfund_agent();
xmachine_memory_bank_state * init_bank_state();
xmachine_memory_bank * init_bank_agent();
void free_bank_agent(xmachine_memory_bank_holder * tmp, xmachine_memory_bank_state * state);
void transition_bank_agent(xmachine_memory_bank_holder * tmp, xmachine_memory_bank_state * from_state, xmachine_memory_bank_state * to_state);
void add_bank_agent_internal(xmachine_memory_bank * agent, xmachine_memory_bank_state * state);
void add_bank_agent(int id, int day_of_month_to_act, int day_of_week_to_act, double total_assets, double loans, double mortgages, double deposits, double centralbank_debt, double equity, double liquidity, double revenues, double total_writeoffs, double interests_accrued, double interests_paid, double dividends_paid, double total_dividends, double retained_earnings, double net_earnings, double total_costs);
void unittest_init_bank_agent();
void unittest_free_bank_agent();
xmachine_memory_government_state * init_government_state();
xmachine_memory_government * init_government_agent();
void free_government_agent(xmachine_memory_government_holder * tmp, xmachine_memory_government_state * state);
void transition_government_agent(xmachine_memory_government_holder * tmp, xmachine_memory_government_state * from_state, xmachine_memory_government_state * to_state);
void add_government_agent_internal(xmachine_memory_government * agent, xmachine_memory_government_state * state);
void add_government_agent(int id, double average_wage, double unemployment_rate, int population_size, double debt, double equity, double liquidity, int day_of_month_to_act, double gov_tax_rate, double labour_tax_income, double capital_tax_income, double gov_general_benefit_rate, double gov_unemployment_rate, double general_benefits, double unemployment_benefits, double earnings, double expenditures);
void unittest_init_government_agent();
void unittest_free_government_agent();
xmachine_memory_centralbank_state * init_centralbank_state();
xmachine_memory_centralbank * init_centralbank_agent();
void free_centralbank_agent(xmachine_memory_centralbank_holder * tmp, xmachine_memory_centralbank_state * state);
void transition_centralbank_agent(xmachine_memory_centralbank_holder * tmp, xmachine_memory_centralbank_state * from_state, xmachine_memory_centralbank_state * to_state);
void add_centralbank_agent_internal(xmachine_memory_centralbank * agent, xmachine_memory_centralbank_state * state);
void add_centralbank_agent(int id, int day_of_month_to_act, double unemployment_rate, double consumption_goods_prices[], int day_of_week_to_act, transaction goods, double weekly_price_averages[], double interest_rate, double liquidity, double loans_banks, double loans_government, double fiat_money, double equity, double liquidity_banks, double liquidity_government, double total_assets, double total_writeoffs, double interests_accrued, double revenues, double net_earnings, double total_costs, transaction houses);
void unittest_init_centralbank_agent();
void unittest_free_centralbank_agent();
xmachine_memory_jpoffice_state * init_jpoffice_state();
xmachine_memory_jpoffice * init_jpoffice_agent();
void free_jpoffice_agent(xmachine_memory_jpoffice_holder * tmp, xmachine_memory_jpoffice_state * state);
void transition_jpoffice_agent(xmachine_memory_jpoffice_holder * tmp, xmachine_memory_jpoffice_state * from_state, xmachine_memory_jpoffice_state * to_state);
void add_jpoffice_agent_internal(xmachine_memory_jpoffice * agent, xmachine_memory_jpoffice_state * state);
void add_jpoffice_agent(int id, int day_of_month_to_act);
void unittest_init_jpoffice_agent();
void unittest_free_jpoffice_agent();
xmachine_memory_mall_state * init_mall_state();
xmachine_memory_mall * init_mall_agent();
void free_mall_agent(xmachine_memory_mall_holder * tmp, xmachine_memory_mall_state * state);
void transition_mall_agent(xmachine_memory_mall_holder * tmp, xmachine_memory_mall_state * from_state, xmachine_memory_mall_state * to_state);
void add_mall_agent_internal(xmachine_memory_mall * agent, xmachine_memory_mall_state * state);
void add_mall_agent(int id, int day_of_week_to_act, transaction goods_transactions);
void unittest_init_mall_agent();
void unittest_free_mall_agent();
xmachine_memory_reagency_state * init_reagency_state();
xmachine_memory_reagency * init_reagency_agent();
void free_reagency_agent(xmachine_memory_reagency_holder * tmp, xmachine_memory_reagency_state * state);
void transition_reagency_agent(xmachine_memory_reagency_holder * tmp, xmachine_memory_reagency_state * from_state, xmachine_memory_reagency_state * to_state);
void add_reagency_agent_internal(xmachine_memory_reagency * agent, xmachine_memory_reagency_state * state);
void add_reagency_agent(int id, int day_of_month_to_act, double mortgages_interest_rate, transaction housing_transactions);
void unittest_init_reagency_agent();
void unittest_free_reagency_agent();

void add_firm_bank_update_deposit_message(int bank_id, double amount);
m_firm_bank_update_deposit * add_firm_bank_update_deposit_message_internal(void);
m_firm_bank_update_deposit * get_first_firm_bank_update_deposit_message(void);
m_firm_bank_update_deposit * get_next_firm_bank_update_deposit_message(m_firm_bank_update_deposit * current);
void freefirm_bank_update_depositmessages(void);

void add_household_bank_update_deposit_message(int bank_id, double amount);
m_household_bank_update_deposit * add_household_bank_update_deposit_message_internal(void);
m_household_bank_update_deposit * get_first_household_bank_update_deposit_message(void);
m_household_bank_update_deposit * get_next_household_bank_update_deposit_message(m_household_bank_update_deposit * current);
void freehousehold_bank_update_depositmessages(void);

void add_interest_rate_message(double rate);
m_interest_rate * add_interest_rate_message_internal(void);
m_interest_rate * get_first_interest_rate_message(void);
m_interest_rate * get_next_interest_rate_message(m_interest_rate * current);
void freeinterest_ratemessages(void);

void add_buy_message(int id, double budget);
m_buy * add_buy_message_internal(void);
m_buy * get_first_buy_message(void);
m_buy * get_next_buy_message(m_buy * current);
void freebuymessages(void);

void add_bought_message(int id, double money_left, int recieved_quantity);
m_bought * add_bought_message_internal(void);
m_bought * get_first_bought_message(void);
m_bought * get_next_bought_message(m_bought * current);
void freeboughtmessages(void);

void add_sell_message(int id, double price, int inventory);
m_sell * add_sell_message_internal(void);
m_sell * get_first_sell_message(void);
m_sell * get_next_sell_message(m_sell * current);
void freesellmessages(void);

void add_sold_message(int id, int unsold_quantities);
m_sold * add_sold_message_internal(void);
m_sold * get_first_sold_message(void);
m_sold * get_next_sold_message(m_sold * current);
void freesoldmessages(void);

void add_goods_transactions_summary_message(int quantity, double avg_price);
m_goods_transactions_summary * add_goods_transactions_summary_message_internal(void);
m_goods_transactions_summary * get_first_goods_transactions_summary_message(void);
m_goods_transactions_summary * get_next_goods_transactions_summary_message(m_goods_transactions_summary * current);
void freegoods_transactions_summarymessages(void);

void add_fired_message(int employee_id);
m_fired * add_fired_message_internal(void);
m_fired * get_first_fired_message(void);
m_fired * get_next_fired_message(m_fired * current);
void freefiredmessages(void);

void add_vacancy_stage1_message(int employer_id, double wage);
m_vacancy_stage1 * add_vacancy_stage1_message_internal(void);
m_vacancy_stage1 * get_first_vacancy_stage1_message(void);
m_vacancy_stage1 * get_next_vacancy_stage1_message(m_vacancy_stage1 * current);
void freevacancy_stage1messages(void);

void add_job_application_stage2_message(int employee_id);
m_job_application_stage2 * add_job_application_stage2_message_internal(void);
m_job_application_stage2 * get_first_job_application_stage2_message(void);
m_job_application_stage2 * get_next_job_application_stage2_message(m_job_application_stage2 * current);
void freejob_application_stage2messages(void);

void add_job_application_stage1_message(int employee_id, double wage);
m_job_application_stage1 * add_job_application_stage1_message_internal(void);
m_job_application_stage1 * get_first_job_application_stage1_message(void);
m_job_application_stage1 * get_next_job_application_stage1_message(m_job_application_stage1 * current);
void freejob_application_stage1messages(void);

void add_job_match_stage1_message(int employer_id, int employee_id, double wage);
m_job_match_stage1 * add_job_match_stage1_message_internal(void);
m_job_match_stage1 * get_first_job_match_stage1_message(void);
m_job_match_stage1 * get_next_job_match_stage1_message(m_job_match_stage1 * current);
void freejob_match_stage1messages(void);

void add_job_change_message(int employer_id, int employee_id);
m_job_change * add_job_change_message_internal(void);
m_job_change * get_first_job_change_message(void);
m_job_change * get_next_job_change_message(m_job_change * current);
void freejob_changemessages(void);

void add_vacancy_stage2_message(int employer_id, double wage);
m_vacancy_stage2 * add_vacancy_stage2_message_internal(void);
m_vacancy_stage2 * get_first_vacancy_stage2_message(void);
m_vacancy_stage2 * get_next_vacancy_stage2_message(m_vacancy_stage2 * current);
void freevacancy_stage2messages(void);

void add_job_match_stage2_message(int employer_id, int employee_id, double wage);
m_job_match_stage2 * add_job_match_stage2_message_internal(void);
m_job_match_stage2 * get_first_job_match_stage2_message(void);
m_job_match_stage2 * get_next_job_match_stage2_message(m_job_match_stage2 * current);
void freejob_match_stage2messages(void);

void add_employment_status_message(int employer_id, double wage, int ndividends);
m_employment_status * add_employment_status_message_internal(void);
m_employment_status * get_first_employment_status_message(void);
m_employment_status * get_next_employment_status_message(m_employment_status * current);
void freeemployment_statusmessages(void);

void add_loan_request_1_message(int firm_id, int bank_id, double amount);
m_loan_request_1 * add_loan_request_1_message_internal(void);
m_loan_request_1 * get_first_loan_request_1_message(void);
m_loan_request_1 * get_next_loan_request_1_message(m_loan_request_1 * current);
void freeloan_request_1messages(void);

void add_loan_request_2_message(int firm_id, int bank_id, double amount);
m_loan_request_2 * add_loan_request_2_message_internal(void);
m_loan_request_2 * get_first_loan_request_2_message(void);
m_loan_request_2 * get_next_loan_request_2_message(m_loan_request_2 * current);
void freeloan_request_2messages(void);

void add_loan_acknowledge_1_message(int bank_id, int firm_id, double amount);
m_loan_acknowledge_1 * add_loan_acknowledge_1_message_internal(void);
m_loan_acknowledge_1 * get_first_loan_acknowledge_1_message(void);
m_loan_acknowledge_1 * get_next_loan_acknowledge_1_message(m_loan_acknowledge_1 * current);
void freeloan_acknowledge_1messages(void);

void add_loan_acknowledge_2_message(int bank_id, int firm_id, double amount);
m_loan_acknowledge_2 * add_loan_acknowledge_2_message_internal(void);
m_loan_acknowledge_2 * get_first_loan_acknowledge_2_message(void);
m_loan_acknowledge_2 * get_next_loan_acknowledge_2_message(m_loan_acknowledge_2 * current);
void freeloan_acknowledge_2messages(void);

void add_debt_request_message(int bank_id, double amount);
m_debt_request * add_debt_request_message_internal(void);
m_debt_request * get_first_debt_request_message(void);
m_debt_request * get_next_debt_request_message(m_debt_request * current);
void freedebt_requestmessages(void);

void add_debt_ack_message(int bank_id, double amount);
m_debt_ack * add_debt_ack_message_internal(void);
m_debt_ack * get_first_debt_ack_message(void);
m_debt_ack * get_next_debt_ack_message(m_debt_ack * current);
void freedebt_ackmessages(void);

void add_household_share_message(double amount);
m_household_share * add_household_share_message_internal(void);
m_household_share * get_first_household_share_message(void);
m_household_share * get_next_household_share_message(m_household_share * current);
void freehousehold_sharemessages(void);

void add_capital_tax_message(double amount);
m_capital_tax * add_capital_tax_message_internal(void);
m_capital_tax * get_first_capital_tax_message(void);
m_capital_tax * get_next_capital_tax_message(m_capital_tax * current);
void freecapital_taxmessages(void);

void add_labour_tax_message(double amount);
m_labour_tax * add_labour_tax_message_internal(void);
m_labour_tax * get_first_labour_tax_message(void);
m_labour_tax * get_next_labour_tax_message(m_labour_tax * current);
void freelabour_taxmessages(void);

void add_unemployment_benefit_message(double amount);
m_unemployment_benefit * add_unemployment_benefit_message_internal(void);
m_unemployment_benefit * get_first_unemployment_benefit_message(void);
m_unemployment_benefit * get_next_unemployment_benefit_message(m_unemployment_benefit * current);
void freeunemployment_benefitmessages(void);

void add_general_benefit_message(double amount);
m_general_benefit * add_general_benefit_message_internal(void);
m_general_benefit * get_first_general_benefit_message(void);
m_general_benefit * get_next_general_benefit_message(m_general_benefit * current);
void freegeneral_benefitmessages(void);

void add_tax_rate_message(double value);
m_tax_rate * add_tax_rate_message_internal(void);
m_tax_rate * get_first_tax_rate_message(void);
m_tax_rate * get_next_tax_rate_message(m_tax_rate * current);
void freetax_ratemessages(void);

void add_fund_request_message(int firm_id, double amount);
m_fund_request * add_fund_request_message_internal(void);
m_fund_request * get_first_fund_request_message(void);
m_fund_request * get_next_fund_request_message(m_fund_request * current);
void freefund_requestmessages(void);

void add_fund_request_ack_message(int firm_id, double amount);
m_fund_request_ack * add_fund_request_ack_message_internal(void);
m_fund_request_ack * get_first_fund_request_ack_message(void);
m_fund_request_ack * get_next_fund_request_ack_message(m_fund_request_ack * current);
void freefund_request_ackmessages(void);

void add_new_entrant_loan_message(int firm_id, int bank_id, double amount);
m_new_entrant_loan * add_new_entrant_loan_message_internal(void);
m_new_entrant_loan * get_first_new_entrant_loan_message(void);
m_new_entrant_loan * get_next_new_entrant_loan_message(m_new_entrant_loan * current);
void freenew_entrant_loanmessages(void);

void add_interest_on_loan_message(int bank_id, double amount);
m_interest_on_loan * add_interest_on_loan_message_internal(void);
m_interest_on_loan * get_first_interest_on_loan_message(void);
m_interest_on_loan * get_next_interest_on_loan_message(m_interest_on_loan * current);
void freeinterest_on_loanmessages(void);

void add_loan_writeoff_message(int bank_id, double amount);
m_loan_writeoff * add_loan_writeoff_message_internal(void);
m_loan_writeoff * get_first_loan_writeoff_message(void);
m_loan_writeoff * get_next_loan_writeoff_message(m_loan_writeoff * current);
void freeloan_writeoffmessages(void);

void add_firm_net_profit_message(int id, int isconstructor, double net_income);
m_firm_net_profit * add_firm_net_profit_message_internal(void);
m_firm_net_profit * get_first_firm_net_profit_message(void);
m_firm_net_profit * get_next_firm_net_profit_message(m_firm_net_profit * current);
void freefirm_net_profitmessages(void);

void add_bank_net_profit_message(int id, double net_income);
m_bank_net_profit * add_bank_net_profit_message_internal(void);
m_bank_net_profit * get_first_bank_net_profit_message(void);
m_bank_net_profit * get_next_bank_net_profit_message(m_bank_net_profit * current);
void freebank_net_profitmessages(void);

void add_housing_price_message(double price);
m_housing_price * add_housing_price_message_internal(void);
m_housing_price * get_first_housing_price_message(void);
m_housing_price * get_next_housing_price_message(m_housing_price * current);
void freehousing_pricemessages(void);

void add_buy_housing_message(int buyer_id, int bank_id, double liquidity, double quarterly_income, double quarterly_mortgage_paid);
m_buy_housing * add_buy_housing_message_internal(void);
m_buy_housing * get_first_buy_housing_message(void);
m_buy_housing * get_next_buy_housing_message(m_buy_housing * current);
void freebuy_housingmessages(void);

void add_sell_housing_message(int seller_id, double price, int quantity);
m_sell_housing * add_sell_housing_message_internal(void);
m_sell_housing * get_first_sell_housing_message(void);
m_sell_housing * get_next_sell_housing_message(m_sell_housing * current);
void freesell_housingmessages(void);

void add_bought_housing_message(int buyer_id, double liquidity_spent, double mortgage_used, double annuity);
m_bought_housing * add_bought_housing_message_internal(void);
m_bought_housing * get_first_bought_housing_message(void);
m_bought_housing * get_next_bought_housing_message(m_bought_housing * current);
void freebought_housingmessages(void);

void add_sold_housing_message(int seller_id, int quantity_sold, double price_sold);
m_sold_housing * add_sold_housing_message_internal(void);
m_sold_housing * get_first_sold_housing_message(void);
m_sold_housing * get_next_sold_housing_message(m_sold_housing * current);
void freesold_housingmessages(void);

void add_mortgaging_capacity_message(int bank_id, double equity, double risky_assets);
m_mortgaging_capacity * add_mortgaging_capacity_message_internal(void);
m_mortgaging_capacity * get_first_mortgaging_capacity_message(void);
m_mortgaging_capacity * get_next_mortgaging_capacity_message(m_mortgaging_capacity * current);
void freemortgaging_capacitymessages(void);

void add_mortgage_requests_message(int bank_id, double amount);
m_mortgage_requests * add_mortgage_requests_message_internal(void);
m_mortgage_requests * get_first_mortgage_requests_message(void);
m_mortgage_requests * get_next_mortgage_requests_message(m_mortgage_requests * current);
void freemortgage_requestsmessages(void);

void add_mortgage_payment_from_sale_message(int bank_id, double amount);
m_mortgage_payment_from_sale * add_mortgage_payment_from_sale_message_internal(void);
m_mortgage_payment_from_sale * get_first_mortgage_payment_from_sale_message(void);
m_mortgage_payment_from_sale * get_next_mortgage_payment_from_sale_message(m_mortgage_payment_from_sale * current);
void freemortgage_payment_from_salemessages(void);

void add_mortgage_payment_message(int bank_id, double interest, double principal);
m_mortgage_payment * add_mortgage_payment_message_internal(void);
m_mortgage_payment * get_first_mortgage_payment_message(void);
m_mortgage_payment * get_next_mortgage_payment_message(m_mortgage_payment * current);
void freemortgage_paymentmessages(void);

void add_mortgage_writeoff_message(int bank_id, double amount);
m_mortgage_writeoff * add_mortgage_writeoff_message_internal(void);
m_mortgage_writeoff * get_first_mortgage_writeoff_message(void);
m_mortgage_writeoff * get_next_mortgage_writeoff_message(m_mortgage_writeoff * current);
void freemortgage_writeoffmessages(void);

void add_housing_transactions_summary_message(int quantity, double avg_price);
m_housing_transactions_summary * add_housing_transactions_summary_message_internal(void);
m_housing_transactions_summary * get_first_housing_transactions_summary_message(void);
m_housing_transactions_summary * get_next_housing_transactions_summary_message(m_housing_transactions_summary * current);
void freehousing_transactions_summarymessages(void);


void set_id(int id);
int get_id();
void set_bank_id(int bank_id);
int get_bank_id();
void set_isconstructor(int isconstructor);
int get_isconstructor();
void set_day_of_month_to_act(int day_of_month_to_act);
int get_day_of_month_to_act();
void set_isinsolvent(int isinsolvent);
int get_isinsolvent();
void set_it_no(int it_no);
int get_it_no();
void set_day_of_week_to_act(int day_of_week_to_act);
int get_day_of_week_to_act();
void set_average_goods_price(double average_goods_price);
double get_average_goods_price();
int_array * get_employees();
void set_wage_offer(double wage_offer);
double get_wage_offer();
void set_average_wage(double average_wage);
double get_average_wage();
void set_no_employees(int no_employees);
int get_no_employees();
void set_vacancies(int vacancies);
int get_vacancies();
void set_employees_needed(int employees_needed);
int get_employees_needed();
void set_day_of_month_wages_paid(int day_of_month_wages_paid);
int get_day_of_month_wages_paid();
void set_labour_productivity(double labour_productivity);
double get_labour_productivity();
void set_production_current(int production_current);
int get_production_current();
void set_production_estimate(int production_estimate);
int get_production_estimate();
void set_production_plan(int production_plan);
int get_production_plan();
void set_unit_goods_price(double unit_goods_price);
double get_unit_goods_price();
void set_day_of_month_production_completed(int day_of_month_production_completed);
int get_day_of_month_production_completed();
void set_unit_house_price(double unit_house_price);
double get_unit_house_price();
void set_labour_productivity_construction(double labour_productivity_construction);
double get_labour_productivity_construction();
void set_capital_productivity_construction(double capital_productivity_construction);
double get_capital_productivity_construction();
void set_capital_construction(double capital_construction);
double get_capital_construction();
void set_physical_capital(double physical_capital);
double get_physical_capital();
int * get_projects();
void set_loans_interest_rate(double loans_interest_rate);
double get_loans_interest_rate();
void set_debt(double debt);
double get_debt();
void set_inventory(int inventory);
int get_inventory();
void set_sales(int sales);
int get_sales();
void set_revenue(double revenue);
double get_revenue();
void set_total_assets(double total_assets);
double get_total_assets();
void set_costs(double costs);
double get_costs();
void set_total_interest_payments(double total_interest_payments);
double get_total_interest_payments();
void set_dividends_paid(double dividends_paid);
double get_dividends_paid();
void set_dividends_retained(double dividends_retained);
double get_dividends_retained();
void set_earnings(double earnings);
double get_earnings();
void set_ebit(double ebit);
double get_ebit();
void set_equity(double equity);
double get_equity();
void set_liquidity(double liquidity);
double get_liquidity();
void set_capital_goods(double capital_goods);
double get_capital_goods();
void set_hasloan(int hasloan);
int get_hasloan();
void set_hasinvestment(int hasinvestment);
int get_hasinvestment();
void set_liquidity_need(double liquidity_need);
double get_liquidity_need();
loan * get_loan_list();
void set_delta_housing_price(double delta_housing_price);
double get_delta_housing_price();
void set_weekly_consumption_budget(double weekly_consumption_budget);
double get_weekly_consumption_budget();
void set_consumption_budget(double consumption_budget);
double get_consumption_budget();
void set_my_employer_id(int my_employer_id);
int get_my_employer_id();
void set_wage(double wage);
double get_wage();
void set_day_of_month_wage_recieved(int day_of_month_wage_recieved);
int get_day_of_month_wage_recieved();
void set_mortgages_interest_rate(double mortgages_interest_rate);
double get_mortgages_interest_rate();
void set_tax_rate(double tax_rate);
double get_tax_rate();
mortgage_array * get_mortgages_list();
void set_mortgages(double mortgages);
double get_mortgages();
void set_housing_payment(double housing_payment);
double get_housing_payment();
void set_housing_price(double housing_price);
double get_housing_price();
void set_housing_units(int housing_units);
int get_housing_units();
void set_dividends(int dividends);
int get_dividends();
void set_fund_shares(double fund_shares);
double get_fund_shares();
int * get_previous_wages();
void set_hmarket_role(int hmarket_role);
int get_hmarket_role();
void set_equity_ratio(double equity_ratio);
double get_equity_ratio();
void set_minimum_equity_ratio(double minimum_equity_ratio);
double get_minimum_equity_ratio();
double * get_mortgage_costs();
void set_share_firms(double share_firms);
double get_share_firms();
void set_share_construction_firms(double share_construction_firms);
double get_share_construction_firms();
void set_share_banks(double share_banks);
double get_share_banks();
void set_n_dividends(int n_dividends);
int get_n_dividends();
void set_dividends_recieved(double dividends_recieved);
double get_dividends_recieved();
void set_firm_investment(double firm_investment);
double get_firm_investment();
void set_loans(double loans);
double get_loans();
void set_deposits(double deposits);
double get_deposits();
void set_centralbank_debt(double centralbank_debt);
double get_centralbank_debt();
void set_revenues(double revenues);
double get_revenues();
void set_total_writeoffs(double total_writeoffs);
double get_total_writeoffs();
void set_interests_accrued(double interests_accrued);
double get_interests_accrued();
void set_interests_paid(double interests_paid);
double get_interests_paid();
void set_total_dividends(double total_dividends);
double get_total_dividends();
void set_retained_earnings(double retained_earnings);
double get_retained_earnings();
void set_net_earnings(double net_earnings);
double get_net_earnings();
void set_total_costs(double total_costs);
double get_total_costs();
void set_unemployment_rate(double unemployment_rate);
double get_unemployment_rate();
void set_population_size(int population_size);
int get_population_size();
void set_gov_tax_rate(double gov_tax_rate);
double get_gov_tax_rate();
void set_labour_tax_income(double labour_tax_income);
double get_labour_tax_income();
void set_capital_tax_income(double capital_tax_income);
double get_capital_tax_income();
void set_gov_general_benefit_rate(double gov_general_benefit_rate);
double get_gov_general_benefit_rate();
void set_gov_unemployment_rate(double gov_unemployment_rate);
double get_gov_unemployment_rate();
void set_general_benefits(double general_benefits);
double get_general_benefits();
void set_unemployment_benefits(double unemployment_benefits);
double get_unemployment_benefits();
void set_expenditures(double expenditures);
double get_expenditures();
double * get_consumption_goods_prices();
transaction * get_goods();
double * get_weekly_price_averages();
void set_interest_rate(double interest_rate);
double get_interest_rate();
void set_loans_banks(double loans_banks);
double get_loans_banks();
void set_loans_government(double loans_government);
double get_loans_government();
void set_fiat_money(double fiat_money);
double get_fiat_money();
void set_liquidity_banks(double liquidity_banks);
double get_liquidity_banks();
void set_liquidity_government(double liquidity_government);
double get_liquidity_government();
transaction * get_houses();
transaction * get_goods_transactions();
transaction * get_housing_transactions();
int agent_get_id(void);
double agent_get_x(void);
double agent_get_y(void);
double agent_get_z(void);
/* partitioning.c */
void partition_data(int totalnodes, xmachine ** agent_list, double cloud_data[], int partition_method);


void save_partition_data(void);
void generate_partitions(double cloud_data[], int partitions, int partition_method);

/* messageboard.c */
m_firm_bank_update_deposit * get_next_message_firm_bank_update_deposit_in_range(m_firm_bank_update_deposit * current);



m_household_bank_update_deposit * get_next_message_household_bank_update_deposit_in_range(m_household_bank_update_deposit * current);



m_interest_rate * get_next_message_interest_rate_in_range(m_interest_rate * current);



m_buy * get_next_message_buy_in_range(m_buy * current);



m_bought * get_next_message_bought_in_range(m_bought * current);



m_sell * get_next_message_sell_in_range(m_sell * current);



m_sold * get_next_message_sold_in_range(m_sold * current);



m_goods_transactions_summary * get_next_message_goods_transactions_summary_in_range(m_goods_transactions_summary * current);



m_fired * get_next_message_fired_in_range(m_fired * current);



m_vacancy_stage1 * get_next_message_vacancy_stage1_in_range(m_vacancy_stage1 * current);



m_job_application_stage2 * get_next_message_job_application_stage2_in_range(m_job_application_stage2 * current);



m_job_application_stage1 * get_next_message_job_application_stage1_in_range(m_job_application_stage1 * current);



m_job_match_stage1 * get_next_message_job_match_stage1_in_range(m_job_match_stage1 * current);



m_job_change * get_next_message_job_change_in_range(m_job_change * current);



m_vacancy_stage2 * get_next_message_vacancy_stage2_in_range(m_vacancy_stage2 * current);



m_job_match_stage2 * get_next_message_job_match_stage2_in_range(m_job_match_stage2 * current);



m_employment_status * get_next_message_employment_status_in_range(m_employment_status * current);



m_loan_request_1 * get_next_message_loan_request_1_in_range(m_loan_request_1 * current);



m_loan_request_2 * get_next_message_loan_request_2_in_range(m_loan_request_2 * current);



m_loan_acknowledge_1 * get_next_message_loan_acknowledge_1_in_range(m_loan_acknowledge_1 * current);



m_loan_acknowledge_2 * get_next_message_loan_acknowledge_2_in_range(m_loan_acknowledge_2 * current);



m_debt_request * get_next_message_debt_request_in_range(m_debt_request * current);



m_debt_ack * get_next_message_debt_ack_in_range(m_debt_ack * current);



m_household_share * get_next_message_household_share_in_range(m_household_share * current);



m_capital_tax * get_next_message_capital_tax_in_range(m_capital_tax * current);



m_labour_tax * get_next_message_labour_tax_in_range(m_labour_tax * current);



m_unemployment_benefit * get_next_message_unemployment_benefit_in_range(m_unemployment_benefit * current);



m_general_benefit * get_next_message_general_benefit_in_range(m_general_benefit * current);



m_tax_rate * get_next_message_tax_rate_in_range(m_tax_rate * current);



m_fund_request * get_next_message_fund_request_in_range(m_fund_request * current);



m_fund_request_ack * get_next_message_fund_request_ack_in_range(m_fund_request_ack * current);



m_new_entrant_loan * get_next_message_new_entrant_loan_in_range(m_new_entrant_loan * current);



m_interest_on_loan * get_next_message_interest_on_loan_in_range(m_interest_on_loan * current);



m_loan_writeoff * get_next_message_loan_writeoff_in_range(m_loan_writeoff * current);



m_firm_net_profit * get_next_message_firm_net_profit_in_range(m_firm_net_profit * current);



m_bank_net_profit * get_next_message_bank_net_profit_in_range(m_bank_net_profit * current);



m_housing_price * get_next_message_housing_price_in_range(m_housing_price * current);



m_buy_housing * get_next_message_buy_housing_in_range(m_buy_housing * current);



m_sell_housing * get_next_message_sell_housing_in_range(m_sell_housing * current);



m_bought_housing * get_next_message_bought_housing_in_range(m_bought_housing * current);



m_sold_housing * get_next_message_sold_housing_in_range(m_sold_housing * current);



m_mortgaging_capacity * get_next_message_mortgaging_capacity_in_range(m_mortgaging_capacity * current);



m_mortgage_requests * get_next_message_mortgage_requests_in_range(m_mortgage_requests * current);



m_mortgage_payment_from_sale * get_next_message_mortgage_payment_from_sale_in_range(m_mortgage_payment_from_sale * current);



m_mortgage_payment * get_next_message_mortgage_payment_in_range(m_mortgage_payment * current);



m_mortgage_writeoff * get_next_message_mortgage_writeoff_in_range(m_mortgage_writeoff * current);



m_housing_transactions_summary * get_next_message_housing_transactions_summary_in_range(m_housing_transactions_summary * current);




/* memory.c */
xmachine * add_xmachine(void);
double FLAME_get_environment_variable_ratio_liquidity();
double FLAME_get_environment_variable_consumption_adjustment_speed();
double FLAME_get_environment_variable_wealth_effect();
double FLAME_get_environment_variable_turnover_probability();
double FLAME_get_environment_variable_production_markup();
double FLAME_get_environment_variable_price_markup();
double FLAME_get_environment_variable_firm_memory_persistance();
double FLAME_get_environment_variable_ratio_debt_firm();
double FLAME_get_environment_variable_ratio_fiscal_policy();
double FLAME_get_environment_variable_ratio_capitalist_households();
double FLAME_get_environment_variable_inflation_target();
double FLAME_get_environment_variable_firms_minimum_equity_ratio();
double FLAME_get_environment_variable_firm_startup_leverage();
double FLAME_get_environment_variable_household_startup_leverage();
double FLAME_get_environment_variable_car_buffer_threshold();
double FLAME_get_environment_variable_housing_market_entrance_prob();
double FLAME_get_environment_variable_fire_sale_threshold();
double FLAME_get_environment_variable_household_budget_constraint();
double FLAME_get_environment_variable_capital_adequecy_ratio();
double FLAME_get_environment_variable_housing_price_up_rate();
double FLAME_get_environment_variable_housing_price_down_rate();
double FLAME_get_environment_variable_household_mortgage_writeoff_high();
double FLAME_get_environment_variable_household_mortgage_writeoff_low();


/* rules.c */
int FLAME_integer_in_array(int a, int * b, int size);

/* timing.c */
double get_time(void);

int firm_init(void);

int FLAME_condition_firm_idle_FirmUpdateDeposits_end(xmachine_memory_firm *a);
int firm_update_bank_account(void);
int FLAME_condition_firm_firm_update_bank_account_FirmUpdateDeposits_end(xmachine_memory_firm *a);

int FLAME_condition_firm_idle_FirmConsumptionStart_FirmHousingStart(xmachine_memory_firm *a);
int firm_consumption_supply(void);
int FLAME_condition_firm_firm_consumption_supply_FirmConsumptionStart_FirmRecieveSales(xmachine_memory_firm *a);
int firm_consumption_recieve_sales(void);
int FLAME_filter_firm_firm_consumption_recieve_sales_FirmRecieveSales_FirmConsumptionPrice_sold(const void *msg, const void *params);
int firm_consumption_update_market_price(void);

int FLAME_condition_firm_idle_FirmLabourStart_FirmLabourPayWages(xmachine_memory_firm *a);
int firm_labour_workforce_needed(void);
int FLAME_condition_firm_firm_labour_workforce_needed_FirmLabourStart_FirmLabourStage1(xmachine_memory_firm *a);

int FLAME_condition_firm_idle_FirmLabourStage1_FirmLabourStage1End(xmachine_memory_firm *a);
int firm_labour_fire(void);
int FLAME_condition_firm_firm_labour_fire_FirmLabourStage1_FirmLabourStage1End(xmachine_memory_firm *a);
int firm_labour_job_announcement_stage1(void);
int FLAME_condition_firm_firm_labour_job_announcement_stage1_FirmLabourStage1_FirmLabourStage1Application(xmachine_memory_firm *a);
int firm_labour_job_offer_stage1(void);
int FLAME_filter_firm_firm_labour_job_offer_stage1_FirmLabourStage1Application_FirmLabourStage1End_job_match_stage1(const void *msg, const void *params);
int firm_labour_update(void);
int FLAME_filter_firm_firm_labour_update_FirmLabourStage1End_FirmLabourStage2_job_change(const void *msg, const void *params);
int firm_labour_job_announcement_stage2(void);
int FLAME_condition_firm_firm_labour_job_announcement_stage2_FirmLabourStage2_FirmLabourStage2End(xmachine_memory_firm *a);

int FLAME_condition_firm_idle_FirmLabourStage2_FirmLabourPayWages(xmachine_memory_firm *a);
int firm_labour_job_offer_stage2(void);
int FLAME_filter_firm_firm_labour_job_offer_stage2_FirmLabourStage2End_FirmLabourPayWages_job_match_stage2(const void *msg, const void *params);

int FLAME_condition_firm_idle_FirmLabourPayWages_FirmConsumptionStart(xmachine_memory_firm *a);
int firm_labour_pay_wages(void);
int FLAME_condition_firm_firm_labour_pay_wages_FirmLabourPayWages_FirmLabourWageAdjustment(xmachine_memory_firm *a);
int firm_labour_trace_wages(void);

int FLAME_condition_firm_idle_FirmProductionStart_FirmLabourStart(xmachine_memory_firm *a);

int FLAME_condition_firm_idle_FirmProductionStart_FirmProductionSkip(xmachine_memory_firm *a);
int firm_production_skip(void);
int FLAME_condition_firm_firm_production_skip_FirmProductionSkip_FirmLabourStart(xmachine_memory_firm *a);

int FLAME_condition_firm_idle_FirmProductionSkip_FirmProductionRoleCheck(xmachine_memory_firm *a);

int FLAME_condition_firm_idle_FirmProductionRoleCheck_FirmProductionRegular(xmachine_memory_firm *a);

int FLAME_condition_firm_idle_FirmProductionRoleCheck_FirmProductionConstructor(xmachine_memory_firm *a);
int firm_production_produce_goods(void);
int FLAME_condition_firm_firm_production_produce_goods_FirmProductionRegular_FirmLabourStart(xmachine_memory_firm *a);
int firm_production_set_price(void);
int FLAME_condition_firm_firm_production_set_price_FirmProductionRegular_FirmProductionPlanning(xmachine_memory_firm *a);
int firm_production_plan(void);
int firm_production_compute_labour_demand(void);
int firm_production_construct_houses(void);
int FLAME_condition_firm_firm_production_construct_houses_FirmProductionConstructor_FirmLabourStart(xmachine_memory_firm *a);
int firm_production_construction_plan(void);
int FLAME_condition_firm_firm_production_construction_plan_FirmProductionConstructor_FirmConstructionLabourDemand(xmachine_memory_firm *a);
int firm_production_construction_labour_demand(void);

int FLAME_condition_firm_idle_FirmCreditStart_FirmProductionStart(xmachine_memory_firm *a);
int firm_credit_check_interest_rate(void);
int FLAME_condition_firm_firm_credit_check_interest_rate_FirmCreditStart_FirmCreditLiquidityNeed(xmachine_memory_firm *a);
int firm_credit_check_liquidity_need(void);

int FLAME_condition_firm_idle_FirmCreditStatus_FirmCreditDividendPayments(xmachine_memory_firm *a);

int FLAME_condition_firm_idle_FirmCreditStatus_FirmCreditLoanRequest(xmachine_memory_firm *a);

int FLAME_condition_firm_idle_FirmCreditLoanRequest_FirmCreditInsolvency(xmachine_memory_firm *a);
int firm_credit_demand_loans_1(void);
int FLAME_condition_firm_firm_credit_demand_loans_1_FirmCreditLoanRequest_FirmCreditLoanBorrow1(xmachine_memory_firm *a);
int firm_credit_borrow_loans_1(void);
int FLAME_filter_firm_firm_credit_borrow_loans_1_FirmCreditLoanBorrow1_FirmCreditLoanBorrow2_loan_acknowledge_1(const void *msg, const void *params);

int FLAME_condition_firm_idle_FirmCreditLoanBorrow2_FirmCreditDividendPayments(xmachine_memory_firm *a);
int firm_credit_borrow_loans_2(void);
int FLAME_condition_firm_firm_credit_borrow_loans_2_FirmCreditLoanBorrow2_FirmCreditIlliquidityStatus(xmachine_memory_firm *a);
int FLAME_filter_firm_firm_credit_borrow_loans_2_FirmCreditLoanBorrow2_FirmCreditIlliquidityStatus_loan_acknowledge_2(const void *msg, const void *params);

int FLAME_condition_firm_idle_FirmCreditIlliquidityStatus_FirmCreditDividendPayments(xmachine_memory_firm *a);
int firm_credit_request_investment(void);
int FLAME_condition_firm_firm_credit_request_investment_FirmCreditIlliquidityStatus_FirmCreditCheckInvestment(xmachine_memory_firm *a);
int firm_credit_check_investment(void);
int FLAME_filter_firm_firm_credit_check_investment_FirmCreditCheckInvestment_FirmCreditBankruptcy_fund_request_ack(const void *msg, const void *params);

int FLAME_condition_firm_idle_FirmCreditBankruptcy_FirmCreditLoanPayment(xmachine_memory_firm *a);
int firm_credit_illiquidity_bankrupt(void);
int FLAME_condition_firm_firm_credit_illiquidity_bankrupt_FirmCreditBankruptcy_FirmCreditIncomeStatement(xmachine_memory_firm *a);
int firm_credit_exit_market(void);
int firm_credit_distribute_net_profit(void);
int firm_credit_pay_interest_on_loans(void);
int firm_credit_compute_income_statement(void);
int firm_credit_do_balance_sheet(void);

int FLAME_condition_firm_idle_FirmHousingStart_FirmUpdateDeposits(xmachine_memory_firm *a);

int FLAME_condition_firm_idle_FirmHousingStart_FirmHousingMarket(xmachine_memory_firm *a);

int FLAME_condition_firm_idle_FirmHousingMarket_FirmUpdateDeposits(xmachine_memory_firm *a);
int firm_housing_enter_market(void);
int FLAME_condition_firm_firm_housing_enter_market_FirmHousingMarket_FirmHousingSell(xmachine_memory_firm *a);
int firm_housing_collect_sale_revenues(void);
int FLAME_filter_firm_firm_housing_collect_sale_revenues_FirmHousingSell_FirmHousingPrice_sold_housing(const void *msg, const void *params);
int firm_housing_update_market_price(void);
int household_init(void);

int FLAME_condition_household_idle_HouseholdUpdateDeposits_end(xmachine_memory_household *a);
int household_update_bank_account(void);
int FLAME_condition_household_household_update_bank_account_HouseholdUpdateDeposits_end(xmachine_memory_household *a);

int FLAME_condition_household_idle_HHConsumptionStart_HHConsumptionWeekly(xmachine_memory_household *a);
int household_consumption_monthly_budget(void);
int FLAME_condition_household_household_consumption_monthly_budget_HHConsumptionStart_HHConsumptionWeekly(xmachine_memory_household *a);

int FLAME_condition_household_idle_HHConsumptionWeekly_HHHousingStart(xmachine_memory_household *a);
int household_consumption_demand(void);
int FLAME_condition_household_household_consumption_demand_HHConsumptionWeekly_HHConsumptionRecieveGoods(xmachine_memory_household *a);
int household_consumption_recieve_goods(void);
int FLAME_filter_household_household_consumption_recieve_goods_HHConsumptionRecieveGoods_HHHousingStart_bought(const void *msg, const void *params);

int FLAME_condition_household_idle_HHLabourStart_HHLabourEmploymentStatus(xmachine_memory_household *a);
int household_labour_check_fired(void);
int FLAME_condition_household_household_labour_check_fired_HHLabourStart_HHLabourStage1(xmachine_memory_household *a);
int FLAME_filter_household_household_labour_check_fired_HHLabourStart_HHLabourStage1_fired(const void *msg, const void *params);
int household_labour_reemployment_application(void);
int FLAME_condition_household_household_labour_reemployment_application_HHLabourStage1_HHLabourStage2(xmachine_memory_household *a);

int FLAME_condition_household_idle_HHLabourStage1_HHLabourStage1Applications(xmachine_memory_household *a);
int household_labour_turnover(void);
int FLAME_filter_household_household_labour_turnover_HHLabourStage2_HHLabourEmploymentStatus_job_match_stage1(const void *msg, const void *params);
int household_labour_employment_application(void);
int household_labour_employment(void);
int FLAME_filter_household_household_labour_employment_HHLabourStage1Placement_HHLabourEmploymentStatus_job_match_stage2(const void *msg, const void *params);
int household_labour_report_status(void);

int FLAME_condition_household_idle_HHLabourPayroll_HHConsumptionStart(xmachine_memory_household *a);
int household_labour_recieve_wage(void);
int FLAME_condition_household_household_labour_recieve_wage_HHLabourPayroll_HHConsumptionStart(xmachine_memory_household *a);

int FLAME_condition_household_idle_HHCreditStart_HHCreditMonthly(xmachine_memory_household *a);
int household_credit_check_interest_rate(void);
int FLAME_condition_household_household_credit_check_interest_rate_HHCreditStart_HHCreditCheckTax(xmachine_memory_household *a);
int household_credit_check_tax_rate(void);
int household_credit_update_mortgage_rates(void);

int FLAME_condition_household_idle_HHCreditIsCapitalist_HHCreditBalanceSheet(xmachine_memory_household *a);
int household_credit_collect_shares(void);
int FLAME_condition_household_household_credit_collect_shares_HHCreditIsCapitalist_HHCreditCapitalTax(xmachine_memory_household *a);
int household_credit_pay_capital_tax(void);
int household_credit_do_balance_sheet(void);

int FLAME_condition_household_idle_HHCreditMonthly_HHLabourStart(xmachine_memory_household *a);
int household_credit_collect_benefits(void);
int FLAME_condition_household_household_credit_collect_benefits_HHCreditMonthly_HHCreditEmployment(xmachine_memory_household *a);
int household_credit_collect_unemployment(void);
int FLAME_condition_household_household_credit_collect_unemployment_HHCreditEmployment_HHLabourStart(xmachine_memory_household *a);
int household_credit_pay_labour_tax(void);
int FLAME_condition_household_household_credit_pay_labour_tax_HHCreditEmployment_HHLabourStart(xmachine_memory_household *a);

int FLAME_condition_household_idle_HHHousingStart_HouseholdUpdateDeposits(xmachine_memory_household *a);
int household_housing_market_role(void);
int FLAME_condition_household_household_housing_market_role_HHHousingStart_HHHousingRole(xmachine_memory_household *a);

int FLAME_condition_household_idle_HHHousingRole_HHHousingPrice(xmachine_memory_household *a);
int household_housing_check_wealth(void);
int FLAME_condition_household_household_housing_check_wealth_HHHousingRole_HHHousingCheckWealth(xmachine_memory_household *a);
int household_housing_sell(void);
int FLAME_condition_household_household_housing_sell_HHHousingRole_HHHousingRevenue(xmachine_memory_household *a);
int household_housing_fire_sell(void);
int FLAME_condition_household_household_housing_fire_sell_HHHousingRole_HHHousingRevenue(xmachine_memory_household *a);
int household_housing_collect_sale_revenue(void);
int FLAME_filter_household_household_housing_collect_sale_revenue_HHHousingRevenue_HHHousingPrice_sold_housing(const void *msg, const void *params);

int FLAME_condition_household_idle_HHHousingCheckWealth_HHHousingPrice(xmachine_memory_household *a);
int household_housing_enter_market(void);
int FLAME_condition_household_household_housing_enter_market_HHHousingCheckWealth_HHHousingBargain(xmachine_memory_household *a);
int household_housing_buy(void);
int FLAME_filter_household_household_housing_buy_HHHousingBargain_HHHousingPrice_bought_housing(const void *msg, const void *params);
int household_housing_update_market_price(void);
int household_housing_pay_mortgages(void);
int household_housing_debt_writeoff(void);
int equityfund_init(void);

int FLAME_condition_equityfund_idle_EFLabourMarket_end(xmachine_memory_equityfund *a);
int equityfund_audit_dividends(void);
int FLAME_condition_equityfund_equityfund_audit_dividends_EFLabourMarket_end(xmachine_memory_equityfund *a);

int FLAME_condition_equityfund_idle_EquityFundStart_EFLabourMarket(xmachine_memory_equityfund *a);
int equityfund_credit_invest_illiquids(void);
int FLAME_condition_equityfund_equityfund_credit_invest_illiquids_EquityFundStart_EFCreditDistributeShares(xmachine_memory_equityfund *a);
int equityfund_credit_distribute_shares(void);
int equityfund_credit_collect_bank_shares(void);
int equityfund_credit_collect_firm_shares(void);
int equityfund_credit_do_balance_sheet(void);
int bank_init(void);

int FLAME_condition_bank_idle_BankUpdateDeposits_end(xmachine_memory_bank *a);
int bank_update_deposits(void);
int FLAME_condition_bank_bank_update_deposits_BankUpdateDeposits_end(xmachine_memory_bank *a);
int FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_end_household_bank_update_deposit(const void *msg, const void *params);
int FLAME_filter_bank_bank_update_deposits_BankUpdateDeposits_end_firm_bank_update_deposit(const void *msg, const void *params);

int FLAME_condition_bank_idle_BankCreditStart_BankHousingMarket(xmachine_memory_bank *a);
int bank_credit_process_loan_requests_1(void);
int FLAME_condition_bank_bank_credit_process_loan_requests_1_BankCreditStart_BankCreditRequest2(xmachine_memory_bank *a);
int FLAME_filter_bank_bank_credit_process_loan_requests_1_BankCreditStart_BankCreditRequest2_loan_request_1(const void *msg, const void *params);
int bank_credit_process_loan_requests_2(void);
int bank_credit_recieve_loan_writeoffs(void);
int FLAME_filter_bank_bank_credit_recieve_loan_writeoffs_BankCreditLoanWriteOffs_BankCreditNewEntrants_loan_writeoff(const void *msg, const void *params);
int bank_credit_recieve_new_entrant_loan_requests(void);
int FLAME_filter_bank_bank_credit_recieve_new_entrant_loan_requests_BankCreditNewEntrants_BankCreditLoanInterests_new_entrant_loan(const void *msg, const void *params);
int bank_credit_collect_loan_interests(void);
int FLAME_filter_bank_bank_credit_collect_loan_interests_BankCreditLoanInterests_BankCreditLiquidityNeed_interest_on_loan(const void *msg, const void *params);

int FLAME_condition_bank_idle_BankCreditLiquidityNeed_BankCreditIncomeStatement(xmachine_memory_bank *a);
int bank_credit_request_liquidity(void);
int FLAME_condition_bank_bank_credit_request_liquidity_BankCreditLiquidityNeed_BankCreditLiquidtyRecieve(xmachine_memory_bank *a);
int bank_credit_recieve_liquidity(void);
int FLAME_filter_bank_bank_credit_recieve_liquidity_BankCreditLiquidtyRecieve_BankCreditIncomeStatement_debt_ack(const void *msg, const void *params);
int bank_credit_compute_income_statement(void);
int bank_credit_compute_dividends(void);
int bank_credit_do_balance_sheet(void);

int FLAME_condition_bank_idle_BankHousingMarket_BankUpdateDeposits(xmachine_memory_bank *a);
int bank_housing_compute_capital_status(void);
int FLAME_condition_bank_bank_housing_compute_capital_status_BankHousingMarket_BankHousingCrediting(xmachine_memory_bank *a);
int bank_housing_deliver_mortages(void);
int FLAME_filter_bank_bank_housing_deliver_mortages_BankHousingCrediting_BankHousingSales_mortgage_requests(const void *msg, const void *params);
int bank_housing_recieve_mortgage_principals(void);
int FLAME_filter_bank_bank_housing_recieve_mortgage_principals_BankHousingSales_BankHousingMortgages_mortgage_payment_from_sale(const void *msg, const void *params);
int bank_housing_recieve_mortgages(void);
int FLAME_filter_bank_bank_housing_recieve_mortgages_BankHousingMortgages_BankHousingWriteOff_mortgage_payment(const void *msg, const void *params);
int bank_housing_debt_writeoff(void);
int FLAME_filter_bank_bank_housing_debt_writeoff_BankHousingWriteOff_BankUpdateDeposits_mortgage_writeoff(const void *msg, const void *params);
int government_init(void);
int government_trace_unemployment_status(void);

int FLAME_condition_government_idle_GovernmentStart_GovernmentMonthly(xmachine_memory_government *a);
int government_update_fiscal_policy(void);
int FLAME_condition_government_government_update_fiscal_policy_GovernmentStart_GovernmentCapitalTax(xmachine_memory_government *a);
int government_collect_capital_tax(void);
int government_compute_income_statement(void);
int government_do_balance_sheet(void);

int FLAME_condition_government_idle_GovernmentMonthly_end(xmachine_memory_government *a);
int government_distribute_general_benefits(void);
int FLAME_condition_government_government_distribute_general_benefits_GovernmentMonthly_GovernmentUnemploymentBenefits(xmachine_memory_government *a);
int government_distribute_unemployment_benefits(void);
int government_collect_labour_tax(void);
int centralbank_init(void);

int FLAME_condition_centralbank_idle_CentralBankConsumption_CentralBankHousing(xmachine_memory_centralbank *a);
int centralbank_trace_goods_prices(void);
int FLAME_condition_centralbank_centralbank_trace_goods_prices_CentralBankConsumption_CentralBankHousing(xmachine_memory_centralbank *a);

int FLAME_condition_centralbank_idle_CentralBankLabour_CentralBankConsumption(xmachine_memory_centralbank *a);
int centralbank_trace_unemployment_status(void);
int FLAME_condition_centralbank_centralbank_trace_unemployment_status_CentralBankLabour_CentralBankConsumption(xmachine_memory_centralbank *a);

int FLAME_condition_centralbank_idle_CentralBankCredit_CentralBankLabour(xmachine_memory_centralbank *a);
int centralbank_set_interest_rate(void);
int FLAME_condition_centralbank_centralbank_set_interest_rate_CentralBankCredit_CentralBankDebtRequests(xmachine_memory_centralbank *a);
int centralbank_process_debt_requests(void);
int centralbank_compute_income_statement(void);
int centralbank_do_balance_sheet(void);

int FLAME_condition_centralbank_idle_CentralBankHousing_end(xmachine_memory_centralbank *a);
int centralbank_trace_housing_prices(void);
int FLAME_condition_centralbank_centralbank_trace_housing_prices_CentralBankHousing_end(xmachine_memory_centralbank *a);
int jpoffice_init(void);

int FLAME_condition_jpoffice_idle_JPOLabourMarket_end(xmachine_memory_jpoffice *a);
int jpoffice_labour_stage1(void);
int FLAME_condition_jpoffice_jpoffice_labour_stage1_JPOLabourMarket_JPOLabourStage2(xmachine_memory_jpoffice *a);
int FLAME_sort_jpoffice_jpoffice_labour_stage1_JPOLabourMarket_JPOLabourStage2_vacancy_stage1();
int FLAME_sort_jpoffice_jpoffice_labour_stage1_JPOLabourMarket_JPOLabourStage2_job_application_stage1();
int jpoffice_labour_stage2(void);
int FLAME_sort_jpoffice_jpoffice_labour_stage2_JPOLabourStage2_end_vacancy_stage2();
int FLAME_sort_jpoffice_jpoffice_labour_stage2_JPOLabourStage2_end_job_application_stage2();
int mall_init(void);

int FLAME_condition_mall_idle_MallConsumptionMarket_end(xmachine_memory_mall *a);
int mall_consumption_shopping(void);
int FLAME_condition_mall_mall_consumption_shopping_MallConsumptionMarket_MallConsumptionSummary(xmachine_memory_mall *a);
int FLAME_sort_mall_mall_consumption_shopping_MallConsumptionMarket_MallConsumptionSummary_sell();
int mall_consumption_summary(void);
int reagency_init(void);

int FLAME_condition_reagency_idle_REAgencyHousingMarket_end(xmachine_memory_reagency *a);
int reagency_housing_check_interest_rate(void);
int FLAME_condition_reagency_reagency_housing_check_interest_rate_REAgencyHousingMarket_REAgencyHousingProcess(xmachine_memory_reagency *a);
int reagency_housing_process(void);
int FLAME_sort_reagency_reagency_housing_process_REAgencyHousingProcess_REAgencyHousingSummary_sell_housing();
int FLAME_sort_reagency_reagency_housing_process_REAgencyHousingProcess_REAgencyHousingSummary_mortgaging_capacity();
int reagency_housing_summary(void);
#endif
