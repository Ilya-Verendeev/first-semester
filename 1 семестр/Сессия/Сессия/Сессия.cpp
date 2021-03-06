#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <malloc.h>
#include <string.h>
//функция факториала
int factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	int vr = 1;
	for (int i = 1; i <= n; i++)
	{
		vr = vr * i;
	}
	return vr;
}
//окончание функции факториала
//функция умножения квадратной матрицы
double** mult(double** a, double** b, int n)
{
	double **vr;
	vr = (double **)malloc(sizeof(double *) * n);
	for (int i = 0; i < n; i++)
	{
		vr[i] = (double *)malloc(sizeof(double) * n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			vr[i][j] = 0;
			for (int k = 0; k < n; k++)
				vr[i][j] += a[i][k] * b[k][j];
		}
	}
	return vr;
}
//окончание функции умножения квадратной матрицы
//функция сложения квадратной матрицы
double** sum(double** a, double** b, int n)
{
	double **vr;
	vr = (double **)malloc(sizeof(double *) * n);
	for (int i = 0; i < n; i++)
	{
		vr[i] = (double *)malloc(sizeof(double) * n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			vr[i][j] = a[i][j] + b[i][j];
		}
	}
	return vr;
}
//окончание функции сложения квадратной матрицы
//функция возведения в степень квадратной матрицы
double** expon(double** a, int n, int step)
{
	double **vr;
	vr = (double **)malloc(sizeof(double *) * n);
	for (int i = 0; i < n; i++)
	{
		vr[i] = (double *)malloc(sizeof(double) * n);
	}
	if (step == 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					vr[i][i] = 1;
				}
				else 
				{
					vr[i][j] = 0;
				}
			}
		}
	}
	if (step > 0)
	{
		vr = mult(expon(a, n, step - 1), a, n);
	}
	return vr;
}
//окончание функции возведения в степень
//создания элемента для суммы экспоненты
double** element(double **a, int n, int temp)
{
	double **vr;
	vr = (double **)malloc(sizeof(double *) * n);
	for (int i = 0; i < n; i++)
	{
		vr[i] = (double *)malloc(sizeof(double) * n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			vr[i][j] = expon(a, n, temp)[i][j] / factorial(temp);
		}
	}
	return vr;
}
//окончание функции для подсчету элемента
double modul(double a)
{
	if (a >= 0)
	{
		return a;
	}
	else
	{
		return (-a);
	}
}
//поиск нормы матрицы
double norma(double** a, int n)
{
	double* vr;
	vr = (double*)malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++)
	{
		vr[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			vr[i] = vr[i] + modul(a[i][j]);
		}
	}
	double max = vr[0];
	for (int i = 1; i < n; i++)
	{
		if (vr[i] > max)
		{
			max = vr[i];
		}
	}
	return max;
}
//окончание функции поиска нормы

//функция по созданию ряда
void check(double** a, int n, double q, double***vr)
{
	double **summa;
	summa = (double **)malloc(sizeof(double *) * n);
	for (int i = 0; i < n; i++)
	{
		summa[i] = (double *)malloc(sizeof(double) * n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				summa[i][j] = 1;
			}
			else
			{
				summa[i][j] = 0;
			}
		}
	}
	summa = sum(summa, a, n);
	int nomer = 1;
	while ((norma(element(a, n, nomer), n) / norma(summa, n)) >= q)
	{
		nomer++;
		summa = sum(summa, element(a, n, nomer), n);
	
	}
	*vr = summa;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 3;
	//создание двумерного динмического массива размерности n = 3
	double **a;
	a = (double **)malloc(sizeof(double*) * n);
	for (int i = 0; i < n; i++)
	{
		a[i] = (double *)malloc(sizeof(double)*n);
	}
	//завершение создания двумерного динамического массива размерности n = 3
	srand(time(NULL));
	//заполнение матрицы рандомными числами
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = 0;
			}
		}
	}
	//заполнили матрицу рандомными числами
	printf("Данная матрица\n");
	//вывод данной матрицы
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%f ", a[i][j]);
		}
		printf("\n");
	}
	//окончание вывода данной матрицы
	//проверка по введенному числу
	float ch;
	printf("Введите число ch:\n");
	scanf("%f", &ch);
	double **summa;
	summa = (double **)malloc(sizeof(double*) * n);
	for (int i = 0; i < n; i++)
	{
		summa[i] = (double *)malloc(sizeof(double)*n);
	}
	check(a, n, ch, &summa);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%f ", summa[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++)
	{
		free(summa[i]);
	}
	free(summa);
}
