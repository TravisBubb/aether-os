ARCH = x86

OBJDIR = ../../../obj
ARCH_OBJ = $(OBJDIR)/arch.o

.PHONY: all clean

all: $(ARCH_OBJ)

$(ARCH_OBJ):
	$(MAKE) -C $(ARCH)

clean:
	$(MAKE) -C $(ARCH) clean
