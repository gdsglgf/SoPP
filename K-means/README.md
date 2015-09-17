# K-means
基本K均值算法
```txt
1：选择K个点作为初始质心
2：repeat
3:   将每个点指派到最近的质心，形成K个簇。
4：  重新计算每个簇的质心。
5：until 质心不发生改变。
```

## 变量变换
![将具有有限值域的相异度映射到[0, a]区间](https://github.com/gdsglgf/SoPP/raw/master/K-means/VariableTransformation.jpg)
其中，s和s'分别是相似度的原值和新值，max_s和min_s分别是相似度的最大值和最小值。

## 欧几里得距离
![](https://github.com/gdsglgf/SoPP/raw/master/K-means/EuclideanDistance.jpg)
其中，n是维数，而x<sub>k</sub>和y<sub>k</sub>分别是x和y的第k个属性值（分量）。

测试数据来自[博文](http://www.cnblogs.com/leoo2sk/archive/2010/09/20/k-means.html "http://www.cnblogs.com/leoo2sk/archive/2010/09/20/k-means.html")，测试结果与#47楼回复相同。