#include <stdio.h>

int potencia_loop(int x, int p);

int main(void)
{
	int n_linhas;
	scanf("%d", &n_linhas);
	int x, y;
	scanf("%d", &x);
	scanf("%d", &y);

	int resultado = potencia_loop(x, y);
	printf("%d\n", resultado);
	return 0;
}

int potencia_loop(int x, int p)
{
	if (p < 0)
		return 1.0 / potencia_loop(x, - p);

	int resultado = 1;

	for (int i = 0; i < p; i++)
		resultado *= x;

	return resultado;
}
