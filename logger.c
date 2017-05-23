#include "logger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define LOG_MAX_LENGTH 80

const char *log_levels[] = {"ERR", "WAR", "INF", "DEB"};
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
            _logger_config->level[i] = (char*) malloc(sizeof(char)*4);
            if(!_logger_config->level[i]) return 2+i;
        }

        strcpy(_logger_config->level[0], "ERR");
        strcpy(_logger_config->level[1], "WAR");
        strcpy(_logger_config->level[2], "INF");
        strcpy(_logger_config->level[3], "DEB");

        /* decorators */
        const int default_size[] = {1, 6, 5, 2, 1};
        const char* default_colors[] = {
            "\x1B[31m", /* red */
            "\x1B[33m", /* yellow */
            "\x1B[32m", /* green */
            "\x1B[36m"  /* blue */
        };

        for(i=0; i<_LIBLOGGER_LEVELS; i++)
        {
            for(j=0; j<_LIBLOGGER_DECORATORS; j++)
            {
                _logger_config->decorator[i][j] = (char*) malloc(
                        sizeof(char)*default_size[i]);
                if(!_logger_config->decorator[i][j]) return 6*j+i;
            }

            _logger_config->decorator[i][0][0] = 0;
            strcpy(_logger_config->decorator[i][1], default_colors[i]);
            strcpy(_logger_config->decorator[i][2], "\x1B[0m");
            strcpy(_logger_config->decorator[i][3], " ");
            _logger_config->decorator[i][4][0] = 0;
        }
    }

    return 0;
}

int logger_generic(int level, char *str, ...)
{
    va_list va;
    char log[LOG_MAX_LENGTH];

    va_start(va, str);
    vsprintf(log, str, va);
    fprintf(stderr, "%s[%s%s%s]%s%s%s",
            _logger_config->decorator[level][0],
            _logger_config->decorator[level][1],
            _logger_config->level[level],
            _logger_config->decorator[level][2],
            _logger_config->decorator[level][3],
            log,
            _logger_config->decorator[level][4]
            );
    va_end(va);

    return 0;
}

