#pragma warning(disable : 4996)
#include <stdio.h>

#define N 100
#define YES 1
#define NO 0
//#define days 6
//#define hours 23


typedef struct
{
	char name[N];
	char surname[N];
	char specialty[N];
	int cabinet;
} doctor;

doctor people[N];
//int shedule[days][hours];
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
void time(void);
void read(void);
void save(void);
int find_number(void);

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
			time();
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
	printf("7-Selection of a doctor by professionand time of appointment.\n");
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
		scanf("%s", &people[num].specialty);
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

	printf("N   surname              name                 specialty\n");
	for (num = 0; num < number; num++)
	{
		printf("%-3d %-20s %-20s %-10s\n", num, people[num].surname, people[num].name, people[num].specialty);
	}
	system("pause");
}

void cab(void)
{

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

void time(void)
{

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
		int i = 0;
		int j = 0;
		char line[N];
		char* ptr = fgets(line, N, fpin); // чтение строки

		if (ptr == NULL)
		{
			break; // файл исчерпан
		}

		for (j = 0; line[i] != ' '; i++, j++)
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

		number++;
	}

	fclose(fpin); // закрыть входной файл

	save();
	alph();
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
