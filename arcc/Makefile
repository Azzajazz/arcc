SRCDIR = src/
INCDIR = include/
BINDIR = bin/

CC = gcc
CFLAGS = -I$(INCDIR)
TARGETS = $(BINDIR)arcc

all: $(TARGETS)

$(BINDIR)arcc: $(SRCDIR)*.c
	$(CC) $(CFLAGS) $? -o $@

clean:
	cd $(BINDIR) && rm *.o *.out $(TARGETS)
