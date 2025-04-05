#include "string_utils.h"
#include <stddef.h>

size_t aether_strlen(const char *str) {
  const char *s = str;
  while (*s != '\0') {
    s++;
  }
  return s - str;
}

char *aether_strcpy(char *dest, const char *src) {
  char *original_dest = dest;
  while (*src != '\0') {
    *dest++ = *src++;
  }

  *dest = '\0';
  return original_dest;
}

char *aether_strncpy(char *dest, const char *src, size_t n) {
  char *original_dest = dest;

  while (n-- > 0 && *src != '\0') {
    *dest++ = *src++;
  }

  if (n > 0) {
    *dest = '\0';
  }

  return original_dest;
}
