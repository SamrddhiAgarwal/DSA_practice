class Solution {
public:
    int cnt=0;
    void dfs(vector<vector<int>>& grid,int row,int col)
    {
        grid[row][col]=2;
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        cnt++;
        for(int i=0;i<4;i++)
        {
            int x=row+dx[i];
            int y=col+dy[i];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1)
            {
                
                dfs(grid,x,y);
            } //1+dfs doesn't work cause at one point we 
            
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j);
                    mx=max(mx,cnt);
                    cnt=0;
                }
            }
        }
        return mx;
        
    }
};