#include <stdio.h>

int multiplos(int y);

int main(void)
{
	int n_linhas;
	scanf("%d", &n_linhas);
	
	int n;

	int result;
	for (int i = 0; i < n_linhas; i++)
	{
		scanf("%d", &n);
		result = multiplos(n);
		printf("%d\n", result);
	}

	return 0;
}


int multiplos(int y)
{
	int sum = 0;
	for (int i = y - 1; i > 0; i--)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}
	return sum;
}
