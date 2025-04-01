#ifndef VGA_TEXT_H
#define VGA_TEXT_H

#include "vga.h"
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Clears the VGA text screen of all characters
 *
 * Replaces all characters in the VGA text buffer with a ' ' character and
 * resets the writer's current position to (0, 0).
 *
 * @param writer Pointer to VgaWriter struct.
 *
 * @returns VGA_SUCCESS - operation was successful
 * @returns VGA_ERROR_NOT_INITIALIZED - operation was unsuccessful, the given
 * writer was not previously initialized
 */
int vga_clear_screen(VgaWriter *writer);

/**
 * @brief Writes a string to the VGA text screen at the writer's current
 * position
 *
 * @param writer Pointer to VgaWriter struct.
 *
 * @returns VGA_SUCCESS - operation was successful
 */
int vga_write_string(VgaWriter *writer, const char *str);

/**
 * @brief Sets the cursor position of the writer to the desired row and column
 *
 * @param writer Pointer to VgaWriter struct.
 *
 * @returns VGA_SUCCESS - operation was successful
 */
int vga_set_cursor(VgaWriter *writer, size_t row, size_t column);

#endif
