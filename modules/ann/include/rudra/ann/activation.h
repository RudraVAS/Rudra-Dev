#ifndef RUDRA_ACTIVATION_H
#define RUDRA_ACTIVATION_H

#include "def.h"

#ifdef __cplusplus
extern "C" {
#endif				/* __cplusplus */

	void activate(double *, unsigned long, double, enum a_type);
	double activate_deriv(double, double, enum a_type);

#ifdef __cplusplus
}
#endif				/* __cplusplus */
#endif				/* RUDRA_ACTIVATION_H */
