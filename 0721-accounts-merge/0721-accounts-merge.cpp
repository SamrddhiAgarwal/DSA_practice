class dsu
{
public:
    vector<int> parent,rank,size;
    dsu(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
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
            size[pu]+=size[pv];
        }
        else 
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        dsu ds(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string& c=accounts[i][j];
                if(mp.find(c)==mp.end())
                mp[c]=i;
                else
                ds.unionBysize(i,mp[c]);
            }
        }
        // vector<vector<string>> lists(n); 
        // for(auto it:mp)
        // {
        //     int i=ds.findPar(it.second);
        //     lists[i].push_back(it.first);
        // }
        // vector<vector<string>> ans;
        // for(int i=0;i<n;i++)
        // {
        //     if(lists[i].empty()) continue;
        //     vector<string>temp;
        //     temp.push_back(accounts[i][0]);
        //     sort(lists[i].begin(),lists[i].end());
        //     for(auto &e:lists[i])
        //     temp.push_back(e);
        //     ans.push_back(temp);
        // }
        // alternate method using set to not use sorting later same time complexity
        unordered_map<int, set<string>> merged_lists;
        for(auto& it : mp)
        {
            int leader = ds.findPar(it.second);
            merged_lists[leader].insert(it.first); // Auto-sorts here!
        }
        
        // 3. Build the final answer structure
        vector<vector<string>> ans;
        for(auto& it : merged_lists)
        {
            int account_idx = it.first;
            // Get the person's name
            vector<string> temp = {accounts[account_idx][0]}; 
            
            // Push all sorted emails into the vector
            temp.insert(temp.end(), it.second.begin(), it.second.end());
            ans.push_back(temp);
        }
        return ans;
    }
};