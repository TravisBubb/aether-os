#include "vga.h"
#include "vga_text.h"

// Read a byte from the specified I/O port
static inline uint8_t inb(uint16_t port) {
  uint8_t result;
  // Inline assembly to read a byte from a port
  asm volatile("inb %1, %0" : "=a"(result) : "dN"(port));
  return result;
}

// Write a byte to the specified I/O port
static inline void outb(uint16_t port, uint8_t value) {
  // Inline assembly to write a byte to a port
  asm volatile("outb %0, %1" ::"a"(value), "dN"(port));
}

// Simple serial print function using UART
void serial_init() {
  // Set up the serial port (COM1: 0x3F8).
  // This is a simplified version; you would configure the UART properly here
  outb(0x3F8 + 1, 0x00); // Disable all interrupts
  outb(0x3F8 + 3, 0x80); // Set DLAB (Divisor Latch Access Bit)
  outb(0x3F8 + 0, 0x03); // Set baud rate (115200)
  outb(0x3F8 + 1, 0x00); // Disable all interrupts
  outb(0x3F8 + 3, 0x03); // 8 bits, no parity, 1 stop bit
}

void serial_write(char c) {
  while ((inb(0x3F8 + 5) & 0x20) == 0) {
  } // Wait for the transmitter to be ready
  outb(0x3F8, c); // Send character
}

void serial_print(const char *str) {
  while (*str) {
    serial_write(*str);
    str++;
  }
}

int kernel_main() {
  serial_init();

  VgaWriter writer = {0};
  // TODO: Need to figure out why this causes memory issues (gdb cannot access the address of writer in this call)
  //vga_init(&writer);

  writer.buffer = VGA_BUFFER_ADDR;
  writer.color_scheme = vga_color_entry(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  writer.row = 0;
  writer.column = 0;

  serial_print("Initialized writer\n");

  serial_print("attempting to clear the screen...\n");
  vga_clear_screen(&writer);
  serial_print("cleared the screen\n");

  serial_print("attempting to write a string to the screen...\n");
  vga_write_string(&writer, "Hello, World!");
  serial_print("wrote string to the screen\n");

  while (1)
    ;

  return 0;
}
