#include "../include/rudra/dp/missing_data.h"
#include <math.h>
#include <stdlib.h>
#include "../include/rudra/dp/vector.h"

void fix_mean(unsigned * missing_col, TYPE **arr, unsigned row, unsigned col) {
	unsigned c;
	unsigned * miss_row = NULL;
	float mean = 0.0f;
	float s = 0.0f, n = 0.0f;
	for(int i = 0; i < vec_len(missing_col); i++) {
		c = missing_col[i];
		for(int j = 0; j < row; j++) {
			if(!isnan(arr[j][c])) {
				s+=arr[j][c];
				n++;
			} else {
				vec_push(miss_row, j);
			}
		}
		mean = n == 0 ? 0 : s / n;
		for(int j = 0; j < vec_len(miss_row); j++)
			arr[miss_row[j]][c] = mean;
		
		s = 0, n = 0;
	}
}

void missing_data(TYPE **arr, unsigned row, unsigned col, enum missing_options opt)
{
	unsigned * missing_row = NULL;
	for(int i = 0; i < col; i++) {
		for(int j = 0; j < row; j++) {
			if(isnan(arr[j][i])) {
				vec_push(missing_row, i);
				break;
			}
		}
	}
	if(missing_row == NULL) return;

        switch(opt) {
                case MEAN:
			fix_mean(missing_row, arr, row, col);
                        break;
                case MODE:
	//		fix_mode(arr, row, col);
                        break;
                case MEDIAN:
	//		fix_median(arr, row, col);
                        break;
        }
}