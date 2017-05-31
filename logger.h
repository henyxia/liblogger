#ifndef __LIBLOGGER_LOGGER__
#define __LIBLOGGER_LOGGER__

#define _LIBLOGGER_GLB -1
#define _LIBLOGGER_FAT 0
#define _LIBLOGGER_ERR 1
#define _LIBLOGGER_WAR 2
#define _LIBLOGGER_INF 3
#define _LIBLOGGER_DEB 4
#define _LIBLOGGER_TRC 5
#define _LIBLOGGER_ALL 6

/* logger */
#define logger_fatal(...)   logger_generic(_LIBLOGGER_FAT, __VA_ARGS__)
#define logger_error(...)   logger_generic(_LIBLOGGER_ERR, __VA_ARGS__)
#define logger_warning(...) logger_generic(_LIBLOGGER_WAR, __VA_ARGS__)
#define logger_info(...)    logger_generic(_LIBLOGGER_INF, __VA_ARGS__)
#define logger_debug(...)   logger_generic(_LIBLOGGER_DEB, __VA_ARGS__)
#define logger_trace(...)   logger_generic(_LIBLOGGER_TRC, __VA_ARGS__)
#define logger_all(...)     logger_generic(_LIBLOGGER_ALL, __VA_ARGS__)

/* levels */
#define logger_config_fatal(a)   logger_level_generic(_LIBLOGGER_FAT, a)
#define logger_config_error(a)   logger_level_generic(_LIBLOGGER_ERR, a)
#define logger_config_warning(a) logger_level_generic(_LIBLOGGER_WAR, a)
#define logger_config_info(a)    logger_level_generic(_LIBLOGGER_INF, a)
#define logger_config_debug(a)   logger_level_generic(_LIBLOGGER_DEB, a)
#define logger_config_trace(a)   logger_level_generic(_LIBLOGGER_TRC, a)
#define logger_config_all(a)     logger_level_generic(_LIBLOGGER_ALL, a)

/* decorators */
#define logger_config_global_0(a) \
    logger_decorator_generic(_LIBLOGGER_GLB, 0, a)
#define logger_config_global_1(a) \
    logger_decorator_generic(_LIBLOGGER_GLB, 1, a)
#define logger_config_global_2(a) \
    logger_decorator_generic(_LIBLOGGER_GLB, 2, a)
#define logger_config_global_3(a) \
    logger_decorator_generic(_LIBLOGGER_GLB, 3, a)
#define logger_config_global_4(a) \
    logger_decorator_generic(_LIBLOGGER_GLB, 4, a)
#define logger_config_global_5(a) \
    logger_decorator_generic(_LIBLOGGER_GLB, 5, a)
#define logger_config_global_6(a) \
    logger_decorator_generic(_LIBLOGGER_GLB, 6, a)
#define logger_config_global_7(a) \
    logger_decorator_generic(_LIBLOGGER_GLB, 7, a)

#define logger_config_fatal_0(a) logger_decorator_generic(_LIBLOGGER_FAT, 0, a)
#define logger_config_fatal_1(a) logger_decorator_generic(_LIBLOGGER_FAT, 1, a)
#define logger_config_fatal_2(a) logger_decorator_generic(_LIBLOGGER_FAT, 2, a)
#define logger_config_fatal_3(a) logger_decorator_generic(_LIBLOGGER_FAT, 3, a)
#define logger_config_fatal_4(a) logger_decorator_generic(_LIBLOGGER_FAT, 4, a)
#define logger_config_fatal_5(a) logger_decorator_generic(_LIBLOGGER_FAT, 5, a)
#define logger_config_fatal_6(a) logger_decorator_generic(_LIBLOGGER_FAT, 6, a)
#define logger_config_fatal_7(a) logger_decorator_generic(_LIBLOGGER_FAT, 7, a)

#define logger_config_error_0(a) logger_decorator_generic(_LIBLOGGER_ERR, 0, a)
#define logger_config_error_1(a) logger_decorator_generic(_LIBLOGGER_ERR, 1, a)
#define logger_config_error_2(a) logger_decorator_generic(_LIBLOGGER_ERR, 2, a)
#define logger_config_error_3(a) logger_decorator_generic(_LIBLOGGER_ERR, 3, a)
#define logger_config_error_4(a) logger_decorator_generic(_LIBLOGGER_ERR, 4, a)
#define logger_config_error_5(a) logger_decorator_generic(_LIBLOGGER_ERR, 5, a)
#define logger_config_error_6(a) logger_decorator_generic(_LIBLOGGER_ERR, 6, a)
#define logger_config_error_7(a) logger_decorator_generic(_LIBLOGGER_ERR, 7, a)

#define logger_config_warning_0(a) \
    logger_decorator_generic(_LIBLOGGER_WAR, 0, a)
