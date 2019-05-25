/*
 * This file contains math functions for calculating math function intersections
 * and integrals
 *
 *
 *
 */





#include <math.h>
#include "my_math.h"


/*
 * Constant used for restriction of Runge method. It garants that function won't
 * have looping
 */
#define MAX_N 1ull << 32

double aproach_chord(math_func_t f, math_func_t g, double left, double right);

double aproach_newton(math_func_t f, math_func_t f_der,
  math_func_t g, math_func_t g_der, double x);

double convexValue(math_func_t f, math_func_t g, double left, double right);

double integral_simpson(math_func_t f, double left, double right, int n_2);

void swaplf(double *a, double *b)
{
	double t = *a;
	*a = *b;
	*b = t;
}

/*
 * Calculates intersection of two functions using combining method of chord
 * method and Newton method
 */
double root(math_func_t f, math_func_t g, math_func_t f_der, math_func_t g_der,
  double left, double right, double eps)
{
	if(convexValue(f, g, left, right) * ((f(right) - g(right)) - (f(left) - g(left))) < 0)
		swaplf(&left, &right);
	while(fabsl(f(right) - f(left)) > 2 * eps || right - left > 2 * eps)
	{
		double l = aproach_chord(f, g, left, right);
		double r = aproach_newton(f, g, f_der, g_der, right);
		left = l;
		right = r;
	}
	return right / 2 + left / 2;
}


/*
 * Step of chord method of root finding
 */
double aproach_chord(math_func_t f, math_func_t g, double left, double right)
{
    double l = f(left) - g(left);
    double r = f(right) - g(right);
    return (l * right - r * left) / (l - r);
}

/*
 * Step of Newton method of root finding
 */
double aproach_newton(math_func_t f, math_func_t g,
	math_func_t f_der, math_func_t g_der, double x)
{
    return x - (f(x) - g(x)) / (f_der(x) - g_der(x));
}

/*
 * Calculates how function is convex
 */
double convexValue(math_func_t f, math_func_t g, double left, double right)
{
	double m = left / 2.0 + right / 2.0;
    return (f(m) - g(m))  - ((f(left) - g(left)) + (f(right) - g(right))) / 2;
}

/*
 * Calculates integral by Runge method using Simpso method as base
 * return:
 *	0 - no problem
 *	-1 - integral can't be calculated for this function
 */
int integral_accurate_runge(double *result, math_func_t f, double left,
	double right, double eps, unsigned long long n_start)
{
	int ret = 0;
	double s1, s2;
	unsigned long long n = n_start / 2;
	s1 = integral_simpson(f, left, right, n);
	do {
		n *= 2;
		s2 = s1;
		s1 = integral_simpson(f, left, right, n);

		if(n < MAX_N) // Garants no looping
		{
			ret = -1;
			break;
		}
	} while(fabsl(s1 - s2) / 15); //for simpson method
	*result = s1;
	return ret;
}

/*
 * Calculates integral by Simpson method
 */
double integral_simpson(math_func_t f, double left, double right, int n_2)
{
	double d = (right - left) / n_2 / 2;
	double sum = 0;
	if(right > left)
		for(double x = left; x < right; x += 2 * d)
		{
			sum += f(x - d) + 4 * f(x) + f(x + d);
		}
	else
		for(double x = left; x > right; x += 2 * d)
		{
			sum += f(x - d) + 4 * f(x) + f(x + d);
		}
	sum *= d / 3;
	return sum;
}
