class Solution {
public:
    int timer=1; 
    void dfs(int v,int parent, vector<int>& vis,vector<int>& first,vector<int>& low,vector<vector<int>>& ans,vector<vector<int>>& adj)
    {
        vis[v]=1;
        first[v]=low[v]=timer++;

        for(auto& u:adj[v])
        {
            if(u==parent ) continue;

            if(!vis[u])
            {
                dfs(u,v,vis,first,low,ans,adj);
                low[v]=min(low[v],low[u]);
                if(first[v]<low[u])
                ans.push_back({u,v});
            }
            else
            {
                low[v]=min(low[v],low[u]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n),ans;
        for(auto& e:connections)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n,0),low(n),first(n);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            dfs(i,-1,vis,first,low,ans,adj);
        }
        return ans;
    }
};
// we can do this also instead of using ans in dfs using check condition later
// for(auto& y : connections){
//             int u  = y[0];
//             int v  = y[1];
//             if(dis[u]<low[v] || dis[v]<low[u]) ans.push_back({u,v});
