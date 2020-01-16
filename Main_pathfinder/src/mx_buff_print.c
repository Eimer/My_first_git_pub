#include "../inc/pathfinder.h"

void mx_buff_print(t_arrays *main_arr, t_restore *rt) {
		mx_print_delim();
		mx_printstr("Path: ");
		mx_printstr(main_arr->no_repeat[rt->route[1]]);
    	mx_printstr(" -> ");
    	mx_printstr(main_arr->no_repeat[rt->route[0]]);
    	mx_printstr("\n");
}
