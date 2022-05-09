#include <stdio.h>
#include <stdlib.h>

float ** create_matrix(int rows, int columns);
void populate_matrix(float **mat, int rows, int columns);
void free_matrix(float **mat, int rows);
void print_matrix(float **mat, int rows, int columns);

float ** prodesc(float **mat1, int rows1, int columns1, float **mat2, int rows2, int columns2, int *rows_output, int *columns_output);

int main(void)
{
	int n_mats;
	scanf("%d", &n_mats);

	int mat_rows, mat_columns;	
	scanf("%d %d", &mat_rows, &mat_columns);
	float **mat = create_matrix(mat_rows, mat_columns);
	populate_matrix(mat, mat_rows, mat_columns);

	for (int i = 1; i < n_mats; ++i)
	{
		int mat_mult_rows, mat_mult_columns;
		scanf("%d %d", &mat_mult_rows, &mat_mult_columns);
		float **mat_mult = create_matrix(mat_mult_rows, mat_mult_columns);
		if (mat == NULL || mat_mult == NULL) return 1;

		populate_matrix(mat_mult, mat_mult_rows, mat_mult_columns);

		float **mat_aux = prodesc(mat, mat_rows, mat_columns, mat_mult, mat_mult_rows, mat_mult_columns, &mat_rows, &mat_columns);
		
		free_matrix(mat, mat_rows);
		free_matrix(mat_mult, mat_mult_rows);
		mat = mat_aux;
	}
	print_matrix(mat, mat_rows, mat_columns);
	free_matrix(mat, mat_rows);
	return 0;
}


float ** prodesc(float **mat1, int rows1, int columns1, float **mat2, int rows2, int columns2, int *rows_output, int *columns_output)
{
	if (columns1 != rows2)
	{
		printf("Matrix dimensions aren't matching.");
		return NULL;
	}
	*rows_output = rows1;
	*columns_output = columns2;

	float **resulting_mat = create_matrix(*rows_output, *columns_output);

	for (int row = 0; row < *rows_output; row++)
	{
		for (int column = 0; column < *columns_output; column++)
		{
			for (int position = 0; position < columns1; position++)
				resulting_mat[row][column] += mat1[row][position] * mat2[position][column];
		}		
	}
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
		{
			printf("%.1f", mat[row][column]);
			if (column != columns - 1)
				printf(" ");
		}
		printf("\n");
	}
}