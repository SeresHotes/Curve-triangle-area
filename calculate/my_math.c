#include <math.h>
#include "my_math.h"

//typedef double (*math_func_t)(double);

double aproach_chord(math_func_t f, math_func_t g, double left, double right);

double aproach_newton(math_func_t f, math_func_t f_der,
  math_func_t g, math_func_t g_der, double x);
double convexValue(math_func_t f, math_func_t g, double left, double right);

void swaplf(double *a, double *b)
{
	double t = *a;
	*a = *b;
	*b = t;
}

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

double aproach_chord(math_func_t f, math_func_t g, double left, double right)
{
    double l = f(left) - g(left);
    double r = f(right) - g(right);
    return (l * right - r * left) / (l - r);
}

double aproach_newton(math_func_t f, math_func_t g,
	math_func_t f_der, math_func_t g_der, double x)
{
    return x - (f(x) - g(x)) / (f_der(x) - g_der(x));
}

double convexValue(math_func_t f, math_func_t g, double left, double right)
{
	double m = left / 2.0 + right / 2.0;
    return (f(m) - g(m))  - ((f(left) - g(left)) + (f(right) - g(right))) / 2;
}

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
