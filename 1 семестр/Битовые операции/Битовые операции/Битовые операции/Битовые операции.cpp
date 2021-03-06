#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<malloc.h>
#include <locale.h>
#include <time.h>
typedef struct bit {
	char *c;
	int size;
} bit;
void bit_create(bit*m);
void bit_delete(bit*m);
void bit_print(bit*m);
char bit_search(bit*m);
bit bit_putbit(bit*m);

void bit_create(bit*m) {
	int i;
	m->c = (char*)malloc(m->size * sizeof(char));
	srand(time(NULL));
	for (i = 0; i < m->size; i++) {
		m->c[i] = rand() % 128;
	}
}
void bit_delete(bit* m) {
	free(m->c);
}
//вывод битового массива
void bit_print(bit* m) {
	int n, num, i;
	char vr;
	for (num = 0; num < m->size; num++) {
		for (i = 0; i < 8; i++) {
			vr = 1 << i;
			printf("%d", ((m->c[num])&vr) >> i);
		}
	}
}
char bit_search(bit*m) {
	char vr;
	int n, num, pos;
	printf("\n%s ", "Введите номер бита, который нужно найти:");
	scanf("%d", &num);
	while (num < 0 || num >= 8 * m->size) {
		printf("%s", "Номер находится за пределами, введите новый:");
		scanf("%d", &num);
	}
	n = num / 8;
	pos = num % 8;
	vr = 1 << pos;
	return ((m->c[n]) & vr) >> pos;
}
bit bit_putbit(bit*m) {
	bit m1;
	char vr;
	int pos, num, n, i, bit;
	m1.size = m->size;
	bit_create(&m1);
	printf("%s ", "Введите номер бита, который нужно изменить: ");
	scanf("%d", &num);
	while (num < 0 || num >= 8 * m->size) {
		printf("%s\n", "Номер находится за пределами, введите новый: ");
		scanf("%d", &num);
	}
	printf("%s ", "Введите новое значение для бита: ");
	scanf("%d", &bit);
	while (bit != 0 && bit != 1) {
		printf("%s ", "Введите корректное значение:");
		scanf("%d", &bit);
	}
	n = num / 8;
	pos = num % 8;
	if (bit == 0) {
		vr = 1 << pos;
		vr = ~vr;
		m1.c[n] = m->c[n] & vr;
	}
	if (bit == 1) {
		vr = 1 << pos;
		m1.c[n] = m->c[n] | vr;
	}
	return m1;
}
int main() {
	bit obj;
	setlocale(LC_ALL, "Russian");
	printf("%s", "Введите длину битового массива = ");
	scanf("%d", &obj.size);
	bit_create(&obj);
	bit_print(&obj);
	char k = bit_search(&obj);
	printf("%u\n", k);
	obj = bit_putbit(&obj);
	bit_print(&obj);
	bit_delete(&obj);
	return 0;
}
