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

void parse_commands(char user_command[], char *cmd_list[]){

	int ptr_index = 1, cmd_index = 0;
	cmd_list[0] = user_command;
	for(; cmd_index < MAX_LINE_LENGTH && user_command[cmd_index] != '\0'; cmd_index++){
		if(user_command[cmd_index] == ';'){
			user_command[cmd_index] = '\0';
			cmd_list[ptr_index++] = &user_command[cmd_index + 1];
		}
	}
	cmd_list[ptr_index] = NULL;
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

void remove_trailing_n(char *command){

	const char delim[2] = "\n";
	strtok(command, delim);
}