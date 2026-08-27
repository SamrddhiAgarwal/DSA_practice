class Solution {
public:
    pair<int,int>start,end;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    int ans;
    void dfs(int i,int j,int mask,int total_mask,int m ,int n)
    {
        if(i==end.first && j==end.second)
        {
            if(mask==total_mask)
            ans++;

            return;
        }
        for(int k=0;k<4;k++)
        {
            
            int r=i+dx[k];
            int c=j+dy[k];

            if(r>=0 && r<n && c>=0 && c<m && ((mask & (1 << (r*m+c)))==0))
            {
                dfs(r,c,mask|(1 << (r*m+c)),total_mask,m,n);
            }       
        }    
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int total_mask=(1<<(m*n))-1;
        int mask=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    start={i,j};
                    mask|=(1 << (i*m+j));
                }
                if(grid[i][j]==2)
                end={i,j};
                if(grid[i][j]==-1)
                {
                    mask|=(1<< (i*m+j));
                }
            }
        }
        ans=0;
        dfs(start.first,start.second,mask,total_mask,m,n);
        return ans;
    }
};