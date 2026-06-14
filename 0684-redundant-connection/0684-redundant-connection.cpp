// class dsu
// {
// public:
//     vector<int> parent,rank,size;
//     dsu(int n)
//     {
//         parent.resize(n+1);
//         rank.resize(n+1,0);
//         size.resize(n+1,0);
//         for(int i=0;i<n+1;i++)
//         {
//             parent[i]=i;
//         }
//     }

//     int findPar(int u)
//     {
//         if(parent[u]==u) return u;

//         return parent[u]=findPar(parent[u]);
//     }

//     void unionByrank(int u, int v)
//     {
//         int pu =findPar(u), pv=findPar(v);
//         if(pu==pv) return;
        
//         if(rank[pu]>rank[pv])
//         parent[pv]= pu;
//         else if(rank[pv]>rank[pu])
//         parent[pu]= pv;
//         else
//         {
//             parent[pu]=pv;
//             rank[pv]++;
//         }
//     }

//     void unionBysize(int u,int v)
//     {
//         int pu =findPar(u), pv=findPar(v);
//         if(pu==pv) return;
        
//         if(size[pu]>size[pv])
//         {
//             parent[pv]= pu;
//             size[pv]+=size[pu];
//         }
//         else 
//         {
//             parent[pu]=pv;
//             size[pu]+=size[pv];
//         }
        
//     }
// };
// class Solution {
// public:
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         int n=edges.size();
//         dsu ds(n);
//         for(auto e:edges)
//         {
//             int u=e[0];
//             int v=e[1];
//             if(ds.findPar(u)==ds.findPar(v)) return e;
//             ds.unionByrank(u,v);
//         }
//         return {};
//     }
// };
class Solution {
public:
    bool cycle(vector<vector<int>>& adj,int src,int dst)
    {
        int n=adj.size();
        queue<pair<int,int>>q;
        // no need of vis as for till now we don't have a cycle
        q.push({src,-1});
        // vis[src]=1;
        while(!q.empty())
        {
            auto [v,parent]=q.front();
            q.pop();
            if(v==dst) return true;
            for(auto u:adj[v])
            {
                if(u!=parent)
                q.push({u,v});
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            if(adj[v].size()!=0 && adj[u].size()!=0 && cycle(adj,u,v))
            return e;
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        return {};
    }
};