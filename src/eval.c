#include "../headers/eval.h"

Value parseBool(char* str) {
  if (strcmp("false",str) == 0)
    return value_create_false();
  else
    return value_create_true();
}

Value eval(char* str) {
  if (strcmp("",str) == 0)
    return value_create_nil();
  else
    return parseBool(str);
}