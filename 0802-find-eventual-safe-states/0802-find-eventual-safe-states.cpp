// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         // anode can not be safe node if there is acycle ie for that node one of it edge is revisting it back
//         int V=graph.size();
//         vector<vector<int>> rgraph(V);
//         vector<int> indegree(V,0);
//         for(int i=0;i<V;i++)
//         {
//             for(auto v:graph[i])
//             {
//                 rgraph[v].push_back(i);
//                 indegree[i]++;
//             }
//         }
//         queue<int>q;
//         for(int i=0;i<V;i++)
//         {
//             if(indegree[i]==0) // this will insert all terminal node
//             q.push(i);
//         }
//         vector<int> ans;
//         while(!q.empty())
//         {
//             int b=q.front();
//             q.pop();
//             ans.push_back(b);
//             for(auto &a:rgraph[b])
//             {
//                 indegree[a]--;

//                 if(indegree[a]==0)
//                 q.push(a);
//             }
//         }
//         sort(ans.begin(),ans.end());
//         return ans;
//     }
// };
class Solution {
public:
    bool dfs(int v, vector<int>& vis, vector<vector<int>>& adj,vector<bool>& cycle)
    {
        vis[v]=1;
        // pvis[v]=1;

        for(auto& u:adj[v])
        {
            if(!vis[u])
            {
                if(dfs(u,vis,adj,cycle)) {
                    
                    cycle[v]=true;
                    return true;
                }
            }
            
            // else if(pvis[u])
            else if(vis[u]==1){
                cycle[v]=true;
            return true;
            }
        }
        // pvis[v]=0;
        vis[v]=2;
        cycle[v]=false;
        return false;
        //stack store for toposort but possible nly with cycle check
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<bool>cycle(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,graph,cycle);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(!cycle[i]) ans.push_back(i);
        }
        return ans;// no need to sort since i=0->n
    }
};