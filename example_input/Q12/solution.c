#include <stdio.h>
#include <stdlib.h>

float ** create_matrix(int rows, int columns);
void populate_matrix(float **mat, int rows, int columns);
void free_matrix(float **mat, int rows);

float somamatriz(float **mat, int rows, int columns);

int main(void)
{
	int rows, columns;
	scanf("%d %d", &rows, &columns);

	float ** mat = create_matrix(rows, columns);
	if (mat == NULL) return 0;

	populate_matrix(mat, rows, columns);

	float resultado = somamatriz(mat, rows, columns);
	free_matrix(mat, rows);

	printf("%.1f\n", resultado);

	return 0;
}


float somamatriz(float **mat, int rows, int columns)
{
	float sum = 0;
	
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
			sum += mat[row][column];
	}
	return sum;
}


float ** create_matrix(int rows, int columns)
{
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
	if (mat == NULL) return;
	
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

