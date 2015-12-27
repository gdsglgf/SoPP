# Longest Zero Sum Sequence
##问题描述:
```txt
给定一个数列A[1..n], 问能不能找到这样的最长的子序列, 它们的和为0.
即找到i, j(其中1<=i<=j<=n)使得sum(A[i]+...+A[j])=0并且(j-i)的值最大.
存在时,输出子序列A[i...j];
不存在这样的子序列时, 返回"False".
```

##输入
```txt
1 2 5 -3 2 -7 1
1 2 3 4 5 6 7 8
1 5 1 0 1 5 1
1 -1 -1 1
```

##输出
```txt
1 2 5 -3 2 -7
False
0
1 -1 -1 1
```

##解题思路
```txt
当sum(A[i]+...+A[j]) = 0时, 下面等式成立
    sum(A[1]+...+A[i - 1]) = sum(A[1]+...+A[j])

因此可使用B[1..n]分别计算出A[1..n]的前i项和, 其中
B[1] = sum(A[1]) = A[1]
B[2] = sum(A[1] + A[2]) = B[1] + A[2]
...
B[n] = sum(A[1] + A[2] + ... + A[n]) = B[n - 1] + A[n]

当B[a] = B[b], 1 <= a < b时, sum(A[a + 1]+...+A[b]) = 0.

注意:使用这种方式, 并不一定能找到最长子序列.
即没有考虑存在B[i] = 0, 1 <= i <= n的情况.

```


## 参考
https://www.linkedin.com/grp/post/4005475-122870007<br>
http://www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/
