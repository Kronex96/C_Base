#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#include "mydir.h"

void print_dir_contants(const char *strdir)
{
	DIR *dir;	//переменная типа DIR
	struct dirent *entry;	

	/*открываем директорию*/
	dir= opendir(strdir);

	if (dir)
	{
		/*заполняем структуру*/
		while (entry = readdir(dir))
		{
			printf("file %s\n", entry->d_name);	//указатель разыменовываем
		}
	}
}