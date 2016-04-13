# SoPP
The SoPP is Solution of the Programming Problem.

### [BankerAlgorithm](https://github.com/gdsglgf/SoPP/tree/master/BankerAlgorithm)
操作系统 银行家算法

### [Bigraph](https://github.com/gdsglgf/SoPP/tree/master/Bigraph)
二分图最大匹配算法

### [FastFindInOrderedMatrix](https://github.com/gdsglgf/SoPP/tree/master/FastFindInOrderedMatrix)
在行列均递增有序的二维数组中快速查找关键字

### [Graph](https://github.com/gdsglgf/SoPP/tree/master/Graph)
图算法: 深度优先搜索, 宽度优先搜索

### [K-means](https://github.com/gdsglgf/SoPP/tree/master/K-means)
K均值算法

### [Knapsack](https://github.com/gdsglgf/SoPP/tree/master/Knapsack)
计算0-1背包, 完全背包最大价值和选择的物品

### [LongestZeroSumSequence](https://github.com/gdsglgf/SoPP/tree/master/LongestZeroSumSequence)
找出和为0的最长子序列

### [Sorting](https://github.com/gdsglgf/SoPP/tree/master/Sorting)
计数排序, 堆排序, 插入排序, 归并排序, 快排, 基数排序

### [StringMatching](https://github.com/gdsglgf/SoPP/tree/master/StringMatching)
字符串匹配: 蛮力搜索, Horspool, KMP

### [WorkAssignment](https://github.com/gdsglgf/SoPP/tree/master/WorkAssignment)
任务指派问题

### Code Demo

```java
import java.util.Scanner;
import java.util.Stack;
import java.io.FileNotFoundException;
import java.io.File;


class MutableInteger {
	public MutableInteger() {
		this.value = 0;
	}
	
	public MutableInteger(int value) {
		this.value = value;
	}
	
	public int getValue() {
		return value;
	}
	
	public void setValue(int value) {
		this.value = value;
	}
	
	public void add(int n) {
		value += n;
	}
	
	private int value;
}


public class ParnerMatcher {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File(args[0]));
		int n = sc.nextInt();

		Stack<MutableInteger> stack = new Stack<MutableInteger>();

		int base = 0;
		for (int i = 0; i < n; i++) {
			int temp = sc.nextInt();
			int num = temp - base;
			// push num numbers to stack
			for (int j = 0; j < num; j++) {
				stack.push(new MutableInteger(1));
			}

			// pop the stack and store the counter as result
			MutableInteger mi = stack.pop();
			System.out.printf("%d ", mi.getValue());
			
			// peek the stack and increase the counter
			if (!stack.empty()) {
				MutableInteger top = stack.peek();
				top.add(mi.getValue());
			}

			base = temp;
		}
		System.out.println();
	}
}
```
### Input
```txt
6
4 5 6 6 6 6
```
### Output
```txt
1 1 1 4 5 6
```
