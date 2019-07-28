void mx_printstr(const char *s);
void mx_printchar(char c);

static void my_func(int map_length, int map_width, int i, int j) {
	if((i == 0 && j == 0)
		|| (i == map_length + 1 && j == 0)){
			mx_printstr("<=");
	}
	else if ((j == map_width + 1 && i == map_length + 1)
			|| (j ==  map_width + 1  && i == 0)){
				if(map_width != 1){
					mx_printchar('=');
				}
				mx_printchar('>');
	}
	else if ((j != 1) && (j != map_width)){
			mx_printchar('-');
    }
}

void race00(int map_length, int map_width,int one_y, int one_x) {
    int i,j;
if(map_length > 0 && map_width > 0 && one_y > 0 && one_x > 0 && one_y <= map_length && one_x <= map_width) {
    for(i = 0;i <= map_length + 1; i++) {
        for(j = 0; j <= map_width + 1; j++) {
            if(i == 0 || i == map_length + 1 ) {
                my_func(map_length, map_width, i, j);
            }
            else if(j == 0 || j == map_width + 1) {
                        if(i % 2 == 0) {
                            mx_printchar('+');
                        }
                        else {
                            mx_printchar('*');
                        }
            }
            else if ( i == one_y + 1 && j == one_x + 1) {
                mx_printchar('1');
            }
            else {
				mx_printchar('0');
			}
		}
	mx_printchar('\n');
	}
}
}
