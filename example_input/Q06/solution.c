#include <stdio.h>

int inteiros(int x);

int main(void)
{
	int n_linhas;
	scanf("%d", &n_linhas);
	
	int n;

	int result;
	for (int i = 0; i < n_linhas; i++)
	{
		scanf("%d", &n);
		result = inteiros(n);
		printf("%d\n", result);
	}

	return 0;
}


int inteiros(int x)
{
	return (x + 1.0) / 2 * x;
}
