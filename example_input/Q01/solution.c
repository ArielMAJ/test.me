#include <stdio.h>

int multiplica(int a, int b);

int main(void)
{
	int n_linhas;
	scanf("%d", &n_linhas);

	int n1 = 2, n2 = 3;

	scanf("%d", &n1);
	scanf("%d", &n2);

	printf("%d\n", multiplica(n1, n2));
	return 0;
}

int multiplica(int a, int b)
{
	int resultado = 0;
	for(int i = 0; i < b; i++)
	{
		resultado += a;
	}
	return resultado;
}

