/**
 * \file  timing.c
 * \brief Timing routines
 */

#include "header.h"

#include <sys/time.h>

/** \fn double get_time(void)
 * \brief Returns an elapsed time on the calling processor 
 * \return Time in seconds since an arbitrary time in the past.
 */


double get_time(void) {
    struct timeval now;    
    
    /* in some implementations, clock() wraps round after 36 minutes.
     * use gettimeofday() instead, which gives us time since the Epoch 
     */
# ifndef S_SPLINT_S
    gettimeofday(&now, NULL);
# endif
    
    /* return time in secs */
    return now.tv_sec + (now.tv_usec * 1.e-6);
}

