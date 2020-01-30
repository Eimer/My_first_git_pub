#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *list = *head;

    if (list->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    while (list->next->next != NULL) {
        list = list->next;
    }
    free(list->next);
    list->next = NULL;
    list = NULL;
}
