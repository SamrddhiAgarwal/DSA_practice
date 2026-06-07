class DisjointSet
{
public:
    vector<int> size,parent;
    DisjointSet(int n)
    {
        size.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    int findPar(int u)
    {
        if(parent[u]==u) return u;
        return parent[u]=findPar(parent[u]);
    }
    void unionbySize(int u, int v)
    {
        int pu=findPar(u),pv=findPar(v);
        if(pu==pv) return;
        if(size[pu]>size[pv])
        {
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
        else
        {
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra=0;
        for(auto e:connections)
        {
            int u=e[0];
            int v=e[1];

            if(ds.findPar(u)!=ds.findPar(v))
            {
                ds.unionbySize(u,v);
            }
            else
            extra++;
        }
        int conn=0;
        for(int i=0;i<n;i++)
        {
            if(ds.findPar(i)==i)
            conn++;
        }
        
        return conn-1<=extra ? conn-1 : -1;
    }
};