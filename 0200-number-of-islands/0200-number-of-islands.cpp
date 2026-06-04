class Solution {
public:
    void dfs(vector<vector<char>>& grid,int row,int col)
    {
        grid[row][col]='2';
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        for(int i=0;i<4;i++) 
        {
            int x=row+dx[i];
            int y=col+dy[i];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]=='1')
            dfs(grid,x,y); 
        }
        
    } // TC-4*mn SC-mn(stack space)
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int cnt=0;
        
        queue<pair<int,int>> q;
        
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    cnt++;
                    // dfs(grid,i,j);
                    q.push({i,j});
                    grid[i][j]=0;
                    while(!q.empty())
                    {
                        auto [row,col]=q.front();
                        q.pop();
                        // grid[row][col]=0;// doing here cause tle remember to always change grid when pushed
                        for(int i=0;i<4;i++)                             
                        {
                            int x=row+dx[i];
                            int y=col+dy[i];
                            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]=='1')
                            {
                                grid[x][y]=0;
                                q.push({x,y});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};