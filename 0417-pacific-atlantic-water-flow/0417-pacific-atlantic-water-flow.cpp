class Solution {
public:
    void dfs_p(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& vis)
    {
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};

        for(int d=0;d<4;d++)
        {
            int x=i+dx[d];
            int y=j+dy[d];

            if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && grid[x][y]>=grid[i][j])
            dfs_p(grid,x,y,vis);
        }
            
    }
   /* void dfs_a(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& vis,vector<vector<int>>& result)
    {
        vis[i][j]=2;
        result.push_back({i,j});
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};

        for(int d=0;d<4;d++)
        {
            int x=i+dx[d];
            int y=j+dy[d];

            if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==1 && grid[x][y]>=grid[i][j])
            dfs_a(grid,x,y,vis,result);
        }
            
    }*/
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> pac(n,vector<int>(m,0));
        vector<vector<int>> atl(n,vector<int>(m,0));
        vector<vector<int>>result;
        for(int i=0;i<n;i++)
        {
            if(!pac[i][0])
            dfs_p(heights,i,0,pac);
        }
        for(int i=0;i<m;i++)
        {
            if(!pac[0][i])
            dfs_p(heights,0,i,pac);
        
        }
        //since m==n;

        for(int i=0;i<n;i++)
        {
            if(!atl[i][m-1])
            dfs_p(heights,i,m-1,atl);
            
        }
        for(int i=0;i<m;i++)
        {
            if(!atl[n-1][i])
            dfs_p(heights,n-1,i,atl);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pac[i][j] && atl[i][j])
                result.push_back({i,j});
            }
        }
        return result;
    }
};