#include "func.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct temper
	{
		int year, mn, day, hr, min, temp;
	};

int main(int argc, char const *argv[])
{
	FILE *s;
	int cnt = 0;
	struct temper in;
	char d[40];
	char src_n[100] = {0};	//переменная для имени источника
	intro_filenames(src_n);

	if (checking(src_n))	//проверяем наличие файла-источника
		return 0;			//если ошибка была, то программа завершится
	else
		printf("ok!\n");

	s = fopen(src_n, "r");
	fgets(d, 40, s);
	printf("after open: %s", d);
	to_strct(d, &in.year, &in.mn, &in.day, &in.hr, &in.min, &in.temp);
	printf("after fgets out: %d_%d_%d_%d_%d_%d_\n", in.year, in.mn, in.day, in.hr, in.min, in.temp);

	while((fgetc(s) != EOF) && (cnt < 5))
	{
		fgets(d, 40, s);
		printf("fgets: %s", d);
		to_strct(d, &in.year, &in.mn, &in.day, &in.hr, &in.min, &in.temp);
		printf("out: %d_%d_%d_%d_%d_%d_\n", in.year, in.mn, in.day, in.hr, in.min, in.temp);
		cnt++;
	}

	fclose(s);

	return 0;
}