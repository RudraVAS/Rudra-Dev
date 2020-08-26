#include "rudra_init.h"
#include <stdio.h>
#include <time.h>

/**
 * rudra_init - Allocate the memory to the struct rudra_nn acc. to the the given parameters.
 *
 * @n_inputs - no. of inputs
 * @n_hlayers - no. of total hidden layers
 * @n_hnodes - no. of nodes in each hidden layer
 * @n_outputs - no. of outputs
 *
 * TODO: Make the no. of nodes in our NN an array/vector, so that we can even specify the
 *	different no.(s) of nodes for each hidden layer.
 * TODO: Make a function pointer for normalization function and the activation function.
 */

rudra_ann * rudra_init (size_t n_inputs, size_t n_hlayers, size_t n_hnodes, size_t n_outputs) {
	RUDRA_ASSERT(n_inputs > 0);
	RUDRA_ASSERT(n_hlayers >= 0);
	if(n_hlayers) {
		RUDRA_ASSERT(n_hnodes > 0);
	}
	RUDRA_ASSERT(n_outputs > 0);

/**
 * Here +1 is for bias values. For more info visit:
 * https://stats.stackexchange.com/questions/296981/formula-for-number-of-weights-in-neural-network
 */
	size_t h_weights = n_hlayers ? (n_inputs + 1) * n_hnodes + (n_hlayers - 1) *
				(n_hnodes - 1) * n_hnodes : 0;
	size_t o_weights = (n_hlayers ? (n_hnodes + 1) : (n_inputs + 1)) * n_outputs;
	size_t t_weights = h_weights + o_weights;
	size_t t_neurons = n_inputs + n_hlayers * n_hnodes + n_outputs;

/**
 * t_neurons - n_input for delta.
 */
	size_t alloc_size = sizeof(rudra_ann) + sizeof(double) * (t_weights + t_neurons +
				(t_neurons - n_inputs));

	rudra_ann * __nn = malloc(alloc_size);
	RUDRA_ASSERT(__nn);

	__nn->n_inputs = n_inputs;
	__nn->n_hlayers = n_hlayers;
	__nn->n_hnodes = n_hnodes;
	__nn->n_outputs = n_outputs;

	__nn->t_weights = t_weights;
	__nn->t_neurons = t_neurons;

	__nn->weight = (double *)(sizeof(rudra_ann) + (char *)__nn);
	__nn->output = __nn->weight + t_weights;
	__nn->delta = __nn->output + t_neurons;

/**
 * assigning random weights.
 */
	srand(time(NULL));
	for(size_t i = 0; i < __nn->t_weights; i++) {
		__nn->weight[i] = ((rand() % 1000) / 1000) - 0.5;
	}
	return __nn;
}
