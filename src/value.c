#include "../headers/value.h"

Value value_create_nil() {
  return (Value){TYPEID_NIL,NULL};
}

int value_eq(Value v1, Value v2) {
  return v1.typeId == v2.typeId && v1.ptr == v2.ptr;
}