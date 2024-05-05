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
      Value false = value_create(TYPEID_BOOL,&_value_false);
      Value v = value_create_false();
      should_eq(false.typeId,v.typeId,unsigned int);
      should_eq(false.ptr,v.ptr,void*);
    });
  });

  describe("value_create_true", {
    it("has TYPEID_BOOL typeid and ptr to true", {
      Value true = value_create(TYPEID_BOOL,&_value_true);
      Value v = value_create_true();
      should_eq(true.typeId,v.typeId,unsigned int);
      should_eq(true.ptr,v.ptr,void*);
    });
  });

  describe("value_create_long", {
    it("creates 0", {
      Value v = value_create_long(0);
      should_eq(TYPEID_NUMBER,v.typeId,unsigned int);
      should_eq(0,*(long*)(v.ptr),long);
      free(v.ptr);
    });

    it("creates 1", {
      Value v = value_create_long(1);
      should_eq(TYPEID_NUMBER,v.typeId,unsigned int);
      should_eq(1,*(long*)(v.ptr),long);
      free(v.ptr);
    });

    it("creates -1", {
      Value v = value_create_long(-1);
      should_eq(TYPEID_NUMBER,v.typeId,unsigned int);
      should_eq(-1,*(long*)(v.ptr),long);
      free(v.ptr);
    });
  });

  describe("value_eq", {
    it("same typeId, same ptr", {
      Value v1 = value_create(0,NULL);
      Value v2 = value_create(0,NULL);
      should(value_eq(v1,v2));
    });

    it("different typeId, same ptr", {
      Value v1 = value_create(0,NULL);
      Value v2 = value_create(1,NULL);
      should_not(value_eq(v1,v2));
    });

    it("same typeId, different ptr", {
      Value v1 = value_create(0,NULL);
      Value v2 = value_create(0,NULL+1);
      should_not(value_eq(v1,v2));
    });

    it("true is not equal to false", {
      Value v1 = value_create_true();
      Value v2 = value_create_false();
      should_not(value_eq(v1,v2));
    });

    it("true is equal to true", {
      Value v1 = value_create_true();
      Value v2 = value_create_true();
      should(value_eq(v1,v2));
    });

    it("false is equal to false", {
      Value v1 = value_create_false();
      Value v2 = value_create_false();
      should(value_eq(v1,v2));
    });

    it("nil is not equal to booleans", {
      Value nil = value_create_nil();
      Value false = value_create_false();
      Value true = value_create_true();
      should_not(value_eq(nil,false));
      should_not(value_eq(nil,true));
    });
  });
});