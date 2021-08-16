#include <stdio.h>
#include <string.h>


int str_sum_digits(const char *cs);

int main(int argc, char const *argv[])
{
	char str1[100];

	scanf("%s", str1);
	printf("length of %s = %lu\n", str1, strlen(str1));
	printf("%d\n",str_sum_digits(str1));
		
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