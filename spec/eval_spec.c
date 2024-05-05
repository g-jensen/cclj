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
  });
});