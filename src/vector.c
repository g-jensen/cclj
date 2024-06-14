#include "../headers/vector.h"

Vector vector_create() {
  Vector out;
  out._size = 0;
  out._capacity = 8;
  out._data = calloc(out._capacity,sizeof(Value));
  return out;
}

void vector_destroy(Vector vec) {
  free(vec._data);
}

char* vector_create_to_str(Vector vec) {
  char* out = malloc(sizeof(char)*3);
  strcpy(out,"[]");
  return out;
}

long vector_size(Vector vec) {
  return 0;
}