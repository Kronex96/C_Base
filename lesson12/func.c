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
	printf("Usage %s [options] [path]\n", appname);
	printf("If you didn't enter path, program will list the current folder.\n");
	printf("You can use next options:\n	-h: instructions\n	-a: prints all containing files and directories\n	-f: prints all files and directories are contained in subdirectories\n");
	return;
}

void print_type(struct stat *st)
{
   switch (st->st_mode & S_IFMT)
   {
      case S_IFBLK:	printf("block device	");				break;
      case S_IFCHR:	printf("character device	");		break;
      case S_IFDIR:	printf("directory	");					break;
      case S_IFIFO:	printf("FIFO/pipe	");					break;
      case S_IFLNK:	printf("symlink	");					break;
      case S_IFREG:	printf("regular file	");				break;
      case S_IFSOCK:	printf("socket	");						break;
      default:			printf("unknown?	");					break;
   }
}

void dir_contents(const char *strdir, bool all, bool force)
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
			if (stat(full_name, &file_info) == 0)
			{
				print_type(&file_info);
				printf("sz	%10ld ", file_info.st_size);
			}
			printf("file %s\n",full_name);
			if (((file_info.st_mode & S_IFMT) == S_IFDIR) && (entry->d_name[0] != '.') && force)
				{
					dir_contents(full_name, all, force);
				}
		}
	}
	closedir(dir);
}