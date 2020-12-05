#ifndef __PROPOGATION_H
#define __PROPOGATION_h

#ifdef __cplusplus
extern "C" {
#endif

#include "structure.h"
#include "def.h"

void feed_fwd(struct ann *, TYPE *);
void backprop(struct ann *, TYPE *, TYPE *, TYPE);

#ifdef __cplusplus        
}
#endif

#endif  /*__PROPOGATION_H */