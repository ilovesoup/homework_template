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
    Constant(int64_t i) : value(i) { }
    Constant(double d) : value(d) { }
    ~Constant() {}

    Datum evaluate(const RowDataPtr r, int rowID) {
        return value;
    }
private:
    const Datum value;
};


class Plus : public AstNode {
public:
    Plus(AstNodePtr const l, AstNodePtr const r) : left(l), right(r) { }

    Datum evaluate(const RowDataPtr r, int rowID) {
        Datum lVal = left->evaluate(r, rowID);
        Datum rVal = right->evaluate(r, rowID);
        if (lVal.getType() == Datum::Double || rVal.getType() == Datum::Double) {
            return lVal.getDouble() + rVal.getDouble();
        } else {
            return lVal.getInt() + rVal.getInt();
        }
    }
private:
    AstNodePtr const left;
    AstNodePtr const right;
};

class Minus : public AstNode {
public:
    Minus(AstNodePtr const l, AstNodePtr const r) : left(l), right(r) { }

    Datum evaluate(const RowDataPtr r, int rowID) {
        Datum lVal = left->evaluate(r, rowID);
        Datum rVal = right->evaluate(r, rowID);
        if (lVal.getType() == Datum::Double || rVal.getType() == Datum::Double) {
            return lVal.getDouble() + rVal.getDouble();
        } else {
            return lVal.getInt() - rVal.getInt();
        }
    }
private:
    AstNodePtr const left;
    AstNodePtr const right;
};


#endif //HOMEWORK_CPP_ASTNODE_H
