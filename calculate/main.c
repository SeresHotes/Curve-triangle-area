#include <stdio.h>
#include <stdlib.h>
#include "my_math.h"
#include "console_commands.h"
#include <math.h>


extern double f1(double x);
extern double f2(double x);
extern double f3(double x);
extern double f1_der(double x);
extern double f2_der(double x);
extern double f3_der(double x);



int command_root_f(int argc, char *argv[])
{
	if(argc < 3)
	{
		fprintf(stderr, "%s\n", "ERROR: not enough arguments. See --help");
		return 1;
	}
	int k1, k2;

	sscanf(argv[1], "%d", &k1);
	sscanf(argv[2], "%d", &k2);
	math_func_t t1, t11;
	math_func_t t2, t21;
	switch(k1)
	{
	case 1:
		t1 = f1;
		t11 = f1_der;
		break;
	case 2:
		t1 = f2;
		t11 = f2_der;
		break;
	case 3:
		t1 = f3;
		t11 = f3_der;
		break;
	default:
		fprintf(stderr, "%s\n", "ERROR: bad arguments");
		return 1;
	}
	switch(k2)
	{
	case 1:
		t2 = f1;
		t21 = f1_der;
		break;
	case 2:
		t2 = f2;
		t21 = f2_der;
		break;
	case 3:
		t2 = f3;
		t21 = f3_der;
		break;
	default:
		fprintf(stderr, "%s\n", "ERROR: bad arguments");
		return 1;
	}
	printf("%lf\n", root(t1, t2, t11, t21, global.left, global.right, global.eps));
	return 3;
}

int command_border_f(int argc, char *argv[])
{
	if(argc < 3)
	{
		fprintf(stderr, "%s\n", "ERROR: not enough arguments. See --help");
		return 1;
	}

	sscanf(argv[1], "%lf", &global.left);
	sscanf(argv[2], "%lf", &global.right);
	if(global.right < global.left)
		swaplf(&global.left, &global.right);

	return 3;
}
int command_read_f(int argc, char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "%s\n", "ERROR: not enough arguments. See --help");
		return 1;
	}

	FILE *file = fopen(argv[1], "r");
	if(!file)
	{
		fprintf(stderr, "%s\n", "ERROR: file doesn't exist");
		return 2;
	}

	fscanf(file, "%lf", &global.left);
	fscanf(file, "%lf", &global.right);
	if(global.right < global.left)
		swaplf(&global.left, &global.right);
	fclose(file);
	return 2;

}

int command_area_f(int argc, char *argv[])
{
	if(argc < 1)
	{
		fprintf(stderr, "%s\n", "ERROR: not enough arguments. See --help");
		return 1;
	}

	double x12, x23, x13;
	double eps1 = global.eps / 10;
	double eps2 = global.eps / 10;
	int n = 1 / eps2 + 1;

	x12 = root(f1, f2, f1_der, f2_der, global.left, global.right, eps1);
	x23 = root(f2, f3, f2_der, f3_der, global.left, global.right, eps1);
	x13 = root(f1, f3, f1_der, f3_der, global.left, global.right, eps1);

	double sum = 0;
	double i;
	int err;
	err |= integral_accurate_runge(&i, f1, x12, x13, eps2, n);
	sum += i;
	err |= integral_accurate_runge(&i, f3, x13, x23, eps2, n);
	sum += i;
	err |= integral_accurate_runge(&i, f2, x23, x12, eps2, n);
	sum += i;
	if(err)
	{
		fprintf(stderr, "%s\n", "Function is not integrable by riman");
		return 1;
	}
	printf("%f\n", fabs(sum));
	return 1;

}

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		int command_area_f(argc - 1, argv + 1);
		return 0;
	}

	command_t command_root =
	{
		.name_ext = "--root",
		.name_red = "",
		.desc_args = "<function number> <function number>",
		.description = "calculates intersection of functions",
		.func = command_root_f
	};
	command_t command_border =
	{
		.name_ext = "--border",
		.name_red = "-b",
		.desc_args = "<left border> <right border>",
		.description = "sets function bordes in calculations",
		.func = command_border_f
	};
	command_t command_read =
	{
		.name_ext = "--read",
		.name_red = "-r",
		.desc_args = "<file>",
		.description = "reads from the file border values",
		.func = command_read_f
	};
	command_t command_area =
	{
		.name_ext = "--area",
		.name_red = "-a",
		.desc_args = "",
		.description = "calculates area of curved triangle formed by 3 functions",
		.func = command_area_f
	};



	global.command_array_size = 5;
	global.command_array = malloc(sizeof(command_t) * global.command_array_size);
	global.command_array[0] = command_root;
	global.command_array[1] = command_help;
	global.command_array[2] = command_read;
	global.command_array[3] = command_border;
	global.command_array[4] = command_area;



	command_realize(argc, argv);
	return 0;

}
