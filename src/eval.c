#include "../headers/eval.h"

Value parseBool(char* str) {
  if (strcmp("false",str) == 0)
    return value_create_false();
  else
    return value_create_true();
}

int str_is_bool(char* str) {
  return strcmp(str,"false") == 0 || strcmp(str,"true") == 0;
}

int str_is_blank(char* str) {
  size_t len = strlen(str);
  for (size_t i = 0; i < len; i++)
    if (str[i] != ' ' && str[i] != '\n')
      return 0;
  return 1;
}

Value eval_create_value(char* str) {
  if (str_is_blank(str) || strcmp(str,"nil") == 0)
    return value_create_nil();
  else if (str_is_bool(str))
    return parseBool(str);
  else {
    char* endptr;
    return value_create_long(strtol(str,&endptr,10));
  }
}