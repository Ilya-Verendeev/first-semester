#include"pch.h"
#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#define pi 3.14159265358979323846
/* описываем функцию рандома*/
float random(float min, float max)
{

	float scale = (float)rand() / RAND_MAX;
	float x = min + scale * (max - min);
	return x;
}
/* заканчиваем описывать функцию рандома */
int main(void)
{
	float t, l, h, beta;
	setlocale(LC_ALL, "Rus");
	int n, k_popal = 0;
	printf("Напишите расстояние между линиями:\n");
	scanf("%f", &t);
	printf("Напишите длину иглы:\n");
	scanf("%f", &l);
	printf("Напишите количество испытаний:\n");
	scanf("%d", &n);
	srand(time(NULL));
	/* начинаем рандомить броски */
	for (int i = 0; i < n; ++i)
	{
		h = random(0, t);
		/*printf("%f\t", h);*/
		beta = random(0, pi / 2);
		/*printf("%f\n", beta);*/
		if (h < l * sin(beta))
		{
			k_popal++;
		}
	}
	printf("Количество попавших  иголок %d\n", k_popal);
	printf("Количество попавших  иголок %d\n", n - k_popal);
	printf("отношение количества попаданий к количеству промахов %f\n", (float)k_popal / (float)(n - k_popal));
	printf("оценка числа pi %f", (2 * l * n) / (t * k_popal));
	return 0;
}

