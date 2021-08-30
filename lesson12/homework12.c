#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>


#include "func.h"

extern char *optarg;
extern int optind, opterr, optopt;

int main(int argc, char *argv[])
{
	
	const char *opts = "ah";
	char path[255] = {0};
	int vars;
	bool prnt_all = false;

	while((vars = getopt(argc, argv, opts)) != -1)
	{
		switch(vars)
		{
			case 'h' :
			{
				printf("argc = %d\n", argc);
				help(argv[0]);
				return 0;
			}
			case 'a' :
			{
				prnt_all = true;
				break;
			}
		}
	}

	getcwd(path, 255);	//получаем путь и заносим его в строчный массив
	printf("path = %s\n", path);
	dir_contents(path, prnt_all);
	/*printf("argc = %d\n", argc);
	if (argc < 2)
	{
		printf("no path passed\n");
		getcwd(path, 255);	//получаем путь и заносим его в строчный массив
		printf("path = %s\n", path);
		dir_contents(path, prnt_all);
	}
	else
	{
		for (int i = 0; i < argc; i++)
		{
			printf("argv[%d] = %s\n", i, argv[i]);
		}
		dir_contents(argv[argc-1], prnt_all);
	}*/


	return 0;
}
