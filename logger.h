#ifndef __LIBLOGGER_LOGGER__
#define __LIBLOGGER_LOGGER__

#define _LIBLOGGER_ERR 0
#define _LIBLOGGER_WAR 1
#define _LIBLOGGER_INF 2
#define _LIBLOGGER_DEB 3

#define logger_error(...)	logger_generic(_LIBLOGGER_ERR, __VA_ARGS__)
#define logger_warning(...)	logger_generic(_LIBLOGGER_WAR, __VA_ARGS__)
#define logger_info(...)	logger_generic(_LIBLOGGER_INF, __VA_ARGS__)
#define logger_debug(...)	logger_generic(_LIBLOGGER_DEB, __VA_ARGS__)

#define _LIBLOGGER_LEVELS       4
#define _LIBLOGGER_DECORATORS   5

struct logger_config {
    char* level[_LIBLOGGER_LEVELS];
    char* decorator[_LIBLOGGER_LEVELS][_LIBLOGGER_DECORATORS];
};

int logger_generic(int, char*, ...);
int logger_init(struct logger_config*);

#endif

