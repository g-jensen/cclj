#include "src/specc.h"

#include "../headers/value.h"

module(value_spec, {
  
  describe("value_create", {
    it("populates member variables", {
      int a;
      Value v1;
      v1.typeId = 1;
      v1.ptr = &a;
      Value v2 = value_create(1,&a);
      should_eq(v1.typeId,v2.typeId,unsigned int);
      should_eq(v1.ptr,v2.ptr,void*);
    });
  })

  describe("value_create_nil", {
    it("has TYPEID_NIL typeid and NULL ptr", {
      Value nil = value_create(TYPEID_NIL,NULL);
      Value v = value_create_nil();
      should_eq(nil.typeId,v.typeId,unsigned int);
      should_eq(nil.ptr,v.ptr,void*);
    });
  });

  describe("value_create_false", {
    it("has TYPEID_BOOL typeid and ptr to false", {
      Value _false = value_create(TYPEID_BOOL,&_value_false);
      Value v = value_create_false();
      should_eq(_false.typeId,v.typeId,unsigned int);
      should_eq(_false.ptr,v.ptr,void*);
    });
  });

  describe("value_create_true", {
    it("has TYPEID_BOOL typeid and ptr to true", {
      Value _true = value_create(TYPEID_BOOL,&_value_true);
      Value v = value_create_true();
      should_eq(_true.typeId,v.typeId,unsigned int);
      should_eq(_true.ptr,v.ptr,void*);
    });
  });

  describe("value_eq", {
    it("true with same typeId, same ptr", {
      Value v1 = value_create(0,NULL);
      Value v2 = value_create(0,NULL);
      should(value_eq(v1,v2));
    });

    it("false with different typeId, same ptr", {
      Value v1 = value_create(0,NULL);
      Value v2 = value_create(1,NULL);
      should_not(value_eq(v1,v2));
    });

    it("false with same typeId, different ptr", {
      Value v1 = value_create(0,NULL);
      Value v2 = value_create(0,NULL+1);
      should_not(value_eq(v1,v2));
    });
  });
});