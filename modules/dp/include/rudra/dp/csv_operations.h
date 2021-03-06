#ifndef __CSV_H
#define __CSV_H

#include <stdio.h>
#include "def.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TAB		1<<0
#define COMMA		1<<1
#define SEMICOLAN	1<<2
#define SPACE		1<<3

#define __TAB		'	'
#define __COMMA		','
#define __SEMICOLAN	';'
#define __SPACE		' '

char ** read_csv (char *, unsigned char);
TYPE ** f2m (char *, unsigned char);
FILE * m2f(char *, TYPE **, unsigned long, unsigned long);

#ifdef __cplusplus
}
#endif

#endif	/* __CSV_H */
