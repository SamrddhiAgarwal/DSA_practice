class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int j=1;
        for(int i=2;i<n;i++)
        {
            if(nums[i]!=nums[j])
            {
                j++;
                nums[j]=nums[i];
            }
            else if( nums[i]==nums[j] && nums[i]!=nums[j-1])
            {
                j++;
                nums[j]=nums[i];
            }
        }
        return j+1;
    }
};