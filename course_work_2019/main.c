#pragma warning(disable : 4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 100
#define YES 1
#define NO 0

typedef struct
{
	float mon[1];
	float tue[1];
	float wed[1];
	float thu[1];
	float fri[1];
	float sat[1];
	float sun[1];
} schedule;

typedef struct
{
	char name[N];
	char surname[N];
	char specialty[N];
	int cabinet;
	schedule week;
	float from;
	float to;
} doctor;

doctor people[N];

int number = 0;
int num;
int found;

int menu(void);
void rep(void);
void edit(void);
void del(void);
void alph(void);
void cab(void);
void spec(void);
void times(void);
void read(void);
void save(void);
void shed(void);
int find_number(void);

int main(void)
{
	srand(time(NULL));

	int a;
	while ((a = menu()) != 9)
	{
		switch (a)
		{
		case 1:
			rep();
			break;
		case 2:
			edit();
			break;
		case 3:
			del();
			break;
		case 4:
			alph();
			break;
		case 5:
			cab();
			break;
		case 6:
			spec();
			break;
		case 7:
			times();
			break;
		case 8:
			read();
			break;
		default:
			printf("ERROR\n");
			system("pause");
		};
	}
	return 0;
}

int menu()
{
	system("cls");
	int m;
	printf("Select menu item:\n");
	printf("1-Base replenishment.\n");
	printf("2-Base editing.\n");
	printf("3-Delete records.\n");
	printf("4-Display the contents of the database by last name in alphabetical order.\n");
	printf("5-Displays the download of the selected cabinet by day of the week.\n");
	printf("6-Listing doctors in the specified specialty in alphabetical order.\n");
	printf("7-Selection of a doctor by profession and time of appointment.\n");
	printf("8-load from file\n");
	printf("9-Exit the program\n");
	scanf("%d", &m);
	system("cls");
	return m;
}

void rep(void)
{
	printf("Enter last name > ");
	scanf("%s", people[number].surname);

	printf("Enter name > ");
	scanf("%s", people[number].name);

	printf("Enter specialty > ");
	scanf("%s", people[number].specialty);

	printf("Enter cabinet number > ");
	scanf("%d", &people[number].cabinet);

	shed();
	
	number++;
	save();
	system("cls");
}

void edit(void)
{
	find_number();
	if (found == NO)
	{
		printf("a doctor with that name does not exist\n");
	}
	else
	{
		printf("Enter new last name > ");
		scanf("%s", people[num].surname);

		printf("Enter new name > ");
		scanf("%s", people[num].name);

		printf("Enter new specialty > ");
		scanf("%s", people[num].specialty);
	}
	save();
	alph();
}

void del(void)
{
	find_number();
	if (found == NO)
	{
		printf("a doctor with that name does not exist\n");
	}
	else
	{
		for (number--; num < number; num++)
		{
			people[num] = people[num + 1];
		}
		printf("a doctor with that name was delited\n");
	}
	save();
	alph();
}

void alph(void)
{
	int j;
	doctor Temp;

	for (j = number - 1; j > 0; j--)
	{
		for (num = 0; num < j; num++)
		{
			if (strcmp(people[num].surname, people[num + 1].surname) > 0)
			{
				Temp = people[num];
				people[num] = people[num + 1];
				people[num + 1] = Temp;
			}
		}
	}

	printf("N   surname              name                 specialty            cabinet\n");
	for (num = 0; num < number; num++)
	{
		printf("%-3d %-20s %-20s %-20s %-3d\n", num, people[num].surname, people[num].name, people[num].specialty, people[num].cabinet);
	}
	system("pause");
}

