int LowerBound(vector<int> array, const int target)
{
	int l = 0 ;
	int r = array.size() ;
	int lastPos = -1 ;
	while ( l < r)
	{
		const int mid = (l+r) >> 1 ;
		if (array.at(mid) >= target)
		{
			r = mid ;
		}
		else
		{
			lastPos = mid-1 ;
			l = mid+1 ;
		}
	}
	return lastPos ;
}


