#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <stddef.h> 
//структура дробного числа
typedef enum status
{
	ERROR,
	OK 
}status;
typedef struct frac {
	int num;
	int denom;
} frac;
//структура комплексного числа
typedef struct complex {
	frac real;
	frac imag;
} complex;
frac frac_create(int num, int denom);
int NOD(int a, int b);
int NOK(int a, int b);
frac frac_sum(frac *f1, frac *f2);
frac frac_sub(frac *f1, frac *f2);
frac frac_mult(frac *f1, frac *f2);
frac frac_div(frac *f1, frac *f2);
complex sum(complex *c1, complex *c2);
complex sub(complex *c1, complex *c2);
complex mult(complex *c1, complex *c2);
status check(complex *c2);
status check(complex *c2)
{
	if ((c2->real.num == 0) && (c2->imag.num == 0))
	{
		return ERROR;
	}
	else {
		return OK;
	}

	return (c2->real.num == 0) && (c2->imag.num == 0)
		? ERROR
		: OK;
}
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
//функция НОК
int NOK(int a, int b)
{
	int nok = (a * b) / NOD(a, b);
	return nok;
}
//функция НОД
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
frac frac_sum(frac *f1, frac *f2)
{
	frac f;
	*f1 = frac_create(f1->num, f1->denom);
	*f2 = frac_create(f2->num, f2->denom);
	f.denom = NOK(f1->denom, f2->denom);
	f.num = f1->num * (f.denom / f1->denom) + f2->num * (f.denom / f2->denom);
	f = frac_create(f.num, f.denom);
	return f;
}
frac frac_sub(frac *f1, frac *f2)
{
	frac f;
	*f1 = frac_create(f1->num, f1->denom);
	*f2 = frac_create(f2->num, f2->denom);
	f.denom = NOK(f1->denom, f2->denom);
	f.num = f1->num * (f.denom / f1->denom) - f2->num * (f.denom / f2->denom);
	f = frac_create(f.num, f.denom);
	return f;
}
frac frac_mult(frac *f1, frac *f2)
{
	frac f;
	*f1 = frac_create(f1->num, f1->denom);
	*f2 = frac_create(f2->num, f2->denom);
	f.denom = f1->denom * f2->denom;
	f.num = f1->num * f2->num;
	f = frac_create(f.num, f.denom);
	return f;
}
frac frac_div(frac *f1, frac *f2)
{
	frac f;

	*f1 = frac_create(f1->num, f1->denom);
	*f2 = frac_create(f2->num, f2->denom);

	f.denom = (f1->denom * f2->num);
	f.num = (f1->num * f2->denom);
	f = frac_create(f.num, f.denom);
	return f;
}
complex sum(complex *c1, complex *c2)
{
	complex c;
	c.real = frac_sum(&c1->real, &c2->real);
	c.imag = frac_sum(&c1->imag, &c2->imag);
	return c;
}
complex sub(complex *c1, complex *c2)
{
	complex c;
	c.real = frac_sub(&c1->real, &c2->real);
	c.imag = frac_sub(&c1->imag, &c2->imag);
	return c;
}
complex mult(complex *c1, complex *c2)
{
	complex c;
	c.real = frac_sub(&frac_mult(&c1->real, &c2->real), &frac_mult(&c1->imag, &c2->imag));
	c.imag = frac_sum(&frac_mult(&c1->real, &c2->imag), &frac_mult(&c1->imag, &c2->real));
	return c;
}
complex div(complex *c1, complex *c2)
{
	frac chisl, znam, proizv1, proizv2;
	complex c;
	//расписываем действительную часть частного
	proizv1 = frac_mult(&c1->real, &c2->real);
	proizv2 = frac_mult(&c1->imag, &c2->imag);
	chisl = frac_sum(&proizv1, &proizv2);
	proizv1 = frac_mult(&c2->real, &c2->real);
	proizv2 = frac_mult(&c2->imag, &c2->imag);
	znam = frac_sum(&proizv1, &proizv2);
	c.real = frac_div(&chisl, &znam);
	//расписываем мнимую часть частного
	proizv1 = frac_mult(&c1->imag, &c2->real);
	proizv2 = frac_mult(&c1->real, &c2->imag);
	chisl = frac_sub(&proizv1, &proizv2);
	proizv1 = frac_mult(&c2->real, &c2->real);
	proizv2 = frac_mult(&c2->imag, &c2->imag);
	znam = frac_sum(&proizv1, &proizv2);
	c.imag = frac_div(&chisl, &znam);
	return c;
}
int main(void)
{
	complex c, c1, c2;
	setlocale(LC_ALL, "Russian");
	printf("Введите действительную часть первого числа:\n");
	scanf("%d\n%d", &c1.real.num, &c1.real.denom);
	printf("Введите мнимую часть первого числа:\n");
	scanf("%d\n%d", &c1.imag.num, &c1.imag.denom);
	printf("Введите действительную часть второго числа:\n");
	scanf("%d\n%d", &c2.real.num, &c2.real.denom);
	printf("Введите мнимую часть второго числа:\n");
	scanf("%d\n%d", &c2.imag.num, &c2.imag.denom);
	c = sum(&c1, &c2);
	printf("Сумма двух комплексных чисел:\n");
	printf("(%d/%d) + (%d/%d)i\n", c.real.num, c.real.denom, c.imag.num, c.imag.denom);
	c = sub(&c1, &c2);
	printf("Разность двух комплексных чисел:\n");
	printf("(%d/%d) + (%d/%d)i\n", c.real.num, c.real.denom, c.imag.num, c.imag.denom);
	c = mult(&c1, &c2);
	printf("Произведение двух комплексных чисел:\n");
	printf("(%d/%d) + (%d/%d)i\n", c.real.num, c.real.denom, c.imag.num, c.imag.denom);
	if (check(&c2) == OK)
	{
		c = div(&c1, &c2);
		printf("Статус:\n%d\n", OK);
		printf("Частное двух комплексных чисел:\n");
		printf("(%d/%d) + (%d/%d)i\n", c.real.num, c.real.denom, c.imag.num, c.imag.denom);
	}
	else
		printf("Статус:\n%d", ERROR);
	return 0;
}