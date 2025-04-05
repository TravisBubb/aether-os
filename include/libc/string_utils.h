#ifndef _STRING_UTILS_H
#define _STRING_UTILS_H

#include <stdarg.h>
#include <stddef.h>

/**
 * @brief Returns the length of the given string
 */
size_t aether_strlen(const char *str);

char *aether_strcpy(char *dest, const char *src);
char *aether_strncpy(char *dest, const char *src, size_t n);

int aether_vsnprintf(char *str, size_t size, const char *fmt, va_list ap);

/**
 * @brief Converts the given integer value to a string in the desired base
 */
char *aether_itoa(int value, char *str, int base);

/**
 * @brief Converts the given integer value to a string
 */
char *aether_itoa_decimal(int value, char *str);

/**
 * @brief Converts the given integer value to a hexadecimal string
 */
char *aether_itoa_hex(int value, char *str);

#endif // _STRING_UTILS_H
