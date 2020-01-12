#include "../inc/libmx.h"

void mx_del_strarr(char ***arr) {
		char **buffer = *arr;
		for (int i = 0; buffer[i]; i++)	{
			free(buffer[i]);
			buffer[i] = NULL;
		}
	free(*arr);
	*arr = NULL;
}
