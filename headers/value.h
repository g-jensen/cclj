#ifndef _VALUE_H_
#define _VALUE_H_

#include <stdlib.h>
#include <string.h>

#include "util.h"

#define VALUE_NIL_TYPEID 0
#define VALUE_BOOL_TYPEID 1
#define VALUE_NUMBER_TYPEID 2

typedef struct Value {
  unsigned int type_id;
  void* ptr;
} Value;

static char* str_create_nil();
static char* str_create_bool(Value v);
static char* str_create_long(Value v);

Value value_construct(unsigned int typeId, void* ptr);
Value value_create_nil();
Value value_create_false();
Value value_create_true();
Value value_create_long(long l);

void value_destroy(Value v); // [GMJ] Not testable as far as I know.

int value_eq(Value v1, Value v2);
char* value_create_to_string(Value v);

#endif