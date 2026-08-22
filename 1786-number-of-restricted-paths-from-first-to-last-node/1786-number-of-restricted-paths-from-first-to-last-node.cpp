
// class Solution {
// public:
//     long long MOD = 1e9 + 7;
    
//     long long dfs(int u, int n, vector<vector<pair<int, int>>>& adj, vector<long long>& dist, vector<long long>& memo) {
//         if (u == n) return 1; // Reached destination
//         if (memo[u] != -1) return memo[u]; // Return cached answer
        
//         long long total_ways = 0;
//         for (auto& edge : adj[u]) {
//             int v = edge.first;
//             // Strict evaluation criterion
//             if (dist[u] > dist[v]) {
//                 total_ways = (total_ways + dfs(v, n, adj, dist, memo)) % MOD;
//             }
//         }
        
//         return memo[u] = total_ways;
//     }
//     int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
//         // 1. Build adjacency list
//         vector<vector<pair<int, int>>> adj(n + 1);
//         for (const auto& edge : edges) {
//             adj[edge[0]].push_back({edge[1], edge[2]});
//             adj[edge[1]].push_back({edge[0], edge[2]});
//         }
        
//         // 2. Run Dijkstra from node n
//         vector<long long> dist(n + 1, 1e18); // Use a large value for infinity
//         dist[n] = 0;
//         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
//         pq.push({0, n});
        
//         while (!pq.empty()) {
//             auto [d, u] = pq.top();
//             pq.pop();
            
//             if (d > dist[u]) continue;
            
//             for (auto& edge : adj[u]) {
//                 int v = edge.first;
//                 int w = edge.second;
//                 if (dist[u] + w < dist[v]) {
//                     dist[v] = dist[u] + w;
//                     pq.push({dist[v], v});
//                 }
//             }
//         }

//         // vector<long long> memo(n + 1, -1);
//         // return dfs(1, n, adj, dist, memo);
        
//         // 3. Sort node labels based on their Dijkstra distance (Topological Sort)
//         vector<int> sorted_nodes(n);
//         for (int i = 0; i < n; ++i) sorted_nodes[i] = i + 1;
        
//         sort(sorted_nodes.begin(), sorted_nodes.end(), [&](int a, int b) {
//             return dist[a] < dist[b];
//         });
        
//         // 4. Bottom-up DP tabulation over the sorted order
//         vector<long long> ways(n + 1, 0);
//         ways[n] = 1; // Base case
        
//         for (int u : sorted_nodes) {
//             for (auto& edge : adj[u]) {
//                 int v = edge.first;
//                 if (dist[u] > dist[v]) {
//                     ways[u] = (ways[u] + ways[v]) % MOD;
//                 }
//             }
//         }
        
//         return ways[1];
//     }
// };
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        long long MOD = 1e9 + 7;
        
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<long long> dist(n + 1, 1e18);
        vector<long long> ways(n + 1, 0);
        
        dist[n] = 0;
        ways[n] = 1; // Base case
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, n});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            if (d > dist[u]) continue;
            
            // Look at all neighbors to propagate counts or update paths
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                
                // 1. Classical Dijkstra distance update 
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
                
                // 2. On-the-fly path count update
                // If neighbor 'v' has a larger finalized distance than current node 'u',
                // 'v' can safely inherit the valid ways coming out from 'u'.
                if (dist[v] > dist[u]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        
        return ways[1];
    }
};
