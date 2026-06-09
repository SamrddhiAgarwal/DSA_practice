class Solution {
public:
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        int n=grid.size();
        int m=grid[0].size();
        int sr=entrance[0];
        int sc=entrance[1];
        
        queue<pair<int,int>>q;
        int sp=0;
        q.push({sr,sc});
        grid[sr][sc]=1;
        int sz;

        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        while(!q.empty())
        {
            
            sz=q.size();
            while(sz--)
            {
                auto [r,c]=q.front();
                q.pop();
                if((r==0 || c==0 || r==n-1 || c==m-1) && !(sr==r && sc==c)) return sp;

                for(int i=0;i<4;i++)
                {
                    
                        int x=r+dx[i];
                        int y=c+dy[i];
                        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]=='.')
                        {
                            grid[x][y]='+';
                            q.push({x,y});
                        }
                    
                }
            }
            sp++;
        }
        return -1;
    
    }
};