/*
 * This module is used to generate asm code of each type of operation
 */
#include "gen_samples.h"
#include "polka_read.h"
#include <stdio.h>
#include "op_node.h"

void gen_sample_init(FILE* file, char *fun_name)
{
	fprintf(file, "global %s\n", fun_name);
	fprintf(file, "EXTERN exp\n");
	fprintf(file, "%s:\n", fun_name);
	fprintf(file, "\tpush ebp\n");
	fprintf(file, "\tmov ebp, esp\n\n");
	fprintf(file, "\tpush ebx\n");

	fprintf(file, "\tfinit\n");
}

void gen_sample_const(FILE* file, int op, double value)
{

	switch(op)
	{
	case CON_E:
		value = 2.7182818284590452354;
		break;
	case CON_PI:
		value = 3.14159265358979323846;
		break;
	default:
		break;
	}

	fprintf(file, "\tpush %u\n", ((uint32_t*)&value)[1]);
	fprintf(file, "\tpush %u\n\n", ((uint32_t*)&value)[0]);

}

void gen_sample_x(FILE* file)
{
	fprintf(file, "\tmov ecx, dword[ebp + 8]\n"
				  "\tmov edx, dword[ebp + 12]\n"
				  "\tpush edx\n"
				  "\tpush ecx\n\n");
}

void gen_sample_unar(FILE* file, int op)
{
	fprintf(file, "\tfld qword[esp]\n");

	switch(op)
	{
	case EXP:
		fprintf(file, "\tmov ebx, esp\n");
		fprintf(file, "\tand esp, -16\n");
		fprintf(file, "\tsub esp, 16\n");
		fprintf(file, "\tfstp qword[esp]\n");
		fprintf(file, "\tcall exp\n");
		fprintf(file, "\tmov esp, ebx\n");

		break;
	case COS:
		fprintf(file, "\tfcos\n");
		break;
	case SIN:
		fprintf(file, "\tfsin\n");
		break;
	case TAN:
		fprintf(file, "\tfptan\n"
					  "\tfxchg\n"
					  "\tfstp ST1\n");
		break;
	case CTG:
		fprintf(file, "\tfptan\n"
					  "\tfdivrp\n");
		break;
	case SPE_1_DIX_X_2:
		fprintf(file, "\tfld ST0\n"
					  "\tfmulp\n"
					  "\tfld1\n"
					  "\tfdivrp ST1, ST0\n");
	}
	fprintf(file, "\tfstp qword[esp]\n\n");
}

void gen_sample_binar(FILE* file, int op)
{
	fprintf(file, "\tfld qword[esp + 8]\n");
	fprintf(file, "\tfld qword[esp]\n");

	switch(op)
	{
	case PLU:
		fprintf(file, "\tfaddp\n");
		break;
	case MIN:
		fprintf(file, "\tfsubp\n");
		break;
	case DIV:
		fprintf(file, "\tfdivp st1, st0\n");
		break;
	case MUL:
		fprintf(file, "\tfmulp\n");
		break;
	}
	fprintf(file, "\tadd esp, 8\n");
	fprintf(file, "\tfstp qword[esp]\n\n");
}
void gen_sample_stop(FILE *file)
{
	fprintf(file, "\tfld qword[esp]\n");
	fprintf(file, "\tadd esp, 8\n");

	fprintf(file, "\tpop ebx\n");
	fprintf(file, "\tpop ebp\n");
	fprintf(file, "\tret\n");
}
