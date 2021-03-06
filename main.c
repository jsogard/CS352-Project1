#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>

#include "utils.h"
#include "history.h"

#define CODE_EXIT 200

int do_user_command(char *user_command, history* hist){

	int be_concurrent;
	char *args[MAX_WORD_COUNT + 1]; 
	args[MAX_WORD_COUNT] = NULL;

	parse_words(user_command, args);

	// display history
	if(strcmp(args[0], "history") == 0){
		history_to_string(hist);
		return 0;
	}
	
	// exit program
	if(strcmp(args[0], "exit") == 0){
		free_history(hist);
		return CODE_EXIT;
	}

	// execute a command
	if(strcmp(args[0], "!!") == 0){
		char *cmd = get_last_log(hist);
		if(cmd){
			strcpy(user_command, cmd);
			parse_words(user_command, args);
		}
		else{
			printf("No commands in history\n");
			return 0;
		}
	}
	else if(*(args[0]) == '!'){
		int index = args[0][1] - '0';
		char *cmd = get_log(hist, index);
		if(cmd){
			strcpy(user_command, cmd);
			parse_words(user_command, args);
		}
		else{
			printf("No such command in history\n");
			return 0;
		}
	}

	add_log(hist, user_command);
	be_concurrent = check_concurrency(args);

	// make child process execute command
	if(fork() == 0){

		if(execute_command(args) != 0){
			printf("Invalid command: \"%s\"\n", user_command);
		}
		kill(getpid(), SIGTERM);
	}
	// parent process
	else{
		if(be_concurrent)
			wait(NULL);
	}
	return 0;
}


int is_whitespace(char string[]){

	char ws[4] = " \n\t";
	int i, j, white = 0;
	for(i = 0; i < MAX_LINE_LENGTH && string[i] != '\0'; i++){
		for(j = 0; j < 3; j++){
			if(string[i] == ws[j]){
				white = 1;
				break;
			}
		}
		if(white == 0) return 0;
		white = 0;
	}
	return 1;
}



int main(void){
	char user_command[MAX_LINE_LENGTH];
	char *command_list[MAX_LINE_LENGTH];
	history *hist = new_history();
	char *command;

	while(1){
		printf("osh>");
		fgets(user_command, MAX_LINE_LENGTH, stdin);
		if(is_whitespace(user_command))
			continue;

		remove_trailing_n(user_command);
		int i = 0;

		parse_commands(user_command, command_list);

		while((command = command_list[i++]) != NULL){
			do_user_command(command, hist);
		}
	}

	return 0;
}