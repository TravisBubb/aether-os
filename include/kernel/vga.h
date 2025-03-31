#ifndef VGA_H
#define VGA_H

#include <stdint.h>

#define VGA_BUFFER_WIDTH 80
#define VGA_BUFFER_HEIGHT 25
#define VGA_BUFFER_ADDR (volatile vga_entry_t *)0xB8000

// VGA return codes
#define VGA_SUCCESS 0
#define VGA_ERROR_NULL_WRITER 1
#define VGA_ERROR_NOT_INITIALIZED 2

/**
 * @typedef vga_color_entry_t
 * @brief VGA color entry definition
 */
typedef uint8_t vga_color_entry_t;

/**
 * @typedef vga_character_entry_t
 * @brief VGA Character Entry definition
 */
typedef unsigned char vga_character_entry_t;

/**
 * @typedef vga_entry_t
 * @brief VGA text entry including an ASCII character and color scheme
 */
typedef uint16_t vga_entry_t;

/**
 * @brief VGA color modes
 *
 * These colors are used to set foreground and background colors for text
 * displayed in VGA text mode.
 */
typedef enum {
  VGA_COLOR_BLACK = 0,
  VGA_COLOR_BLUE = 1,
  VGA_COLOR_GREEN = 2,
  VGA_COLOR_CYAN = 3,
  VGA_COLOR_RED = 4,
  VGA_COLOR_MAGENTA = 5,
  VGA_COLOR_BROWN = 6,
  VGA_COLOR_LIGHT_GREY = 7,
  VGA_COLOR_DARK_GREY = 8,
  VGA_COLOR_LIGHT_BLUE = 9,
  VGA_COLOR_LIGHT_GREEN = 10,
  VGA_COLOR_LIGHT_CYAN = 11,
  VGA_COLOR_LIGHT_RED = 12,
  VGA_COLOR_LIGHT_MAGENTA = 13,
  VGA_COLOR_LIGHT_BROWN = 14,
  VGA_COLOR_WHITE = 15,
} VgaColor;

/**
 * @brief Represents the VGA text-mode screen
 */
typedef struct __attribute__((aligned(8))){
  volatile vga_entry_t *buffer;   ///< The VGA text buffer
  vga_color_entry_t color_scheme; ///< The VGA color scheme
  uint8_t row;                    ///< The current row position
  uint8_t column;                 ///< The current column position
} VgaWriter;

/**
 * @brief Creates a vga_color_entry_t
 *
 * @param fg A VgaColor representing the desired foreground color.
 * @param bg A VgaColor representing the desired background color.
 *
 * @returns A vga_color_entry_t representing the desired VGA color scheme.
 */
static inline vga_color_entry_t vga_color_entry(VgaColor fg, VgaColor bg) {
  return (vga_color_entry_t)fg | ((vga_color_entry_t)bg << 4);
}

/**
 * @brief Creates a vga_entry_t from the given VGA character entry and color
 * entry
 *
 * @param c The vga_character_entry_t representing the VGA text character.
 * @param color The vga_color_entry_t representing the VGA background and
 * foreground color scheme.
 *
 * @returns A vga_entry_t that represents a VGA text character and corresponding
 * color scheme.
 */
static inline vga_entry_t vga_entry(vga_character_entry_t c,
                                    vga_color_entry_t color) {
  return (vga_entry_t)c | ((vga_entry_t)color << 8);
}

/**
 * @brief Initializes the provided VgaWriter
 *
 * This function sets up the VGA text buffer, resets the cursor position, and
 * applies the default color scheme.
 *
 * @param writer Pointer to VgaWriter struct.
 *
 * @returns VGA_SUCCESS - operation was successful
 * @returns VGA_ERROR_NULL_WRITER - operation was unsuccessful, a null writer
 * was provided
 */
int vga_init(VgaWriter *writer);

#endif // VGA_H
