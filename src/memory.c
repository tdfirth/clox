#include <stdlib.h>

#include "common.h"
#include "memory.h"
#include "vm.h"

void *reallocate(void *previous, size_t old_size, size_t new_size)
{
  if (new_size == 0) {
    free(previous);
    return NULL;
  }
  return realloc(previous, new_size);
}

static void free_object(Object *object)
{
  switch (object->type) {
  case OBJECT_STRING: {
    ObjectString *string = (ObjectString *)object;
    FREE_ARRAY(char, string->chars, string->length + 1);
    FREE(ObjectString, object);
    break;
  }
  }
}

void free_objects()
{
  Object *object = vm.objects;
  while (object != NULL) {
    Object *next = object->next;
    free_object(object);
    object = next;
  }
}
