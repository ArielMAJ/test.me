#include <stdio.h>
#include <stdlib.h>

float * scan_vect(int length);
void print_vect(float *vect, int length);

float * somaacumulativa(float *vect1, int lenght);

int main(void)
{
	int n_linhas;
	scanf("%d", &n_linhas);

	int length[n_linhas];
	for (int i = 0; i < n_linhas; i++)
		scanf("%d", &length[i]);

	for (int i = 0; i < n_linhas; i++)
	{
		float *vect1 = scan_vect(length[i]);
		if (vect1 == NULL) return 1;

		float *vect2 = somaacumulativa(vect1, length[i]);
		if (vect2 == NULL) return 1;
		
		print_vect(vect2, length[i]);

		free(vect1);
		free(vect2);
	}
 
	return 0;
}

float * somaacumulativa(float *vect1, int lenght)
{
	float * vect2 = (float *) calloc(lenght, sizeof(float));
	if (vect2 == NULL) return NULL;

	vect2[0] = vect1[0];
	for (int i = 1; i < lenght; i++)
		vect2[i] = vect1[i] + vect2[i - 1];

	return vect2;
}

float * scan_vect(int length)
{
	if (length < 1) return NULL;
	float *vect = (float *) calloc(length, sizeof(float));
	if (vect == NULL) return NULL;

	for (int i = 0; i < length; i++)
		scanf("%f", &vect[i]);

	return vect;
}

void print_vect(float *vect, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%.1f", vect[i]);
		if (i != length - 1)
			printf(" ")
	}
	printf("\n");
}