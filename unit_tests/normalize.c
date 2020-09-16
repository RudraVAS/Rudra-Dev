#include "rudra_normalization.h"
#include <stdio.h>
#include <stdlib.h>

double ** m2p(int r, int c, double arr[r][c]) {
	double **ret = malloc(r * sizeof(double *));
	for(int i = 0; i<r; i++)
		ret[i] = malloc(sizeof(double) * c);

	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			ret[i][j] = arr[i][j];

	return ret;
}

int main() {
	printf("%ld", sizeof(enum n_types));
	int a;
	scanf("%d", &a);
	double arr[5][4] = {
		{10, 10, 12, 11},
		{10, 550, 60, 80},
		{20, 80, 90, 65},
		{70, 550, 60, 80},
		{60, 80, 90, 65}};

	double ** ptr = m2p(5, 4, arr);

	normalization(ptr, 5, 4, 10, a);

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 4; j++)
			printf("%lf ", ptr[i][j]);

		printf("\n");
	}
	return 0;
}

