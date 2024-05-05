#include <string.h>

#include "value.h"

static Value parseBool(char* str);
static int str_is_bool(char* str);
static int str_is_blank(char* str);

Value eval(char* str);