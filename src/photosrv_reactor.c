/*
*author : xuke.coder@gmail.com
*date   : 2015-03-04
*/

#include "photosrv_common.h"
#include "photosrv_log.h"
#include "photosrv_modules.h"
#include "photosrv_reactor.h"


photosrv_module_t   reactor_mgr = {
    PHOTOSRV_MODULE_CORE,
    photosrv_reactor_module_init,
    photosrv_reactor_module_release
};

int
photosrv_reactor_module_init(void *data)
{
    photosrv_core_modules_t     *core_modules = NULL;
    photosrv_reactor_t          *reactor_mgr = NULL;

    core_modules = (photosrv_core_modules_t *)data;
    reactor_mgr = core_modules->reactor_mgr;

    if (!(reactor_mgr->reactor = event_init())) {
        return PHOTOSRV_ERROR;
    }

    
    return PHOTOSRV_OK;
}

void
photosrv_reactor_module_release(void *data)
{
    photosrv_core_modules_t     *core_modules = NULL;

}

