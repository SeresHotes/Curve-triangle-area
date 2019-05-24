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
	SPE_1_DIX_X_2
} op_un_t;

int polka_realize_word(char* word, int *op_base, int *op, double *value);

#endif /*POLKA_READ_H*/