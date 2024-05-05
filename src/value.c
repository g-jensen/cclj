#include "../headers/value.h"

int _value_false = 0;
int _value_true = 1;

Value _value_create(unsigned int typeId, void* ptr) {
  return (Value){typeId,ptr};
}

Value value_create_nil() {
  return _value_create(TYPEID_NIL,NULL);
}

Value value_create_false() {
  int* false_ptr = malloc(sizeof(int));
  *false_ptr = 0;
  return _value_create(TYPEID_BOOL,false_ptr);
}

Value value_create_true() {
  int* true_ptr = malloc(sizeof(int));
  *true_ptr = 1;
  return _value_create(TYPEID_BOOL,true_ptr);
}

Value value_create_long(long l) {
  long* long_ptr = malloc(sizeof(long));
  *long_ptr = l;
  return _value_create(TYPEID_NUMBER,long_ptr);
}

void value_destroy(Value v) {
  free(v.ptr);
}

int value_eq(Value v1, Value v2) {
  if (v1.typeId != v2.typeId)
    return 0;
  if (v1.typeId == TYPEID_BOOL) {
    return *(int*)(v1.ptr) == *(int*)(v2.ptr);
  }
  if (v1.typeId == TYPEID_NUMBER)
    return *(long*)(v1.ptr) == *(long*)(v2.ptr);
  return v1.ptr == v2.ptr;
}