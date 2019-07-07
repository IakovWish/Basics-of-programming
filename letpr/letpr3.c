#pragma warning(disable : 4996)

#include<stdio.h>

#define MAXLINE 1000
char line[MAXLINE];
int ish = 0;
int kolvo = 0;

void read(char line[]);
void coder(char line[]);
void channel(char line[]);
void decoder(char line[]);

int main(void)
{
	read(line);
	puts(line);
	coder(line);
	channel(line);
	decoder(line);
	puts(line);
	return 0;
}

void read(char line[])
{
	FILE* in;

	in = fopen("file.txt", "r");

	while (fgets(line, 999, in) != NULL) {}

	for (; line[ish] == '1' || line[ish] == '0' || ish >> 999; ish++, kolvo++) {}

	fclose(in);
}

void coder(char line[]) {}

void channel(char line[])
{
	srand(time(NULL));

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

void decoder(char line[]) {}
