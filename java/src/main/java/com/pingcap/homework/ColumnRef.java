package com.pingcap.homework;

public class ColumnRef extends ASTNode {
  private final int pos;

  public ColumnRef(int pos) {
    this.pos = pos;
  }

  public int getPos() {
    return pos;
  }

  @Override
  public Object evaluate(RowData r, int rowID) {
    return r.get(rowID, pos);
  }
}
