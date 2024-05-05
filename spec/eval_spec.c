#include "src/specc.h"

#include "../headers/eval.h"

module(eval_spec, {
  
  describe("eval_create_value blank strings", {
    it("\"\"", {
      Value nil = value_create_nil();
      Value v = eval_create_value("");
      should(value_eq(nil,v));
      value_destroy(v);
    });

    it("\" \"", {
      Value nil = value_create_nil();
      Value v = eval_create_value(" ");
      should(value_eq(nil,v));
      value_destroy(v);
    });

    it("\"  \"", {
      Value nil = value_create_nil();
      Value v = eval_create_value("  ");
      should(value_eq(nil,v));
      value_destroy(v);
    });

    it("\"\\n\"", {
      Value nil = value_create_nil();
      Value v = eval_create_value("\n");
      should(value_eq(nil,v));
      value_destroy(v);
    });

    it("\" \\n \"", {
      Value nil = value_create_nil();
      Value v = eval_create_value(" \n ");
      should(value_eq(nil,v));
      value_destroy(v);
    });
  });

  describe("eval_create_value single literals", {
    it("\"nil\"", {
      Value nil = value_create_nil();
      Value v = eval_create_value("nil");
      should(value_eq(nil,v));
      value_destroy(v);
      value_destroy(nil);
    });

    it("\"false\"", {
      Value false = value_create_false();
      Value v = eval_create_value("false");
      should(value_eq(false,v));
      value_destroy(v);
      value_destroy(false);
    });

    it("\"true\"", {
      Value true = value_create_true();
      Value v = eval_create_value("true");
      should(value_eq(true,v));
      value_destroy(v);
      value_destroy(true);
    });

    it("\"0\"", {
      Value zero = value_create_long(0);
      Value v = eval_create_value("0");
      should(value_eq(zero,v));
      value_destroy(v);
      value_destroy(zero);
    });

    it("\"1\"", {
      Value one = value_create_long(1);
      Value v = eval_create_value("1");
      should(value_eq(one,v));
      value_destroy(v);
      value_destroy(one);
    });

    it("\"-1\"", {
      Value neg_one = value_create_long(-1);
      Value v = eval_create_value("-1");
      should(value_eq(neg_one,v));
      value_destroy(v);
      value_destroy(neg_one);
    });

    it("\"123\"", {
      Value onetwothree = value_create_long(123);
      Value v = eval_create_value("123");
      should(value_eq(onetwothree,v));
      value_destroy(v);
      value_destroy(onetwothree);
    });
  });
});