#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define MAXLEN 1000 // максимальная длина строки
#define NLINES 1000 // максимальное число строк

int main(void)
{
	FILE* fpin = fopen("C:\\Users\\User\\source\\repos\\file.txt", "rt"); // открыть входной файл для чтения
	FILE* fpout = fopen("C:\\Users\\User\\source\\repos\\result.txt", "wt"); // открыть файл для записи
	int nlines1 = 0; // число строк в файле
	char** lines_ptr = NULL; // указатель на динамический массив
	int npointers = NLINES; // число указателей в динамическом массиве
	int i, j;

	if (fpin == NULL)
	{
		printf("error opening file input\n"); // информация об ошибке
		return; // ошибка при открытии файла
	}

	if (fpout == NULL)
	{
		printf("error opening file output\n"); // информация об ошибке
		return; // ошибка при открытии файла
	}

	lines_ptr = (char**)calloc(NLINES, sizeof(char*)); // заказать и обнулить динамический массив указателей

	while (!feof(fpin)) // цикл до конца файла
	{
		char line[MAXLEN];
		char* ptr = fgets(line, MAXLEN, fpin); // чтение строки

		if (ptr == NULL)
		{
			break; // файл исчерпан
		}

		int len = (int)strlen(line); // определить длину строки
		if (nlines1 == npointers) // динамический массив исчерпан
		{
			npointers += NLINES; // увеличить число указателей в массиве

			lines_ptr = (char**)realloc(lines_ptr, npointers * sizeof(char*)); // перезаказать память для массива указателей
			memset(&lines_ptr[nlines1], 0, NLINES * sizeof(char*)); // обнулить новую часть массива указателе
		}

		lines_ptr[nlines1] = (char*)malloc(len + 1); // заказать в памяти место для строки плюс один байт
		strcpy(lines_ptr[nlines1], line); // сохранить строку в динамическом массиве
		nlines1++;
	}

	for (nlines1--; nlines1 >= 0; nlines1--) // цикл по строкам
	{
		char* ptr = lines_ptr[nlines1]; // указатель на текущую строку

		for (j = 0; ptr[j] != '\0' && ptr[j] != '\n'; j++)
		{
			fprintf(fpout, "%c", ptr[j]);
		}
		fprintf(fpout, "\n");
	}

	for (i = 0; i < nlines1; i++) // отказаться от памяти для строк
	{
		if (lines_ptr[i] != NULL)
		{
			free(lines_ptr[i]);
		}
	}

	if (lines_ptr != NULL) // отказаться от динамического массива указателей
	{
		free(lines_ptr);
	}

	fclose(fpin); // закрыть входной файл
	fclose(fpout); // закрыть выходной файл

	return 0;
}
