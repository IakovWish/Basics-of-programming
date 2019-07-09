#pragma warning(disable : 4996) // чиним fopen

#include<stdio.h>

#define MAXLINE 1000 // размер массива
char line[MAXLINE]; // задаем массив, в который перепишем данные из файла
int MISTAKES[MAXLINE]; // массив с ошибками
int pos = 0; // позиция элемента в массиве

int mistake; // количество ошибок

void read(char line[]); // читаем данные из файла
void coder(char line[]); // кодируем их
void channel(char line[]); // добавляем ошибки
void decoder(char line[]); // раскодировываем
void writer(char line[]); // выводим результаты
void ERRORS(char line[]); // выводим ошибки

int main(void)
{
	read(line); // читаем данные из файла
	coder(line); // кодируем их
	channel(line); // добавляем ошибки
	decoder(line); // раскодировываем
	writer(line); // записываем
	ERRORS(line); // отчет о добавленных ошибках
	return 0;
}

void read(char line[]) // читаем
{
	FILE* fp = fopen("file.txt", "r");
	if (NULL == fp)
	{
		printf("ошибка\n");
		return 0;
	}
	
	while (!feof(fp))
	{
		fgets(line, 999, fp);
	}
	fclose(fp);

	puts(line); //вставляем исходные данные
}

void coder(char line[]) {} // кодируем

void channel(char line[]) // добавляем ошибки
{
	srand(time(NULL)); // рандом

	int kolvo = 0; // количество элементов в массиве
	int cnt = 0; // счетчик

	for (; line[pos] == '1' || line[pos] == '0' || pos > 998; pos++, kolvo++) {} // считаем количество элементов

	int max_mistake = kolvo * 40 / 100; // выщитываем максимальное допустимое количество ошибок
	mistake = 0 + rand() % max_mistake; // выщитываем, сколько добавить ошибок

	while (cnt != mistake) // добавляем все ошибки
	{
		pos = 0 + rand() % (kolvo - 1); // берем рандомный элемент
		MISTAKES[cnt++] = pos + 1; // запоминаем его

		if (line[pos] == '1') // если это единица, то...
		{
			line[pos] = '0'; // меняем его на нуль
		}
		else // если это нуль...
		{
			line[pos] = '1'; //меняем его на единицу
		}
	}
}

void decoder(char line[]) {} // раскодировываем

void writer(char line[]) // записываем результат
{
	puts(line); // вставляем результат
}

void ERRORS(char line[]) // вставляем позицию ошибочных элементов
{
	for (pos = 0; pos != mistake; pos++) // перечисляем все ошибки
	{
		printf("%d ", MISTAKES[pos]); // и вставляем их позиции
	}
}
