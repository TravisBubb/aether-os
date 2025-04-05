#ifndef _STRING_UTILS_H
#define _STRING_UTILS_H

#include <stddef.h>

/**
 * @brief Returns the length of the given string
 */
size_t aether_strlen(const char *str);

char *aether_strcpy(char *dest, const char *src);
char *aether_strncpy(char *dest, const char *src, size_t n);

#endif // _STRING_UTILS_H
