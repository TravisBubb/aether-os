OBJDIR = ../obj/tests
TESTS_AR = $(OBJDIR)/tests.a

LIBS = $(OBJDIR)/test_runner/test_runner.a \
	   $(OBJDIR)/core/core.a

CFLAGS += -c

.PHONY: all clean

all: $(LIBS) $(OBJS)

$(LIBS):
	$(MAKE) -C test_runner
	$(MAKE) -C core

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C test_runner clean
	$(MAKE) -C core clean

