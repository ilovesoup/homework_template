package com.pingcap.homework.dummy;

import com.pingcap.homework.RowData;

public class DummyRowData implements RowData {

  private Object [][] rows;

  public DummyRowData(Object[][] rows) {
    this.rows = rows;
  }

  @Override
  public Object getSchema() {
    throw new UnsupportedOperationException("not supported");
  }

  @Override
  public int getSize() {
    return rows.length;
  }

  @Override
  public Object get(int rowID, int pos) {
    return rows[rowID][pos];
  }

  @Override
  public int getInt(int rowID, int pos) {
    return (int)rows[rowID][pos];
  }

  @Override
  public double getDouble(int rowID, int pos) {
    return (double)rows[rowID][pos];
  }
}
