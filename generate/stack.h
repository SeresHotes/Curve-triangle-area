/*
 * This module is used to create operation tree from polka notation
 */
 
#ifndef STACK_H
#define STACK_H
#include "op_node.h"
#include <stdlib.h>

typedef op_node_t* T;

typedef struct stack_node {
	T val;
	struct stack_node *next;
	struct stack_node *prev;
} stack_node;

stack_node* stack_push(stack_node *end, T val);

stack_node* stack_pop(stack_node *end, T *val);

#endif /*STACK_H*/
