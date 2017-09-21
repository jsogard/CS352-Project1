#ifndef UTILS_H
#define UTILS_H

#define MAX_LINE_LENGTH 80 /* maximum length of a command line */
#define MAX_WORD_COUNT MAX_LINE_LENGTH/2

// parses `entire_line` into `words` delimited by " " and returns highest index inclusive
int parse_words(char *entire_line, char *words[]);


#endif