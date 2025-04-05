#include "logging.h"
#include "serial.h"
#include <stdarg.h>
#include <vsnprintf.h>

void log(LogLevel level, const char *fmt, ...) {
  char buffer[256];

  va_list args;
  va_start(args, fmt);

  vsnprintf(buffer, sizeof(buffer), fmt, args);

  va_end(args);

  serial_write(buffer);
}
