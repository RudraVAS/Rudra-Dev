/**
 * File Containing global definations
 */
#ifndef __RUDRA_DEF_H
#define __RUDRA_DEF_H

#include<assert.h>
/**
 *Runtime deagnostic function(to handle runtime assertion)
 */
#define RUDRA_ASSERT(reason) assert(reason)
#define RUDRA_ASSERT_MSG(reason, msg) assert((reason) && (msg))

/**
 * TODO: know what *oputut do
 * FIXME: code and comment
 */

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * struct rudra_ann - defines the structure of a neural network interface
 * @n_inputs: number of categories/features/rows of inputs
 * @n_hlayers: number of hidden layers
 * @n_hnodes: number of hidden nodes
 * @n_outputs: number of outputs
 * @t_weights: total weights (hidden weights + output weights)
 * @t_neurons: total neurons
 * @weight: array that contains all the weights (weight[t_weights])
 * @output: array that contains all the outputs (output[t_neurons])
 * @delta: array for delta of each hidden and output neurons
 */
typedef struct rudra_ann{
	size_t n_inputs;
	size_t n_hlayers;
	size_t n_hnodes;
	size_t n_outputs;
	size_t t_weights;
	size_t t_neurons;

	double *weight;
	double *output;
	double *delta;
} rudra_ann;

#ifdef __cplusplus
}
#endif

#endif  /*__RUDRA_DEF_H_*/
