package com.pingcap.homework;

public class Caster {
  public static double toDouble(Object val) {
    if (val instanceof Integer) {
      return (double)((Integer)val);
    } else if (val instanceof Double) {
      return (Double)val;
    } else {
      throw new UnsupportedOperationException("cannot cast to double");
    }
  }
}
