#include "logger.h"

#include <stdio.h>

int main(void)
{
    printf("Printing with default logger config\n");

    logger_config_default();

    logger_fatal("fatal\n");
    logger_error("error\n");
    logger_warning("warning\n");
    logger_info("info\n");
    logger_debug("debug\n");
    logger_trace("trace\n");
    logger_all("all\n");

    printf("Printing with an empty logger config\n");

    logger_config_init();
    logger_config_date_format("%T");

    logger_fatal("fatal\n");
    logger_error("error\n");
    logger_warning("warning\n");
    logger_info("info\n");
    logger_debug("debug\n");
    logger_trace("trace\n");
    logger_all("all\n");

    printf("Printing with a custom logger config\n");

    logger_config_init();
    logger_config_date_format("%F %T");
    logger_config_global_0("[");
    logger_config_global_1("]");
    logger_config_global_2("-");
    logger_config_global_3("(");
    logger_config_global_4(")");
    logger_config_global_5("=");
    logger_config_global_6("-->");
    logger_config_global_7("\x1b[0m");
    logger_config_fatal("FAT");
    logger_config_error("ERR");
    logger_config_warning("WAR");
    logger_config_info("INF");
    logger_config_debug("DEB");
    logger_config_trace("TRC");
    logger_config_all("ALL");



    logger_fatal("fatal\n");
    logger_error("error\n");
    logger_warning("warning\n");
    logger_info("info\n");
    logger_debug("debug\n");
    logger_trace("trace\n");
    logger_all("all\n");

    return 0;
}

