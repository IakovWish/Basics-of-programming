#pragma warning(disable : 4996)
#include <stdio.h>

#define N 100
#define YES 1
#define NO 0

typedef struct
{
	char name[N];
	char surname[N];
	int cabinet;
	char specialty[N];
} doctor;

doctor people[20];
int number = 0;
int num;
int found = NO;

int menu(void);
void rep(void);
void edit(void);
void del(void);
void alph(void);
void cab(void);
void spec(void);
void time(void);
int find_number(void);

int main(void)
{
	int a;
	while ((a = menu()) != 8)
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
		};
	}
	return 0;
}

int menu()
{
	system("cls");
	int m;
	printf("Select menu item.\n");
	printf("1-Base replenishment.\n");
	printf("2-Base editing.\n");
	printf("3-Delete records.\n");
	printf("4-Display the contents of the database by last name in alphabetical order.\n");
	printf("5-Displays the download of the selected cabinet by day of the week.\n");
	printf("6-Listing doctors in the specified specialty in alphabetical order.\n");
	printf("7-Selection of a doctor by professionand time of appointment.\n");
	printf("8-Exit the program\n");
	scanf("%d", &m);
	return m;
}

void rep(void)
{
	system("cls");
	printf("Enter last name > ");
	scanf("%s", people[number].surname);

	printf("Enter name > ");
	scanf("%s", people[number].name);

	printf("Enter specialty > ");
	scanf("%s", &people[number].specialty);

	number++;
}

void edit(void)
{
	system("cls");
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
	system("pause");
}

void del(void)
{
	system("cls");
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
	system("pause");
}

void alph(void)
{
	system("cls");
	int i, j;
	doctor Temp;

	for (j = number - 1; j > 0; j--)
	{
		for (i = 0; i < j; i++)
		{
			if (strcmp(people[i].surname, people[i + 1].surname) > 0)
			{
				Temp = people[i];
				people[i] = people[i + 1];
				people[i + 1] = Temp;
			}
		}
	}
	
	printf(" N surname name specialty\n");
	for (i = 0; i < number; i++)
	{
		printf("%2i. %-20s %-20s %10s\n", i, people[i].surname, people[i].name, people[i].specialty);
	}
	system("pause");
}

void cab(void)
{

}

void spec(void)
{
	system("cls");
	char zad_specialty[N];
	printf("Enter specialty > ");
	scanf("%s", &zad_specialty);

	found = NO;
	int i;
	int flag;

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
			printf("%2i. %-20s %-20s %10s\n", i, people[num].surname, people[num].name, people[num].specialty);
			found = YES;
		}
	}
	system("pause");
}

void time(void)
{

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
