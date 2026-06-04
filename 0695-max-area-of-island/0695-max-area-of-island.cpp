class Solution {
public:
    int cnt=0;
    int dfs(vector<vector<int>>& grid,int row,int col) // other method is using int& cnt 
    {
        grid[row][col]=2;
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        // cnt++;
        int size=1;//method adopted from below actually what mistake we did was size++ after condition check which was returning only the number of time dfs was called that time
        for(int i=0;i<4;i++)
        {
            int x=row+dx[i];
            int y=col+dy[i];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1)
            {
                
                size+=dfs(grid,x,y);
            } //1+dfs doesn't work cause at one point we 
            
        }
        return size;
    }
    int dfs2(vector<vector<int>>& grid,int x,int y) // other method is using int& cnt 
    {
        int n=grid.size();
        int m=grid[0].size();

        if(!(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1)) return 0;
        int mx=1; // remeber mx=1 not 0
        grid[x][y]=2;// remember to chnage here 

        mx+=dfs2(grid,x+1,y);
        mx+=dfs2(grid,x-1,y);
        mx+=dfs2(grid,x,y+1);
        mx+=dfs2(grid,x,y-1);
        return mx;
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
                    // dfs(grid,i,j);
                    // mx=max(mx,cnt);
                    // cnt=0;
                    // mx=max(mx,dfs2(grid,i,j));
                    mx=max(mx,dfs(grid,i,j));
                }
            }
        }
        return mx;
        
    }
};