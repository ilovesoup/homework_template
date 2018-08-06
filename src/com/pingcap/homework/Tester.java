package com.pingcap.homework;

import com.pingcap.homework.BinaryOpNode.Operation;
import com.pingcap.homework.dummy.DummyEvaluatorBuilder;
import com.pingcap.homework.dummy.DummyRowData;

public class Tester {
  private static final int NUM = 10000000;
  public static void main(String args[]) throws Exception {
    RowData data = loadData();
    ASTNode lhs = new BinaryOpNode(new ColumnRef(0), new Constant(99.88), Operation.Minus);
    ASTNode rhs = new BinaryOpNode(new ColumnRef(1), new ColumnRef(2), Operation.Plus);
    ASTNode expr = new BinaryOpNode(lhs, rhs, Operation.Plus);

    RowData res = baseline(expr, data);
    verify(res);
  }

  private static RowData baseline(ASTNode root, RowData data) {
    EvaluatorBuilder builder = new DummyEvaluatorBuilder();
    Evaluator evaluator = builder.build(root, null);
    long nanoStart = System.nanoTime();
    RowData res = (RowData) evaluator.evaluate(data);
    System.out.println((System.nanoTime() - nanoStart) / 1000000000.0);
    return res;
  }

  private static void verify(RowData r) throws Exception {
    for (int i = 0; i < NUM; i++) {
      double e = (i - 99.88) + (i + 1 + i + 1.1);
      double a = (double)r.get(i, 0);
      if (Math.abs(e - a) > 0.0001) {
        throw new Exception("wrong answer");
      }
    }
  }

  private static RowData loadData() {
    Object [][] data = new Object[NUM][];
    for (int i = 0; i < NUM; i++) {
      data[i] = new Object[]{i, i + 1, i + 1.1};
    }
    return new DummyRowData(data);
  }

}
