#ifndef RUDRA_MATRIX_H
#define RUDRA_MATRIX_H

#include "def.h"

#ifdef __cplusplus
extern "C" {
#endif				/* __cplusplus */

	enum bool {
		FALSE,
		TRUE
	};

	TYPE **m2p(int r, int c, TYPE arr[r][c]);
	void matmulv(TYPE **, TYPE **, unsigned long, unsigned long,
			TYPE **, unsigned long, unsigned long);
	TYPE **matmul(TYPE **, unsigned long, unsigned long,
			TYPE **, unsigned long, unsigned long);
	TYPE **transpose(TYPE **, unsigned long, unsigned long);
	TYPE **split(TYPE **, unsigned long, unsigned long,
		       unsigned long, unsigned long, enum bool);
	void scalar_add(TYPE, TYPE **, unsigned long, unsigned long);

	void delcol(TYPE **, unsigned long, unsigned long,
		    unsigned long);

#ifdef __cplusplus
}
#endif

#endif	/* RUDRA_MATRIX_H */
