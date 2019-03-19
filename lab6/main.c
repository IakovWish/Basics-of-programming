#pragma warning(disable : 4996) //���������� ��� ������������� ���������� ������� (scanf)
#include <stdio.h>
// ����������� ������������� ��������
#define YES 1
#define NO 0
#define MAXLINE 1000
void process_line(char buffer[]); // ��������� �������
int main(void)
{
	char line[MAXLINE];
	printf("Please, enter some words\nWARNING: words which consist of more than N letters will be deleted\n");
	gets(line);
	process_line(line);
	printf("Result:\n");
	puts(line);
	return 0;
}
void process_line(char buffer[])
{
	char c; // ������� ������
	int word = NO; // ������� �����
	int overkill = NO; // ��� �������� ���� � �����
	int symb = NO; // ��������� ������� ������ ��������
	int ish = 0; // ������� �������� ������� �������� c�����
	int res = 0; // ������� �������� ������� �������������� ������
	int start = 0; // ������� ������ �����
	int n = 0; // ������� ���� � �����
	int j;
	int N; // ���������� ���������� ���� � ������
	printf("Enter N="); // ����� ���������
	scanf("%d", &N); // ���� N � ����������
	do
	{
		c = buffer[ish]; // ����� ������� ������ �� ������
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') // ������ �����������
		{
			if (symb == NO && word == YES && overkill == NO) // ���� ����� ��� ���-� ��������, �� �������� ��-� N, ���������...
			{
				for (j = start; j < ish; j++) // ����� �� �������� �������� ��� ���������� � �������������� ������
				{
					buffer[res] = buffer[j]; // ����������� �����
					res++;
				}
				buffer[res] = c;
				res++;
			}
			word = NO;
			symb = NO;
			overkill = NO;
			n = 0;
		}
		else
		{
			n++;
			if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) // ��������� ��� �� � ����� ������ ��������
			{
				symb = YES; // � ����� ���� ������ ������
			}
			if (word == NO) // ������� ������ ����� �����
			{
				start = ish; // ��������� ������� ������ �����
			}
			if (n > N) // �������� �� ������� ����
			{
				overkill = YES; // �������
			}
			word = YES;
		}
		ish++;
	}
	while (c != '\0'); // ���������� �� ����� ������
	buffer[res++] = '\0';// ������������� ����� �����
}