/*
*author : xuke.coder@gmail.com
*date   : 2015-02-28
*/

#ifndef _PHOTOSRV_LOG_H
#define _PHOTOSRV_LOG_H


#define PHOTOSRV_MAX_ERROR_SIZE     2048
#define PHOTOSRV_STDERR_FD          STDERR_FILENO

void
photosrv_log_write(int fd, const char *str_format, ...);


#endif