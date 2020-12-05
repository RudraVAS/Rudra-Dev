#ifndef __RUDRA_OPTIMIZER_H
#define __RUDRA_OPTIMIZER_H

#include "structure.h"

#ifdef cplusplus
extern "C" {
#endif

    void shuffle(TYPE **, TYPE **, unsigned);
    void SGD(struct ann *, TYPE **, TYPE **, unsigned long, unsigned, TYPE);

#ifdef cplusplus
}
#endif


#endif  /* __RUDRA_OPTIMIZER_H */