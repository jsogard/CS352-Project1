#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#include "utils.h"
#include "history.h"



int main(void){
	char *args[MAX_WORD_COUNT + 1]; /* command line arguments */
	char user_command[MAX_LINE_LENGTH];
	int keep_running = 1, return_code, be_concurrent;

	args[MAX_WORD_COUNT] = NULL;

	while(keep_running){
		printf("osh>");
		fgets(user_command, MAX_LINE_LENGTH, stdin);

		parse_words(user_command, args);
		be_concurrent = check_concurrency(args);



		if(strcmp(args[0], "exit") == 0){

			keep_running = 0;

		} else if(fork() == 0){ /* child process */

			printf("\n");
			return_code = execute_command(args);

			switch(return_code){
				case EXIT_CODE_OKAY:
					break;
				default:
					printf("ERROR #%d\n", return_code);
			}

		} else { /* parent process */

			if(be_concurrent)
				wait(NULL);

		}
	
	}

	return 0;
}