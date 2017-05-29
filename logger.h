#ifndef __LIBLOGGER_LOGGER__
#define __LIBLOGGER_LOGGER__

#define _LIBLOGGER_FAT 0
#define _LIBLOGGER_ERR 1
#define _LIBLOGGER_WAR 2
#define _LIBLOGGER_INF 3
#define _LIBLOGGER_DEB 4
#define _LIBLOGGER_TRC 5
#define _LIBLOGGER_ALL 6

#define logger_fatal(...)   logger_generic(_LIBLOGGER_FAT, __VA_ARGS__)
#define logger_error(...)   logger_generic(_LIBLOGGER_ERR, __VA_ARGS__)
#define logger_warning(...) logger_generic(_LIBLOGGER_WAR, __VA_ARGS__)
#define logger_info(...)    logger_generic(_LIBLOGGER_INF, __VA_ARGS__)
#define logger_debug(...)   logger_generic(_LIBLOGGER_DEB, __VA_ARGS__)
#define logger_trace(...)   logger_generic(_LIBLOGGER_TRC, __VA_ARGS__)
#define logger_all(...)     logger_generic(_LIBLOGGER_ALL, __VA_ARGS__)

#define _LIBLOGGER_LEVELS       7
#define _LIBLOGGER_DECORATORS   8

struct logger_config {
    char* level[_LIBLOGGER_LEVELS];
    char* decorator[_LIBLOGGER_LEVELS][_LIBLOGGER_DECORATORS];
    char* date_format;
};

int logger_generic(int, char*, ...);
int logger_init(struct logger_config*);

#endif

