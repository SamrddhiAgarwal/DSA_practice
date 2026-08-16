class Solution {
public:
    bool dfs(vector<int>&arr,int u,vector<bool>&vis)
    {
        int n=arr.size();
        vis[u]=true;
        if(arr[u]==0)
        return true;
        bool ans=false;
        int fv=u+arr[u],bv=u-arr[u];
        if(fv<n && !vis[fv])
        ans|=dfs(arr,fv,vis);
        if(bv>=0 && !vis[bv])
        ans|=dfs(arr,bv,vis);
        return ans;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        
        vector<bool>vis(n,false);
        return dfs(arr,start,vis);
    }
};