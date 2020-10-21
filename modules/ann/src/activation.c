#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "rudra/ann/activation.h"

/**
 * rudra_linear - activation function used the formula (value*contant) to
 * 	produce value for output matrix
 *
 * @z - input feature value to be transformed to range
 * @m - Constant term mutiplied with each z
 * 
 * Return Type - double tranformed output feature value
 */
double rudra_linear(double z, double m)
{
	return (z * m);
}

/**
 * rudra_elu - activation function used the formula (below) to produce value
 * 	for output matrix
 * 
 * @z - input feature value to be transformed
 * @alpha - constant used in ELU activation function
 * Return Type - double tranformed output feature value 
 * 
 * TODO:  Null
 */
double rudra_elu(double z, double alpha)
{
	return ((z > 0) ? z : (alpha * (exp(z) - 1)));
}

/**
 * rudra_relu -activation function used the formula (below) to produce value
 * 	for output matrix 
 *
 * @z - input feature value to be transformed
 * Return Type - double tranformed output feature value 
 * 
 * TODO:  Null
 */
double rudra_relu(double z)
{
	return (z > 0) ? z : 0;
}

/**
 * rudra_leakyrelu - activation function used the formula (below) to produce value for output matrix 
 * 
 * @z - input feature value to be transformed
 * @alpha - constant used in this activation function
 * Return Type - double tranformed output feature value  
 * TODO:  Null
 */
double rudra_leakyrelu(double z, double alpha)
{
	return ((z > 0) ? z : (alpha * z));
}

/**
* rudra_sigmoid -activation function used the formula (1/(1+e^(-x))) to produce value for output matrix 
 * 
 * @z - input feature value to be transformed
 * Return Type - double tranformed output feature value 
 * TODO:  Null 
 */
double rudra_sigmoid(double z)
{
	return 1 / (1 + exp(-z));
}

/**
 * rudra_tan_h - activation function used the formula (tanh) to produce value for output matrix 
 * 
 * @z - input feature value to be transformed
 * Return Type - double tranformed output feature value 
 * TODO:  Null 
 */
double rudra_tan_h(double z)
{
	return tanh(z);

}

/**
 * rudra_linear_derv - Function To compute the derivative of linear activation function
 *
 * @z - input feature value to be transformed to range
 * @m - Constant term mutiplied with each z
 * Return Type - derivative of activation function
 * TODO:  Null
 */
double rudra_linear_derv(double z, double m)
{
	return m;
}


/**
 * rudra_elu_derv - Function To compute the derivative of ELU activation function
 *
 * @z - input feature value to be transformed to range
 * @alpha - Constant used in elu
 * Return Type - derivative of activation function
 * TODO:  Null
 */
double rudra_elu_derv(double z, double alpha)
{
	return z > 0 ? 1 : alpha * exp(z);
}


/**
 * rudra_relu_derv - Function To compute the derivative of RELU activation function
 *
 * @z - input feature value to be transformed to range
 * Return Type - derivative of activation function
 * TODO:  Null
 */
double rudra_relu_derv(double z)
{
	return z > 0;
}

/**
 * rudra_leakyrelu_derv - Function To compute the derivative of Leaky RELU activation function
 *
 * @z - input feature value to be transformed to range
 * @alpha - Constant used in Leaky Relu
 * Return Type - derivative of activation function 
 * TODO:  Null
 */
double rudra_leakyrelu_derv(double z, double alpha)
{
	return z > 0 ? 1 : alpha;
}


/**
 * rudra_sigmoid_derv - Function To compute the derivative of Sigmoid activation function
 *
 * @z - input feature value to be transformed to range
 * Return Type - derivative of activation function 
 * TODO:  Null
 */
double rudra_sigmoid_derv(double z)
{
	double x = 1 / (1 + exp(-z));
	return x * (1 - x);
}

/**
 * rudra_tan_h_derv - Function To compute the derivative of tanh activation function
 *
 * @z - input feature value to be transformed to range
 * Return Type - derivative of activation function 
 * TODO:  Null
 */
double rudra_tan_h_derv(double z)
{
	return 1 - (pow(tanh(z), 2));
}



/**
 * acti_derv: Function To compute the choose and call the derivative of activation function
 *
 * @z: input feature value to be transformed to range
 * @alpha: Constant used as per the activation function  and if not then any integer value is fine
 * 
 * return: double derivative of activation function 
 */
double activate_deriv(double z, double alpha, enum a_type decision)
{
	double answer;
	switch (decision) {
	case SIGMOID:
		answer = rudra_sigmoid_derv(z);
		return answer;

	case RELU:
		answer = rudra_relu_derv(z);
		return answer;

	case LEAKY_RELU:
		answer = rudra_leakyrelu_derv(z, alpha);
		return answer;

	case LINEAR:
		answer = rudra_linear_derv(z, alpha);
		return answer;

	case ELU:
		answer = rudra_elu_derv(z, alpha);
		return answer;

	case TANH:
		answer = rudra_tan_h_derv(z);
		return answer;

	default:
		return 0.0;

	}
}


/**
 * activation: main function of activation function used by layers to call
 * 	their respective activation function.
 * 
 * @ptr: Contain the pointer of the matrix to which activation function is
 * 	applied
 * @rows: number of Rows in the matrix (whose pointer is passed)
 * @columns: number of columns in the matrix (whose pointer is passed)
 * @alpha: input used to pass the constant value when required else pass 0
 * @decision: contain the decision of activation function to be used in the
 * 	layer
 * 
 * Return Type - void
 * 
 * TODO:  Adding more activation functions like sofmax etc.
 */

void activate(double *ptr, unsigned long size, double alpha,
	      enum a_type act)
{
//      double * ret = malloc(sizeof(double) * size);
	for (int i = 0; i < size; i++) {
		switch (act) {
		case SIGMOID:
			ptr[i] = rudra_sigmoid(ptr[i]);
			break;

		case RELU:
			ptr[i] = rudra_relu(ptr[i]);
			break;

		case LEAKY_RELU:
			ptr[i] = rudra_leakyrelu(ptr[i], alpha);
			break;


		case LINEAR:
			ptr[i] = rudra_linear(ptr[i], alpha);
			break;

		case ELU:
			ptr[i] = rudra_elu(ptr[i], alpha);
			break;


		case TANH:
			ptr[i] = rudra_tan_h(ptr[i]);
			break;

		default:
			break;
		}
	}
//      return ret;
}
