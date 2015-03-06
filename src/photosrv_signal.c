#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/eventfd.h>

int
photosrv_signal_init(int *evfd, int block_flag, photosrv_err_t *err)
{
    int    ret = 0;

    if (!err) {
        return PHOTOSRV_ERROR;
    }
    
    if (!evfd) {
        err->log_errno = PHOTOSRV_ERR_PARAM;
        return PHOTOSRV_ERROR;
    }

    if (block_flag == PHOTOSRV_FALSE) {
        if ((ret = eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC)) == -1) {
            err->sys_errno = errno;
            return PHOTOSRV_ERROR;
        }
    } else {
        if ((ret = eventfd(0, EFD_CLOEXEC)) == -1) {
            err->sys_errno = errno;
            return PHOTOSRV_ERROR;
        }
    }

    *evfd = ret;

    return PHOTOSRV_OK;
}

void
photosrv_signal_release(int evfd, photosrv_err_t *err)
{
    if (close(evfd) == -1) {
        err->sys_errno = errno;
    }
    
}

int
photosrv_signal_send(int evfd, photosrv_err_t *err)
{
    uint64_t    val = 0x555;

    if (write(evfd, &val, sizeof(val)) == -1) {
        if (err) {
            err->sys_errno = errno;
        }
        return PHOTOSRV_ERROR;
    }
    return PHOTOSRV_OK;
}

int
photosrv_signal_recv(int evfd, photosrv_err_t *err)
{
    uint64_t    val = 0;

    if (read(evfd, &val, sizeof(val)) == -1) {
        if (err) {
            err->sys_errno = errno;
        }
        return PHOTOSRV_ERROR;
    }

    return PHOTOSRV_OK;
    
}

