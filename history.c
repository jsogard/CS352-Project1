#include "history.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

history *new_history(){

	history *hist = (history*)malloc(sizeof(history));
	hist->size = 0;
	hist->top = NULL;
	hist->bottom = NULL;
	return hist;
}

void push(history *hist, log *hlog){

	hlog->index = hist->size + 1;
	hlog->prev = NULL;
	hlog->next = hist->top;

	if(hist->top) 
		hist->top->prev = hlog;
	else
		hist->bottom = hlog;
	hist->top = hlog;
	hist->size++;

}

void pop(history *hist){

	hist->bottom = hist->bottom->prev;
	free(hist->bottom->next);
	hist->bottom->next = NULL;
	hist->size--;
	
}

void add_log(history *hist, char *cmd){

	log *hlog = (log*)malloc(sizeof(log));
	hlog->command = calloc(strlen(cmd)+1, sizeof(char));
	strcpy(hlog->command, cmd);

	push(hist, hlog);
	if(hist->size > MAX_HISTORY_LOG_SIZE)
		pop(hist);

}


char *get_log(history *hist, int index){

	log *curr = hist->top;
	while(curr){
		if(curr->index == index)
			return curr->command;
		curr = curr->next;
	}
	return NULL;
}

char *get_last_log(history *hist){

	if(hist->top) return hist->top->command;
	return NULL;
}

char *history_to_string(history *hist){

	char *out = "";
	log *curr = hist->top;
	while(curr){
		printf("%2d: %s\n", curr->index, curr->command);
		curr = curr->next;
	}
	return out;
}

void free_history(history *hist){

	log *curr = hist->top, *tail;
	while(curr){
		tail = curr;
		curr = curr->next;
		free(tail);
	}
	free(hist);
}