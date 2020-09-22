#ifndef RUDRA_LAYERS_H
#define RUDRA_LAYERS_H

#include "def.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

struct __layer {
	unsigned short n_nodes;
	unsigned short n_weights;
	double * nodes;
	double * weights;
};

struct ann {
	unsigned short n_hlayers;
	struct __layer * layer[2];
	struct __layer ** hlayer;
};

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif	/* RUDRA_LAYERS_H */

