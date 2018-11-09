#ifndef HOMEWORK_CPP_ROWDATA_H
#define HOMEWORK_CPP_ROWDATA_H

#include <memory>

struct Datum {
    enum Type { Int, Double } type;
    union {
        int64_t i;
        double d;
    };

    Datum(int64_t value) : type(Int), i(value) { }
    Datum(double value) : type(Double), d(value) { }

    int64_t getInt() {
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
    virtual Datum    get(int rowID, size_t pos) = 0;
    virtual int64_t  getInt(int rowID, size_t pos) = 0;
    virtual double   getDouble(int rowID, size_t pos) = 0;
    virtual void *   getSchema() = 0;
    virtual size_t   getSize() = 0;
};

typedef std::shared_ptr<RowData> RowDataPtr;

#endif //HOMEWORK_CPP_ROWDATA_H
