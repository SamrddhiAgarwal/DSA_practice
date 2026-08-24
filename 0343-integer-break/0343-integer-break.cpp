class Solution {
public:
    int integerBreak(int n) {
        // vector<int>dp(max(n+1,7),0);
        // dp[1]=1;
        // dp[2]=1;
        if(n==2) return 1;
        // dp[3]=2;
        if(n==3) return 2;
        // dp[4]=4;
        int third=4;
        if(n==4) return 4;
        // dp[5]=6;
        int second=6;
        if(n==5) return 6;
        // dp[6]=9;
        int first=9;
        if(n==6) return 9;
        for(int i=7;i<=n;i++)
        {
            //dp[i]=3*dp[i-3];
            int ans=third*3;
            third=second;
            second=first;
            first=ans;
        }
        return first;
    }
};