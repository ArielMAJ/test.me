#include <stdio.h>

int menor(float *vect, int length);

int main(void)
{
	int n_linhas;
	scanf("%d", &n_linhas);
	int lenght[n_linhas];
	for (int i = 0; i < n_linhas; ++i)
		scanf("%d", &lenght[i]);
	

	for (int i = 0; i < n_linhas; ++i)
	{
		float vect[lenght[i]];

		for (int j = 0; j < lenght[i]; j++)
			scanf("%f", &vect[j]);
		
		int pos = menor(vect, lenght[i]);
		printf("%d %.1f\n", pos, vect[pos]);
	}

	return 0;
}


int menor(float *vect, int length)
{
	int min = 0;
	
	for (int i = 1; i < length; i++)
	{
		if (vect[min] > vect[i])
			min = i;
	}
	return min;
}