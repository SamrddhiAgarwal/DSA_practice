#include <vector>
#include <numeric>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
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
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);
        
        // 1. Union all allowed swap indices
        for (const auto& swap : allowedSwaps) {
            dsu.unite(swap[0], swap[1]);
        }
        
        // 2. Group source frequencies by their component root index
        // Root Parent Index -> Map of {Number -> Frequency}

        unordered_map<int, unordered_map<int, int>> componentCounts;
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            componentCounts[root][source[i]]++;
        }
        
        int hammingDistance = 0;
        
        // 3. Compare with target elements
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            int targetNum = target[i];
            
            // Check if the target number exists within this connected component's source pool
            if (componentCounts[root][targetNum] > 0) {
                componentCounts[root][targetNum]--; // Successfully matched!
            } else {
                hammingDistance++; // No match available in this component
            }
        }
        
        return hammingDistance;
    }
};
