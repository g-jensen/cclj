#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdlib.h>
#include <string.h>

#include "value.h"

typedef struct Vector {
  Value* _data;
  long _size;
  size_t _capacity;
} Vector;

Vector vector_create();
void vector_destroy(Vector vec); // not unit testable

char* vector_create_to_str(Vector vec);

long vector_size(Vector vec);
void vector_put(Vector vec, long index, Value value);
void vector_append(Vector vec, Value value);
Value vector_get(Vector vec, long index);
void vector_remove(Vector vec, long index);

#endif