#include <stdio.h>
// определение символических констант
#define YES 1
#define NO 0
#define MAXLINE 1000
void process_line(char buffer[]);
int main(void)
{
	char line[MAXLINE];
	gets(line);
	process_line(line);
	puts(line);
	return 0;
}
void process_line(char buffer[])
{
	char c; // текущий символ
	int prev_c; // предыдущий символ
	int flag; // признак слова
	int found; // индикатор того, что искомый признак в слове обнаружен
	int i; // позиция текущего символа исходной cтроки 
	int pos; // позиция текущего символа результирующей строки
	int start; // позиция начала слова
	int j;
	// начальные присваивания (инициализация)
	flag = NO;
	found = NO;
	prev_c = ' ';
	start = 0;
	i = 0;
	pos = 0;
	// цикл чтения символов из строки
	do
	{
		c = buffer[i]; // взять текущий символ из буфера
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') // найден разделитель
		{
			if (flag == YES) // это первый разделить после слова
			{
				if (found == NO) // проверить, обнаружен ли в слове искомый признак
				{
					for (j = start; j < i; j++) // слово не подлежит удалению оно копируется в результирующую строку
					{
						buffer[pos++] = buffer[j];
					}
				}
			}
			flag = NO;
			buffer[pos++] = c;
		}
		else
		{
			if (flag == NO) // найдена буква
			{
				start = i; // запомнить позицию начала слова
			}

			if (prev_c == c) // проверка совпадения текущего и предыдущего символов
			{
				found = YES; // (обнаружение искомого признака в слове)
			}
			else
			{
				found = NO;
			}
			flag = YES;
		}
		prev_c = c;
		i++;
	} while (c != '\0');
}
