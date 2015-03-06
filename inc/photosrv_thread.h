/*
*author : xuke.coder@gmail.com
*date   : 2015-03-06
*/

#ifndef _PHOTOSRV_THREAD_H
#define _PHOTOSRV_THREAD_H

#include <pthread.h>

#define photosrv_thread_lock_t  pthread_mutex_t

typedef struct photosrv_thread_s	photosrv_thread_t;

struct photosrv_thread_s {
    photosrv_link_t      link;
    void                *thread_pool;
    pthread_t            tid;
    int                  release_done;
    int                  release_start;
    int                  signal;
};

typedef void * (*photosrv_thread_func_t) (void *data);

int
photosrv_thread_lock_init(photosrv_thread_lock_t *lock);
void
photosrv_thread_lock_release(photosrv_thread_lock_t *lock);
void
photosrv_thread_lock(photosrv_thread_lock_t *lock);
void
photosrv_thread_unlock(photosrv_thread_lock_t *lock);
int
photosrv_thread_create(photosrv_thread_t *cur_thread, 
    photosrv_thread_func_t thread_func, void *data);
void
photosrv_thread_destroy(photosrv_thread_t *cur_thread);



#endif
