#ifndef clox_memory_h
#define clox_memory_h

#include "object.h"

#define ALLOCATE(type, count)                                                  \
  (type *)reallocate(NULL, 0, sizeof(type) * (count))

#define FREE(type, pointer) reallocate(pointer, sizeof(type), 0)

// TODO hardcore mode - implement a SLOB/SLAB/SLUB memory allocator for
// yourself. One malloc is allowed at the very start and then you must allocate
// all of the, memory from that in here... sounds trick but awesome.
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity)*2)

#define GROW_ARRAY(previous, type, old_count, count)                           \
  (type *)reallocate(previous, sizeof(type) * (old_count),                     \
                     sizeof(type) * (count))

#define FREE_ARRAY(type, pointer, old_count)                                   \
  reallocate(pointer, sizeof(type) * (old_count), 0)

void *reallocate(void *previous, size_t old_sze, size_t new_size);
void free_objects();

#endif
