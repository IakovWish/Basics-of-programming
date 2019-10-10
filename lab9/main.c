#pragma warning(disable : 4996) //необходимо для использования устаревших функций (scanf)
#include <stdio.h>

/*определение символических констант*/
#define YES 1
#define NO 0
#define MAXLINE 1024  // максимальная длина массива

int main(void)
{
	/*объявление и инициализация*/
	char line[MAXLINE]; // текущая строка
	char result[MAXLINE]; // результирующая строка
	char c; // текущий символ
	int word = NO; // признак слова
	int symb = NO; // индикатор наличия лишних символов
	int cnt = 0; // счетчик
	int cnt_max; // количество букв в самом длинном слове в текущей строке
	char* in_ptr = line; // указатель на текущий символ входной строки
	char* out_ptr = result; // указатель на текущий символ выходной строки
	char* word_ptr = line; // указатель на начало слова
	char* output_ptr = result; // указатель на результирующий массив

	FILE* fpin = fopen("file.txt", "rt"); // открыть файл для чтения
	FILE* fpout = fopen("result.txt", "wt"); // открыть файл для записи

	if (fpin == NULL)
	{
		printf ("error opening file\n"); // информация об ошибке
		return; // ошибка при открытии файла
	}

	if (fpout == NULL)
	{
		printf("error opening file\n"); // информация об ошибке
		return; // ошибка при открытии файла
	}

	while (!feof(fpin))// цикл до конца файла
	{
		cnt_max = 0; // перед рассмотрением каждой строки аннулируем количество букв в самом длинном слове
		in_ptr = fgets(line, MAXLINE, fpin); // получакм новую строку и ставим на нее указатель

		if (in_ptr == NULL)
		{
			break; // файл исчерпан
		}

		do
		{
			c = *in_ptr; // взять текущий символ из буфера
			if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '?' || c == '!' || c == ';' || c == ':' ||
				c == '-' || c == '_' || c == '(' || c == ')' || c == '\t' || c == '/' || c == '&' || c == '"') // разделитель найден
			{
				if (cnt > cnt_max && symb == NO)
				{
					cnt_max = cnt;
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
				}
				if (word == NO) // найдена первая буква слова
				{
					word_ptr = in_ptr; // запомнить адрес начала слова
				}
				word = YES;
			}
			in_ptr++;
		} while (c != '\0');

		in_ptr = line;

		do
		{
			c = *in_ptr; // взять текущий символ из буфера
			if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '?' || c == '!' || c == ';' || c == ':' ||
				c == '-' || c == '_' || c == '(' || c == ')' || c == '\t' || c == '/' || c == '&' || c == '"') // разделитель найден
			{
				if (word == YES && symb == NO && cnt != cnt_max || symb == YES)
				{
					while (word_ptr < in_ptr)
					{
						*out_ptr++ = *word_ptr++; // копирование слова
					}
				}
				else
				{
					word_ptr = word_ptr + cnt_max;
				}

				if (c != '\0')
				{
					*out_ptr++ = c;
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
				}
				if (word == NO) // найдена первая буква слова
				{
					word_ptr = in_ptr; // запомнить адрес начала слова
				}
				word = YES;
			}
			in_ptr++;
		} while (c != '\0');
	}

	while (output_ptr != out_ptr)
	{
		fprintf(fpout, "%c", *output_ptr++);
	}

	fclose(fpin); // закрыть входной файл
	fclose(fpout); // закрыть выходной файл

	return 0;
}
