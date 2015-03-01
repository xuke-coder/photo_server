/*
*author : xuke.coder@gmail.com
*date   : 2015-03-04
*/

#ifndef _PHOTOSRV_REACTOR_H
#define _PHOTOSRV_REACTOR_H


typedef struct photosrv_reactor_s      photosrv_reactor_t;

struct photosrv_reactor_s {
    struct event_base   *reactor;
};

#endif

