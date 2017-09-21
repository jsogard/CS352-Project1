#include <stdio.h>
#include <unistd.h>

#include "utils.h"


int main(void){
	char *args[MAX_WORD_COUNT]; /* command line arguments */
	char user_command[MAX_LINE_LENGTH];
	int run = 1, i, word_count;

	while(run){
		printf("osh>");
		fgets(user_command, MAX_LINE_LENGTH, stdin);

		word_count = parse_words(user_command, args);
		for(i = 0; i < word_count; i++)
			printf("Word #%d: \"%s\"\n", i, args[i]);
	}

	return 0;
}