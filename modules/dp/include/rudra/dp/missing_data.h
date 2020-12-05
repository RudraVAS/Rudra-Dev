#ifndef __RUDRA_MISSING_DATA
#define __RUDRA_MISSING_DATA

#include "def.h"

#ifdef cplusplus
extern "C" {
#endif

enum missing_options {
        MEAN,
        MODE,
        MEDIAN
};

void missing_data(TYPE **, unsigned, unsigned, enum missing_options);

#ifdef cplusplus
}
#endif

#endif  /* __RUDRA_MISSING_DATA */