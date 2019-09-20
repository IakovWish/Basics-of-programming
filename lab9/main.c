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
	char c = 'a'; // текущий символ
	int word = NO; // признак слова
	int symb = NO; // индикатор наличия лишних символов
	char* in_ptr = buffer; // указатель на текущий символ входной строки
	char* out_ptr = buffer; // указатель на текущий символ выходной строки
	char* word_ptr = buffer; // указатель на начало слова
	int cnt = 0; // счетчик
	int cnt_max = 0;

	do
	{
		do
		{
			do
			{
				c = *in_ptr; // взять текущий символ из буфера
				if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && c != ' ' && c != '\0' && c != '.' && c != ',' && c != '\n' && c != '?' &&
					c != '!' && c != ';' && c != ':' && c != '-' && c != '_' && c != '\t' && c != ')' && c != '(' && c != '/' && c != '&' && c != '"')
				{
					symb = YES; // в слове есть лишний символ
				}
				if (word == NO) // найдена первая буква слова
				{
					word_ptr = in_ptr; // запомнить адресс начала слова
				}
				word = YES;
				in_ptr++; // смотрим следущую букву
				cnt++;
			} while (c != ' ' && c != '\0' && c != '.' && c != ',' && c != '\n' && c != '?' && c != '!' && c != ';' && c != ':' &&
				c != '-' && c != '_' && c != '\t' && c != ')' && c != '(' && c != '/' && c != '&' && c != '"'); // повторяем до конца слова

			if (cnt > cnt_max && symb == NO)
			{
				cnt_max = cnt;
			}
			cnt = 0;
			word = NO;
			symb = NO;
		} while (c != '\0');

		in_ptr = buffer;


		do
		{
			do
			{
				c = *in_ptr; // взять текущий символ из буфера
				if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && c != ' ' && c != '\0' && c != '.' && c != ',' && c != '\n' && c != '?' && // ищем лишние символы
					c != '!' && c != ';' && c != ':' && c != '-' && c != '_' && c != '\t' && c != ')' && c != '(' && c != '/' && c != '&' && c != '"')
				{
					symb = YES; // в слове есть лишний символ
				}
				if (word == NO) // найдена первая буква слова
				{
					word_ptr = in_ptr; // запомнить адресс начала слова
				}
				word = YES;
				in_ptr++; // смотрим следущую букву
				cnt++;
			} while (c != ' ' && c != '\0' && c != '.' && c != ',' && c != '\n' && c != '?' && c != '!' && c != ';' && c != ':' &&
				c != '-' && c != '_' && c != '\t' && c != ')' && c != '(' && c != '/' && c != '&' && c != '"'); // повторяем до конца слова

			if (word = YES && symb == NO && cnt != cnt_max || symb == YES)
			{
				while (word_ptr < in_ptr)
				{
					*out_ptr++ = *word_ptr++; // копирование слова
				}
			}
			cnt = 0;
			word = NO;
			symb = NO;

		} while (c != '\0'); // продолжать до конца строки

		*out_ptr++ = c;

	} while (c != '\0'); // продолжать до конца строки
}
