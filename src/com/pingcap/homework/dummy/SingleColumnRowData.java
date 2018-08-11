package com.pingcap.homework.dummy;

import com.pingcap.homework.RowData;

public class SingleColumnRowData implements RowData {
  private Object[] rows;


  public SingleColumnRowData(Object[] rows) {
    this.rows = rows;
  }

  @Override
  public Object get(int rowID, int pos) {
    return rows[rowID];
  }

  @Override
  public int getInt(int rowID, int pos) {
    return (int) rows[rowID];
  }

  @Override
  public double getDouble(int rowID, int pos) {
    return (double) rows[rowID];
  }

  @Override
  public Object getSchema() {
    throw new UnsupportedOperationException("not supported");
  }


  @Override
  public int getSize() {
    return rows.length;
  }
}

