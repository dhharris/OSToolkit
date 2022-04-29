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

$(ODIR)/%.o: $(SDIR)/%.c | $(ODIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(ODIR):
	mkdir -p $(ODIR)

.PHONY: clean
clean:
	$(RM) $(ODIR)/*.o example toolkit
