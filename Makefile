#FILE   : Makefile
#Author : Jean "henyxia" Wasilewski

CC=gcc
CFLAGS=-c -Wall -Wextra -Werror -std=c89 -g
LIBS=
SOURCES=main.c logger.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=testMe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clear:
	rm -f $(OBJECTS) $(EXECUTABLE)
