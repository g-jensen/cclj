#include <string.h>

#include "value.h"

static char* trim_beginning(char* str);
static int char_is_blank(char c);
static char* last_token(char* str);
static Value parseBool(char* str);
static int str_is_bool(char* str);
static int str_is_blank(char* str);

Value eval_create_value(char* str);