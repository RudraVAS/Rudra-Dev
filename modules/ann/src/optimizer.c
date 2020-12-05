#include "../include/rudra/ann/optimizer.h"
#include <stdlib.h>
#include <time.h>
#include "../include/rudra/ann/vector.h"
#include "../include/rudra/ann/propogation.h"

/**
 * shuffle: shuffle a matrix on basis of row.
 *
 * @data: matrix that needs to be shuffled.
 * @row: no. of rows in the matrix.
 *
 * return: void
 */
void shuffle(TYPE **a, TYPE **b, unsigned row)
{
	unsigned index;
	TYPE *tmp;
	srand(time(0));
	for (int i = row - 1; i >= 0; i--) {
		index = (rand() % row);

		tmp = a[i];
		a[i] = a[index];
		a[index] = tmp;

		tmp = b[i];
		b[i] = b[index];
		b[index] = tmp;
	}
	tmp = NULL;
}

/**
 * SGD: Stochastic Gradient Descent optimizer.
 *
 * @ptr: main ann structure for the given data.
 * @input: matrix containing the input.
 * @output: matrix containing the output.
 * @i_row: no. of rows in input matrix.
 * @batch_size: no. of rows in each batch.
 * @lr: learning rate
 *
 * return: void
 */

/*
void SGD(struct ann *ptr, TYPE **input, TYPE **output,
	unsigned long ir, unsigned batch_size, TYPE lr)
{
	shuffle(input, output, ir);

	short n_batch = ir / batch_size;

	for (unsigned i = 0; i < ir; i += batch_size) {
		for (unsigned j = 0; j < batch_size; j++)
			backprop(ptr, input[j + i], output[j + i], lr);
	}
}
*/
void SGD(struct ann *ptr, TYPE **input, TYPE **output, unsigned long ir,
	unsigned batch_size, TYPE lr)
{
	shuffle(input, output, ir);

	short n_batch = ir / batch_size;

	for (unsigned i = 0; i < ir; i += batch_size) {
		for (unsigned j = 0; j < batch_size && i+j < ir; j++){
//			printf("%d %d %d\n", i, j, j+i);
			backprop(ptr, input[j + i], output[j + i], lr);
		}
	}
}