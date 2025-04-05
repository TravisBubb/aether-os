OBJDIR = ../../obj/tests/test_runner
TEST_RUNNER_AR = $(OBJDIR)/test_runner.a
OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(wildcard *.c))

CFLAGS += -c

.PHONY: all clean

all: $(TEST_RUNNER_AR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ $<

$(TEST_RUNNER_AR): $(OBJS)
	$(AR) rcs $@ $^

clean:
	rm -rf $(OBJDIR)
