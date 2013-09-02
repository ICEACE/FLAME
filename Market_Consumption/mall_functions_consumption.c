#include "../header.h"
#include "../mall_agent_header.h"
#include "../library_header.h"

/*
 * \fn: int mall_consumption_shopping()
 * \brief:
 */
int mall_consumption_shopping()
{
    /* Initialize **
     */
    
    int firm_id, hh_id;
    double price, budget;
    int quantity, total_sold;

    double denominator;
    
    double min_price;
    int min_price_index;
    int min_price_is_picked;
    
    /* identifiers used to hold weekly transaction summary
     */
    
    int transaction_quantity = 0;
    double transaction_volume = 0;
    
    /* Allocate local buyer queues and seller lists.
     */
    seller_array sellers_list;
    buyer_array buyers_list;
    
    /* Initialize */
    init_seller_array(&sellers_list);
    init_buyer_array(&buyers_list);
    
    denominator = 0;
    min_price_is_picked = 0;
    /* Collect supply */
    START_SELL_MESSAGE_LOOP
    firm_id = sell_message->id;
    price = sell_message->price;
    
    if ( min_price_is_picked == 0){
        min_price = price;
        min_price_is_picked = 1;
        min_price_index = 0;
    }
    
    denominator += 1 / price;
    quantity = sell_message->inventory;
    /* Add to the shelve */
    add_seller(&sellers_list, firm_id, price, quantity);
	FINISH_SELL_MESSAGE_LOOP
    
    /* Queue the households */
    START_BUY_MESSAGE_LOOP
    hh_id = buy_message->id;
    budget = buy_message->budget;
    /* Add household to the queue */
    add_buyer(&buyers_list, hh_id, budget, 0);
	FINISH_BUY_MESSAGE_LOOP
    
    
    if (sellers_list.size == 0 || buyers_list.size == 0) {
        /* Free seller list */
        free_seller_array(&sellers_list);
        /* Free buyer queues */
        free_buyer_array(&buyers_list);
        return 0;
    }
    
    
    /* Do the matching *
     * Input assumptions:
     * sellers are sorted ascendingly by price.
     * buyers are randomly queued
     * this is done at message filtering stage.
     */
    double select_prob;
    double firm_select_prob, firm_select_prob_cum;
    int tmp,i,j;
    int sold_out = 0;
    for (i = 0; i < buyers_list.size; i++) {
        
        if (sold_out == sellers_list.size) { break; }
        
        budget = buyers_list.array[i].budget;
        if (budget < min_price) { continue; }
        /* Filtering out households with initially insufficient budgets.
         */
        
        select_prob = (double) random_int(0, sellers_list.size) / sellers_list.size;
        firm_select_prob_cum = 0;
        j = min_price_index;
        do {
            /* Filtering out households those who have spent their budget down below min price. */
            if (budget < min_price) { break; }

            /* No goods left to buy more. */
            if (sold_out == sellers_list.size) { break; }
            
            quantity = sellers_list.array[j].inventory;
            if (quantity == 0) {
            /* This is the case when goods right after min price goods have already been sold out. */
                if (j == min_price_index) {
                    min_price_index = j+1;
                }
                j++;
                continue;
            }
            
            price = sellers_list.array[j].price;
            if (budget < price) {
                /* Houshold (select_prob) desires something she/he cannot afford (any more).
                 Try finding a cheaper product by starting over.
                 Make sure that an affordable good is targeted.
                 */
                tmp = (int)firm_select_prob_cum * 100;
                select_prob = (double)random_int(0, tmp) / (tmp + 1);
                firm_select_prob_cum = 0;
                j = min_price_index;
                continue;
            }
            
            firm_select_prob = (1 / price) / denominator;
            firm_select_prob_cum += firm_select_prob;
            if ((firm_select_prob_cum - select_prob) >= 0){
                quantity = (int) floor(budget / price);
                if (quantity >= sellers_list.array[j].inventory) {
                    quantity = sellers_list.array[j].inventory;
                    sold_out++;
                    denominator -= 1/price;
                    if (j == min_price_index){
                        min_price_index = j+1;
                        min_price = sellers_list.array[j+1].price;
                    }
                }
                buyers_list.array[i].recieved_quantity += quantity;
                sellers_list.array[j].inventory -= quantity;
                buyers_list.array[i].budget -= quantity * price;
                budget = buyers_list.array[i].budget;
                
                transaction_quantity += quantity;
                transaction_volume += quantity * price;
                
                j = min_price_index;
                select_prob = (double)random_int(0, sellers_list.size) / sellers_list.size;
                continue;
            }
            j++;
        } while (1);
    }
    

    //indeed keeps unsold quantities.
    total_sold = 0;
    quantity = 0;
    // Send out revenue information.
    for (i =0; i < sellers_list.size; i++) {
        firm_id = sellers_list.array[i].id;
        quantity = sellers_list.array[i].inventory;
        add_sold_message(firm_id, quantity);
        total_sold += quantity;
    }
    quantity = 0;
    // Send out goods information.
    for (i =0; i < buyers_list.size; i++) {
        hh_id = buyers_list.array[i].id;
        budget = buyers_list.array[i].budget;
        quantity = buyers_list.array[i].recieved_quantity;
        add_bought_message(hh_id, budget, quantity);
    }
    
    // Finish
    //printf("Mall: Total Goods Not Sold= %d\n", total_sold);
    if (transaction_quantity > 0) {
        GOODS_TRANSACTIONS.quantity = transaction_quantity;
        GOODS_TRANSACTIONS.avg_price = transaction_volume / transaction_quantity;
    }
    
    /* Free seller list */
    free_seller_array(&sellers_list);
    /* Free buyer queues */
    free_buyer_array(&buyers_list);
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int mall_consumption_summary()
 * \brief:
 */
int mall_consumption_summary()
{
    double price;
    int quantity;
    
    price = GOODS_TRANSACTIONS.avg_price;
    quantity = GOODS_TRANSACTIONS.quantity;
    
    add_goods_transactions_summary_message(quantity, price);
    
	return 0; /* Returning zero means the agent is not removed */
}



