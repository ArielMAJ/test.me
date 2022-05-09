#include <stdio.h>
#include <stdlib.h>

float ** create_matrix(int rows, int columns);
void populate_matrix(float **mat, int rows, int columns);
void free_matrix(float **mat, int rows);
void print_matrix(float **mat, int rows, int columns);

void transpose(float ***mat, int *rows, int *columns);
float somacoluna(float **mat, int total_rows, int column_to_sum_up);

int main(void)
{
	int rows, columns;
	scanf("%d %d", &rows, &columns);

	float ** mat = create_matrix(rows, columns);
	if (mat == NULL) return 1;

	populate_matrix(mat, rows, columns);

	transpose(&mat, &rows, &columns);
	print_matrix(mat, rows, columns);
	float resultado = somacoluna(mat, rows, 0);
	free_matrix(mat, rows);

	printf("%.1f", resultado);

	return 0;
}


float somacoluna(float **mat, int total_rows, int column_to_sum_up)
{
	float sum = 0;
	
	for (int row = 0; row < total_rows; row++)
	{
		sum += mat[row][column_to_sum_up];
	}
	return sum;
}

// Receives the matrix variable's reference.
void transpose(float ***mat, int *rows, int *columns)
{
	if ((*rows < 2 && *columns < 2) || *rows < 1 || *columns < 1) return;

	{
		// Swapping rows and columns.
		int tmp = *rows;
		*rows = *columns;
		*columns = tmp;
	}

	float **aux_mat = create_matrix(*rows, *columns);
	for (int row = 0; row < *rows; row++)
		for (int column = 0; column < *columns; column++)
			aux_mat[row][column] = (*mat)[column][row];

	free_matrix(*mat, *columns);
	*mat = aux_mat;
	return;
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

void print_matrix(float **mat, int rows, int columns)
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
			printf("%.1f ", mat[row][column]);
		printf("\n");
	}
}
