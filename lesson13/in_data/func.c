#include <stdio.h>

#include "func.h"

int day_count(const int numb)		//функция определяет кол-во дней в месяце
{
	if (numb == 2)
		return 28;
	else if (numb == 4 || numb == 6 || numb == 9 || numb == 11)
		return 30;
	else
		return 31;
}