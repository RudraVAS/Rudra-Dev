/**
 * rudra_activate.h: Contains a wide variety of activation function, that user can choose to
 * use according to the needs.
 *
 * TODO: We can add more activation functions in the future, to make it a full fledged
 *	library header, that could work along without any dependency except standard math
 *	library.
 */
#ifndef __RUDRA_ACTIVATION
#define __RUDRA_ACTIVATION

#ifdef __cplusplus
extern "C" {
#endif

double rudra_activ_sigmoid(double);
double rudra_activ_tanh(double);
double rudra_activ_relu(double);
double rudra_activ_lrelu(double);
double rudra_activ_prelu(double);
double rudra_activ_softmax(double);
double rudra_activ_swish(double);

#ifdef __cplusplus
}
#endif

#endif	/* __RUDRA_ACTIVATION */
