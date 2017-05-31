#include "logger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#define LOG_MAX_LENGTH 80
#define MAX_TIME_BUFFER_LENGTH  80

/* struct */
struct logger_config {
    char* level[_LIBLOGGER_LEVELS];
    char* decorator[_LIBLOGGER_LEVELS][_LIBLOGGER_DECORATORS];
    char* date_format;
};

/* internal config */
struct logger_config *_logger_config;

/* functions */
int logger_config_init(void)
{
    int i, j;

    /* init */
    _logger_config = (struct logger_config*) malloc(
            sizeof(struct logger_config));
    if(!_logger_config) return 1;

    /* error msg  */
    for(i=0; i<_LIBLOGGER_LEVELS; i++)
    {
        _logger_config->level[i] = (char*) malloc(sizeof(char));
        if(!_logger_config->level[i]) return i+1;

        _logger_config->level[i][0] = 0;
    }

    /* decorators */
    for(i=0; i<_LIBLOGGER_LEVELS; i++)
    {
        for(j=0; j<_LIBLOGGER_DECORATORS; j++)
        {
            _logger_config->decorator[i][j] = (char*) malloc(sizeof(char));
            if(!_logger_config->decorator[i][j]) return _LIBLOGGER_LEVELS*j+i+4;

            _logger_config->decorator[i][j][0] = 0;
        }
    }

    return 0;
}

int logger_config_default(void)
{
    int i, j;

    /* init */
    _logger_config = (struct logger_config*) malloc(
            sizeof(struct logger_config));
    if(!_logger_config) return 1;

    /* error msg  */
    for(i=0; i<_LIBLOGGER_LEVELS; i++)
    {
        _logger_config->level[i] = (char*) malloc(sizeof(char)*6);
        if(!_logger_config->level[i]) return 2+i;
    }

    strcpy(_logger_config->level[0], "FATAL");
    strcpy(_logger_config->level[1], "ERROR");
    strcpy(_logger_config->level[2], "WARN ");
    strcpy(_logger_config->level[3], "INFO ");
    strcpy(_logger_config->level[4], "DEBUG");
    strcpy(_logger_config->level[5], "TRACE");
    strcpy(_logger_config->level[6], "ALL  ");

    /* date format */
    _logger_config->date_format = malloc(sizeof(char)*6);
    if(!_logger_config->date_format) return 6;

    strcpy(_logger_config->date_format, "%x %X");

    /* decorators */
    const int default_size[] = {2, 2, 2, 7, 6, 2, 1, 1};
    const char* default_pre_level[] = {
        "[\x1B[35m", /* fatal - purple */
        "[\x1B[31m", /* error - red */
        "[\x1B[33m", /* warn - yellow */
        "[\x1B[32m", /* info - green */
        "[\x1B[34m", /* debug - blue */
        "[\x1B[36m", /* trace - cyan */
        "[\x1B[37m"  /* all - grey */
    };

    for(i=0; i<_LIBLOGGER_LEVELS; i++)
    {
        for(j=0; j<_LIBLOGGER_DECORATORS; j++)
        {
            _logger_config->decorator[i][j] = (char*) malloc(
                    sizeof(char)*default_size[i]);
            if(!_logger_config->decorator[i][j]) return 7*j+i;
        }

        strcpy(_logger_config->decorator[i][0], "(");
        strcpy(_logger_config->decorator[i][1], ")");
        strcpy(_logger_config->decorator[i][2], " ");
        strcpy(_logger_config->decorator[i][3], default_pre_level[i]);
        strcpy(_logger_config->decorator[i][4], "\x1B[0m]");
        strcpy(_logger_config->decorator[i][5], " ");
        _logger_config->decorator[i][6][0] = 0;
        _logger_config->decorator[i][7][0] = 0;
    }

    return 0;
}

int logger_config_date_format(char *format)
{
    size_t size = strlen(format);

    _logger_config->date_format = (char*) malloc(sizeof(char)*size);
    if(!_logger_config->date_format) return 1;

    strcpy(_logger_config->date_format, format);

    return 0;
}

int logger_decorator_generic(int level, int decorator, char* format)
{
    int i;
    int len;
    int ret;

    len = strlen(format);

    /* special case for global config */
    if(level==_LIBLOGGER_GLB)
    {
        for(i=0;i<_LIBLOGGER_LEVELS;i++)
        {
            ret = logger_decorator_generic(i, decorator, format);
            if(ret) return ret;
        }

        return 0;
    }

    /* if already used, cleaning it */
    if(_logger_config->decorator[level][decorator])
    {
        free(_logger_config->decorator[level][decorator]);
    }

    _logger_config->decorator[level][decorator] = (char*)
        malloc(sizeof(char)*(len+1));
    if(!_logger_config->decorator[level][decorator]) return 1;

    strcpy(_logger_config->decorator[level][decorator], format);

    return 0;
}

int logger_level_generic(int level, char* format)
{
    int len;

    len = strlen(format);

    /* if already used, cleaning it */
    if(_logger_config->level[level])
    {
        free(_logger_config->level[level]);
    }

    _logger_config->level[level] = (char*)
        malloc(sizeof(char)*(len+1));
    if(!_logger_config->level[level]) return 1;

    strcpy(_logger_config->level[level], format);

    return 0;
}

int logger_generic(int level, char *str, ...)
{
    va_list va;
    char log[LOG_MAX_LENGTH];
    char time_buffer[MAX_TIME_BUFFER_LENGTH];
    struct tm *info;
    time_t rawtime;
    int ret;

    ret = time(&rawtime);
    if(ret < 0) return 1;

    info = localtime(&rawtime);

#ifndef _LIBLOGGER_NO_CHECKS
    if(!_logger_config->date_format)
    {
        fprintf(stderr, "date_format is NULL, cannot output log!\n");
        return 2;
    }
#endif

    strftime(time_buffer, MAX_TIME_BUFFER_LENGTH, _logger_config->date_format,
            info);

    va_start(va, str);
    vsprintf(log, str, va);
    fprintf(stderr, "%s%s%s%s%s%s%s%s%s%s%s",
            _logger_config->decorator[level][0],
            time_buffer,
            _logger_config->decorator[level][1],
            _logger_config->decorator[level][2],
            _logger_config->decorator[level][3],
            _logger_config->level[level],
            _logger_config->decorator[level][4],
            _logger_config->decorator[level][5],
            _logger_config->decorator[level][6],
            log,
            _logger_config->decorator[level][7]
            );
    va_end(va);

    return 0;
}

