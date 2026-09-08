class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> adj(5);
        adj[0]={1};
        adj[1]={0,2};
        adj[2]={0,1,3,4};
        adj[3]={2,4};
        adj[4]={0};

        vector<long long>prev(5,1),curr(5,0);
        
        int ans=0,MOD=1e9+7;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<5;j++)
            {
                curr[j]=0;
                for(auto c:adj[j])
                curr[j]=(curr[j]+prev[c])%MOD;
            }
            prev=curr;
        }
        for(int i=0;i<5;i++)
        {
            ans=(ans+prev[i])%MOD;
        }
        return ans;
    }
};