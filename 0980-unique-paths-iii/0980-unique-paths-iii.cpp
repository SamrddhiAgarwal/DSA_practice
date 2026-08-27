// class Solution {
// public:
//     pair<int,int>start,end;
//     int dx[4]={-1,0,1,0};
//     int dy[4]={0,-1,0,1};
//     int ans;
//     void dfs(int i,int j,int mask,int total_mask,int m ,int n)
//     {
//         if(i==end.first && j==end.second)
//         {
//             if(mask==total_mask)
//             ans++;

//             return;
//         }
//         for(int k=0;k<4;k++)
//         {
            
//             int r=i+dx[k];
//             int c=j+dy[k];

//             if(r>=0 && r<n && c>=0 && c<m && ((mask & (1 << (r*m+c)))==0))
//             {
//                 dfs(r,c,mask|(1 << (r*m+c)),total_mask,m,n);
//             }       
//         }    
//     }
//     int uniquePathsIII(vector<vector<int>>& grid) {
//         int n=grid.size(),m=grid[0].size();
//         int total_mask=(1<<(m*n))-1;
//         int mask=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(grid[i][j]==1)
//                 {
//                     start={i,j};
//                     mask|=(1 << (i*m+j));
//                 }
//                 if(grid[i][j]==2)
//                 end={i,j};
//                 if(grid[i][j]==-1)
//                 {
//                     mask|=(1<< (i*m+j));
//                 }
//             }
//         }
//         ans=0;
//         dfs(start.first,start.second,mask,total_mask,m,n);
//         return ans;
//     }
// };
class Solution {
public:
    int m, n;
    int ex, ey;
    int ans;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    inline void dfs(vector<vector<int>>& g, int x, int y, int left) {
        if (x == ex && y == ey) {
            if (left == 1) ans++;
            return;
        }

        int tmp = g[x][y];
        g[x][y] = -1;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if ((unsigned)nx < (unsigned)m && (unsigned)ny < (unsigned)n && g[nx][ny] != -1) {
                dfs(g, nx, ny, left - 1);
            }
        }

        g[x][y] = tmp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = (int)grid.size();
        n = (int)grid[0].size();
        ans = 0;

        int sx = 0, sy = 0;
        int total = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1) total++;
                if (grid[i][j] == 1) { sx = i; sy = j; }
                else if (grid[i][j] == 2) { ex = i; ey = j; }
            }
        }

        dfs(grid, sx, sy, total);
        return ans;
    }
};
