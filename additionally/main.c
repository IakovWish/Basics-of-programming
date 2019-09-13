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
	char c; // текущий символ
	int word = NO; // признак слова
	int symb = NO; // индикатор наличия лишних символов
	char* in_ptr = buffer; // указатель на текущий символ входной строки
	char* out_ptr = buffer; // указатель на текущий символ выходной строки
	char* word_ptr = buffer; // указатель на начало слова
	char* start_word_max = buffer;
	char* end_word_max = buffer;
	int cnt = 0;
	int max = 0;
	char* p = buffer;
	int len = strlen(buffer);
	char* d = buffer[998];
	int i = 0;
	char* start_slovo = buffer;
	char* end_slovo = buffer;
	int est = NO;

	do
	{
		c = *in_ptr; // взять текущий символ из буфера
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '?' || c == '!' || c == ';' || c == ':' ||
			c == '-' || c == '_' || c == '(' || c == ')' || c == '\t' || c == '/' || c == '&' || c == '"') // разделитель найден
		{
			if (word == YES && symb == NO) // если подходит по-1му/2му условию выполнить...
			{
				start_slovo = word_ptr;
				end_slovo = in_ptr;
				est = YES;
				word = NO;
				symb = NO;
			}
		}

		else
		{
			if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) // проверить не является ли этот символ лишним
			{
				symb = YES; // в слове есть лишний символ
			}
			if (word == NO) // найдена первая буква слова
			{
				word_ptr = in_ptr; // запомнить адрес начала слова
			}
			word = YES;
		}
		in_ptr++;
	} while (c != '\0'); // продолжать до конца строки

	if (est == NO)
	{
		printf("ERROR\nPlease, enter WORDS\n");
		exit(1);
	}
	
	word = NO; // признак слова
	symb = NO; // индикатор наличия лишних символов
	*in_ptr = buffer[0]; // указатель на текущий символ входной строки
	* out_ptr = buffer[0]; // указатель на текущий символ выходной строки
	* word_ptr = buffer[0]; // указатель на начало слова
	* start_word_max = buffer[0];
	* end_word_max = buffer[0];
	cnt = 0;
	max = 0;
	* p = buffer[0];
	len = strlen(buffer);
	i = 0;
	est = NO;

	do
	{
		c = *in_ptr; // взять текущий символ из буфера
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '?' || c == '!' || c == ';' || c == ':' ||
			c == '-' || c == '_' || c == '(' || c == ')' || c == '\t' || c == '/' || c == '&' || c == '"') // разделитель найден
		{
			if (word == YES && c == '\0') // если подходит по-1му/2му условию выполнить...
			{
				while (p < start_word_max) // слово не подлежит удалению оно копируется в результирующую строку
				{
					*out_ptr++ = *p++; // копирование слова
				}
				end_word_max++;
				while (i++ < len)  // слово не подлежит удалению оно копируется в результирующую строку
				{
					*out_ptr++ = *end_word_max++; // копирование слова
				}
				*out_ptr++ = '\0'; // вставляем разделитель
			}

			word = NO;
			symb = NO;
			cnt = 0;
		}

		else
		{
			cnt++;
			if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) // проверить не является ли этот символ лишним
			{
				symb = YES; // в слове есть лишний символ
				if (word == YES)
				{
					start_slovo = word_ptr;
					end_slovo = in_ptr;
				}
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
	} while (c != '\0'); // продолжать до конца строки
}
