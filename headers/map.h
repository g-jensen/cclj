#ifndef _MAP_H_
#define _MAP_H_

#include "value.h"

Value* map_create();
void map_destroy(Value* map);
char* map_create_to_str(Value* map);
void map_put(Value* map, Value key, Value value);
Value map_get(Value* map, Value key);

#endif