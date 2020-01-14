#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
	t_list *cur = *list;

	if (*list  == 0) {
		*list = mx_create_node(data);
		return;
	}
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = mx_create_node(data);
	cur = cur->next;
}
