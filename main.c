#include "../inc/libmx.h"
#include <stdio.h>
#include <time.h>

bool cmp(void *a, void *b) {
    char *ta = a;
    char *tb = b;
    if(mx_strcmp(ta, tb) > 0) {
        return true;
    }
    else {
        return false;
    }
}


int main()
{	
	//TEST CASES!!!

	//mx_quicksort
	printf("%s\n", "\x1b[36mTEST FOR mx_quicksort\033[0m");
	char *sort_test[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
	if((mx_quicksort(sort_test, 0, 3)) == 2) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: {/Michelangelo/, /Donatello/, /Leonardo/, /Raphael/}, 0, 3\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: {/Michelangelo/, /Donatello/, /Leonardo/, /Raphael/}, 0, 3\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	// mx_get_char_index
	printf("%s\n", "\x1b[36mTEST FOR mx_get_char_index\033[0m");
	int res1 = mx_get_char_index("123", '2');
	int res2 = mx_get_char_index(NULL, '7');
	int res3 = mx_get_char_index("123", '7');
	if(res1 == 1) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: 123, 2\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: 123, 2\033[0m");
	}
	if(res2 == -2) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: null, 2\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: null, 2\033[0m");	
		
	}
	if(res3 == -1) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: 123, 7\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: 123, 7\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_strndup//
	printf("%s\n", "\x1b[36mTEST FOR mx_strndup\033[0m");

	if((mx_strcmp(mx_strndup("122", 2), "123") < 0)) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: 123, 4\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: 123, 4\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	// //mx_strndup//
	printf("%s\n", "\x1b[36mTEST FOR mx_strcpy\033[0m");
	char src[]="12345226789";
	char dst[]= "1111111111";
	mx_strncpy(dst, src, 3);
	if(mx_strlen(dst) == 10) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: 12345226789, 1111111111, 3\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: 12345226789, 1111111111,3\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_strcat//
	printf("%s\n", "\x1b[36mTEST FOR mx_strcat\033[0m");
	char test_s1[20] = "hello";
	char test_s2[] = "there";
	if((mx_strlen(mx_strcat(test_s1, test_s2))) == 10) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: hello, there\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: hello, there\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_strstr//
	printf("%s\n", "\x1b[36mTEST FOR mx_strcpy\033[0m");
	if (mx_strstr("12a34", "2a1") == NULL) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: 12a34, 2a1\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: 12a34, 2a1\033[0m");
	}
	if (mx_strstr("1234", "23") != NULL) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: 1234, 23\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: 1234, 23\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_get_substr_index//
	printf("%s\n", "\x1b[36mTEST FOR mx_get_substr_index\033[0m");
	
	if(mx_get_substr_index("McDonalds", "Don") == 2) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: McDonalds, Don\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: McDonalds, Don\033[0m");
	}
	if(mx_get_substr_index("McDonalds Donuts", "on") == 3) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: McDonalds, Donuts\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: McDonalds, Donuts\033[0m");
	}
	if (mx_get_substr_index("McDonalds", "Donatello") == -1) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: McDonalds, Donatello\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: McDonalds, Donatello\033[0m");
	}
	if(mx_get_substr_index("McDonalds", NULL) == -2) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: McDonalds, null\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: McDonalds, null\033[0m");
	}
	if(mx_get_substr_index(NULL, "Don") == -2) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: null, Don\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: null, Don\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_count_substr//
	printf("%s\n", "\x1b[36mTEST FOR mx_count_substr\033[0m");
	if(mx_count_substr("yo, yo, yo Neo", "yo") == 3) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: yo, yo, yo Neo, yo\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: yo, yo, yo Neo, yo\033[0m");
	}
	if(mx_count_substr("yo, yo, yo Neo", NULL) == -1) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: yo, yo, yo Neo, NULL\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: yo, yo, yo Neo, NULL\033[0m");
	}
	if(mx_count_substr(NULL, "yo") == -1) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: NULL, yo\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: NULL, yo\033[0m");
	}
	if(mx_count_substr("he  l  o", "lo") == 0) {
		printf("%s\n", "\x1b[33mOK FOR INPUTS: \"he  l  o\", lo, if answer is 0\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: \"he  l  o\", lo\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_count_words//
	printf("%s\n", "\x1b[36mTEST FOR mx_count_words\033[0m");
	if(mx_count_words(" follow * the white rabbit ", '*') == 2) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: / follow * the white rabbit /, *\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: / follow * the white rabbit /, *\033[0m");
	}
	if (mx_count_words(" follow * the white rabbit ", ' ') == 5) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: / follow * the white rabbit /, / /\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: / follow * the white rabbit /, / /\033[0m");
	}
	if(mx_count_words(NULL, ' ') == -1) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: null, / /\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: FOR INPUTS: null, / /\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_strtrim//
	printf("%s\n", "\x1b[36mTEST FOR mx_strtrim\033[0m");
	if(mx_strlen(mx_strtrim("\t\t\t 1223")) == 4) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: \"\\t\\t\\t 1223\"\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: \"\\t\\t\\t 1223\"\033[0m");
	}
	if(mx_strtrim(NULL) == NULL) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: NULL\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: NULL\033[0m");
	}
	if(mx_strlen(mx_strtrim("1223")) == 4) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: 1223\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: 1223\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_del_extra_spaces
	printf("%s\n", "\x1b[36mTEST FOR mx_del_extra_spaces\033[0m");
	if(mx_strlen(mx_del_extra_spaces("\f  My name...   \r  is   Neo  \t\n")) == 17) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: \"\\f  My name... is Neo  \\t\\n\"\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: \"\\f  My name... is Neo  \\t\\n\"\033[0m");
	}
	if(mx_del_extra_spaces(NULL) == NULL) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: NULL\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: NULL\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_strsplit
	printf("%s\n", "\x1b[36mTEST FOR mx_strsplit\033[0m");
	char **test = mx_strsplit("**Good bye,**Mr.*Anderson.****", '*');
	if(mx_strcmp(test[0], "Good bye,") == 0) {
		printf("%s", "Good bye,");
		printf("%s", "\x1b[32m OK\033[0m");
	}
	else {
		printf("%s", "Good bye,");
		printf("%s", "\x1b[31m FILED\033[0m");
	}
	printf("%c", '\n');
	if(mx_strcmp(test[1], "Mr.") == 0) {
		printf("%s", "Mr.");
		printf("%s", "\x1b[32m OK\033[0m");
	}
	else {
		printf("%s", "Mr.");
		printf("%s", "\x1b[31m FILED\033[0m");
	}
	printf("%c", '\n');
	if(mx_strcmp(test[2], "Anderson.") == 0) {
		printf("%s", "Anderson.");
		printf("%s", "\x1b[32m OK\033[0m");
	}
	else {
		printf("%s", "Anderson.");
		printf("%s", "\x1b[31m FILED\033[0m");
	}
	printf("%c", '\n');
	printf("%c", '\n');
	sleep(1);
	//mx_strjoin
	printf("%s\n", "\x1b[36mTEST FOR mx_strjoin\033[0m");
	if(mx_strcmp("dodge this", mx_strjoin("dodge ", "this")) == 0) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: \"dodge \", \"this\"\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: \"dodge \", \"this\"\033[0m");
	}
	if(mx_strcmp("dodge ", mx_strjoin("dodge ", NULL)) == 0) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: \"dodge \", NULL\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: \"dodge \", NULL\033[0m");
	}
	if(mx_strcmp("this", mx_strjoin(NULL, "this")) == 0) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: NULL, \"dodge \"\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: NULL, \"dodge \"\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	// mx_file_to_str
	printf("%s\n", "\x1b[36mTEST FOR mx_file_to_str\033[0m");
	if(mx_strcmp("12345", mx_file_to_str("test.txt")) == 0) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: 12345 in test.txt\033[0m");
	} else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: 12345 in test.txt\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_replace_substr
	printf("%s\n", "\x1b[36mTEST FOR mx_replace_substr\033[0m");
	if(mx_strcmp("McDonuts", mx_replace_substr("McDonalds", "alds", "uts")) == 0) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS: \"McDonalds\", \"ald\", \"1\"\033[0m");
	} 
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: \"McDonalds\", \"ald\", \"1\"\033[0m");
	}
	if(mx_replace_substr("McDonalds", "alds", NULL) == NULL) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS:  \"McDonalds\", \"alds\", NULL\033[0m");
	} 
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: \"McDonalds\", \"alds\", NULL\033[0m");
	}
	if(mx_replace_substr("McDonalds", NULL, "123") == NULL) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS:  \"McDonalds\", NULL, \"123\"\033[0m");
	} 
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS: \"McDonalds\", \"alds\", NULL\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_memset
	printf("%s\n", "\x1b[36mTEST FOR mx_memset\033[0m");
	char test1[] = "die";
	char test2[] = "die";
	const char test3[] = "1";
	if(mx_strcmp(test1, mx_memset(test1, 97, 1)) == 0) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS:  \"die\", 97, 1\033[0m");	
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS:  \"die\", 97, 1\033[0m");
	}
	printf("%c", '\n');
	printf("%s\n", "\x1b[36mTEST FOR mx_memspy\033[0m");
	if(mx_strcmp("1ie", mx_memcpy(test2, test3, 1)) == 0) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS:  \"die\", \"die\", 1\033[0m");	
	}
	else {
		printf("%s\n", "\x1b[31mFILED OR INPUTS:  \"die\", \"die\", 1\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_memccpy
	printf("%s\n", "\x1b[36mTEST FOR mx_memccpy\033[0m");
	char d[] = "98765432198";
    char s[] = "0123456789";	
	if(mx_memccpy(d, s, 's', 7) == NULL) {
		printf("%s\n", "\x1b[32mtest1 OK\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED test1\033[0m");
	}
	char u[] = "98765432198";
    char v[] = "0123456789";
	if(mx_strcmp("32198", mx_memccpy(u, v, '5', 7)) == 0) {
		printf("%s\n", "\x1b[32mtest2 OK\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED test2\033[0m");
	}
	printf("%c", '\n');

	//mx_memcmp
	printf("%s\n", "\x1b[36mTEST FOR mx_memcmp\033[0m");
	if(mx_memcmp("1234", "1a34", 2) != 0) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS:  \"1234\", \"1a34\", 2\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS:  \"1234\", \"1a34\", 2\033[0m");
	}
	if(mx_memcmp("1234", "1234", 200) == 0) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS:  \"1234\", \"1234\", 200\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS:  \"1234\", \"1234\", 200\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_memchr
	printf("%s\n", "\x1b[36mTEST FOR mx_memchr\033[0m");
	if(mx_strcmp("234", mx_memchr("1234", 50, 4)) == 0) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS:  \"1234\", 50, 4\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS:  \"1234\", 50, 4\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_memrchr
	printf("%s\n", "\x1b[36mTEST FOR mx_memrchr\033[0m");
	if(mx_strcmp("ity", mx_memrchr("Trinity", 'i', 7)) == 0) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS:  \"Trinity\", \'i\', 7\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS:  \"Trinity\", \'i\', 7\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_memmem
	printf("%s\n", "\x1b[36mTEST FOR mx_memmem\033[0m");
	if(mx_strcmp("123taa", (mx_memmem("aaa123taa", 7, "123", 3))) == 0) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS:  \"aaa123taa\", 7,  \"123\", 3\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS:  \"aaa123taa\", 7,  \"123\", 3\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_memmove
	printf("%s\n", "\x1b[36mTEST FOR mx_memmove\033[0m");
	char test_dst1 []= "1234567890";
	mx_memmove(&test_dst1[4], &test_dst1[3], 3);
	if (mx_strcmp("1234456890", test_dst1) == 0) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS:  \"1234567890\", \"567890\",  \"4567890\", 3\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS:  \"1234567890\", \"567890\",  \"4567890\", 3\033[0m");
	}
	printf("%c", '\n');
	sleep(1);
	//mx_realoc
	printf("%s\n", "\x1b[36mTEST FOR mx_realoc\033[0m");
	char *test_relloc = (char *) malloc(10 * sizeof(char));
	for (size_t i = 0; i < 10; i++) {
		test_relloc[i] = 'a';
	}
	char *test_relloc1 = mx_realloc(test_relloc, 120);
	for (size_t i = 0; i < 120; i++)
	{
		test_relloc1[i] = '1';
	}
	if(mx_strlen(test_relloc1) == 120) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS:  \"aaaaaaaaaa\", 120\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS:  \"aaaaaaaaaa\", 120\033[0m");
	}
	printf("%c", '\n');
	
	printf("%s\n", "\x1b[36mTEST FOR mx_create_node\033[0m");
	
	t_list *test_tlist1 = mx_create_node("123");
	if(mx_strcmp("123", test_tlist1->data) == 0) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS:  \"123\"\033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS:  \"123\"\033[0m");
	}
	printf("%c", '\n');
	
	t_list *node1 = mx_create_node("2");
	t_list *node2 = mx_create_node("1");
	node1->next = node2;
	node2->next = NULL;
	sleep(1);
	// while(node1->next != NULL) {
	// 	printf("%s ", node1->data);
	// 	node1 = node1->next;
	// }
	// printf("%s ", node1->data);
	//mx_pop_back(&node1);

	printf("%s\n", "\x1b[36mTEST FOR mx_list_size\033[0m");
	if(mx_list_size(node1) == 2) {
		printf("%s\n", "\x1b[32mOK FOR INPUTS:  two nodes \033[0m");
	}
	else {
		printf("%s\n", "\x1b[31mFILED FOR INPUTS:  two nodes \033[0m");
	}
	printf("%c", '\n');
	
	printf("%s\n", "\x1b[36mTEST FOR mx_sort_list\033[0m");
	printf("%s\n", "INPUTS: 2,1");
	printf("%s", "OUTPUTS: ");
	mx_sort_list(node1, cmp);
	while(node1->next != NULL) {
		printf("%s ", node1->data);
		node1 = node1->next;
	}
	printf("%s ", node1->data);
		
	return 0;
}
