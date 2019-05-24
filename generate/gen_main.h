#ifndef GEN_MAIN_H
#define GEN_MAIN_H

#include <stdio.h>
#include "op_node.h"


void gen_init(FILE *file);
void gen_make_fun(FILE *file, char *fun_name, op_node_t *top);


#endif /*GEN_MAIN_H*/
