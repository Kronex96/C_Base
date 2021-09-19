#include "func.h"

void intro_filenames(char *src)	//функция запроса имени файла
{
	char name_f[100] = {0};

	printf("Please enter name of source:\n");
	scanf("%s", src);

	return;
}

bool checking(char *file)	//функция проверки файла на наличие
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


bool to_strct(char *in, int *yr, int *mn, int *day, int *hr, int *min, int *temp)
{
	
	*yr = 0;
	*mn = 0;
	*day = 0;
	*hr = 0;
	*min = 0;
	*temp = 0;
	int l = strlen(in);
	if ((in[4] != ';') || (in[7] != ';') || (in[10] != ';') || (in[13] != ';') || (in[16] != ';'))
		return 1;

	//год
	for (int i = 0; i < 4; i++)
		*yr = 10 * *yr + in[i] - 48;
	
	for (int i = 5; i < 7; i++)
		*mn = 10 * *mn + in[i] - 48;
	
	for (int i = 8; i < 10; i++)
		*day = 10 * *day + in[i] - 48;
	
	for (int i = 11; i < 13; i++)
		*hr = 10 * *hr + in[i] - 48;
	
	for (int i = 14; i < 16; i++)
		*min = 10 * *min + in[i] - 48;
	
	if (in[17] == '-')
	{
		for (int i = 18; i < 20; i++)
		{
			*temp = 10 * *temp + in[i] - 48;
		}
		*temp = -(*temp);
	}
	else
		for (int i = 17; i < 19; i++)
		{
			*temp = (10 * *temp) + in[i] - 48;
		}	
	
	return 0;
}

void print_stat(int nmn, int cnt, int min, int max, int aver)
{
	printf("count of measure for month number %d:	%d\n",nmn, cnt);	//кол-во данных и номер месяца
	printf("min temp:	%d\n", min);	//вывод минимальной температуры
	printf("max temp:	%d\n", max);	//вывод максимальной температуры
	printf("average:	%d\n", aver);	//вывод средней температуры
	return;
}

void help()
{
	printf("This program take file of temperature data and make statistic.\n");
	printf("Statistic include minimum, average and maximum temperature for each month and year.\n");
	printf("If you use this program without any keys, the program will take the file from its directory");
	printf(" and will give full statistic.\n");
	printf("By default, the programm looks file with 'temperature.csv'\n");
	printf("You also can use some keys:\n");
	printf("   -h - you will get help;\n");
	printf("   -f - you must determine the file you need;\n");
	printf("   -m - programm will generate statistic for only this month. Format: xx\n");
	printf("      example: -m 02\n");
	return;
}

bool m_to_num(const char *s, int *m)
{
	//int a = strlen(s);
	*m = 0;
	if (((s[0] == '0') && (s[1] > '0') && (s[1] <= '9')) || ((s[0] == '1') && (s[1] >= '0') && (s[1] < '3')))
	{
		*m = ((s[0]-48) * 10) + s[1]-48;
		return 0;
	}
	else
	{
		printf("ERROR!!!\nformat month number is not valid!\n");
		return 1;
	}
}
