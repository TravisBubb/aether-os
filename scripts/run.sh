#!/bin/bash
set -e

echo "[+] Running AetherOS in QEMU..."
qemu-system-x86_64 -cdrom build/aether.iso -boot d

