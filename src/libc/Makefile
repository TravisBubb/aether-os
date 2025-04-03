OBJDIR = ../../obj/libc
LIBC_AR = $(OBJDIR)/libc.a
LIBC_OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(wildcard *.c))

CFLAGS += -c -I../../include/libc

.PHONY: all clean

all: $(LIBC_AR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ $<

$(LIBC_AR): $(LIBC_OBJS)
	$(AR) rcs $@ $^

clean:
	rm -rf $(OBJDIR)
