#include <stdio.h>

int divide(int a, int b);

int main(int argc, char const *argv[])
{
	int n_linhas;
	int num, den;

	scanf("%d", &n_linhas);

	scanf("%d", &num);
	scanf("%d", &den);

	printf("%d\n", divide(num, den));
	
	return 0;
}

int divide(int a, int b)
{
	int resultado = 0;

	while (a > 0)
	{
		a -= b;
		resultado++;
	}
	if (a < 0)
		resultado--;

	return resultado;
}