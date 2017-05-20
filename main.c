#include "logger.h"

#include <stdio.h>

int main(void)
{
    logger_init(NULL);
    logger_error("error\n");
    logger_warning("warning\n");
    logger_info("info\n");
    logger_debug("debug\n");

    return 0;
}

