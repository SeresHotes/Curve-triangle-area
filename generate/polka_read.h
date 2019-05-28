/*
 * This module provides base for all program. It realizes word from file,
 * containing inverse polka notations function and returns type of the word
 *
 */

#ifndef POLKA_READ_H
#define POLKA_READ_H


typedef enum {
	UNAR,
	BINAR,
	CONST,
	SPEC_X
}op_base_t;
typedef enum {
	PLU,
	MIN,
	DIV,
	MUL
}op_bin_t;
typedef enum {
	TAN,
	CTG,
	SIN,
	COS,
	SPE_1_DIX_X_2, // y = 1/(x^2). Used for derivative of tan
	EXP
} op_un_t;
typedef enum {
	CON_E,
	CON_PI,
	NUM
} op_const_t;

int polka_realize_word(char* word, int *op_base, int *op, double *value);

#endif /*POLKA_READ_H*/
