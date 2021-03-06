#include "pch.h" 
#include <stdlib.h> 
#include <math.h>  
#include <stdio.h> 
#include <locale.h>

int getStringLength(char *a);
void sum(char *a, char *b, char **c, int* length);
void sub(char *a, char *b, char **c, int* length);
void reverse(char *str, int length);
void shiftleft(char *target, int position, int all_numbers);

int main()
{
	setlocale(LC_ALL, "Russian");
	char a[1000];
	char b[1000];
	printf("Введите первое число:\n");
	scanf("%s", a);
	printf("Введите второе число:\n");
	scanf("%s", b);

	char * result = 0;
	int resultLength = 0;

	sum(a, b, &result, &resultLength);
	printf("Сумма введенных чисел: %s\nКоличество символов в сумме: %d\n", result, resultLength);

	printf("\n");

	sub(a, b, &result, &resultLength);
	printf("Разность введенных чисел: %s\nКоличество символов в разности: %d\n", result, resultLength);
	free(result);
	return 0;
}

void sum(char *a, char *b, char **c, int* length)
{
	int length_a; // длина числа а 
	int length_b; //длина числа b 
	int k = 0; // количество сумм разрядов больших 9 при сложении 
	length_a = getStringLength(a);
	length_b = getStringLength(b);
	int length_c; //длина результата +1 на возможное переполнение*/ 
	if (length_a >= length_b)
	{
		length_c = length_a + 1;
	}
	else
	{
		length_c = length_b + 1;
	}
	//выделяем место для результата 
	char *result = (char *)malloc((length_c + 1) * sizeof(char));

	//запуcкаем поразрядное сложение 
	for (int i = 0; i < length_c; i++)
	{
		char element_a = a[length_a - 1 - i];
		char element_b = b[length_b - 1 - i];
		if (i >= length_a)
			element_a = '0';
		if (i >= length_b)
			element_b = '0';
		int int_a = element_a - '0';
		int int_b = element_b - '0';
		int sum = int_a + int_b + k;
		k = 0;
		if (sum > 9)
		{

			sum = sum % 10;
			k++;
		}
		char element_c = sum + '0';
		result[i] = element_c;
	}
	result[length_c] = '\0';
	reverse(result, getStringLength(result));
	for (int i = 0; i < length_c; i++)
	{
		if (result[i] != '0')
		{
			shiftleft(result, i, length_c);
			break;
		}
	}
	//printf(result); 
	//printf(" \n"); 
	*c = result;
	*length = getStringLength(result);
}

void sub(char *a, char *b, char **c, int* length)
{
	int length_a; // длина числа а 
	int length_b; //длина числа b 
	int k = 0; // количество разностей разрядов меньших 0 при вычитании 
	length_a = getStringLength(a);
	length_b = getStringLength(b);
	int length_c; //длина результата +1 на возможное переполнение*/ 
	if (length_a >= length_b)
	{
		length_c = length_a + 1;
	}
	else
	{
		length_c = length_b + 1;
	}

	//выделяем место для результата 
	char* result = (char *)malloc((length_c + 1) * sizeof(char));

	// запускаем поразрядное вычитание 
	for (int i = 0; i < length_c; i++)
	{
		int sub;
		char element_a = a[length_a - 1 - i];
		char element_b = b[length_b - 1 - i];
		if (i >= length_a)
			element_a = '0';
		if (i >= length_b)
			element_b = '0'; 
		int int_a = element_a - '0';
		int int_b = element_b - '0';
		sub = int_a - int_b - k;
		k = 0;
		if (sub < 0)
		{
			sub = (sub + 10) % 10;
			k++;
		}
		char element_c = sub + '0';
		result[i] = element_c;
	}

	result[length_c] = '\0';
	reverse(result, getStringLength(result));
	for (int i = 0; i < length_c; i++)
	{
		if (result[i] != '0')
		{
			shiftleft(result, i, length_c);
			break;
		}
	}
	if (result[0] == '0')
	{
		length_c = getStringLength(result);
		shiftleft(result, length_c - 1, length_c);
	}
	*c = result;
	*length = getStringLength(result);
}
//функция для переворота символьного массива
void reverse(char *str, int length)
{
	int k;
	for (int i = 0; i < length / 2; i++)
	{
		k = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = k;
	}
}
//функция для определения длины массива
int getStringLength(char *a)
{
	int length = 0;
	while (*a != '\0')
	{
		a++;
		length++;
	}
	return length;
}
//функция для обрезания нулей
void shiftleft(char *target, int position, int all_numbers)
{
	for (int i = position; i <= all_numbers; i++)
	{
		target[i - position] = target[i];
	}
}