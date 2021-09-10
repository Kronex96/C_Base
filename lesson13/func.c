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


void to_strct(char *in, int *yr, int *mn, int *day, int *hr, int *min, int *temp)
{
	
	*yr = 0;
	*mn = 0;
	*day = 0;
	*hr = 0;
	*min = 0;
	*temp = 0;
	int l = strlen(in);

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
	
	return;
}