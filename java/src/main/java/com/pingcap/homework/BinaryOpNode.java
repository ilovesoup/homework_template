package com.pingcap.homework;

import java.util.Objects;

public class BinaryOpNode extends ASTNode {
  private final ASTNode left;
  private final ASTNode right;

  @Override
  public Object evaluate(RowData r, int rowID) {
    Object lhs = left.evaluate(r, rowID);
    Object rhs = right.evaluate(r, rowID);
    switch (op) {
      case Plus:
        if (lhs instanceof Double || rhs instanceof Double) {
          return Caster.toDouble(lhs) + Caster.toDouble(rhs);
        } else {
          return (Integer)lhs + (Integer)rhs;
        }
      case Minus:
        if (lhs instanceof Double || rhs instanceof Double) {
          return Caster.toDouble(lhs) - Caster.toDouble(rhs);
        } else {
          return (Integer)lhs - (Integer)rhs;
        }
    }

    throw new UnsupportedOperationException("operation not supported");
  }

  public ASTNode getLeft() {
    return left;
  }

  public ASTNode getRight() {
    return right;
  }

  public Operation getOp() {
    return op;
  }

  public enum Operation {
    Plus, Minus
  }

  public final Operation op;

  protected BinaryOpNode(ASTNode left, ASTNode right, Operation op) {
    this.left = Objects.requireNonNull(left);
    this.right = Objects.requireNonNull(right);
    this.op = op;
  }
}
