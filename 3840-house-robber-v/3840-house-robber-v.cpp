class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        
        int n=nums.size();
        vector<long long>dp(n,0);
        // dp[0]=nums[0];
        long long prev2=nums[0];
        if(n==1) return nums[0];
        long long prev1;
        if(colors[0]==colors[1])
        prev1=max(nums[0],nums[1]);
        // dp[1]=max(nums[0],nums[1]);
        else
        prev1=nums[1]+nums[0];
        // dp[1]=nums[1]+nums[0];
        long long curr;
        for(int i=2;i<n;i++)
        {
            if(colors[i]==colors[i-1])
            // dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
            curr=max(prev1,nums[i]+prev2);
            
            else
            curr=nums[i]+prev1;
            // dp[i]=nums[i]+dp[i-1];}
            
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
        // return dp[n-1];
    }
};