#include <stdio.h>
#include <string.h>

#include "memory.h"
#include "object.h"
#include "value.h"
#include "vm.h"

#define ALLOCATE_OBJECT(type, object_type)                                     \
  (type *)allocate_object(sizeof(type), object_type)

static Object *allocate_object(size_t size, ObjectType type)
{
  Object *object = (Object *)reallocate(NULL, 0, size);
  object->type = type;
  object->next = vm.objects;
  vm.objects = object;
  return object;
}

static ObjectString *allocate_string(char *chars, int length)
{
  ObjectString *string = ALLOCATE_OBJECT(ObjectString, OBJECT_STRING);
  string->length = length;
  string->chars = chars;
  return string;
}

ObjectString *take_string(char *chars, int length)
{
  return allocate_string(chars, length);
}

ObjectString *copy_string(const char *chars, int length)
{
  char *heap_chars = ALLOCATE(char, length + 1);
  memcpy(heap_chars, chars, length);
  heap_chars[length] = '\0';
  return allocate_string(heap_chars, length);
}

void print_object(Value value)
{
  switch (OBJECT_TYPE(value)) {
  case OBJECT_STRING:
    printf("%s", AS_CSTRING(value));
    break;
  }
}
