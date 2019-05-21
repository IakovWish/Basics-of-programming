#pragma warning(disable : 4996)
#include <stdio.h> 

int main()
{
	unsigned long res = 0; // результат
	unsigned long mask = 1; // маска
	unsigned long N; // исходное число
	printf("Enter N ");
	scanf("%x", &N);
	while (N != 0)
	{
		res ^= (N & mask); // смотрим последнее число и записываем его в результат
		N = N >> 1; // меняем последнее число, сдвигая N
		res = res << 1; // свобождаем место под следующее число в результате
	}
	res = res >> 1; // если N = 0 значит надо отменить последнее действие
	printf("result: %x", res);
	return 0;
}
