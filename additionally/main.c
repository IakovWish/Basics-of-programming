#pragma warning(disable : 4996) //необходимо для использования устаревших функций (scanf)
#include <stdio.h>
/*определение символических констант*/
#define YES 1
#define NO 0
#define MAXLINE 1000
void process_line(char buffer[]); // объявляем функцию

int main(void)
{
	char line[MAXLINE];
	char result[MAXLINE];
	printf("Please, enter some words\n");
	gets(line);
	process_line(line);
	printf("Result:\n");
	puts(line);
	return 0;
}

void process_line(char buffer[])
{
	/*объявление и инициализация*/
	char c = 'a'; // текущий символ
	int word = NO; // признак слова
	int symb = NO; // индикатор наличия лишних символов
	char *in_ptr = buffer; // указатель на текущий символ входной строки
	char *out_ptr = buffer; // указатель на текущий символ выходной строки
	char *word_ptr = buffer; // указатель на начало слова
	char *start_word_max = buffer;
	char *end_word_max = buffer;
	int cnt = 0;
	int max = 0;
	char *p = buffer;
	int len = strlen(buffer);
	int i = 0;

	do
	{
		do
		{
			c = *in_ptr; // взять текущий символ из буфера
			if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != ' ') && (c != '\0')) // проверить не является ли этот символ лишним
			{
				symb = YES; // в слове есть лишний символ
			}
			if (word == NO) // найдена первая буква слова
			{
				word_ptr = in_ptr; // запомнить адресс начала слова
			}
			word = YES;
			in_ptr++;
			c = *in_ptr;
		} while (c != ' ' && c != '\0');

		if (symb == YES)
		{
			if (c == '\0')
			{
				goto end;
			}
			word = NO;
			symb = NO;
		}
		else
		{
			word = NO;
			symb = NO;
			in_ptr = word_ptr;
			do
			{
			end:
				c = *in_ptr; // взять текущий символ из буфера
				if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '?' || c == '!' || c == ';' || c == ':' ||
					c == '-' || c == '_' || c == '(' || c == ')' || c == '\t' || c == '/' || c == '&' || c == '"') // разделитель найден
				{
					cnt = 0;
					if (c == '\0') // 
					{
						while (p < start_word_max) //
						{
							*out_ptr++ = *p++; // копирование слова
						}
						end_word_max++;
						while (cnt++ < len) // 
						{
							*out_ptr++ = *end_word_max++; // копирование слова
						}
						*out_ptr++ = c; // вставляем разделитель
					}
					word = NO;
					symb = NO;
				}
				else
				{
					cnt++;
					if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) // проверить не является ли этот символ лишним
					{
						symb = YES; // в слове есть лишний символ
					}
					if (word == NO && symb == NO) // найдена первая буква слова
					{
						word_ptr = in_ptr; // запомнить адресс начала слова
					}
					if (cnt > max && symb == NO) // проверка на <перебор> букв
					{
						start_word_max = word_ptr;
						end_word_max = in_ptr;
						max = cnt;
					}
					word = YES;
				}
				in_ptr++;
			} while (c != ' ' && c != '\0');
		}
	} while (c != '\0'); // продолжать до конца строки
}