void cab(void) // Вывод загрузки выбранного кабинета по дням недели.
{
	found = NO;
	int zad_cab;
	printf("Enter cabinet > ");
	scanf("%d", &zad_cab);

	for (num = 0; num < number && found == NO; num++)
	{
		if (people[num].cabinet == zad_cab)
		{
			found = YES;
		}
	}

	printf("surname              name                 specialty            cabinet  from    to\n");

	printf("\nMonday\n");
	
	for (num = 0; num != number; num++)
	{
		if (people[num].cabinet == zad_cab)
		{
			printf("%-20s %-20s %-20s %-3d     %6.2f  %6.2f\n", people[num].surname, people[num].name, people[num].specialty, people[num].cabinet, people[num].week.mon[0], people[num].week.mon[1]);
		}
	}

	printf("\nTuesday\n");

	for (num = 0; num != number; num++)
	{
		if (people[num].cabinet == zad_cab)
		{
			printf("%-20s %-20s %-20s %-3d     %6.2f  %6.2f\n", people[num].surname, people[num].name, people[num].specialty, people[num].cabinet, people[num].week.tue[0], people[num].week.tue[1]);
		}
	}

	printf("\nWednesday\n");

	for (num = 0; num != number; num++)
	{
		if (people[num].cabinet == zad_cab)
		{
			printf("%-20s %-20s %-20s %-3d     %6.2f  %6.2f\n", people[num].surname, people[num].name, people[num].specialty, people[num].cabinet, people[num].week.wed[0], people[num].week.wed[1]);
		}
	}

	printf("\nThursday\n");

	for (num = 0; num != number; num++)
	{
		if (people[num].cabinet == zad_cab)
		{
			printf("%-20s %-20s %-20s %-3d     %6.2f  %6.2f\n", people[num].surname, people[num].name, people[num].specialty, people[num].cabinet, people[num].week.thu[0], people[num].week.thu[1]);
		}
	}

	printf("\nFriday\n");

	for (num = 0; num != number; num++)
	{
		if (people[num].cabinet == zad_cab)
		{
			printf("%-20s %-20s %-20s %-3d     %6.2f  %6.2f\n", people[num].surname, people[num].name, people[num].specialty, people[num].cabinet, people[num].week.fri[0], people[num].week.fri[1]);
		}
	}

	printf("\nSaturday\n");

	for (num = 0; num != number; num++)
	{
		if (people[num].cabinet == zad_cab)
		{
			printf("%-20s %-20s %-20s %-3d     %6.2f  %6.2f\n", people[num].surname, people[num].name, people[num].specialty, people[num].cabinet, people[num].week.sat[0], people[num].week.sat[1]);
		}
	}

	printf("\nSunday\n");

	for (num = 0; num != number; num++)
	{
		if (people[num].cabinet == zad_cab)
		{
			printf("%-20s %-20s %-20s %-3d     %6.2f  %6.2f\n", people[num].surname, people[num].name, people[num].specialty, people[num].cabinet, people[num].week.sun[0], people[num].week.sun[1]);
		}
	}

	if (found == NO)
	{
		system("cls");
		printf("cabinet %d does not exist\n", zad_cab);
	}

	system("pause");
}

void spec(void)
{
	char zad_specialty[N];
	printf("Enter specialty > ");
	scanf("%s", &zad_specialty);

	found = NO;
	int i;
	int flag;

	printf("surname              name                 specialty\n");

	for (num = 0; num < number; num++)
	{
		i = 0;
		flag = NO;

		do
		{
			if (people[num].specialty[i] != zad_specialty[i])
			{
				flag = YES;
				break;
			}
			i++;
		} while (people[num].specialty[i] != '\0' && zad_specialty[i] != '\0');

		if (flag == NO && people[num].specialty[i] == '\0' && zad_specialty[i] == '\0')
		{
			printf("%-20s %-20s %-10s\n", people[num].surname, people[num].name, people[num].specialty);
			found = YES;
		}
	}
	if (found == NO)
	{
		system("cls");
		printf("specialty %s does not exist\n", zad_specialty);
	}
	system("pause");
}

void times(void) // Подбор врача по специальности и времени приёма.
{
	char zad_specialty[N];
	printf("Enter specialty > ");
	scanf("%s", &zad_specialty);

	float zad_time;
	printf("Enter time > ");
	scanf("%f", &zad_time);

	// добавить дни недели

	found = NO;
	int i;
	int flag;

	printf("surname              name                 specialty\n");

	for (num = 0; num < number; num++)
	{
		i = 0;
		flag = NO;

		do
		{
			if (people[num].specialty[i] != zad_specialty[i])
			{
				flag = YES;
				break;
			}
			i++;
		} while (people[num].specialty[i] != '\0' && zad_specialty[i] != '\0');

		if (flag == NO && people[num].specialty[i] == '\0' && zad_specialty[i] == '\0' && people[num].week.sun[0] < zad_time && people[num].week.sun[1] > zad_time)
		{
			printf("%-20s %-20s %-10s %6.2f  %6.2f\n", people[num].surname, people[num].name, people[num].specialty, people[num].week.sun[0], people[num].week.sun[1]); // добавить не только вс
			found = YES;
		}
	}
	if (found == NO)
	{
		system("cls");
		printf("specialty %s does not exist\n", zad_specialty);
	}
	system("pause");
}

