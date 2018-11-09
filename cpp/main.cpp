#include <iostream>
#include "ASTNode.h"
#include "RowData.h"
#include "dummy/DummyEvaluator.h"
#include <iostream>
#include <chrono>
#include <cmath>
#include <exception>
#include <memory>

using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using std::make_shared;
using std::unique_ptr;

const int NUM = 10000000;

void verify(RowDataPtr r) {
    for (int i = 0; i < NUM; i++) {
        double e = (i - 99.88) + (i + 1 + i + 1.1);
        double a = r->getDouble(i, 0);
        if (abs(e - a) > 0.0001) {
            throw new std::runtime_error("wrong answer");
        }
    }
}

RowDataPtr loadData() {
    DummyRowData * const pDummyRaw = new DummyRowData(NUM);
    RowDataPtr pData(pDummyRaw);
    for (int i = 0; i < NUM; i++) {
        Row row{Datum(i), Datum(i + 1), Datum(i + 1.1)};
        pDummyRaw->addRow(row);
    }
    return pData;
}


void baseline(AstNodePtr root) {
    RowDataPtr pData = loadData();
    DummyEvaluatorBuilder builder;
    unique_ptr<Evaluator<RowDataPtr>> evaluator(builder.build(root, NULL));
    cout << "baseline started..." << endl;
    auto start = high_resolution_clock::now();
    RowDataPtr pRes = evaluator->evaluate(pData);
    auto end = high_resolution_clock::now();
    cout << duration_cast<nanoseconds>(end - start).count() / 1000000000.0 << "s" << endl;

    verify(pRes);
}

void userCode(AstNodePtr root) {}


int main() {
    // col(0) = i; col(1) = i + 1; col(2) = i + 1.1
    // lhs = col(0) - 99.98 = i - 99.98
    // rhs = col(1) + col(2) = i + 1 + i + 1.1 = 2i + 2.1
    // expr = 3i + 97.88
    AstNodePtr lhs(new BinaryOpNode(AstNodePtr(new ColumnRef(0)), AstNodePtr(new Constant(99.88)), BinaryOpNode::Minus));
    AstNodePtr rhs(new BinaryOpNode(AstNodePtr(new ColumnRef(1)), AstNodePtr(new ColumnRef(2)), BinaryOpNode::Plus));
    AstNodePtr expr(new BinaryOpNode(lhs, rhs, BinaryOpNode::Plus));

    userCode(expr);
    baseline(expr);

    return 0;
}