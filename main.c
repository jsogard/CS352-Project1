#include <stdio.h>
#include <unistd.h>

#include "utils.h"



int main(void){
	char *args[MAX_WORD_COUNT + 1]; /* command line arguments */
	char user_command[MAX_LINE_LENGTH];
	int keep_running = 1, return_code;

	args[MAX_WORD_COUNT] = NULL;

	while(keep_running){
		printf("osh>");
		fgets(user_command, MAX_LINE_LENGTH, stdin);

		parse_words(user_command, args);
		return_code = execute_command(args, 0);

		switch(return_code){
			case EXIT_CODE_QUIT:
				keep_running = 0;
				break;
			case EXIT_CODE_OKAY:
				break;
			default:
				printf("ERROR #%d\n", return_code);
		}
	}

	return 0;
}