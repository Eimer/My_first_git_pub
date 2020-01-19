#include "../inc/libmx.h"

void mx_pop_front(t_list **head) {
        t_list *tmp = *head;
        free(*head);
        tmp->next = NULL;
}
