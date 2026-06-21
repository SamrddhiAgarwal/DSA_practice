class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     long long mx=INT_MIN,s=nums[0];
    //     for(int i=1;i<nums.size();i++)
    //     {
    //         mx=max(s,mx);
    //         if(s<0)
    //         {
                
    //             s=0;
    //         }
            
    //         s=s+nums[i];
    //     }
    //     mx=max(mx,s);
    //     return mx;
        
    // }
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> sum(n,0);
        sum[0]=nums[0];
        int ms=0;
        int mx=nums[0];
        if(ms>nums[0]) ms=nums[0];
        for(int i=1;i<n;i++)
        {
            sum[i]=sum[i-1]+nums[i]; //sm+=arr[i];
            mx=max(mx,sum[i]-ms);
            ms=min(ms,sum[i]);
        }
        return mx;
    }
};