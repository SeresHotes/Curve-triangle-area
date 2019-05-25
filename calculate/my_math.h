/*
 * This file contains math functions for calculating math function intersections
 * and integrals
 *
 *
 *
 */

#ifndef MY_MATH_H
#define MY_MATH_H



void swaplf(double *a, double *b);

/*
 * Type for math functions y = f(x)
 */
typedef double (*math_func_t)(double);


/*
 * Calculates intersection of two functions using combining method of chord
 * method and Newton method
 */
double root(math_func_t f, math_func_t g, math_func_t f_der, math_func_t g_der,
  double left, double right, double eps);


/*
 * Calculates integral by Runge method using Simpso method as base
 * return:
 *	0 - no problem
 *	-1 - integral can't be calculated for this function
 */
int integral_accurate_runge(double *result, math_func_t f, double left,
	double right, double eps, unsigned long long n_start);

#endif /*MY_MATH_H*/
