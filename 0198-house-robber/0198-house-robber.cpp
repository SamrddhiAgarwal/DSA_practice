class Solution {
public:
    int helper(int n,vector<int>& nums,vector<int>& dp)
    {
        if(n==0)
        return 0;
        if(n==1)
        return nums[0];
        if(dp[n]!=-1) return dp[n];
        return dp[n]= max(helper(n-2,nums,dp)+nums[n-1],helper(n-1,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int> dp(n+1,-1);
        // return helper(n,nums,dp);
        int curr,prev2=0,prev=nums[0];
        for(int i=2;i<n+1;i++)
        {
            curr=max(prev2+nums[i-1],prev);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};