#ifndef _PHOTOSRV_SIGNAL_H
#define _PHOTOSRV_SIGNAL_H

int
photosrv_signal_init(int *evfd, int block_flag, photosrv_err_t *err);
void
photosrv_signal_release(int evfd, photosrv_err_t *err);
int
photosrv_signal_send(int evfd, photosrv_err_t *err);
int
photosrv_signal_recv(int evfd, photosrv_err_t *err);


#endif
