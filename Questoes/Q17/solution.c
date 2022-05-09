#include <stdio.h>
#include <stdlib.h>

float ** create_matrix(int rows, int columns);
void populate_matrix(float **mat, int rows, int columns);
void free_matrix(float **mat, int rows);

float mediamat(float **mat, int rows, int columns);

int main(void)
{
	int n_mats;
	scanf("%d", &n_mats);

	int rows, columns;	
	for (int i = 0; i < n_mats; ++i)
	{
		scanf("%d %d", &rows, &columns);
		float **mat = create_matrix(rows, columns);
		populate_matrix(mat, rows, columns);

		printf("%.2f\n", mediamat(mat, rows, columns));

		free_matrix(mat, rows);
	}

	return 0;
}


float mediamat(float **mat, int rows, int columns)
{
	float sum = 0.0;
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; ++j)
		{
			sum += mat[i][j];
			
		}
	}
	return sum / (rows * columns);
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
