#include <stdio.h>

float fact(float n);

int main(void)
{
	int n_linhas;
	scanf("%d", &n_linhas);
	
	int n;

	float result;
	for (int i = 0; i < n_linhas; i++)
	{
		scanf("%d", &n);
		result = fact(n);
		printf("%.0f\n", result);
	}

	return 0;
}


 float fact(float n)
{
	for (int i = n - 1; i > 0; i--)
		n *= i;
	return n;
}
