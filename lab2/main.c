#pragma warning(disable : 4996) //���������� ��� ������������� ���������� ������� (scanf)
#include <stdio.h> //���������� ��� ����������� ������ ������� �����/������
int main(void) //������� ������� main �� ��������� ������ �� ������������ �������, ���������� ������ ����������
{ /*������ ���� ���������*/
	float s; //����� ����
	float a; //��������� ������� ����
	float c; //��������� ���������� �������� ����
	float b; //����������� ���������� �������� ����
	int n; //����� ��������� ����
	int i; //����� ���������� �������� ����
	int sign; //���� ���������� �������� ����
	/*���� ���������� ����*/
	printf("n="); //����� ���������: n=
	scanf("%d", &n); //���� � ���������� �������� ���������� n
	/*��������� ������������ ����������*/
	s=0;
	sign=1;
	i = 0;
	c = 3;
	b = 1;
	while (i < n) //�������� ����� "����"
	{ /*������ ���� �����*/
		a = c / b; //���������� ���������� �������� ����
		s = s + a * sign; //����������� ���������� �������� ���� � �����
		sign = -sign; // ����� ����� ���������� �������� ����
		c = c + 1; //���������� ��������� ���������� �������� ����
		b = b + 3; //���������� ����������� ���������� �������� ����
		i = i + 1; //���������� ������ ���������� �������� ����
	} /*����� ���� �����*/
	printf("s= %f\n", s); //����� �� ����� �������� ����� ��������� ����
	return 0; //��������� ������������ ������� ����������� ����������
} /*����� ���� ���������*/