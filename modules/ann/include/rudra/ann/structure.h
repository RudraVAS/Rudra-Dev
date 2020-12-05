#ifndef RUDRA_LAYERS_H
#define RUDRA_LAYERS_H

#include "def.h"

#ifdef __cplusplus
extern "C" {
#endif

	struct __layer {
		unsigned short n_nodes;
		unsigned short wc, wr;
		TYPE alpha;
		enum a_type act_code;
		enum n_type nor_code;
		TYPE bias;
		TYPE **unactiv_nodes;
		TYPE **nodes;
		TYPE **weights;
		TYPE **d1;
		TYPE **d2;
		TYPE **d3;
		TYPE **d4;
		TYPE **df;
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
