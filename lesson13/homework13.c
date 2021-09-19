#include "func.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

struct temper
{
	int year, mn, day, hr, min, temp;
};
struct inf
{
	int min, max, aver;
};

extern char *optarg;
extern int optind, opterr, optopt;

int main(int argc, char const *argv[])
{
	const char *opts = "hf:m:";
	FILE *s;
	int cnt, nmn, in_mn, y_aver, y_min, y_max, n, vars, nv;
	bool op_m = 0;
	struct temper in;
	struct inf stat;
	char d[40];
	char src_n[100] = {0};	//переменная для имени источника
	sprintf(src_n, "temperature.csv");
	cnt = nv = 0;

	while((vars = getopt(argc, argv, opts)) != -1)
	{
		switch(vars)
		{
			case 'h' :
			{
				help();
				return 0;
			}
			case 'f' :
			{
				nv++;
				memset(src_n, 0, sizeof(src_n));
				break;
			}
			case 'm' :
			{
				nv++;
				op_m = 1;
				break;
			}
		}
	}
	if (nv == 1)
	{
		if(op_m)
		{
			if(m_to_num(argv[2], &in_mn)) return 0;
		}

		else
		{
			sprintf(src_n, argv[2]);
		}
	}
	else if (nv == 2)
	{
		sprintf(src_n, argv[2]);
		if(m_to_num(argv[4], &in_mn)) return 0;
	}
	
	if (checking(src_n))	//проверяем наличие файла-источника
		return 0;			//если ошибка была, то программа завершится
	else
		printf("all is ok!\n");

	s = fopen(src_n, "r");
	y_min = stat.min = 100;	//устанавливаем минимальную температуру выше максимально возможного значения
	y_max = stat.max = -100;	//устанавливаем максимальную температуру ниже минимально возможного значения
	nmn = 1;
	y_aver = n = 0;
	printf("stats fo file: %s\n", src_n);
	while(fgets(d, 40, s))
	{
		n++;
		if (to_strct(d, &in.year, &in.mn, &in.day, &in.hr, &in.min, &in.temp))
		{
			n--;
			printf("error in string number: %d\n", n);
		}
		else
		{
			y_aver = y_aver + in.temp;
			if (y_min > in.temp) y_min = in.temp;	//ищем минимальную температуру для месяца
			if (y_max < in.temp) y_max = in.temp;	//ищем максимальную температуру для месяца
			if (in.mn == nmn)
			{
				cnt++;	//считаем кол-во измерений
				if (stat.min > in.temp) stat.min = in.temp;	//ищем минимальную температуру для месяца
				if (stat.max < in.temp) stat.max = in.temp;	//ищем максимальную температуру для месяца
				stat.aver = stat.aver + in.temp;	//набираем значения для вычисления средней
			}
			else
			{
				stat.aver = stat.aver / cnt;
				if ((in_mn == 0) || (in_mn == nmn))
				{
					print_stat(nmn, cnt, stat.min, stat.max, stat.aver);	//выводим статистику
				}
				cnt = 1;			//учёт значения для новой статистики
				stat.min = 100;		//сбрасываем минимальную температуру выше максимально возможного значения
				stat.max = -100;	//сбрасываем максимальную температуру ниже минимально возможного значения
				stat.aver = 0;		//сбрасываем среднюю температуру
				if (stat.min > in.temp) stat.min = in.temp; //ведём учёт новой температуры для поиска минимальной
				if (stat.max < in.temp) stat.max = in.temp;	//ведём учёт новой температуры для поиска максимальной
				stat.aver = stat.aver + in.temp;
				nmn++;
			}
		}
	}
	stat.aver = stat.aver / cnt;
	if ((in_mn == 0) || (in_mn == nmn))
	{
		print_stat(nmn, cnt, stat.min, stat.max, stat.aver);	//выводим статистику
	}
	y_aver = y_aver / n;
	if (!(op_m))
		printf("\nstat of year:\naverage = %d\nminimum = %d\nmaximum = %d\n", y_aver, y_min, y_max);
	fclose(s);

	return 0;
}