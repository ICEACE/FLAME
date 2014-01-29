/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"



/* Box filtering functions */




union pu_firm_bank_init_loans 
{
    m_firm_bank_init_loans *ptr;
    void *ptr_anon;
};

/** \fn void add_firm_bank_init_loans_message(int bank_id, double amount)
 * \brief Add firm_bank_init_loans message by calling internal and processing.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_firm_bank_init_loans_message(int bank_id, double amount)
{
    int rc;
	m_firm_bank_init_loans msg;
    
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_firm_bank_init_loans, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_bank_init_loans' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_init_loans' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_bank_init_loans' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_bank_init_loans* getInternalMessage_firm_bank_init_loans(void)
{
    static m_firm_bank_init_loans *msg_prev = NULL;
    union pu_firm_bank_init_loans msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_bank_init_loans); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_bank_init_loans' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_bank_init_loans' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_bank_init_loans, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_bank_init_loans' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_init_loans' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_firm_bank_init_loans * get_first_firm_bank_init_loans_message()
 * \brief Get the first firm_bank_init_loans message in the firm_bank_init_loans message list.
 * \return The first message in the list.
 */
m_firm_bank_init_loans * get_first_firm_bank_init_loans_message()
{
	return getInternalMessage_firm_bank_init_loans();
}

/** \fn xmachine_message_firm_bank_init_loans * get_next_firm_bank_init_loans_message(xmachine_message_firm_bank_init_loans * current)
 * \brief Get the next firm_bank_init_loans message in the firm_bank_init_loans message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_bank_init_loans * get_next_firm_bank_init_loans_message(m_firm_bank_init_loans * current)
{
	return getInternalMessage_firm_bank_init_loans();
}


/* Box filtering functions */




union pu_firm_bank_init_deposit 
{
    m_firm_bank_init_deposit *ptr;
    void *ptr_anon;
};

/** \fn void add_firm_bank_init_deposit_message(int bank_id, double amount)
 * \brief Add firm_bank_init_deposit message by calling internal and processing.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_firm_bank_init_deposit_message(int bank_id, double amount)
{
    int rc;
	m_firm_bank_init_deposit msg;
    
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_firm_bank_init_deposit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_bank_init_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_init_deposit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_bank_init_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_bank_init_deposit* getInternalMessage_firm_bank_init_deposit(void)
{
    static m_firm_bank_init_deposit *msg_prev = NULL;
    union pu_firm_bank_init_deposit msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_bank_init_deposit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_bank_init_deposit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_bank_init_deposit' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_bank_init_deposit, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_bank_init_deposit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_init_deposit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_firm_bank_init_deposit * get_first_firm_bank_init_deposit_message()
 * \brief Get the first firm_bank_init_deposit message in the firm_bank_init_deposit message list.
 * \return The first message in the list.
 */
m_firm_bank_init_deposit * get_first_firm_bank_init_deposit_message()
{
	return getInternalMessage_firm_bank_init_deposit();
}

/** \fn xmachine_message_firm_bank_init_deposit * get_next_firm_bank_init_deposit_message(xmachine_message_firm_bank_init_deposit * current)
 * \brief Get the next firm_bank_init_deposit message in the firm_bank_init_deposit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_bank_init_deposit * get_next_firm_bank_init_deposit_message(m_firm_bank_init_deposit * current)
{
	return getInternalMessage_firm_bank_init_deposit();
}


/* Box filtering functions */




union pu_firm_bank_update_deposit 
{
    m_firm_bank_update_deposit *ptr;
    void *ptr_anon;
};

/** \fn void add_firm_bank_update_deposit_message(int bank_id, double amount)
 * \brief Add firm_bank_update_deposit message by calling internal and processing.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_firm_bank_update_deposit_message(int bank_id, double amount)
{
    int rc;
	m_firm_bank_update_deposit msg;
    
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_firm_bank_update_deposit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_bank_update_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_bank_update_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_bank_update_deposit* getInternalMessage_firm_bank_update_deposit(void)
{
    static m_firm_bank_update_deposit *msg_prev = NULL;
    union pu_firm_bank_update_deposit msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_bank_update_deposit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_bank_update_deposit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_bank_update_deposit' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_bank_update_deposit, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_bank_update_deposit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_update_deposit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_firm_bank_update_deposit * get_first_firm_bank_update_deposit_message()
 * \brief Get the first firm_bank_update_deposit message in the firm_bank_update_deposit message list.
 * \return The first message in the list.
 */
m_firm_bank_update_deposit * get_first_firm_bank_update_deposit_message()
{
	return getInternalMessage_firm_bank_update_deposit();
}

/** \fn xmachine_message_firm_bank_update_deposit * get_next_firm_bank_update_deposit_message(xmachine_message_firm_bank_update_deposit * current)
 * \brief Get the next firm_bank_update_deposit message in the firm_bank_update_deposit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_bank_update_deposit * get_next_firm_bank_update_deposit_message(m_firm_bank_update_deposit * current)
{
	return getInternalMessage_firm_bank_update_deposit();
}


/* Box filtering functions */




union pu_household_bank_init_mortgages 
{
    m_household_bank_init_mortgages *ptr;
    void *ptr_anon;
};

/** \fn void add_household_bank_init_mortgages_message(int bank_id, double amount)
 * \brief Add household_bank_init_mortgages message by calling internal and processing.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_household_bank_init_mortgages_message(int bank_id, double amount)
{
    int rc;
	m_household_bank_init_mortgages msg;
    
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_household_bank_init_mortgages, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'household_bank_init_mortgages' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_bank_init_mortgages' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_bank_init_mortgages' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_household_bank_init_mortgages* getInternalMessage_household_bank_init_mortgages(void)
{
    static m_household_bank_init_mortgages *msg_prev = NULL;
    union pu_household_bank_init_mortgages msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_household_bank_init_mortgages); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'household_bank_init_mortgages' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'household_bank_init_mortgages' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_household_bank_init_mortgages, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'household_bank_init_mortgages' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_bank_init_mortgages' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_household_bank_init_mortgages * get_first_household_bank_init_mortgages_message()
 * \brief Get the first household_bank_init_mortgages message in the household_bank_init_mortgages message list.
 * \return The first message in the list.
 */
m_household_bank_init_mortgages * get_first_household_bank_init_mortgages_message()
{
	return getInternalMessage_household_bank_init_mortgages();
}

/** \fn xmachine_message_household_bank_init_mortgages * get_next_household_bank_init_mortgages_message(xmachine_message_household_bank_init_mortgages * current)
 * \brief Get the next household_bank_init_mortgages message in the household_bank_init_mortgages message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_household_bank_init_mortgages * get_next_household_bank_init_mortgages_message(m_household_bank_init_mortgages * current)
{
	return getInternalMessage_household_bank_init_mortgages();
}


/* Box filtering functions */




union pu_household_bank_init_deposit 
{
    m_household_bank_init_deposit *ptr;
    void *ptr_anon;
};

/** \fn void add_household_bank_init_deposit_message(int bank_id, double amount)
 * \brief Add household_bank_init_deposit message by calling internal and processing.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_household_bank_init_deposit_message(int bank_id, double amount)
{
    int rc;
	m_household_bank_init_deposit msg;
    
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_household_bank_init_deposit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'household_bank_init_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_bank_init_deposit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_bank_init_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_household_bank_init_deposit* getInternalMessage_household_bank_init_deposit(void)
{
    static m_household_bank_init_deposit *msg_prev = NULL;
    union pu_household_bank_init_deposit msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_household_bank_init_deposit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'household_bank_init_deposit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'household_bank_init_deposit' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_household_bank_init_deposit, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'household_bank_init_deposit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_bank_init_deposit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_household_bank_init_deposit * get_first_household_bank_init_deposit_message()
 * \brief Get the first household_bank_init_deposit message in the household_bank_init_deposit message list.
 * \return The first message in the list.
 */
m_household_bank_init_deposit * get_first_household_bank_init_deposit_message()
{
	return getInternalMessage_household_bank_init_deposit();
}

/** \fn xmachine_message_household_bank_init_deposit * get_next_household_bank_init_deposit_message(xmachine_message_household_bank_init_deposit * current)
 * \brief Get the next household_bank_init_deposit message in the household_bank_init_deposit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_household_bank_init_deposit * get_next_household_bank_init_deposit_message(m_household_bank_init_deposit * current)
{
	return getInternalMessage_household_bank_init_deposit();
}


/* Box filtering functions */




union pu_household_bank_update_deposit 
{
    m_household_bank_update_deposit *ptr;
    void *ptr_anon;
};

/** \fn void add_household_bank_update_deposit_message(int bank_id, double amount)
 * \brief Add household_bank_update_deposit message by calling internal and processing.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_household_bank_update_deposit_message(int bank_id, double amount)
{
    int rc;
	m_household_bank_update_deposit msg;
    
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_household_bank_update_deposit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'household_bank_update_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_bank_update_deposit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_bank_update_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_household_bank_update_deposit* getInternalMessage_household_bank_update_deposit(void)
{
    static m_household_bank_update_deposit *msg_prev = NULL;
    union pu_household_bank_update_deposit msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_household_bank_update_deposit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'household_bank_update_deposit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'household_bank_update_deposit' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_household_bank_update_deposit, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'household_bank_update_deposit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_bank_update_deposit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_household_bank_update_deposit * get_first_household_bank_update_deposit_message()
 * \brief Get the first household_bank_update_deposit message in the household_bank_update_deposit message list.
 * \return The first message in the list.
 */
m_household_bank_update_deposit * get_first_household_bank_update_deposit_message()
{
	return getInternalMessage_household_bank_update_deposit();
}

/** \fn xmachine_message_household_bank_update_deposit * get_next_household_bank_update_deposit_message(xmachine_message_household_bank_update_deposit * current)
 * \brief Get the next household_bank_update_deposit message in the household_bank_update_deposit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_household_bank_update_deposit * get_next_household_bank_update_deposit_message(m_household_bank_update_deposit * current)
{
	return getInternalMessage_household_bank_update_deposit();
}


/* Box filtering functions */




union pu_bank_centralbank_init_debt 
{
    m_bank_centralbank_init_debt *ptr;
    void *ptr_anon;
};

/** \fn void add_bank_centralbank_init_debt_message(int bank_id, double amount)
 * \brief Add bank_centralbank_init_debt message by calling internal and processing.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_bank_centralbank_init_debt_message(int bank_id, double amount)
{
    int rc;
	m_bank_centralbank_init_debt msg;
    
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_bank_centralbank_init_debt, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_centralbank_init_debt' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_centralbank_init_debt' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_centralbank_init_debt' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_centralbank_init_debt* getInternalMessage_bank_centralbank_init_debt(void)
{
    static m_bank_centralbank_init_debt *msg_prev = NULL;
    union pu_bank_centralbank_init_debt msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_centralbank_init_debt); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_centralbank_init_debt' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_centralbank_init_debt' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_centralbank_init_debt, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_centralbank_init_debt' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_centralbank_init_debt' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bank_centralbank_init_debt * get_first_bank_centralbank_init_debt_message()
 * \brief Get the first bank_centralbank_init_debt message in the bank_centralbank_init_debt message list.
 * \return The first message in the list.
 */
m_bank_centralbank_init_debt * get_first_bank_centralbank_init_debt_message()
{
	return getInternalMessage_bank_centralbank_init_debt();
}

/** \fn xmachine_message_bank_centralbank_init_debt * get_next_bank_centralbank_init_debt_message(xmachine_message_bank_centralbank_init_debt * current)
 * \brief Get the next bank_centralbank_init_debt message in the bank_centralbank_init_debt message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_centralbank_init_debt * get_next_bank_centralbank_init_debt_message(m_bank_centralbank_init_debt * current)
{
	return getInternalMessage_bank_centralbank_init_debt();
}


/* Box filtering functions */




union pu_bank_centralbank_init_deposit 
{
    m_bank_centralbank_init_deposit *ptr;
    void *ptr_anon;
};

/** \fn void add_bank_centralbank_init_deposit_message(int bank_id, double amount)
 * \brief Add bank_centralbank_init_deposit message by calling internal and processing.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_bank_centralbank_init_deposit_message(int bank_id, double amount)
{
    int rc;
	m_bank_centralbank_init_deposit msg;
    
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_bank_centralbank_init_deposit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_centralbank_init_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_centralbank_init_deposit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_centralbank_init_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_centralbank_init_deposit* getInternalMessage_bank_centralbank_init_deposit(void)
{
    static m_bank_centralbank_init_deposit *msg_prev = NULL;
    union pu_bank_centralbank_init_deposit msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_centralbank_init_deposit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_centralbank_init_deposit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_centralbank_init_deposit' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_centralbank_init_deposit, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_centralbank_init_deposit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_centralbank_init_deposit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bank_centralbank_init_deposit * get_first_bank_centralbank_init_deposit_message()
 * \brief Get the first bank_centralbank_init_deposit message in the bank_centralbank_init_deposit message list.
 * \return The first message in the list.
 */
m_bank_centralbank_init_deposit * get_first_bank_centralbank_init_deposit_message()
{
	return getInternalMessage_bank_centralbank_init_deposit();
}

/** \fn xmachine_message_bank_centralbank_init_deposit * get_next_bank_centralbank_init_deposit_message(xmachine_message_bank_centralbank_init_deposit * current)
 * \brief Get the next bank_centralbank_init_deposit message in the bank_centralbank_init_deposit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_centralbank_init_deposit * get_next_bank_centralbank_init_deposit_message(m_bank_centralbank_init_deposit * current)
{
	return getInternalMessage_bank_centralbank_init_deposit();
}


/* Box filtering functions */




union pu_bank_centralbank_update_deposit 
{
    m_bank_centralbank_update_deposit *ptr;
    void *ptr_anon;
};

/** \fn void add_bank_centralbank_update_deposit_message(int bank_id, double amount)
 * \brief Add bank_centralbank_update_deposit message by calling internal and processing.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_bank_centralbank_update_deposit_message(int bank_id, double amount)
{
    int rc;
	m_bank_centralbank_update_deposit msg;
    
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_bank_centralbank_update_deposit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_centralbank_update_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_centralbank_update_deposit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_centralbank_update_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_centralbank_update_deposit* getInternalMessage_bank_centralbank_update_deposit(void)
{
    static m_bank_centralbank_update_deposit *msg_prev = NULL;
    union pu_bank_centralbank_update_deposit msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_centralbank_update_deposit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_centralbank_update_deposit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_centralbank_update_deposit' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_centralbank_update_deposit, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_centralbank_update_deposit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_centralbank_update_deposit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bank_centralbank_update_deposit * get_first_bank_centralbank_update_deposit_message()
 * \brief Get the first bank_centralbank_update_deposit message in the bank_centralbank_update_deposit message list.
 * \return The first message in the list.
 */
