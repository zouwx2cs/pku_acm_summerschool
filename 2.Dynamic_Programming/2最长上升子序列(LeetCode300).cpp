class Solution {
// dp[i] ��ʾ��ǰ����Ϊi+1�����������������е���Сĩβֵ
// ����֪��dp[]һ���ǵ����ģ�ÿ���һ��Ԫ�ؾͿ������۰���Ҹ���dp
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0 ;
        int dp[nums.size()] = {nums[0], };
        int maxLen = 1 ; // �տ�ʼ�ҵ����������Ӵ��ǵ�һ��Ԫ�أ�����Ϊ1
        for (int i = 1; i < nums.size(); ++i)
        {
            int l = 0, r = maxLen ;
            while (l < r)
            {
                const int mid = l + ((r-l) >> 1) ;
                if (dp[mid] < nums[i])
                    l = mid+1 ;
                else
                    r = mid ;
            }
            
            // ����Ϊl+1��������������е���Сĩβֵ���Ը���Ϊ��Ԫ����
            dp[l] = nums[i] ;
            
            // �����ǰԪ�ر�dp������Ԫ�ض�����󳤶ȾͿ���+1�����Ը�Ԫ�ؽ�β
            if (l == maxLen)    
                ++maxLen ;
        }
        return maxLen ;
    }
};