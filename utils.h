#ifndef UTILS_H
#define UTILS_H

#include <errno.h>

#define MAX_LINE_LENGTH 80 /* maximum length of a command line */
#define MAX_WORD_COUNT MAX_LINE_LENGTH/2


// parses `entire_line` into `words` delimited by " " and returns highest index + 1
int parse_words(char *entire_line, char *words[]);
int execute_command(char *args[]);
int check_concurrency(char *args[]);
void remove_trailing_n(char *command);

#endif