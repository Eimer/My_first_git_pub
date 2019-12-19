#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
	t_list *new = list;
	int count = 0;

	while (new != NULL) {
 		new = new->next;
 		count++;
	}
	new = NULL;
	return count;
}
