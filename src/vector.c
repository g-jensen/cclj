#include "../headers/vector.h"

Vector* vector_create() {
  Vector* out = (Vector*)malloc(sizeof(Value));
  out->_size = 0;
  out->_capacity = 8;
  out->_data = calloc(out->_capacity,sizeof(Value));
  return out;
}

void vector_destroy(Vector* vec) {
  for (size_t i = 0; i < vec->_size; i++) {
    value_destroy(vec->_data[i]);
  }
  free(vec->_data);
  free(vec);
}

char* vector_create_to_str(Vector* vec) {
  char* out = malloc(sizeof(char)*3);
  strcpy(out,"[]");
  return out;
}

long vector_size(Vector* vec) {
  return vec->_size;
}

void vector_put(Vector* vec, long index, Value value) {
  vec->_size = 1;
  vec->_data[index] = value;
}

Value vector_get(Vector* vec, long index) {
  return vec->_data[0];
}