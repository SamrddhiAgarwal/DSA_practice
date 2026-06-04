class Solution {
public:
    int dfs_dp(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        // if(!(i>=0 && i<n && j>=0 && j<m))
        // return dp[i][j]=0;
        int mx=0;
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};;
        for(int d=0;d<4;d++)
        {
            int x=i+dx[d];
            int y=j+dy[d];
            if(!(x>=0 && x<n && y>=0 && y<m && grid[x][y]>grid[i][j])) 
            mx=max(mx,0);
            else
            {
                if(dp[x][y]!=-1)
                mx=max(mx,dp[x][y]);
                else
                {
                    
                    mx=max(mx,dfs_dp(grid,dp,x,y));
                }
            }
        }
        return dp[i][j]=1+mx;
    }
    int dfs_dp2(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j)
    {
        
        int n=grid.size();
        int m=grid[0].size();
        
        // if(!(i>=0 && i<n && j>=0 && j<m))
        // return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int mx=0;
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};;
        for(int d=0;d<4;d++)
        {
            int x=i+dx[d];
            int y=j+dy[d];
            if((x>=0 && x<n && y>=0 && y<m && grid[x][y]>grid[i][j]))
            mx=max(mx,dfs_dp2(grid,dp,x,y));
            // else
            // mx=max(mx,0);
            
        }
        return dp[i][j]=1+mx;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        int mx=0;int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==-1)
                mx=max(mx,dfs_dp2(matrix,dp,i,j));
                else
                mx=max(mx,dp[i][j]);
            }
        }
        return mx;
    }
};