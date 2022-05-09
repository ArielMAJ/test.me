#include <stdio.h>

float fact(float n);

int main(void)
{
	int n_linhas;
	scanf("%d", &n_linhas);
	
	int n;

	for (int i = 0; i < n_linhas; i++)
	{
		scanf("%d", &n);
		printf("%.0f\n", fact(n));
	}

	return 0;
}


 float fact(float n)
{
	for (int i = n - 1; i > 0; i--)
		n *= i;
	return n;
}
