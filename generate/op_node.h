/*
 * This module provides base for all program too.
 * It is used for creating nodes of operation tree (express tree)
 *
 */

#ifndef OP_NODE_H
#define OP_NODE_H
#include "polka_read.h"
#include <stdio.h>
#include <stdint.h>

/*
 * Basic structure node, containg operation
 */
typedef struct op_node_t{
	op_base_t op_base;
	int op;
	struct op_node_t **args; // Reference to nodes, which the operation is perfomed on
	int count;
	double value;
} op_node_t;




/*
 * Reads file containig inverse polka notation function and makes operarion tree
 */
op_node_t * op_read_and_get_tree(FILE *file);

/*
 * Allocates node in heap memmory
 */
op_node_t * op_node_create_clear();


/*
 * Copies just fields from src to dest
 */
void op_node_soft_cpy(op_node_t* dest, op_node_t *src);

/*
 * Copies all operation tree from src to dest
 */
void op_node_hard_cpy(op_node_t* dest, op_node_t *src);

/*
 * Theese functions change existing node to another operation whithout allocating
 */
void op_node_config_unar(op_node_t *node, op_un_t op, op_node_t *arg);
void op_node_config_binar(op_node_t *node, op_un_t op, op_node_t *arg1, op_node_t *arg2);
void op_node_config_const(op_node_t *node, double value);
void op_node_config_x(op_node_t *node);


/*
 * Theese functions allocate new node
 */
op_node_t *op_node_create_unar(op_un_t op, op_node_t *arg);
op_node_t *op_node_create_binar(op_bin_t op, op_node_t *arg1, op_node_t *arg2);
op_node_t *op_node_create_const(op_const_t op, double number);
op_node_t *op_node_create_x();

void op_node_delete(op_node_t *node);
void op_node_delete_tree(op_node_t *node);
#endif // OP_NODE_H
