#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int str_sum_digits(const char *cs);
int get_integers(const char *str);
int summ_int(int a);

int main(int argc, char const *argv[])
{
	char str1[100];
	int a, b;

	scanf("%s", str1);
	printf("length of %s = %lu\n", str1, strlen(str1));
	printf("%d\n",str_sum_digits(str1));
	
	printf("\nchecking result\n");
	a = get_integers(str1);
	printf("all integers are %d\n", a);
	b = summ_int(a);
	printf("summ of them = %d\n", b);

	return 0;
}

int str_sum_digits(const char *cs)
{
	int sum = 0;

	int length = strlen(cs);

	for (int i = 0; i < length; i++)
	{
		if ((cs[i] >= '0') && (cs[i] <= '9'))
			{
				printf("%c\n", cs[i]);
				sum = sum + cs[i] - 48;
			}
	}

	return sum;

}

int get_integers(const char *str)
{
	int length = strlen(str);
	char check[20];
	int j = 0;
	int a;
	for (int i = 0; i < length; i++)
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			check[j] = str[i];
			j++;
		}
	}
	
	return atoi(check);
}

int summ_int(int a)
{
	int sum = 0;

	while(a > 0)
	{
		sum = sum + (a % 10);
		a = a / 10;
	}

	return sum;
}