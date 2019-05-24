#include "stack.h"
#include "op_node.h"
#include <stdlib.h>


stack_node* stack_push(stack_node *end, T val)
{
	stack_node *n = malloc(sizeof(n[0]));
	n->val = val;
	n->prev = end;
	n->next = 0;
	
	if(end)
		end->next = n;
	return n;
}


stack_node* stack_pop(stack_node *end, T *val)
{
	if(val)
		*val = end->val;
	
	stack_node *p = end->prev;
	if(p)
		p->next = 0;
	free(end);
	return p;
}