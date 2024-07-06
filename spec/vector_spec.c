#include "src/specc.h"

#include "../headers/vector.h"

module(vector, {

  describe("vector_create_to_str", {
    it("empty vector", {
      Vector* vec = vector_create();
      char* str = vector_create_to_str(vec);
      should_str_eq("[]",str);
      free(str);
      vector_destroy(vec);
    });
  });

  describe("modifying vector", {
    context("putting in an empty vector", {
      it("index 0", {
        Vector* vec = vector_create();
        Value one = value_create_long(1);
        vector_put(vec,0,one);
        should_eq(1,vector_size(vec),long);
        should(value_eq(one,vector_get(vec,0)));
        vector_destroy(vec);
      });
    });
  });

});