#include <stdio.h>

int maior(int *vect, int length);

int main(void)
{
	int lenght;
	scanf("%d", &lenght);
	
	int vect[lenght];

	for (int i = 0; i < lenght; i++)
		scanf("%d", &vect[i]);
	
	int pos = maior(vect, lenght);
	printf("%d %d\n", pos, vect[pos]);

	return 0;
}


int maior(int *vect, int length)
{
	int max = 0;
	
	for (int i = 1; i < length; i++)
	{
		if (vect[max] < vect[i])
			max = i;
	}
	return max;
}
