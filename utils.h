#ifndef UTILS_H
#define UTILS_H

#include <errno.h>
#include "consts.h"


// parses `entire_line` into `words` delimited by " " and returns highest index + 1
int parse_words(char *entire_line, char *words[]);
void parse_commands(char user_command[], char *cmd_list[]);
int execute_command(char *args[]);
int check_concurrency(char *args[]);
void remove_trailing_n(char *command);

#endif