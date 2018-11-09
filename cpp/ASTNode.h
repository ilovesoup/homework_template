#ifndef HOMEWORK_CPP_ASTNODE_H
#define HOMEWORK_CPP_ASTNODE_H

#include "RowData.h"

class AstNode;
typedef std::shared_ptr<AstNode> AstNodePtr;

class AstNode {
public:
    virtual ~AstNode() {};
    virtual Datum evaluate(const RowDataPtr r, int rowID) = 0;
};

class ColumnRef : public AstNode {
public:
    ColumnRef(int _pos) : pos(_pos) {}
    ~ColumnRef() {}

    int getPos() {
        return pos;
    }

    Datum evaluate(const RowDataPtr r, int rowID) {
        return r->get(rowID, pos);
    }
private:
    const int pos;
};

class Constant : public AstNode {
public:
    Constant(int i) : value(i) { }
    Constant(double d) : value(d) { }
    ~Constant() {}

    Datum evaluate(const RowDataPtr r, int rowID) {
        return value;
    }
private:
    const Datum value;
};


class BinaryOpNode : public AstNode {
public:
    enum Op {Plus, Minus} op;

    BinaryOpNode(AstNodePtr const l, AstNodePtr const r, Op _op) : left(l), right(r), op(_op) { }
    ~BinaryOpNode() {}

    Datum evaluate(const RowDataPtr r, int rowID) {
        Datum lVal = left->evaluate(r, rowID);
        Datum rVal = right->evaluate(r, rowID);
        switch (op) {
            case Plus:
                if (lVal.getType() == Datum::Double || rVal.getType() == Datum::Double) {
                    return lVal.getDouble() + rVal.getDouble();
                } else {
                    return lVal.getInt() + rVal.getInt();
                }
            case Minus:
                if (lVal.getType() == Datum::Double || rVal.getType() == Datum::Double) {
                    return lVal.getDouble() - rVal.getDouble();
                } else {
                    return lVal.getInt() - rVal.getInt();
                }
        }
    }
private:
    AstNodePtr const left;
    AstNodePtr const right;
};

#endif //HOMEWORK_CPP_ASTNODE_H
