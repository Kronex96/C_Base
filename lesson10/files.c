#include "files.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

void intro_filenames(char *src, char *dst)
{
	char name_f[100] = {0};

	printf("Please enter name of source, and name of destination\n");
	scanf("%s %s", src, dst);

	return;
}

bool checking(char *file)
{
	FILE *f;

	f = fopen(file, "r");
	if (f == NULL)
	{
		printf("\nERROR!!!\nThis file not exists\n");
		printf("Please enter other name or create file with this name\n");
		return 1;
	}
	
	fclose(f);
	return 0;
}

int size_file(char *file)
{
	FILE *f;
	size_t size;

	f = fopen(file, "r");
	
	fseek(f, 0, SEEK_END);
	size = ftell(f);
		
	fclose(f);
	return size;
}

void cp_file(char *src, char *dst)
{
	FILE *s, *d;
	char c;

	s = fopen(src, "r");
	d = fopen(dst, "w");

	while((c = fgetc(s)) != EOF)
	{
		fprintf(d, "%c", c);
	}

	fclose(s);
	fclose(d);

}