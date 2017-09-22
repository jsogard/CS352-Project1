#ifndef HISTORY_H
#define HISTORY_H

#define MAX_HISTORY_LOG_SIZE 10


typedef struct log{

	char command[80];
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