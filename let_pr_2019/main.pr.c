#pragma warning(disable : 4996) // чиним fopen

#include<stdio.h>

#define MAXLINE 1000 // размер массива

char line[MAXLINE]; // задаем массив, в который перепишем данные из файла
int MISTAKES[MAXLINE]; // массив с ошибками
char RES[MAXLINE];
int i = 0;
int k = 0;
char f;
char s;
char t;
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
	coder(line); // кодируем их // миша
	channel(line); // добавляем ошибки
	decoder(line); // раскодировываем // яша
	writer(line); // записываем // миша
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

void decoder(char line[]) // раскодировываем
{
	k = 0;
	pos = 0;
	while (k != kolvo/3)
	{
		if (line[pos++] == '0') // 1
		{
			f = '0';
			if (line[pos++] == '0') // 2
			{
				s = '0';
				if (line[pos++] == '0') // 3
				{
					t = '0'; // 
					k++;
				}
				else //3
				{
					t = '1'; //
					k++;
				}
			}
			else // 2
			{
				s = '1';
				if (line[pos++] == '0') // 3
				{
					t = '0';
					k++;
				}
				else //3
				{
					t = '1'; //
					k++;
				}
			}
		}
		else // 1
		{
			f = '1';
			if (line[pos++] == '1') // 2
			{
				s = '1';
				if (line[pos++] == '1') // 3
				{
					t = '1'; // 
					k++;
				}
				else // 3
				{
					t = '1'; // 
					k++;
				}
			}
			else // 2
			{
				s = '0';
				if (line[pos++] == '1') // 3
				{
					t = '1'; // 
					k++;
				}
				else // 3
				{
					t = '0'; // 
					k++;
				}
			}
		}
		if (f + s + t == 3 || f + s + t == 2)
		{
			RES[i++] = '1';
		}
		else
		{
			RES[i++] = '0';
		}
	}
}

void writer(char line[]) // записываем результат
{
	puts(line); // вставляем результат
	puts(RES);
}

void ERRORS(char line[]) // вставляем позицию ошибочных элементов
{
	for (pos = 0; pos != mistake; pos++) // перечисляем все ошибки
	{
		printf("%d ", MISTAKES[pos]); // и вставляем их позиции
	}
}
