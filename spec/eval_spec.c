#include "src/specc.h"

#include "../headers/eval.h"

module(eval_spec, {
  
  describe("eval", {
    it("empty string", {
      should(value_eq(value_create_nil(),eval("")));
    });
  });
});