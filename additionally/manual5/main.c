#pragma warning(disable : 4996) //необходимо для использования устаревших функций (scanf)
#include <stdio.h>
#define N 10
int main(void)
{
	int x[N]; // массив из N элементов
	int aver = 0; // среднее арифметическое
	int i;
	for (i = 0; i < N; i++) // ввод массива
	{
		scanf("%d", &x[i]);
	}
	for (i = 0; i < N; i++)
	{
		aver = aver + x[i];
	}
	aver = aver / N; // вычисление среднего арифметического значения
	for (i = 0; i < N; i++) // выборочное обнуление элементов
	{
		if (x[i] > aver)
			x[i] = 0;
	}
	for (i = 0; i < N; i++) // вывод массива
	{
		printf("%d ", x[i]);
	}
	printf("\n");
	return 0;
}
