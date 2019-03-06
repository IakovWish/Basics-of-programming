#include <stdio.h>
/*определение символических констант*/
#define YES 1
#define NO 0
int main(void)
{
	int c; // текущий символ из потока
	int word; // признак слова
	int cnt; // счётчик
	int vowel_fnd; // индикатор того, что обнаружено слово с гласной буквой
	int flag; // индикатор того, что в слове нет лишних символов
	/*начальные присваивания (инициализация)*/
	cnt = 0;
	word = NO;
	vowel_fnd = NO;
	flag = NO;
	while ((c = getchar()) != EOF) // цикл чтения символов из потока, связанного с клавиатурой
	{
		if (c == ' ' || c == '.' || c == '\n' || c == ',') // если найден разделитель, проверить...
		{
			if (word == YES) // был ли это разделитель после СЛОВА. Если да, проверить...
			{
				if (vowel_fnd == YES) // была ли в слове обнаружена глассная букава, если да, проверить...
				{
					if (flag == NO) // были ли в слове лишние символы, если нет, выполнить...
					{
						cnt = cnt + 1; // прибавить один к счетчику
					}
				}
			}
			word = NO; // поставить индикатор слова на "нет"
			vowel_fnd = NO; // поставить индикатор гласной буквы на "нет"
			flag = NO; // поставить инд лишних символов на "нет"
		}
		else // если разделитель не найден, то проверить...
		{
			if (c == 'e' || c == 'y' || c == 'u' || c == 'i' || c == 'o' || c == 'a' ||
			    c == 'E' || c == 'Y' || c == 'U' || c == 'I' || c == 'O' || c == 'A') // если была найдена гл буква, то выполнить...
			{
				vowel_fnd = YES; // поставить индикатор гл букв на "да"
			}
			else
				if (c <= 'a' && c >= 'z' || c <= 'A' && c >= 'Z') // если гл буква не найдена, проверить на не букву
				{
					flag = YES; // если это не буква, поставить инд на "да"
				}
			word = YES; // поставить инд признака слова на "да"
		}
	}
	printf("number of words = %d\n", cnt); // вывесть значения счетчика
	return 0;
}
