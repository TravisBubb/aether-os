#include "string_utils.h"
#include <stddef.h>

static int write_string(char *dest, const char *src);
static int write_int(char *dest, const int n);
static int write_hex(char *dest, const int n, const int write_prefix);

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

int aether_vsnprintf(char *str, size_t size, const char *fmt, va_list ap) {
  size_t written = 0;

  while (*fmt != '\0') {
    size_t tmp = 0;

    if (written >= size - 1)
      break;

    if (*fmt == '%') {
      const char c = *++fmt;

      switch (c) {
      case 's':
        tmp = write_string(str, va_arg(ap, char *));
        str += tmp;
        written += tmp;
        break;
      case 'd':
        tmp = write_int(str, va_arg(ap, int));
        str += tmp;
        written += tmp;
        break;
      case 'x':
        tmp = write_hex(str, va_arg(ap, int), 1);
        str += tmp;
        written += tmp;
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

char *aether_itoa(int value, char *str, int base) {
  int tmp_val;
  char tmp_char;
  char *ptr = str;
  char *r_ptr = str;
  int is_negative = 0;

  if (value < 0 && base == 10) {
    is_negative = 1;
    value = -value;
  }

  // Build the integer string in reverse order by picking off one value
  // at a time and setting it in the buffer.
  do {
    tmp_val = value % base;
    *ptr++ = (tmp_val < 10) ? (tmp_val + '0') : (tmp_val - 10 + 'a');
    value /= base;
  } while (value);

  if (is_negative)
    *ptr++ = '-';

  *ptr = '\0';

  // Reverse the string
  ptr--;
  while (r_ptr < ptr) {
    tmp_char = *ptr;
    *ptr-- = *r_ptr;
    *r_ptr++ = tmp_char;
  }

  return str;
}

char *aether_itoa_decimal(int value, char *str) {
  return aether_itoa(value, str, 10);
}

char *aether_itoa_hex(int value, char *str) {
  return aether_itoa(value, str, 16);
}

static int write_string(char *dest, const char *src) {
  int ret = 0;
  while (*src != '\0') {
    *dest++ = *src++;
    ret++;
  }

  return ret;
}

static int write_int(char *dest, const int n) {
  char str[16];

  aether_itoa_decimal(n, &str[0]);
  return write_string(dest, str);
}

static int write_hex(char *dest, const int n, int write_prefix) {
  char str[32];
  int ret = 0;

  if (write_prefix) {
    ret = write_string(dest, "0x");
    dest += ret;
  }

  aether_itoa_hex(n, &str[0]);
  return ret + write_string(dest, str);
}
