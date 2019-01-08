int BinarySearch(vector<int> array, const int target)
{
	int l = 0 ;
	int r = array.size() ;
	while (l < r)
	{
		const int mid = (l+r) >> 1 ;
		const int pivot = array.at(mid) ;
		if (target < pivot)
			r = mid ;
		else if (target > pivot)
			l = mid + 1 ;
		else 
			return mid ;
	}
	return -1 ;
}
