#pragma warning(disable : 4996)

#include<stdio.h> 

#define MAXLINE 1000

int main(void)
{
	srand(time(NULL));

	char line[MAXLINE];
	gets(line);
	int pogr = 0 + rand() % 20;
	int ish;
	int mist;

	do
	{
		mist = 0 + rand() % 2;
		ish = 0 + rand() % 20;
		pogr = pogr--;

		if (mist == 1)
		{
			line[ish] = '0';
		}

		else
		{
			line[ish] = '1';
		}
	}
	while (pogr >= 0);
	puts(line);
	return 0;
}
