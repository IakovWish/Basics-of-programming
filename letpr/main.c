#pragma warning(disable : 4996)

#include<stdio.h> 

#define MAXLINE 1000

int main(void)
{
	srand(time(NULL));

	char line[MAXLINE];
	int kolvo = 0;
	int ish;
	int mist;
	int pogr;

	gets(line);

	for (ish = 0; line[ish] == '1' || line[ish] == '0' || ish == 999; ish++)
	{
		kolvo++;
	}

	pogr = 0 + rand() % (kolvo *40/100);

	do
	{
		mist = 0 + rand() % 2;
		ish = 0 + rand() % (kolvo-1);
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
