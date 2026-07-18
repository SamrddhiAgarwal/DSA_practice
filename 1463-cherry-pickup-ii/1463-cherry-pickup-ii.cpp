class Solution {
public:
    int helper(int i, int j1, int j2, vector<vector<vector<int>>>& dp, vector<vector<int>>& mat)
    {
        int n = mat.size();
        int m=mat[0].size();
        
        // correct boundary
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;

        // base case
        if (i == n-1) 
        {
            if(j1==j2) return mat[n-1][j1];
            else return mat[n-1][j1]+mat[n-1][j2];
        }

        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int curr = (j1 == j2) ? mat[i][j1] : mat[i][j1] + mat[i][j2];
        int mx=curr;
        for(int dj1=-1;dj1<2;dj1++)
        {
            // if(j1+dj1<0 || j1+dj1>=m) continue;
            for(int dj2=-1;dj2<2;dj2++)
            {
                // if(j2+dj2>=m || j2+dj2<0) continue;
                int ans=curr+helper(i+1,dj1+j1,dj2+j2,dp,mat);
                mx=max(mx,ans);
            }
        }
        
        return dp[i][j1][j2] = (int)mx;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m=grid[0].size(); 
        // vector<vector<vector<int>>> dp(n,
        //     vector<vector<int>>(m, vector<int>(m, -1)));
            vector<vector<int>> dp(m, vector<int>(m, -1));
            vector<vector<int>> newdp(m, vector<int>(m, -1));
        // return helper(0, 0, m - 1, dp, grid);
        for(int j1=m-1;j1>=0;j1--)
        {
            for(int j2=0;j2<m;j2++)
            {
            
                // dp[n-1][j1][j2]=(j1==j2)?grid[n-1][j1]:grid[n-1][j1]+grid[n-1][j2];
                dp[j1][j2]=(j1==j2)?grid[n-1][j1]:grid[n-1][j1]+grid[n-1][j2];
                    
            }
        }

        for(int i=n-2;i>=0;i--)
        {
            for(int j1=m-1;j1>=0;j1--)
            {
                for(int j2=0;j2<m;j2++)
                {
                    int curr= (j1==j2)? grid[i][j2]:grid[i][j1]+grid[i][j2];
                    int mx=curr;
                    for(int dj1=-1;dj1<2;dj1++)
                    {
                        for(int dj2=-1;dj2<2;dj2++)
                        {
                            int nj1=j1+dj1,nj2=j2+dj2;
                            if(nj1<0||nj2<0||nj1>=m||nj2>=m) continue;
                            // mx=max(mx,curr+dp[i+1][nj1][nj2]);
                            mx=max(mx,curr+dp[nj1][nj2]);
                        }
                    }
                    newdp[j1][j2]=mx;
                }
            }
            dp=newdp;
        }
        return dp[0][m-1];
    }
};