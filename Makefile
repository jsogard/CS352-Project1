OBJECTS = main.o utils.o
CC = gcc
CFLAGS = -Werror -Wall

all: $(OBJECTS)
	$(CC) -o cs352 $(OBJECTS)

%.o: %.c %.h
	$(CC) -c $<

main.o: main.c utils.h history.h
	$(CC) -c main.c

clean:
	rm -rf *~ *.o