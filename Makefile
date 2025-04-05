BUILD_DIR = build
ISO_DIR = iso
GRUB_CFG_DIR = $(ISO_DIR)/boot/grub
KERNEL_BIN = $(BUILD_DIR)/kernel.bin
KERNEL_ISO = $(BUILD_DIR)/aether.iso
ARCH = x86
ARCH_DIR = src/kernel/arch/$(ARCH)
GRUB_CFG = $(ARCH_DIR)/boot/grub.cfg

CC = x86_64-elf-gcc
CFLAGS = -ffreestanding -nostdlib -nostartfiles -mno-red-zone \
		 -O0 -Wall -Wextra -g \
		 -I$(CURDIR)/include/libc \
		 -I$(CURDIR)/include/c \
		 -I$(CURDIR)/include/sys \
		 -I$(CURDIR)/include/kernel \
		 -I$(CURDIR)/include/kernel/drivers \
		 -I$(CURDIR)/include/kernel/logging
LD = x86_64-elf-ld
LDFLAGS = -g -T $(ARCH_DIR)/linker.ld
GDB = x86_64-elf-gdb
AR = x86_64-elf-ar

export CC CFLAGS

SRC = src
KERNEL = $(SRC)/kernel
LIBC = $(SRC)/libc

OBJDIR = obj
LIBC_AR = $(OBJDIR)/libc/libc.a
MULTIBOOT_HEADER = $(OBJDIR)/multiboot_header.o
PROTECTED_MODE_INIT = $(OBJDIR)/protected_mode_init.o
LONG_MODE_INIT = $(OBJDIR)/long_mode_init.o
KERNEL_OBJS = $(patsubst %.c, $(OBJDIR)/kernel/%.o, $(notdir $(wildcard $(KERNEL)/*.c)))
KERNEL_AR = $(OBJDIR)/kernel/drivers/drivers.a \
			$(OBJDIR)/kernel/logging/logging.a

ARCHIVES = $(LIBC_AR)

.PHONY: all clean

all: $(KERNEL_ISO)

$(KERNEL_OBJS):
	$(MAKE) -C $(KERNEL) 

$(LIBC_AR):
	$(MAKE) -C $(LIBC)

$(KERNEL_BIN): $(LIBC_AR) $(KERNEL_OBJS) 
	$(LD) $(LDFLAGS) -o $(KERNEL_BIN) \
		$(MULTIBOOT_HEADER) \
		$(PROTECTED_MODE_INIT) \
		$(LONG_MODE_INIT) \
		$(KERNEL_OBJS) \
		$(KERNEL_AR) \
		$(ARCHIVES)

$(KERNEL_ISO): $(KERNEL_BIN)
	@mkdir -p $(GRUB_CFG_DIR)
	@cp $(GRUB_CFG) $(GRUB_CFG_DIR)/grub.cfg
	@mkdir -p $(ISO_DIR)/boot
	@cp $(KERNEL_BIN) $(ISO_DIR)/boot/kernel.bin
	
	grub-mkrescue -o $(KERNEL_ISO) $(ISO_DIR)

	@rm -rf $(ISO_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)/*
	$(MAKE) -C $(KERNEL) clean
	$(MAKE) -C $(LIBC) clean
