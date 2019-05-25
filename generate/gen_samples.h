/*
 * This module is used to generate asm code of each type of operation
 */

#ifndef GEN_SAMPLES_H
#define GEN_SAMPLES_H
#include <stdio.h>

void gen_sample_init(FILE* file, char *fun_name);
void gen_sample_stop(FILE* file);
void gen_sample_const(FILE* file, double value);
void gen_sample_x(FILE* file);
void gen_sample_unar(FILE* file, int op);
void gen_sample_binar(FILE* file, int op);


#endif /*GEN_SAMPLES_H*/
