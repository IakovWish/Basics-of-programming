#pragma warning(disable : 4996) //необходимо для использования устаревших функций (scanf)
#include <stdio.h>
/* определение символических констант*/
#define YES 1
#define NO 0
#define MAXLINE 1000
int N; // наибольшее количество букв в строке
void process_line(char buffer[]); // объявляем функцию

int main(void)
{
	char line[MAXLINE];
	printf("Please, enter some words\nWARNING: words which consist of more than N letters will be deleted\n");
	gets(line);
	printf("Enter N=");
	scanf("%d", &N);
	process_line(line);
	printf("Result:\n");
	puts(line);
	return 0;
}

void process_line(char buffer[])
{
	char c; // текущий символ
	int word = NO; // признак слова
	int overkill = NO; // инд перебора букв в слове
	int symb = NO; // индикатор наличия лишних символов
	int ish = 0; // позиция текущего символа исходной cтроки
	int res = 0; // позиция текущего символа результирующей строки
	int start = 0; // позиция начала слова
	int n = 0; // сщетчик букв в слове
	int j;

	do
	{
		c = buffer[ish]; // взять текущий символ из буфера
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '?' || c == '!' || c == ';' || c == ':' ||
			c == '-' || c == '_' || c == '(' || c == ')' || c == '\t' || c == '/' || c == '&' || c == '"') // разделитель найден
		{
			if (symb == NO && word == YES && overkill == NO || symb == YES && word == YES) // если подходит по-1му/2му условию выполнить...
			{
				for (j = start; j < ish; j++) // слово не подлежит удалению оно копируется в результирующую строку вместе со своим разделителем
				{
					buffer[res++] = buffer[j]; // копирование слова
				}
			}

			word = NO;
			symb = NO;
			overkill = NO;
			n = 0;
			buffer[res++] = c; // ставим разделитель
		}

		else
		{
			n++; // найдена новая буква, увеличиваем счетчик букв
			if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) // проверить не является ли этот символ лишним
			{
				symb = YES; // в слове есть лишний символ
			}
			if (word == NO) // найдена первая буква слова
			{
				start = ish; // запомнить позицию начала слова
			}
			if (n > N) // проверка на перебор букв
			{
				overkill = YES; // перебор
			}
			word = YES;
		}
		ish++;
	} while (c != '\0'); // продолжать до конца строки
}
