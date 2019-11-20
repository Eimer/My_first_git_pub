#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
	char *res_str;
	int len;
	len = mx_strlen(str);
	res_str = mx_strnew(len);
	res_str = mx_strcpy(res_str, str);
	return res_str;
}
