class Solution {
public:
typedef pair<int,pair<int,int>> p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        priority_queue<p,vector<p>,greater<p>>pq; 
        pq.push({0,{0,0}});
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        while(!pq.empty())
        {
            int d=pq.top().first;
            auto [r,c]=pq.top().second;
            pq.pop();
            if(r==n-1 && c==m-1) return dist[r][c];
            if(dist[r][c]<d) continue;
            for(int i=0;i<4;i++)
            {
                int x=r+dx[i];
                int y=c+dy[i];
                if(!(x>=0 && x<n && y>=0 && y<m)) continue;
                int w=abs(heights[x][y]-heights[r][c]);
                if(dist[x][y]>max(d,w))
                {
                    dist[x][y]=max(d,w);
                    pq.push({dist[x][y],{x,y}});
                }
            }
        }
        return dist[n-1][m-1];      
    }
};