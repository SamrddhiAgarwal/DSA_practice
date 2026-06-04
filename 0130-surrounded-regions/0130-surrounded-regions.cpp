class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        grid[i][j]='A';
        int n=grid.size(),m=grid[0].size();
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int d=0;d<4;d++)
        {
            int x=i+dx[d];
            int y=j+dy[d];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]=='O')
            dfs(grid,x,y);
        }
    }
    void solve(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]=='O') dfs(grid,i,0);
            if(grid[i][m-1]=='O') dfs(grid,i,m-1);
        }
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]=='O') dfs(grid,0,j);
            if(grid[n-1][j]=='O') dfs(grid,n-1,j);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='O') grid[i][j]='X';
                else if (grid[i][j]=='A') grid[i][j]='O';
            }
        }
    }
};