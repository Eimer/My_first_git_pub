#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
	t_list *i;
	t_list *j;

	for (i = lst; i != NULL; i = i->next) {
		for (j = i->next; j != NULL; j = j->next) {
			if ((*cmp)(i->data, j->data) > 0) {
				t_list *new = i->data;
				i->data = j->data;
				j->data = new;
				new = NULL;
			}
		}
	}
	i = NULL;
	j = NULL;
	return lst;
}
