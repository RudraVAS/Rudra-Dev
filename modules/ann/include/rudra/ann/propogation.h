#ifndef __PROPOGATION_H
#define __PROPOGATION_h

#ifdef __cplusplus
extern "C" {
#endif

#include "structure.h"

void feed_fwd(struct ann *, double *);
void backprop(struct ann *, double *, double *, double);

#ifdef __cplusplus        
}
#endif

#endif  /*__PROPOGATION_H */