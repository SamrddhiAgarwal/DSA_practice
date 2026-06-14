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
// method-1;
    // int removeStones(vector<vector<int>>& stones) {
    //     int n=stones.size();
    //     dsu ds(100001);
    //     unordered_map<int,int>mp;
    //     for(auto s:stones)
    //     {
    //         int r=s[0];
    //         int c=s[1];
    //         if(mp.find(c)==mp.end())
    //         mp[c]=r;
    //         else
    //         ds.unionBysize(r,mp[c]);

    //     }
    //     set<int> st;
    //     for(auto it:mp)
    //     {
    //         st.insert(ds.findPar(it.second));
    //     }
    //     return n-st.size();
    // }
//method 2
// int removeStones(vector<vector<int>>& stones) {
//         int n=stones.size();
//         int mx=-1;
//         for(auto s:stones)
//         {
//             mx=max(mx,s[0]);
//         }
//         dsu ds(mx);
//         unordered_map<int,int>mp;
//         for(auto s:stones)
//         {
//             int r=s[0];
//             int c=s[1];
//             if(mp.find(c)==mp.end())
//             mp[c]=r;
//             else
//             ds.unionBysize(r,mp[c]);

//         }
//         set<int> st;
//         for(auto it:mp)
//         {
//             st.insert(ds.findPar(it.second));
//         }
//         return n-st.size();
// }


// method -3
    // int removeStones(vector<vector<int>>& stones) {
    //     int n=stones.size();
    //     unordered_map<int,vector<int>>mp2;
    //     for(auto& s:stones)
    //     {
    //         int r=s[0];
    //         int c=s[1];
    //         mp2[r].push_back(c);
    //     }
    //     int sz=mp2.size();
    //     dsu ds(sz);
    //     unordered_map<int,int>mp;
    //     int i=0;
    //     for(auto it:mp2)
    //     {
    //         for(auto c:it.second)
    //         {
    //             if(mp.find(c)==mp.end())
    //             mp[c]=i;
    //             else
    //             ds.unionBysize(i,mp[c]);
    //         }
    //         i++;
    //     }
    //     int cnt=0;
    //     for(int i=0;i<sz;i++)
    //     {
    //         if(ds.findPar(i)==i) cnt++;
    //     }
    //     return n-cnt;
    // }

//method -4
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int mxr=-1,mxc=-1;
        for(auto& s:stones)
        {
            mxr=max(mxr,s[0]);
            mxc=max(mxc,s[1]);
        }
        dsu ds(mxr+mxc+1);
        unordered_map<int,int>mp; //for unique all row and stones
        for(auto& s:stones)
        {
            int r=s[0];
            int c=s[1]+mxr+1;
            ds.unionBysize(r,c);
            mp[r]=1;
            mp[c]=1;
        }
        int cnt=0;
        for(auto it:mp)
        {
            if(ds.findPar(it.first)==it.first)
            cnt++;
        }
        return n-cnt;
    }
};