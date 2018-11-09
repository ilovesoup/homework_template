#ifndef HOMEWORK_CPP_EVALUATOR_H
#define HOMEWORK_CPP_EVALUATOR_H

#include <cstddef>
#include "RowData.h"
#include "ASTNode.h"

template <typename T>
class Evaluator {
public:
    virtual T evaluate(RowDataPtr data) = 0;
};

template <typename T>
class EvaluatorBuilder {
public:
    virtual Evaluator<T> * build(AstNodePtr root, void * schema) = 0;
};

#endif //HOMEWORK_CPP_EVALUATOR_H
