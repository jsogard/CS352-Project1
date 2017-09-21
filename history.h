#ifndef HISTORY_H
#define HISTORY_H


typedef struct log_cmd{
	char *command;
	int index;
	struct log_cmd *next;
	struct log_cmd *prev;
} log_cmd;

typedef struct history_log{

	int size;
	log_cmd *top;
	log_cmd *bottom;

} history_log;

void add_cmd(history_log *log, char *args[]);
void get_cmd(history_log *log, int index);
void log_to_string(history_log *log);


#endif