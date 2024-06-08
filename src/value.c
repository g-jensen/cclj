#include "../headers/value.h"

Value value_construct(unsigned int type_id, void* ptr) {
  return (Value){type_id,ptr};
}

Value value_create_nil() {
  return value_construct(VALUE_NIL_TYPEID,NULL);
}

Value value_create_false() {
  int* false_ptr = malloc(sizeof(int));
  *false_ptr = 0;
  return value_construct(VALUE_BOOL_TYPEID,false_ptr);
}

Value value_create_true() {
  int* true_ptr = malloc(sizeof(int));
  *true_ptr = 1;
  return value_construct(VALUE_BOOL_TYPEID,true_ptr);
}

Value value_create_long(long l) {
  long* long_ptr = malloc(sizeof(long));
  *long_ptr = l;
  return value_construct(VALUE_NUMBER_TYPEID,long_ptr);
}

void value_destroy(Value v) {
  free(v.ptr);
}

int value_eq(Value v1, Value v2) {
  if (v1.type_id != v2.type_id)
    return 0;
  if (v1.type_id == VALUE_BOOL_TYPEID)
    return *(int*)(v1.ptr) == *(int*)(v2.ptr);
  if (v1.type_id == VALUE_NUMBER_TYPEID)
    return *(long*)(v1.ptr) == *(long*)(v2.ptr);
  return v1.ptr == v2.ptr;
}

char* str_create_nil() {
  char* out = malloc(sizeof(char)*4);
  strcpy(out,"nil");
  return out;
}

char* str_create_bool(Value v) {
  char* out;
  if (*((int*)v.ptr)) {
    out = malloc(sizeof(char)*5);
    strcpy(out,"true");
  } else {
    out = malloc(sizeof(char)*6);
    strcpy(out,"false");
  }
  return out;
}

char* str_create_long(Value v) {
  char* out = malloc(sizeof(char)*12);
  long_to_ascii(*((long*)v.ptr),out);
  return out;
}

char* value_create_to_string(Value v) {
  if (v.type_id == VALUE_NIL_TYPEID) {
    return str_create_nil();
  } else if (v.type_id == VALUE_BOOL_TYPEID) {
    return str_create_bool(v);
  } else {
    return str_create_long(v);
  }
}