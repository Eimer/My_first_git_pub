#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
	int result;
	int j;

	if ((str == NULL) || (sub == NULL)) {
		return -2;
	}
	if (mx_strstr(str, sub) == NULL) {
		return -1;
	}
	j = mx_strlen(mx_strstr(str, sub));
	result = mx_strlen(str) - j;
	return result;
}
