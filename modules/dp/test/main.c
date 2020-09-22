#include "rudra/dp.h"
#include <stdio.h>

int main() {
	char a[100];

	scanf("%s", a);

	double ** matrix = f2matrix(a, COMMA);

	printf("INFO %ld %ld %ld\n", vec_row(matrix), vec_col(matrix), vec_len(matrix));
	for(unsigned int i = 0; i < vec_row(matrix); i++) {
                for(unsigned int j = 0; j < vec_col(matrix); j++) {
                        printf("%lf ", matrix[i][j]);
                }
                printf("\n");
        }

	FILE * fptr = matrix2f("copy.csv", matrix, vec_row(matrix), vec_col(matrix));

	if(!fptr) {
		printf("ERROR");
	}
	return 0;
}
