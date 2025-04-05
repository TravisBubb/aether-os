SOURCES = $(wildcard *.c)
OBJDIR = ../../obj/kernel
OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(wildcard *.c))

LIBS = $(OBJDIR)/drivers/drivers.a \
	   $(OBJDIR)/logging/logging.a

CFLAGS += -c

.PHONY: all clean deps

all: $(LIBS) $(OBJS)

$(LIBS):
	$(MAKE) -C arch
	$(MAKE) -C drivers
	$(MAKE) -C logging

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C arch clean
	$(MAKE) -C drivers clean
	$(MAKE) -C logging clean
