#include <stdio.h>

float media(float *vect, int length);

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
		
		printf("%.1f\n", media(vect, lenght[i]));
	}

	return 0;
}


float media(float *vect, int length)
{
	float sum = 0.0;
	
	for (int i = 0; i < length; i++)
	{
		sum += vect[i];
	}
	return sum / length;
}