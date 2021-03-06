#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
typedef struct frac {
	int num;
	int denom;
} frac;
frac frac_create(int num, int denom);
int NOD(int a, int b);
int NOK(int a, int b);
frac frac_sum(frac *f1, frac *f2);
frac frac_sub(frac *f1, frac *f2);
void frac_print(frac *f);
frac frac_create(int num, int denom)
{
	int t;
	if (num*denom < 0)
	{
		t = -1;
	}
	else 
	{ 
		t = 1; 
	}
	num = abs(num);
	denom = abs(denom);
	int temp = NOD(num, denom);
	frac f;
	f.num = t * (num / temp);
	f.denom = (denom / temp);
	return f;
}
int NOK(int a, int b)
{
	int nok = (a * b) / NOD(a, b);
	return nok;
}
int NOD(int a, int b)
{
	while (a && b)
	{
		if (b > a)
		{
			b = b % a;
		}
		else
		{
			a = a % b;
		}
	}
	int nod = b + a;

	return nod;
}
void frac_print(frac *f)
{
	*f = frac_create(f->num, f->denom);
	printf("Дробное значение:\n%d/%d\n", f->num, f->denom);
	printf("Десятичное значение:\n%f\n\n", (float)f->num / (float)f->denom);
}
frac frac_sum(frac *f1, frac *f2)
{
	frac f;
	f.denom = NOK(f1->denom, f2->denom);
	f.num = f1->num * (f.denom/f1->denom) + f2->num * (f.denom/f2->denom);
	return f;
}
frac frac_sub(frac *f1, frac *f2)
{
	frac f;
	f.denom = NOK(f1->denom, f2->denom);
	f.num = f1->num * (f.denom / f1->denom) - f2->num * (f.denom / f2->denom);
	return f;
}
int main()
{
	frac obj1, obj2;
	setlocale(LC_ALL, "Russian");
	int num, denom;
	printf("Введите первое число:\n");
	scanf("%d\n", &num);
	scanf("%d", &denom);
	obj1 = frac_create(num, denom);
	printf("Преобразованная первая дробь:\n%d/%d\n\n", obj1.num, obj1.denom);
	printf("Введите второе число:\n");
	scanf("%d\n", &num);
	scanf("%d", &denom);
	obj2 = frac_create(num, denom);
	printf("Преобразованная вторая дробь:\n%d/%d\n\n", obj2.num, obj2.denom);
	frac_print(&frac_sum(&obj1, &obj2));
	frac_print(&frac_sub(&obj1, &obj2));
	return 0;
}