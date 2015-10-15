# Longest Zero Sum Sequence
##问题描述:
```txt
给定一个数列A[1..n], 问能不能找到这样的最长的子序列, 它们的和为0.
即找到i, j(其中1<=i<=j<=n)使得sum(A[i]+...+A[j])=0并且j-i最大.
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

## 参考
https://www.linkedin.com/grp/post/4005475-122870007<br>
http://www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/
