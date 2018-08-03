package com.pingcap.homework.dummy;

import com.pingcap.homework.ASTNode;
import com.pingcap.homework.Evaluator;
import com.pingcap.homework.EvaluatorBuilder;

public class DummyEvaluatorBuilder implements EvaluatorBuilder {

  @Override
  public Evaluator build(ASTNode root) {
    return new DummyEvaluator(root);
  }
}
