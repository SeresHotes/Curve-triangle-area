#include "op_node.h"
#include "polka_read.h"

#include <stdint.h>
#include <stdlib.h>

void op_node_soft_cpy(op_node_t* dest, op_node_t *src)
{
	*dest = *src;
}
void op_node_hard_cpy(op_node_t* dest, op_node_t *src)
{
	op_node_soft_cpy(dest, src);
	dest->args = malloc(dest->count * sizeof(dest->args[0]));
	for(int i = 0; i < dest->count; i++)
	{
		dest->args[i] = op_node_create_clear();
		op_node_hard_cpy(dest->args[i], src->args[i]);
	}
}

op_node_t * op_node_create_clear()
{
	op_node_t * n = malloc(sizeof(op_node_t));
	n->args = 0;
	return n;
}

void op_node_config_unar(op_node_t *node, op_un_t op, op_node_t *arg)
{
	node->op_base = UNAR;
	node->op = op;
	node->args = realloc(node->args, sizeof(node->args[0]));
	node->args[0] = arg;
	node->count = 1;
}
void op_node_config_binar(op_node_t *node, op_un_t op, op_node_t *arg1, op_node_t *arg2)
{
	node->op_base = BINAR;
	node->op = op;
	node->args = realloc(node->args, 2 * sizeof(node->args[0]));
	node->args[0] = arg1;
	node->args[1] = arg2;
	node->count = 2;
}
void op_node_config_const(op_node_t *node, double value)
{
	node->op_base = CONST;
	if(node->args)
		free(node->args);
	node->args = 0;
	node->value = value;
	node->count = 0;
}
void op_node_config_x(op_node_t *node)
{
	node->op_base = SPEC_X;
	if(node->args)
		free(node->args);
	node->args = 0;
	node->count = 0;
}



op_node_t *op_node_create_unar(op_un_t op, op_node_t *arg)
{
	op_node_t *n = malloc(sizeof(n[0]));
	n->op_base = UNAR;
	n->op = op;
	n->args = malloc(sizeof(n->args[0]));
	n->args[0] = arg;
	n->count = 1;
	return n;
}
op_node_t *op_node_create_binar(op_bin_t op, op_node_t *arg1, op_node_t *arg2)
{
	op_node_t *n = malloc(sizeof(n[0]));
	n->op_base = BINAR;
	n->op = op;
	n->args = malloc(2 * sizeof(n->args[0]));
	n->args[0] = arg1;
	n->args[1] = arg2;
	n->count = 2;
	return n;
}
op_node_t *op_node_create_const(double number)
{

	op_node_t *n = malloc(sizeof(n[0]));
	n->op_base = CONST;
	n->value = number;
	n->args = 0;
	n->count = 0;
	return n;
}

op_node_t *op_node_create_x()
{
	op_node_t *n = malloc(sizeof(n[0]));
	n->op_base = SPEC_X;
	n->args = 0;
	n->count = 0;
	return n;
}

void op_node_delete(op_node_t *node)
{
	if(node->args)
		free(node->args);
	free(node);
}
void op_node_delete_tree(op_node_t *node)
{
	for(int i = 0; i < node->count; i++)
	{
		op_node_delete_tree(node->args[i]);
	}
	op_node_delete(node);
}
