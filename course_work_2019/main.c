#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

#define N 100
#define YES 1
#define NO 0

typedef struct
{
	char name[N];
	char surname[N];
	char specialty[N];
	int cabinet;
	float timing[7][2];
} doctor;

doctor* people;

//char day_week[N];
int number = 0;
int num;
int found;
int cntt = 0;

int menu(void); // Меню.
void rep(void); // Пополнение базы.
void edit(void); // Редактирование базы.
void del(void); // Удаление записей.
void alph(void); // Вывод содержимого базы по фамилиям в алфавитном порядке.
void cab(void); // Вывод загрузки выбранного кабинета по дням недели.
void spec(void); // Вывод списка врачей по указанной специальности в алфавитном порядке.
void times(void); // Подбор врача по специальности и времени приёма.
void read(void); // Чтение из файла.
void save(void); // Запись в файл.
void find_number(void); // Поиск номера по фамилии.
void count(void);
//void day_finder(void);

int main(void)
{
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
	count();
	people = (doctor*)realloc(people, (++cntt) * sizeof(doctor));

	FILE* fpout = fopen("C:\\Users\\User\\source\\repos\\file.txt", "a"); // открыть файл для записи

	int k;

	printf("Enter last name > ");
	scanf("%s", &people[number].surname);
	fprintf(fpout, "%s ", people[number].surname);

	printf("Enter name > ");
	scanf("%s", &people[number].name);
	fprintf(fpout, "%s ", people[number].name);

	printf("Enter specialty > ");
	scanf("%s", &people[number].specialty);
	fprintf(fpout, "%s ", people[number].specialty);

	printf("Enter cabinet number > ");
	scanf("%d", &people[number].cabinet);
	fprintf(fpout, "%d", people[number].cabinet);

	for (k = 0; k < 7; k++)
	{
		//day_finder();

		printf("Enter the start time on the %d day > ", k + 1);
		scanf("%f", &people[number].timing[k][0]);
		fprintf(fpout, " %.2f ", people[number].timing[k][0]);

		printf("Enter the end time on the %d day> ", k + 1);
		scanf("%f", &people[number].timing[k][1]);
		fprintf(fpout, "%.2f", people[number].timing[k][1]);
	}
	fprintf(fpout, "\n");

	fclose(fpout); // закрыть выходной файл
	number++;
	system("cls");
}

void edit(void)
{
	int k;

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

		printf("Enter new cabinet > ");
		scanf("%d", &people[num].cabinet);

		for (k = 0; k < 7; k++)
		{
			printf("Enter the new start time on the %d day > ", k + 1);
			scanf("%f", &people[num].timing[k][0]);

			printf("Enter the new end time on the %d day > ", k + 1);
			scanf("%f", &people[num].timing[k][1]);
		}
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

	count();
	people = (doctor*)realloc(people, (--cntt) * sizeof(doctor));
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

	int day;
	printf("Enter day of the week > ");
	scanf("%d", &day);

	for (num = 0; num < number && found == NO; num++)
	{
		if (people[num].cabinet == zad_cab)
		{
			found = YES;
			break;
		}
	}

	if (found == YES)
	{
		printf("%d\n", day);
		printf("surname              name                 specialty            cabinet  from    to\n");

		for (num = 0; num < number; num++)
		{
			if (people[num].cabinet == zad_cab)
			{
				printf("%-20s %-20s %-20s %-3d    %6.2f  %6.2f\n", people[num].surname, people[num].name, people[num].specialty, people[num].cabinet, people[num].timing[day - 1][0], people[num].timing[day - 1][1]);
			}
		}
	}
	else
	{
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

	int day;
	printf("Enter day of the week > ");
	scanf("%d", &day);

	found = NO;
	int i;
	int flag = NO;

	printf("surname              name                 specialty            cabinet  from    to\n");

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

		if (flag == NO && people[num].specialty[i] == '\0' && zad_specialty[i] == '\0' && people[num].timing[day - 1][0] < zad_time && people[num].timing[day - 1][1] > zad_time)
		{
			printf("%-20s %-20s %-20s %-3d     %6.2f  %6.2f\n", people[num].surname, people[num].name, people[num].specialty, people[num].cabinet, people[num].timing[day - 1][0], people[num].timing[day - 1][1]);
			found = YES;
		}
	}

	if (found == NO)
	{
		system("cls");
		printf("At %4.2f no %s works.\n", zad_time, zad_specialty);
	}

	system("pause");
}

