/*
 * This module processes input from console and decides what to do.
 *
 * "command_t" refers to command to be executed
 * "global" refers to global settings for all console commands
 * "command_realize" realizes command and executes it
 * "command_help_f" - base help function
 * all command_t command should be added to global.command_array
 */
#include "console_commands.h"
#include <stdio.h>
#include <string.h>


global_t global =
{
	.left = LEFT_BORDER,
	.right = RIGHT_BORDER,
	.eps = 0.00001
};

int command_help_f(int argc, char *argv[])
{
	printf("no options: calculates area of curve triangle\n");
	for(int i = 0; i < global.command_array_size; i++)
	{
	    if(global.command_array[i].name_red)
			printf("%-4s", global.command_array[i].name_red);


	    if(global.command_array[i].name_ext)
			printf("%-12s %-30s ", global.command_array[i].name_ext, global.command_array[i].desc_args);
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
	      	fprintf(stderr, "ERROR: bad argument: %s\n", argv[i]);
	      	i++;
    	}
    }
}




command_t command_help = {
	.name_ext = "--help",
	.name_red = "-h",
	.func = command_help_f,
	.description = "gives help information",
	.desc_args = ""
};
