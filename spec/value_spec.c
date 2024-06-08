#include "src/specc.h"

#include "../headers/value.h"

module(value_spec, {
  
  describe("value_construct", {
    it("populates member variables", {
      int a;
      Value v1;
      v1.type_id = 1;
      v1.ptr = &a;
      Value v2 = value_construct(1,&a);
      should_eq(v1.type_id,v2.type_id,unsigned int);
      should_eq(v1.ptr,v2.ptr,void*);
    });
  });

  describe("value_create_nil", {
    it("has VALUE_NIL_TYPEID typeid and NULL ptr", {
      Value v = value_create_nil();
      should_eq(VALUE_NIL_TYPEID,v.type_id,unsigned int);
      should_eq(NULL,v.ptr,void*);
      value_destroy(v);
    });
  });

  describe("value_create_false", {
    it("has VALUE_BOOL_TYPEID typeid and ptr to false", {
      Value v = value_create_false();
      should_eq(VALUE_BOOL_TYPEID,v.type_id,unsigned int);
      should_eq(0,*(int*)(v.ptr),int);
      value_destroy(v);
    });
  });

  describe("value_create_true", {
    it("has VALUE_BOOL_TYPEID typeid and ptr to true", {
      Value v = value_create_true();
      should_eq(VALUE_BOOL_TYPEID,v.type_id,unsigned int);
      should_eq(1,*(int*)(v.ptr),int);
      value_destroy(v);
    });
  });

  describe("value_create_long", {
    it("creates 0", {
      Value v = value_create_long(0);
      should_eq(VALUE_NUMBER_TYPEID,v.type_id,unsigned int);
      should_eq(0,*(long*)(v.ptr),long);
      value_destroy(v);
    });

    it("creates 1", {
      Value v = value_create_long(1);
      should_eq(VALUE_NUMBER_TYPEID,v.type_id,unsigned int);
      should_eq(1,*(long*)(v.ptr),long);
      value_destroy(v);
    });

    it("creates -1", {
      Value v = value_create_long(-1);
      should_eq(VALUE_NUMBER_TYPEID,v.type_id,unsigned int);
      should_eq(-1,*(long*)(v.ptr),long);
      value_destroy(v);
    });
  });

  describe("value_eq", {
    it("same type_id, same ptr", {
      Value v1 = value_construct(0,NULL);
      Value v2 = value_construct(0,NULL);
      should(value_eq(v1,v2));
    });

    it("different type_id, same ptr", {
      Value v1 = value_construct(0,NULL);
      Value v2 = value_construct(1,NULL);
      should_not(value_eq(v1,v2));
    });

    it("same type_id, different ptr", {
      Value v1 = value_construct(0,NULL);
      Value v2 = value_construct(0,NULL+1);
      should_not(value_eq(v1,v2));
    });

    context("booleans", {
      it("true is not equal to false", {
        Value v1 = value_create_true();
        Value v2 = value_create_false();
        should_not(value_eq(v1,v2));
        value_destroy(v1);
        value_destroy(v2);
      });

      it("true is equal to true", {
        Value v1 = value_create_true();
        Value v2 = value_create_true();
        should(value_eq(v1,v2));
        value_destroy(v1);
        value_destroy(v2);
      });

      it("false is equal to false", {
        Value v1 = value_create_false();
        Value v2 = value_create_false();
        should(value_eq(v1,v2));
        value_destroy(v1);
        value_destroy(v2);
      });

      it("nil is not equal to booleans", {
        Value nil = value_create_nil();
        Value false = value_create_false();
        Value true = value_create_true();
        should_not(value_eq(nil,false));
        should_not(value_eq(nil,true));
        value_destroy(nil);
        value_destroy(false);
        value_destroy(true);
      });
    });

    context("numbers", {
      it("long 0 is equal to long 0", {
        Value zero1 = value_create_long(0);
        Value zero2 = value_create_long(0);
        should(value_eq(zero1,zero2));
        value_destroy(zero1);
        value_destroy(zero2);
      });

      it("long 0 is not equal to long 1", {
        Value zero = value_create_long(0);
        Value one = value_create_long(1);
        should_not(value_eq(zero,one));
        value_destroy(zero);
        value_destroy(one);
      });

      it("long 0 is not equal to nil", {
        Value zero = value_create_long(0);
        Value nil = value_create_nil();
        should_not(value_eq(zero,nil));
        value_destroy(zero);
        value_destroy(nil);
      });
    });
  });

  context("value_create_to_string", {
    
    it("nil", {
      Value nil = value_create_nil();
      char* str = value_create_to_string(nil);
      should_str_eq("nil",str);
      value_destroy(nil);
      free(str);
    });

    context("bool", {
      
      it("true", {
        Value true = value_create_true();
        char* str = value_create_to_string(true);
        should_str_eq("true",str);
        value_destroy(true);
        free(str);
      });

      it("false", {
        Value false = value_create_false();
        char* str = value_create_to_string(false);
        should_str_eq("false",str);
        value_destroy(false);
        free(str);
      });
    });

    context("long", {

      it("1", {
        Value one = value_create_long(1);
        char* str = value_create_to_string(one);
        should_str_eq("1",str);
        value_destroy(one);
        free(str);
      });

      it("0", {
        Value zero = value_create_long(0);
        char* str = value_create_to_string(zero);
        should_str_eq("0",str);
        value_destroy(zero);
        free(str);
      });

      it("-1", {
        Value neg_1 = value_create_long(-1);
        char* str = value_create_to_string(neg_1);
        should_str_eq("-1",str);
        value_destroy(neg_1);
        free(str);
      });

      it("15", {
        Value fifteen = value_create_long(15);
        char* str = value_create_to_string(fifteen);
        should_str_eq("15",str);
        value_destroy(fifteen);
        free(str);
      });

      it("-15", {
        Value neg_fifteen = value_create_long(-15);
        char* str = value_create_to_string(neg_fifteen);
        should_str_eq("-15",str);
        value_destroy(neg_fifteen);
        free(str);
      });

      it("-2147483647", {
        Value long_min = value_create_long(-2147483647);
        char* str = value_create_to_string(long_min);
        should_str_eq("-2147483647",str);
        value_destroy(long_min);
        free(str);
      });

      it("2147483647", {
        Value long_max = value_create_long(2147483647);
        char* str = value_create_to_string(long_max);
        should_str_eq("2147483647",str);
        value_destroy(long_max);
        free(str);
      });

    });
  });
});