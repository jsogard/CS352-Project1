#include "utils.h"

#include <string.h>


int parse_words(char *entire_line, char *words[]){
	
	const char delim[3] = " \n";
	char *token;
	int i = 0;

	token = strtok(entire_line, delim);

	while(token != NULL && i < MAX_WORD_COUNT){
		words[i++] = token;

		token = strtok(NULL, delim);
	}

	return i;
}