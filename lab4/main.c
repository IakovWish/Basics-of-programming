#pragma warning(disable : 4996) //���������� ��� ������������� ���������� ������� (scanf)
#include <stdio.h>
// ����������� ������������� ��������
#define YES 1
#define NO 0
#define MAXLINE 1000
void process_line(char buffer[]);
int main(void)
{
	char line[MAXLINE];
	gets(line);
	process_line(line);
	puts(line);
	return 0;
}
void process_line(char buffer[])
{
	char c; // ������� ������
	int flag; // ������� �����
	int found; // ��������� ����, ��� ������� ������� � ����� ���������
	int i; // ������� �������� ������� �������� c�����
	int pos; // ������� �������� ������� �������������� ������
	int start; // ������� ������ �����
	int n; // ���������� ����� ����� � �����
	int j;
	int symb;
	int N; // ���������� ���������� ���� � ������
	printf("N=");
	scanf("%d", &N); // ���� N � ����������
	// ��������� ������������ (�������������)
	flag = NO;
	found = NO;
	symb = NO;
	start = 0;
	i = 0;
	pos = 0;
	do // ���� ������ �������� �� ������
	{
		c = buffer[i]; // ����� ������� ������ �� ������
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') // ������ �����������
		{
			if (symb == NO) // ���� �� � ����� ������ �������, ���� ���, ���������...
			{
				if (flag == YES) // ��� ������ ��������� ����� �����
				{
					if (found == NO) // ���������, ��������� �� � ����� ������� �������
					{
						for (j = start; j < i; j++) // ����� �� �������� �������� ��� ���������� � �������������� ������
						{
							buffer[pos++] = buffer[j];
						}
					}
				}
			}
			flag = NO;
			n = 0;
			symb = NO;
			found = NO;
			buffer[pos++] = c;
		}
		else
		{
			if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) // ��������� ��� �� � ����� ������ ��������
			{
				symb = YES; // ���� � ����� ���� ������ ������, ��������� ��� �� "��"
			}
			if (flag == NO) // ������� �����
			{
				start = i; // ��������� ������� ������ �����
			}
			if (n >= N) // �������� ���������� �������� � ����������� ��������
			{
				found = YES; // (����������� �������� �������� � �����)
			}
			flag = YES;
			++n;
		}
		i++;
	} while (c != '\0');
}