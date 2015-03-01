/*
*author : xuke.coder@gmail.com
*date   : 2015-02-27
*/

#include <stdarg.h>
#include "photosrv_common.h"
#include "photosrv_log.h"


void
photosrv_log_write(int fd, const char *str_format, ...)
{
    char        log_buf[PHOTOSRV_MAX_ERROR_SIZE + 1];
    va_list     args;
    int         str_len = 0;
    
    if (fd <= 0) {
        return;
    }

    va_start(args, str_format);
    str_len = vsnprintf(log_buf, PHOTOSRV_MAX_ERROR_SIZE, str_format, args);
    va_end(args);

    log_buf[str_len] = '\0';

    write(fd, log_buf, str_len);
    
}