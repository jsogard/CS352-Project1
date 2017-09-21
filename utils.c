#include "utils.h"

#include <string.h>
#include <unistd.h>


int parse_words(char *entire_line, char *words[]){
	
	const char delim[3] = " \n";
	char *token;
	int i = 0;

	token = strtok(entire_line, delim);

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

	if(strcmp(args[0], "exit") == 0)
		return EXIT_CODE_QUIT;

	if(execvp(args[0], args) == -1){
		return errno;
	}

	return 0;
}