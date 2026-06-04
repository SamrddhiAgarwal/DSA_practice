class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int> color(n,0);
        queue<int>q;

        for(int i=0;i<n;i++)
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
    }
};