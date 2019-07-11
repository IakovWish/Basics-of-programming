#pragma warning(disable : 4996) // чиним fopen

#include <stdio.h>

#define MAXLINE 1000 // размер массива

char ORIG[MAXLINE]; // задаем массив, в который перепишем данные из файла
char CODED[MAXLINE]; // массив с закодированными данными
char RES[MAXLINE]; // массив с результатами
int MISTAKES[MAXLINE]; // массив с позициями ошибок

int pos; // позиция элемента в массиве
int pos_; // позиция элемента массиве
int mistake; // количество ошибок
int kolvo; // количество элементов в исходном массиве

void read(char ORIG[]); // читаем данные из файла
void coder(char CODED[]); // кодируем их
void channel(char CODED[]); // добавляем ошибки
void decoder(char CODED[]); // раскодировываем
void writer(char CODED[]); // выводим результаты
void ERRORS(int MISTAKES[]); // выводим ошибки

int main(void) // главная функция
{
	read(ORIG); // читаем данные из файла
	coder(CODED); // кодируем их
	channel(CODED); // добавляем ошибки
	decoder(CODED); // раскодировываем
	writer(CODED); // записываем
	ERRORS(MISTAKES); // отчет о добавленных ошибках
	return 0;
}

void read(char ORIG[]) // читаем
{
	FILE* fp = fopen("file.txt", "r");
	if (NULL == fp)// если файл с данными отсутствует, то...
	{
		printf("error: file not found\n"); // выводим ошибку
		exit(1); // выходим из программы
	}
	else
	{
		while (!feof(fp))
		{
			fgets(ORIG, 999, fp);
		}
		fclose(fp); // закрываем файл
	}

	for (kolvo = 0, pos = 0; ORIG[pos] == '1' || ORIG[pos] == '0' || pos > 998; pos++, kolvo++) {} // считаем кол-во элементов в исходном массиве

	if (kolvo == 0) // если в файле пусто, то...
	{
		printf("ERROR\nPlease add original data to file\n"); // выводим ошибку
		exit(1); // выходим из программы
	}

	printf(" |original data|\n"); // подсказка
	puts (ORIG); // выводим оригинальный код
}

void coder(char CODED[]) // кодируем
{
	for (pos = 0, pos_ = 0; pos_ != kolvo; pos_++) // преобразуем данные из исходного массива в новые данные и заполняем ими новый массив
	{
		if (ORIG[pos_] == '1' || ORIG[pos_] == '0')
		{
			CODED[pos++] = ORIG[pos_];
			CODED[pos++] = ORIG[pos_];
			CODED[pos++] = ORIG[pos_];
		}
	}

	printf(" |coded data|\n"); // подсказка
	puts(CODED); // выводим закодированный код
}

void channel(char CODED[]) // добавляем ошибки
{
	srand(time(NULL)); // включаем рандом

	pos_ = 0;

	int max_mistake = kolvo * 3 * 40 / 100; // выщитываем максимальное допустимое количество ошибок
	mistake = 0 + rand() % max_mistake; // выщитываем, сколько добавить ошибок

	while (pos_ != mistake) // добавляем все ошибки
	{
		pos = 0 + rand() % (kolvo * 3 - 1); // берем рандомный элемент
		MISTAKES[pos_++] = pos + 1; // запоминаем его позицию

		if (CODED[pos] == '1') // если это единица, то...
		{
			CODED[pos] = '0'; // меняем его на нуль
		}
		else // если ноль, то...
		{
			CODED[pos] = '1'; // меняем его на единицу
		}
	}

	printf(" |data with mistakes|\n"); // подсказка
	puts(CODED); // выводим масссив с ошибками
}

void decoder(char CODED[]) // раскодировываем
{
	pos = 0;
	pos_ = 0;
	char pred = CODED[pos++]; // предыдущий элемент
	char c = CODED[pos++]; // текущий элемент
	
	while (pos_ != kolvo * 3) // пока не пройдем каждый элемент
	{
		if (pred == c) // если 2 символа равны, то...
		{
			RES[pos_++] = c; // записываем в результат
			CODED[pos++]; // 3й символ нас не интересует
		}
		else // если не равны, тогда...
		{
			RES[pos_++] = CODED[pos++]; // от 3го зависит результат, поэтому его и пишем
		}
		pred = CODED[pos++]; // переходим к следующим тройкам
		c = CODED[pos++]; // тоже самое
	}
}

void writer(char CODED[]) // записываем результат
{
	printf(" |result|\n"); // подсказка
	puts(RES); // выводим результат

	FILE* in = fopen("result.txt", "a"); // открываем файл
	if (NULL == in) // если он не доступен, то...
	{
		printf("error: could not create file\n"); // выводим ошибку
		exit(1); // выходим из программы
	}
	else
	{
		fputs(RES, in); // вставляем результаты в файл
		fprintf(in, "\n");
		fclose(in); // закрываем файл
	}
}

void ERRORS(int MISTAKES[]) // вставляем позицию ошибочных элементов
{
	printf(" |error position|\n"); // подсказка

	for (pos = 0; pos != mistake; pos++) // вставляем позиции ошибок
	{
		printf("%d ", MISTAKES[pos]);
	}
}
