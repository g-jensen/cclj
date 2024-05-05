#include "../headers/eval.h"

Value parseBool(char* str) {
  if (strcmp("false",str) == 0)
    return value_create_false();
  else
    return value_create_true();
}

int str_is_blank(char* str) {
  size_t len = strlen(str);
  for (size_t i = 0; i < len; i++)
    if (str[i] != ' ' && str[i] != '\n')
      return 0;
  return 1;
}

Value eval(char* str) {
  if (str_is_blank(str) || strcmp(str,"nil") == 0)
    return value_create_nil();
  else
    return parseBool(str);
}