#include <rudra/dp.h>
#include <stdio.h>

int main() {
	char a[100];

	scanf("%s", a);

	double ** matrix = f2matrix(a, COMMA);
//	printf("nxt");
	double ** matrix1 = f2matrix(a, COMMA);

	printf("INFO %ld %ld %ld\n", vec_row(matrix), vec_col(matrix), vec_len(matrix));
	for(unsigned int i = 0; i < vec_row(matrix); i++) {
                for(unsigned int j = 0; j < vec_col(matrix); j++) {
                        printf("%lf ", matrix[i][j]);
                }
                printf("\n");
//		free(matrix[i]);
        }
//	free(matrix);
	FILE * fptr = matrix2f("copy.csv", matrix, vec_row(matrix), vec_col(matrix));

	if(!fptr) {
		printf("ERROR");
	}

//	printf("main->matrix|main->matrix1");
//	for(int i = 0; i < vec_row(matrix); i++) {
//		printf("%p : %p\n", matrix[i], matrix1[i]);
//		free(matrix[i]);
//		free(matrix1[i]);
//	}
//	printf("main->matrix | main->matrix1\n%p : %p\n", matrix, matrix1);
//	free(matrix);
//	free(matrix1);
	fclose(fptr);
	return 0;
}
