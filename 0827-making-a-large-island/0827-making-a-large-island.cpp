/*
class Solution {
public:
    int dfs(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& vis) // other method is using int& cnt 
    {
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        int size=1;
        for(int i=0;i<4;i++)
        {
            int x=row+dx[i];
            int y=col+dy[i];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && !vis[x][y])
            {
                
                size+=dfs(grid,x,y,vis);
            } 
        }
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<vector<int>> nvis(n,vector<int>(n,0));
        int mx=0; int cnt=0;// one method istaking each element for case where 1 is more but it will cause tle so one of modifies way is this
        // this method still gives tle since it is using every zero 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    vis=nvis;
                    mx=max(mx,dfs(grid,i,j,vis));
                    cnt++;
                }
            }
        }
        if(cnt==0) return n*n;
        return mx;
    }
};*/

//method 2 we calculate mx for all one store it but the problem is no it's solve no it's not 0 1 1      0011
//       1 0 1      1101
//       1 1 0      0100
//                  1100

class Solution {
public:
    int dfs(vector<vector<int>>& grid,int row,int col,int color) 
    {
        grid[row][col]=color;
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        int size=1;
        for(int i=0;i<4;i++)
        {
            int x=row+dx[i];
            int y=col+dy[i];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 )
            {
                
                size+=dfs(grid,x,y,color);
            } 
        }
        return size;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        // vector<vector<int>> vis(n,vector<int>(n,0));
        vector<int> area;int c=2;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int sz=dfs(grid,i,j,c);
                    mx=max(mx,sz);
                    area.push_back(sz);
                    c++;
                }
            }
        }

        set<int> st;
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    for(int d=0;d<4;d++)
                    {
                        int x=i+dx[d];
                        int y=j+dy[d];
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]!=0 )
                        {
                            st.insert(grid[x][y]);
                        } 
                    }
                    int a=1;
                    for(auto color:st)
                    {
                        if(color>1)
                        a+=area[color-2];
                    }
                    st.clear();
                    mx=max(mx,a);
                }
            }
        }
        return mx;
    }
};