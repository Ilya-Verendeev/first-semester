#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef int dim;
typedef struct matrix
{
	dim line;
	dim column;
}matrix;
typedef enum state
{
	OK,
	WRONG_DIM,
	NEG_DIM
}
state m_init(dim line, dim column);
state m_init(dim line, dim column)
{
	int ** a = (int **)malloc(sizeof(int *) * line);


