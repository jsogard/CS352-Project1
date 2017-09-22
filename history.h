#ifndef HISTORY_H
#define HISTORY_H

#define MAX_HISTORY_LOG_SIZE 10

#include "consts.h"


typedef struct log{

	char command[MAX_LINE_LENGTH + 1];
	int index;
	struct log *next;
	struct log *prev;

} log;

typedef struct history{

	int size;
	log *top;
	log *bottom;

} history;

history *new_history();
void add_log(history *hist, char *cmd);
char *get_log(history *hist, int index);
char *get_last_log(history *hist);
char *history_to_string(history *hist);
void free_history(history *hist);


#endif