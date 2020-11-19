#ifndef RUDRA_LAYERS_H
#define RUDRA_LAYERS_H

#include "def.h"

#ifdef __cplusplus
extern "C" {
#endif

	struct __layer {
		unsigned short n_nodes;
		unsigned short wc, wr;
		double alpha;
		enum a_type act_code;
		enum n_type nor_code;
		double bias;
		double **unactiv_nodes;
		double **nodes;
		double **weights;
		double **d1;
		double **d2;
		double **d3;
		double **d4;
		double **df;
	};

	struct ann {
		unsigned short n_hlayers;
		struct __layer *layer[2];
		struct __layer **hlayer;
	};

#ifdef __cplusplus
}
#endif
#endif				/* __LAYERS_H */
