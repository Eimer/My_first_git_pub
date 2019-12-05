#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
 	int count = 1;
 	unsigned long buff = nbr;
 	char *res = NULL;
 	char *res1 = NULL;
 	while(nbr / 16 > 0) {
 		nbr = nbr / 16;
 		count++;
 	}
 	res = (char *) malloc(count + 1);
 	res1 = (char *) malloc(count + 1);
 	for (int i = 0; i < count; i++) {
 		if((buff % 16 >= 0) && (buff % 16) <= 9) {
 			res[i] = buff % 16 + 48;
 		}
 		else if((buff % 16 >= 10) && (buff % 16) <= 15) {
 				res[i] = buff % 16 + 87;
 		}
 		buff = buff / 16;
 	}
 	res[count] = '\0';
 	for (int i = 0; i < count; i++) {
 		res1[count - i - 1] = res[i];
 	}
 	res1[count] = '\0';
 	return res1;
}
