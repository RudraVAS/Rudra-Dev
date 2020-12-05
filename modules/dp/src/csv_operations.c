/**
 * TODO[OPTIMIZATION]: Create a macro that check the delimiters on compile
 *	time and change the code accordingly, making less switch-cases.
 */

#include <stdio.h>
#include <assert.h>
#include "../include/rudra/dp/csv_operations.h"
#include "../include/rudra/dp/vector.h"
#include "../include/rudra/dp/xalloc.h"

#define USE_XALLOC	1

#define DEBUG printf("A\n");

#define __check(SEP_TOKEN, SEP)                         \
	case SEP_TOKEN:                                 \
		switch(__delimiter & SEP) {             \
		case 0:                                 \
			goto csv_input;                 \
		default:                                \
			vec_push(__tbuffer, '\0');      \
			vec_push(__cmatrix, __tbuffer); \
			__col++;                        \
			__tbuffer = NULL;               \
		}                                       \
		break;

/**
 * For the future additions/patches, please keep in mind the
 * following ranges for the states:
 *
 *	+=======================+===============+===============+
 *	|	data type	|	memory	|	range	|
 *	+-----------------------+---------------+---------------+
 *	|	unsigned char	|	1 B	|	[0~7]	|
 *	|	uint16_t	|	2 B	|	[0~15]	|
 *	|	uint32_t	|	4 B	|	[0~31]	|
 *	|	uint64_t	|	8 B	|	[0~63]	|
 *	+=======================+===============+===============+
 */

/**
 * read_csv: returns a string in matrix format of a csv file
 *
 * @__fname: file name(*.csv)
 * @__delimiter: seperating basis. Current supported constraints:
 *	~ TAB
 *	~ COMMA
 *	~ SEMICOLAN
 *	~ SPACE
 */
char **read_csv(char *__fname, unsigned char __delimiter)
{
	FILE *__fptr = fopen(__fname, "r");

	if (!__fptr) {
		return NULL;
	}

	char **__cmatrix = NULL;
	char *__tbuffer = NULL;
//	char *tmp_buffer = NULL;
	char f = 0;
	char exit_now = 0;

	TYPE tmp;
	char __ch = getc(__fptr);
	unsigned long __col = 0;

	while (__ch != EOF) {
//		printf("%c\n", __ch);
		switch (__ch) {
			__check(__TAB, TAB);
			__check(__COMMA, COMMA);
			__check(__SEMICOLAN, SEMICOLAN);
			__check(__SPACE, SPACE);

		case '\n':
		      check_again:
			vec_push(__tbuffer, '\0');
			vec_push(__cmatrix, __tbuffer);

			__col++;

			if (!f) {
				vec_col_inc_man(__cmatrix, __col);
				f = 1;
			} else {
				assert(vec_col(__cmatrix) == __col);
			}

			__tbuffer = NULL;

			__col = 0;
			vec_row_inc(__cmatrix);
			break;

		default:
		      csv_input:
			vec_push(__tbuffer, __ch);
			break;
		}

		if (exit_now)
			goto coffin;
		__ch = getc(__fptr);
	}

	if (__tbuffer) {
		exit_now = 1;
		goto check_again;
	}

      coffin:
	fclose(__fptr);

	return __cmatrix;
}

/**
 * f2matrix: returns a matrix(TYPE) for the given csv file name.
 *
 * @fname: file name(*.csv)
 * @delimiter: seperating constraints. Currently supported constraints:
 *	~ TAB
 *	~ COMMA
 *	~ SEMICOLAN
 *	~ SPACE
 */
TYPE **f2m(char *fname, unsigned char delimiter)
{
	char **cmatrix = read_csv(fname, delimiter);
	char *ctmp = NULL;
	char *ntmp = NULL;

	TYPE **ret = NULL;
	TYPE *tmp = NULL;
	TYPE val;

	unsigned long row = vec_row(cmatrix);
	unsigned long col = vec_col(cmatrix);
//	printf("csv->f2matrix->cmatrix[] | csv->f2matrix->tmp\n");
	for (unsigned long i = 0; i < row; i++) {
		for (unsigned long j = 0; j < col; j++) {
			val = (sizeof(TYPE) == sizeof(double)) ?
				strtod(cmatrix[i * col + j], &ctmp) :
				strtof(cmatrix[i * col + j], &ctmp);

			if(val == 0.0){
				ntmp = cmatrix[i*col+j];
				while(*ntmp!='\0') {
					if(*ntmp == '0')
						goto okay_tested;
					ntmp++;
				}
				val = 0.0/0.0;
			}
okay_tested:

			vec_push(tmp, val);
			ctmp = NULL;
		}
		vec_push(ret, tmp);
		tmp = NULL;
//		printf("%p : %p : %p\n", cmatrix[i], tmp, ret);
#ifndef USE_XALLOC
DEBUG
              free(cmatrix[i]);
DEBUG
#endif
	}
	vec_row_inc_man(ret, row);
	vec_col_inc_man(ret, col);
//	printf("csv->cmatrix\n%p\n", cmatrix);
#ifndef USE_XALLOC
DEBUG
      free(cmatrix);
DEBUG
#endif
	return ret;
}

FILE *m2f(char *fname, TYPE **matrix, unsigned long row,
	       unsigned long col)
{
	FILE *fptr = fopen(fname, "w");

	if (!fptr) {
		return NULL;
	}

	for (unsigned long i = 0; i < row; i++) {
		for (unsigned long j = 0; j < col - 1; j++) {
			fprintf(fptr, "%lf, ", matrix[i][j]);
		}
		fprintf(fptr, "%lf\n", matrix[i][col - 1]);
	}

	return fptr;
}
