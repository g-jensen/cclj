#include "src/specc.h"

#include "../headers/vector.h"

module(vector, {

  describe("vector_create", {
    it("has 0 size", {
      Vector vec = vector_create();
      should_eq(0, vec._size,long);
      vector_destroy(vec);
    });

    it("has 8 capacity", {
      Vector vec = vector_create();
      should_eq(8, vec._capacity,long);
      vector_destroy(vec);
    });
  });

  describe("vector_create_to_str", {
    it("empty vector", {
      Vector vec = vector_create();
      char* str = vector_create_to_str(vec);
      should_str_eq("[]",str);
      free(str);
      vector_destroy(vec);
    });
  });

  describe("vector_size", {
    it("empty vector", {
      Vector vec = vector_create();
      should_eq(0,vector_size(vec),long);
      vector_destroy(vec);
    });
  });

  describe("vector_put", {
    context("empty vector", {
      it("index 0", {
        Vector vec = vector_create();
        Value one = value_create_long(1);
        vector_put(vec,0,one);
        should_eq(0,vector_size(vec),long);
        vector_destroy(vec);
      });
    });
  });

});