#include "../inc/libmx.h"

static char *cstatic(const char *s1, const char *s2) {
	int k = 0;
	int i = 0;
	int line1 = mx_strlen(s1);
	int line2 = mx_strlen(s2);
	char *new =	mx_strnew(line1+line2);

	for (i = 0; i < line1; i++)
		new[i] = s1[i];
	for (i = line1; i < line2 + line1; i++) {
		new[i] = s2[k];
		k++;
	}
	return new;
}

char *mx_strjoin(const char *s1, const char *s2) {
	char *new = NULL;

	if (s1 == NULL && s2 == NULL) {
		return NULL;
	}
	if (s2 == NULL) {
		new = mx_strdup(s1);
		return new;
	}
	if (s1 == NULL) {
		new = mx_strdup(s2);
		return new;
	}
	new = cstatic(s1, s2);
	return new;
}
