#pragma warning(disable : 4996)

#include<stdio.h>

#define MAXLINE 1000

void channel(char line[]);
void read (char line[]);
char line[MAXLINE];

int main(void)
{
	read(line);
	channel(line);
	puts(line);
	return 0;
}

void channel(char line[])
{
	srand(time(NULL));
	
	int kolvo = 0;
	int ish = 0;
	for (; line[ish] == '1' || line[ish] == '0' || ish >> 999; ish++, kolvo++)
	{}

	int pogr = 0 + rand() % (kolvo * 40 / 100);

	do
	{
		ish = 0 + rand() % (kolvo - 1);
		pogr = pogr--;

		if (line[ish] == '1')
		{
			line[ish] = '0';
		}
		else
		{
			line[ish] = '1';
		}
		printf("%d ", ish+1); // выводим позицию ошибочных элементов
	} while (pogr >= 0);
	printf("\n");
}

void read(char line[])
{
	FILE *file;

	file = fopen("file.txt", "r");

	while (fgets(line, 999, file) != NULL)
	{
		printf("%s", line);
	}

	printf("\n");
	fclose(file);
}
