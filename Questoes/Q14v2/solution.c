#include <stdio.h>
#include <stdlib.h>

float ** create_matrix(int rows, int columns);
void populate_matrix(float **mat, int rows, int columns);
void free_matrix(float **mat, int rows);
void print_matrix(float **mat, int rows, int columns);

float detord2(float **mat);

int main(void)
{
	float ** mat = create_matrix(2, 2);
	if (mat == NULL) return 1;
	populate_matrix(mat, 2, 2);

	float resultado = detord2(mat);
	free_matrix(mat, 2);

	printf("%.1f", resultado);

	return 0;
}


float detord2(float **mat)
{
	float principal = 1.0;
	for (int row = 0; row < 2; row++)
		principal *= mat[row][row];

	float secundaria = 1.0;
	for (int column = 1; column >= 0; column--)
		secundaria *= mat[1 - column][column];

	return principal - secundaria;
}

float ** create_matrix(int rows, int columns) {
	if (rows <= 0 || columns <= 0) return NULL;

	float **mat = (float **) calloc(rows, sizeof(float *));
	if (mat == NULL) return NULL;

	for (int i = 0; i < rows; i++) {
		mat[i] = (float *) calloc(columns, sizeof(float));
		if (mat[i] == NULL) return NULL;
	}

	return mat;
}

void populate_matrix(float **mat, int rows, int columns)
{	
	for (int row = 0; row < rows; row++)
		for (int column = 0; column < columns; column++)
			scanf("%f", &mat[row][column]);
}

void free_matrix(float **mat, int rows)
{
	for (int i = 0; i < rows; i++)
		free(mat[i]);
	free(mat);

	return;
}
void print_matrix(float **mat, int rows, int columns)
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
			printf("%.1f ", mat[row][column]);
		printf("\n");
	}
}
