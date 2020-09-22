/**
 * FIXME: Pay really really really close attention to memory leaks.
 * TODO: Create a variation of allocating memory, and freeing then automatically at end.
 */
#include "layer_manipulation.h"
#include "rudra/dp/xalloc.h"
#include <stdlib.h>
#include <stdio.h>

struct ann * init(unsigned short n_inputs, unsigned short n_outputs) {
	unsigned int i_size;
	unsigned int o_size;

	i_size = sizeof(struct __layer) + sizeof(double) * (n_inputs * (1 + n_outputs));
	o_size = sizeof(struct __layer) + sizeof(double) * n_outputs;

	struct __layer * i_layer = xmalloc(i_size);
	struct __layer * o_layer = xmalloc(o_size);
	struct ann * __ann = xmalloc(sizeof(struct ann));

	i_layer->n_nodes = n_inputs;
	o_layer->n_nodes = n_outputs;
	i_layer->n_weights = n_inputs * n_outputs;
	o_layer->n_weights = 0;

	i_layer->nodes = (double *)((char *)i_layer + sizeof(struct __layer));
	o_layer->nodes = (double *)((char *)o_layer + sizeof(struct __layer));
	i_layer->weights = i_layer->nodes + i_layer->n_nodes;
	o_layer->weights = NULL;

	__ann->n_hlayers = 0;
	__ann->layer[INPUT] = i_layer;
	__ann->layer[OUTPUT] = o_layer;
	__ann->hlayer = NULL;

	return __ann;
}

char add_layer(struct ann * _ann, unsigned short n_hnodes, unsigned char act_func) {
	if(!_ann) {
		return -1;
	}
printf("%u : %u\n", _ann, &n_hnodes);
	int a, *b;
	printf("%u : %u\n", &a, b);
	_ann = xrealloc(_ann, sizeof(_ann) + sizeof(_ann->hlayer));
printf("%ld\n", sizeof(*_ann));
/*
	if(_ann->n_hlayers) {

	}
	else {
		size_t i_size;
		i_size = sizeof(struct __layer) + sizeof(double) *
			(ann->layer[INPUT]->n_nodes * (1 + n_hnodes));

		_ann->layer[INPUT]->n_weights = ann->layer[INPUT]->n_nodes * n_hnodes;
		_ann->layer[INPUT] = realloc(_ann->layer[INPUT], i_size);
	}

	size_t l_size;

	l_size = sizeof(struct __layer) +
		sizeof(double) * (n_hnodes * (1 + _ann->layer[OUTPUT]->n_nodes));

	struct __layer * hlayer = malloc(l_size);

	hlayer->n_nodes = n_hnodes;

	hlayer->nodes = (double *)((char *)hlayer + sizeof(struct __layer));
	hlayer->weights = h_layer->nodes + h_layer->n_nodes;

	_ann->n_hlayers++;*/
}

