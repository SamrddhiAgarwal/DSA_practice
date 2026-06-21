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
            mx=max(mx,sum[i]-ms); //mx;
            ms=min(ms,sum[i]);// min taken will be 0 if all possitve other wise negative will come since subarray of later subarray are subtracted dur to being negative that otal sum had already been less than 0 and giving negative impact so it needed to be added when we are doing mx and it thus negative negative is positive
        }
        return mx;
    }
};