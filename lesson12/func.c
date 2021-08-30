#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/stat.h>

#include "func.h"

void help (const char *appname)
{
	printf("usage %s [path]\n", appname);
	return;
}

void print_type(struct stat *st)
{
   switch (st->st_mode & S_IFMT)
   {
      case S_IFBLK:	printf("block device ");				break;
      case S_IFCHR:	printf("character device ");			break;
      case S_IFDIR:	printf("directory ");					break;
      case S_IFIFO:	printf("FIFO/pipe ");					break;
      case S_IFLNK:	printf("symlink ");						break;
      case S_IFREG:	printf("regular file ");				break;
      case S_IFSOCK:	printf("socket ");						break;
      default:			printf("unknown? ");						break;
   }
}

void dir_contents(const char *strdir, bool all)
/*
{
	DIR *dir;	//переменная типа DIR
	struct dirent *entry;

	dir = opendir(strdir);

	if (dir)
	{
		while(entry = readdir(dir))
		{
			printf("file %s\n", entry->d_name);	//указатель разыменовываем
		}
	}

	closedir(dir);
}
*/
{	
	DIR *dir;	//переменная типа DIR
	struct dirent *entry;
	struct stat file_info;
	char full_name[255] = {0};

	dir = opendir(strdir);

	if (dir)
	{
		while(entry = readdir(dir))
		{
			if(entry->d_name[0] =='.' && !all)
				continue;
			
			memset(full_name, 0, 255);
			sprintf(full_name, "%s/%s", strdir, entry->d_name);
			full_name[254] = '\0';
			if (stat(entry->d_name, &file_info) == 0)
			{
				print_type(&file_info);
				printf("sz %10ld ", file_info.st_size);
			}
			printf("file %s\n",full_name);	//указатель разыменовываем
			if ((file_info.st_mode & S_IFMT) == S_IFDIR)
				{
					printf("conatins\n");
					dir_contents(full_name, all);
				}
		}
	}

	closedir(dir);
}