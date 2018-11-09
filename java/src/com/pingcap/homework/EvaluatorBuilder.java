package com.pingcap.homework;

public interface EvaluatorBuilder {
  Evaluator build(ASTNode root, Object schema);
}
