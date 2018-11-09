package com.pingcap.homework;

public abstract class ASTNode {
  public abstract Object evaluate(RowData r, int rowID);
}
