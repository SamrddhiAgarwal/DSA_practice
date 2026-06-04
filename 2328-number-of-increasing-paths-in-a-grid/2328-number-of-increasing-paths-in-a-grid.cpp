class Solution {
public:
    int MOD=1000000007;
    int dfs_dp2(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j)
    {
        
        int n=grid.size();
        int m=grid[0].size();
        
        
        if(dp[i][j]!=-1) return dp[i][j];

        long long cnt=1;
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};;
        for(int d=0;d<4;d++)
        {
            int x=i+dx[d];
            int y=j+dy[d];
            if((x>=0 && x<n && y>=0 && y<m && grid[x][y]>grid[i][j]))
            cnt+=(dfs_dp2(grid,dp,x,y));
        }
        return dp[i][j]=(cnt%MOD);
    }
    
    int countPaths(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        long long cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==-1)
                cnt+=dfs_dp2(matrix,dp,i,j);
                else
                cnt+=(dp[i][j]);
            }
        }
        return (cnt%MOD);
    }
};