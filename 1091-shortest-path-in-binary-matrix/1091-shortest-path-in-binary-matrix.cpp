// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& matrix) {
//         int n = matrix.size();
// 	int m = matrix[0].size();

// 	queue<pair<int,int>> q;
// 	q.push({0,0});

// 	if(matrix[0][0] == 1)
// 		return -1;

// 	matrix[0][0] = 1;

// 	while(!q.empty())
// 	{
// 		auto it = q.front();
// 		int row = it.first;
// 		int col = it.second;
// 		int steps = matrix[row][col];
// 		q.pop();

// 		if(row == n-1 && col == m-1)
// 				return steps;

// 		for(int i= -1; i<= 1; i++)
// 		{
// 			for(int j = -1; j<=1; j++)
// 			{
// 				int nrow = row + i;
// 				int ncol = col + j;
// 				if(nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && matrix[nrow][ncol] == 0)
// 				{
// 					q.push({nrow, ncol});
// 					matrix[nrow][ncol] = steps +1;
// 				}
// 			}
// 		}
// 	}
// 	return -1;
//     }
// };


/*
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        
        queue<pair<int,int>>q;
        int sp=0;
        q.push({0,0});
        grid[0][0]=1;
        int sz;
        while(!q.empty())
        {
            sp++;
            sz=q.size();
            while(sz--)
            {
                auto [r,c]=q.front();
                q.pop();
                if(r==n-1 && c==m-1) return sp;

                for(int i=-1;i<=1;i++)
                {
                    for(int j=-1;j<=1;j++)
                    {
                        int x=r+i;
                        int y=c+j;
                        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==0)
                        {
                            grid[x][y]=1;
                            q.push({x,y});
                        }
                    }
                }
            }
        }
        return -1;
    }
};*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        
        queue<pair<int,int>>q;
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        q.push({0,0});
        grid[0][0]=1;
        dist[0][0]=1;
        while(!q.empty())
        {
            
            auto [r,c]=q.front();
            q.pop();
            if(r==n-1 && c==m-1) return dist[r][c];

            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int x=r+i;
                    int y=c+j;
                    // if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==0 && dist[x][y]>dist[r][c]+1)
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==0 )
                    {
                        grid[x][y]=1;
                        dist[x][y]=dist[r][c]+1;
                        q.push({x,y});                        
                    }
                }
            }
            
        }
        return -1;
    }
};