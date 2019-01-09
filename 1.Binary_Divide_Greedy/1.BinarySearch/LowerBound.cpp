// by zouwx2cs
// 有序数组中找到不大于目标数且下标最大的元素的下标
// 复杂度： 时间O(logn)，空间O(1)
// para: array 有序vector
// para: target 查找目标值
// return: int 不大于目标数且下标最大的元素的下标，找不到返回-1
int LowerBound(vector<int> array, const int target)
{
	int l = 0 ;
	int r = array.size() ;
	while (l < r)
	{
		const int mid = l + ((r-l) >> 1) ; // 为了防止(L+R)过大溢出:
		if (array.at(mid) >= target) // 命中==也往左走
			r = mid ;
		else
			l = mid+1 ;
	}
	return l-1 ; // 最后落在比目标位置大1的位置
}

