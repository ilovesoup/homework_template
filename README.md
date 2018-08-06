This is a homework.
It's a expression evaluator. Users provide expression with row data to evaluate.
The expression includes 

1. Column reference to a column in a row. Pos is the position of column referenced in row (starting from zero)
2. A constant value of double or integer
3. binary operations include Minus and Plus

All value and expressions only have two types: double and int. When performing calculate arithmetic operations, data type is always promoted to larger type. That is, if double plus / minus integer, result will be double; if integer plus integer, result will be integer (no need for promotion).
No NULL value in input data and you don't need to care about it.

Evaluation process has a dummy implementation in com.pingcap.homework.dummy package. 

Your work is to optimize (reimplement) those dummy classes, you might change RowData implementation for better speed; you might optimize evaluator for more effective calculation; you might change whatever you see fit.
But, you cannot assume expression to calculate and the schema of rows are static and hardcoded.
