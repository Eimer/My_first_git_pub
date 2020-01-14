#include "../inc/pathfinder.h"

static int count_len(t_arrays *main_arrays) {
    int len = 0;

    while (main_arrays->no_repeat[len]) {
        len++;
    }
    return len;
}

static int check_nb(int n, t_arrays *main_arr, t_restore *rt) {
	int i = rt->route[rt->size];
	int j = rt->route[0];

	if (i != n) {
		if (main_arr->arr_path[i][n] == main_arr->shortest_path[j][i] - main_arr->shortest_path[j][n])
			return 1;
	}
	return 0;
}

static void pr_route(t_arrays *main_arr, t_restore *rt) {
	for (int i = 1; i <= rt->size; i++){
		mx_printstr(main_arr->no_repeat[rt->route[i]]);
		if (i < rt->size)
			mx_printstr("->");
		else
			mx_printstr("\n");
	}
}

void mx_btrack(t_arrays *main_arr, t_restore *rt) {
    int len = count_len(main_arr);

	if (rt->route[rt->size] == rt->route[0]) {
		mx_printstr(main_arr->no_repeat[rt->route[1]]);
    	mx_printstr("->");
    	mx_printstr(main_arr->no_repeat[rt->route[0]]);
    	printf("\n");
    	pr_route(main_arr,rt);
    	printf("\n");
	}
	else {
		for (int i = 0; i < len; i++) {
			if(check_nb(i, main_arr, rt)) {
				if (rt->size < rt->count) {
					rt->size++;
					rt->route[rt->size] = i;
				}
				mx_btrack(main_arr, rt);
				if(rt->size > 1)
					rt->size--;
			}
		}
	}
}
