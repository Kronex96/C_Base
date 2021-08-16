#include <stdio.h>
#include <stdint.h>


/*task1
На стандартном потоке ввода задан текст, состоящий из латинских букв
и цифр и оканчивающийся точкой. На стандартный поток вывода
вывести цифру, наиболее часто встречающуюся в тексте
(если таких цифр несколько, вывести любую из них)
*/
void often ();

/*task2
Циклически сдвинуть массив влево на 1 элемент
(Первый элемент становится вторым, второй - третим и так далее.
Последний становится первым).
*/
void shift ();

/*task3
Сделать реверс массива(первый элемент становится последним,
последний - первым и так далее)
*/
void reverse ();

/*task 4
Отсортировать массив по возрастанию.
*/
void sort(void);

//additional functions
int get_max (int array[], int sz);	//determines value of max
int find_max (int array[], int sz, int max);	//determines index of max
void swap_el (int array[], int sz, int index);	//replace max to last index

int main(int argc, char const *argv[])
{
	/* code */
	sort();

	return 0;
}


int get_max (int array[], int sz)
{
	int max = array[0];
	int i;

	for (i = 0; i <= sz; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return max;
}

int find_max (int array[], int sz, int max)
{
	int i;
	for (i = 0; i <= sz; i++)
	{
		if (array[i] == max)
			return i;
	}
}

void swap_el (int array[], int sz, int index)
{
	int tmp, i;

	tmp = array[sz];
	array[sz] = array[index];
	array[index] = tmp;
}


void sort(void)
{
	int array[5];	
	int sz = 5;
	int max, index, temp, i, j;

	printf("enter %d numbers\n", sz);
	
	for (i = 0; i < sz; i ++)	//entering array
		{
			scanf("%d", &array[i]);
		}
	
	for (j = sz - 1; j > 0; j--)
	{
		max = get_max(array, j);
		index = find_max(array, j, max);
		if (index < (j))
			swap_el(array, j, index);
	}
	
	printf("\nnew array\n");

	for (i = 0; i < sz; i++)
		printf("n%d = %d\n", i, array[i]);
}
