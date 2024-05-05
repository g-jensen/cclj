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

int value_eq(Value v1, Value v2) {
  return v1.typeId == v2.typeId && v1.ptr == v2.ptr;
}