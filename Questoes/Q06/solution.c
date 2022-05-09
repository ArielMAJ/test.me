#include <stdio.h>

int inteiros(int x);

int main(void)
{
	int n_linhas;
	scanf("%d", &n_linhas);
	
	int n;

	for (int i = 0; i < n_linhas; i++)
	{
		scanf("%d", &n);
		printf("%d\n", inteiros(n));
	}

	return 0;
}


int inteiros(int x)
{
	return (x + 1.0) / 2 * x;
}
