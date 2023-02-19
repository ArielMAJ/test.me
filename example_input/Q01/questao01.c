#include <stdio.h>

int multiplica(int x, int y);

int main(int argc, char const *argv[])
{
	int n_linhas;
	scanf("%d", &n_linhas);

	for (int i = 0; i < n_linhas; ++i)
	{
		int x, y;
		scanf("%d", &x);
		scanf("%d", &y);

		printf("%d", multiplica(x, y));
	}
	return 0;
}

int multiplica(int x, int y)
{
	int res = 0;
	for (int i = 0; i < y; ++i)
		res += x;
	return res;
}