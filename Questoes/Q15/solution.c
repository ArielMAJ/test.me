#include <stdio.h>
#include <stdlib.h>

float * scan_vect(int length);

float pertence(float *vect1, int length1, float *vect2, int length2);

int main(void)
{
	int length1, length2;
	scanf("%d %d", &length1, &length2);

	float *vect1 = scan_vect(length1);
	float *vect2 = scan_vect(length2);
	if (vect1 == NULL || vect2 == NULL) return 1;
	float result = pertence(vect1, length1, vect2, length2);
	printf("%.1f\n", result);

	free(vect1);
	free(vect2);
 
	return 0;
}

float pertence(float *vect1, int length1, float *vect2, int length2)
{
	for (int i = 0; i < length1 - 1; i++) {
		for (int j = i + 1; j < length1; j++) {
			if (vect1[i] == vect1[j])
				vect1[j] = 0;
		}
	}

	for (int i = 0; i < length2 - 1; i++) {
		for (int j = i + 1; j < length2; j++) {
			if (vect2[i] == vect2[j])
				vect2[j] = 0;
		}
	}

	float sum = 0;
	for (int i = 0; i < length1; i++) {
		if (vect1[i] == 0) continue;
		for (int j = 0; j < length2; j++) {
			if (vect2[j] == 0) continue;
			if (vect1[i] == vect2[j]) {
				sum += vect1[i];
				break;
			}
		}
	}

	return sum;
}

float * scan_vect(int length)
{
	if (length < 1) return NULL;
	float *vect = (float *) calloc(length, sizeof(float));

	for (int i = 0; i < length; i++)
		scanf("%f", &vect[i]);

	return vect;
}