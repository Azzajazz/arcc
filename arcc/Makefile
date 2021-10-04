SRCDIR = src
INCDIR = include
BINDIR = bin
OBJDIR = obj

CC = gcc
CFLAGS = -I$(INCDIR)

_DEPS = AST.h lexer.h parser.h token.h utils.h asm_generator.h list.h
DEPS = $(addprefix $(INCDIR)/,$(_DEPS))

_OBJS = AST.o lexer.o parser.o token.o utils.o main.o asm_generator.o list.o
OBJS = $(addprefix $(OBJDIR)/,$(_OBJS))

BINS = $(BINDIR)/arcc

.PHONY: all clean

all: $(OBJS) $(BINS)

$(BINDIR)/arcc: $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@
	cp $@ ../examples

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm $(OBJDIR)/*.o $(BINDIR)/*
