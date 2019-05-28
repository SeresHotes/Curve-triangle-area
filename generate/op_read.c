
#include "op_read.h"
#include "op_node.h"
#include "stack.h"
#include "polka_read.h"
#include <stdio.h>



/*
 * Reads file containig inverse polka notation function and makes operarion tree
 * It pushes operation in stack, if the operarion is a const or x. When in reaches
 * binary or unary operation, two or one operations respectively are poped and
 * referenced by the operation.
 */
op_node_t * op_read_and_get_tree(FILE *file)
{

	char str[100];
	int op_base;
	int op;
	double value;
	stack_node * st = 0;
	while(fscanf(file, "%100s", str) != EOF)
	{
		polka_realize_word(str, &op_base, &op, &value);

		if(op_base == CONST)
		{
			op_node_t *t = op_node_create_const(op, value);
			st = stack_push(st, t);
			continue;
		}
		if(op_base == SPEC_X)
		{
			op_node_t *t = op_node_create_x();
			st = stack_push(st, t);
			continue;
		}
		if(op_base == UNAR)
		{
			op_node_t *a1;
			st = stack_pop(st, &a1);
			op_node_t *t = op_node_create_unar(op, a1);
			st = stack_push(st, t);
			continue;
		}
		if(op_base == BINAR)
		{
			op_node_t *a1, *a2;
			st = stack_pop(st, &a2);
			st = stack_pop(st, &a1);
			op_node_t *t = op_node_create_binar(op, a1, a2);
			st = stack_push(st, t);
			continue;
		}
	}
	op_node_t *t = st->val;
	stack_pop(st, 0);
	return t;
}
