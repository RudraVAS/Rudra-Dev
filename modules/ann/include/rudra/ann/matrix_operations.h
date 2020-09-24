#ifndef RUDRA_MATRIX_H
#define RUDRA_MATRIX_H

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

enum bool {
	FALSE,
	TRUE
};

double **m2p(int r, int c, double arr[r][c]);
double **matmul(double **, unsigned long, unsigned long,
		double **, unsigned long, unsigned long);
double **transpose(double **, unsigned long, unsigned long);
double **split(double **, unsigned long, unsigned long,
	       unsigned long, unsigned long, enum bool);

void delcol(double **, unsigned long, unsigned long,
	    unsigned long);

#ifdef __cplusplus
}
#endif	/* __cplusplus */
#endif	/* RUDRA_MATRIX_H */
