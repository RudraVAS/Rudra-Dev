#ifndef RUDRA_OPERATIONS_H
#define RUDRA_OPERATIONS_H

#ifdef __cplusplus
extern "C" {
#endif				/* __cplusplus */

	enum bool_ {
		FALSE,
		TRUE
	};

	double **m2p(int r_, int c_, double[r_][c_]);
	void matmulv(double **, double **, unsigned long, unsigned long,
			double **, unsigned long, unsigned long);
	double **matmul(double **, unsigned long, unsigned long,
			double **, unsigned long, unsigned long);
	double **transpose(double **, unsigned long, unsigned long);
	double **split(double **, unsigned long, unsigned long,
		       unsigned long, unsigned long, enum bool_);
	void scalar_add(double, double **, unsigned long, unsigned long);

	void delcol(double **, unsigned long, unsigned long,
		    unsigned long);

#ifdef __cplusplus
}
#endif

#endif	/* RUDRA_OPERATIONS_H */
