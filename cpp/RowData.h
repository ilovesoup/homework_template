#ifndef HOMEWORK_CPP_ROWDATA_H
#define HOMEWORK_CPP_ROWDATA_H

#include <memory>

struct Datum {
    enum Type { Int, Double } type;
    union {
        int i;
        double d;
    };

    Datum(int value) : type(Int), i(value) { }
    Datum(double value) : type(Double), d(value) { }

    int getInt() {
        if (type == Double) {
            return static_cast<int>(d);
        } else {
            return i;
        }
    }

    double getDouble() {
        if (type == Int) {
            return static_cast<double>(i);
        } else {
            return d;
        }
    }

    Type getType() {
        return type;
    }
};

struct RowData {
    virtual Datum    get(int rowID, int pos) = 0;
    virtual int      getInt(int rowID, int pos) = 0;
    virtual double   getDouble(int rowID, int pos) = 0;
    virtual void *   getSchema() = 0;
    virtual int      getSize() = 0;
};

typedef std::shared_ptr<RowData> RowDataPtr;

#endif //HOMEWORK_CPP_ROWDATA_H