#define logger_config_warning_1(a) \
    logger_decorator_generic(_LIBLOGGER_WAR, 1, a)
#define logger_config_warning_2(a) \
    logger_decorator_generic(_LIBLOGGER_WAR, 2, a)
#define logger_config_warning_3(a) \
    logger_decorator_generic(_LIBLOGGER_WAR, 3, a)
#define logger_config_warning_4(a) \
    logger_decorator_generic(_LIBLOGGER_WAR, 4, a)
#define logger_config_warning_5(a) \
    logger_decorator_generic(_LIBLOGGER_WAR, 5, a)
#define logger_config_warning_6(a) \
    logger_decorator_generic(_LIBLOGGER_WAR, 6, a)
#define logger_config_warning_7(a) \
    logger_decorator_generic(_LIBLOGGER_WAR, 7, a)

#define logger_config_info_0(a) logger_decorator_generic(_LIBLOGGER_INF, 0, a)
#define logger_config_info_1(a) logger_decorator_generic(_LIBLOGGER_INF, 1, a)
#define logger_config_info_2(a) logger_decorator_generic(_LIBLOGGER_INF, 2, a)
#define logger_config_info_3(a) logger_decorator_generic(_LIBLOGGER_INF, 3, a)
#define logger_config_info_4(a) logger_decorator_generic(_LIBLOGGER_INF, 4, a)
#define logger_config_info_5(a) logger_decorator_generic(_LIBLOGGER_INF, 5, a)
#define logger_config_info_6(a) logger_decorator_generic(_LIBLOGGER_INF, 6, a)
#define logger_config_info_7(a) logger_decorator_generic(_LIBLOGGER_INF, 7, a)

#define logger_config_debug_0(a) logger_decorator_generic(_LIBLOGGER_DEB, 0, a)
#define logger_config_debug_1(a) logger_decorator_generic(_LIBLOGGER_DEB, 1, a)
#define logger_config_debug_2(a) logger_decorator_generic(_LIBLOGGER_DEB, 2, a)
#define logger_config_debug_3(a) logger_decorator_generic(_LIBLOGGER_DEB, 3, a)
#define logger_config_debug_4(a) logger_decorator_generic(_LIBLOGGER_DEB, 4, a)
#define logger_config_debug_5(a) logger_decorator_generic(_LIBLOGGER_DEB, 5, a)
#define logger_config_debug_6(a) logger_decorator_generic(_LIBLOGGER_DEB, 6, a)
#define logger_config_debug_7(a) logger_decorator_generic(_LIBLOGGER_DEB, 7, a)

#define logger_config_trace_0(a) logger_decorator_generic(_LIBLOGGER_TRC, 0, a)
#define logger_config_trace_1(a) logger_decorator_generic(_LIBLOGGER_TRC, 1, a)
#define logger_config_trace_2(a) logger_decorator_generic(_LIBLOGGER_TRC, 2, a)
#define logger_config_trace_3(a) logger_decorator_generic(_LIBLOGGER_TRC, 3, a)
#define logger_config_trace_4(a) logger_decorator_generic(_LIBLOGGER_TRC, 4, a)
#define logger_config_trace_5(a) logger_decorator_generic(_LIBLOGGER_TRC, 5, a)
#define logger_config_trace_6(a) logger_decorator_generic(_LIBLOGGER_TRC, 6, a)
#define logger_config_trace_7(a) logger_decorator_generic(_LIBLOGGER_TRC, 7, a)

#define logger_config_all_0(a) logger_decorator_generic(_LIBLOGGER_ALL, 0, a)
#define logger_config_all_1(a) logger_decorator_generic(_LIBLOGGER_ALL, 1, a)
#define logger_config_all_2(a) logger_decorator_generic(_LIBLOGGER_ALL, 2, a)
#define logger_config_all_3(a) logger_decorator_generic(_LIBLOGGER_ALL, 3, a)
#define logger_config_all_4(a) logger_decorator_generic(_LIBLOGGER_ALL, 4, a)
#define logger_config_all_5(a) logger_decorator_generic(_LIBLOGGER_ALL, 5, a)
#define logger_config_all_6(a) logger_decorator_generic(_LIBLOGGER_ALL, 6, a)
#define logger_config_all_7(a) logger_decorator_generic(_LIBLOGGER_ALL, 7, a)

/* constants */
#define _LIBLOGGER_LEVELS       7
#define _LIBLOGGER_DECORATORS   8

/* functions */
int logger_generic(int, char*, ...);
int logger_level_generic(int, char*);
int logger_decorator_generic(int, int, char*);

int logger_config_init(void);
int logger_config_default(void);
int logger_config_empty_all(void);
int logger_config_date_format(char*);

#endif

