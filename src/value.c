#include "../headers/value.h"

Value value_construct(unsigned int type_id, void* ptr) {
  return (Value){type_id,ptr};
}

Value value_create_nil() {
  return value_construct(TYPEID_NIL,NULL);
}

Value value_create_false() {
  int* false_ptr = malloc(sizeof(int));
  *false_ptr = 0;
  return value_construct(TYPEID_BOOL,false_ptr);
}

Value value_create_true() {
  int* true_ptr = malloc(sizeof(int));
  *true_ptr = 1;
  return value_construct(TYPEID_BOOL,true_ptr);
}

Value value_create_long(long l) {
  long* long_ptr = malloc(sizeof(long));
  *long_ptr = l;
  return value_construct(TYPEID_NUMBER,long_ptr);
}

void value_destroy(Value v) {
  free(v.ptr);
}

int value_eq(Value v1, Value v2) {
  if (v1.type_id != v2.type_id)
    return 0;
  if (v1.type_id == TYPEID_BOOL)
    return *(int*)(v1.ptr) == *(int*)(v2.ptr);
  if (v1.type_id == TYPEID_NUMBER)
    return *(long*)(v1.ptr) == *(long*)(v2.ptr);
  return v1.ptr == v2.ptr;
}