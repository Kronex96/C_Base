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
	
	const char *opts = "ahf";
	char path[255] = {0};	//массив, в который помещается путь
	int n = 1;				//переменная для определения кол-ва аргументов
	int vars;
	bool prnt_all = false;	//всё содержимое или нет
	bool force = false;		//нужен ли листинг содержащихся папок

	while((vars = getopt(argc, argv, opts)) != -1)
	{
		switch(vars)
		{
			case 'h' :
			{
				help(argv[0]);
				return 0;
			}
			case 'a' :
			{
				prnt_all = true;
				n = 2;	//кол-во аргументов больше
				break;
			}
			case 'f' :
			{
				force = true;
				n = 2;	//кол-во аргументов больше
				break;
			}
		}
	}

	if (argv[n] != 0)
	{
		printf("path is entered\n");
		printf("path = %s\n", argv[n]);
		dir_contents(argv[n], prnt_all, force);	//запускаем функцию с введенным путём
	}
	else
	{
		printf("path is not entered\n");
		getcwd(path, 255);	//получаем путь и заносим его в строчный массив
		printf("path = %s\n", path);
		dir_contents(path, prnt_all, force);	//запускаем функцию с текущей директорией
	}

	return 0;
}