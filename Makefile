CC = x86_64-elf-gcc
LD = x86_64-elf-ld
AS = x86_64-elf-as
GDB = x86_64-elf-gdb

CFLAGS = -ffreestanding -O2 -Wall -Wextra -g
LDFLAGS = -T src/boot/linker.ld

# Output files
BUILD_DIR = build
KERNEL_BIN = $(BUILD_DIR)/kernel.bin

# Source files
SRC = src/kernel/main.c
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))

# Default target
all: $(KERNEL_BIN)

# Compile source files
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Link everything
$(KERNEL_BIN): $(OBJS)
	$(LD) -o $(KERNEL_BIN) $(OBJS) $(LDFLAGS)

# Debugging mode with GDB
debug: all

# Clean build files
clean:
	rm -rf $(BUILD_DIR)/*

