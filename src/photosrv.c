/*
*author : xuke.coder@gmail.com
*date   : 2015-02-27
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "photosrv.h"

photosrv_manager_t  *photosrv_mgr;

int
main(int argc, char *argv[])
{

    if (photosrv_mgr_init() != PHOTOSRV_OK) {
        return PHOTOSRV_ERROR;
    }

    if (photosrv_mgr_parse_opt(argc, argv) != PHOTOSRV_OK) {
        return PHOTOSRV_ERROR;
    }
    


    photosrv_mgr_release();
    
    return 0;
}

static int
photosrv_mgr_init()
{
    if (!(photosrv_mgr = (photosrv_manager_t *)malloc(
        sizeof(photosrv_manager_t)))) {
        printf("no more memory!\n");
        return PHOTOSRV_ERROR;
    }

    memset(photosrv_mgr, 0, sizeof(photosrv_manager_t));

    return PHOTOSRV_OK;
}

static void
photosrv_mgr_release()
{
    if (!photosrv_mgr) {
        return;
    }

    free(photosrv_mgr);
    
    photosrv_mgr = NULL;
}

static int
photosrv_mgr_parse_opt(int argc, char *argv[])
{
    char cmd_opt = 0;

    while ((cmd_opt = getopt(argc, argv, "hrs::")) != -1) {
        switch (cmd_opt) {
            case 'h':
                photosrv_mgr->option.help = PHOTOSRV_TRUE;
                break;

            case 'r':
                photosrv_mgr->option.reload = PHOTOSRV_TRUE;
                break;
                
            case 's':
                if (!strcmp(optarg, "stop")) {
                    photosrv_mgr->option.signal_type = PHOTOSRV_SIGNAL_STOP;
                }

                break;

            default:
                photosrv_log_write(PHOTOSRV_STDERR_FD, "Illegal option '%c' \n",
                    cmd_opt);
                return PHOTOSRV_FALSE;
        }   
    }

    return PHOTOSRV_TRUE;
}


