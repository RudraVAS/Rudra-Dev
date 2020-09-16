#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/rudra_normalization.h"

/**
 * rudra_zscore: Normalize the data set using the formula
 *		Z = (Score - mean)/standard deviation.
 *
 * @raw_data: Pointer of a 2-D matrix dataset
 * @n_rows: no of rows in dataset
 * @n_cols: no of features(columns in the dataset)
 *
 * return: void
 */
void rudra_zscore(double **raw_data, size_t n_rows, size_t n_cols) {
	size_t i, j;
	double mean[n_cols], std_dev[n_cols];
	double value, sum, sq_sum;
	for (i = 0; i < n_cols; i++) {
		sum = 0.0;
		for (j = 0; j < n_rows; j++) {
			sum += raw_data[j][i];
		}
		mean[i] = sum / n_rows;
		sq_sum = 0.0;
		for (j = 0; j < n_rows; j++) {
			sq_sum += pow(raw_data[j][i] - mean[i], 2);
		}
		std_dev[i] = sqrt(sq_sum / n_rows);
		for (j = 0; j < n_rows; j++) {
			value = raw_data[j][i];
			raw_data[j][i] = (value - mean[i]) / std_dev[i];
		}
	}
}

/**
 * rudra_logscale: Normalize the data set using the formula Z= log(X).
 *
 * @raw_data: Pointer of a 2-D matrix dataset
 * @n_rows: no of rows in dataset
 * @n_cols: no of features(columns in the dataset)
 * @base: base used in log to scale the data
 *
 * return: void
 */
void rudra_logscale(double **raw_data, size_t n_rows, size_t n_cols,
			size_t base) {
	size_t i, j;
	double value;
	for (i = 0; i < n_cols; i++) {
		for (j = 0; j < n_rows; j++) {
			value = (log(raw_data[j][i])) / (log(base));
			raw_data[j][i] = value;
		}
	}

}

/**
 * rudra_minmax: Normalize the data set using the formula:
 *		Z = (X - Xmin) / (Xmax - Xmin).
 *
 * @raw_data: Pointer of a 2-D matrix dataset
 * @n_rows: no of rows in dataset
 * @n_cols: no of features(columns in the dataset)
 *
 * return: void
 */
void rudra_minmax(double **raw_data, size_t n_rows, size_t n_cols) {
	int i, j;
	double value;
	double min[n_cols], max[n_cols];
	for (i = 0; i < n_cols; i++) {
		min[i] = 1000000000000;
		for (j = 0; j < n_rows; j++) {
			if (min[i] > raw_data[j][i]) {
				min[i] = raw_data[j][i];
			}
			if (max[i] < raw_data[j][i]) {
				max[i] = raw_data[j][i];
			}
		}
		for (j = 0; j < n_rows; j++) {
			value = raw_data[j][i];
			raw_data[j][i] =
			    (value - min[i]) / (max[i] - min[i]);
		}
	}
}

/**
 * normalization: Function Contain all normalization calling based on swwitch case.
 *
 * @raw_data: Pointer of a 2-D matrix dataset
 * @m: no of rows in dataset
 * @n: no of features(columns in the dataset)
 * @b: base used in log scaling(optional only used when called log sclaing)
 * @decision: Type of the normalization that you perform.
 *	For more info please look at enum n_types in *.h file for the
 *	corresponding file.
 *
 * return: void
 */
void normalization(double **raw_data, size_t m, size_t n, size_t b, enum n_types decision) {
	switch (decision){
	case 0:
		rudra_zscore(raw_data, m, n);
		break;
	case 1:
		rudra_logscale(raw_data, m, n, b);
		break;
	case 2:
		rudra_minmax(raw_data, m, n);
		break;
	default:
		exit(1);
	}
}

