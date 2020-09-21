/**
 * Right now I am creating a variable named '__addr_list' which contains
 * each and every address of heap which is allocated in the program
 * with x[m/re]alloc, but the issue here is that it is global, so I
 * don't know if it is okay as it can be easily manipulated by the
 * d3buggers out there. I just don't know.
 */

#include "xalloc.h"
#include <stdio.h>
unsigned long __addr_cnt = 0;
void ** __addr_list = NULL;

void * xmalloc(size_t __size) {
	void * __ptr = malloc(__size);
	printf("%p\n", __ptr);
	if(!__addr_cnt) {
		__addr_list = malloc(sizeof(void **));
	}
	else {
		__addr_list = realloc(__addr_list, sizeof(void **) * (__addr_cnt + 1));
	}

	__addr_list[__addr_cnt] = __ptr;
	__addr_cnt++;

	return __ptr;
}

void * xrealloc(void * __ptr, size_t __size) {
	void * __reptr = realloc(__ptr, __size);

	if(__reptr != __ptr) {
		for(unsigned long __i = 0; __i < __addr_cnt; __i++) {
			if(__addr_list[__i] == __ptr) {
				__addr_list[__i] = __reptr;
				return __reptr;
			}
		}
	}

	return __reptr;
}

void __garbage_collector() {
	while(__addr_cnt) {
		__addr_cnt--;
		printf("%ld : %p\n", __addr_cnt, __addr_list[__addr_cnt]);
		xfree(__addr_list[__addr_cnt]);
	}
out:
	printf("%p\n", __addr_list);
	xfree(__addr_list);
}
