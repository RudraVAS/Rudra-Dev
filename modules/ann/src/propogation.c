#include "../include/rudra/ann/propogation.h"
#include "../include/rudra/ann/structure.h"
#include "../include/rudra/ann/matrix_operations.h"
#include "../include/rudra/ann/activation.h"
#include <stddef.h>
#include <stdlib.h>

void feed_fwd(struct ann *ptr, TYPE *in)
{
	unsigned long i, j, k;
	for (i = 0; i < ptr->layer[INPUT]->n_nodes; i++) {
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

		if(p_layer == c_layer) c_layer = NULL;
	}
}

TYPE cost_deriv(TYPE target, TYPE output)
{
	return output - target;
}

void __backprop_o(struct __layer * p, struct __layer * c, TYPE * target) {
	for(int i = 0; i < p->n_nodes; i++) {
		p->d1[i][0] = cost_deriv(target[i], p->nodes[i][0]);
		p->d2[i][0] = activate_deriv(p->unactiv_nodes[i][0],
                                   p->alpha, p->act_code);
		p->d4[i][0] = p->d1[i][0] * p->d2[i][0];
	}

	if(p->d3 == NULL) {
		p->d3 = malloc(sizeof(TYPE *));
		p->d3[0] = malloc(sizeof(TYPE) * c->n_nodes);
	}

	for(int i = 0; i < c->n_nodes; i++) {
		p->d3[0][i] = c->nodes[i][0];
	}

	if(c->df == NULL) {
		c->df = malloc(sizeof(TYPE *) * c->wr);
		for(int i = 0; i < c->wr; i++)
			c->df[i] = malloc(sizeof(TYPE) * c->wc);
	}

	matmulv(c->df, p->d4, p->n_nodes, 1, p->d3, 1, c->n_nodes);
}

void __backprop_h(struct __layer * p, struct __layer *m, struct __layer *c) {
	TYPE ** tmp = transpose(m->weights, m->wr, m->wc);

	matmulv(m->d1, tmp, m->wc, m->wr, p->d4, p->n_nodes, 1);

	for(int i = 0; i < m->wc; i++)
		free(tmp[i]);
	free(tmp);

	for(int i = 0; i < m->n_nodes; i++) {
		m->d2[i][0] = activate_deriv(m->unactiv_nodes[i][0],
				m->alpha, m->act_code);
		m->d4[i][0] = m->d1[i][0] * m->d2[i][0];
	}

	if(m->d3 == NULL) {
		m->d3 = malloc(sizeof(TYPE *));
		m->d3[0] = malloc(sizeof(TYPE) * c->n_nodes);
	}
	for(int i = 0; i < c->n_nodes; i++)
		m->d3[0][i] = c->nodes[i][0];

	if(c->df == NULL) {
		c->df = malloc(sizeof(TYPE *) * c->wr);
		for(int i = 0; i < c->wr; i++)
			c->df[i] = malloc(sizeof(TYPE) * c->wc);
	}

	matmulv(c->df, m->d4, m->n_nodes, 1, m->d3, 1, c->n_nodes);
}

void update(struct __layer * p, struct __layer * c, TYPE lr) {
	for(int i = 0; i < c->wr; i++)
		for(int j = 0; j < c->wc; j++)
			c->weights[i][j] -= lr * c->df[i][j];

	for(int i = 0; i < p->n_nodes; i++)
		c->bias -= lr * p->d4[i][0];
}

void backprop(struct ann * ptr, TYPE * in, TYPE * target, TYPE lr) {
	feed_fwd(ptr, in);

	struct __layer *c, *m, *p;
	c = m = p = NULL;

	p = ptr->layer[OUTPUT];

	if(ptr->n_hlayers) {
		m = ptr->hlayer[ptr->n_hlayers-1];
		if(ptr->n_hlayers == 1)
			c = ptr->layer[INPUT];
		else
			c = ptr->hlayer[ptr->n_hlayers -2];
	}
	else {
		m = ptr->layer[INPUT];
	}

	__backprop_o(p, m, target);
	update(p, m, lr);

	int i = ptr->n_hlayers;

	while(i) {
		__backprop_h(p, m, c);
		update(m, c, lr);

		p = m, m = c, i--;

		switch(i) {
			case 0:
				c = NULL;
				break;
			case 1:
				c = ptr->layer[INPUT];
				break;
			default:
				c = ptr->hlayer[i-2];
				break;
		}
	}

	p = m = c = NULL;
}
