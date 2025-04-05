#define LOG_INFO(fmt, ...) log(LOG_LEVEL_INFO, fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...) log(LOG_LEVEL_WARN, fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) log(LOG_LEVEL_ERROR, fmt, ##__VA_ARGS__)

/**
 * @brief Represents the level/priority of a log entry
 */
typedef enum {
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR
} LogLevel;

/**
 * @brief Logs a message with the given format arguments
 *
 * Note that this logger currently only supports a Serial sink with COM1 and
 * does not currently buffer and asynchronously process logs. Additionally,
 * this logging module does not support configurations like custom log template
 * options and minimum log levels.
 */
void log(LogLevel level, const char* fmt, ...);

