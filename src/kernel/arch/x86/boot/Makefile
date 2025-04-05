AS = nasm
ASFLAGS = -f elf64 -g
OBJDIR = ../../../../../obj
SOURCES = $(wildcard *.asm)
OBJECTS = $(patsubst %.asm, $(OBJDIR)/%.o, $(SOURCES))

.PHONY: all clean

all: $(OBJECTS)

$(OBJDIR)/%.o: %.asm
	@mkdir -p $(OBJDIR)
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	rm -rf $(OBJDIR)/*
