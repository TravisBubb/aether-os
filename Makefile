CC = x86_64-elf-gcc
LD = x86_64-elf-ld
GDB = x86_64-elf-gdb
AS = nasm

CFLAGS = -ffreestanding -nostdlib -nostartfiles -mno-red-zone \
		 -O0 -Wall -Wextra -g \
		 -Iinclude/kernel \
		 -Iinclude/c \
		 -Iinclude/libc \
		 -Iinclude/sys
LDFLAGS = -T src/boot/linker.ld
ASFLAGS = -f elf64 -g

# Output files
BUILD_DIR = build
ISO_DIR = iso
GRUB_CFG_DIR = $(ISO_DIR)/boot/grub
KERNEL_BIN = $(BUILD_DIR)/kernel.bin
KERNEL_ISO = $(BUILD_DIR)/aether.iso

# Source files
SOURCES = $(wildcard src/kernel/*.c) \
		  $(wildcard src/c/*.c) \
		  $(wildcard src/libc/*.c) \
		  $(wildcard src/boot/*.asm)
OBJECTS = $(filter %.o, $(patsubst %.c, $(BUILD_DIR)/%.o, $(SOURCES)) $(patsubst %.asm, $(BUILD_DIR)/%.o, $(SOURCES)))
GRUB_CFG = src/boot/grub.cfg

.PHONY: all clean

# Default target
all: $(KERNEL_ISO)

$(BUILD_DIR)/%.o: %.asm
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $< -o $@

# Compile source files
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Link everything
$(KERNEL_BIN): $(OBJECTS)
	$(LD) -o $(KERNEL_BIN) $(OBJECTS) $(LDFLAGS)

# Generate an iso file
$(KERNEL_ISO): $(KERNEL_BIN)
	@mkdir -p $(GRUB_CFG_DIR)
	@cp $(GRUB_CFG) $(GRUB_CFG_DIR)/grub.cfg
	@mkdir -p $(ISO_DIR)/boot
	@cp $(KERNEL_BIN) $(ISO_DIR)/boot/kernel.bin
	
	grub-mkrescue -o $(KERNEL_ISO) $(ISO_DIR)

	@rm -rf $(ISO_DIR)

# Debugging mode with GDB
debug: all

# Clean build files
clean:
	rm -rf $(BUILD_DIR)/*

