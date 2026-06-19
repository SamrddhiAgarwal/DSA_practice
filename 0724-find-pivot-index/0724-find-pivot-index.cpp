class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum=0;
        for(auto& n:nums)
        {
            total_sum+=n;
        }
        int left_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if( (2 * left_sum)+nums[i] == total_sum)
            return i;
            left_sum+=nums[i];
        }
        return -1;
    }
};