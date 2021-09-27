SRCDIR = src
INCDIR = include
BINDIR = bin
OBJDIR = obj

CC = gcc
CFLAGS = -I$(INCDIR)

_DEPS = AST.h lexer.h parser.h token.h utils.h
DEPS = $(patsubst %,$(INCDIR)/%,$(_DEPS))

_OBJ = AST.o lexer.o parser.o token.o utils.o main.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

TARGETS = $(BINDIR)/arcc

.PHONY: all clean

all: $(TARGETS)

$(BINDIR)/arcc: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm $(OBJDIR)/*.o $(BINDIR)/*
