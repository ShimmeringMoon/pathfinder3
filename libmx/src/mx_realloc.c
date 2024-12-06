#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL) return malloc(size);
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    void *new_ptr = malloc(size);
    if (new_ptr == NULL) return NULL;
    size_t cur = malloc_usable_size(ptr);
    cur = (cur < size) ? cur : size;
    mx_memcpy(new_ptr, ptr, cur);
    free(ptr);
    return new_ptr;
}
