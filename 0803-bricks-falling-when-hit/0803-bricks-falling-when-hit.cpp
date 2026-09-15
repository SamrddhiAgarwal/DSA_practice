#include <vector>
#include <numeric>

using namespace std;

class DSU {
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n, 1);
    }
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            size[root_j] += size[root_i];
        }
    }
    
    int getSize(int i) {
        return size[find(i)];
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int r = grid.size();
        int c = grid[0].size();
        
        // 1. Mark hits on the grid. 
        // If a brick was 1, make it 2 (means it was present but got hit). If it was 0, it stays 0.
        for (auto& hit : hits) {
            if (grid[hit[0]][hit[1]] == 1) {
                grid[hit[0]][hit[1]] = 2;
            }
        }
        
        // DSU size: r * c elements + 1 virtual node for the "Roof" at index (r * c)
        int roof = r * c;
        DSU dsu(roof + 1);
        
        // Helper to convert 2D coordinate to 1D index
        auto getIndex = [&](int i, int j) { return i * c + j; };
        
        // 2. Build the initial DSU graph with remaining stable bricks (grid[i][j] == 1)
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 1) {
                    if (i == 0) dsu.unite(getIndex(i, j), roof);
                    
                    // Connect with top and left neighbors to avoid double-connecting
                    if (i > 0 && grid[i - 1][j] == 1) dsu.unite(getIndex(i, j), getIndex(i - 1, j));
                    if (j > 0 && grid[i][j - 1] == 1) dsu.unite(getIndex(i, j), getIndex(i, j - 1));
                }
            }
        }
        
        vector<int> result(hits.size(), 0);
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // 3. Process hits in reverse order
        for (int k = hits.size() - 1; k >= 0; --k) {
            int hr = hits[k][0];
            int hc = hits[k][1];
            
            // If it was originally empty (0), hitting it does nothing
            if (grid[hr][hc] == 0) continue;
            
            int preRoofSize = dsu.getSize(roof);
            
            // Restore the brick
            grid[hr][hc] = 1;
            if (hr == 0) dsu.unite(getIndex(hr, hc), roof);
            
            // Connect to its 4 neighbors
            for (auto& d : dirs) {
                int nr = hr + d[0];
                int nc = hc + d[1];
                if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc] == 1) {
                    dsu.unite(getIndex(hr, hc), getIndex(nr, nc));
                }
            }
            
            int postRoofSize = dsu.getSize(roof);
            
            // If the size increased, the difference (minus the restored brick itself) 
            // represents the bricks that were brought back into connection with the roof.
            result[k] = max(0, postRoofSize - preRoofSize - 1);
        }
        
        return result;
    }
};
