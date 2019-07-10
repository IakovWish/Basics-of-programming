#pragma warning(disable : 4996) // чиним fopen

#include<stdio.h>

#define MAXLINE 1000 // размер массива

char line[MAXLINE]; // задаем массив, в который перепишем данные из файла
char RES[MAXLINE]; // массив с результатами
int MISTAKES[MAXLINE]; // массив с ошибками

int pos = 0; // позиция элемента в массиве
int mistake; // количество ошибок
int kolvo = 0; // количество элементов в массиве

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

	for (pos = 0; line[pos] == '1' || line[pos] == '0' || pos > 998; pos++, kolvo++) {} // считаем количество элементов

	for (pos = 0; pos != kolvo; pos++) // выводим оригинальный массив
	{
		printf("%c", line[pos]);
	}
	printf(" original data\n"); // подсказка
}

void coder(char line[]) {} // кодируем

void channel(char line[]) // добавляем ошибки
{
	srand(time(NULL)); // включаем рандом

	int cnt = 0; // счетчик

	int max_mistake = kolvo * 70 / 100; // выщитываем максимальное допустимое количество ошибок
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

	for (pos = 0; pos != kolvo; pos++) // выводим массив с ошибками
	{
		printf("%c", line[pos]);
	}
	printf(" data with mistakes\n"); // подсказка
}

void decoder(char line[]) // раскодировываем
{
	pos = 0;
	char pred = line[pos++]; // предыдущий элемент
	char c = line[pos++]; // текущий элемент
	int i = 0; // как pos
	while (i != kolvo) // пока не пройдем каждый элемент
	{
		RES[i++] = ' '; // для красоты
		if (pred == c) // если 2 символа равны, то...
		{
			RES[i++] = c; // записываем в результат
			line[pos++]; // 3й символ нас не интересует
		}
		else // если не равны, тогда...
		{
			RES[i++] = line[pos++]; // от 3го зависит результат, поэтому его и пишем
		}
		RES[i++] = ' '; // для красоты
		pred = line[pos++]; // переходим к следующим тройкам
		c = line[pos++]; // тоже самое
	}
}

void writer(char line[]) // записываем результат
{
	for (pos = 0; pos != kolvo; pos++) // в консоль
	{
		printf("%c", RES[pos]);
	}
	printf("result\n"); // подсказка

	FILE* in = fopen("result.txt", "a"); // и в файл
	if (NULL == in)
	{
		printf("ошибка\n");
		return 0;
	}
	else
	{
		fputs(RES, in);
		fprintf(in, "\n");
		fclose(in);
	}
}

void ERRORS(char line[]) // вставляем позицию ошибочных элементов
{
	for (pos = 0; pos != mistake; pos++) // перечисляем все ошибки
	{
		printf("%d ", MISTAKES[pos]); // и вставляем их позиции
	}
	printf("error position\n"); // подсказка
}
