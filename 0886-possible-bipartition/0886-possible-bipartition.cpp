class Solution {
public:
    bool dfs(vector<vector<int>>& adj,vector<int>& color,int v)
    {
        for(auto u:adj[v])
        {
            if(color[u]==0)
            {
                color[u]=-color[v];
                if(dfs(adj,color,u)==false) return false;
            }
            else
            {
                if(color[u]==color[v])
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> graph(n+1);
        for(auto E: dislikes)
        {
            int u=E[0];
            int v=E[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> color(n+1,0);

        for(int i=1;i<=n;i++)
        {
            if(color[i]==0)
            {
                color[i]=1;
                if(dfs(graph,color,i)==false)
                return false;
            }
        }
        return true;


        /*queue<int>q;

        for(int i=1;i<=n;i++)
        {
            if(color[i]==0)
            {
                color[i]=1;
                q.push(i);
                while(!q.empty())
                {
                    int v=q.front();
                    q.pop();
                    for(auto u:graph[v])
                    {
                        if(color[u]==0)
                        {
                            color[u]=-color[v];                    
                            q.push(u);
                        }
                        else
                        {
                            if(color[u]==color[v])
                            return false;
                        }                
                    }
                }
            }
            
        }
        return true;
        */
    }
};