This is a homework.
It's a expression evaluator. Users provide expression with row data to evaluate.
The expression includes a) column reference to a column in a row b) A constant value c) binary operations include Minus and Plus
All value and expressions only have two types: double and int. When calculate arithmetic operations, data type are always promoted to larger type.
That is, if double plus / minus integer, result will be double; if integer plus integer, result will be integer (no need for promotion).
No NULL value in input data.

Evaluation process has a dummy implementation in com.pingcap.homework.dummy package. 

Your work is to optimize those classes, you might change RowData implementation for better speed; you might optimize evaluator for more effective calculation; you might change whatever you see fit.
But, you cannot assume expression to calculate, the schema of rows are static and hardcoded.
