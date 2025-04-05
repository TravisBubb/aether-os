#include "vsnprintf.h"

int vsnprintf(char *str, size_t size, const char *fmt, va_list ap) {
  int written = 0;
  char *buf;

  while (*fmt != '\0') {
    if (written >= size - 1)
      break;

    if (*fmt == '%') {
      const char c = *++fmt;

      switch (c) {
      case 's':
        buf = va_arg(ap, char *);
        while (*buf != '\0') {
          *str++ = *buf++;
        }
        buf = NULL;
        written++;
        break;
      case 'd':
        *str++ = 'D';
        written++;
        break;
      case 'x':
        *str++ = 'X';
        written++;
        break;
      default:
        fmt++;
        continue;
      }

      fmt++;
      continue;
    }

    *str++ = *fmt++;
    written++;
  }

  str[written] = '\0';
  return written;
}
