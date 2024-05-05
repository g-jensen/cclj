#include "src/specc.h"

#include "../headers/eval.h"

module(eval_spec, {
  
  describe("eval", {
    it("blank strings", {
      should(value_eq(value_create_nil(),eval("")));
      should(value_eq(value_create_nil(),eval(" ")));
      should(value_eq(value_create_nil(),eval("  ")));
      should(value_eq(value_create_nil(),eval("\n")));
      should(value_eq(value_create_nil(),eval(" \n ")));
    });

    it("\"nil\"", {
      should(value_eq(value_create_nil(),eval("nil")));
    });

    it("\"false\"", {
      should(value_eq(value_create_false(),eval("false")));
    });

    it("\"true\"", {
      should(value_eq(value_create_true(),eval("true")));
    });

    it("\"0\"", {
      should(value_eq(value_create_long(0),eval("0")));
    });

    it("\"1\"", {
      should(value_eq(value_create_long(1),eval("1")));
    });

    it("\"123\"", {
      should(value_eq(value_create_long(123),eval("123")));
    });
  });
});