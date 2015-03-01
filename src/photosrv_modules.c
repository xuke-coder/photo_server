/*
*author : xuke.coder@gmail.com
*date   : 2015-03-04
*/


#include "photosrv_common.h"
#include "photosrv_log.h"

extern photosrv_module_t   slabs_mgr;
extern photosrv_module_t   reactor_mgr;

photosrv_module_t*  modules_mgr[] = {
        &slabs_mgr,
        &reactor_mgr
};