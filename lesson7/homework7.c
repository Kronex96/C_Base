#include <stdio.h>


void math_func(int *a, int *b, int *summ, int *diff, int *mult, int *div, int *rem);

int main(int argc, char const *argv[])
{
	/* code */

	int a, b, summ, diff, mult, div, rem;

	printf("enter two numbers\n");
	scanf("%d %d", &a, &b);

	math_func(&a, &b, &summ, &diff, &mult, &div, &rem);
	printf("summ = %d\ndiff = %d\nmult = %d\ndiv  = %d rem = %d\n", summ, diff, mult, div, rem);

	return 0;
}

void math_func(int *a, int *b, int *summ, int *diff, int *mult, int *div, int *rem)
{
	*summ = *a + *b;
	*diff = *a - *b;
	*mult = *a * *b;
	*div  = *a / *b;
	*rem  = *a % *b;

	return;
}