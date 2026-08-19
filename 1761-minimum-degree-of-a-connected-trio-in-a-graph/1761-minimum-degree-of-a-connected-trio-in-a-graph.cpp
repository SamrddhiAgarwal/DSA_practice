class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>>adj(n+1,vector<bool>(n+1,false));
        vector<int>indegree(n+1,0);
        for(auto& e:edges)
        {
            int u=e[0];
            int v=e[1];

            indegree[u]++;
            indegree[v]++;
            adj[u][v]=true;
            adj[v][u]=true;
        }
        int ans=1e9;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(!adj[i][j]) continue;

                for(int k=j+1;k<=n;k++)
                {
                    if(adj[i][k] && adj[j][k])
                    {
                        int degree=indegree[i]+indegree[j]+indegree[k]-6;
                        ans=min(ans,degree);
                    }
                }
            }
        }
        return ans==1e9? -1:ans;
    }
};