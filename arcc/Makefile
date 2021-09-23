SRCDIR = src/
INCDIR = include/
BINDIR = bin/

CC = gcc
CFLAGS = -I$(INCDIR)
TARGETS = arcc

all: $(TARGETS)

arcc: $(SRCDIR)*.c
	$(CC) $(CFLAGS) $? -o $(BINDIR)$@

clean:
	cd $(BINDIR) && rm *.o *.out $(TARGETS)
