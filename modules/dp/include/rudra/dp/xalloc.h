#ifndef RUDRA_XALLOC_H
#define RUDRA_XALLOC_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

void * xmalloc(size_t __size);
void * xrealloc(void * __ptr, size_t __size);
void __garbage_collector() __attribute__ ((destructor));

#ifndef xfree
#define xfree(__ptr)				\
		do {				\
			if(__ptr!=NULL) {	\
				free(__ptr);	\
				__ptr = NULL;	\
			}			\
		} while(0)
#endif

#ifdef __cplusplus
}
#endif

#endif /* RUDRA_XALLOC_H */
