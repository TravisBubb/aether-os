OBJDIR = ../../../obj/kernel/logging
LOGGING_AR = $(OBJDIR)/logging.a
OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(wildcard *.c))

CFLAGS += -c

.PHONY: all clean

all: $(LOGGING_AR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ $<

$(LOGGING_AR): $(OBJS)
	$(AR) rcs $@ $^

clean:
	rm -rf $(OBJDIR)
