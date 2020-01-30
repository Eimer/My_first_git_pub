#include "../inc/uls.h"

void mx_get_xatr(char *obj) {
    int xatr = 0;
    acl_t plus;

    xatr = listxattr(obj, NULL, 0, 0);
    plus = acl_get_file(obj, ACL_TYPE_EXTENDED);
    if (xatr > 0) {
        printf("@");
    }
    if (plus != NULL)
        printf("+");
    acl_free(plus);
}