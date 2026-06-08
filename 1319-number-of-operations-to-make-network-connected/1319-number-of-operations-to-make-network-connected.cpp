// class DisjointSet
// {
// public:
//     vector<int> size,parent;
//     DisjointSet(int n)
//     {
//         size.resize(n,0);
//         parent.resize(n);
//         for(int i=0;i<n;i++)
//         {
//             parent[i]=i;
//         }
//     }

//     int findPar(int u)
//     {
//         if(parent[u]==u) return u;
//         return parent[u]=findPar(parent[u]);
//     }
//     void unionbySize(int u, int v)
//     {
//         int pu=findPar(u),pv=findPar(v);
//         if(pu==pv) return;
//         if(size[pu]>size[pv])
//         {
//             size[pu]+=size[pv];
//             parent[pv]=pu;
//         }
//         else
//         {
//             size[pv]+=size[pu];
//             parent[pu]=pv;
//         }
//     }
// };
// class Solution {
// public:
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         // check befor only no need of calculating extra 
//         int total_conn=connections.size();
//         if(total_conn<n-1) return -1;
//         DisjointSet ds(n);
//         int extra=0;
//         for(auto& e:connections) // copying by reference inc speed 
//         {
//             int u=e[0];
//             int v=e[1];

//             if(ds.findPar(u)!=ds.findPar(v))
//             {
//                 ds.unionbySize(u,v);
//             }
//             // else
//             // extra++; 
//         }
//         int conn=0;
//         for(int i=0;i<n;i++)
//         {
//             if(ds.findPar(i)==i)
//             conn++;
//         }
//         return conn-1;
//         // return conn-1<=extra ? conn-1 : -1;
//     }
// };

class Solution {
public:
    int extra=0;
    void dfs(vector<int> adj[],vector<int>& vis,int v,int parent)
    {   
        vis[v]=1;
        for(auto& u:adj[v])
        {
            if(!vis[u])
            {
                // vis[u]=1;
                dfs(adj,vis,u,v);
            }
            else if(u!=parent)
            extra++;
        }
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto& e:connections)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        int conn=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]){
            // vis[i]=1;
            conn++;
            dfs(adj,vis,i,-1);
            }
        }
        extra=extra/2;
        return extra>=conn-1 ? conn-1:-1;
    }
};