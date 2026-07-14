class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<vector<int>>q; //i,j,steps,stageOfKey
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='@')
                q.push({i,j,0,0});
                else if(grid[i][j]>='a' && grid[i][j]<='f')
                cnt++;
            }
        }
        int decistage=(1 << cnt) - 1;

        // int vis[n][m][decistage+1];
        // memset(vis,0,sizeof(int));
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(decistage + 1, 0)));
        vis[q.front()[0]][q.front()[1]][0]=1;

        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};

        while(!q.empty())
        {
            int i=q.front()[0];
            int j=q.front()[1];
            int steps=q.front()[2];
            int decikey=q.front()[3];
            q.pop();
            if(decistage==decikey) return steps;
            for(int d=0;d<4;d++)
            {
                int nx=dx[d]+i;
                int ny=dy[d]+j;
                if(!(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#')) continue;
                else if((grid[nx][ny]=='.' || grid[nx][ny]=='@')&& !vis[nx][ny][decikey]) 
                {
                    vis[nx][ny][decikey]=1;
                    q.push({nx,ny,steps+1,decikey});
                }
                else if(grid[nx][ny]>='a' && grid[nx][ny]<='f')
                {
                    int decik= (1<<(grid[nx][ny]-'a'))|decikey;
                    if( !vis[nx][ny][decik])
                    {
                    vis[nx][ny][decik]=1;
                    q.push({nx,ny,steps+1,decik});
                    }
                }
                else if(grid[nx][ny]>='A' && grid[nx][ny]<='F')
                {
                    if(((decikey>>(grid[nx][ny]-'A')) & 1) ==1  && !vis[nx][ny][decikey])
                    {
                        vis[nx][ny][decikey]=1;
                        q.push({nx,ny,steps+1,decikey});
                    }
                    
                }
            }
        }
        return -1;
    }
};