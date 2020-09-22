#ifndef RUDRA_LAYER_MANIPULATION_H
#define RUDRA_LAYER_MANIPULATION_H

#include "layers.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

struct ann * init(unsigned short, unsigned short);
char add_layer(struct ann *, unsigned short, unsigned char);

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif  /* RUDRA_LAYER_MAINPULATION_H */

