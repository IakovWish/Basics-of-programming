#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>
#include <windows.h>

#define YES 1
#define NO 0

int main(void)
{
	char directives[12][8];

	strcpy(directives[0], "include");
	strcpy(directives[1], "define");
	strcpy(directives[2], "undef");
	strcpy(directives[3], "if");
	strcpy(directives[4], "ifdef");
	strcpy(directives[5], "ifndef");
	strcpy(directives[6], "else");
	strcpy(directives[7], "elif");
	strcpy(directives[8], "endif");
	strcpy(directives[9], "line");
	strcpy(directives[10], "error");
	strcpy(directives[11], "pragma");

	HANDLE hStdout;
	WORD foregroundColor0;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	foregroundColor0 = FOREGROUND_BLUE;
	SetConsoleTextAttribute(hStdout, foregroundColor0);

	FILE* f = fopen("C:\\Users\\User\\source\\repos\\test11.txt", "r");
	if (f == NULL)
	{
		return;
	}

	char line[100];
	char* ptr = NULL;
	char mas[8];
	char* pptr;

	while (!feof(f))
	{
		fgets(line, 100, f);
		ptr = line;

		while (*ptr != '\n' && *ptr != '\0')
		{
			int i = 0;
			if (*ptr == '#')
			{
				pptr = ptr + 1;

				do
				{
					mas[i] = *pptr;
				} while (*pptr != ' ' && i++ != 8 && *pptr != '\0' && *pptr++ != '\n');

				i = 0;
				int j = 0;
				int flag = NO;

				for (j = 0; j < 12; j++)
				{
					i = 0;
					do
					{
						if (mas[i] != directives[j][i])
						{
							flag = YES;
							break;
						}
						i++;
					} while (mas[i] != ' ' && directives[j][i] != '\0');

					if (flag == NO && (mas[i] == ' ' || mas[i] == '\0' || mas[i] == '\n') && directives[j][i] == '\0')
					{
						SetConsoleTextAttribute(hStdout, foregroundColor0);
						break;
					}

					flag = NO;
				}
			}

			while (*ptr != ' ' && *ptr != '\n' && *ptr != '\0')
			{
				printf("%c", *ptr++);
			}

			if (*ptr != '\0')
			{
				printf("%c", *ptr++);
			}

			SetConsoleTextAttribute(hStdout, 7);
		}

		if (*ptr == '\n')
		{
			printf("%c", *ptr++);
		}
	}
	return 0;
}
