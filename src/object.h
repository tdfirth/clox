#ifndef clox_object_h
#define clox_object_h

#include "common.h"
#include "value.h"

#define OBJECT_TYPE(value) (AS_OBJECT(value)->type)

#define IS_STRING(value) is_object_type(value, OBJECT_STRING)
#define AS_STRING(value) ((ObjectString *) AS_OBJECT(value))
#define AS_CSTRING(value) (((ObjectString *) AS_OBJECT(value))->chars)

typedef enum {
  OBJECT_STRING,
} ObjectType;

struct sObject {
  ObjectType type;
};

struct sObjectString {
  Object object;
  int length;
  char *chars;
};


static inline bool is_object_type(Value, value, ObjectType type)
{
  return IS_OBJECT(value) && AS_OBJECT(value)->type == type;
}

#endif
