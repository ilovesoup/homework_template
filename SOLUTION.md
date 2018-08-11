目前对dummy包的优化只有下面两个:

1. 对DummyEvaluator加入了并发, 线程数为核心数;
2. 优化DummyEvaluator中的'new Object[]{val}'语句, 以减少对象申请, 通过SingleColumnRowData实现;

其他还有一些点, 只修改dummy不能实现, 可能想法有点走偏, 所以没有实现, 只是写在这里;

<b>1-BinaryOpNode内大量使用instanceof</b>

对java不是很熟悉, 不太清楚这类操作是否费时;

可实现一个自己的值类型, 来优化掉这个操作, 如:
```
public class Value {
    int type;
    Object value;
}
```

<b>2-GC问题</b>

实际上线测试时, 发现GC影响非常大;

Evaluator内主要会大量创建对象的地方有两个;

一是Evaluator内的'new Object[]{val}'语句, 这部分如上所说, 已经优化掉了;

二是BinaryOpNode内大量创建对象, 目前没有什么好的优化思路;

测试时用了比较暴力的做法, 设置了jvm参数 -Xms16G -Xmx32G, 效果非常明显;