class Solution {
public:
    void dfs(int v, vector<vector<int>>& adj,vector<int>& vis)
    {
        vis[v]=1;

        for(int u=0;u<adj[v].size();u++)
        {
            if(!vis[u] && adj[v][u]==1)
            dfs(u,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();int cnt=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,isConnected,vis);
            }
        }
        return cnt;
    }
};