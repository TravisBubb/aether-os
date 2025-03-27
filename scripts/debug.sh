#!/bin/bash
set -e

echo "[+] Starting QEMU in debug mode..."
qemu-system-x86_64 -kernel build/kernel.bin -s -S &

echo "[+] Attaching GDB..."
x86_64-elf-gdb -ex "target remote localhost:1234" -ex "layout asm" -ex "layout regs"
