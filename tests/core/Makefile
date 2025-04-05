OBJDIR = ../../obj/tests/core
CORE_AR = $(OBJDIR)/core.a
OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(wildcard *.c))

CFLAGS += -c

.PHONY: all clean

all: $(CORE_AR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ $<

$(CORE_AR): $(OBJS)
	$(AR) rcs $@ $^

clean:
	rm -rf $(OBJDIR)
