#include <stdio.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 80 /* maximum length of a command line */


int main(void){
	char *args[MAX_LINE_LENGTH/2]; /* command line arguments */
	char user_command[MAX_LINE_LENGTH];
	int run = 1;

	while(run){
		printf("osh>");
		fgets(user_command, 80, stdin);

		printf("You wrote: %s\n", user_command);
	}

	return 0;
}