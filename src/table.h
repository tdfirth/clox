#ifndef clox_table_h
#define clox_table_h

#include "common.h"
#include "value.h"

typedef struct {
  ObjectString *key;
  Value value;
} Entry;

typedef struct {
  int count;
  int capacity;
  Entry *entries;
} Table;

void init_table(Table *table);
void free_table(Table *table);
bool table_get(Table *table, ObjectString *key, Value *value);
bool table_set(Table *table, ObjectString *key, Value value);
bool table_delete(Table *table, ObjectString *key);
void table_add_all(Table *from, Table *to);
ObjectString *table_find_string(Table *table, const char *chars, int length,
                                uint32_t hash);

#endif
