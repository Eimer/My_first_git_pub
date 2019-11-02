#include "../inc/libmx.h"
#include <stdio.h>

int mx_quicksort(char **arr, int left, int right) {
	int res = -1;
	char *mid = NULL;
	char *buffer = NULL;
	if(left <= right && left >= 0 && right >= 0) {
		mid = arr[(right - left) / 2];
		while(left <= right) {
			while(mx_strcmp(arr[left], mid) < 0)
				left++;
			while(mx_strcmp(arr[right], mid) > 0)
				right--;

			if(left <= right) {
				buffer = arr[left];
				arr[left] = arr[right];
				arr[right] = buffer;
				left++;
				right--;
				res++;
			}
		}
	}
			return res;
}
