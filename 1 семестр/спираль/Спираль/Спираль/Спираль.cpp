#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	printf("Vvedite dliny:\n");
	scanf("%d", &n);
	//заполняем часть до сомнительной середины
	for (int i = 0; i < (n-1)/2; i++)
	{
		// вставляем вертикальные палки
		for (int j = 0; j < i; j++)
		{
			printf("%c ", 179);
		}
		//вставляем левые верхние уголки
		printf("%c ", 218);
		//вставляем горизонтальные палки
		for (int j = i + 1; j < n - i - 1; j++)
		{
			printf("%c ", 196);
		}
		//вставляем правые верхние уголки
		printf("%c ", 191);
		//довставляем вертикальные уголки
		for (int j = n - i; j < n; j++)
		{
			printf("%c ", 179);
		}
		printf("\n\n");
	}
	//проверяем на четность
	if (n % 2 == 1)
	{
		//заполняем центральную часть
		for (int i = 0; i < n / 2-1; i++)
		{
			printf("%c ", 179);
		}
		printf("%c ", 192);
		printf("%c ", 196);
		for (int i = n / 2 + 1; i < n; i++)
		{
			printf("%c ", 179);
		}
		printf("\n\n");
		//закончили заполнение центральной строки
		//все что ниже
		for (int i = 0; i < n/2-1; i++)
		{
			for (int j = 0; j < (n - 2 - (2 * i + 2) - (n / 2 - 1 - i)); j++)
			{
				printf("%c ", 179);
			}
			printf("%c ", 192);
			for (int j = 0; j < 2 * i + 2; j++)
			{
				printf("%c ", 196);
			}
			printf("%c ", 217);
			for (int j = 0; j < n / 2 - 1 - i; j++)
			{
				printf("%c ", 179);
			}
			printf("\n\n");
		}

	}
	//для нечетных строк готово
	//для четных строк делаем
	else
	{
		//делаем центр
		for (int i = 0; i < (n - 1) / 2; i++)
		{
			printf("%c ", 179);
		}
		printf("%c ", 196);
		printf("%c ", 191);
		for (int i = 0; i < (n - 1) / 2; i++)
		{
			printf("%c ", 179);
		}
		printf("\n\n");
		//доделали центр
		//доделываем остаток
		for (int i = 0; i < (n-1) / 2; i++)
		{
			for (int j = 0; j < n - (1 + 2 * i) - 2 - ((n - 1) / 2 - i); j++)
			{
				printf("%c ", 179);
			}
			printf("%c ", 192); 
			for (int j = 0; j < 1 + 2 * i; j++)
			{
				printf("%c ", 196);
			}
			printf("%c ", 217);
			for (int j = 0; j < (n - 1) / 2 - i; j++)
			{
				printf("%c ", 179);
			}
			printf("\n\n");
		}

	}
	for (int i = 0; i < n - 1; i++)
	{
		printf("%c ", 196);
	}
	printf("%c ", 217);

}

