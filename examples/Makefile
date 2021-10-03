SRCDIR = C
ASMDIR = asm
BINDIR = bin

_SRC = retint.c
SRC = $(addprefix $(SRCDIR)/,$(_SRC))

_BINS = retint
BINS = $(addprefix $(BINDIR)/,$(_BINS))

.PHONY: all gcc_asm clean asm bin arcc_asm gcc_link

all: gcc_asm arcc_asm gcc_link

gcc_asm: CC := gcc
gcc_asm: CFLAGS := -S -O3 -fno-asynchronous-unwind-tables
gcc_asm: $(patsubst $(SRCDIR)/%.c,$(ASMDIR)/%_gcc.s,$(SRC))

arcc_asm: CC := ./arcc
arcc_asm: $(patsubst $(SRCDIR)/%.c,$(ASMDIR)/%_arcc.s,$(SRC))

gcc_link: CC := gcc
gcc_link: $(BINS)

$(ASMDIR)/%_gcc.s: $(SRCDIR)/%.c | asm
	$(CC) $(CFLAGS) $< -o $@

$(ASMDIR)/%_arcc.s: $(SRCDIR)/%.c
	$(CC) $< -o $@

$(BINDIR)/%: $(ASMDIR)/%_arcc.s | bin
	$(CC) $< -o $@

asm:
	mkdir -p $(ASMDIR)

bin:
	mkdir -p $(BINDIR)

clean:
	rm -f $(ASMDIR)/*.s $(BINDIR)/*