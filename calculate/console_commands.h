/*
 * This module processes input from console and decides what to do.
 *
 * "command_t" refers to command to be executed
 * "global" refers to global settings for all console commands
 * "command_realize" realizes command and executes it
 * "command_help_f" - base help function
 * all command_t command should be added to global.command_array
 */

#ifndef CONSOLE_COMMANDS_H
#define CONSOLE_COMMANDS_H

typedef struct{
	char *name_ext;
	char *name_red;
	int (*func)(int, char **);
	char *description;
	char *desc_args;
} command_t;

typedef struct{
	command_t *command_array;
	int command_array_size;
	char *input_name;
	double left, right;
	double eps;

} global_t;
int command_help_f(int argc, char *argv[]);
void command_realize(int argc, char *argv[]);
extern global_t global;
extern command_t command_help;
#endif /*CONSOLE_COMMANDS_H*/
