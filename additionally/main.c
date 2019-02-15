#include <stdio.h> //необходимо для корректного вызова функций ввода/вывода
/*описание переменных*/
#define LOWER -100 //нижняя граница температур в таблице
#define UPPER 100 //верхняя граница температур в таблице
#define STEP 20 //величина шага
int main(void) //главная функция main не принимает данных от операционной системы, возвращает статус завершения
{ /*начало тела программы*/
	int fahr, cels; //описание целочисленных переменных
	fahr = LOWER; //присваивание переменной "fahr" нижнее значение (-100)
	while (fahr <= UPPER) //введения цикла "пока"
	{ /*начало тела цикла*/
		cels = (int) 5.0/9.0*(fahr - 32); //вычисление целочисленной температуры и помещение ее в переменную cels
		printf("%4d %4d \n", fahr, cels); //вывод на экран значений fahr и cels, в заданной форме
		fahr = fahr + STEP; //присваивание переменной "fahr" новое значение
	} /*конец тела цикла*/
	return 0; //программа возвращается признак корректного завершения
} /*конец тела программы*/
