package com.pingcap.homework.dummy;

import com.pingcap.homework.ASTNode;
import com.pingcap.homework.Evaluator;
import com.pingcap.homework.RowData;

import java.util.Objects;

public class DummyEvaluator implements Evaluator {
  private final ASTNode root;

  public DummyEvaluator(ASTNode root) {
    this.root = Objects.requireNonNull(root);
  }

  @Override
  public RowData evaluate(RowData data) {
    final int NumThread = Runtime.getRuntime().availableProcessors();
    final int N = data.getSize();
    Thread[] threads = new Thread[NumThread - 1];
    Object[] result = new Object[data.getSize()];

    for (int i = 0; i < NumThread - 1; i++) {
      final int begin = i;
      Thread t = new Thread(new Runnable() {
        @Override
        public void run() {
          for (int i = begin; i < N; i+= NumThread) {
            result[i] = root.evaluate(data, i);
          }
        }
      });

      t.start();
      threads[i] = t;
    }

    for (int i = NumThread - 1; i < N; i+=NumThread) {
      Object val = root.evaluate(data, i);
      result[i] = val;
    }

    for (int i = 0; i < NumThread - 1; i++ ) {
      try {
        threads[i].join();
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
    return new SingleColumnRowData(result);
  }
}
