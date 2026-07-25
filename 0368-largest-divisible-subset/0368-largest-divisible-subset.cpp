class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> ind(n,-1);
        int mx=0;
        
        for(int i=0;i<n;i++)
        {
            ind[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    // dp[i]=max(dp[i],dp[j]+1);
                    if(dp[j]+1>dp[i])
                    {
                        dp[i]=dp[j]+1;
                        ind[i]=j;
                    }
                }
            }
            if(dp[i]>dp[mx])
            {
                mx=i;
            }
        }
        vector<int>ans;
        while(ind[mx]!=mx)
        {
            ans.push_back(nums[mx]);
            mx=ind[mx];
        }
        ans.push_back(nums[mx]);
        return ans;
        
    }
};