#include <stdlib.h>

#define TYPEID_NIL 0

typedef struct Value {
  unsigned int typeId;
  void* ptr;
} Value;

Value value_create(unsigned int typeId, void* ptr);
Value value_create_nil();
int value_eq(Value v1, Value v2);