#include "src/specc.h"

#include "../headers/eval.h"

module(eval_spec, {
  
  describe("eval", {
    it("\"\"", {
      should(value_eq(value_create_nil(),eval("")));
    });

    it("\"false\"", {
      should(value_eq(value_create_false(),eval("false")));
    });

    it("\"true\"", {
      should(value_eq(value_create_true(),eval("true")));
    });
  });
});