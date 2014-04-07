#include "../header.h"
#include "../mall_agent_header.h"
#include "../library_header.h"


/*
 * \fn: int mall_consumption_shopping()
 * \brief:
 */
int mall_consumption_shopping()
{
    /* Allocate local buyer queues and seller lists. */
    seller_array sellers_list;
    buyer_array buyers_list;
    /* Initialize arrays. */
    init_seller_array(&sellers_list);
    init_buyer_array(&buyers_list);
    
    /* Collect supply */
    int firm_id, inventory;;
    double price, inv_price;
    
    START_SELL_MESSAGE_LOOP
    firm_id = sell_message->id;
    price = sell_message->price;
    inventory = sell_message->inventory;
    if (price > 0 && inventory > 0) {
        /* Add to the shelve */
        inv_price = 1/price;
        add_seller(&sellers_list, firm_id, price, inventory, inv_price);
    }
    else if (inventory <= 0){
        if (WARNING_MODE) {
            printf("Warning @mall_consumption_shopping(): An invalid inventory = %d is received from Firm ID = %d\n", inventory, firm_id);
        }
    }
    else{
        if (WARNING_MODE) {
            printf("Warning @mall_consumption_shopping(): An invalid price = %f is received from Firm ID = %d\n", price, firm_id);
        }
    }
	FINISH_SELL_MESSAGE_LOOP
    
    
    /* Queue the households */
    int hh_id;
    double budget;
    START_BUY_MESSAGE_LOOP
    hh_id = buy_message->id;
    budget = buy_message->budget;
    if (budget > 0) {
        /* Add household to the queue */
        add_buyer(&buyers_list, hh_id, budget);
    }
    else{
        if (WARNING_MODE) {
            printf("Warning @mall_consumption_shopping(): An invalid budget = %f is received from Household ID = %d\n", budget, hh_id);
        }
    }
	FINISH_BUY_MESSAGE_LOOP
    

    /* 
    Consumption by Foreign Sector.
    This can be due to, for instance, tourism.
     */
    int total_fx_sold = 0;
    double total_fx_volume = 0;
    int fxsize, fxamount, fxinventory, fxfirm_id, j;
    double fxprice;
    fxsize = sellers_list.size;

    /*
     Following mechanism simulates the case when a certain ratio
     of produced goods are consumed by foreign sector.
     */
    /*
    for (int j = 0; j < fxsize; ++j)
    {
        fxamount = (int) (FIRM_EXPORT_RATIO * sellers_list.array[j].inventory);
        fxfirm_id = sellers_list.array[j].id;
        fxprice = sellers_list.array[j].price;
        sellers_list.array[j].inventory -= fxamount;
        add_sold_message(fxfirm_id, fxamount);
        total_fx_sold += fxamount;
        total_fx_volume += fxamount * fxprice;
    }
    */
    
    /*
     Following algorithm simulates when a certain transaction volume is taken
     place due to foreign sector consumtion in local markets.
     */
    
    /* It should be noted that the growth of demand via following equation is not linear!
     */
    
    if (IT_NO == 5) {
        DEMAND_TOURISM = 75;
    } else {
        DEMAND_TOURISM = (1 + EXPORT_GROWTH_RATE / 48) * DEMAND_TOURISM;
    }
    
    
    do {
        if (fxsize == 0) {break;}
        if (total_fx_volume >= DEMAND_TOURISM) {break;}
        j = 0;
        while (j < fxsize) {
            if (total_fx_volume >= DEMAND_TOURISM) {break;}
            fxinventory = sellers_list.array[j].inventory;
            if (fxinventory <= 0){
                remove_seller(&sellers_list, j);
                fxsize = sellers_list.size;
                continue;
            }
            
            fxfirm_id = sellers_list.array[j].id;
            fxprice = sellers_list.array[j].price;
            if (fxinventory <= 100) {
                fxamount = 1;
            } else {
                fxamount = (int) (FIRM_EXPORT_RATIO * fxinventory);
            }
            sellers_list.array[j].inventory -= fxamount;
            add_sold_message(fxfirm_id, fxamount);
            total_fx_sold += fxamount;
            total_fx_volume += fxamount * fxprice;
            j++;
        }
    } while (1);
    
    add_mall_centralbank_goods_message(total_fx_volume);

    
    
    
    /* Do the matching *
     * Input assumptions:
     * sellers are sorted ascendingly by price.
     * buyers are randomly queued
     * this is done at message filtering stage.
     */
    
    
    /* Calculate min_price, max_price, denominator*/
    double denominator = 0;
    double min_price = 5;
    double max_price = 0;
    int i;
    
    for (i=0; i < sellers_list.size; i++) {
        firm_id = sellers_list.array[i].id;
        inventory = sellers_list.array[i].inventory;
        inv_price = sellers_list.array[i].inv_price;
        price = sellers_list.array[i].price;
        if (price < min_price) {
            min_price = price;
        }
        if (price > max_price) {
            max_price = price;
        }
        if (price > 0 && inventory > 0) {
            denominator += inv_price;
        }
    }
 
    double select_prob;
    double inv_price_cum;
    double denominator_temp;
    int ind;
    int transaction_size;
    double transaction_volume;
    
    /* Identifiers below are used to hold weekly transaction summary.
     */
    int total_sold = total_fx_sold;
    double total_volume = total_fx_volume;
    int transaction_occured;


    do {
        
        if (sellers_list.size == 0 || buyers_list.size == 0) {break;}
        
        hh_id = buyers_list.array[0].id;
        budget = buyers_list.array[0].budget;
        price = sellers_list.array[0].price;
        
        /* The household in the turn does not have enough money to buy even
         the cheapest available good.
         */
        if (budget < price) {
            remove_buyer(&buyers_list,0);
            continue;
        }
        
        /* Determining the probability of picking a random seller. */
        select_prob = (double) random_int(0, 99) / 100;
        inv_price_cum = 0;
        transaction_size = 0;
        transaction_volume = 0;
        transaction_occured = 0;
        for (ind = 0; ind < sellers_list.size; ind++) {
            inventory = sellers_list.array[ind].inventory;
            firm_id = sellers_list.array[ind].id;
            if (inventory <= 0) {
                remove_seller(&sellers_list, ind);
                if (WARNING_MODE) {
                    printf("Warning @mall_consumption_shopping(): An invalid inventory = %d is detected while processing Firm ID = %d\n", inventory, firm_id);
                }
                break;
            }
            inv_price_cum += sellers_list.array[ind].inv_price;
            price = sellers_list.array[ind].price;
            
            /* Household with current budget does not afford to buy further goods in the list.
             The household buys from the ones he/she affords to buy.
             */
            if (budget <= price) {
                denominator_temp = inv_price_cum;
                if (denominator_temp <= 0) {
                    if (WARNING_MODE) {
                        printf("Warning @mall_consumption_shopping(): An invalid state is detected while processing Household ID = %d\n", hh_id);
                    }
                    remove_buyer(&buyers_list, 0);
                    break;
                }
                inv_price_cum = 0;
                for (i = 0; i <= ind; i++) {
                    inventory = sellers_list.array[i].inventory;
                    inv_price_cum += sellers_list.array[i].inv_price;
                    if ((inv_price_cum / denominator_temp - select_prob) >= 0) {
                        transaction_size = (int) floor(budget / price);
                        if (transaction_size > inventory){
                            transaction_size = inventory;
                        }
                        /* Update household budget and send out message.*/
                        transaction_volume = transaction_size * price;
                        budget -= transaction_volume;
                        buyers_list.array[0].budget = budget;
                        add_bought_message(hh_id, transaction_volume, transaction_size);
                        /* Send out sales info. */
                        add_sold_message(firm_id, transaction_size);
                        total_sold += transaction_size;
                        total_volume += transaction_volume;
                        /* Update sellers inventory to go */
                        inventory -= transaction_size;
                        if (inventory == 0) {
                            denominator -= sellers_list.array[i].inv_price;
                            remove_seller(&sellers_list, i);
                        }
                        else{
                            sellers_list.array[i].inventory = inventory;
                        }
                        transaction_occured = 1;
                        break;
                    }
                }
                break;
            }
            
            /* Household decides to buy from the current shelf he/she is examining.
             */
            if ((inv_price_cum / denominator - select_prob) >= 0) {
                transaction_size = (int) floor(budget / price);
                if (transaction_size > inventory){
                    transaction_size = inventory;
                }
                /* Update household budget and send out message.*/
                transaction_volume = transaction_size * price;
                budget -= transaction_volume;
                buyers_list.array[0].budget = budget;
                add_bought_message(hh_id, transaction_volume, transaction_size);
                /* Send out sales info. */
                add_sold_message(firm_id, transaction_size);
                total_sold += transaction_size;
                total_volume += transaction_volume;
                /* Update sellers inventory to go */
                inventory -= transaction_size;
                if (inventory == 0) {
                    denominator -= sellers_list.array[ind].inv_price;
                    remove_seller(&sellers_list, ind);
                }
                else{
                    sellers_list.array[ind].inventory = inventory;
                }
                transaction_occured = 1;
            }
            /* Household is eager to buy from a more expensive shelf.
             */
            
        }/* Sellers Loop End */
        if (transaction_occured == 0) {
            if (WARNING_MODE) {
                printf("Warning @mall_consumption_shopping(): Transaction did not take place while processing Household ID = %d\n", hh_id);
                remove_buyer(&buyers_list, 0);
            }
        }
    } while (1);
    
    /* Finish */
    GOODS_TRANSACTIONS.quantity = total_sold;
    if (total_sold > 0) {
        GOODS_TRANSACTIONS.avg_price = total_volume / total_sold;
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
    
    if (DATA_COLLECTION_MODE) {
        char * filename;
        FILE * file1;
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "./outputs/data/Mall_snapshot.txt");
        
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %d %f\n",IT_NO, quantity, price);
        fclose(file1);
        free(filename);
    }
    
    add_goods_transactions_summary_message(quantity, price);
    
    if (PRINT_DEBUG_MODE) {
        printf("Mall posts weekly transaction summaries. \n");
    }

    
	return 0; /* Returning zero means the agent is not removed */
}



