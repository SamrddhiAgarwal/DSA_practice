class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    // void dfs()
    // {
    //     grid[i][j]=-1;
    //     int dx[]={1,-1,0,0};
    //     int dy[]={0,0,-1,1};
    //     for(int i=0;i<4;i++)
    //     {
    //         int x=i+dx[i];
    //         int y=j+dy[i];
    //         if(x>=0 && x<n && y>=0 && y<m && grid[x][y]>=0)
    //         {
    //             if(grid[x][y])
    //         }
    //     }
    // }
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<p,vector<p>,greater<p>> pq;
        int time=0;
        int n=grid.size();
        
        pq.push({grid[0][0],{0,0}});
        grid[0][0]=-1;

        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};

        while(!pq.empty())
        {
            int h=pq.top().first;
            auto [r,c]=pq.top().second;
            pq.pop();
            if(time<h) time=h;
            if(r==n-1 && c==n-1) return time;
            for(int i=0;i<4;i++)
            {
                int x=r+dx[i];
                int y=c+dy[i];
                if(x>=0 && x<n && y>=0 && y<n && grid[x][y]!=-1)
                {
                    pq.push({grid[x][y],{x,y}});
                    grid[x][y]=-1;
                }
            }
        }
        return time;
    }
};