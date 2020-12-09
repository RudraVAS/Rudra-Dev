#include "../include/rudra/ann/matrix_operations.h"
#include <stdlib.h>
#include <assert.h>
#include <immintrin.h>

/**
 * m2p: converts a static matrix to dynamic.
 *
 * @r: no. of rows of the static matrix.
 * @c: no. of cols of the static matrix.
 * @arr: static matrix
 *
 * return: dynamic matrix
 */
TYPE **m2p(int r, int c, TYPE arr[r][c])
{
	TYPE **ret = malloc(r * sizeof(TYPE *));
	for (int i = 0; i < r; i++)
		ret[i] = malloc(sizeof(TYPE) * c);

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
void matmulv(TYPE ** ret, TYPE **arr1, unsigned long r1, unsigned long c1,
		TYPE **arr2, unsigned long r2, unsigned long c2)
{
	assert(c1 == r2);

	unsigned long i, j;

	for (i = 0; i < r1; i++) {
		for (j = 0; j < c2; j++) {
			int k = 0, m = 0;
			TYPE stemp = 0.0;

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
}

TYPE ** matmul(TYPE ** arr1, unsigned long r1, unsigned long c1,
		TYPE ** arr2, unsigned long r2, unsigned long c2) {
	TYPE ** ret;
	ret = malloc(sizeof(TYPE *) * r1);

	for(int i = 0; i < r1; i++)
		ret[i] = malloc(sizeof(TYPE) * c2);

	matmulv(ret, arr1, r1, c1, arr2, r2, c2);

	return ret;
}

void avx_mulv(float ** c, float ** a, unsigned long ar, unsigned long ac,
		float ** b, unsigned long br, unsigned long bc) {
	unsigned short n_8 = bc >> 3;
	unsigned short rem = bc - (n_8 << 3);

	static __m256_u m_a, m_b, * m_c;
	static __m128_u _m_a, _m_b, * _m_c;
	
	static unsigned i, j, k, l;
	l = n_8 << 3;

	for(i = 0; i < ar; i++) {
		for(j = 0; j < ac; j++) {
			m_a = _mm256_broadcast_ss(&a[i][j]);
			for(k = 0; k < n_8; k++) {
				m_b = _mm256_loadu_ps(&(b[j][k << 3]));
				m_c = (void *)&(c[i][k << 3]);
				*m_c = _mm256_add_ps(*m_c, _mm256_mul_ps(m_a, m_b));
				
			}
			if(rem >= 4) {
				_m_a = _mm_broadcast_ss(&a[i][j]);
				_m_b = _mm_loadu_ps(&(b[j][n_8 << 3]));
				_m_c = (void *)&(c[i][n_8 << 3]);
				*_m_c = _mm_add_ps(* _m_c, _mm_mul_ps(_m_a, _m_b));
				for(k = l + 4; k < l + rem; k++)
					c[i][k] += a[i][j] * b[j][k];
			}
			else {
				for(k = l; k < l + rem; k++)
					c[i][k] += a[i][j] * b[j][k];
			}
		}
	}
}

float ** avx_mul(float ** a, unsigned long ar, unsigned long ac,
		float ** b, unsigned long br, unsigned long bc) {
	assert(ac == br);
	float ** ret;
	ret = malloc(sizeof(float *) * ar);

	for(int i = 0; i < ar; i++)
		ret[i] = malloc(sizeof(TYPE) * bc);

	avx_mulv(ret, a, ar, ac, b, br, bc);
	
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
void delcol(TYPE **mat, unsigned long r, unsigned long c,
	    unsigned long rem)
{
	unsigned long i, j;
	TYPE **ret;

	ret = malloc(sizeof(TYPE *) * r);
	for (i = 0; i < r; i++) {
		ret[i] = malloc(sizeof(TYPE) * (c - 1));
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
 * return: [TYPE **] transpose of matrix.
 */
TYPE **transpose(TYPE **arr, unsigned long r, unsigned long c)
{
	TYPE **ret;
	unsigned long i, j;
	ret = malloc(sizeof(TYPE *) * c);

	for (i = 0; i < c; i++) {
		ret[i] = malloc(sizeof(TYPE) * r);
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
TYPE **split(TYPE **matrix, unsigned long r, unsigned long c,
	       unsigned long si, unsigned long ei, enum bool horizontal)
{
	assert(si < ei);
	TYPE **ret = NULL;
	unsigned long size = 0;

	switch (horizontal) {
	case FALSE:
		assert(si >= 0 && ei < c);
		ret = malloc(sizeof(TYPE *) * r);
		size = ei - si + 1;
		for (int i = 0; i < r; i++) {
			ret[i] = malloc(sizeof(TYPE) * size);
			for (int j = 0; j < size; j++)
				ret[i][j] = matrix[i][j + si];
		}
		break;
	case TRUE:
		assert(si >= 0 && ei < r);
		size = ei - si + 1;
		ret = malloc(sizeof(TYPE *) * size);
		for (int i = 0; i < size; i++) {
			ret[i] = malloc(sizeof(TYPE) * c);
			for (int j = 0; j < c; j++)
				ret[i][j] = matrix[i + si][j];
		}
		break;
	}
	return ret;
}


void scalar_add(TYPE a, TYPE **arr, unsigned long r, unsigned long c)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			arr[i][j] += a;
}
