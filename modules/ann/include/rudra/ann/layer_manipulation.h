#ifndef RUDRA_LAYER_MANIPULATION_H
#define RUDRA_LAYER_MANIPULATION_H

#include "structure.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

struct ann * init(unsigned, unsigned);
struct ann * add_layer(struct ann *, unsigned);
void print_det(struct ann *);
void cleanup(struct ann *);

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif  /* RUDRA_LAYER_MAINPULATION_H */
