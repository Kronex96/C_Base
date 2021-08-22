#include <stdio.h>
#include <stdbool.h>
#include "files.h"



int main(int argc, char const *argv[])
{
	char src_n[100] = {0};	//переменная для имени источника
	char dst_n[100] = {0};	//переменная для имени назначения
	int a = 0;
	
	intro_filenames(src_n, dst_n);	//вводим имена файлов

	if (checking(src_n))	//проверяем наличие файла-источника
		return 0;			//если ошибка была, то программа завершится

	a = size_file(src_n);	//измеряем его размер.

	cp_file(src_n, dst_n);	//копируем файл

	printf("copying process completed successfully\n");
	printf("transfered %d bytes\n", a);
	
	return 0;
}