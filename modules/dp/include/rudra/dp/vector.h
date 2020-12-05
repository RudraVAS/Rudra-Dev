#ifndef RUDRA_VECTOR_H
#define RUDRA_VECTOR_H

//#define __DEBUG_VEC

#ifdef __cplusplus
extern "C" {
#endif

#define MAX(_A, _B) (_A > _B ? _A : _B)
#include<stdlib.h>
#include<stddef.h>
#include<stdio.h>
#include"xalloc.h"

struct __vector {
	size_t	len,
		cap,
		row,
		col;
	char	addr[0];
};

#define __vec_hdr(v) ((struct __vector*)((char *)v - offsetof(struct __vector, addr)))
#define vec_len(v) (v ? __vec_hdr(v)->len : 0)
#define vec_cap(v) (v ? __vec_hdr(v)->cap : 0)
#define vec_row(v) (v ? __vec_hdr(v)->row : 0)
#define vec_col(v) (v ? __vec_hdr(v)->col : 0)
#define vec_col_inc(v) (v ? __vec_hdr(v)->col++ : 0)
#define vec_row_inc(v) (v ? __vec_hdr(v)->row++ : 0)
#define vec_row_inc_man(v, r) (v ? __vec_hdr(v)->row = r : 0)
#define vec_col_inc_man(v, c) (v ? __vec_hdr(v)->col = c : 0)

#ifndef __DEBUG_VEC
#define vec_push(v, x) (__vec_fit(v, 1), v[vec_len(v)] = x, __vec_hdr(v)->len++)
#else
#define vec_push(v, x) printf("%d ", x)
#endif
#define __vec_fit(v, n) (vec_len(v) + n <= vec_cap(v) ? 0 :	\
			(v = __dp_vec_grow(v, vec_len(v) + n, sizeof(*v))))

void * __dp_vec_grow(void *, size_t, size_t);

#ifdef __cplusplus
}
#endif

#endif	/* RUDRA_VECTOR_H */
