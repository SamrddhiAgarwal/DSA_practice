class Solution {
public:
    int bfs(vector<vector<int>>& grid)
    {
        int n=grid.size(),m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                q.push({i,j});
                if(grid[i][j]==1)
                fresh++;
            }
        }
        // return fresh;
        if(fresh==0) return 0;
        int time=0;
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        while(!q.empty())
        {
            time++;
            int sz=q.size();
            while(sz>0)
            {
                auto [r,c]=q.front();
                q.pop();
                
                // int dx[]={0,1,0,-1};
                // int dy[]={-1,0,1,0};
                for(int i=0;i<4;i++)
                {
                    int x=r+dx[i];
                    int y=c+dy[i];
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1)
                    {
                        grid[x][y]=2;
                        q.push({x,y});
                        fresh--;
                    }
                    
                }
                sz--;
            }
        }
        return (fresh!=0) ? -1:time-1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
        /*int time= bfs(grid); 
        
        int n=grid.size(),m=grid[0].size();
        // can be optimised if we count number of fresh oranges before hand
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(grid[i][j]==1)
        //         return -1;
        //     }
        // }
        if(time>0)
        return time-1; // edge case if no fresh ornages are present actually no need actually needed if no rotten no fresh oranges are present matrix is all 0 then it create error 
        return 0;*/
    }
};