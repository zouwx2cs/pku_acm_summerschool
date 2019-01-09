// by zouwx2cs
// 有序数组中折半查找
// 复杂度： 时间O(logn)，空间O(1)
// para: array 有序vector
// para: target 查找目标值
// return: int 目标值在vector中的下标，找不到返回-1
int BinarySearch(vector<int> array, const int target)
{
	int l = 0 ;
	int r = array.size() ; // 左闭右开写法
	while (l < r) // 因为是左闭右开，所以这里没有等于的情况
	{
		const int mid = l + ((r-l) >> 1) ; // 为了防止(L+R)过大溢出，且 +- 比 >> 优先级高
		const int pivot = array.at(mid) ;
		if (target < pivot)	// 首先排除概率大的情况可以提升效率
			r = mid ;		// 更新查找范围，注意r，右侧是开区间
		else if (target > pivot)
			l = mid + 1 ;
		else 
			return mid ;
	}
	return -1 ;
}
