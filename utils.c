#include "utils.h"

#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int parse_words(char *entire_line, char *words[]){

	// keep original string unmodified
	char *temp = calloc(strlen(entire_line)+1, sizeof(char));
	strcpy(temp, entire_line);
	
	const char delim[3] = " \n";
	char *token;
	int i = 0;

	token = strtok(temp, delim);

	while(token != NULL && i < MAX_WORD_COUNT){
		words[i++] = token;

		token = strtok(NULL, delim);
	}
	words[i] = NULL;

	return i;
}

int check_concurrency(char *args[]){

	int i = 0;
	while(args[i] != NULL) i++;
	if(strcmp(args[i-1], "&") == 0){
		args[i-1] = NULL;
		return 1;
	}

	return 0;
}

int execute_command(char *args[]){

	if(execvp(args[0], args) == -1){
		return errno;
	}

	return 0;
}