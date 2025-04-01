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

  serial_write("This is a test string for serial\n:)");

  while (1)
    ;

  return 0;
}
