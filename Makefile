SHELL=/bin/sh
.SUFFIXES:
.SUFFIXES: .c .o

IDIR=./include
SDIR=./src
ODIR=./obj

CC=clang
CFLAGS=-g -Wall -Wextra -Werror -I $(IDIR)
LFLAGS=-framework ApplicationServices

BIN=toolkit
SRC=$(wildcard $(SDIR)/*.c)
OBJ=$(patsubst $(SDIR)/%.c,$(ODIR)/%.o,$(SRC))

all: $(BIN) example

$(BIN): $(filter-out $(ODIR)/example.o,$(OBJ))
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@

example: $(ODIR)/example.o
	$(CC) $(LFLAGS) -o $@ $<

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

#example.o: example.c
#	$(CC) $(CFLAGS) $^
#
#display.o: display.c
#	$(CC) $(CFLAGS) display.c
#
#input.o: input.c
#	$(CC) $(CFLAGS) input.c
#
#scripts.o: scripts.c
#	$(CC) $(CFLAGS) scripts.c
#
#mouse.o: mouse.c
#	$(CC) $(CFLAGS) mouse.c
#
#toolkit.o: toolkit.c
#	$(CC) $(CFLAGS) toolkit.c

.PHONY: clean
clean:
	$(RM) $(ODIR)/*.o example toolkit
