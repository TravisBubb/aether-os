#include <stdint.h>

#define COM1 0x3F8 // Base address for COM1

/**
 * @brief Wrapper around the assembly outb instruction
 */
static inline void outb(uint16_t port, uint8_t val) {
  __asm__ volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}

/**
 * @brief Wrapper around the assembly inb instruction
 */
static inline uint8_t inb(uint16_t port) {
  uint8_t ret;
  __asm__ volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
  return ret;
}

/**
 * @brief Checks whether the serial port is ready to be written to or not
 */
static inline int serial_is_transmit_ready() { return inb(COM1 + 5) & 0x20; }

/**
 * @brief Initializes the COM1 serial interface
 *
 * @returns 0 - success
 * @returns 1 - failure
 */
int serial_init();

/**
 * @brief Writes a single character to the serial interface
 */
void serial_write_char(char c);

/**
 * @brief Writes a string to the serial interface
 */
void serial_write(const char *str);
