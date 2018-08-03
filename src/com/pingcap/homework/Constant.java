package com.pingcap.homework;

public class Constant extends ASTNode {
  private final Object val;

  public Constant(Object val) {
    if (val instanceof Integer || val instanceof Double) {
      this.val = val;
    } else {
      throw new IllegalArgumentException("val must be integer or double");
    }
  }

  @Override
  public Object evaluate(RowData r, int rowID) {
    return val;
  }
}
