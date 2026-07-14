
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Min-heap storing: {obstacles_removed, i, j}
        // Greater<vector<int>> makes it a Min-Heap instead of a Max-Heap
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // Distance/Visited array to store minimum obstacles removed to reach cell (i, j)
        vector<vector<int>> dist(n, vector<int>(m, 1e9)); 
        
        // Start from top-left corner
        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int rem = curr[0];
            int i = curr[1];
            int j = curr[2];
            
            // Destination reached! Guaranteed to be the global minimum.
            if(i == n - 1 && j == m - 1) return rem;
            
            // If we found a worse path than a previously processed one, skip it
            if(rem > dist[i][j]) continue;
            
            for(int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                
                // Boundary check
                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    // Cost to move into the next cell
                    int next_rem = rem + grid[nx][ny];
                    
                    // Relaxation step: only push if we found a strictly better path
                    if(next_rem < dist[nx][ny]) {
                        dist[nx][ny] = next_rem;
                        pq.push({next_rem, nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};
