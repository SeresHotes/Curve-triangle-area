#include "gen_main.h"
#include "polka_read.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "console_commands.h"
#include "der_main.h"



int command_generate_f(int argc, char *argv[])
{
	if(argc < 3)
	{
		fprintf(stderr, "%s\n", "ERROR: not enough arguments. See --help");
		return 1;
	}

	FILE *file = fopen(argv[1], "r");
	if(!file)
	{
		fprintf(stderr, "%s\n", "ERROR: file doesn't exist");
		return 2;
	}

	op_node_t *op = op_read_and_get_tree(file);
	fclose(file);



	FILE *fw = fopen(global.output_name, "w");
	if(!fw)
		fprintf(stderr, "%s\n", "ERROR: can't create file");


	gen_init(fw);
	gen_make_fun(fw, argv[2], op);
	op_node_delete_tree(op);

	fclose(fw);
	return 3;
}
int command_generate_der_f(int argc, char *argv[])
{
	if(argc < 3)
	{
		fprintf(stderr, "%s\n", "ERROR: not enough arguments. See --help");
		return 1;
	}

	FILE *file = fopen(argv[1], "r");
	if(!file)
	{
		fprintf(stderr, "%s\n", "ERROR: file doesn't exist");
		return 2;
	}

	op_node_t *op = op_read_and_get_tree(file);
	op_node_t *op1 = der_get_der_function(op);
	fclose(file);



	FILE *fw = fopen(global.output_name, "w");
	if(!fw)
		fprintf(stderr, "%s\n", "ERROR: can't create file");


	gen_init(fw);
	gen_make_fun(fw, argv[2], op1);

	op_node_delete_tree(op1);

	fclose(fw);
	return 3;
}








int main(int argc, char *argv[])
{
	if(argc <= 1)
	{
		fprintf(stdout, "ERROR: need arguments\n");
		return -1;
	}


	command_t command_generate = {
		.name_ext = "--generate",
		.name_red = "-g",
		.func = command_generate_f,
		.description = "generates asm function from polka notation file",
		.desc_args = "<filename> <filename>"
	};
	command_t command_generate_der = {
		.name_ext = "--deriative",
		.name_red = "-d",
		.func = command_generate_der_f,
		.description = "generates asm deriative of function from polka notation file",
		.desc_args = "<filename> <filename>"
	};

	global.command_array_size = 4;
	global.command_array = malloc(sizeof(command_t) * global.command_array_size);
	global.command_array[0] = command_help;
	global.command_array[1] = command_generate;
	global.command_array[2] = command_generate_der;
	global.command_array[3] = command_output;



	command_realize(argc, argv);
	return 0;

}
