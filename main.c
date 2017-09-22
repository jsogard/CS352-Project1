#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#include "utils.h"
#include "history.h"


int main(void){
	char *args[MAX_WORD_COUNT + 1]; 
	char user_command[MAX_LINE_LENGTH];
	int run = 1, be_concurrent;
	history *hist = new_history();
	args[MAX_WORD_COUNT] = NULL;

	while(run){
		printf("osh>");
		fgets(user_command, MAX_LINE_LENGTH, stdin);

		parse_words(user_command, args);

		// display history
		if(strcmp(args[0], "history") == 0){
			history_to_string(hist);
		}
		// exit program
		else if(strcmp(args[0], "exit") == 0){
			run = 0;
			free_history(hist);
		}
		// execute a command
		else{

			// TODO check if history argument

			add_log(hist, user_command);
			be_concurrent = check_concurrency(args);

			// make child process execute command
			if(fork() == 0){

				if(execute_command(args) != 0){
					printf("Invalid command");
				}
			}
			// parent process
			else{
				if(be_concurrent)
					wait(NULL);
			}

		}
	
	}

	return 0;
}