void read(void)
{
	count();
	people = (doctor*)malloc(cntt * sizeof(doctor));
	FILE* fpin = fopen("C:\\Users\\User\\source\\repos\\file.txt", "rt"); // открыть входной файл для чтения

	if (fpin == NULL)
	{
		printf("error opening file input\n"); // информация об ошибке
		return; // ошибка при открытии файла
	}

	while (!feof(fpin)) // цикл до конца файла
	{
		int i, j, k;
		char line[N];
		char* mas = line;
		char* ptr = fgets(line, N, fpin); // чтение строки

		if (ptr == NULL)
		{
			break; // файл исчерпан
		}

		for (i = 0, j = 0; line[i] != ' '; i++, j++)
		{
			people[number].surname[j] = line[i];
		}
		people[number].surname[j] = '\0';

		for (i++, j = 0; line[i] != ' '; i++, j++)
		{
			people[number].name[j] = line[i];
		}
		people[number].name[j] = '\0';

		for (i++, j = 0; line[i] != ' '; i++, j++)
		{
			people[number].specialty[j] = line[i];
		}
		people[number].specialty[j] = '\0';

		mas = &line[++i];

		people[number].cabinet = atoi(mas);

		for (k = 0; k < 7; k++)
		{
			for (i++; line[i] != ' '; i++)
			{

			}

			mas = &line[++i];

			people[number].timing[k][0] = atof(mas);

			for (i++; line[i] != ' '; i++)
			{

			}

			mas = &line[++i];

			people[number].timing[k][1] = atof(mas);
		}

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
		fprintf(fpout, "%s %s %s %d", people[num].surname, people[num].name, people[num].specialty, people[num].cabinet);

		for (int k = 0; k < 7; k++)
		{
			fprintf(fpout, " %.2f %.2f", people[num].timing[k][0], people[num].timing[k][1]);
		}
		fprintf(fpout, "\n");
	}

	fclose(fpout); // закрыть выходной файл
}

void find_number(void)
{
	found = NO;
	char find_surname[N];
	printf("Enter last name > ");
	scanf("%s", find_surname);

	for (num = 0; num < number && found == NO; num++)
	{
		int i = 0;
		int flag = NO;

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

//void day_finder(void)
//{
//	int a;
//	a++;
//	switch (a)
//	{
//	case 1:
//		day_week[N] = "Monday";
//		break;
//	case 2:
//		day_week[N] = "Tuesday";
//		break;
//	case 3:
//		day_week[N] = "Wednesday";
//		break;
//	case 4:
//		day_week[N] = "Thursday";
//		break;
//	case 5:
//		day_week[N] = "Friday";
//		break;
//	case 6:
//		day_week[N] = "Saturday";
//		break;
//	case 7:
//		day_week[N] = "Sunday";
//		break;
//	default:
//		printf("ERROR. THERE IS NO SUCH DAY\n");
//		system("pause");
//	};
//}

void count(void)
{
	cntt = 0;
	FILE* fpin = fopen("C:\\Users\\User\\source\\repos\\file.txt", "rt"); // открыть входной файл для чтения

	if (fpin == NULL)
	{
		printf("error opening file input\n"); // информация об ошибке
		return; // ошибка при открытии файла
	}

	while (!feof(fpin)) // цикл до конца файла
	{
		char line[N];
		char* ptr = fgets(line, N, fpin); // чтение строки
		int i = 0;

		if (ptr == NULL)
		{
			break; // файл исчерпан
		}

		i = 0;

		while (line[i] != '\n')
		{
			i++;
		}
		cntt++;
	}

	fclose(fpin); // закрыть входной файл
}
