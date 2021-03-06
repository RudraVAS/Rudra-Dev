/**
* rudra_normalization.h: Contains a wide variety of normalization function,
* that user can choose to use according to the needs.
*
* TODO: We can add more normalization functions in the future, to make it a
*	full fledged library header, that could work along without any
*	dependency except standard math library.
*/

#ifndef RUDRA_NORMALIZATION_H
#define RUDRA_NORMALIZATION_H

#include "def.h"

#ifdef __cplusplus
extern "C"
{
#endif	/* __cplusplus */

#include <stdlib.h>
#include "def.h"

void rudra_zscore (TYPE **, size_t, size_t);
void rudra_logscale (TYPE **, size_t, size_t, size_t);
void rudra_minmax (TYPE **, size_t, size_t);
void normalization (TYPE **, size_t, size_t, size_t, enum n_type);

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif	/* RUDRA_NORMALIZATION_H */
