/**
 * TODO[OPTIMIZATION]: Create a macro that check the delimiters on compile
 *	time and change the code accordingly, making less switch-cases.
 */

#include <stdio.h>
#include "csv.h"
#include "vector.h"
#include "xalloc.h"

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
char ** read_csv(char * __fname, unsigned char __delimiter) {
	FILE * __fptr = fopen(__fname, "r");

	if(!__fptr) {
		return NULL;
	}

	char ** __cmatrix = NULL;
	char * __tbuffer = NULL;
	char * tmp_buffer = NULL;

	double tmp;
	char __ch = getc(__fptr);
	unsigned long __col = 0;

	while(__ch != EOF) {
		switch(__ch) {
		case __TAB:
			switch(__delimiter & TAB) {
			case 0:
				goto csv_input;
			default:
				vec_push(__tbuffer, '\0');
				vec_push(__cmatrix, __tbuffer);
				__col++;
				__tbuffer = NULL;
			}
			break;

		case __COMMA:
			switch(__delimiter & COMMA) {
			case 0:
				goto csv_input;
			default:
				vec_push(__tbuffer, '\0');
				vec_push(__cmatrix, __tbuffer);
				__col++;
				__tbuffer = NULL;
			}
			break;

		case __SEMICOLAN:
			switch(__delimiter & SEMICOLAN) {
			case 0:
				goto csv_input;
			default:
				vec_push(__tbuffer, '\0');
				vec_push(__cmatrix, __tbuffer);
				__col++;
				__tbuffer = NULL;
			}
			break;

		case __SPACE:
			switch(__delimiter & SPACE) {
			case 0:
				goto csv_input;
			default:
				vec_push(__tbuffer, '\0');
				vec_push(__cmatrix, __tbuffer);
				__col++;
				__tbuffer = NULL;
			}
			break;

		case '\n':
			vec_push(__tbuffer, '\0');
			vec_push(__cmatrix, __tbuffer);
			__col++;
			__tbuffer = NULL;

			switch(vec_col(__cmatrix)) {
			case 0:
				vec_col_inc_man(__cmatrix, __col);
				break;

			default:
				switch(vec_col(__cmatrix) == __col) {
				case 0:
					printf("error");
					break;
				}
			}

			__col = 0;
			vec_row_inc(__cmatrix);
			break;

		default:
		csv_input:
			vec_push(__tbuffer, __ch);
			break;
		}

		__ch = getc(__fptr);
	}

	free(__fptr);

	return __cmatrix;
}

/**
 * f2matrix: returns a matrix(double) for the given csv file name.
 *
 * @fname: file name(*.csv)
 * @delimiter: seperating constraints. Currently supported constraints:
 *	~ TAB
 *	~ COMMA
 *	~ SEMICOLAN
 *	~ SPACE
 */
double ** f2matrix (char * fname, unsigned char delimiter) {
	char ** cmatrix = read_csv(fname, delimiter);
	char * ctmp = NULL;

	double ** ret = NULL;
	double * tmp = NULL;
	double val;

	unsigned long row = vec_row(cmatrix);
	unsigned long col = vec_col(cmatrix);

	for(unsigned long i = 0; i < row; i++) {
		for(unsigned long j = 0; j < col; j++) {
			val = strtod(cmatrix[i * col + j], &ctmp);
			vec_push(tmp, val);
			ctmp = NULL;
		}
		vec_push(ret, tmp);
		tmp = NULL;
	}
	vec_row_inc_man(ret, row);
	vec_col_inc_man(ret, col);

	return ret;
}

