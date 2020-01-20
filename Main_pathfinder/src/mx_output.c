#include "../inc/pathfinder.h"

static int count_len(t_arrays *main_arrays) {
    int len = 0;

    while (main_arrays->no_repeat[len]) {
        len++;
    }
    return len;
}

static int* mem_int_arr(int count) {
	int *arr = (int*)malloc(sizeof(int) * count);
	int j = 0;

	for(; j < count; j++) {
		arr[j] = 0;
	}
	return arr;
}

static t_restore *new_route(t_arrays *main_arr, int start, int finish) {
	t_restore *rt = (t_restore*)malloc(sizeof(t_restore));
    int len = count_len(main_arr);

	if(rt == NULL)
		exit(-1);
	rt->route = mem_int_arr(len);
	rt->size = 1;
	rt->count = len;
	rt->route[0] = finish;
	rt->route[1] = start;
	return rt;
}

void mx_output(t_arrays *main_arr, int start, int finish) {
	t_restore *rt = new_route(main_arr, start, finish);

	mx_btrack(main_arr, rt);
	free(rt->route);
	free(rt);
}
