class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));        
        queue<pair<pair<int,int>,pair<int,int>>> q;
        
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                {
                    q.push({{i,j},{-1,-1}});
                    vis[i][j]=1;
                    while(!q.empty())
                    {
                        auto [row,col]=q.front().first;
                        auto [prow,pcol]=q.front().second;
                        q.pop();
                        for(int i=0;i<4;i++)                             
                        {
                            int x=row+dx[i];
                            int y=col+dy[i];
                            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==grid[row][col]  )
                            {
                                if(!vis[x][y] ) 
                                {
                                    vis[x][y]=1;
                                    q.push({{x,y},{row,col}});
                                }
                                else if (!(x==prow && y==pcol)) return true;
                            }
                            
                        }
                    }
                }
            }
        }
        return false;
    
    }
};