m_bank_centralbank_update_deposit * get_first_bank_centralbank_update_deposit_message()
{
	return getInternalMessage_bank_centralbank_update_deposit();
}

/** \fn xmachine_message_bank_centralbank_update_deposit * get_next_bank_centralbank_update_deposit_message(xmachine_message_bank_centralbank_update_deposit * current)
 * \brief Get the next bank_centralbank_update_deposit message in the bank_centralbank_update_deposit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_centralbank_update_deposit * get_next_bank_centralbank_update_deposit_message(m_bank_centralbank_update_deposit * current)
{
	return getInternalMessage_bank_centralbank_update_deposit();
}


/* Box filtering functions */




union pu_fund_centralbank_init_deposit 
{
    m_fund_centralbank_init_deposit *ptr;
    void *ptr_anon;
};

/** \fn void add_fund_centralbank_init_deposit_message(double amount)
 * \brief Add fund_centralbank_init_deposit message by calling internal and processing.
 * \param amount Message variable.
 */
void add_fund_centralbank_init_deposit_message(double amount)
{
    int rc;
	m_fund_centralbank_init_deposit msg;
    
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_fund_centralbank_init_deposit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'fund_centralbank_init_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fund_centralbank_init_deposit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fund_centralbank_init_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_fund_centralbank_init_deposit* getInternalMessage_fund_centralbank_init_deposit(void)
{
    static m_fund_centralbank_init_deposit *msg_prev = NULL;
    union pu_fund_centralbank_init_deposit msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_fund_centralbank_init_deposit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'fund_centralbank_init_deposit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'fund_centralbank_init_deposit' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_fund_centralbank_init_deposit, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'fund_centralbank_init_deposit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fund_centralbank_init_deposit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_fund_centralbank_init_deposit * get_first_fund_centralbank_init_deposit_message()
 * \brief Get the first fund_centralbank_init_deposit message in the fund_centralbank_init_deposit message list.
 * \return The first message in the list.
 */
m_fund_centralbank_init_deposit * get_first_fund_centralbank_init_deposit_message()
{
	return getInternalMessage_fund_centralbank_init_deposit();
}

/** \fn xmachine_message_fund_centralbank_init_deposit * get_next_fund_centralbank_init_deposit_message(xmachine_message_fund_centralbank_init_deposit * current)
 * \brief Get the next fund_centralbank_init_deposit message in the fund_centralbank_init_deposit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_fund_centralbank_init_deposit * get_next_fund_centralbank_init_deposit_message(m_fund_centralbank_init_deposit * current)
{
	return getInternalMessage_fund_centralbank_init_deposit();
}


/* Box filtering functions */




union pu_fund_centralbank_update_deposit 
{
    m_fund_centralbank_update_deposit *ptr;
    void *ptr_anon;
};

/** \fn void add_fund_centralbank_update_deposit_message(double amount)
 * \brief Add fund_centralbank_update_deposit message by calling internal and processing.
 * \param amount Message variable.
 */
void add_fund_centralbank_update_deposit_message(double amount)
{
    int rc;
	m_fund_centralbank_update_deposit msg;
    
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_fund_centralbank_update_deposit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'fund_centralbank_update_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fund_centralbank_update_deposit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fund_centralbank_update_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_fund_centralbank_update_deposit* getInternalMessage_fund_centralbank_update_deposit(void)
{
    static m_fund_centralbank_update_deposit *msg_prev = NULL;
    union pu_fund_centralbank_update_deposit msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_fund_centralbank_update_deposit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'fund_centralbank_update_deposit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'fund_centralbank_update_deposit' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_fund_centralbank_update_deposit, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'fund_centralbank_update_deposit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fund_centralbank_update_deposit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_fund_centralbank_update_deposit * get_first_fund_centralbank_update_deposit_message()
 * \brief Get the first fund_centralbank_update_deposit message in the fund_centralbank_update_deposit message list.
 * \return The first message in the list.
 */
m_fund_centralbank_update_deposit * get_first_fund_centralbank_update_deposit_message()
{
	return getInternalMessage_fund_centralbank_update_deposit();
}

/** \fn xmachine_message_fund_centralbank_update_deposit * get_next_fund_centralbank_update_deposit_message(xmachine_message_fund_centralbank_update_deposit * current)
 * \brief Get the next fund_centralbank_update_deposit message in the fund_centralbank_update_deposit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_fund_centralbank_update_deposit * get_next_fund_centralbank_update_deposit_message(m_fund_centralbank_update_deposit * current)
{
	return getInternalMessage_fund_centralbank_update_deposit();
}


/* Box filtering functions */




union pu_gov_centralbank_init_deposit 
{
    m_gov_centralbank_init_deposit *ptr;
    void *ptr_anon;
};

/** \fn void add_gov_centralbank_init_deposit_message(double amount)
 * \brief Add gov_centralbank_init_deposit message by calling internal and processing.
 * \param amount Message variable.
 */
void add_gov_centralbank_init_deposit_message(double amount)
{
    int rc;
	m_gov_centralbank_init_deposit msg;
    
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_gov_centralbank_init_deposit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'gov_centralbank_init_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_centralbank_init_deposit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'gov_centralbank_init_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_gov_centralbank_init_deposit* getInternalMessage_gov_centralbank_init_deposit(void)
{
    static m_gov_centralbank_init_deposit *msg_prev = NULL;
    union pu_gov_centralbank_init_deposit msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_gov_centralbank_init_deposit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'gov_centralbank_init_deposit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'gov_centralbank_init_deposit' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_gov_centralbank_init_deposit, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'gov_centralbank_init_deposit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_centralbank_init_deposit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_gov_centralbank_init_deposit * get_first_gov_centralbank_init_deposit_message()
 * \brief Get the first gov_centralbank_init_deposit message in the gov_centralbank_init_deposit message list.
 * \return The first message in the list.
 */
m_gov_centralbank_init_deposit * get_first_gov_centralbank_init_deposit_message()
{
	return getInternalMessage_gov_centralbank_init_deposit();
}

/** \fn xmachine_message_gov_centralbank_init_deposit * get_next_gov_centralbank_init_deposit_message(xmachine_message_gov_centralbank_init_deposit * current)
 * \brief Get the next gov_centralbank_init_deposit message in the gov_centralbank_init_deposit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_gov_centralbank_init_deposit * get_next_gov_centralbank_init_deposit_message(m_gov_centralbank_init_deposit * current)
{
	return getInternalMessage_gov_centralbank_init_deposit();
}


/* Box filtering functions */




union pu_gov_centralbank_update_deposit 
{
    m_gov_centralbank_update_deposit *ptr;
    void *ptr_anon;
};

/** \fn void add_gov_centralbank_update_deposit_message(double amount)
 * \brief Add gov_centralbank_update_deposit message by calling internal and processing.
 * \param amount Message variable.
 */
void add_gov_centralbank_update_deposit_message(double amount)
{
    int rc;
	m_gov_centralbank_update_deposit msg;
    
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_gov_centralbank_update_deposit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'gov_centralbank_update_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_centralbank_update_deposit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'gov_centralbank_update_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_gov_centralbank_update_deposit* getInternalMessage_gov_centralbank_update_deposit(void)
{
    static m_gov_centralbank_update_deposit *msg_prev = NULL;
    union pu_gov_centralbank_update_deposit msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_gov_centralbank_update_deposit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'gov_centralbank_update_deposit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'gov_centralbank_update_deposit' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_gov_centralbank_update_deposit, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'gov_centralbank_update_deposit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_centralbank_update_deposit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_gov_centralbank_update_deposit * get_first_gov_centralbank_update_deposit_message()
 * \brief Get the first gov_centralbank_update_deposit message in the gov_centralbank_update_deposit message list.
 * \return The first message in the list.
 */
m_gov_centralbank_update_deposit * get_first_gov_centralbank_update_deposit_message()
{
	return getInternalMessage_gov_centralbank_update_deposit();
}

/** \fn xmachine_message_gov_centralbank_update_deposit * get_next_gov_centralbank_update_deposit_message(xmachine_message_gov_centralbank_update_deposit * current)
 * \brief Get the next gov_centralbank_update_deposit message in the gov_centralbank_update_deposit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_gov_centralbank_update_deposit * get_next_gov_centralbank_update_deposit_message(m_gov_centralbank_update_deposit * current)
{
	return getInternalMessage_gov_centralbank_update_deposit();
}


/* Box filtering functions */




union pu_interest_rate 
{
    m_interest_rate *ptr;
    void *ptr_anon;
};

/** \fn void add_interest_rate_message(double rate)
 * \brief Add interest_rate message by calling internal and processing.
 * \param rate Message variable.
 */
void add_interest_rate_message(double rate)
{
    int rc;
	m_interest_rate msg;
    
    msg.rate = rate;
    
    
    rc = MB_AddMessage(b_interest_rate, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'interest_rate' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'interest_rate' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'interest_rate' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_interest_rate* getInternalMessage_interest_rate(void)
{
    static m_interest_rate *msg_prev = NULL;
    union pu_interest_rate msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_interest_rate); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'interest_rate' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'interest_rate' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_interest_rate, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'interest_rate' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'interest_rate' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_interest_rate * get_first_interest_rate_message()
 * \brief Get the first interest_rate message in the interest_rate message list.
 * \return The first message in the list.
 */
m_interest_rate * get_first_interest_rate_message()
{
	return getInternalMessage_interest_rate();
}

/** \fn xmachine_message_interest_rate * get_next_interest_rate_message(xmachine_message_interest_rate * current)
 * \brief Get the next interest_rate message in the interest_rate message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_interest_rate * get_next_interest_rate_message(m_interest_rate * current)
{
	return getInternalMessage_interest_rate();
}


/* Box filtering functions */




union pu_capital_tax_rate 
{
    m_capital_tax_rate *ptr;
    void *ptr_anon;
};

/** \fn void add_capital_tax_rate_message(double value)
 * \brief Add capital_tax_rate message by calling internal and processing.
 * \param value Message variable.
 */
void add_capital_tax_rate_message(double value)
{
    int rc;
	m_capital_tax_rate msg;
    
    msg.value = value;
    
    
    rc = MB_AddMessage(b_capital_tax_rate, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'capital_tax_rate' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_tax_rate' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_tax_rate' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_capital_tax_rate* getInternalMessage_capital_tax_rate(void)
{
    static m_capital_tax_rate *msg_prev = NULL;
    union pu_capital_tax_rate msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_capital_tax_rate); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'capital_tax_rate' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'capital_tax_rate' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_capital_tax_rate, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'capital_tax_rate' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_tax_rate' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_capital_tax_rate * get_first_capital_tax_rate_message()
 * \brief Get the first capital_tax_rate message in the capital_tax_rate message list.
 * \return The first message in the list.
 */
m_capital_tax_rate * get_first_capital_tax_rate_message()
{
	return getInternalMessage_capital_tax_rate();
}

/** \fn xmachine_message_capital_tax_rate * get_next_capital_tax_rate_message(xmachine_message_capital_tax_rate * current)
 * \brief Get the next capital_tax_rate message in the capital_tax_rate message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_capital_tax_rate * get_next_capital_tax_rate_message(m_capital_tax_rate * current)
{
	return getInternalMessage_capital_tax_rate();
}


/* Box filtering functions */




union pu_labour_tax_rate 
{
    m_labour_tax_rate *ptr;
    void *ptr_anon;
};

/** \fn void add_labour_tax_rate_message(double value)
 * \brief Add labour_tax_rate message by calling internal and processing.
 * \param value Message variable.
 */
void add_labour_tax_rate_message(double value)
{
    int rc;
	m_labour_tax_rate msg;
    
    msg.value = value;
    
    
    rc = MB_AddMessage(b_labour_tax_rate, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'labour_tax_rate' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'labour_tax_rate' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'labour_tax_rate' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_labour_tax_rate* getInternalMessage_labour_tax_rate(void)
{
    static m_labour_tax_rate *msg_prev = NULL;
    union pu_labour_tax_rate msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_labour_tax_rate); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'labour_tax_rate' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'labour_tax_rate' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_labour_tax_rate, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'labour_tax_rate' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'labour_tax_rate' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_labour_tax_rate * get_first_labour_tax_rate_message()
 * \brief Get the first labour_tax_rate message in the labour_tax_rate message list.
 * \return The first message in the list.
 */
m_labour_tax_rate * get_first_labour_tax_rate_message()
{
	return getInternalMessage_labour_tax_rate();
}

/** \fn xmachine_message_labour_tax_rate * get_next_labour_tax_rate_message(xmachine_message_labour_tax_rate * current)
 * \brief Get the next labour_tax_rate message in the labour_tax_rate message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_labour_tax_rate * get_next_labour_tax_rate_message(m_labour_tax_rate * current)
{
	return getInternalMessage_labour_tax_rate();
}


/* Box filtering functions */




union pu_household_jpoffice_id 
{
    m_household_jpoffice_id *ptr;
    void *ptr_anon;
};

/** \fn void add_household_jpoffice_id_message(int household_id)
 * \brief Add household_jpoffice_id message by calling internal and processing.
 * \param household_id Message variable.
 */
void add_household_jpoffice_id_message(int household_id)
{
    int rc;
	m_household_jpoffice_id msg;
    
    msg.household_id = household_id;
    
    
    rc = MB_AddMessage(b_household_jpoffice_id, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'household_jpoffice_id' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_jpoffice_id' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_jpoffice_id' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_household_jpoffice_id* getInternalMessage_household_jpoffice_id(void)
{
    static m_household_jpoffice_id *msg_prev = NULL;
    union pu_household_jpoffice_id msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_household_jpoffice_id); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'household_jpoffice_id' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'household_jpoffice_id' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_household_jpoffice_id, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'household_jpoffice_id' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_jpoffice_id' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_household_jpoffice_id * get_first_household_jpoffice_id_message()
 * \brief Get the first household_jpoffice_id message in the household_jpoffice_id message list.
 * \return The first message in the list.
 */
m_household_jpoffice_id * get_first_household_jpoffice_id_message()
{
	return getInternalMessage_household_jpoffice_id();
}

/** \fn xmachine_message_household_jpoffice_id * get_next_household_jpoffice_id_message(xmachine_message_household_jpoffice_id * current)
 * \brief Get the next household_jpoffice_id message in the household_jpoffice_id message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_household_jpoffice_id * get_next_household_jpoffice_id_message(m_household_jpoffice_id * current)
{
	return getInternalMessage_household_jpoffice_id();
}


/* Box filtering functions */




union pu_jpoffice_household_employer 
{
    m_jpoffice_household_employer *ptr;
    void *ptr_anon;
};

/** \fn void add_jpoffice_household_employer_message(int household_id, int employer_id)
 * \brief Add jpoffice_household_employer message by calling internal and processing.
 * \param household_id Message variable.
 * \param employer_id Message variable.
 */
void add_jpoffice_household_employer_message(int household_id, int employer_id)
{
    int rc;
	m_jpoffice_household_employer msg;
    
    msg.household_id = household_id;
    msg.employer_id = employer_id;
    
    
    rc = MB_AddMessage(b_jpoffice_household_employer, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'jpoffice_household_employer' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'jpoffice_household_employer' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'jpoffice_household_employer' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_jpoffice_household_employer* getInternalMessage_jpoffice_household_employer(void)
{
    static m_jpoffice_household_employer *msg_prev = NULL;
    union pu_jpoffice_household_employer msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_jpoffice_household_employer); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'jpoffice_household_employer' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'jpoffice_household_employer' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_jpoffice_household_employer, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'jpoffice_household_employer' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'jpoffice_household_employer' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_jpoffice_household_employer * get_first_jpoffice_household_employer_message()
 * \brief Get the first jpoffice_household_employer message in the jpoffice_household_employer message list.
 * \return The first message in the list.
 */
m_jpoffice_household_employer * get_first_jpoffice_household_employer_message()
{
	return getInternalMessage_jpoffice_household_employer();
}

/** \fn xmachine_message_jpoffice_household_employer * get_next_jpoffice_household_employer_message(xmachine_message_jpoffice_household_employer * current)
 * \brief Get the next jpoffice_household_employer message in the jpoffice_household_employer message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_jpoffice_household_employer * get_next_jpoffice_household_employer_message(m_jpoffice_household_employer * current)
{
	return getInternalMessage_jpoffice_household_employer();
}


/* Box filtering functions */




union pu_firm_jpoffice_id 
{
    m_firm_jpoffice_id *ptr;
    void *ptr_anon;
};

/** \fn void add_firm_jpoffice_id_message(int firm_id, int isconstructor)
 * \brief Add firm_jpoffice_id message by calling internal and processing.
 * \param firm_id Message variable.
 * \param isconstructor Message variable.
 */
void add_firm_jpoffice_id_message(int firm_id, int isconstructor)
{
    int rc;
	m_firm_jpoffice_id msg;
    
    msg.firm_id = firm_id;
    msg.isconstructor = isconstructor;
    
    
    rc = MB_AddMessage(b_firm_jpoffice_id, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_jpoffice_id' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_jpoffice_id' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_jpoffice_id' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_jpoffice_id* getInternalMessage_firm_jpoffice_id(void)
{
    static m_firm_jpoffice_id *msg_prev = NULL;
    union pu_firm_jpoffice_id msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_jpoffice_id); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_jpoffice_id' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_jpoffice_id' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_jpoffice_id, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_jpoffice_id' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_jpoffice_id' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_firm_jpoffice_id * get_first_firm_jpoffice_id_message()
 * \brief Get the first firm_jpoffice_id message in the firm_jpoffice_id message list.
 * \return The first message in the list.
 */
m_firm_jpoffice_id * get_first_firm_jpoffice_id_message()
{
	return getInternalMessage_firm_jpoffice_id();
}

/** \fn xmachine_message_firm_jpoffice_id * get_next_firm_jpoffice_id_message(xmachine_message_firm_jpoffice_id * current)
 * \brief Get the next firm_jpoffice_id message in the firm_jpoffice_id message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_jpoffice_id * get_next_firm_jpoffice_id_message(m_firm_jpoffice_id * current)
{
	return getInternalMessage_firm_jpoffice_id();
}


/* Box filtering functions */




union pu_jpoffice_firm_employee 
{
    m_jpoffice_firm_employee *ptr;
    void *ptr_anon;
};

/** \fn void add_jpoffice_firm_employee_message(int firm_id, int employee_id)
 * \brief Add jpoffice_firm_employee message by calling internal and processing.
 * \param firm_id Message variable.
 * \param employee_id Message variable.
 */
void add_jpoffice_firm_employee_message(int firm_id, int employee_id)
{
    int rc;
	m_jpoffice_firm_employee msg;
    
    msg.firm_id = firm_id;
    msg.employee_id = employee_id;
    
    
    rc = MB_AddMessage(b_jpoffice_firm_employee, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'jpoffice_firm_employee' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'jpoffice_firm_employee' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'jpoffice_firm_employee' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_jpoffice_firm_employee* getInternalMessage_jpoffice_firm_employee(void)
{
    static m_jpoffice_firm_employee *msg_prev = NULL;
    union pu_jpoffice_firm_employee msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_jpoffice_firm_employee); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'jpoffice_firm_employee' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'jpoffice_firm_employee' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_jpoffice_firm_employee, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'jpoffice_firm_employee' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'jpoffice_firm_employee' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_jpoffice_firm_employee * get_first_jpoffice_firm_employee_message()
 * \brief Get the first jpoffice_firm_employee message in the jpoffice_firm_employee message list.
 * \return The first message in the list.
 */
m_jpoffice_firm_employee * get_first_jpoffice_firm_employee_message()
{
	return getInternalMessage_jpoffice_firm_employee();
}

/** \fn xmachine_message_jpoffice_firm_employee * get_next_jpoffice_firm_employee_message(xmachine_message_jpoffice_firm_employee * current)
 * \brief Get the next jpoffice_firm_employee message in the jpoffice_firm_employee message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_jpoffice_firm_employee * get_next_jpoffice_firm_employee_message(m_jpoffice_firm_employee * current)
{
	return getInternalMessage_jpoffice_firm_employee();
}


/* Box filtering functions */




union pu_buy 
{
    m_buy *ptr;
    void *ptr_anon;
};

/** \fn void add_buy_message(int id, double budget)
 * \brief Add buy message by calling internal and processing.
 * \param id Message variable.
 * \param budget Message variable.
 */
void add_buy_message(int id, double budget)
{
    int rc;
	m_buy msg;
    
    msg.id = id;
    msg.budget = budget;
    
    
    rc = MB_AddMessage(b_buy, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'buy' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'buy' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'buy' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_buy* getInternalMessage_buy(void)
{
    static m_buy *msg_prev = NULL;
    union pu_buy msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_buy); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'buy' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'buy' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_buy, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'buy' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'buy' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_buy * get_first_buy_message()
 * \brief Get the first buy message in the buy message list.
 * \return The first message in the list.
 */
m_buy * get_first_buy_message()
{
	return getInternalMessage_buy();
}

/** \fn xmachine_message_buy * get_next_buy_message(xmachine_message_buy * current)
 * \brief Get the next buy message in the buy message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_buy * get_next_buy_message(m_buy * current)
{
	return getInternalMessage_buy();
}


/* Box filtering functions */




union pu_bought 
{
    m_bought *ptr;
    void *ptr_anon;
};

/** \fn void add_bought_message(int id, double money_spent, int received_quantity)
 * \brief Add bought message by calling internal and processing.
 * \param id Message variable.
 * \param money_spent Message variable.
 * \param received_quantity Message variable.
 */
void add_bought_message(int id, double money_spent, int received_quantity)
{
    int rc;
	m_bought msg;
    
    msg.id = id;
    msg.money_spent = money_spent;
    msg.received_quantity = received_quantity;
    
    
    rc = MB_AddMessage(b_bought, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bought' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bought' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bought' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bought* getInternalMessage_bought(void)
{
    static m_bought *msg_prev = NULL;
    union pu_bought msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bought); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bought' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bought' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bought, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bought' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bought' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bought * get_first_bought_message()
 * \brief Get the first bought message in the bought message list.
 * \return The first message in the list.
 */
m_bought * get_first_bought_message()
{
	return getInternalMessage_bought();
}

/** \fn xmachine_message_bought * get_next_bought_message(xmachine_message_bought * current)
 * \brief Get the next bought message in the bought message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bought * get_next_bought_message(m_bought * current)
{
	return getInternalMessage_bought();
}


/* Box filtering functions */




union pu_sell 
{
    m_sell *ptr;
    void *ptr_anon;
};

/** \fn void add_sell_message(int id, double price, int inventory)
 * \brief Add sell message by calling internal and processing.
 * \param id Message variable.
 * \param price Message variable.
 * \param inventory Message variable.
 */
void add_sell_message(int id, double price, int inventory)
{
    int rc;
	m_sell msg;
    
    msg.id = id;
    msg.price = price;
    msg.inventory = inventory;
    
    
    rc = MB_AddMessage(b_sell, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'sell' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sell' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sell' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_sell* getInternalMessage_sell(void)
{
    static m_sell *msg_prev = NULL;
    union pu_sell msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_sell); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'sell' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'sell' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_sell, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'sell' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sell' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_sell * get_first_sell_message()
 * \brief Get the first sell message in the sell message list.
 * \return The first message in the list.
 */
m_sell * get_first_sell_message()
{
	return getInternalMessage_sell();
}

/** \fn xmachine_message_sell * get_next_sell_message(xmachine_message_sell * current)
 * \brief Get the next sell message in the sell message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_sell * get_next_sell_message(m_sell * current)
{
	return getInternalMessage_sell();
}


/* Box filtering functions */




union pu_sold 
{
    m_sold *ptr;
    void *ptr_anon;
};

/** \fn void add_sold_message(int id, int sold_quantities)
 * \brief Add sold message by calling internal and processing.
 * \param id Message variable.
 * \param sold_quantities Message variable.
 */
void add_sold_message(int id, int sold_quantities)
{
    int rc;
	m_sold msg;
    
    msg.id = id;
    msg.sold_quantities = sold_quantities;
    
    
    rc = MB_AddMessage(b_sold, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'sold' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sold' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sold' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_sold* getInternalMessage_sold(void)
{
    static m_sold *msg_prev = NULL;
    union pu_sold msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_sold); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'sold' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'sold' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_sold, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'sold' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sold' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_sold * get_first_sold_message()
 * \brief Get the first sold message in the sold message list.
 * \return The first message in the list.
 */
m_sold * get_first_sold_message()
{
	return getInternalMessage_sold();
}

/** \fn xmachine_message_sold * get_next_sold_message(xmachine_message_sold * current)
 * \brief Get the next sold message in the sold message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_sold * get_next_sold_message(m_sold * current)
{
	return getInternalMessage_sold();
}


/* Box filtering functions */




union pu_goods_transactions_summary 
{
    m_goods_transactions_summary *ptr;
    void *ptr_anon;
};

/** \fn void add_goods_transactions_summary_message(int quantity, double avg_price)
 * \brief Add goods_transactions_summary message by calling internal and processing.
 * \param quantity Message variable.
 * \param avg_price Message variable.
 */
void add_goods_transactions_summary_message(int quantity, double avg_price)
{
    int rc;
	m_goods_transactions_summary msg;
    
    msg.quantity = quantity;
    msg.avg_price = avg_price;
    
    
    rc = MB_AddMessage(b_goods_transactions_summary, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'goods_transactions_summary' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'goods_transactions_summary' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'goods_transactions_summary' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_goods_transactions_summary* getInternalMessage_goods_transactions_summary(void)
{
    static m_goods_transactions_summary *msg_prev = NULL;
    union pu_goods_transactions_summary msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_goods_transactions_summary); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'goods_transactions_summary' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'goods_transactions_summary' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_goods_transactions_summary, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'goods_transactions_summary' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'goods_transactions_summary' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_goods_transactions_summary * get_first_goods_transactions_summary_message()
 * \brief Get the first goods_transactions_summary message in the goods_transactions_summary message list.
 * \return The first message in the list.
 */
m_goods_transactions_summary * get_first_goods_transactions_summary_message()
{
	return getInternalMessage_goods_transactions_summary();
}

/** \fn xmachine_message_goods_transactions_summary * get_next_goods_transactions_summary_message(xmachine_message_goods_transactions_summary * current)
 * \brief Get the next goods_transactions_summary message in the goods_transactions_summary message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_goods_transactions_summary * get_next_goods_transactions_summary_message(m_goods_transactions_summary * current)
{
	return getInternalMessage_goods_transactions_summary();
}


/* Box filtering functions */




union pu_fired 
{
    m_fired *ptr;
    void *ptr_anon;
};

/** \fn void add_fired_message(int employee_id)
 * \brief Add fired message by calling internal and processing.
 * \param employee_id Message variable.
 */
void add_fired_message(int employee_id)
{
    int rc;
	m_fired msg;
    
    msg.employee_id = employee_id;
    
    
    rc = MB_AddMessage(b_fired, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'fired' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fired' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fired' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_fired* getInternalMessage_fired(void)
{
    static m_fired *msg_prev = NULL;
    union pu_fired msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_fired); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'fired' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'fired' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_fired, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'fired' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fired' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_fired * get_first_fired_message()
 * \brief Get the first fired message in the fired message list.
 * \return The first message in the list.
 */
m_fired * get_first_fired_message()
{
	return getInternalMessage_fired();
}

/** \fn xmachine_message_fired * get_next_fired_message(xmachine_message_fired * current)
 * \brief Get the next fired message in the fired message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_fired * get_next_fired_message(m_fired * current)
{
	return getInternalMessage_fired();
}


/* Box filtering functions */




union pu_vacancy_stage1 
{
    m_vacancy_stage1 *ptr;
    void *ptr_anon;
};

/** \fn void add_vacancy_stage1_message(int employer_id, double wage)
 * \brief Add vacancy_stage1 message by calling internal and processing.
 * \param employer_id Message variable.
 * \param wage Message variable.
 */
void add_vacancy_stage1_message(int employer_id, double wage)
{
    int rc;
	m_vacancy_stage1 msg;
    
    msg.employer_id = employer_id;
    msg.wage = wage;
    
    
    rc = MB_AddMessage(b_vacancy_stage1, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'vacancy_stage1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancy_stage1' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancy_stage1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_vacancy_stage1* getInternalMessage_vacancy_stage1(void)
{
    static m_vacancy_stage1 *msg_prev = NULL;
    union pu_vacancy_stage1 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_vacancy_stage1); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'vacancy_stage1' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'vacancy_stage1' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_vacancy_stage1, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'vacancy_stage1' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancy_stage1' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_vacancy_stage1 * get_first_vacancy_stage1_message()
 * \brief Get the first vacancy_stage1 message in the vacancy_stage1 message list.
 * \return The first message in the list.
 */
m_vacancy_stage1 * get_first_vacancy_stage1_message()
{
	return getInternalMessage_vacancy_stage1();
}

/** \fn xmachine_message_vacancy_stage1 * get_next_vacancy_stage1_message(xmachine_message_vacancy_stage1 * current)
 * \brief Get the next vacancy_stage1 message in the vacancy_stage1 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_vacancy_stage1 * get_next_vacancy_stage1_message(m_vacancy_stage1 * current)
{
	return getInternalMessage_vacancy_stage1();
}


/* Box filtering functions */




union pu_job_application_stage2 
{
    m_job_application_stage2 *ptr;
    void *ptr_anon;
};

/** \fn void add_job_application_stage2_message(int employee_id)
 * \brief Add job_application_stage2 message by calling internal and processing.
 * \param employee_id Message variable.
 */
void add_job_application_stage2_message(int employee_id)
{
    int rc;
	m_job_application_stage2 msg;
    
    msg.employee_id = employee_id;
    
    
    rc = MB_AddMessage(b_job_application_stage2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_application_stage2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application_stage2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application_stage2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_application_stage2* getInternalMessage_job_application_stage2(void)
{
    static m_job_application_stage2 *msg_prev = NULL;
    union pu_job_application_stage2 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_application_stage2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_application_stage2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_application_stage2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_application_stage2, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_application_stage2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application_stage2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_job_application_stage2 * get_first_job_application_stage2_message()
 * \brief Get the first job_application_stage2 message in the job_application_stage2 message list.
 * \return The first message in the list.
 */
m_job_application_stage2 * get_first_job_application_stage2_message()
{
	return getInternalMessage_job_application_stage2();
}

/** \fn xmachine_message_job_application_stage2 * get_next_job_application_stage2_message(xmachine_message_job_application_stage2 * current)
 * \brief Get the next job_application_stage2 message in the job_application_stage2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_application_stage2 * get_next_job_application_stage2_message(m_job_application_stage2 * current)
{
	return getInternalMessage_job_application_stage2();
}


/* Box filtering functions */




union pu_job_application_stage1 
{
    m_job_application_stage1 *ptr;
    void *ptr_anon;
};

/** \fn void add_job_application_stage1_message(int employee_id, double wage)
 * \brief Add job_application_stage1 message by calling internal and processing.
 * \param employee_id Message variable.
 * \param wage Message variable.
 */
void add_job_application_stage1_message(int employee_id, double wage)
{
    int rc;
	m_job_application_stage1 msg;
    
    msg.employee_id = employee_id;
    msg.wage = wage;
    
    
    rc = MB_AddMessage(b_job_application_stage1, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_application_stage1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application_stage1' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application_stage1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_application_stage1* getInternalMessage_job_application_stage1(void)
{
    static m_job_application_stage1 *msg_prev = NULL;
    union pu_job_application_stage1 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_application_stage1); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_application_stage1' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_application_stage1' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_application_stage1, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_application_stage1' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application_stage1' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_job_application_stage1 * get_first_job_application_stage1_message()
 * \brief Get the first job_application_stage1 message in the job_application_stage1 message list.
 * \return The first message in the list.
 */
m_job_application_stage1 * get_first_job_application_stage1_message()
{
	return getInternalMessage_job_application_stage1();
}

/** \fn xmachine_message_job_application_stage1 * get_next_job_application_stage1_message(xmachine_message_job_application_stage1 * current)
 * \brief Get the next job_application_stage1 message in the job_application_stage1 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_application_stage1 * get_next_job_application_stage1_message(m_job_application_stage1 * current)
{
	return getInternalMessage_job_application_stage1();
}


/* Box filtering functions */




union pu_job_match_stage1 
{
    m_job_match_stage1 *ptr;
    void *ptr_anon;
};

/** \fn void add_job_match_stage1_message(int employer_id, int employee_id, double wage)
 * \brief Add job_match_stage1 message by calling internal and processing.
 * \param employer_id Message variable.
 * \param employee_id Message variable.
 * \param wage Message variable.
 */
void add_job_match_stage1_message(int employer_id, int employee_id, double wage)
{
    int rc;
	m_job_match_stage1 msg;
    
    msg.employer_id = employer_id;
    msg.employee_id = employee_id;
    msg.wage = wage;
    
    
    rc = MB_AddMessage(b_job_match_stage1, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_match_stage1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_match_stage1' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_match_stage1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_match_stage1* getInternalMessage_job_match_stage1(void)
{
    static m_job_match_stage1 *msg_prev = NULL;
    union pu_job_match_stage1 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_match_stage1); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_match_stage1' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_match_stage1' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_match_stage1, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_match_stage1' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_match_stage1' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_job_match_stage1 * get_first_job_match_stage1_message()
 * \brief Get the first job_match_stage1 message in the job_match_stage1 message list.
 * \return The first message in the list.
 */
m_job_match_stage1 * get_first_job_match_stage1_message()
{
	return getInternalMessage_job_match_stage1();
}

/** \fn xmachine_message_job_match_stage1 * get_next_job_match_stage1_message(xmachine_message_job_match_stage1 * current)
 * \brief Get the next job_match_stage1 message in the job_match_stage1 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_match_stage1 * get_next_job_match_stage1_message(m_job_match_stage1 * current)
{
	return getInternalMessage_job_match_stage1();
}


/* Box filtering functions */




union pu_job_change 
{
    m_job_change *ptr;
    void *ptr_anon;
};

/** \fn void add_job_change_message(int employer_id, int employee_id)
 * \brief Add job_change message by calling internal and processing.
 * \param employer_id Message variable.
 * \param employee_id Message variable.
 */
void add_job_change_message(int employer_id, int employee_id)
{
    int rc;
	m_job_change msg;
    
    msg.employer_id = employer_id;
    msg.employee_id = employee_id;
    
    
    rc = MB_AddMessage(b_job_change, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_change' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_change' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_change' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_change* getInternalMessage_job_change(void)
{
    static m_job_change *msg_prev = NULL;
    union pu_job_change msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_change); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_change' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_change' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_change, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_change' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_change' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_job_change * get_first_job_change_message()
 * \brief Get the first job_change message in the job_change message list.
 * \return The first message in the list.
 */
m_job_change * get_first_job_change_message()
{
	return getInternalMessage_job_change();
}

/** \fn xmachine_message_job_change * get_next_job_change_message(xmachine_message_job_change * current)
 * \brief Get the next job_change message in the job_change message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_change * get_next_job_change_message(m_job_change * current)
{
	return getInternalMessage_job_change();
}


/* Box filtering functions */




union pu_vacancy_stage2 
{
    m_vacancy_stage2 *ptr;
    void *ptr_anon;
};

/** \fn void add_vacancy_stage2_message(int employer_id, double wage)
 * \brief Add vacancy_stage2 message by calling internal and processing.
 * \param employer_id Message variable.
 * \param wage Message variable.
 */
void add_vacancy_stage2_message(int employer_id, double wage)
{
    int rc;
	m_vacancy_stage2 msg;
    
    msg.employer_id = employer_id;
    msg.wage = wage;
    
    
    rc = MB_AddMessage(b_vacancy_stage2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'vacancy_stage2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancy_stage2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancy_stage2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_vacancy_stage2* getInternalMessage_vacancy_stage2(void)
{
    static m_vacancy_stage2 *msg_prev = NULL;
    union pu_vacancy_stage2 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_vacancy_stage2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'vacancy_stage2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'vacancy_stage2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_vacancy_stage2, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'vacancy_stage2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancy_stage2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_vacancy_stage2 * get_first_vacancy_stage2_message()
 * \brief Get the first vacancy_stage2 message in the vacancy_stage2 message list.
 * \return The first message in the list.
 */
m_vacancy_stage2 * get_first_vacancy_stage2_message()
{
	return getInternalMessage_vacancy_stage2();
}

/** \fn xmachine_message_vacancy_stage2 * get_next_vacancy_stage2_message(xmachine_message_vacancy_stage2 * current)
 * \brief Get the next vacancy_stage2 message in the vacancy_stage2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_vacancy_stage2 * get_next_vacancy_stage2_message(m_vacancy_stage2 * current)
{
	return getInternalMessage_vacancy_stage2();
}


/* Box filtering functions */




union pu_job_match_stage2 
{
    m_job_match_stage2 *ptr;
    void *ptr_anon;
};

/** \fn void add_job_match_stage2_message(int employer_id, int employee_id, double wage)
 * \brief Add job_match_stage2 message by calling internal and processing.
 * \param employer_id Message variable.
 * \param employee_id Message variable.
 * \param wage Message variable.
 */
void add_job_match_stage2_message(int employer_id, int employee_id, double wage)
{
    int rc;
	m_job_match_stage2 msg;
    
    msg.employer_id = employer_id;
    msg.employee_id = employee_id;
    msg.wage = wage;
    
    
    rc = MB_AddMessage(b_job_match_stage2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_match_stage2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_match_stage2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_match_stage2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_match_stage2* getInternalMessage_job_match_stage2(void)
{
    static m_job_match_stage2 *msg_prev = NULL;
    union pu_job_match_stage2 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_match_stage2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_match_stage2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_match_stage2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_match_stage2, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_match_stage2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_match_stage2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_job_match_stage2 * get_first_job_match_stage2_message()
 * \brief Get the first job_match_stage2 message in the job_match_stage2 message list.
 * \return The first message in the list.
 */
m_job_match_stage2 * get_first_job_match_stage2_message()
{
	return getInternalMessage_job_match_stage2();
}

/** \fn xmachine_message_job_match_stage2 * get_next_job_match_stage2_message(xmachine_message_job_match_stage2 * current)
 * \brief Get the next job_match_stage2 message in the job_match_stage2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_match_stage2 * get_next_job_match_stage2_message(m_job_match_stage2 * current)
{
	return getInternalMessage_job_match_stage2();
}


/* Box filtering functions */




union pu_employment_status 
{
    m_employment_status *ptr;
    void *ptr_anon;
};

/** \fn void add_employment_status_message(int employer_id, double wage, int nshares)
 * \brief Add employment_status message by calling internal and processing.
 * \param employer_id Message variable.
 * \param wage Message variable.
 * \param nshares Message variable.
 */
void add_employment_status_message(int employer_id, double wage, int nshares)
{
    int rc;
	m_employment_status msg;
    
    msg.employer_id = employer_id;
    msg.wage = wage;
    msg.nshares = nshares;
    
    
    rc = MB_AddMessage(b_employment_status, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'employment_status' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'employment_status' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'employment_status' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_employment_status* getInternalMessage_employment_status(void)
{
    static m_employment_status *msg_prev = NULL;
    union pu_employment_status msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_employment_status); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'employment_status' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'employment_status' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_employment_status, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'employment_status' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'employment_status' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_employment_status * get_first_employment_status_message()
 * \brief Get the first employment_status message in the employment_status message list.
 * \return The first message in the list.
 */
m_employment_status * get_first_employment_status_message()
{
	return getInternalMessage_employment_status();
}

/** \fn xmachine_message_employment_status * get_next_employment_status_message(xmachine_message_employment_status * current)
 * \brief Get the next employment_status message in the employment_status message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_employment_status * get_next_employment_status_message(m_employment_status * current)
{
	return getInternalMessage_employment_status();
}


/* Box filtering functions */




union pu_firm_household_wage_payment 
{
    m_firm_household_wage_payment *ptr;
    void *ptr_anon;
};

/** \fn void add_firm_household_wage_payment_message(int firm_id, double wage)
 * \brief Add firm_household_wage_payment message by calling internal and processing.
 * \param firm_id Message variable.
 * \param wage Message variable.
 */
void add_firm_household_wage_payment_message(int firm_id, double wage)
{
    int rc;
	m_firm_household_wage_payment msg;
    
    msg.firm_id = firm_id;
    msg.wage = wage;
    
    
    rc = MB_AddMessage(b_firm_household_wage_payment, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_household_wage_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_household_wage_payment' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_household_wage_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_household_wage_payment* getInternalMessage_firm_household_wage_payment(void)
{
    static m_firm_household_wage_payment *msg_prev = NULL;
    union pu_firm_household_wage_payment msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_household_wage_payment); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_household_wage_payment' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_household_wage_payment' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_household_wage_payment, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_household_wage_payment' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_household_wage_payment' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_firm_household_wage_payment * get_first_firm_household_wage_payment_message()
 * \brief Get the first firm_household_wage_payment message in the firm_household_wage_payment message list.
 * \return The first message in the list.
 */
m_firm_household_wage_payment * get_first_firm_household_wage_payment_message()
{
	return getInternalMessage_firm_household_wage_payment();
}

/** \fn xmachine_message_firm_household_wage_payment * get_next_firm_household_wage_payment_message(xmachine_message_firm_household_wage_payment * current)
 * \brief Get the next firm_household_wage_payment message in the firm_household_wage_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_household_wage_payment * get_next_firm_household_wage_payment_message(m_firm_household_wage_payment * current)
{
	return getInternalMessage_firm_household_wage_payment();
}


/* Box filtering functions */




union pu_firm_bank_loan_request_1 
{
    m_firm_bank_loan_request_1 *ptr;
    void *ptr_anon;
};

/** \fn void add_firm_bank_loan_request_1_message(int firm_id, int bank_id, double amount)
 * \brief Add firm_bank_loan_request_1 message by calling internal and processing.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_firm_bank_loan_request_1_message(int firm_id, int bank_id, double amount)
{
    int rc;
	m_firm_bank_loan_request_1 msg;
    
    msg.firm_id = firm_id;
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_firm_bank_loan_request_1, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_bank_loan_request_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_loan_request_1' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_bank_loan_request_1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_bank_loan_request_1* getInternalMessage_firm_bank_loan_request_1(void)
{
    static m_firm_bank_loan_request_1 *msg_prev = NULL;
    union pu_firm_bank_loan_request_1 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_bank_loan_request_1); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_bank_loan_request_1' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_bank_loan_request_1' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_bank_loan_request_1, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_bank_loan_request_1' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_loan_request_1' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_firm_bank_loan_request_1 * get_first_firm_bank_loan_request_1_message()
 * \brief Get the first firm_bank_loan_request_1 message in the firm_bank_loan_request_1 message list.
 * \return The first message in the list.
 */
m_firm_bank_loan_request_1 * get_first_firm_bank_loan_request_1_message()
{
	return getInternalMessage_firm_bank_loan_request_1();
}

/** \fn xmachine_message_firm_bank_loan_request_1 * get_next_firm_bank_loan_request_1_message(xmachine_message_firm_bank_loan_request_1 * current)
 * \brief Get the next firm_bank_loan_request_1 message in the firm_bank_loan_request_1 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_bank_loan_request_1 * get_next_firm_bank_loan_request_1_message(m_firm_bank_loan_request_1 * current)
{
	return getInternalMessage_firm_bank_loan_request_1();
}


/* Box filtering functions */




union pu_firm_bank_loan_request_2 
{
    m_firm_bank_loan_request_2 *ptr;
    void *ptr_anon;
};

/** \fn void add_firm_bank_loan_request_2_message(int firm_id, int bank_id, double amount)
 * \brief Add firm_bank_loan_request_2 message by calling internal and processing.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_firm_bank_loan_request_2_message(int firm_id, int bank_id, double amount)
{
    int rc;
	m_firm_bank_loan_request_2 msg;
    
    msg.firm_id = firm_id;
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_firm_bank_loan_request_2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_bank_loan_request_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_loan_request_2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_bank_loan_request_2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_bank_loan_request_2* getInternalMessage_firm_bank_loan_request_2(void)
{
    static m_firm_bank_loan_request_2 *msg_prev = NULL;
    union pu_firm_bank_loan_request_2 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_bank_loan_request_2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_bank_loan_request_2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_bank_loan_request_2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_bank_loan_request_2, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_bank_loan_request_2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_loan_request_2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_firm_bank_loan_request_2 * get_first_firm_bank_loan_request_2_message()
 * \brief Get the first firm_bank_loan_request_2 message in the firm_bank_loan_request_2 message list.
 * \return The first message in the list.
 */
m_firm_bank_loan_request_2 * get_first_firm_bank_loan_request_2_message()
{
	return getInternalMessage_firm_bank_loan_request_2();
}

/** \fn xmachine_message_firm_bank_loan_request_2 * get_next_firm_bank_loan_request_2_message(xmachine_message_firm_bank_loan_request_2 * current)
 * \brief Get the next firm_bank_loan_request_2 message in the firm_bank_loan_request_2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_bank_loan_request_2 * get_next_firm_bank_loan_request_2_message(m_firm_bank_loan_request_2 * current)
{
	return getInternalMessage_firm_bank_loan_request_2();
}


/* Box filtering functions */




union pu_bank_firm_loan_acknowledge_1 
{
    m_bank_firm_loan_acknowledge_1 *ptr;
    void *ptr_anon;
};

/** \fn void add_bank_firm_loan_acknowledge_1_message(int bank_id, int firm_id, double amount)
 * \brief Add bank_firm_loan_acknowledge_1 message by calling internal and processing.
 * \param bank_id Message variable.
 * \param firm_id Message variable.
 * \param amount Message variable.
 */
void add_bank_firm_loan_acknowledge_1_message(int bank_id, int firm_id, double amount)
{
    int rc;
	m_bank_firm_loan_acknowledge_1 msg;
    
    msg.bank_id = bank_id;
    msg.firm_id = firm_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_bank_firm_loan_acknowledge_1, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_firm_loan_acknowledge_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_firm_loan_acknowledge_1' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_firm_loan_acknowledge_1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_firm_loan_acknowledge_1* getInternalMessage_bank_firm_loan_acknowledge_1(void)
{
    static m_bank_firm_loan_acknowledge_1 *msg_prev = NULL;
    union pu_bank_firm_loan_acknowledge_1 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_firm_loan_acknowledge_1); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_firm_loan_acknowledge_1' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_firm_loan_acknowledge_1' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_firm_loan_acknowledge_1, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_firm_loan_acknowledge_1' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_firm_loan_acknowledge_1' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bank_firm_loan_acknowledge_1 * get_first_bank_firm_loan_acknowledge_1_message()
 * \brief Get the first bank_firm_loan_acknowledge_1 message in the bank_firm_loan_acknowledge_1 message list.
 * \return The first message in the list.
 */
m_bank_firm_loan_acknowledge_1 * get_first_bank_firm_loan_acknowledge_1_message()
{
	return getInternalMessage_bank_firm_loan_acknowledge_1();
}

/** \fn xmachine_message_bank_firm_loan_acknowledge_1 * get_next_bank_firm_loan_acknowledge_1_message(xmachine_message_bank_firm_loan_acknowledge_1 * current)
 * \brief Get the next bank_firm_loan_acknowledge_1 message in the bank_firm_loan_acknowledge_1 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_firm_loan_acknowledge_1 * get_next_bank_firm_loan_acknowledge_1_message(m_bank_firm_loan_acknowledge_1 * current)
{
	return getInternalMessage_bank_firm_loan_acknowledge_1();
}


/* Box filtering functions */




union pu_bank_firm_loan_acknowledge_2 
{
    m_bank_firm_loan_acknowledge_2 *ptr;
    void *ptr_anon;
};

/** \fn void add_bank_firm_loan_acknowledge_2_message(int bank_id, int firm_id, double amount)
 * \brief Add bank_firm_loan_acknowledge_2 message by calling internal and processing.
 * \param bank_id Message variable.
 * \param firm_id Message variable.
 * \param amount Message variable.
 */
void add_bank_firm_loan_acknowledge_2_message(int bank_id, int firm_id, double amount)
{
    int rc;
	m_bank_firm_loan_acknowledge_2 msg;
    
    msg.bank_id = bank_id;
    msg.firm_id = firm_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_bank_firm_loan_acknowledge_2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_firm_loan_acknowledge_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_firm_loan_acknowledge_2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_firm_loan_acknowledge_2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_firm_loan_acknowledge_2* getInternalMessage_bank_firm_loan_acknowledge_2(void)
{
    static m_bank_firm_loan_acknowledge_2 *msg_prev = NULL;
    union pu_bank_firm_loan_acknowledge_2 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_firm_loan_acknowledge_2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_firm_loan_acknowledge_2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_firm_loan_acknowledge_2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_firm_loan_acknowledge_2, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_firm_loan_acknowledge_2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_firm_loan_acknowledge_2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bank_firm_loan_acknowledge_2 * get_first_bank_firm_loan_acknowledge_2_message()
 * \brief Get the first bank_firm_loan_acknowledge_2 message in the bank_firm_loan_acknowledge_2 message list.
 * \return The first message in the list.
 */
m_bank_firm_loan_acknowledge_2 * get_first_bank_firm_loan_acknowledge_2_message()
{
	return getInternalMessage_bank_firm_loan_acknowledge_2();
}

/** \fn xmachine_message_bank_firm_loan_acknowledge_2 * get_next_bank_firm_loan_acknowledge_2_message(xmachine_message_bank_firm_loan_acknowledge_2 * current)
 * \brief Get the next bank_firm_loan_acknowledge_2 message in the bank_firm_loan_acknowledge_2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_firm_loan_acknowledge_2 * get_next_bank_firm_loan_acknowledge_2_message(m_bank_firm_loan_acknowledge_2 * current)
{
	return getInternalMessage_bank_firm_loan_acknowledge_2();
}


/* Box filtering functions */




union pu_bank_centralbank_debt_request 
{
    m_bank_centralbank_debt_request *ptr;
    void *ptr_anon;
};

/** \fn void add_bank_centralbank_debt_request_message(int bank_id, double amount)
 * \brief Add bank_centralbank_debt_request message by calling internal and processing.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_bank_centralbank_debt_request_message(int bank_id, double amount)
{
    int rc;
	m_bank_centralbank_debt_request msg;
    
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_bank_centralbank_debt_request, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_centralbank_debt_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_centralbank_debt_request' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_centralbank_debt_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_centralbank_debt_request* getInternalMessage_bank_centralbank_debt_request(void)
{
    static m_bank_centralbank_debt_request *msg_prev = NULL;
    union pu_bank_centralbank_debt_request msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_centralbank_debt_request); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_centralbank_debt_request' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_centralbank_debt_request' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_centralbank_debt_request, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_centralbank_debt_request' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_centralbank_debt_request' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bank_centralbank_debt_request * get_first_bank_centralbank_debt_request_message()
 * \brief Get the first bank_centralbank_debt_request message in the bank_centralbank_debt_request message list.
 * \return The first message in the list.
 */
m_bank_centralbank_debt_request * get_first_bank_centralbank_debt_request_message()
{
	return getInternalMessage_bank_centralbank_debt_request();
}

/** \fn xmachine_message_bank_centralbank_debt_request * get_next_bank_centralbank_debt_request_message(xmachine_message_bank_centralbank_debt_request * current)
 * \brief Get the next bank_centralbank_debt_request message in the bank_centralbank_debt_request message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_centralbank_debt_request * get_next_bank_centralbank_debt_request_message(m_bank_centralbank_debt_request * current)
{
	return getInternalMessage_bank_centralbank_debt_request();
}


/* Box filtering functions */




union pu_household_share 
{
    m_household_share *ptr;
    void *ptr_anon;
};

/** \fn void add_household_share_message(double amount)
 * \brief Add household_share message by calling internal and processing.
 * \param amount Message variable.
 */
void add_household_share_message(double amount)
{
    int rc;
	m_household_share msg;
    
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_household_share, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'household_share' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_share' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_share' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_household_share* getInternalMessage_household_share(void)
{
    static m_household_share *msg_prev = NULL;
    union pu_household_share msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_household_share); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'household_share' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'household_share' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_household_share, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'household_share' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_share' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_household_share * get_first_household_share_message()
 * \brief Get the first household_share message in the household_share message list.
 * \return The first message in the list.
 */
m_household_share * get_first_household_share_message()
{
	return getInternalMessage_household_share();
}

/** \fn xmachine_message_household_share * get_next_household_share_message(xmachine_message_household_share * current)
 * \brief Get the next household_share message in the household_share message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_household_share * get_next_household_share_message(m_household_share * current)
{
	return getInternalMessage_household_share();
}


/* Box filtering functions */




union pu_capital_tax 
{
    m_capital_tax *ptr;
    void *ptr_anon;
};

/** \fn void add_capital_tax_message(double amount)
 * \brief Add capital_tax message by calling internal and processing.
 * \param amount Message variable.
 */
void add_capital_tax_message(double amount)
{
    int rc;
	m_capital_tax msg;
    
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_capital_tax, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'capital_tax' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_tax' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_tax' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_capital_tax* getInternalMessage_capital_tax(void)
{
    static m_capital_tax *msg_prev = NULL;
    union pu_capital_tax msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_capital_tax); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'capital_tax' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'capital_tax' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_capital_tax, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'capital_tax' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_tax' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_capital_tax * get_first_capital_tax_message()
 * \brief Get the first capital_tax message in the capital_tax message list.
 * \return The first message in the list.
 */
m_capital_tax * get_first_capital_tax_message()
{
	return getInternalMessage_capital_tax();
}

/** \fn xmachine_message_capital_tax * get_next_capital_tax_message(xmachine_message_capital_tax * current)
 * \brief Get the next capital_tax message in the capital_tax message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_capital_tax * get_next_capital_tax_message(m_capital_tax * current)
{
	return getInternalMessage_capital_tax();
}


/* Box filtering functions */




union pu_labour_tax 
{
    m_labour_tax *ptr;
    void *ptr_anon;
};

/** \fn void add_labour_tax_message(double amount)
 * \brief Add labour_tax message by calling internal and processing.
 * \param amount Message variable.
 */
void add_labour_tax_message(double amount)
{
    int rc;
	m_labour_tax msg;
    
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_labour_tax, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'labour_tax' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'labour_tax' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'labour_tax' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_labour_tax* getInternalMessage_labour_tax(void)
{
    static m_labour_tax *msg_prev = NULL;
    union pu_labour_tax msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_labour_tax); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'labour_tax' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'labour_tax' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_labour_tax, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'labour_tax' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'labour_tax' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_labour_tax * get_first_labour_tax_message()
 * \brief Get the first labour_tax message in the labour_tax message list.
 * \return The first message in the list.
 */
m_labour_tax * get_first_labour_tax_message()
{
	return getInternalMessage_labour_tax();
}

/** \fn xmachine_message_labour_tax * get_next_labour_tax_message(xmachine_message_labour_tax * current)
 * \brief Get the next labour_tax message in the labour_tax message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_labour_tax * get_next_labour_tax_message(m_labour_tax * current)
{
	return getInternalMessage_labour_tax();
}


/* Box filtering functions */




union pu_unemployment_benefit 
{
    m_unemployment_benefit *ptr;
    void *ptr_anon;
};

/** \fn void add_unemployment_benefit_message(double amount)
 * \brief Add unemployment_benefit message by calling internal and processing.
 * \param amount Message variable.
 */
void add_unemployment_benefit_message(double amount)
{
    int rc;
	m_unemployment_benefit msg;
    
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_unemployment_benefit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'unemployment_benefit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'unemployment_benefit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'unemployment_benefit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_unemployment_benefit* getInternalMessage_unemployment_benefit(void)
{
    static m_unemployment_benefit *msg_prev = NULL;
    union pu_unemployment_benefit msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_unemployment_benefit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'unemployment_benefit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'unemployment_benefit' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_unemployment_benefit, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'unemployment_benefit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'unemployment_benefit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_unemployment_benefit * get_first_unemployment_benefit_message()
 * \brief Get the first unemployment_benefit message in the unemployment_benefit message list.
 * \return The first message in the list.
 */
m_unemployment_benefit * get_first_unemployment_benefit_message()
{
	return getInternalMessage_unemployment_benefit();
}

/** \fn xmachine_message_unemployment_benefit * get_next_unemployment_benefit_message(xmachine_message_unemployment_benefit * current)
 * \brief Get the next unemployment_benefit message in the unemployment_benefit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_unemployment_benefit * get_next_unemployment_benefit_message(m_unemployment_benefit * current)
{
	return getInternalMessage_unemployment_benefit();
}


/* Box filtering functions */




union pu_general_benefit 
{
    m_general_benefit *ptr;
    void *ptr_anon;
};

/** \fn void add_general_benefit_message(double amount)
 * \brief Add general_benefit message by calling internal and processing.
 * \param amount Message variable.
 */
void add_general_benefit_message(double amount)
{
    int rc;
	m_general_benefit msg;
    
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_general_benefit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'general_benefit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'general_benefit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'general_benefit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_general_benefit* getInternalMessage_general_benefit(void)
{
    static m_general_benefit *msg_prev = NULL;
    union pu_general_benefit msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_general_benefit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'general_benefit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'general_benefit' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_general_benefit, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'general_benefit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'general_benefit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_general_benefit * get_first_general_benefit_message()
 * \brief Get the first general_benefit message in the general_benefit message list.
 * \return The first message in the list.
 */
m_general_benefit * get_first_general_benefit_message()
{
	return getInternalMessage_general_benefit();
}

/** \fn xmachine_message_general_benefit * get_next_general_benefit_message(xmachine_message_general_benefit * current)
 * \brief Get the next general_benefit message in the general_benefit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_general_benefit * get_next_general_benefit_message(m_general_benefit * current)
{
	return getInternalMessage_general_benefit();
}


/* Box filtering functions */




union pu_fund_request 
{
    m_fund_request *ptr;
    void *ptr_anon;
};

/** \fn void add_fund_request_message(int firm_id, double amount)
 * \brief Add fund_request message by calling internal and processing.
 * \param firm_id Message variable.
 * \param amount Message variable.
 */
void add_fund_request_message(int firm_id, double amount)
{
    int rc;
	m_fund_request msg;
    
    msg.firm_id = firm_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_fund_request, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'fund_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fund_request' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fund_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_fund_request* getInternalMessage_fund_request(void)
{
    static m_fund_request *msg_prev = NULL;
    union pu_fund_request msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_fund_request); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'fund_request' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'fund_request' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_fund_request, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'fund_request' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fund_request' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_fund_request * get_first_fund_request_message()
 * \brief Get the first fund_request message in the fund_request message list.
 * \return The first message in the list.
 */
m_fund_request * get_first_fund_request_message()
{
	return getInternalMessage_fund_request();
}

/** \fn xmachine_message_fund_request * get_next_fund_request_message(xmachine_message_fund_request * current)
 * \brief Get the next fund_request message in the fund_request message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_fund_request * get_next_fund_request_message(m_fund_request * current)
{
	return getInternalMessage_fund_request();
}


/* Box filtering functions */




union pu_fund_request_ack 
{
    m_fund_request_ack *ptr;
    void *ptr_anon;
};

/** \fn void add_fund_request_ack_message(int firm_id, double amount)
 * \brief Add fund_request_ack message by calling internal and processing.
 * \param firm_id Message variable.
 * \param amount Message variable.
 */
void add_fund_request_ack_message(int firm_id, double amount)
{
    int rc;
	m_fund_request_ack msg;
    
    msg.firm_id = firm_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_fund_request_ack, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'fund_request_ack' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fund_request_ack' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'fund_request_ack' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_fund_request_ack* getInternalMessage_fund_request_ack(void)
{
    static m_fund_request_ack *msg_prev = NULL;
    union pu_fund_request_ack msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_fund_request_ack); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'fund_request_ack' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'fund_request_ack' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_fund_request_ack, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'fund_request_ack' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'fund_request_ack' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_fund_request_ack * get_first_fund_request_ack_message()
 * \brief Get the first fund_request_ack message in the fund_request_ack message list.
 * \return The first message in the list.
 */
m_fund_request_ack * get_first_fund_request_ack_message()
{
	return getInternalMessage_fund_request_ack();
}

/** \fn xmachine_message_fund_request_ack * get_next_fund_request_ack_message(xmachine_message_fund_request_ack * current)
 * \brief Get the next fund_request_ack message in the fund_request_ack message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_fund_request_ack * get_next_fund_request_ack_message(m_fund_request_ack * current)
{
	return getInternalMessage_fund_request_ack();
}


/* Box filtering functions */




union pu_new_entrant_loan 
{
    m_new_entrant_loan *ptr;
    void *ptr_anon;
};

/** \fn void add_new_entrant_loan_message(int firm_id, int bank_id, double amount)
 * \brief Add new_entrant_loan message by calling internal and processing.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_new_entrant_loan_message(int firm_id, int bank_id, double amount)
{
    int rc;
	m_new_entrant_loan msg;
    
    msg.firm_id = firm_id;
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_new_entrant_loan, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'new_entrant_loan' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'new_entrant_loan' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'new_entrant_loan' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_new_entrant_loan* getInternalMessage_new_entrant_loan(void)
{
    static m_new_entrant_loan *msg_prev = NULL;
    union pu_new_entrant_loan msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_new_entrant_loan); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'new_entrant_loan' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'new_entrant_loan' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_new_entrant_loan, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'new_entrant_loan' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'new_entrant_loan' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_new_entrant_loan * get_first_new_entrant_loan_message()
 * \brief Get the first new_entrant_loan message in the new_entrant_loan message list.
 * \return The first message in the list.
 */
m_new_entrant_loan * get_first_new_entrant_loan_message()
{
	return getInternalMessage_new_entrant_loan();
}

/** \fn xmachine_message_new_entrant_loan * get_next_new_entrant_loan_message(xmachine_message_new_entrant_loan * current)
 * \brief Get the next new_entrant_loan message in the new_entrant_loan message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_new_entrant_loan * get_next_new_entrant_loan_message(m_new_entrant_loan * current)
{
	return getInternalMessage_new_entrant_loan();
}


/* Box filtering functions */




union pu_firm_bank_interest_on_loan 
{
    m_firm_bank_interest_on_loan *ptr;
    void *ptr_anon;
};

/** \fn void add_firm_bank_interest_on_loan_message(int bank_id, double amount)
 * \brief Add firm_bank_interest_on_loan message by calling internal and processing.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_firm_bank_interest_on_loan_message(int bank_id, double amount)
{
    int rc;
	m_firm_bank_interest_on_loan msg;
    
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_firm_bank_interest_on_loan, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_bank_interest_on_loan' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_interest_on_loan' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_bank_interest_on_loan' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_bank_interest_on_loan* getInternalMessage_firm_bank_interest_on_loan(void)
{
    static m_firm_bank_interest_on_loan *msg_prev = NULL;
    union pu_firm_bank_interest_on_loan msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_bank_interest_on_loan); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_bank_interest_on_loan' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_bank_interest_on_loan' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_bank_interest_on_loan, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_bank_interest_on_loan' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_interest_on_loan' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_firm_bank_interest_on_loan * get_first_firm_bank_interest_on_loan_message()
 * \brief Get the first firm_bank_interest_on_loan message in the firm_bank_interest_on_loan message list.
 * \return The first message in the list.
 */
m_firm_bank_interest_on_loan * get_first_firm_bank_interest_on_loan_message()
{
	return getInternalMessage_firm_bank_interest_on_loan();
}

/** \fn xmachine_message_firm_bank_interest_on_loan * get_next_firm_bank_interest_on_loan_message(xmachine_message_firm_bank_interest_on_loan * current)
 * \brief Get the next firm_bank_interest_on_loan message in the firm_bank_interest_on_loan message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_bank_interest_on_loan * get_next_firm_bank_interest_on_loan_message(m_firm_bank_interest_on_loan * current)
{
	return getInternalMessage_firm_bank_interest_on_loan();
}


/* Box filtering functions */




union pu_loan_writeoff 
{
    m_loan_writeoff *ptr;
    void *ptr_anon;
};

/** \fn void add_loan_writeoff_message(int bank_id, double amount)
 * \brief Add loan_writeoff message by calling internal and processing.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_loan_writeoff_message(int bank_id, double amount)
{
    int rc;
	m_loan_writeoff msg;
    
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_loan_writeoff, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'loan_writeoff' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_writeoff' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_writeoff' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_loan_writeoff* getInternalMessage_loan_writeoff(void)
{
    static m_loan_writeoff *msg_prev = NULL;
    union pu_loan_writeoff msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_loan_writeoff); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'loan_writeoff' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'loan_writeoff' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_loan_writeoff, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'loan_writeoff' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_writeoff' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_loan_writeoff * get_first_loan_writeoff_message()
 * \brief Get the first loan_writeoff message in the loan_writeoff message list.
 * \return The first message in the list.
 */
m_loan_writeoff * get_first_loan_writeoff_message()
{
	return getInternalMessage_loan_writeoff();
}

/** \fn xmachine_message_loan_writeoff * get_next_loan_writeoff_message(xmachine_message_loan_writeoff * current)
 * \brief Get the next loan_writeoff message in the loan_writeoff message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_loan_writeoff * get_next_loan_writeoff_message(m_loan_writeoff * current)
{
	return getInternalMessage_loan_writeoff();
}


/* Box filtering functions */




union pu_firm_bank_insolvent_account 
{
    m_firm_bank_insolvent_account *ptr;
    void *ptr_anon;
};

/** \fn void add_firm_bank_insolvent_account_message(int bank_id, double liquidity)
 * \brief Add firm_bank_insolvent_account message by calling internal and processing.
 * \param bank_id Message variable.
 * \param liquidity Message variable.
 */
void add_firm_bank_insolvent_account_message(int bank_id, double liquidity)
{
    int rc;
	m_firm_bank_insolvent_account msg;
    
    msg.bank_id = bank_id;
    msg.liquidity = liquidity;
    
    
    rc = MB_AddMessage(b_firm_bank_insolvent_account, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_bank_insolvent_account' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_insolvent_account' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_bank_insolvent_account' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_bank_insolvent_account* getInternalMessage_firm_bank_insolvent_account(void)
{
    static m_firm_bank_insolvent_account *msg_prev = NULL;
    union pu_firm_bank_insolvent_account msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_bank_insolvent_account); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_bank_insolvent_account' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_bank_insolvent_account' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_bank_insolvent_account, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_bank_insolvent_account' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_bank_insolvent_account' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_firm_bank_insolvent_account * get_first_firm_bank_insolvent_account_message()
 * \brief Get the first firm_bank_insolvent_account message in the firm_bank_insolvent_account message list.
 * \return The first message in the list.
 */
m_firm_bank_insolvent_account * get_first_firm_bank_insolvent_account_message()
{
	return getInternalMessage_firm_bank_insolvent_account();
}

/** \fn xmachine_message_firm_bank_insolvent_account * get_next_firm_bank_insolvent_account_message(xmachine_message_firm_bank_insolvent_account * current)
 * \brief Get the next firm_bank_insolvent_account message in the firm_bank_insolvent_account message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_bank_insolvent_account * get_next_firm_bank_insolvent_account_message(m_firm_bank_insolvent_account * current)
{
	return getInternalMessage_firm_bank_insolvent_account();
}


/* Box filtering functions */




union pu_firm_net_profit 
{
    m_firm_net_profit *ptr;
    void *ptr_anon;
};

/** \fn void add_firm_net_profit_message(int id, int isconstructor, double net_income)
 * \brief Add firm_net_profit message by calling internal and processing.
 * \param id Message variable.
 * \param isconstructor Message variable.
 * \param net_income Message variable.
 */
void add_firm_net_profit_message(int id, int isconstructor, double net_income)
{
    int rc;
	m_firm_net_profit msg;
    
    msg.id = id;
    msg.isconstructor = isconstructor;
    msg.net_income = net_income;
    
    
    rc = MB_AddMessage(b_firm_net_profit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_net_profit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_net_profit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_net_profit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_net_profit* getInternalMessage_firm_net_profit(void)
{
    static m_firm_net_profit *msg_prev = NULL;
    union pu_firm_net_profit msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_net_profit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_net_profit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_net_profit' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_net_profit, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_net_profit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_net_profit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_firm_net_profit * get_first_firm_net_profit_message()
 * \brief Get the first firm_net_profit message in the firm_net_profit message list.
 * \return The first message in the list.
 */
m_firm_net_profit * get_first_firm_net_profit_message()
{
	return getInternalMessage_firm_net_profit();
}

/** \fn xmachine_message_firm_net_profit * get_next_firm_net_profit_message(xmachine_message_firm_net_profit * current)
 * \brief Get the next firm_net_profit message in the firm_net_profit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_net_profit * get_next_firm_net_profit_message(m_firm_net_profit * current)
{
	return getInternalMessage_firm_net_profit();
}


/* Box filtering functions */




union pu_bank_net_profit 
{
    m_bank_net_profit *ptr;
    void *ptr_anon;
};

/** \fn void add_bank_net_profit_message(int id, double net_income)
 * \brief Add bank_net_profit message by calling internal and processing.
 * \param id Message variable.
 * \param net_income Message variable.
 */
void add_bank_net_profit_message(int id, double net_income)
{
    int rc;
	m_bank_net_profit msg;
    
    msg.id = id;
    msg.net_income = net_income;
    
    
    rc = MB_AddMessage(b_bank_net_profit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_net_profit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_net_profit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_net_profit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_net_profit* getInternalMessage_bank_net_profit(void)
{
    static m_bank_net_profit *msg_prev = NULL;
    union pu_bank_net_profit msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_net_profit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_net_profit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_net_profit' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_net_profit, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_net_profit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_net_profit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bank_net_profit * get_first_bank_net_profit_message()
 * \brief Get the first bank_net_profit message in the bank_net_profit message list.
 * \return The first message in the list.
 */
m_bank_net_profit * get_first_bank_net_profit_message()
{
	return getInternalMessage_bank_net_profit();
}

/** \fn xmachine_message_bank_net_profit * get_next_bank_net_profit_message(xmachine_message_bank_net_profit * current)
 * \brief Get the next bank_net_profit message in the bank_net_profit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_net_profit * get_next_bank_net_profit_message(m_bank_net_profit * current)
{
	return getInternalMessage_bank_net_profit();
}


/* Box filtering functions */




union pu_bank_centralbank_interest_payment 
{
    m_bank_centralbank_interest_payment *ptr;
    void *ptr_anon;
};

/** \fn void add_bank_centralbank_interest_payment_message(int id, double amount)
 * \brief Add bank_centralbank_interest_payment message by calling internal and processing.
 * \param id Message variable.
 * \param amount Message variable.
 */
void add_bank_centralbank_interest_payment_message(int id, double amount)
{
    int rc;
	m_bank_centralbank_interest_payment msg;
    
    msg.id = id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_bank_centralbank_interest_payment, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_centralbank_interest_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_centralbank_interest_payment* getInternalMessage_bank_centralbank_interest_payment(void)
{
    static m_bank_centralbank_interest_payment *msg_prev = NULL;
    union pu_bank_centralbank_interest_payment msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_centralbank_interest_payment); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_centralbank_interest_payment' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_centralbank_interest_payment, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_centralbank_interest_payment' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_centralbank_interest_payment' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bank_centralbank_interest_payment * get_first_bank_centralbank_interest_payment_message()
 * \brief Get the first bank_centralbank_interest_payment message in the bank_centralbank_interest_payment message list.
 * \return The first message in the list.
 */
m_bank_centralbank_interest_payment * get_first_bank_centralbank_interest_payment_message()
{
	return getInternalMessage_bank_centralbank_interest_payment();
}

/** \fn xmachine_message_bank_centralbank_interest_payment * get_next_bank_centralbank_interest_payment_message(xmachine_message_bank_centralbank_interest_payment * current)
 * \brief Get the next bank_centralbank_interest_payment message in the bank_centralbank_interest_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_centralbank_interest_payment * get_next_bank_centralbank_interest_payment_message(m_bank_centralbank_interest_payment * current)
{
	return getInternalMessage_bank_centralbank_interest_payment();
}


/* Box filtering functions */




union pu_bank_centralbank_debt_payment 
{
    m_bank_centralbank_debt_payment *ptr;
    void *ptr_anon;
};

/** \fn void add_bank_centralbank_debt_payment_message(int id, double amount)
 * \brief Add bank_centralbank_debt_payment message by calling internal and processing.
 * \param id Message variable.
 * \param amount Message variable.
 */
void add_bank_centralbank_debt_payment_message(int id, double amount)
{
    int rc;
	m_bank_centralbank_debt_payment msg;
    
    msg.id = id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_bank_centralbank_debt_payment, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_centralbank_debt_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_centralbank_debt_payment* getInternalMessage_bank_centralbank_debt_payment(void)
{
    static m_bank_centralbank_debt_payment *msg_prev = NULL;
    union pu_bank_centralbank_debt_payment msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_centralbank_debt_payment); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_centralbank_debt_payment' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_centralbank_debt_payment, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_centralbank_debt_payment' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_centralbank_debt_payment' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bank_centralbank_debt_payment * get_first_bank_centralbank_debt_payment_message()
 * \brief Get the first bank_centralbank_debt_payment message in the bank_centralbank_debt_payment message list.
 * \return The first message in the list.
 */
m_bank_centralbank_debt_payment * get_first_bank_centralbank_debt_payment_message()
{
	return getInternalMessage_bank_centralbank_debt_payment();
}

/** \fn xmachine_message_bank_centralbank_debt_payment * get_next_bank_centralbank_debt_payment_message(xmachine_message_bank_centralbank_debt_payment * current)
 * \brief Get the next bank_centralbank_debt_payment message in the bank_centralbank_debt_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_centralbank_debt_payment * get_next_bank_centralbank_debt_payment_message(m_bank_centralbank_debt_payment * current)
{
	return getInternalMessage_bank_centralbank_debt_payment();
}


/* Box filtering functions */




union pu_gov_centralbank_debt_request 
{
    m_gov_centralbank_debt_request *ptr;
    void *ptr_anon;
};

/** \fn void add_gov_centralbank_debt_request_message(double amount)
 * \brief Add gov_centralbank_debt_request message by calling internal and processing.
 * \param amount Message variable.
 */
void add_gov_centralbank_debt_request_message(double amount)
{
    int rc;
	m_gov_centralbank_debt_request msg;
    
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_gov_centralbank_debt_request, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'gov_centralbank_debt_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_centralbank_debt_request' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'gov_centralbank_debt_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_gov_centralbank_debt_request* getInternalMessage_gov_centralbank_debt_request(void)
{
    static m_gov_centralbank_debt_request *msg_prev = NULL;
    union pu_gov_centralbank_debt_request msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_gov_centralbank_debt_request); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'gov_centralbank_debt_request' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'gov_centralbank_debt_request' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_gov_centralbank_debt_request, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'gov_centralbank_debt_request' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_centralbank_debt_request' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_gov_centralbank_debt_request * get_first_gov_centralbank_debt_request_message()
 * \brief Get the first gov_centralbank_debt_request message in the gov_centralbank_debt_request message list.
 * \return The first message in the list.
 */
m_gov_centralbank_debt_request * get_first_gov_centralbank_debt_request_message()
{
	return getInternalMessage_gov_centralbank_debt_request();
}

/** \fn xmachine_message_gov_centralbank_debt_request * get_next_gov_centralbank_debt_request_message(xmachine_message_gov_centralbank_debt_request * current)
 * \brief Get the next gov_centralbank_debt_request message in the gov_centralbank_debt_request message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_gov_centralbank_debt_request * get_next_gov_centralbank_debt_request_message(m_gov_centralbank_debt_request * current)
{
	return getInternalMessage_gov_centralbank_debt_request();
}


/* Box filtering functions */




union pu_gov_centralbank_debt_payment 
{
    m_gov_centralbank_debt_payment *ptr;
    void *ptr_anon;
};

/** \fn void add_gov_centralbank_debt_payment_message(double amount)
 * \brief Add gov_centralbank_debt_payment message by calling internal and processing.
 * \param amount Message variable.
 */
void add_gov_centralbank_debt_payment_message(double amount)
{
    int rc;
	m_gov_centralbank_debt_payment msg;
    
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_gov_centralbank_debt_payment, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'gov_centralbank_debt_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_centralbank_debt_payment' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'gov_centralbank_debt_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_gov_centralbank_debt_payment* getInternalMessage_gov_centralbank_debt_payment(void)
{
    static m_gov_centralbank_debt_payment *msg_prev = NULL;
    union pu_gov_centralbank_debt_payment msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_gov_centralbank_debt_payment); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'gov_centralbank_debt_payment' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'gov_centralbank_debt_payment' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_gov_centralbank_debt_payment, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'gov_centralbank_debt_payment' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_centralbank_debt_payment' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_gov_centralbank_debt_payment * get_first_gov_centralbank_debt_payment_message()
 * \brief Get the first gov_centralbank_debt_payment message in the gov_centralbank_debt_payment message list.
 * \return The first message in the list.
 */
m_gov_centralbank_debt_payment * get_first_gov_centralbank_debt_payment_message()
{
	return getInternalMessage_gov_centralbank_debt_payment();
}

/** \fn xmachine_message_gov_centralbank_debt_payment * get_next_gov_centralbank_debt_payment_message(xmachine_message_gov_centralbank_debt_payment * current)
 * \brief Get the next gov_centralbank_debt_payment message in the gov_centralbank_debt_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_gov_centralbank_debt_payment * get_next_gov_centralbank_debt_payment_message(m_gov_centralbank_debt_payment * current)
{
	return getInternalMessage_gov_centralbank_debt_payment();
}


/* Box filtering functions */




union pu_centralbank_government_profit 
{
    m_centralbank_government_profit *ptr;
    void *ptr_anon;
};

/** \fn void add_centralbank_government_profit_message(double amount)
 * \brief Add centralbank_government_profit message by calling internal and processing.
 * \param amount Message variable.
 */
void add_centralbank_government_profit_message(double amount)
{
    int rc;
	m_centralbank_government_profit msg;
    
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_centralbank_government_profit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'centralbank_government_profit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'centralbank_government_profit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'centralbank_government_profit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_centralbank_government_profit* getInternalMessage_centralbank_government_profit(void)
{
    static m_centralbank_government_profit *msg_prev = NULL;
    union pu_centralbank_government_profit msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_centralbank_government_profit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'centralbank_government_profit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'centralbank_government_profit' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_centralbank_government_profit, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'centralbank_government_profit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'centralbank_government_profit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_centralbank_government_profit * get_first_centralbank_government_profit_message()
 * \brief Get the first centralbank_government_profit message in the centralbank_government_profit message list.
 * \return The first message in the list.
 */
m_centralbank_government_profit * get_first_centralbank_government_profit_message()
{
	return getInternalMessage_centralbank_government_profit();
}

/** \fn xmachine_message_centralbank_government_profit * get_next_centralbank_government_profit_message(xmachine_message_centralbank_government_profit * current)
 * \brief Get the next centralbank_government_profit message in the centralbank_government_profit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_centralbank_government_profit * get_next_centralbank_government_profit_message(m_centralbank_government_profit * current)
{
	return getInternalMessage_centralbank_government_profit();
}


/* Box filtering functions */




union pu_housing_price 
{
    m_housing_price *ptr;
    void *ptr_anon;
};

/** \fn void add_housing_price_message(double price)
 * \brief Add housing_price message by calling internal and processing.
 * \param price Message variable.
 */
void add_housing_price_message(double price)
{
    int rc;
	m_housing_price msg;
    
    msg.price = price;
    
    
    rc = MB_AddMessage(b_housing_price, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'housing_price' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'housing_price' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'housing_price' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_housing_price* getInternalMessage_housing_price(void)
{
    static m_housing_price *msg_prev = NULL;
    union pu_housing_price msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_housing_price); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'housing_price' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'housing_price' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_housing_price, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'housing_price' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'housing_price' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_housing_price * get_first_housing_price_message()
 * \brief Get the first housing_price message in the housing_price message list.
 * \return The first message in the list.
 */
m_housing_price * get_first_housing_price_message()
{
	return getInternalMessage_housing_price();
}

/** \fn xmachine_message_housing_price * get_next_housing_price_message(xmachine_message_housing_price * current)
 * \brief Get the next housing_price message in the housing_price message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_housing_price * get_next_housing_price_message(m_housing_price * current)
{
	return getInternalMessage_housing_price();
}


/* Box filtering functions */




union pu_buy_housing 
{
    m_buy_housing *ptr;
    void *ptr_anon;
};

/** \fn void add_buy_housing_message(int buyer_id, int bank_id, double liquidity, double quarterly_income, double quarterly_mortgage_paid)
 * \brief Add buy_housing message by calling internal and processing.
 * \param buyer_id Message variable.
 * \param bank_id Message variable.
 * \param liquidity Message variable.
 * \param quarterly_income Message variable.
 * \param quarterly_mortgage_paid Message variable.
 */
void add_buy_housing_message(int buyer_id, int bank_id, double liquidity, double quarterly_income, double quarterly_mortgage_paid)
{
    int rc;
	m_buy_housing msg;
    
    msg.buyer_id = buyer_id;
    msg.bank_id = bank_id;
    msg.liquidity = liquidity;
    msg.quarterly_income = quarterly_income;
    msg.quarterly_mortgage_paid = quarterly_mortgage_paid;
    
    
    rc = MB_AddMessage(b_buy_housing, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'buy_housing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'buy_housing' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'buy_housing' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_buy_housing* getInternalMessage_buy_housing(void)
{
    static m_buy_housing *msg_prev = NULL;
    union pu_buy_housing msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_buy_housing); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'buy_housing' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'buy_housing' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_buy_housing, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'buy_housing' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'buy_housing' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_buy_housing * get_first_buy_housing_message()
 * \brief Get the first buy_housing message in the buy_housing message list.
 * \return The first message in the list.
 */
m_buy_housing * get_first_buy_housing_message()
{
	return getInternalMessage_buy_housing();
}

/** \fn xmachine_message_buy_housing * get_next_buy_housing_message(xmachine_message_buy_housing * current)
 * \brief Get the next buy_housing message in the buy_housing message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_buy_housing * get_next_buy_housing_message(m_buy_housing * current)
{
	return getInternalMessage_buy_housing();
}


/* Box filtering functions */




union pu_sell_housing 
{
    m_sell_housing *ptr;
    void *ptr_anon;
};

/** \fn void add_sell_housing_message(int seller_id, double price, int quantity, int type)
 * \brief Add sell_housing message by calling internal and processing.
 * \param seller_id Message variable.
 * \param price Message variable.
 * \param quantity Message variable.
 * \param type Message variable.
 */
void add_sell_housing_message(int seller_id, double price, int quantity, int type)
{
    int rc;
	m_sell_housing msg;
    
    msg.seller_id = seller_id;
    msg.price = price;
    msg.quantity = quantity;
    msg.type = type;
    
    
    rc = MB_AddMessage(b_sell_housing, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'sell_housing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sell_housing' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sell_housing' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_sell_housing* getInternalMessage_sell_housing(void)
{
    static m_sell_housing *msg_prev = NULL;
    union pu_sell_housing msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_sell_housing); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'sell_housing' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'sell_housing' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_sell_housing, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'sell_housing' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sell_housing' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_sell_housing * get_first_sell_housing_message()
 * \brief Get the first sell_housing message in the sell_housing message list.
 * \return The first message in the list.
 */
m_sell_housing * get_first_sell_housing_message()
{
	return getInternalMessage_sell_housing();
}

/** \fn xmachine_message_sell_housing * get_next_sell_housing_message(xmachine_message_sell_housing * current)
 * \brief Get the next sell_housing message in the sell_housing message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_sell_housing * get_next_sell_housing_message(m_sell_housing * current)
{
	return getInternalMessage_sell_housing();
}


/* Box filtering functions */




union pu_bought_housing 
{
    m_bought_housing *ptr;
    void *ptr_anon;
};

/** \fn void add_bought_housing_message(int buyer_id, double liquidity_spent, double mortgage_used, double annuity)
 * \brief Add bought_housing message by calling internal and processing.
 * \param buyer_id Message variable.
 * \param liquidity_spent Message variable.
 * \param mortgage_used Message variable.
 * \param annuity Message variable.
 */
void add_bought_housing_message(int buyer_id, double liquidity_spent, double mortgage_used, double annuity)
{
    int rc;
	m_bought_housing msg;
    
    msg.buyer_id = buyer_id;
    msg.liquidity_spent = liquidity_spent;
    msg.mortgage_used = mortgage_used;
    msg.annuity = annuity;
    
    
    rc = MB_AddMessage(b_bought_housing, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bought_housing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bought_housing' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bought_housing' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bought_housing* getInternalMessage_bought_housing(void)
{
    static m_bought_housing *msg_prev = NULL;
    union pu_bought_housing msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bought_housing); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bought_housing' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bought_housing' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bought_housing, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bought_housing' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bought_housing' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bought_housing * get_first_bought_housing_message()
 * \brief Get the first bought_housing message in the bought_housing message list.
 * \return The first message in the list.
 */
m_bought_housing * get_first_bought_housing_message()
{
	return getInternalMessage_bought_housing();
}

/** \fn xmachine_message_bought_housing * get_next_bought_housing_message(xmachine_message_bought_housing * current)
 * \brief Get the next bought_housing message in the bought_housing message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bought_housing * get_next_bought_housing_message(m_bought_housing * current)
{
	return getInternalMessage_bought_housing();
}


/* Box filtering functions */




union pu_sold_housing 
{
    m_sold_housing *ptr;
    void *ptr_anon;
};

/** \fn void add_sold_housing_message(int seller_id, int quantity_sold, double price_sold)
 * \brief Add sold_housing message by calling internal and processing.
 * \param seller_id Message variable.
 * \param quantity_sold Message variable.
 * \param price_sold Message variable.
 */
void add_sold_housing_message(int seller_id, int quantity_sold, double price_sold)
{
    int rc;
	m_sold_housing msg;
    
    msg.seller_id = seller_id;
    msg.quantity_sold = quantity_sold;
    msg.price_sold = price_sold;
    
    
    rc = MB_AddMessage(b_sold_housing, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'sold_housing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sold_housing' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sold_housing' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_sold_housing* getInternalMessage_sold_housing(void)
{
    static m_sold_housing *msg_prev = NULL;
    union pu_sold_housing msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_sold_housing); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'sold_housing' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'sold_housing' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_sold_housing, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'sold_housing' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sold_housing' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_sold_housing * get_first_sold_housing_message()
 * \brief Get the first sold_housing message in the sold_housing message list.
 * \return The first message in the list.
 */
m_sold_housing * get_first_sold_housing_message()
{
	return getInternalMessage_sold_housing();
}

/** \fn xmachine_message_sold_housing * get_next_sold_housing_message(xmachine_message_sold_housing * current)
 * \brief Get the next sold_housing message in the sold_housing message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_sold_housing * get_next_sold_housing_message(m_sold_housing * current)
{
	return getInternalMessage_sold_housing();
}


/* Box filtering functions */




union pu_bank_reagency_credibility 
{
    m_bank_reagency_credibility *ptr;
    void *ptr_anon;
};

/** \fn void add_bank_reagency_credibility_message(int bank_id, double equity, double risky_assets)
 * \brief Add bank_reagency_credibility message by calling internal and processing.
 * \param bank_id Message variable.
 * \param equity Message variable.
 * \param risky_assets Message variable.
 */
void add_bank_reagency_credibility_message(int bank_id, double equity, double risky_assets)
{
    int rc;
	m_bank_reagency_credibility msg;
    
    msg.bank_id = bank_id;
    msg.equity = equity;
    msg.risky_assets = risky_assets;
    
    
    rc = MB_AddMessage(b_bank_reagency_credibility, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_reagency_credibility' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_reagency_credibility' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_reagency_credibility' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_reagency_credibility* getInternalMessage_bank_reagency_credibility(void)
{
    static m_bank_reagency_credibility *msg_prev = NULL;
    union pu_bank_reagency_credibility msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_reagency_credibility); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_reagency_credibility' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_reagency_credibility' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_reagency_credibility, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_reagency_credibility' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_reagency_credibility' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bank_reagency_credibility * get_first_bank_reagency_credibility_message()
 * \brief Get the first bank_reagency_credibility message in the bank_reagency_credibility message list.
 * \return The first message in the list.
 */
m_bank_reagency_credibility * get_first_bank_reagency_credibility_message()
{
	return getInternalMessage_bank_reagency_credibility();
}

/** \fn xmachine_message_bank_reagency_credibility * get_next_bank_reagency_credibility_message(xmachine_message_bank_reagency_credibility * current)
 * \brief Get the next bank_reagency_credibility message in the bank_reagency_credibility message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_reagency_credibility * get_next_bank_reagency_credibility_message(m_bank_reagency_credibility * current)
{
	return getInternalMessage_bank_reagency_credibility();
}


/* Box filtering functions */




union pu_mortgage_requests 
{
    m_mortgage_requests *ptr;
    void *ptr_anon;
};

/** \fn void add_mortgage_requests_message(int bank_id, double amount)
 * \brief Add mortgage_requests message by calling internal and processing.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_mortgage_requests_message(int bank_id, double amount)
{
    int rc;
	m_mortgage_requests msg;
    
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_mortgage_requests, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'mortgage_requests' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_requests' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mortgage_requests' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_mortgage_requests* getInternalMessage_mortgage_requests(void)
{
    static m_mortgage_requests *msg_prev = NULL;
    union pu_mortgage_requests msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_mortgage_requests); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'mortgage_requests' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'mortgage_requests' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_mortgage_requests, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'mortgage_requests' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_requests' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_mortgage_requests * get_first_mortgage_requests_message()
 * \brief Get the first mortgage_requests message in the mortgage_requests message list.
 * \return The first message in the list.
 */
m_mortgage_requests * get_first_mortgage_requests_message()
{
	return getInternalMessage_mortgage_requests();
}

/** \fn xmachine_message_mortgage_requests * get_next_mortgage_requests_message(xmachine_message_mortgage_requests * current)
 * \brief Get the next mortgage_requests message in the mortgage_requests message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_mortgage_requests * get_next_mortgage_requests_message(m_mortgage_requests * current)
{
	return getInternalMessage_mortgage_requests();
}


/* Box filtering functions */




union pu_mortgage_payment_from_sale 
{
    m_mortgage_payment_from_sale *ptr;
    void *ptr_anon;
};

/** \fn void add_mortgage_payment_from_sale_message(int bank_id, double amount)
 * \brief Add mortgage_payment_from_sale message by calling internal and processing.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_mortgage_payment_from_sale_message(int bank_id, double amount)
{
    int rc;
	m_mortgage_payment_from_sale msg;
    
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_mortgage_payment_from_sale, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'mortgage_payment_from_sale' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_mortgage_payment_from_sale* getInternalMessage_mortgage_payment_from_sale(void)
{
    static m_mortgage_payment_from_sale *msg_prev = NULL;
    union pu_mortgage_payment_from_sale msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_mortgage_payment_from_sale); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'mortgage_payment_from_sale' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_mortgage_payment_from_sale, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'mortgage_payment_from_sale' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_payment_from_sale' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_mortgage_payment_from_sale * get_first_mortgage_payment_from_sale_message()
 * \brief Get the first mortgage_payment_from_sale message in the mortgage_payment_from_sale message list.
 * \return The first message in the list.
 */
m_mortgage_payment_from_sale * get_first_mortgage_payment_from_sale_message()
{
	return getInternalMessage_mortgage_payment_from_sale();
}

/** \fn xmachine_message_mortgage_payment_from_sale * get_next_mortgage_payment_from_sale_message(xmachine_message_mortgage_payment_from_sale * current)
 * \brief Get the next mortgage_payment_from_sale message in the mortgage_payment_from_sale message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_mortgage_payment_from_sale * get_next_mortgage_payment_from_sale_message(m_mortgage_payment_from_sale * current)
{
	return getInternalMessage_mortgage_payment_from_sale();
}


/* Box filtering functions */




union pu_mortgage_payment 
{
    m_mortgage_payment *ptr;
    void *ptr_anon;
};

/** \fn void add_mortgage_payment_message(int bank_id, double interest, double principal)
 * \brief Add mortgage_payment message by calling internal and processing.
 * \param bank_id Message variable.
 * \param interest Message variable.
 * \param principal Message variable.
 */
void add_mortgage_payment_message(int bank_id, double interest, double principal)
{
    int rc;
	m_mortgage_payment msg;
    
    msg.bank_id = bank_id;
    msg.interest = interest;
    msg.principal = principal;
    
    
    rc = MB_AddMessage(b_mortgage_payment, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'mortgage_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_payment' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mortgage_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_mortgage_payment* getInternalMessage_mortgage_payment(void)
{
    static m_mortgage_payment *msg_prev = NULL;
    union pu_mortgage_payment msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_mortgage_payment); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'mortgage_payment' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'mortgage_payment' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_mortgage_payment, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'mortgage_payment' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_payment' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_mortgage_payment * get_first_mortgage_payment_message()
 * \brief Get the first mortgage_payment message in the mortgage_payment message list.
 * \return The first message in the list.
 */
m_mortgage_payment * get_first_mortgage_payment_message()
{
	return getInternalMessage_mortgage_payment();
}

/** \fn xmachine_message_mortgage_payment * get_next_mortgage_payment_message(xmachine_message_mortgage_payment * current)
 * \brief Get the next mortgage_payment message in the mortgage_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_mortgage_payment * get_next_mortgage_payment_message(m_mortgage_payment * current)
{
	return getInternalMessage_mortgage_payment();
}


/* Box filtering functions */




union pu_mortgage_writeoff 
{
    m_mortgage_writeoff *ptr;
    void *ptr_anon;
};

/** \fn void add_mortgage_writeoff_message(int bank_id, double amount)
 * \brief Add mortgage_writeoff message by calling internal and processing.
 * \param bank_id Message variable.
 * \param amount Message variable.
 */
void add_mortgage_writeoff_message(int bank_id, double amount)
{
    int rc;
	m_mortgage_writeoff msg;
    
    msg.bank_id = bank_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_mortgage_writeoff, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'mortgage_writeoff' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_writeoff' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mortgage_writeoff' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_mortgage_writeoff* getInternalMessage_mortgage_writeoff(void)
{
    static m_mortgage_writeoff *msg_prev = NULL;
    union pu_mortgage_writeoff msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_mortgage_writeoff); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'mortgage_writeoff' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'mortgage_writeoff' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_mortgage_writeoff, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'mortgage_writeoff' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mortgage_writeoff' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_mortgage_writeoff * get_first_mortgage_writeoff_message()
 * \brief Get the first mortgage_writeoff message in the mortgage_writeoff message list.
 * \return The first message in the list.
 */
m_mortgage_writeoff * get_first_mortgage_writeoff_message()
{
	return getInternalMessage_mortgage_writeoff();
}

/** \fn xmachine_message_mortgage_writeoff * get_next_mortgage_writeoff_message(xmachine_message_mortgage_writeoff * current)
 * \brief Get the next mortgage_writeoff message in the mortgage_writeoff message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_mortgage_writeoff * get_next_mortgage_writeoff_message(m_mortgage_writeoff * current)
{
	return getInternalMessage_mortgage_writeoff();
}


/* Box filtering functions */




union pu_housing_transactions_summary 
{
    m_housing_transactions_summary *ptr;
    void *ptr_anon;
};

/** \fn void add_housing_transactions_summary_message(int quantity, double avg_price)
 * \brief Add housing_transactions_summary message by calling internal and processing.
 * \param quantity Message variable.
 * \param avg_price Message variable.
 */
void add_housing_transactions_summary_message(int quantity, double avg_price)
{
    int rc;
	m_housing_transactions_summary msg;
    
    msg.quantity = quantity;
    msg.avg_price = avg_price;
    
    
    rc = MB_AddMessage(b_housing_transactions_summary, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'housing_transactions_summary' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'housing_transactions_summary' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'housing_transactions_summary' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_housing_transactions_summary* getInternalMessage_housing_transactions_summary(void)
{
    static m_housing_transactions_summary *msg_prev = NULL;
    union pu_housing_transactions_summary msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_housing_transactions_summary); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'housing_transactions_summary' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'housing_transactions_summary' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_housing_transactions_summary, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'housing_transactions_summary' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'housing_transactions_summary' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_housing_transactions_summary * get_first_housing_transactions_summary_message()
 * \brief Get the first housing_transactions_summary message in the housing_transactions_summary message list.
 * \return The first message in the list.
 */
m_housing_transactions_summary * get_first_housing_transactions_summary_message()
{
	return getInternalMessage_housing_transactions_summary();
}

/** \fn xmachine_message_housing_transactions_summary * get_next_housing_transactions_summary_message(xmachine_message_housing_transactions_summary * current)
 * \brief Get the next housing_transactions_summary message in the housing_transactions_summary message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_housing_transactions_summary * get_next_housing_transactions_summary_message(m_housing_transactions_summary * current)
{
	return getInternalMessage_housing_transactions_summary();
}


/* Box filtering functions */




union pu_firm_foreignsector_amount 
{
    m_firm_foreignsector_amount *ptr;
    void *ptr_anon;
};

/** \fn void add_firm_foreignsector_amount_message(int id, int amount)
 * \brief Add firm_foreignsector_amount message by calling internal and processing.
 * \param id Message variable.
 * \param amount Message variable.
 */
void add_firm_foreignsector_amount_message(int id, int amount)
{
    int rc;
	m_firm_foreignsector_amount msg;
    
    msg.id = id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_firm_foreignsector_amount, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_foreignsector_amount' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_foreignsector_amount' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_foreignsector_amount' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_foreignsector_amount* getInternalMessage_firm_foreignsector_amount(void)
{
    static m_firm_foreignsector_amount *msg_prev = NULL;
    union pu_firm_foreignsector_amount msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_foreignsector_amount); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_foreignsector_amount' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_foreignsector_amount' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_foreignsector_amount, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_foreignsector_amount' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_foreignsector_amount' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_firm_foreignsector_amount * get_first_firm_foreignsector_amount_message()
 * \brief Get the first firm_foreignsector_amount message in the firm_foreignsector_amount message list.
 * \return The first message in the list.
 */
m_firm_foreignsector_amount * get_first_firm_foreignsector_amount_message()
{
	return getInternalMessage_firm_foreignsector_amount();
}

/** \fn xmachine_message_firm_foreignsector_amount * get_next_firm_foreignsector_amount_message(xmachine_message_firm_foreignsector_amount * current)
 * \brief Get the next firm_foreignsector_amount message in the firm_foreignsector_amount message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_foreignsector_amount * get_next_firm_foreignsector_amount_message(m_firm_foreignsector_amount * current)
{
	return getInternalMessage_firm_foreignsector_amount();
}


/* Box filtering functions */




union pu_centralbank_firm_revenues 
{
    m_centralbank_firm_revenues *ptr;
    void *ptr_anon;
};

/** \fn void add_centralbank_firm_revenues_message(int id, double revenues)
 * \brief Add centralbank_firm_revenues message by calling internal and processing.
 * \param id Message variable.
 * \param revenues Message variable.
 */
void add_centralbank_firm_revenues_message(int id, double revenues)
{
    int rc;
	m_centralbank_firm_revenues msg;
    
    msg.id = id;
    msg.revenues = revenues;
    
    
    rc = MB_AddMessage(b_centralbank_firm_revenues, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'centralbank_firm_revenues' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'centralbank_firm_revenues' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'centralbank_firm_revenues' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_centralbank_firm_revenues* getInternalMessage_centralbank_firm_revenues(void)
{
    static m_centralbank_firm_revenues *msg_prev = NULL;
    union pu_centralbank_firm_revenues msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_centralbank_firm_revenues); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'centralbank_firm_revenues' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'centralbank_firm_revenues' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_centralbank_firm_revenues, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'centralbank_firm_revenues' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'centralbank_firm_revenues' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_centralbank_firm_revenues * get_first_centralbank_firm_revenues_message()
 * \brief Get the first centralbank_firm_revenues message in the centralbank_firm_revenues message list.
 * \return The first message in the list.
 */
m_centralbank_firm_revenues * get_first_centralbank_firm_revenues_message()
{
	return getInternalMessage_centralbank_firm_revenues();
}

/** \fn xmachine_message_centralbank_firm_revenues * get_next_centralbank_firm_revenues_message(xmachine_message_centralbank_firm_revenues * current)
 * \brief Get the next centralbank_firm_revenues message in the centralbank_firm_revenues message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_centralbank_firm_revenues * get_next_centralbank_firm_revenues_message(m_centralbank_firm_revenues * current)
{
	return getInternalMessage_centralbank_firm_revenues();
}


/* Box filtering functions */




union pu_foreignsector_centralbank_revenues 
{
    m_foreignsector_centralbank_revenues *ptr;
    void *ptr_anon;
};

/** \fn void add_foreignsector_centralbank_revenues_message(int id, double fx_revenues)
 * \brief Add foreignsector_centralbank_revenues message by calling internal and processing.
 * \param id Message variable.
 * \param fx_revenues Message variable.
 */
void add_foreignsector_centralbank_revenues_message(int id, double fx_revenues)
{
    int rc;
	m_foreignsector_centralbank_revenues msg;
    
    msg.id = id;
    msg.fx_revenues = fx_revenues;
    
    
    rc = MB_AddMessage(b_foreignsector_centralbank_revenues, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'foreignsector_centralbank_revenues' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'foreignsector_centralbank_revenues' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'foreignsector_centralbank_revenues' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_foreignsector_centralbank_revenues* getInternalMessage_foreignsector_centralbank_revenues(void)
{
    static m_foreignsector_centralbank_revenues *msg_prev = NULL;
    union pu_foreignsector_centralbank_revenues msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_foreignsector_centralbank_revenues); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'foreignsector_centralbank_revenues' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'foreignsector_centralbank_revenues' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_foreignsector_centralbank_revenues, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'foreignsector_centralbank_revenues' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'foreignsector_centralbank_revenues' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_foreignsector_centralbank_revenues * get_first_foreignsector_centralbank_revenues_message()
 * \brief Get the first foreignsector_centralbank_revenues message in the foreignsector_centralbank_revenues message list.
 * \return The first message in the list.
 */
m_foreignsector_centralbank_revenues * get_first_foreignsector_centralbank_revenues_message()
{
	return getInternalMessage_foreignsector_centralbank_revenues();
}

/** \fn xmachine_message_foreignsector_centralbank_revenues * get_next_foreignsector_centralbank_revenues_message(xmachine_message_foreignsector_centralbank_revenues * current)
 * \brief Get the next foreignsector_centralbank_revenues message in the foreignsector_centralbank_revenues message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_foreignsector_centralbank_revenues * get_next_foreignsector_centralbank_revenues_message(m_foreignsector_centralbank_revenues * current)
{
	return getInternalMessage_foreignsector_centralbank_revenues();
}

