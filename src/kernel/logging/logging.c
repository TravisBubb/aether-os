#include "logging.h"
#include "serial.h"
#include <stdarg.h>
#include "string_utils.h"

void log(LogLevel level, const char *fmt, ...) {
  char buffer[256] = {0};

  va_list args;
  va_start(args, fmt);

  aether_vsnprintf(buffer, sizeof(buffer), fmt, args);

  va_end(args);

  serial_write(buffer);
}
