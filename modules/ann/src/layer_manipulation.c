#include "rudra/ann/layer_manipulation.h"
#include "rudra/ann/structure.h"
#include "rudra/ann/activation.h"
#include "rudra/ann/xalloc.h"
#include <time.h>
#include <stdio.h>
#include <string.h>


void varset(double *ptr, unsigned size, double c)
{
	for (unsigned i = 0; i < size; i++)
		ptr[i] = c;
}

void rand_varset(double *ptr, unsigned size)
{
	for (unsigned i = 0; i < size; i++)
		ptr[i] = (rand() % 1000) / 1000.0;
}


void def_set(struct __layer *ptr, unsigned wr, unsigned wc)
{
	ptr->n_nodes = wc;
	ptr->wc = wc;
	ptr->wr = wr;
	ptr->alpha = 0;
	ptr->act_code = SIGMOID;
	ptr->nor_code = NORMALIZE_Z;

	ptr->bias = (rand() % 1000) / 1000.0;

	ptr->unactiv_nodes = malloc(sizeof(double *) * wc);
	ptr->nodes = malloc(sizeof(double *) * wc);
	for (int i = 0; i < wc; i++) {
		ptr->unactiv_nodes[i] = malloc(sizeof(double));
		ptr->nodes[i] = malloc(sizeof(double));
		ptr->unactiv_nodes[i][0] = 0;
		ptr->nodes[i][0] = 0;
	}

	if (wr) {
		ptr->weights = malloc(sizeof(double *) * wr);
//		ptr->df = malloc(sizeof(double *) * wr);
		for (int i = 0; i < wr; i++) {
			ptr->weights[i] = malloc(sizeof(double) * wc);
//			ptr->df = malloc(sizeof(double) * wc);
			rand_varset(ptr->weights[i], wc);
		}
	} else {
		ptr->wc = 0;
	}

	ptr->d1 = malloc(sizeof(double) * ptr->n_nodes);
	ptr->d2 = malloc(sizeof(double) * ptr->n_nodes);
	ptr->d4 = malloc(sizeof(double) * ptr->n_nodes);

	for(int i = 0; i < ptr->n_nodes; i++) {
		ptr->d1[i] = malloc(sizeof(double));
		ptr->d2[i] = malloc(sizeof(double));
		ptr->d4[i] = malloc(sizeof(double));
	}

	ptr->d3 = ptr->df = NULL;
}

struct ann *init(unsigned n_inputs, unsigned n_outputs)
{
	srand(time(0));
	struct __layer *in = malloc(sizeof(struct __layer));
	struct __layer *out = malloc(sizeof(struct __layer));

	def_set(in, n_outputs, n_inputs);
	def_set(out, 0, n_outputs);

	struct ann *ret = malloc(sizeof(struct ann));

	ret->n_hlayers = 0;
	ret->layer[INPUT] = in;
	ret->layer[OUTPUT] = out;
	ret->hlayer = NULL;

	in = out = NULL;
	return ret;
}

void re_set(struct __layer *ptr, unsigned wr, unsigned wc)
{
	for (int i = 0; i < ptr->wr; i++)
		free(ptr->weights[i]);
	free(ptr->weights);

	ptr->wr = wr;
	ptr->wc = wc;
	ptr->weights = malloc(sizeof(double *) * wr);
	for (int i = 0; i < wr; i++) {
		ptr->weights[i] = malloc(sizeof(double) * wc);
		rand_varset(ptr->weights[i], wc);
	}
}

struct ann *add_layer(struct ann *ptr, unsigned n_nodes)
{
	struct __layer *clayer = ptr->n_hlayers ?
	    ptr->hlayer[ptr->n_hlayers - 1] : ptr->layer[INPUT];

	re_set(clayer, n_nodes, clayer->wc);

	clayer = NULL;

	struct __layer *hlayer = malloc(sizeof(struct __layer));

	def_set(hlayer, ptr->layer[OUTPUT]->n_nodes, n_nodes);

	ptr->n_hlayers++;
	ptr =
	    realloc(ptr,
		    sizeof(struct ann) +
		    sizeof(struct __layer *) * ptr->n_hlayers);

	ptr->hlayer = (void *) ((char *) ptr + sizeof(struct ann));

	ptr->hlayer[ptr->n_hlayers - 1] = hlayer;
	hlayer = NULL;

	return ptr;
}

void print_layer(char * lname, struct __layer * ptr, char s, char e) {
//	printf("%d", strlen(lname));
	printf("%s", s ? "+===============================================================+\n" : "");
	printf("| %s%s", lname, strlen(lname) < 6 ? "\t" : "");
	printf("\t[n_nodes/wr/wc]\t[%hu/%hu/%hu]\t\t\n", ptr->n_nodes, ptr->wr, ptr->wc);
	printf("|\t\t[act/nor]_code\t[%d/%d]\t\t\n", ptr->act_code, ptr->nor_code);
	printf("|\t\talpha\t\t%lf\t\n", ptr->alpha);
	printf("|\t\tbias\t\t%lf\t\n|\n", ptr->bias);
	printf("|\t\tnodes\t\t");
	for(int i = 0; i < ptr->n_nodes; i++)
		printf("%lf\n%s", ptr->nodes[i][0], i < ptr->n_nodes-1 ? "|\t\t\t\t" : "|\n");
	printf("|\t\tweights\t\t");
	for(int i = 0; i < ptr->wr; i++) {
		for(int j = 0; j < ptr->wc; j++) {
			printf("%lf ", ptr->weights[i][j]);
		}
		printf("\n%s", i < ptr->wr-1 ? "|\t\t\t\t" : "");
	}
	printf("%s%s", ptr->wr ? "" : "\n",
			e ? "+===============================================================+\n"
			: "+---------------------------------------------------------------+\n");
}

void print_det(struct ann *ptr)
{
	print_layer("INPUT", ptr->layer[INPUT], 1, 0);
	for (unsigned i = 0; i < ptr->n_hlayers; i++) {
		print_layer("HL", ptr->hlayer[i], 0, 0);
	}
	print_layer("OUTPUT", ptr->layer[OUTPUT], 0, 1);
	printf("\n");
}


void __cleanup(struct __layer *ptr)
{
	for (unsigned i = 0; i < ptr->wr; i++) {
		free(ptr->weights[i]);
	}
	free(ptr->weights);
	for (unsigned i = 0; i < ptr->n_nodes; i++)
		free(ptr->nodes[i]);
	free(ptr->nodes);
	free(ptr);
}

void cleanup(struct ann *ptr)
{
	__cleanup(ptr->layer[INPUT]);
	__cleanup(ptr->layer[OUTPUT]);
	for (unsigned i = 0; i < ptr->n_hlayers; i++) {
		__cleanup(ptr->hlayer[i]);
	}
	free(ptr);
}
