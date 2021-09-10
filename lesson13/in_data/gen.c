#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "func.h"


void add_null(const char *q)
{
	int a = 0;
	
}

int main(int argc, char const *argv[])
{
	char date[30];	//строка массив для даты
	int tmp;
	

	FILE *d;

	d = fopen("temperature.csv", "a");
		
	for (int imonth = 1; imonth <=12; imonth++)
	{
		for (int iday = 1; iday <= day_count(imonth); iday++)
		{
			for (int ihr = 0; ihr < 24; ihr++)
			{
				for (int imin = 0; imin < 60; imin++)
				{
					tmp = (rand()%200) - 99;
					fprintf(d, "2000;%02d;%02d;%02d;%02d;%02d\n", imonth, iday, ihr, imin, tmp);
					//printf("%s\n", date);
				}
			}
		}
		
	}
	fclose(d);
	
	return 0;
}
/*sprintf(date,"%2d;%2d;", imonth, iday);
			for (int i = 0; i < strlen(date); i++)
			{
				if (date[i] == ' ')
					date[i] = '0';
			}
			fprintf(d, "date: %s\n", date);*/