#pragma warning(disable : 4996) //необходимо для использования устаревших функций (scanf)

#include <stdio.h>
#define MAXLINE 1024
int main(void)
{
	/*указатели на структуру типа FILE для входного и выходного файлов*/
	FILE* fpin;
	FILE* fpout;
	char line[MAXLINE]; // текущая строка
	char* ptr;

	/*открыть файл для чтения*/
	fpin = fopen("test.txt", "rt");
	if (fpin == NULL)
	{
		return; // ошибка при открытии файла
	}

	/*открыть файл для записи*/
	fpout = fopen("result.txt", "wt");
	if (fpout == NULL)
	{
		return; // ошибка при открытии файла
	}

	while (!feof(fpin))// цикл до конца файла
	{
		/*чтение строки*/
		ptr = fgets(line, MAXLINE, fpin);
		if (ptr == NULL)
		{
			break; // файл исчерпан
		}

		while (*ptr != '\0') // цикл до конца строки
		{
			if (*ptr == ' ' || *ptr == '.' || *ptr == ',') // найден разделитель слова
			{
				*ptr++ = '\n'; // ставим символ "конец строки"
				*ptr = '\0'; // ставим ограничитель строки
				break;
			}
			ptr++; // продвигаем указатель по строке
		}
		fputs(line, fpout); // запись строки
	}
	fclose(fpin); // закрыть входной файл
	fclose(fpout); // закрыть выходной файл
	return 0;
}
