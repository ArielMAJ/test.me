#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float ** create_matrix(int rows, int columns);
void populate_matrix(float **mat, int rows, int columns);
void free_matrix(float **mat, int rows);
void print_matrix(float **mat, int rows, int columns);

float ** multimat(float **mat1, float **mat2, int rows, int columns);

int main(void)
{
	int n_mats;
	scanf("%d", &n_mats);

	int rows, columns;	
	scanf("%d %d", &rows, &columns);
	float **mat = create_matrix(rows, columns);
	populate_matrix(mat, rows, columns);

	for (int i = 1; i < n_mats; ++i)
	{
		scanf("%d %d", &rows, &columns);
		float **mat_mult = create_matrix(rows, columns);
		if (mat == NULL || mat_mult == NULL) return 1;

		populate_matrix(mat_mult, rows, columns);

		float **mat_aux = multimat(mat, mat_mult, rows, columns);

		free_matrix(mat, rows);
		free_matrix(mat_mult, rows);
		mat = mat_aux;
	}
	print_matrix(mat, rows, columns);
	free_matrix(mat, rows);
	return 0;
}



float ** multimat(float **mat1, float **mat2, int rows, int columns)
{
	float **resulting_mat = create_matrix(rows, columns);
	if (resulting_mat == NULL) return NULL;

	for (int row = 0; row < rows; row++)
		for (int column = 0; column < columns; column++)
			resulting_mat[row][column] = mat1[row][column] * mat2[row][column];

	return resulting_mat;
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
			printf("%.1f ", mat[row][column]) - 0.0000001;
		printf("\n");
	}
}
