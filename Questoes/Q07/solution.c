#include <stdio.h>
	
unsigned int fib(int k);

unsigned int v_fib[47] = {1, 1};

int main(void)
{
	int n_linhas;
	scanf("%d", &n_linhas);
	
	int n;

	for (int i = 0; i < n_linhas; i++)
	{
		scanf("%d", &n);
		for (int j = 0; j <= n; j++)
			printf("%u ", fib(j));
		printf("\n");
	}

	return 0;
}

unsigned int fib(int k)
{
	

	if (v_fib[k] > 0)
		return v_fib[k];
	if (v_fib[k - 1] == 0)
		v_fib[k - 1] = fib(k - 1);
	if (v_fib[k - 2] == 0)
		v_fib[k - 2] = fib(k - 2);
	
	v_fib[k] = v_fib[k - 1] + v_fib[k - 2];
	return v_fib[k];
}