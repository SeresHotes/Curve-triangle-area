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
	char *output_name;
	char *fun_name;

} global_t;
int command_help_f(int argc, char *argv[]);
void command_realize(int argc, char *argv[]);
extern global_t global;
extern command_t command_output;
extern command_t command_help;
#endif /*CONSOLE_COMMANDS_H*/
