#include <stdio.h>
#pragma warning(disable : 4996)
#define YES 1
#define NO 0
int main(void)
{
	unsigned long int N;
	long MASK0 = 1;
	long MASK1 = 2147483648;
	long i;
	int j;
	int k;
	int flag;
	int cnt = 0;
	printf("N = ");
	scanf("%d", &N);
	printf("\n");
	if (N >= 0)
		for (j = 8; j > 0; --j)
		{
			for (i = 1; i < 5; ++i)
			{
				printf("%d", (N >> j * 4 - i & 1));
			}
			printf(" ");
		}
	else
		for (j = 8, flag = YES; j > 0; --j)
		{
			for (i = 1; i < 5; ++i)
			{
				if (flag == YES)
				{
					flag = NO;
					printf("1");
				}
				else
				{
					printf("%d", ((~N + 1) >> j * 4 - i & 1));
				}
			}
			printf(" ");
		}
	printf("\n");
	printf("k = ");
	scanf("%d", &k);
	while (cnt != k)
	{
		i = N & MASK0;
		if (i == 1)
		{ 
			N = N >> 1;
			N = N | MASK1;
		}
		else
		{
			N = N >> 1;
		}
		cnt++;

		if (N >= 0)
			for (j = 8; j > 0; --j)
			{
				for (i = 1; i < 5; ++i)
				{
					printf("%d", (N >> j * 4 - i & 1));
				}
				printf(" ");
			}
		else
			for (j = 8, flag = YES; j > 0; --j)
			{
				for (i = 1; i < 5; ++i)
				{
					if (flag == YES)
					{
						flag = NO;
						printf("1");
					}
					else
					{
						printf("%d", ((~N + 1) >> j * 4 - i & 1));
					}
				}
				printf(" ");
			}
		printf("\n");
	}
	printf("result: %d\n", N);
	return 0;
}
