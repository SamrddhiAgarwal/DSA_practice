class Solution {
public:
    int sum(vector<int>& nums, int goal)
    {
        if(goal<0) return 0;
        int l=0,r=0,cnt=0,n=nums.size(),s=0;
        while(r<n)
        {
            s=s+nums[r];
            while(s>goal)
            {
                s=s-nums[l];
                l++;
            }
            if(s<=goal) cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sum(nums,goal)-sum(nums,goal-1);
    }
};