#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define YES 1
#define NO 0
#define MAXLEN 1000 // максимальная длина строки
#define NLINES 1000 // максимальное число строк

int word_counter0(char lines[][MAXLEN], int n);
int word_counter1(char** lines, int n);

int main(void)
{
	FILE* fp = fopen("C:\\Users\\User\\source\\repos\\file.txt", "rt"); // открыть входной файл для чтения
	int nlines0 = 0; // число строк в файле
	int nlines1 = 0; // число строк в файле
	static char lines[NLINES][MAXLEN]; // статический массив для хранения строк
	char** lines_ptr = NULL; // указатель на динамический массив
	int npointers = NLINES; // число указателей в динамическом массиве
	int i;
	int nwords0, nwords1; // число слов в массиве строк
	
	if (fp == NULL)
	{
		return; // ошибка при открытии файла
	}
	
#if 1
	lines_ptr = (char**)malloc(NLINES * sizeof(char*)); // заказать динамический массив указателей
	memset(lines_ptr, 0, NLINES * sizeof(char*)); // обнулить массив указателей

#else
	lines_ptr = (char**)calloc(NLINES, sizeof(char*)); //2й вариант

#endif
	while (!feof(fp)) // цикл до конца файла
	{
		char line[MAXLEN];
		char* ptr = fgets(line, MAXLEN, fp); // чтение строки

		if (ptr == NULL)
		{
			break; // файл исчерпан
		}

		if (nlines0 < NLINES) // статический массив ещё не исчерпан
		{
			strcpy(&lines[nlines0][0], line); // сохранить строку в статическом массиве
			nlines0++;
		}

		int len = (int)strlen(line); // определить длину строки
		if (nlines1 == npointers) // динамический массив исчерпан
		{
			npointers += NLINES;// увеличить число указателей в массиве

			lines_ptr = (char**)realloc(lines_ptr, npointers * sizeof(char*)); // перезаказать память для массива указателей
			memset(&lines_ptr[nlines1], 0, NLINES * sizeof(char*)); // обнулить новую часть массива указателе
		}
		
		lines_ptr[nlines1] = (char*)malloc(len + 1); // заказать в памяти место для строки плюс один байт
		strcpy(lines_ptr[nlines1], line); // сохранить строку в динамическом массиве
		nlines1++;
	}
	nwords0 = word_counter0(lines, nlines0);
	nwords1 = word_counter1(lines_ptr, nlines1);
	printf("number of words: %d\n", nwords0);
	printf("number of words: %d\n", nwords1);

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

	fclose(fp); // закрыть входной файл
	return 0;
}

int word_counter0(char lines[][MAXLEN], int n)
{
	int i, j;
	int counter = 0; // счётчик слов
	int flag = NO; // признак слова

	for (i = 0; i < n; i++) // цикл по строкам
	{
		char* ptr = &lines[i][0]; // указатель на текущую строку

		for (j = 0; ptr[j] != '\0'; j++)
		{
			if (ptr[j] == ' ' || ptr[j] == ',' || ptr[j] == '.' || ptr[j] == '\n') // текущий символ - разделитель
			{
				flag = NO;
			}
			else // текущий символ - буква
			{
				if (flag == NO) // первая буква в слове
				{
					counter++;
				}
				flag = YES;
			}
		}

		if (flag == YES) // строка закончилась буквой
		{
			counter++;
		}
	}

	return counter;
}

int word_counter1(char** lines, int n)
{
	int i, j;
	int counter = 0; // счётчик слов
	int flag = NO; // признак слова

	for (i = 0; i < n; i++) // цикл по строкам
	{
#if 1
		char* ptr = *(lines + i); // указатель на текущую строку

#else
		char* ptr = lines[i]; // 2й вариант

#endif
		for (j = 0; ptr[j] != '\0'; j++)
		{
			if (ptr[j] == ' ' || ptr[j] == ',' || ptr[j] == '.' || ptr[j] == '\n') // текущий символ - разделитель
			{
				flag = NO;
			}
			else // текущий символ - буква
			{

				if (flag == NO) // первая буква в слове
				{
					counter++;
				}
				flag = YES;
			}
		}

		if (flag == YES) // строка закончилась буквой
		{
			counter++;
		}
	}

	return counter;
}
