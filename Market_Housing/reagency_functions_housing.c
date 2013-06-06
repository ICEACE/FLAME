#include "../header.h"
#include "../reagency_agent_header.h"
#include "../library_header.h"
#include <math.h> 

/*
 * \fn: int reagency_housing_process()
 * \brief: 
 */
int reagency_housing_process()
{
    /* Initialize **
     */
    
    /* Allocate housing buyer queues and seller listss.
     */
    hseller_array sellers_list;
    hbuyer_array buyers_list;
    hbank_array banks_list;
   
    
    /* Initialize */
    init_hseller_array(&sellers_list);
    init_hbuyer_array(&buyers_list);
    init_hbank_array(&banks_list);
    
 
    /* Collect sellers */
    int id;
    double price, quantity;
    START_SELL_HOUSING_MESSAGE_LOOP
        id = sell_housing_message->seller_id;
        price = sell_housing_message->price;
        quantity = sell_housing_message->quantity;
        add_hseller(&sellers_list, id, price, quantity);
	FINISH_SELL_HOUSING_MESSAGE_LOOP
    
    /* Queue the households */
    int bank;
    double money, income, mortgage;
    START_BUY_HOUSING_MESSAGE_LOOP
        id = buy_housing_message->buyer_id;
        bank = buy_housing_message->bank_id;
        money = buy_housing_message->liquidity;
        income = buy_housing_message->quarterly_income;
        mortgage = buy_housing_message->quarterly_mortgage_paid;
        add_hbuyer(&buyers_list,id,bank,money,income, mortgage);
	FINISH_BUY_HOUSING_MESSAGE_LOOP
    
    /* Queue the banks */
    double risk;
    START_MORTGAGING_CAPACITY_MESSAGE_LOOP
        id = mortgaging_capacity_message->bank_id;
        money = mortgaging_capacity_message->equity;
        risk = mortgaging_capacity_message->risky_assets;
        add_hbank(&banks_list, id, money, risk, 0);
	FINISH_MORTGAGING_CAPACITY_MESSAGE_LOOP
    
    
    if (sellers_list.size == 0 || buyers_list.size == 0) {
        /* Free seller list */
        free_hseller_array(&sellers_list);
        /* Free buyer queues */
        free_hbuyer_array(&buyers_list);
        /* Free bank list */
        free_hbank_array(&banks_list);
        return 0;
    }
    
    /* Do the matching *
     * Input assumptions:
     * sellers are sorted ascendingly by price.
     * buyers are randomly queued
     * this is done at message filtering stage.
     */
    
    //Compute annuity for possible mortgages.
    double annuity;
    double d1, d2;
    d1 = MORTGAGES_INTEREST_RATE/4;
    d2 = d1 * pow((1 + d1), 40);
    annuity = 1/d1 - 1/d2;
    
    int nsold = 0;
    do {
        if (sellers_list.size == 0 ){break;}
        if (buyers_list.size == 0 ){break;}
        
        quantity = sellers_list.array[0].quantity;
        id = sellers_list.array[0].seller_id;
        price = sellers_list.array[0].price;
        if (nsold == quantity){
            add_sold_housing_message(id, nsold, price);
            remove_hseller(&sellers_list, 0);
            nsold = 0;
            continue;
        }
        id = buyers_list.array[0].buyer_id;
        money = buyers_list.array[0].liquidity;
        if (money >= price) {
            add_bought_housing_message(id, price, 0, 0);
            nsold++;
            remove_hbuyer(&buyers_list, 0);
            continue;
        }
        
        /* The household needs mortgage
         */
        
        //No banks in the market is able to give mortgage credit.
        if (banks_list.size == 0 ){
            remove_hbuyer(&buyers_list, 0);
            continue;
        }
        /* Check lending possibility of the bank */
        bank = buyers_list.array[0].bank_id;
        int i = 0;
        int flag = 0;
        do {
            if (banks_list.array[i].id == bank){
                flag = 1;
                break;
            }
            i++;
        } while (i < banks_list.size);
        if (flag == 0){
            remove_hbuyer(&buyers_list, 0);
            continue;
        }
        double mortgage_request = price - money;
        // risky asssets before the market opened.
        risk = banks_list.array[i].risky_assets;
        // mortagages given so far at current round.
        risk += banks_list.array[i].amount_mortgaged;
        // after new requested mortgage.
        risk += mortgage_request;
        
        // equity before the round.
        double equity = banks_list.array[i].equity;
        // equity decreased at current round so far/
        equity -= banks_list.array[i].amount_mortgaged;
        // after new request.
        equity -= mortgage_request;
        
        if (equity < BANK_RISKY_ASSETS_RATIO * risk) {
            remove_hbuyer(&buyers_list, 0);
            remove_hbank(&banks_list, i);
            continue;
        }
        
        /* Check credibility of the household */
        income = buyers_list.array[0].quarterly_income;
        mortgage = buyers_list.array[0].quarterly_mortgage_paid;
        double new_mortgage_cost = mortgage_request / annuity;
        mortgage += new_mortgage_cost;
        
        if (mortgage > HOUSEHOLD_BUDGET_CONSTRAINT * income) {
            remove_hbuyer(&buyers_list, 0);
            continue;
        }
        
        /* Mortgage used */
        add_bought_housing_message(id, money, mortgage_request, annuity);
        remove_hbuyer(&buyers_list, 0);
        nsold++;
    } while (1);
    
    if (nsold > 0 && sellers_list.size > 0) {
        id = sellers_list.array[0].seller_id;
        add_sold_housing_message(id, nsold, price);
    }
    
    
    /* Garbage Collection */
    free_hseller_array(&sellers_list);
    free_hbuyer_array(&buyers_list);
    free_hbank_array(&banks_list);
	return 0; /* Returning zero means the agent is not removed */
}

