class Solution {
public:
    void dfs(int x,int y,vector<vector<int>> & image,int color,int c)
    {
        int n=image.size(),m=image[0].size();
        image[x][y]=color;
        // ans[x][y]=1;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m &&image[nx][ny]==c )
            dfs(nx,ny,image,color,c);
            //previous version give runtime error because for 0 it goes infinite loop

        }
    } 
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        // vector<vector<int>> ans(n,vector<int>(m,0));
        int c=image[sr][sc];
        if (c == color) return image;  // avoid infinite recursion

        dfs(sr,sc,image,color,c);
        
        return image;

        
    }
};