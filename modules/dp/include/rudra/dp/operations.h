#ifndef RUDRA_OPERATIONS_H
#define RUDRA_OPERATIONS_H

#include "def.h"

#ifdef __cplusplus
extern "C" {
#endif				/* __cplusplus */

	enum bool_ {
		FALSE,
		TRUE
	};

	TYPE **dp_m2p(int r_, int c_, TYPE[r_][c_]);
	void dp_matmulv(TYPE **, TYPE **, unsigned long, unsigned long,
			TYPE **, unsigned long, unsigned long);
	TYPE **dp_matmul(TYPE **, unsigned long, unsigned long,
			TYPE **, unsigned long, unsigned long);
	TYPE **dp_transpose(TYPE **, unsigned long, unsigned long);
	TYPE **dp_split(TYPE **, unsigned long, unsigned long,
		       unsigned long, unsigned long, enum bool_);
	void dp_scalar_add(TYPE, TYPE **, unsigned long, unsigned long);

	void dp_delcol(TYPE **, unsigned long, unsigned long,
		    unsigned long);

#ifdef __cplusplus
}
#endif

#endif	/* RUDRA_OPERATIONS_H */
