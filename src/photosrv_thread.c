/*
*author : xuke.coder@gmail.com
*date   : 2015-03-06
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "photosrv_common.h"
#include "photosrv_thread.h"

void
photosrv_thread_lock(photosrv_thread_lock_t *lock)
{
    int error = 0;
    
    if ((error = pthread_mutex_lock(lock)) != 0) {
        printf("pthread mutex lock error %d\n", error);
    }
}

void
photosrv_thread_unlock(photosrv_thread_lock_t *lock)
{
    int error = 0;

    if ((error = pthread_mutex_unlock(lock)) != 0) {
        printf("pthread mutex nulock error %d\n", error);
    }
}

int
photosrv_thread_lock_init(photosrv_thread_lock_t *lock)
{
    int error = 0;

    if ((error = pthread_mutex_init(lock, NULL)) != 0) {
        return PHOTOSRV_ERROR;
    }

    return PHOTOSRV_OK;
}

void
photosrv_thread_lock_release(photosrv_thread_lock_t *lock)
{
    if ((error = pthread_mutex_destroy(lock)) != 0) {
    }
}

int
photosrv_thread_create(photosrv_thread_t *cur_thread, 
    photosrv_thread_func_t thread_func, void *data)
{
    int         error = 0;
    pthread_t   tid = 0;

    cur_thread->tid = tid;
    cur_thread->release_start = PHOTOSRV_FALSE;
    cur_thread->release_done = PHOTOSRV_FALSE;

    if (photosrv_signal_init(&cur_thread->signal, PHOTOSRV_TRUE) != PHOTOSRV_OK) {
        return PHOTOSRV_ERROR;
    }
    
    if ((error = pthread_create(&tid, NULL, thread_func, data)) != 0) {
        goto signal_release;
    }

    return PHOTOSRV_OK;
    
signal_release:
    photosrv_signal_release(cur_thread->signal);
    
    return PHOTOSRV_ERROR;
    
}


void
photosrv_thread_destroy(photosrv_thread_t *worker_thread)
{
    worker_thread->release_start = PHOTOSRV_TRUE;

    photosrv_signal_send(worker_thread->sub_signal);
    
    while (1) {
        if (worker_thread->release_done == PHOTOSRV_TRUE) {
            break;
        }
        usleep(1000);
    }

    photosrv_signal_release(worker_thread->sub_signal, err);
}


