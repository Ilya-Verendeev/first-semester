#include "pch.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
float dir_ave(int m, float b[])
{
	float res, s = 0;
	for (int j = 0; j < m; j++)
	{
		s += b[j];
	}
	res = s / m;
	return res;
}
int main(void)
{
	float x_sr, y_sr, b1 = 0, b2 = 0, b, a, res1 = 0, res2 = 0;
	//считываем с файла значения
	FILE * file;
	file = fopen("C:\\Users\\I\\Desktop\\рабочая\\считывание с файла\\считывание с файла\\input.dat", "r");
	if (file == NULL) {
		exit(1);
	}

	int n;
	fscanf(file, "%d", &n);
	printf("%d\n", n);
	float arr_x[20];
	float arr_y[20];
	for (int i = 0; i < n; i++)
	{
		fscanf(file, "%f %f", &arr_x[i], &arr_y[i]);
		printf("%f %f\n", arr_x[i], arr_y[i]);
	}
	fclose(file);
	//считали
	//начинаем находить среднее через функции
	x_sr = dir_ave(n, arr_x);
	y_sr = dir_ave(n, arr_y);
	//нашли, переходим к определению коэффициентов
	for (int i = 0; i < n; i++) {
		if ((arr_x[i] - x_sr)*(arr_y[i] - y_sr) > 0)
		{
			b1 = b1 + (arr_x[i] - x_sr)*(arr_y[i] - y_sr);
		}
		else 
		{
			b1 = b1 - (arr_x[i] - x_sr)*(arr_y[i] - y_sr); 
		}
		b2 = b2 + (arr_x[i] - x_sr) * (arr_x[i] - x_sr);
	}
	b = b1 / b2;
	a = y_sr - b * x_sr;
	printf("%f %f", a, b);
	return 0;
}

