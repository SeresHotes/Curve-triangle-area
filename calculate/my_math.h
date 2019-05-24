#ifndef MY_MATH_H
#define MY_MATH_H

void swaplf(double *a, double *b);

typedef double (*math_func_t)(double);
double root(math_func_t f, math_func_t g, math_func_t f_der, math_func_t g_der,
  double left, double right, double eps);


double integral_simpson(math_func_t f, double left, double right, int n_2);

#endif /*MY_MATH_H*/
