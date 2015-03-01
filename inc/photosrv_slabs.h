/*
*author : xuke.coder@gmail.com
*date   : 2015-02-27
*/

#ifndef _PHOTOSRV_SLABS_H
#define _PHOTOSRV_SLABS_H

typedef struct photosrv_slabs_s      photosrv_slabs_t;

struct photosrv_slabs_s {
    uint32_t        slabs_num;
    uint32_t        
};

struct photosrv_slab_s {
    uint32_t        item_size;
    uint32_t        item_taotal_num;
    uint32_t        item_free_num;
    void           *item_ptr;
    void          **list_ptr;
};

#endif