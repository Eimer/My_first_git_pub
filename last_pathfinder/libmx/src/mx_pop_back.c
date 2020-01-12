#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    t_list *buff = mx_create_node(NULL);
    t_list *test = NULL;
    if(!(*head)) {
        *head = buff;
    }
    else {
        test = *head;
        while(test->next != NULL) {
            test = test->next;
        }
        free(test);
    }
}
