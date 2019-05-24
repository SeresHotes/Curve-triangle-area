
#include "console_commands.h"
#include <stdio.h>
#include <string.h>




global_t global =
{
	.output_name = "f1.out",
	.fun_name = "f1"
};

int command_help_f(int argc, char *argv[])
{
	for(int i = 0; i < global.command_array_size; i++)
	{
	    if(global.command_array[i].name_red)
			printf("%-4s %-15s ", global.command_array[i].name_red, global.command_array[i].desc_args);
	    else
			printf("%-21s", "");


	    if(global.command_array[i].name_ext)
			printf("%-12s %-15s ", global.command_array[i].name_ext, global.command_array[i].desc_args);
	    else
			printf("%-21s", "");

		printf("%s\n", global.command_array[i].description);
	}
	return 1;
}


void command_realize(int argc, char *argv[])
{
	for(int i = 1; i < argc;)
    {
    	int test = 0;
    	for(int j = 0; j < global.command_array_size; j++)
    	{
    		if(!strcmp(argv[i], global.command_array[j].name_red) ||
				!strcmp(argv[i], global.command_array[j].name_ext))
    		{
    			i += global.command_array[j].func(argc - i, argv + i);
    			test = 1;
    			break;
    		}
    	}
    	if(!test)
    	{
	      	fprintf(stderr, "ERROR: bad argument: %s, see --help\n", argv[i]);
	      	i++;
    	}
    }
}

int command_ourput_f(int argc, char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "%s\n", "ERROR: not enough arguments. See --help");
		return 1;
	}
	global.output_name = argv[1];
	return 2;
}

command_t command_output = {
	.name_ext = "--output",
	.name_red = "-o",
	.func = command_ourput_f,
	.description = "changes output file",
	.desc_args = "<file>"
};


command_t command_help = {
	.name_ext = "--help",
	.name_red = "-h",
	.func = command_help_f,
	.description = "gives help information",
	.desc_args = ""
};