void read(void)
{
	FILE* fpin = fopen("C:\\Users\\User\\source\\repos\\file.txt", "rt"); // открыть входной файл для чтения
	
	if (fpin == NULL)
	{
		printf("error opening file input\n"); // информация об ошибке
		return; // ошибка при открытии файла
	}

	while (!feof(fpin)) // цикл до конца файла
	{
		int i, j;
		char line[N];
		char* ptr = fgets(line, N, fpin); // чтение строки

		if (ptr == NULL)
		{
			break; // файл исчерпан
		}

		for (i = 0, j = 0; line[i] != ' '; i++, j++)
		{
			people[number].surname[j] = line[i];
		}

		for (i++, j = 0; line[i] != ' '; i++, j++)
		{
			people[number].name[j] = line[i];
		}

		for (i++, j = 0; line[i] != '\n' && line[i] != '\0'; i++, j++)
		{
			people[number].specialty[j] = line[i];
		}

		people[number].cabinet = 1 + rand() % 15;

		shed();

		number++;
	}

	fclose(fpin); // закрыть входной файл

	save();
	alph();
}

void save(void)
{
	FILE* fpout = fopen("C:\\Users\\User\\source\\repos\\file.txt", "wt"); // открыть файл для записи

	if (fpout == NULL)
	{
		printf("error opening file output\n"); // информация об ошибке
		return; // ошибка при открытии файла
	}

	for (num = 0; num < number; num++)
	{
		fprintf(fpout, "%s %s %s\n", people[num].surname, people[num].name, people[num].specialty);
	}

	fclose(fpout); // закрыть выходной файл
}

int find_number(void)
{
	found = NO;
	int i;
	int flag;
	char find_surname[N];
	printf("Enter last name > ");
	scanf("%s", find_surname);

	for (num = 0; num < number && found == NO; num++)
	{
		i = 0;
		flag = NO;

		do
		{
			if (people[num].surname[i] != find_surname[i])
			{
				flag = YES;
				break;
			}
			i++;
		} while (people[num].surname[i] != '\0' && find_surname[i] != '\0');

		if (flag == NO && people[num].surname[i] == '\0' && find_surname[i] == '\0')
		{
			found = YES;
			break;
		}
	}
}

void shed(void)
{
	people[number].week.mon[0] = (0 + rand() % 23) + ((0 + rand() % 60) / 100.0);
	people[number].week.mon[1] = people[number].week.mon[0] + 8;

	people[number].week.tue[0] = (0 + rand() % 23) + ((0 + rand() % 60) / 100.0);
	people[number].week.tue[1] = people[number].week.tue[0] + 8;

	people[number].week.wed[0] = (0 + rand() % 23) + ((0 + rand() % 60) / 100.0);
	people[number].week.wed[1] = people[number].week.wed[0] + 8;

	people[number].week.thu[0] = (0 + rand() % 23) + ((0 + rand() % 60) / 100.0);
	people[number].week.thu[1] = people[number].week.thu[0] + 8;

	people[number].week.fri[0] = (0 + rand() % 23) + ((0 + rand() % 60) / 100.0);
	people[number].week.fri[1] = people[number].week.fri[0] + 8;

	people[number].week.sat[0] = (0 + rand() % 23) + ((0 + rand() % 60) / 100.0);
	people[number].week.sat[1] = people[number].week.sat[0] + 8;

	people[number].week.sun[0] = (0 + rand() % 23) + ((0 + rand() % 60) / 100.0);
	people[number].week.sun[1] = people[number].week.sun[0] + 8;
}
