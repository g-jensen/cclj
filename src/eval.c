#include "../headers/eval.h"

char* trim_beginning(char* str) {
  size_t len = strlen(str);
  for (size_t i = 0; i < len; i++) {
    if (!char_is_blank(str[i])) {
      return str+i;
    }
  }
  return str;
}

int char_is_blank(char c) {
  return c == ' ' || c == '\n';
}

char* last_token(char* str) {
  size_t len = strlen(str);
  size_t last_index = 0;
  for (size_t i = 0; i < len; i++)
    if (i != len-1 && char_is_blank(str[i]) && !char_is_blank(str[i+1]))
      last_index = i;
  return trim_beginning(str+last_index);
}

Value parse_bool(char* str) {
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
    if (!char_is_blank(str[i]))
      return 0;
  return 1;
}

Value eval_create_value(char* str) {
  char* last_tok = last_token(str);
  if (str_is_blank(last_tok) || strcmp(last_tok,"nil") == 0)
    return value_create_nil();
  else if (str_is_bool(last_tok))
    return parse_bool(last_tok);
  else {
    char* endptr;
    return value_create_long(strtol(last_tok,&endptr,10));
  }
}