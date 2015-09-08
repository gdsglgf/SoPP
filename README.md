# SoPP
The SoPP is Solution of the Programming Problem.<br>
It includes Online Judge([CodeEval](https://www.codeeval.com "https://www.codeeval.com")), school homeworks and other algorithms.

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
## Input
```txt
6
4 5 6 6 6 6
```
## Output
```txt
1 1 1 4 5 6
```
