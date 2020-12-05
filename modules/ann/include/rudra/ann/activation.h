#ifndef RUDRA_ACTIVATION_H
#define RUDRA_ACTIVATION_H

#include "def.h"

#ifdef __cplusplus
extern "C" {
#endif				/* __cplusplus */

	void activate(TYPE *, unsigned long, TYPE, enum a_type);
	TYPE activate_deriv(TYPE, TYPE, enum a_type);

#ifdef __cplusplus
}
#endif				/* __cplusplus */
#endif				/* RUDRA_ACTIVATION_H */
