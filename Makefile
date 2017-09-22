OBJECTS = main.o utils.o history.o
CC = gcc
CFLAGS = -Werror -Wall -g -c

all: $(OBJECTS)
	$(CC) -o cs352 $(OBJECTS)

%.o: %.c %.h
	$(CC) $(CFLAGS) $<

main.o: main.c utils.h history.h
	$(CC) $(CFLAGS) main.c

clean:
	rm -rf *~ *.o