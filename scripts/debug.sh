#!/bin/bash
set -e

echo "[+] Starting QEMU in debug mode..."
qemu-system-x86_64 -cdrom build/aether.iso -boot d -s -S -serial mon:stdio &

#x86_64-elf-gdb -ex "target remote localhost:1234" -ex "layout asm" -ex "layout regs"
gdb build/kernel.bin -ex "target remote localhost:1234" -ex "layout asm" -ex "layout regs" -ex "layout src"
