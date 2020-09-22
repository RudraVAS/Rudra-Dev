#ifndef RUDRA_DEF_H
#define RUDRA_DEF_H

#ifdef __cplusplus
extern "C" {
#endif

enum __base_layers {
	INPUT,
	OUTPUT
};

enum __activation_functions {
	SIGMOID,
	TANH,
	RELU,
	LRELU,
	PRELU,
	SOFTMAX,
	SWISH
};

#ifdef __cplusplus
}
#endif

#endif	/* RUDRA_DEF_H */
