/*
*author : xuke.coder@gmail.com
*date   : 2015-02-27
*/


#ifndef _PHOTOSRV_H
#define _PHOTOSRV_H

#define PHOTOSRV_OK      0
#define PHOTOSRV_ERROR  -1
#define PHOTOSRV_TRUE    1
#define PHOTOSRV_FALSE   0


typedef enum {
    PHOTOSRV_SIGNAL_STOP,
} PHOTOSRV_SIGNAL_TYPE;

typedef struct photosrv_manager_s   photosrv_manager_t;
typedef struct photosrv_option_s    photosrv_option_t;


struct photosrv_option_s {
    int                     help;
    int                     reload;
    PHOTOSRV_SIGNAL_TYPE    signal_type;
    
};


struct photosrv_manager_s {
    photosrv_option_t       option;
    
};


static int
photosrv_mgr_init();
static void
photosrv_mgr_release();
static int
photosrv_mgr_parse_opt(int argc, char *argv[]);


#endif
