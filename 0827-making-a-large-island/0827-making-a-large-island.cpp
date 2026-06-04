/*
class Solution {
public:
    int dfs(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& vis) // other method is using int& cnt 
    {
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        int size=1;
        for(int i=0;i<4;i++)
        {
            int x=row+dx[i];
            int y=col+dy[i];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && !vis[x][y])
            {
                
                size+=dfs(grid,x,y,vis);
            } 
        }
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<vector<int>> nvis(n,vector<int>(n,0));
        int mx=0; int cnt=0;// one method istaking each element for case where 1 is more but it will cause tle so one of modifies way is this
        // this method still gives tle since it is using every zero 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    vis=nvis;
                    mx=max(mx,dfs(grid,i,j,vis));
                    cnt++;
                }
            }
        }
        if(cnt==0) return n*n;
        return mx;
    }
};*/

//method 2 we calculate mx for all one store it but the problem is no it's solve no it's not 0 1 1      0011
//       1 0 1      1101
//       1 1 0      0100
//                  1100

class Solution {
public:
    int dfs(vector<vector<int>>& grid,int row,int col,int color) 
    {
        grid[row][col]=color;
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        int size=1;
        for(int i=0;i<4;i++)
        {
            int x=row+dx[i];
            int y=col+dy[i];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 )
            {
                
                size+=dfs(grid,x,y,color);
            } 
        }
        return size;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        // vector<vector<int>> vis(n,vector<int>(n,0));
        vector<int> area;int c=2;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int sz=dfs(grid,i,j,c);
                    mx=max(mx,sz);
                    area.push_back(sz);
                    c++;
                }
            }
        }

        set<int> st;
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    for(int d=0;d<4;d++)
                    {
                        int x=i+dx[d];
                        int y=j+dy[d];
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]!=0 )
                        {
                            st.insert(grid[x][y]);
                        } 
                    }
                    int a=1;
                    for(auto color:st)
                    {
                        if(color>1)
                        a+=area[color-2];
                    }
                    st.clear();
                    mx=max(mx,a);
                }
            }
        }
        return mx;
    }
};
/* solution which is done in acceptance 
class Solution {
public:
    int findParent(int node, vector<int>& parent){
        if(parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node], parent);
    }

    void unionBySize(int u, int v,
                     vector<int>& size,
                     vector<int>& parent){

        int pu = findParent(u,parent);
        int pv = findParent(v,parent);

        if(pu == pv) return;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv]+= size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu]+= size[pv];
        }
    }

    bool isValid(int i , int j , int n){
        return i>=0 && j>=0 && i<n && j<n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> parent(n*n);
        vector<int> size(n*n , 1);
        
        vector<int> r ={ -1 , 0 , 1 , 0};
        vector<int> c ={ 0 , 1 , 0 , -1};

        for(int i=0;i<n*n ;i++)
            parent[i] = i;

        for(int i =0 ;i<n ;i++){
            for(int j= 0 ;j < n ;j++){
                if(grid[i][j]==1){
                int num = i * n + j;

                for(int k=0 ;k<4 ;k++){
                    int newR = i+ r[k];
                    int newC = j + c[k];

                    if(isValid(newR , newC , n )&& grid[newR][newC] == 1){
                        int neigh = (newR * n ) + (newC);
                        unionBySize(neigh , num , size , parent);
                    }
                }
                }
            }
        }

        int maxi = INT_MIN;
        for(int i =0 ;i<n ;i++){
            for(int j= 0 ;j < n ;j++){
               if(grid[i][j]==0){
                int num = i * n + j;

                set<int> components;
                for(int k=0 ;k<4 ;k++)
                {
                    int newR = i+ r[k];
                    int newC = j + c[k];

                    if(isValid(newR , newC , n) && grid[newR][newC] == 1){
                        components.insert(findParent((newR * n ) + newC , parent));
                    }
                }
                int totalSize = 1;
                for( auto it : components)
                {
                    totalSize += size[it];
                }
                maxi = max(maxi , totalSize);


              }
            }
        }

        //imp : all 1s
        for(int i=0;i<n*n;i++){
            maxi = max(maxi , size[findParent(i,parent)]);
        }
        return maxi;

    }
};*/



/*dsu solution class DSU {

public:
    vector<int> parent, size;

    DSU(int n) {

        parent.resize(n);

        size.resize(n, 1);  

        for(int i = 0; i < n; i++) {

            parent[i] = i;

        }

    }

    int find(int x) {

        if(parent[x] != x)

            parent[x] = find(parent[x]);

        return parent[x];

    }

    void unite(int x, int y) {

        int px = find(x);

        int py = find(y);



        if(px == py) return;



        if(size[px] < size[py]) {

            parent[px] = py;

            size[py] += size[px];

        } else {

            parent[py] = px;

            size[px] += size[py];

        }

    }

};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n * n);
        bool hasZero = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int node = i * n + j;
                if(grid[i][j] == 1){
                    int ir = i, jr = j + 1;
                    int id = i + 1, jd = j;
                    if(jr < n && grid[ir][jr] == 1){
                        ds.unite(node, ir * n + jr);
                    }
                    if(id < n && grid[id][jd] == 1){
                        ds.unite(node, id * n + jd);
                    }
                } else {
                    hasZero = true; 
                }
            }
        }
        if (!hasZero) return n * n;

        int ans = 0;
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    set<int> st;
                    int curr = 1;

                    for(int k = 0; k < 4; k++){
                        int id = i + dir[k][0], jd = j + dir[k][1];
                        if(id < n && id >= 0 && jd < n && jd >= 0 && grid[id][jd] == 1){
                            int neighbor = id * n + jd;
                            int root = ds.find(neighbor); 
                            
                            if(st.find(root) == st.end()){
                                st.insert(root);
                                curr += ds.size[root];    
                            }
                        }
                    }
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};*/