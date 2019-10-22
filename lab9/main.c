#pragma warning(disable : 4996) //необходимо для использования устаревших функций (scanf)
#include <stdio.h>

/*определение символических констант*/
#define YES 1
#define NO 0
#define MAXLINE 1024  // максимальная длина массива

int main(int argc, char* argv[])
{
	/*объявление и инициализация*/
	char line[MAXLINE]; // текущая строка
	char result[MAXLINE]; // результирующая строка
	int word = NO; // признак слова
	int symb = NO; // индикатор наличия лишних символов
	int cnt = 0; // счетчик
	int cnt_max; // количество букв в самом длинном слове в текущей строке
	char* in_ptr = line; // указатель на текущий символ входной строки
	char* out_ptr = result; // указатель на текущий символ выходной строки
	char* word_ptr = line; // указатель на начало слова
	char* output_ptr = result; // указатель на результирующий массив

	FILE* fpin; // указатели на структуру типа FILE для входнго файла
	FILE* fpout; // указатели на структуру типа FILE для выходного файла

	char file_name[100] = "C:\\Users\\User\\source\\repos\\file.txt"; // файл для чтения по умолчанию
	char result_name[100] = "C:\\Users\\User\\source\\repos\\result.txt"; // файл для результата по умолчанию

	if (argc == 3)
	{
		fpin = fopen(argv[1], "rt"); // открыть файл для чтения
		fpout = fopen(argv[2], "wt"); // открыть файл для записи
	}
	else if (argc == 2)
	{
		fpin = fopen(argv[1], "rt"); // открыть файл для чтения
		fpout = fopen(result_name, "wt"); // открыть файл для записи
	}
	else
	{
		fpin = fopen(file_name, "rt"); // открыть файл для чтения
		fpout = fopen(result_name, "wt"); // открыть файл для записи
	}

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
			if (*in_ptr == '\0' || *in_ptr == '.' || *in_ptr == ' ' || *in_ptr == ',' || *in_ptr == '?' ||
				*in_ptr == '\t' || *in_ptr == ':' || *in_ptr == '/' || *in_ptr == '_' || *in_ptr == '(' ||
				*in_ptr == '\n' || *in_ptr == ')' || *in_ptr == '!' || *in_ptr == '&' || *in_ptr == '"') // разделитель найден
			{
				if (cnt > cnt_max&& symb == NO)
				{
					cnt_max = cnt;
				}
				symb = NO;
				cnt = 0;
			}
			else
			{
				cnt++;
				if ((*in_ptr < 'a' || *in_ptr > 'z') && (*in_ptr < 'A' || *in_ptr > 'Z')) // проверить не является ли этот символ лишним
				{
					symb = YES; // в слове есть лишний символ
				}
			}
		} while (*in_ptr++ != '\0');

		in_ptr = line;

		do
		{
			if (*in_ptr == '\0' || *in_ptr == '.' || *in_ptr == ' ' || *in_ptr == ',' || *in_ptr == '?' ||
				*in_ptr == '\t' || *in_ptr == ':' || *in_ptr == '/' || *in_ptr == '_' || *in_ptr == '(' ||
				*in_ptr == '\n' || *in_ptr == ')' || *in_ptr == '!' || *in_ptr == '&' || *in_ptr == '"') // разделитель найден
			{
				if (word == YES && cnt != cnt_max || symb == YES)
				{
					while (word_ptr < in_ptr)
					{
						*out_ptr++ = *word_ptr++; // копирование слова
					}
				}

				if (*in_ptr != '\0')
				{
					*out_ptr++ = *in_ptr;
				}
				word = NO;
				symb = NO;
				cnt = 0;
			}
			else
			{
				cnt++;
				if ((*in_ptr < 'a' || *in_ptr > 'z') && (*in_ptr < 'A' || *in_ptr > 'Z')) // проверить не является ли этот символ лишним
				{
					symb = YES; // в слове есть лишний символ
				}
				if (word == NO) // найдена первая буква слова
				{
					word_ptr = in_ptr; // запомнить адрес начала слова
				}
				word = YES;
			}
		} while (*in_ptr++ != '\0');
	}

	while (output_ptr != out_ptr)
	{
		fprintf(fpout, "%c", *output_ptr++);
	}

	fclose(fpin); // закрыть входной файл
	fclose(fpout); // закрыть выходной файл

	return 0;
}
