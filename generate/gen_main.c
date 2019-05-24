#include "op_node.h"
#include "gen_samples.h"
#include "gen_main.h"

#define TRACE_ERROR() fprintf(stderr, "ERROR: %s", __FUNCTION__)


void _gen_make_fun(op_node_t *top, FILE *file);

void gen_init(FILE *file)
{
	fprintf(file , "%s\n", "section .text");
}
void gen_make_fun(FILE *file, char *fun_name, op_node_t *top)
{
	gen_sample_init(file, fun_name);
	_gen_make_fun(top, file);
	gen_sample_stop(file);
}

void _gen_make_fun(op_node_t *top, FILE *file)
{
	switch(top->op_base)
	{
	case SPEC_X:
		gen_sample_x(file);
		break;
	case CONST:
		gen_sample_const(file, top->value);
		break;
	case UNAR:
		_gen_make_fun(top->args[0], file);
		gen_sample_unar(file, top->op);
		break;
	case BINAR:
		_gen_make_fun(top->args[0], file);
		_gen_make_fun(top->args[1], file);
		gen_sample_binar(file, top->op);
		break;
	default:
		TRACE_ERROR();
	}
}
