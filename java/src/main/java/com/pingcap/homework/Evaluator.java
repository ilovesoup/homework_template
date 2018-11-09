package com.pingcap.homework;

public interface Evaluator {
  Object evaluate(RowData data);
  default Class<?> getType() {
    throw new UnsupportedOperationException();
  }
}
