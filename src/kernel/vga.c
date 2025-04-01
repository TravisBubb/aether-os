#include "vga.h"
#include <stddef.h>

int vga_init(VgaWriter *writer) {
  if (writer == NULL)
    return VGA_ERROR_NULL_WRITER;

  writer->buffer = VGA_BUFFER_ADDR;
  writer->color_scheme = vga_color_entry(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
  writer->row = 0;
  writer->column = 0;

  return VGA_SUCCESS;
}
