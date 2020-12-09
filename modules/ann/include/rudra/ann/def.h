#ifndef RUDRA_DEF_H
#define RUDRA_DEF_H

#ifdef __cplusplus
extern "C" {
#endif

	enum __base_layers {
		INPUT,
		OUTPUT
	};

	enum a_type {
		SIGMOID,
		RELU,
		LEAKY_RELU,
		LINEAR,
		ELU,
		TANH
	};

	enum n_type {
		NORMALIZE_NONE,
		NORMALIZE_Z,
		NORMALIZE_LOG,
		NORMALIZE_MINIMAX
	};

	#define TYPE float

#ifdef __cplusplus
}
#endif
#endif				/* __DEF_H */
