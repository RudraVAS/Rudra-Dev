#ifndef __STDLIB_H        // Header Guard stdlib start
#include<stdlib.h>
#endif                    // Header Guard Stdlib end
/* File Containing global definations*/
#ifndef __RUDRA_DEF_H            //Hearder Guard Rudra Start
#define __RUDRA_DEF_H
/**
 * TODO: know what *oputut do
 * FIXME: code and comment
 */

#ifdef __cpluscplus
extern "C" {
#endif
/*Structure defining a neural network interface*/
typedef struct rudra_ann{

/*Number of neurons in input layer, Number of hidden layers , Number of hidden neurons in each layerv, Number of neurons in output layer */
    size_t no_inputs, no_hidden_layers, no_hidden , no_outputs;

    /* total no of weights used in neural network and total number of neurns used in neural network*/
    size_t total_weights,total_neurons;

    /*Each weight value(its lenght is value of total_weights)  */
    double *weight;

    /* stores input array and output of each neurons (its length is total_neurons)*/
    double *output;

    /* It stores delta of output and hidden neuron and lenth of this is=(total_neurons - inputs)*/
    double *delta;


} rudra_ann;

#ifdef __cpluscplus
}
#endif

#endif  /*__RUDRA_DEF_H_*/     
