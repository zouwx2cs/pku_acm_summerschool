# 线段树（Interval Tree）
1. 是一颗二叉树
2. 线段：树上的每个节点对应于一个线段（区间）
3. 同一层的节点所代表的区间，相互不会重叠且加起来是个连续的区间。

## 重要性质
1. 每个区间的长度是区间内整数的**个数**
2. **叶子节点长度为1**，不可再分
3. 若一个节点对应的区间是[a,b],则其子节点对应的区间分别是[a,(a+b)/2]和[ (a+b)/2+1,b] （除法去尾取整）
4. 线段树的平分构造，实际上是用了二分的方法。若根节点对应的区间是[a,b],那么它的深度为log2(b-a+1) +1 (向上取整）。
5. 线段树节点**要么0度，要么2度**, 因此若叶子节点数目为N,则线段树总结点数目为2N-1

## 线段树的特征
1. 线段树的深度不超过log2(n)+1（向上取整，n是根节点对应区间的长度）。
2. 线段树上，任意一个区间被分解后得到的“终止节点”数目都是log(n)量级。
3. **线段树上<font color=red>更新叶子节点和进行区间分解时间复杂度都是O(log(n))的**</font>。

## 线段树的主要应用

线段树适用于和区间统计有关的问题。比如某些数据可以按区间进行划分，按区间动态进行修改，而且还需要按区间多次进行查询，那么使用线段树可以达到较快查询速度。

#### 应用举例

给你一个数的序列A1A2……An。 并且可能多次进行下列两个操作：
1. 对序列里面的某个数进行加减
2. 询问这个序列里面任意一个连续的子序列AiAi+1……Aj的和是多少

希望第2个操作每次能在log(n)时间内完成

## 线段树的用法
1. 建树
2. 插入
3. 更新&查询

## 线段树结点的结构
	struct CNode
	{
		int L,R ; //线段（区间）起点和终点（含端点）
		int value ; //要保存的值
		CNode * pLeft, * pRight; // 二叉链表示法
	};

----------
# 线段树注意事项
- 注意区间端点是左闭右闭
- **如果用顺序表（数组）替代二叉链，数组大小要开到叶子节点的四倍**
- 顺序表表示法，根节点索引为index时，左孩子的根索引为(index\*2)，右孩子为(index\*2+1)
