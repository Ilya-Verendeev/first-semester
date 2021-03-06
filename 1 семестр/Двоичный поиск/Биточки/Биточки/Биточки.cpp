#include "pch.h" 
#include <iostream> 
#include <time.h> 
#include <locale.h>
int compare(const void*a, const void*b)
{
	return(*(int*)a - *(int*)b);
}
int main()
{
	int *a;
	int n;
	setlocale(LC_ALL, "Russian");
	printf("Введите размер массива: ");
	scanf("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	srand(time(NULL));
	printf("Сгенерированный массив\n");
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
		printf("%d ", a[i]);
	}
	printf("\n");
	qsort(a, n, sizeof(int), compare);
	printf("Отсортированный массив:\n");
	for(int i = 0; i < n ; i++)
	{
	printf("%d ",a[i]);
	}
	printf("\n");
	//конец генерации и сортировки массива
	int search;
	printf("Введите искомый элемент: \n");
	scanf("%d", &search);
	//искомый элемент
	int left, right, middle;
	left = 0;
	right = n - 1;
	int answer = -1;
	while (left <= right)
	{
		middle = (right + left) / 2;
		if (a[middle] == search)
		{
			answer = middle;
			break;
		}
		if (search < a[middle])
		{
			right = middle-1;
		}
		else
		{
			left = middle+1;
		}
	}
	printf("%d", answer);
	free(a);
	return 0;
}
