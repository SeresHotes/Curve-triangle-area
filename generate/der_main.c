/*
 * This module generates operation tree of derivative of given function
 */

#include "op_node.h"
#include "der_main.h"

/*
 * For every operation in tree this function takes deriative of complex function.
 * For examle, if it gets cos(t), it makes -t'*sin(t), no matter either t is
 * function ot constant.
 */
op_node_t *der_get_der_function(op_node_t *top)
{

	op_node_t *t1;
	op_node_t *t2;
	op_node_t *t3;
	op_node_t *t4;
	op_node_t *t5;
	op_node_t *t6;
	switch(top->op_base)
	{
	case CONST:
		top->value = 0;
		break;
	case SPEC_X:
		top->value = 1;
		top->op_base = CONST;
		break;
	case UNAR:
		switch(top->op)
		{
		case SIN:
			t1 = top->args[0];
			op_node_config_binar(top, MUL, 0, 0);

			t2 = op_node_create_unar(COS, 0);
			top->args[0] = t2;

			t3 = op_node_create_clear();
			op_node_hard_cpy(t3, t1);
			t2->args[0] = t3;

			t1 = der_get_der_function(t1);
			top->args[1] = t1;

			break;
		case COS:
			t1 = top->args[0];
			op_node_config_binar(top, MUL, 0, 0);

			t2 = op_node_create_unar(SIN, 0);
			top->args[0] = t2;

			t3 = op_node_create_clear();
			op_node_hard_cpy(t3, t1);
			t2->args[0] = t3;

			t2 = op_node_create_binar(MUL, 0, 0);
			top->args[1] = t2;

			t3 = op_node_create_const(-1);
			t2->args[0] = t3;

			t1 = der_get_der_function(t1);
			t2->args[1] = t1;

			break;
		case TAN:
			t1 = top->args[0];
			op_node_config_binar(top, MUL, 0, 0);

			t2 = op_node_create_unar(SPE_1_DIX_X_2, 0);
			top->args[0] = t2;

			t4 = op_node_create_unar(COS, 0);
			t2->args[0] = t4;

			t3 = op_node_create_clear();
			op_node_hard_cpy(t3, t1);
			t4->args[0] = t3;

			t1 = der_get_der_function(t1);
			top->args[1] = t1;

			break;
		case CTG:
			t1 = top->args[0];
			op_node_config_binar(top, MUL, 0, 0);

			t2 = op_node_create_unar(SPE_1_DIX_X_2, 0);
			top->args[0] = t2;

			t4 = op_node_create_unar(SIN, 0);
			t2->args[0] = t4;

			t3 = op_node_create_clear();
			op_node_hard_cpy(t3, t1);
			t4->args[0] = t3;

			t2 = op_node_create_binar(MUL, 0, 0);
			top->args[1] = t2;

			t3 = op_node_create_const(-1);
			t2->args[0] = t3;

			t1 = der_get_der_function(t1);
			t2->args[1] = t1;

			break;
		}
		break;
	case BINAR:
		switch(top->op)
		{
		case PLU:
			top->args[0] = der_get_der_function(top->args[0]);
			top->args[1] = der_get_der_function(top->args[1]);
			break;
		case MIN:
			top->args[0] = der_get_der_function(top->args[0]);
			top->args[1] = der_get_der_function(top->args[1]);
			break;
		case MUL:
			t1 = top->args[0];
			t2 = top->args[1];

			op_node_config_binar(top, PLU, 0, 0);
			t3 = op_node_create_binar(MUL, 0, 0);
			top->args[0] = t3;

			t4 = op_node_create_clear();
			op_node_hard_cpy(t4, t1);
			t4 = der_get_der_function(t4);
			t3->args[0] = t4;

			t5 = op_node_create_clear();
			op_node_hard_cpy(t5, t2);
			t3->args[1] = t5;


			t3 = op_node_create_binar(MUL, 0, 0);
			top->args[1] = t3;

			t4 = op_node_create_clear();
			op_node_hard_cpy(t4, t1);
			t3->args[0] = t4;

			t5 = op_node_create_clear();
			op_node_hard_cpy(t5, t2);
			t5 = der_get_der_function(t5);
			t3->args[1] = t5;

			break;
		case DIV:
			t1 = top->args[0];//a
			t2 = top->args[1];//b

			op_node_config_binar(top, MUL, 0, 0);
			//1/b^2
			t3 = op_node_create_unar(SPE_1_DIX_X_2, 0);
			top->args[0] = t3;

			t4 = op_node_create_clear();
			op_node_hard_cpy(t4, t2);
			t3->args[0] = t4;

			t6 = op_node_create_binar(MIN, 0, 0);
			top->args[1] = t6;

			t3 = op_node_create_binar(MUL, 0, 0);
			t6->args[0] = t3;

			t4 = op_node_create_clear();
			op_node_hard_cpy(t4, t1);
			t4 = der_get_der_function(t4);
			t3->args[0] = t4;

			t5 = op_node_create_clear();
			op_node_hard_cpy(t5, t2);
			t3->args[1] = t5;


			t3 = op_node_create_binar(MUL, 0, 0);
			t6->args[1] = t3;

			t4 = op_node_create_clear();
			op_node_hard_cpy(t4, t1);
			t3->args[0] = t4;

			t5 = op_node_create_clear();
			op_node_hard_cpy(t5, t2);
			t5 = der_get_der_function(t5);
			t3->args[1] = t5;

			break;
		}

		break;
	}
	return top;
}
