#include <stddef.h>
#include <string.h>

size_t strlen(const char *str) {
  const char *s = str;
  while (*s != '\0') {
    s++;
  }
  return s - str;
}
