#ifndef HOMEWORK_CPP_DUMMYEVALUATOR_H
#define HOMEWORK_CPP_DUMMYEVALUATOR_H

#include "../Evaluator.h"
#include "../RowData.h"
#include <vector>
#include <exception>

using std::vector;

typedef vector<Datum> Row;

class DummyRowData : public RowData {
public:
    DummyRowData(int rowCount) {}
    ~DummyRowData() {}

    Datum get(int rowID, int pos)  {
        return rows[rowID][pos];
    }

    int getInt(int rowID, int pos) {
        return rows[rowID][pos].getInt();
    }

    double getDouble(int rowID, int pos) {
        return rows[rowID][pos].getDouble();
    }

    void * getSchema() {
        throw std::runtime_error("unsupported operation getSchema");
    }

    int getSize() {
        return rows.size();
    }

    void addRow(Row & row) {
        rows.push_back(row);
    }
private:
    vector<Row> rows;
};

class DummyEvalutor : public Evaluator<RowDataPtr> {
public:
    DummyEvalutor(AstNodePtr _root) : root(_root) {}
    ~DummyEvalutor() {}

    RowDataPtr evaluate(RowDataPtr data) {
        DummyRowData * pRows = new DummyRowData(data->getSize());
        int size = data->getSize();
        for (int i = 0; i < size; i++) {
            Datum val = root->evaluate(data, i);
            Row row;
            row.push_back(val);
            pRows->addRow(row);
        }
        return RowDataPtr(pRows);
    }

private:
    AstNodePtr const root;
};


class DummyEvaluatorBuilder : public EvaluatorBuilder<RowDataPtr> {
public:
    Evaluator<RowDataPtr> * build(AstNodePtr root, void * schema) {
        return new DummyEvalutor(root);
    }
};

#endif //HOMEWORK_CPP_DUMMYEVALUATOR_H
