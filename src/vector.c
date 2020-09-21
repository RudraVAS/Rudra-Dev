#include "vector.h"

void * __vec_grow(void * buffer, size_t min_size, size_t elem_size) {
	size_t new_cap = 1 + 2 * vec_cap(buffer);
	new_cap = MAX(new_cap, min_size);
	size_t new_size = offsetof(struct __vector, addr) + (elem_size * new_cap);
	struct __vector * t_buf;

	if(buffer) {
		t_buf = realloc(__vec_hdr(buffer), new_size);
	}
	else {
		t_buf = xmalloc(new_size);
		t_buf->len = 0;
	}
	t_buf->cap = new_cap;
	return t_buf->addr;
}
