#include "logger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#define LOG_MAX_LENGTH 80
#define MAX_TIME_BUFFER_LENGTH  80

struct logger_config *_logger_config;

int logger_init(struct logger_config *cfg)
{
    int i, j;

    if(cfg == NULL)
    {
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
    }

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

