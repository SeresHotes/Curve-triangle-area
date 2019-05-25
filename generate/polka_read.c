

#include "polka_read.h"
#include <stdio.h>

int polka_realize_word(char* word, int* op_base, int* op, double* value)
{
	if(word[0] >= '0' && word[0] <= '9')
	{
		sscanf(word, "%lf", value);
		*op_base = CONST;
		return 0;
	} else if(word[0] >= 'a' && word[0] <= 'z')
	{
		*op_base = UNAR;
		switch(word[0])
		{
		case 's':
			*op = SIN;
			break;
		case 't':
			*op = TAN;
			break;
		case 'c':
			if(word[1] == 'o')
				*op = COS;
			else
				*op = CTG;
			break;
		case 'x':
			*op_base = SPEC_X;
			break;
		default:
			fprintf(stderr, "%s %s\n", "ERROR: can't realize word: ", word);
			return -1;
		}
	}else {
		*op_base = BINAR;
		switch(word[0])
		{
		case '+':
			*op = PLU;
			break;
		case '-':
			*op = MIN;
			break;
		case '*':
			*op = MUL;
			break;
		case '/':
			*op = DIV;
			break;
		///////////////////////////
		default:
			fprintf(stderr, "%s %s\n", "ERROR: can't realize word: ", word);
			return -1;
			break;
		}
	}
	return 0;
}