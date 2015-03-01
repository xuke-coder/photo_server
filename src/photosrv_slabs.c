/*
*author : xuke.coder@gmail.com
*date   : 2015-02-27
*/

#include "photosrv_common.h"
#include "photosrv_log.h"
#include "photosrv.h"
#include "photosrv_modules.h"


photosrv_module_t   slabs_mgr = {
    PHOTOSRV_MODULE_CORE,
    photosrv_slabs_module_init,
    photosrv_slabs_module_release
};

int
photosrv_slabs_module_init(void *data)
{
    photosrv_core_modules_t     *core_modules = NULL;
    
}

void
photosrv_slabs_module_release(void *data)
{
}

