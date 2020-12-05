/**
 * Right now I am creating a variable named '__dp_addr_list' which contains
 * each and every address of heap which is allocated in the program
 * with x[m/re]alloc, but the issue here is that it is global, so I
 * don't know if it is okay as it can be easily manipulated by the
 * d3buggers out there. I just don't know.
 */

#include "../include/rudra/dp/xalloc.h"
#include <stdio.h>
unsigned long __dp_addr_cnt = 0;
void **__dp_addr_list = NULL;

void *dp_xmalloc(size_t __size)
{
	void *__ptr = malloc(__size);
//	printf("%p\n", __ptr);
	if (!__dp_addr_cnt) {
		__dp_addr_list = malloc(sizeof(void **));
	} else {
		__dp_addr_list =
		    realloc(__dp_addr_list,
			    sizeof(void **) * (__dp_addr_cnt + 1));
	}

	__dp_addr_list[__dp_addr_cnt] = __ptr;
	__dp_addr_cnt++;

	return __ptr;
}

void *dp_xrealloc(void *__ptr, size_t __size)
{
	void *__reptr = realloc(__ptr, __size);

	if (__reptr != __ptr) {
		for (unsigned long __i = 0; __i < __dp_addr_cnt; __i++) {
			if (__dp_addr_list[__i] == __ptr) {
				__dp_addr_list[__i] = __reptr;
				return __reptr;
			}
		}
	}

	return __reptr;
}

void __dp_garbage_collector()
{
	while (__dp_addr_cnt) {
		__dp_addr_cnt--;
//		printf("%ld : %p\n", __dp_addr_cnt, __dp_addr_list[__dp_addr_cnt]);
		xfree(__dp_addr_list[__dp_addr_cnt]);
	}
      out:
//	printf("%p\n", __dp_addr_list);
	xfree(__dp_addr_list);
}
