#include "../inc/libmx.h"

static char *cstatic(char *copy) {
	int k = 0;
	int i = 0;
	int s = mx_strlen(copy);
	char *new_copy = mx_strnew(mx_strlen(copy));

	for (int j = 0; j < s ; j++) {
		if ((copy[j] > 8 && copy[j] < 14) || (copy[j] == 32)) {
			new_copy[i] = ' ';
			if ((copy[j+1] > 8 && copy[j+1] < 14) || (copy[j+1] == 32))
				k++;
			else
				new_copy[i++] = copy[j];
		}
		else
			new_copy[i++] = copy[j];
	}
	mx_strdel(&copy);
	return new_copy;
}

char *mx_del_extra_spaces(const char *str) {
	if (str == NULL) {
		return NULL;
	}
	char *copy = mx_strtrim(str);
	char *new_copy = mx_strnew(mx_strlen(copy));

	for (int l = 0; l < mx_strlen(copy); l++) {
		if ((copy[l] > 8 && copy[l] < 14) || (copy[l] == 32))
			copy[l] = ' ';
	}
	new_copy = cstatic(copy);
	return new_copy;
}
