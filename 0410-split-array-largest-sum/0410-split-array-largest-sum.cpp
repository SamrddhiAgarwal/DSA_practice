class Solution {
public:
    int helper(int p, vector<int>& nums)
    {
        int sum=0, ans=1;
        for(auto& n:nums)
        {
            sum+=n;
            if(sum>p)
            {
                sum=n;
                ans++;
            }
        }
        return ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=nums[0],high=0;
        for(auto& n:nums)
        {
            low=max(n,low);
            high+=n;
        }
        while(low<=high)
        {
            int mid =(low+high)/2;
            int ans=helper(mid,nums);
            if(ans<=k)
            high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
};