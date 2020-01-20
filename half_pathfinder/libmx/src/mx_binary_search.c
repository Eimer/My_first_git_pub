#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
	int left = 0;
	int right = size - 1;
	int search = -1;
	int mid = (left + right) / 2;
	int i = 0;
	*count = 0;
	while(left <= right) {
		mid = (left + right) / 2;
		if(mx_strcmp(arr[mid], s) == 0) {
			search = mid;
			i++;
			*count = i;
			break;
		}
		else if(mx_strcmp(s, arr[mid]) == -1) {
				right = mid - 1;
		}
		else {
			left = mid + 1;
		}
		i++;
	}
return search;
}
