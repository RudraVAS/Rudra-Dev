#include "rudra/ann/matrix_operations.h"
#include <stdlib.h>
#include <assert.h>

/**
 * m2p: converts a static matrix to dynamic.
 *
 * @r: no. of rows of the static matrix.
 * @c: no. of cols of the static matrix.
 * @arr: static matrix
 *
 * return: dynamic matrix
 */
double **m2p(int r, int c, double arr[r][c])
{
	double **ret = malloc(r * sizeof(double *));
	for (int i = 0; i < r; i++)
		ret[i] = malloc(sizeof(double) * c);

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			ret[i][j] = arr[i][j];

	return ret;
}

/**
 * matmul: Finds the dot product of two vectors using unrolled loops for
 *		unit strides.
 *
 * @arr1: 2-d matrix 1
 * @arr2: 2-d matrix 2
 * @r1: no. of rows for vector1
 * @c1: no. of cols for vector1
 * @r2: no. of rows for vector2
 * @c2: no. of rows for vector2
 *
 * return: dot product for the two.
 */
double **matmul(double **arr1, unsigned long r1, unsigned long c1,
		double **arr2, unsigned long r2, unsigned long c2)
{
	assert(c1 == r2);

	unsigned long i, j;
	double **ret;

	ret = malloc(sizeof(double *) * r1);

	for (i = 0; i < r1; i++) {
		ret[i] = malloc(sizeof(double) * c2);
	}

	for (i = 0; i < r1; i++) {
		for (j = 0; j < c2; j++) {
			int k = 0, m = 0;
			double stemp = 0.0;

			m = c1 % 5;

			if (m) {
				for (k = 0; k < m; k++) {
					stemp += arr1[i][k] * arr2[k][j];
				}
			}

			for (; k < c1; k += 5) {
				stemp += arr1[i][k] * arr2[k][j] +
				    arr1[i][k + 1] * arr2[k + 1][j] +
				    arr1[i][k + 2] * arr2[k + 2][j] +
				    arr1[i][k + 3] * arr2[k + 3][j] +
				    arr1[i][k + 4] * arr2[k + 4][j];
			}
			ret[i][j] = stemp;
		}
	}

	return ret;
}

/**
 * delcol: remove a particular column from the matrix
 *
 * @mat: 2D matrix from which the column is to be removed.
 * @r: no. of rows.
 * @c: no. of cols.
 * @rem: index of the column that needs to be removed (0 based index).
 *
 * return: void
 */
void delcol(double **mat, unsigned long r, unsigned long c,
	    unsigned long rem)
{
	unsigned long i, j;
	double **ret;

	ret = malloc(sizeof(double *) * r);
	for (i = 0; i < r; i++) {
		ret[i] = malloc(sizeof(double) * (c - 1));
	}

	for (i = 0; i < r; i++) {
		for (j = 0; j < rem; j++) {
			ret[i][j] = mat[i][j];
		}
		for (j = rem + 1; j < c; j++) {
			ret[i][j - 1] = mat[i][j];
		}
		free(mat[i]);
		mat[i] = ret[i];
	}

	free(ret);
}

/**
 * transpose: returns the transpose of a matrix.
 *
 * @arr: 2D dynamic array.
 * @r: no. of rows.
 * @c: no. of cols.
 *
 * return: [double **] transpose of matrix.
 */
double **transpose(double **arr, unsigned long r, unsigned long c)
{
	double **ret;
	unsigned long i, j;
	ret = malloc(sizeof(double *) * c);

	for (i = 0; i < c; i++) {
		ret[i] = malloc(sizeof(double) * r);
	}

	for (i = 0; i < c; i++)
		for (j = 0; j < r; j++)
			ret[i][j] = arr[j][i];

	return ret;
}

/**
 * split: split a 2D matrix H/V.
 *
 * @r: no. of rows.
 * @c: no. of cols.
 * @si: start index of split.
 * @ei: end index of split.
 * @horizontal: bool that defines 1 as H split else V split.
 *
 * return: splitted 2D matrix.
 */
double **split(double **matrix, unsigned long r, unsigned long c,
	       unsigned long si, unsigned long ei, enum bool horizontal)
{
	assert(si < ei);
	double **ret = NULL;
	unsigned long size = 0;

	switch (horizontal) {
	case FALSE:
		assert(si >= 0 && ei < c);
		ret = malloc(sizeof(double *) * r);
		size = ei - si + 1;
		for (int i = 0; i < r; i++) {
			ret[i] = malloc(sizeof(double) * size);
			for (int j = 0; j < size; j++)
				ret[i][j] = matrix[i][j + si];
		}
		break;
	case TRUE:
		assert(si >= 0 && ei < r);
		size = ei - si + 1;
		ret = malloc(sizeof(double *) * size);
		for (int i = 0; i < size; i++) {
			ret[i] = malloc(sizeof(double) * c);
			for (int j = 0; j < c; j++)
				ret[i][j] = matrix[i + si][j];
		}
		break;
	}
	return ret;
}


void scalar_add(double a, double **arr, unsigned long r, unsigned long c)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			arr[i][j] += a;
}
