class Solution {
public:
        int robber(vector<int>& nums,int j,int n) {
        
        // if(n==0) return 0;
        
        // vector<int>dp(n,0);

        // dp[0]=nums[0];
        int prev2=nums[j];
        // if(n==1) return dp[0];
        // if(n==1) return prev2;

        // dp[1]=max(nums[1],nums[0]);
        int prev=max(nums[j+1],nums[j]);
        int curr;
        for(int i=j+2;i<n;i++)
        {
            // dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
            curr=max(prev,nums[i]+prev2);
            prev2=prev;
            prev=curr;
        }
        // return dp[n-1];
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int ans1=robber(nums,0,n-1);
        int ans2=robber(nums,1,n);
        return max(ans1,ans2);
    }
};