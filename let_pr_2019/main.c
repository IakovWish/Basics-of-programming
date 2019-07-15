#pragma warning(disable : 4996) // чиним fopen

#include <stdio.h>

#define MAXLINE 1000 // размер массива

char orig[MAXLINE]; // задаем массив, в который перепишем данные из файла
char coded[MAXLINE]; // массив с закодированными данными
char result[MAXLINE]; // массив с результатами
int mistakes[MAXLINE]; // массив с позициями ошибок

int pos; // позиция элемента в массиве
int pos_; // позиция элемента массиве
int mistake; // количество ошибок
int kolvo_orig; // количество элементов в исходном массиве
int kolvo_coded;  // количество элементов в закодированном массиве

void read(char orig[]); // читаем данные из файла
void coder(char coded[]); // кодируем их
void channel(char coded[]); // добавляем ошибки
void decoder(char coded[]); // раскодировываем
void writer(char coded[]); // выводим результаты
void errors(int mistakes[]); // выводим ошибки

int main(void) // главная функция
{
	read(orig); // читаем данные из файла
	coder(coded); // кодируем их
	channel(coded); // добавляем ошибки
	decoder(coded); // раскодировываем
	writer(coded); // записываем
	errors(mistakes); // отчет о добавленных ошибках
}

void read(char orig[]) // читаем
{
	FILE* fp = fopen("file.txt", "r");
	if (NULL == fp)// если файл с данными отсутствует, то...
	{
		printf("|error: file not found|\n"); // выводим ошибку
		exit(1); // выходим из программы
	}
	else
	{
		while (!feof(fp))
		{
			fgets(orig, 999, fp);
		}
-		fclose(fp); // закрываем файл
	}

	for (kolvo_orig = 0, pos = 0; orig[pos] != '\0'; pos++, kolvo_orig++) {} // считаем кол-во элементов в исходном массиве

	if (kolvo_orig == 0 || kolvo_orig > 334) // если в файле пусто, то или больше, чем надо
	{
		printf("\nerror: Please change original data in file\n"); // выводим ошибку и...
		exit(1); // выходим из программы
	}

	kolvo_coded = kolvo_orig * 3; // считаем сколько символов будет в закодированном массиве

	printf(" |original data|\n"); // подсказка
	puts (orig); // выводим оригинальный код
}

void coder(char CODED[]) // кодируем
{
	for (pos = 0, pos_ = 0; pos_ != kolvo_orig; pos_++) // кодируем и заполняем новый массив
	{
			CODED[pos++] = orig[pos_];
			CODED[pos++] = orig[pos_];
			CODED[pos++] = orig[pos_];
	}

	printf(" |coded data|\n"); // подсказка
	puts(CODED); // выводим закодированный код
}

void channel(char coded[]) // добавляем ошибки
{
	srand(time(NULL)); // включаем рандом

	pos_ = 0;
	int error; // погрешность в процентах
	printf(" |Please enter error in percent|\n"); // подсказка
	scanf_s ("%d", &error); // считываем с клавиатуры
	int max_mistake = kolvo_coded * error / 100; // выщитываем максимальное допустимое количество ошибок
	mistake = 0 + rand() % max_mistake; // выщитываем, сколько добавить ошибок

	while (pos_ != mistake) // добавляем все ошибки
	{
		pos = 0 + rand() % (kolvo_coded - 1); // берем рандомный элемент
		mistakes[pos_++] = pos + 1; // запоминаем его позицию

		if (coded[pos] == '1') // если это единица, то...
		{
			coded[pos] = '0'; // меняем его на нуль
		}
		else if (coded[pos] == '0')// если ноль, то...
		{
			coded[pos] = '1'; // меняем его на единицу
		}
		else 
		{
			coded[pos] = 33 + rand() % 126; // остальные без разницы, главное чтобы не портили прогу (типо \0)
		}
	}

	printf(" |data with mistakes|\n"); // подсказка
	puts(coded); // выводим масссив с ошибками
}

void decoder(char coded[]) // раскодировываем
{
	pos = pos_ = 0;

	char pred = coded[pos++]; // предыдущий элемент
	char tek = coded[pos++]; // текущий элемент
	char sled = coded[pos++]; // следующий элемент

	while (pos_ != kolvo_coded) // пока не пройдем каждый элемент
	{
		if (pred == tek || tek == sled) // если 2 символа равны, то...
		{
			result[pos_++] = tek; // записываем в результат
		}
		else if (pred == sled || tek == sled) // или 2 таких символа равны...
		{
			result[pos_++] = sled; // тогда такой результат
		}
		else // если все 3 символа не равны, то...
		{
			result[pos_++] = '?'; // вместо символа пишем '?', так будем отличать символ, который не возможно распознать
		}

		pred = coded[pos++]; // переходим к следующим тройкам
		tek = coded[pos++]; // тоже самое
		sled = coded[pos++]; // и тут
	}
	result[pos_] = '\n'; // для красоты
}

void writer(char coded[]) // записываем результат
{
	printf(" |result|\n"); // подсказка
	puts(result); // выводим результат

	FILE* in = fopen("result.txt", "a"); // открываем файл
	if (NULL == in) // если он не доступен, то...
	{
		printf("\nerror: could not create file\n"); // выводим ошибку
		exit(1); // выходим из программы
	}
	else
	{
		fputs(result, in); // вставляем результаты в файл
		fclose(in); // закрываем файл
	}
}

void errors(int mistakes[]) // вставляем позицию ошибочных элементов
{
	printf(" |error position|\n"); // подсказка

	for (pos = 0; pos != mistake; pos++) // вставляем позиции ошибок
	{
		printf("%d ", mistakes[pos]);
	}
}
