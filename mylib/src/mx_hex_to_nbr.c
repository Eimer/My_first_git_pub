unsigned long t_pow(unsigned long n, int pow) {
        int check = 1;
        unsigned long buffer = n;
        if (n < 0) {
                n = n * -1;
                check = -1;
        }
        if(pow == 0) {
                return 1;
        }
        else if (pow > 0)
        for(int i = 0; i < pow - 1; i++) {
                n = n * buffer;
        }
        return n * check;
}

unsigned long mx_hex_to_nbr(const char *hex) {
	int i = 0;
	int j = 0;
	unsigned long res = 0;
	while(hex[i]) {
		i++;
	}
	j = i;
	j--;
	for(int q = 0; q < i; q++) {
		if(hex[q] >= 48 && hex[q] <= 57) {
			res = res + ((hex[q] - 48) * (t_pow(16, j)));
		}
		else if(hex[q] >= 65 && hex[q] <= 70){
			res = res + (((unsigned long)(hex[q] - 65) + 10) * (t_pow(16, j)));
		}
		else if(hex[q] >= 97 && hex[q] <= 102) {
			res = res + ((unsigned long)(hex[q] - 97) + 10) * (t_pow(16, j));
		}
	j--;
	}
	return res;
}
