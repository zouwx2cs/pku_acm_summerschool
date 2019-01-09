// by zouwx2cs
// �����������ҵ�������Ŀ�������±�����Ԫ�ص��±�
// ���Ӷȣ� ʱ��O(logn)���ռ�O(1)
// para: array ����vector
// para: target ����Ŀ��ֵ
// return: int ������Ŀ�������±�����Ԫ�ص��±꣬�Ҳ�������-1
int LowerBound(vector<int> array, const int target)
{
	int l = 0 ;
	int r = array.size() ;
	while (l < r)
	{
		const int mid = l + ((r-l) >> 1) ; // Ϊ�˷�ֹ(L+R)�������:
		if (array.at(mid) >= target) // ����==Ҳ������
			r = mid ;
		else
			l = mid+1 ;
	}
	return l-1 ; // ������ڱ�Ŀ��λ�ô�1��λ��
}

