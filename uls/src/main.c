#include "../inc/uls.h"

// int main (int argc, char **argv) {
//     t_add_in_func *audit = (t_add_in_func *)malloc(sizeof(t_add_in_func));
//     audit->flags = (int *)malloc(sizeof(int) * 10);

int main(int argc, char *argv[]) {
    //mx_get_obj_info("/installer.failurerequests");
    //mx_get_obj_info("main.c");
    //mx_get_obj_info("/Applications/");
    //mx_get_obj_info("/sbin");
    //mx_get_obj_info("link_to_main");
    //mx_get_obj_info(".");
    if (argc == 1) {
        argv[1] = ".";
    }
    for (int i = 1; i < argc; i++)
        mx_output_l(argv[i]);
    argv = NULL;
    argc = 0;
}
