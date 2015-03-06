#ifndef _PHOTOSRV_QUEUE_H
#define _PHOTOSRV_QUEUE_H

typedef struct photosrv_link_s           photosrv_link_t;
typedef struct photosrv_queue_s          photosrv_queue_t;

struct photosrv_link_s {
    photosrv_link_t      *prev;
    photosrv_link_t      *next;
};


struct photosrv_queue_s {
    photosrv_link_t          head;
    photosrv_atomic_lock_t   atomic_lock;
    photosrv_thread_lock_t   thread_lock;
    uint32_t            	size;
    uint32_t            	max_size;
    int                 	release_flag;
};


#define     photosrv_queue_init(que, max_size)      \
                que->head.next = &que->head;        \
                que->head.prev = &que->head;        \
                que->size = 0;                      \
                que->max_size = max_size;           \
                que->release_flag = XIO_FALSE;

#define     photosrv_queue_release(que)             \
                que->head.next = &que->head;        \
                que->head.prev = &que->head;        \
                que->size = 0;                      \
                que->max_size = 0;                  \
                que->release_flag = XIO_FALSE;

#define     photosrv_queue_single_pop(que, head, node)   \
                head = &que->head;                  \
                if (head->next == head) {           \
                    node = NULL;                    \
                } else {                            \
                    node = head->next;              \
                    head->next = node->next;        \
                    node->next = NULL;              \
                    que->size--;                    \
                }

#define     photosrv_queue_single_push(que, tail, node)  \
                tail = que->head.prev;              \
                tail->next = node;                  \
                node->next = &que->head;            \
                que->head.prev = node;              \
                que->size++;

#define     photosrv_queue_single_get(que, head, node, temp, size, i)            \
                head = &que->head;                                          \
                if (head->next == head) {                                   \
                    node = NULL;                                            \
                } else {                                                    \
                    node = head->next;                                      \
                    temp = node;                                            \
                    for (i = 1; (temp->next != head) && (i < size); i++) {  \
                        temp = temp->next;                                  \
                    }                                                       \
                    if (temp->next != head) {                               \
                        head->next = temp->next;                            \
                        que->size -= size;                                  \
                    } else {                                                \
                        head->next = head;                                  \
                        head->prev = head;                                  \
                        que->size = 0;                                      \
                    }                                                       \
                }
                    
                
                


#define     photosrv_queue_double_pop(que, head, node)   \
                head = &que->head;                  \
                if (head->next == head) {           \
                    node = NULL;                    \
                } else {                            \
                    node = head->next;              \
                    head->next = node->next;        \
                    head->next->prev = head;        \
                    que->size--;                    \
                }

#define     photosrv_queue_double_push(que, tail, node)  \
                tail = que->head.prev;              \
                tail->next = node;                  \
                node->prev = tail;                  \
                node->next = &que->head;            \
                que->head.prev = node;              \
                que->size++;
                

#define     photosrv_queue_double_remove(que, link)      \
                link->prev->next = link->next;      \
                link->next->prev = link->prev;      \
                que->size--;
#endif
