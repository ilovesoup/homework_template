package com.pingcap.homework;

public interface RowData {
  Object get(int rowID, int pos);
  int getInt(int rowID, int pos);
  double getDouble(int rowID, int pos);
  Object getSchema();
  int    getSize();
}
