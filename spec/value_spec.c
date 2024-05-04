#include "src/specc.h"

#include "../headers/value.h"

module(value_spec, {
  
  describe("value_create_nil", {
    it("has TYPEID_NIL typeid and null ptr",{
      Value nil;
      nil.typeId = TYPEID_NIL;
      nil.ptr = NULL;
      Value v = value_create_nil();
      should_eq(nil.typeId,v.typeId,unsigned int);
      should_eq(nil.ptr,v.ptr,void*);
    });
  });

  describe("value_eq", {
    it("true with same typeId, same ptr", {
      Value v1;
      v1.typeId = 0;
      v1.ptr = NULL;
      Value v2;
      v2.typeId = 0;
      v2.ptr = NULL;
      should(value_eq(v1,v2));
    });

    it("false with different typeId, same ptr", {
      Value v1;
      v1.typeId = 0;
      v1.ptr = NULL;
      Value v2;
      v2.typeId = 1;
      v2.ptr = NULL;
      should_not(value_eq(v1,v2));
    });

    it("false with same typeId, different ptr", {
      Value v1;
      v1.typeId = 0;
      v1.ptr = NULL;
      Value v2;
      v2.typeId = 0;
      v2.ptr = NULL+1;
      should_not(value_eq(v1,v2));
    });
  });
});