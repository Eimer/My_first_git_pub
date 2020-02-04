#include "../inc/uls.h"

void mx_get_xatr(char *obj) {
    int xatr = 0;
    acl_t plus;

    xatr = listxattr(obj, NULL, 0, XATTR_NOFOLLOW);
    plus = acl_get_file(obj, ACL_TYPE_EXTENDED);
    if (xatr > 0) {
        printf("@");
    }
    else if (plus != NULL)
        printf("+");
    else {
        printf(" ");
    }
    acl_free(plus);
}
