#include "../headers/value.h"

int _value_false = 0;
int _value_true = 1;

Value value_create(unsigned int typeId, void* ptr) {
  return (Value){typeId,ptr};
}

Value value_create_nil() {
  return value_create(TYPEID_NIL,NULL);
}

Value value_create_false() {
  return value_create(TYPEID_BOOL,&_value_false);
}

Value value_create_true() {
  return value_create(TYPEID_BOOL,&_value_true);
}

Value value_create_long(long l) {
  long* long_ptr = malloc(sizeof(long));
  *long_ptr = l;
  return value_create(TYPEID_NUMBER,long_ptr);
}

int value_eq(Value v1, Value v2) {
  if (v1.typeId != v2.typeId)
    return 0;
  if (v1.typeId == TYPEID_NUMBER)
    return *(long*)(v1.ptr) == *(long*)(v2.ptr);
  return v1.ptr == v2.ptr;
}