#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#include "files.h"


int main(int argc, char const *argv[])
{
	char path[255] = {0};

	getcwd(path, 255);	//получаем путь и заносим его в строчный массив

	printf("path = %s\n", path);

	print_dir_contants(path);

	return 0;
}