#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>
int power(int a);
int map(int *a, int *f);
int chet(int a);
int sum(int a, int b);
int  * reduce(int *a, int akk, int(*f)(int));
int filter(int **b, int * a, int length, int(*f)(int));
int fmax(int a, int b)
{
	if (b >= a)
	{
		a = b;
	}
	return a;
}
int chet(int a)
{
	if (a % 2 == 0)
	{
		return 1;
	}
	else 
	{ 
		return 0; 
	}
}
int power(int a)
{
	return a * a * a;
}
//функция filter
int filter(int **result, int * a, int length, int(*f)(int))
{
	int * vr;
	int k = 0;
	vr = (int *)malloc(sizeof(int)*length);
	for (int i = 0; i < length; i++)
	{
		if (f(a[i]) == 1)
		{
			vr[k] = a[i];
			k++;
		}
	}	

	vr = (int *)realloc(vr, sizeof(int)*k);
	*result = vr;
		return k;
		free(vr);
}
//конец функции filter
//функция map
void map(int ** result, int *a, int length, int (*f)(int))
{
	int * vr;
	vr = (int *)malloc(sizeof(int)*length);
	for (int i = 0; i < length; i++)
	{
		vr[i] = f(a[i]);
	}
	*result = vr;
}
//конец функции map
//начало функции reduce
int reduce(int *a, int length, int akk, int(*f)(int, int))
{
	for (int i = 0; i < length; i++)
	{
		akk = f(akk, a[i]);
	}
	return akk;
}
//конец функции reduce
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	//реализуем map
	int length_a = 10;
	int a[10];
	for (int i = 0; i < length_a; i++)
	{
		a[i] = rand() % 20;
	}
	printf("Получившийся массив, после рандома:\n");
	for (int i = 0; i < length_a; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	int * result = 0;
	map(&result, a, length_a, power);
	printf("Получившийся массив, после применения map:\n");
	for (int i = 0; i < length_a; i++)
	{
		printf("%d ", result[i]);
	}	
	printf("\n\n");
	int max = 0;
	max = reduce(result, length_a, max, fmax);
	printf("Максимальный элемент, выведенный при помощи reduce:\n%d", max);
	printf("\n");
	/*кончаем реализацию map
	printf("\n\n");
	result = 0;
	//начинаем реализацию filter
	int k = filter(&result, a, length_a, chet);
	printf("Размер получившегося массива:\n");
	printf("%d\n", k);
	printf("Получившийся массив, после применения filter:\n");
	for (int i = 0; i < k; i++)
	{
		printf("%d ", result[i]);
	}
	//кончаем реализацию filter
	printf("\n\n");
	*/
	free(result);
	return 0;
}


