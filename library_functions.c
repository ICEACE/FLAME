/**
 * \file  library_functions.c
 * \brief Holds user created library functions.
 */

#include "header.h"
#include "library_header.h"

/** \fn int random_int(int min,int max)
 * \brief Returns an integer between and including min and max
 * \param min The minimum integer.
 * \param max The maximum integer.
 * \return The random integer.
 */
int random_int(int min,int max)
{
    return min + rand() % (max - min + 1);
}

double max(double a, double b)
{
    return (a >= b) ? a : b;
}

double min(double a, double b)
{
    return (a <= b) ? a : b;
}

/*
 * \fn: int random_number(int a, int b)
 * \brief: Return a random interger between a and b inclusive.
 */
int random_number(int a, int b)
{
	return (a+(int)(((double)b)*rand()/(RAND_MAX+1.0)));
}
