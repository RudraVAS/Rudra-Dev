#ifndef __OPTIMIZER_H
#define __OPTIMIZER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "structure.h"

void shuffle(double **, double **, unsigned);
void SGD(struct ann *, double **, double **, unsigned, double);

#ifdef __cplusplus
}
#endif

#endif  /* __OPTIMIZER_H */