class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        
        // vector<int>dp(n,0);

        // dp[0]=nums[0];
        int prev2=nums[0];
        // if(n==1) return dp[0];
        if(n==1) return prev2;

        // dp[1]=max(nums[1],nums[0]);
        int prev=max(nums[1],nums[0]);
        int curr;
        for(int i=2;i<n;i++)
        {
            // dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
            curr=max(prev,nums[i]+prev2);
            prev2=prev;
            prev=curr;
        }
        // return dp[n-1];
        return prev;
    }
};