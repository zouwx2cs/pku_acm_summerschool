// by zouwx2cs
// �����������۰����
// ���Ӷȣ� ʱ��O(logn)���ռ�O(1)
// para: array ����vector
// para: target ����Ŀ��ֵ
// return: int Ŀ��ֵ��vector�е��±꣬�Ҳ�������-1
int BinarySearch(vector<int> array, const int target)
{
	int l = 0 ;
	int r = array.size() ; // ����ҿ�д��
	while (l < r) // ��Ϊ������ҿ�����������û�е��ڵ����
	{
		const int mid = l + ((r-l) >> 1) ; // Ϊ�˷�ֹ(L+R)����������� +- �� >> ���ȼ���
		const int pivot = array.at(mid) ;
		if (target < pivot)	// �����ų����ʴ�������������Ч��
			r = mid ;		// ���²��ҷ�Χ��ע��r���Ҳ��ǿ�����
		else if (target > pivot)
			l = mid + 1 ;
		else 
			return mid ;
	}
	return -1 ;
}
