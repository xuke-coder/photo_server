/*
*author : xuke.coder@gmail.com
*date   : 2015-03-04
*/

#ifndef _PHOTOSRV_MODULES_H
#define _PHOTOSRV_MODULES_H


typedef enum {
    PHOTOSRV_MODULE_CORE,
    PHOTOSRV_MODULE_HTTP
} PHOTOSRV_MODULE_TYPE;

typedef int (*photosrv_module_init) (void *);
typedef void (*photosrv_module_release) (void *);
typedef int (*photosrv_process_init) (void *);
typedef void (*photosrv_process_release) (void *);
typedef int (*photosrv_thread_init) (void *);
typedef void (*photosrv_thread_release) (void *);



typedef struct photosrv_module_s       photosrv_module_t;

struct photosrv_module_s {
    PHOTOSRV_MODULE_TYPE        module_type;
    photosrv_module_init        module_init;
    photosrv_module_release     module_release;
    photosrv_process_init       process_init;
    photosrv_process_release    process_release;
    photosrv_thread_init        thread_init;
    photosrv_thread_release     thread_release;
};


#endif

