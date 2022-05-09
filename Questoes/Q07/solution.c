#include <stdio.h>
	
unsigned int fib(int k);

int main(void)
{
	int n_linhas;
	scanf("%d", &n_linhas);
	
	int n;

	for (int i = 0; i < n_linhas; i++)
	{
		scanf("%d", &n);
		for (int j = 0; j <= n; j++)
		{
			printf("%u", fib(j));
			if (j != n)
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}

// unsigned int fib(int k)
// {
// 	if (k == 0 || k == 1)
// 		return 1;

// 	unsigned int previous = 0;
// 	unsigned int last = 1;
// 	unsigned int current = 1;
// 	for (int i = 2; i <= k; ++i)
// 	{
// 		previous = last;
// 		last = current;
// 		current = previous + last;
// 	}
// 	return current;
// }

unsigned int fib(int k)
{
	static unsigned int v_fib[47] = {1, 1};

	if (v_fib[k] > 0)
		return v_fib[k];
	if (v_fib[k - 1] == 0)
		v_fib[k - 1] = fib(k - 1);
	if (v_fib[k - 2] == 0)
		v_fib[k - 2] = fib(k - 2);
	
	v_fib[k] = v_fib[k - 1] + v_fib[k - 2];
	return v_fib[k];
}