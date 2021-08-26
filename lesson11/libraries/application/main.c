#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <mydir.h>


int main(int argc, char *argv[])
{
	
	char path[255] = {0};

	if (argc < 2)
	{
		printf("no path passed\n");
		getcwd(path, 255);	//получаем путь и заносим его в строчный массив
		printf("path = %s\n", path);
		print_dir_contants(path);
	}
	else
	{
		printf("path = %s\n", argv[1]);
		print_dir_contants(argv[1]);	
	}
	
		

	

	return 0;
	
}