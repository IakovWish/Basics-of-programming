#include <stdio.h>
/* ����������� ������������� ��������*/
#define YES 1
#define NO 0
int main(void)
{
	int c; // ������� ������ �� ������
	int flag; // ������� �����
	int cnt; // �������
	int found; // ��������� ����, ��� ������� ������� ���������
	/*��������� ������������ (�������������)*/
	cnt = 0;
	flag = NO;
	found = NO;
	while ((c = getchar()) != EOF) // ���� ������ �������� �� ������, ���������� � �����������
	{
		if (c == ' ' || c == '.' || c == '\n' || c == ',') // �������� ����������� �� �����
		{
			if (flag == YES) // ���� ������� ����� ��� ���, ������ ������ ��� �����
			{
				if (found == YES) // ��� ������ ����������� ����� ����� � ������� ���� �������
				{
					cnt = cnt + 1; // ��������� ���� � ��������
				}
			}
			flag = NO; // ����� �����������
			found = NO; // ����� � ������� ������ �� �������
		}
		else // ���� ����� ��� �� ���������
		{
			if (c == 'e' || c == 'y' || c == 'u' || c == 'i' || c =='o' || c == 'a' ||
			    c == 'E' || c == 'Y' || c == 'U' || c == 'I' || c == 'O' || c == 'A') // �������� �� ������� �����
			{
				found = YES; // ������� �������� �����
			}
			flag = YES; // ������� ����� �����������
		}
	}
	printf("number of words = %d\n", cnt);
	return 0;
}