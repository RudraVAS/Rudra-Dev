typedef struct rudra_ann{

/*Number of neurons in input layer, Number of hidden layers , Number of hidden neurons in each layerv, Number of neurons in output layer */
    size_t inputs, hidden_layers, hidden , outputs;

    /* total no of weights used in neural network and total number of neurns used in neural network*/
    size_t total_weights,total_neurons;

    /*Each weight value(its lenght is value of total_weights)  */
    double *weight;

    /* stores input array and output of each neurons (its length is total_neurons)*/
    double *output;

    /* It stores delta of output and hidden neuron and lenth of this is=(total_neurons - inputs)*/
    double *delta;

} rudra_ann;
