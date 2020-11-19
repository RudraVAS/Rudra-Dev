#include "rudra/ann/optimizer.h"
#include <stdlib.h>
#include <time.h>
#include "rudra/ann/vector.h"
#include "rudra/ann/propogation.h"

/**
 * shuffle: shuffle a matrix on basis of row.
 *
 * @data: matrix that needs to be shuffled.
 * @row: no. of rows in the matrix.
 *
 * return: void
 */
void shuffle(double **a, double **b, unsigned row)
{
	unsigned index;
	double *tmp;
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
 * @i_row: no. of rows in input matrix.
 * @i_col: no. of cols in input matrix.
 * @output: matrix containing the output.
 * @o_row: no. of rows in output matrix.
 * @o_col: no. of cols in output matrix.
 * @batch_size: no. of rows in each batch.
 * @lr: learning rate
 *
 * return: void
 */
void SGD(struct ann *ptr, double **input, double **output,
	unsigned batch_size, double lr)
{
	shuffle(input, output, vec_row(input));

	short n_batch = vec_row(input) / batch_size;

	for (unsigned i = 0; i < vec_row(input); i += batch_size) {
		for (unsigned j = 0; j < batch_size; j++)
			backprop(ptr, input[j + i], output[j + i], lr);
	}
}