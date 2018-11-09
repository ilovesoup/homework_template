package com.pingcap.homework.dummy;

import com.pingcap.homework.ASTNode;
import com.pingcap.homework.Evaluator;
import com.pingcap.homework.RowData;
import java.util.Objects;

public class DummyEvaluator implements Evaluator {
  private final ASTNode root;
  public DummyEvaluator(ASTNode root) {
    this.root = Objects.requireNonNull(root);
  }

  @Override
  public RowData evaluate(RowData data) {
    Object [][] result = new Object[data.getSize()][];
    for (int i = 0; i < data.getSize(); i++) {
      Object val = root.evaluate(data, i);
      result[i] = new Object[] {val};
    }
    return new DummyRowData(result);
  }
}
