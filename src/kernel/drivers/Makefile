OBJDIR = ../../../obj/kernel/drivers
DRIVERS_AR = $(OBJDIR)/drivers.a
OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(wildcard *.c))

CFLAGS += -c

.PHONY: all clean

all: $(DRIVERS_AR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ $<

$(DRIVERS_AR): $(OBJS)
	$(AR) rcs $@ $^

clean:
	rm -rf $(OBJDIR)
