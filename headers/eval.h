#ifndef _EVAL_H_
#define _EVAL_H_

#include <string.h>

#include "value.h"

static int char_is_blank(char c);
static char* trim_beginning(char* str);
static char* last_token(char* str);
static Value parse_bool(char* str);
static int str_is_bool(char* str);
static int str_is_blank(char* str);

Value eval_create_value(char* str);

#endif