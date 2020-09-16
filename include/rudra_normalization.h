/**
* rudra_normalization.h: Contains a wide variety of normalization function,
* that user can choose to use according to the needs.
*
* TODO: We can add more normalization functions in the future, to make it a
*	full fledged library header, that could work along without any
*	dependency except standard math library.
*/

#ifndef __RUDRA_NORMALIZATION_H
#define __RUDRA_NORMALIZATION_H

#ifdef __cplusplus
extern "C"
{
#endif	/* __cplusplus */

#include <stdlib.h>

enum n_types {
	NORMALIZE_Z,
	NORMALIZE_LOG,
	NORMALIZE_MINIMAX
};


void rudra_zscore (double **, size_t, size_t);
void rudra_logscale (double **, size_t, size_t, size_t);
void rudra_minmax (double **, size_t, size_t);
void normalization (double **, size_t, size_t, size_t, enum n_types);

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif	/* __RUDRA_NORMALIZATION_H */
