class Solution {
public:
vector<vector<int>> bfs(vector<vector<int>>& grid)
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                q.push({i,j});
            }
        }
        int time=0;
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        while(!q.empty())
        {
            
            int sz=q.size();
            while(sz>0)
            {
                auto [r,c]=q.front();
                q.pop();
                ans[r][c]=time;
                // int dx[]={0,1,0,-1};
                // int dy[]={-1,0,1,0};
                for(int i=0;i<4;i++)
                {
                    int x=r+dx[i];
                    int y=c+dy[i];
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && ans[x][y]==-1)
                    {
                        grid[x][y]=0;
                        q.push({x,y});
                        
                    }
                    
                }
                sz--;
            }
            time++;
        }
        return ans;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // return bfs(mat);

        //method 2 almost same;
        int n=mat.size(),m=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    mat[i][j]=0;
                }
                else
                {
                    mat[i][j]=-1;
                }
            }
        }
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        while(!q.empty())
        {   
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=r+dx[i];
                int y=c+dy[i];                    
                if(x>=0 && x<n && y>=0 && y<m && mat[x][y]==-1 )
                {
                    mat[x][y]=mat[r][c]+1;
                    q.push({x,y});
                }
            }
        }
        return mat;
    }
};