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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        dsu ds(10001);
        unordered_map<int,int>mp;
        for(auto s:stones)
        {
            int r=s[0];
            int c=s[1];
            if(mp.find(c)==mp.end())
            mp[c]=r;
            else
            ds.unionBysize(r,mp[c]);

        }
        set<int> st;
        for(auto it:mp)
        {
            st.insert(ds.findPar(it.second));
        }
        return n-st.size();
    }
};