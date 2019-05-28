/*
 * This module provides base for all program. It realizes word from file,
 * containing inverse polka notations function and returns type of the word
 *
 */

#include "polka_read.h"
#include <stdio.h>
#include <string.h>

int polka_realize_word(char* word, int* op_base, int* op, double* value)
{
	if(word[0] >= '0' && word[0] <= '9')
	{
		sscanf(word, "%lf", value);
		*op_base = CONST;
		*op = NUM;
		return 0;
	} else if(word[0] >= 'a' && word[0] <= 'z')
	{
		*op_base = UNAR;
		switch(word[0])
		{
		case 'e':
			if(strcmp("e", word) == 0)
			{
				*op_base = CONST;
				*op = CON_E;
			}
			else
				*op = EXP;
			break;
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
		case 'p':
			*op_base = CONST;
			*op = CON_PI;
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
			if(strcmp(word, "-") == 0)
				*op = MIN;
			else
			{
				*op_base = CONST;
				*op = NUM;
				sscanf(word, "%lf", value);
			}
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
