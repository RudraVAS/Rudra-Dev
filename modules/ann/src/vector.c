#include "../include/rudra/ann/vector.h"
#define USE_XALLOC	1

void *__vec_grow(void *buffer, size_t min_size, size_t elem_size)
{
	size_t new_cap = 1 + 2 * vec_cap(buffer);
	new_cap = MAX(new_cap, min_size);
	size_t new_size =
	    offsetof(struct __vector, addr) + (elem_size * new_cap);
	struct __vector *t_buf;

	if (buffer) {
#ifdef USE_XALLOC
		t_buf = xrealloc(__vec_hdr(buffer), new_size);
#else
		t_buf = realloc(__vec_hdr(buffer), new_size);
#endif
	} else {
#ifdef USE_XALLOC
		t_buf = xmalloc(new_size);
#else
		t_buf = malloc(new_size);
#endif
		t_buf->len = 0;
		t_buf->cap = t_buf->row = 0;
	}
	t_buf->cap = new_cap;
	return t_buf->addr;
}
