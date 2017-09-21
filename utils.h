#ifndef UTILS_H
#define UTILS_H

#include <errno.h>

#define MAX_LINE_LENGTH 80 /* maximum length of a command line */
#define MAX_WORD_COUNT MAX_LINE_LENGTH/2


// define the exit codes for argument interpretation
#define EXIT_CODE_QUIT 			100
#define EXIT_CODE_CONCURRENT 	101
#define EXIT_CODE_NONCONCURRENT 102
#define EXIT_CODE_OKAY			103


// parses `entire_line` into `words` delimited by " " and returns highest index + 1
int parse_words(char *entire_line, char *words[]);

int execute_command(char *args[]);

int check_concurrency(char *args[]);

#endif