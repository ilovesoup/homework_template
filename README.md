This is a homework. You can choose to implement it in either C++ or Java (C++ preferred)
It's an expression evaluator (consider its an evaluator as a database runtime). Users provide expression with row data to evaluate. 
The expression includes 

1. Column reference to a column in a row. Pos is the position of column referenced in row (starting from zero)
2. A constant value of double or integer
3. binary operations include Minus and Plus

All value and expressions only have two types: double and int. When performing arithmetic operations, data type is always promoted to larger type. That is, if double plus / minus integer, result will be double; if integer plus integer, result will be integer (no need for promotion).
No NULL value in input data and you don't need to care about it.

Evaluation process has a dummy implementation in com.pingcap.homework.dummy package (Java) or source files in dummy folder (C++). 

Your work has two parts:
1. Analyze why this piece of code is slow and inefficient. [Optional] Provide an report with evidence (for example, CPU efficiency, cache locality, branch miss or GC pause and etc) and reasoning.
2. According to your analysis, optimize (reimplement) those dummy classes: make it as fast as you can. You might change RowData implementation for better speed; you might optimize evaluator for more effective calculation; you might change whatever you see fit (even slightly change interfaces provided).
But, you cannot assume expression to calculate and the schema of rows are static (schemas are the same for all rows in a single test but might change between tests) and hardcoded.

Please don't fork and submit your solution. Send us your code by mail please :)
