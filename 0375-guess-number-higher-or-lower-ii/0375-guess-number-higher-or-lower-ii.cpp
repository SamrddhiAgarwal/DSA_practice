class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int start=n;start>=1;start--)
        {
            for(int end=start+1;end<=n;end++)
            {
                
                
                    int mn=INT_MAX;
                    for(int i=start;i<=end;i++)
                    {
                        mn=min(mn,i+max(dp[start][i-1],dp[i+1][end]));
                    }
                    dp[start][end]=mn;
                
            }
            
        }
        return dp[1][n];
    }
};