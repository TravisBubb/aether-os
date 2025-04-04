#include "logging.h"
#include "serial.h"
#include "vga.h"
#include "vga_text.h"

int kernel_main() {
  VgaWriter writer;
  vga_init(&writer);

  vga_clear_screen(&writer);
  vga_write_string(
      &writer,
      "Hello, World! This is a long string that should hopefully illustrate "
      "the line wrapping functionality that was just implemented.\n\n:)");

  serial_init();

  LOG_INFO("this %s a test: %s\n", "IS", "Hello, World!");
  LOG_INFO("int: %d, str: %s\n", 912, "integer");
  LOG_INFO("int: %d, hex: %x\n", 912, 912);

  while (1)
    ;

  return 0;
}
