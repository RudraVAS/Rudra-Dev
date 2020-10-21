#include "rudra/ann/propogation.h"
#include "rudra/ann/structure.h"
#include <stddef.h>

void feed_fwd(struct ann *ptr, double *in)
{
	unsigned i, j, k;
	for (int i = 0; i < ptr->layer[INPUT]->n_nodes; i++) {
		ptr->layer[INPUT]->nodes[i][0] = in[i];
		ptr->layer[INPUT]->unactiv_nodes[i][0] = in[i];
	}

	for (i = 0; i < ptr->n_hlayers; i++) {
		for (j = 0; j < ptr->hlayer[i]->n_nodes; j++)
			free(ptr->hlayer[i]->nodes[j]);
		free(ptr->hlayer[i]->nodes);
	}

	for (i = 0; i < ptr->layer[OUTPUT]->n_nodes; i++)
		free(ptr->layer[OUTPUT]->nodes[i]);
	free(ptr->layer[OUTPUT]->nodes);

	struct __layer *p_layer = ptr->layer[INPUT];
	struct __layer *c_layer = NULL;
	unsigned hlayer_i = 0;

	c_layer =
	    ptr->n_hlayers >
	    hlayer_i ? ptr->hlayer[hlayer_i] : ptr->layer[OUTPUT];

	while (c_layer) {
		hlayer_i++;
		c_layer->nodes =
		    matmul(p_layer->weights, p_layer->wr, p_layer->wc,
			   p_layer->nodes, p_layer->n_nodes, 1);
		scalar_add(p_layer->bias, c_layer->nodes,
			   c_layer->n_nodes, 1);

		for (int i = 0; i < c_layer->n_nodes; i++) {
			c_layer->unactiv_nodes[i][0] =
			    c_layer->nodes[i][0];
			activate(c_layer->nodes[i], 1, c_layer->alpha,
				 c_layer->act_code);
		}

		p_layer = c_layer;
		c_layer =
		    ptr->n_hlayers >
		    hlayer_i ? ptr->hlayer[hlayer_i] : ptr->layer[OUTPUT];

		p_layer == c_layer ? (c_layer = NULL) : 0;
	}
}

double *cost_deriv(double *target, double **output, unsigned r)
{
	double *ret = malloc(sizeof(double *) * r);

	for (int i = 0; i < r; i++)
		ret[i] = output[i][0] - target[i];

	return ret;
}


void backprop(struct ann *ptr, double *in, double *target, double lr)
{
	feed_fwd(ptr, in);
	struct __layer *p_layer = ptr->layer[OUTPUT];
	struct __layer *c_layer = ptr->n_hlayers ?
	    ptr->hlayer[ptr->n_hlayers - 1] : ptr->layer[INPUT];

	if (p_layer->derr_dout != NULL) {
		free(p_layer->derr_dout);
		p_layer->derr_dout = NULL;
	}

	if (p_layer->derr_dw != NULL) {
		for (int i = 0; i < p_layer->n_nodes; i++)
			free(p_layer->derr_dw[i]);
		free(p_layer->derr_dw);
	}

	p_layer->derr_dout =
	    cost_deriv(target, p_layer->nodes, p_layer->n_nodes);

	for (int i = 0; i < p_layer->n_nodes; i++) {
		p_layer->dout_din[i] =
		    activate_deriv(p_layer->unactiv_nodes[i][0],
				   p_layer->alpha, p_layer->act_code);
	}

	double **tmp = malloc(sizeof(double *) * p_layer->n_nodes);
	for (int i = 0; i < p_layer->n_nodes; i++) {
		tmp[i] = malloc(sizeof(double));
		tmp[i][0] = p_layer->dout_din[i] * p_layer->derr_dout[i];
	}
	if (p_layer->din_dw == NULL) {
		p_layer->din_dw = malloc(sizeof(double *));
		p_layer->din_dw[0] = malloc(sizeof(double *)
					    * c_layer->n_nodes);
	}
	for (int i = 0; i < c_layer->n_nodes; i++) {
		p_layer->din_dw[0][i] = c_layer->nodes[i][0];
	}
	p_layer->derr_dw =
	    matmul(tmp, p_layer->n_nodes, 1, p_layer->din_dw, 1,
		   c_layer->n_nodes);

	for (int i = 0; i < c_layer->wr; i++)
		for (int j = 0; j < c_layer->wc; j++)
			c_layer->weights[i][j] -=
			    lr * p_layer->derr_dw[i][j];

	for (int i = 0; i < p_layer->n_nodes; i++)
		c_layer->bias -= lr * tmp[i][0];

	for (int i = 0; i < p_layer->n_nodes; i++)
		free(tmp[i]);
	free(tmp);
/**
 * Hidden layers
 */
	struct __layer *m_layer = NULL;
	for (int i = ptr->n_hlayers - 1; i >= 0; i--) {
		m_layer = c_layer;
		if (i) {
			c_layer = ptr->hlayer[i - 1];
		} else {
			c_layer = ptr->layer[INPUT];
		}

		tmp = malloc(sizeof(double *) * p_layer->n_nodes);
		for (int i = 0; i < p_layer->n_nodes; i++) {
			tmp[i] = malloc(sizeof(double));
			tmp[i][0] = p_layer->derr_dout[i] *
			    p_layer->dout_din[i];
		}
		double **tmp1 = transpose(m_layer->weights,
					  m_layer->wr, m_layer->wc);

		double **tmp2 = matmul(tmp1, m_layer->wc, m_layer->wr,
				       tmp, p_layer->n_nodes, 1);

		if (m_layer->derr_dout == NULL) {
			m_layer->derr_dout = malloc(sizeof(double)
						    * m_layer->n_nodes);
		}

		for (int i = 0; i < m_layer->wc; i++)
			free(tmp1[i]);
		free(tmp1);

		for (int i = 0; i < m_layer->n_nodes; i++) {
			m_layer->derr_dout[i] = tmp2[i][0];
			m_layer->dout_din[i] =
			    activate_deriv(m_layer->unactiv_nodes[i][0],
					   m_layer->alpha,
					   m_layer->act_code);
			tmp2[i][0] = m_layer->derr_dout[i]
			    * m_layer->dout_din[i];
		}

		if (m_layer->din_dw == NULL) {
			m_layer->din_dw = malloc(sizeof(double *));
			m_layer->din_dw[0] = malloc(sizeof(double)
						    * m_layer->n_nodes);
		}

		for (int i = 0; i < c_layer->n_nodes; i++) {
			m_layer->din_dw[0][i] = c_layer->nodes[i][0];
		}

		if (m_layer->derr_dw != NULL) {
			for (int i = 0; i < c_layer->wr; i++)
				free(m_layer->derr_dw[i]);
			free(m_layer->derr_dw);
		}

		m_layer->derr_dw = matmul(tmp2, m_layer->n_nodes, 1,
					  m_layer->din_dw, 1,
					  c_layer->n_nodes);

		for (int i = 0; i < c_layer->wr; i++)
			for (int j = 0; j < c_layer->wc; j++)
				c_layer->weights[i][j] -=
				    lr * m_layer->derr_dw[i][j];

		for (int i = 0; i < p_layer->n_nodes; i++)
			c_layer->bias -= lr * tmp[i][0];

		for (int i = 0; i < m_layer->n_nodes; i++)
			free(tmp2[i]);
		free(tmp2);

		for (int i = 0; i < p_layer->n_nodes; i++)
			free(tmp[i]);
		free(tmp);

		p_layer = m_layer;
	}
	c_layer = m_layer = p_layer = NULL;
}