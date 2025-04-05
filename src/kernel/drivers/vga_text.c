#include "vga_text.h"
#include "string_utils.h"
#include "vga.h"
#include <stddef.h>

static void vga_write_newline(VgaWriter *writer);

int vga_clear_screen(VgaWriter *writer) {
  if (writer == NULL)
    return VGA_ERROR_NULL_WRITER;

  if (writer->buffer == NULL)
    return VGA_ERROR_NOT_INITIALIZED;

  vga_entry_t space_entry = vga_entry(' ', writer->color_scheme);

  // Iterate over rows (y-axis) first, then columns (x-axis)
  for (int y = 0; y < VGA_BUFFER_HEIGHT; y++) {
    for (int x = 0; x < VGA_BUFFER_WIDTH; x++) {
      writer->buffer[x + (y * VGA_BUFFER_WIDTH)] = space_entry;
    }
  }

  return vga_set_cursor(writer, 0, 0);
}

int vga_write_string(VgaWriter *writer, const char *str) {
  if (writer == NULL)
    return VGA_ERROR_NULL_WRITER;

  if (writer->buffer == NULL)
    return VGA_ERROR_NOT_INITIALIZED;

  size_t len = aether_strlen(str);

  for (size_t i = 0; i < len; i++) {
    const size_t idx = writer->row * VGA_BUFFER_WIDTH + writer->column;

    if (str[i] == '\n') {
      vga_write_newline(writer);
      continue;
    }

    writer->buffer[idx] = vga_entry(str[i], writer->color_scheme);

    if (writer->column++ == VGA_BUFFER_WIDTH)
      vga_write_newline(writer);
  }

  return VGA_SUCCESS;
}

int vga_set_cursor(VgaWriter *writer, size_t row, size_t column) {
  if (writer == NULL)
    return VGA_ERROR_NULL_WRITER;

  writer->row = row;
  writer->column = column;

  return VGA_SUCCESS;
}

static void vga_write_newline(VgaWriter *writer) {
  writer->column = 0;
  writer->row++;

  // TODO: Handle row wraparound / scrolling
}
