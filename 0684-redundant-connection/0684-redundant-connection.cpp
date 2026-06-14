class dsu
{
public:
    vector<int> parent,rank,size;
    dsu(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=0;i<n+1;i++)
        {
            parent[i]=i;
        }
    }

    int findPar(int u)
    {
        if(parent[u]==u) return u;

        return parent[u]=findPar(parent[u]);
    }

    void unionByrank(int u, int v)
    {
        int pu =findPar(u), pv=findPar(v);
        if(pu==pv) return;
        
        if(rank[pu]>rank[pv])
        parent[pv]= pu;
        else if(rank[pv]>rank[pu])
        parent[pu]= pv;
        else
        {
            parent[pu]=pv;
            rank[pv]++;
        }
    }

    void unionBysize(int u,int v)
    {
        int pu =findPar(u), pv=findPar(v);
        if(pu==pv) return;
        
        if(size[pu]>size[pv])
        {
            parent[pv]= pu;
            size[pv]+=size[pu];
        }
        else 
        {
            parent[pu]=pv;
            size[pu]+=size[pv];
        }
        
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        dsu ds(n);
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            if(ds.findPar(u)==ds.findPar(v)) return e;
            ds.unionByrank(u,v);
        }
        return {};
    }
};