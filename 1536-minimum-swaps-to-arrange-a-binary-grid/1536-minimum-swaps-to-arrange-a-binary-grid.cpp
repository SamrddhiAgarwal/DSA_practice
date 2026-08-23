// // class Solution {
// // public:
// //     int minSwaps(vector<vector<int>>& grid) {
// //         int n = grid.size();
// //         vector<int> arr(n, 0);
        
// //         for (int i = 0; i < n; ++i) {
// //             int zeros = 0;
// //             for (int j = n - 1; j >= 0; --j) {
// //                 if (grid[i][j] == 0) {
// //                     zeros++;
// //                 } else {
// //                     break; // Stop at the first '1' from the right
// //                 }
// //             }
// //             arr[i] = zeros;
// //         }

// //         int minswaps=0;

// //         for(int i=0;i<n;i++)
// //         {
// //             for(int j=0;j<n-i-1;j++)
// //             {
// //                 if(arr[j]<arr[j+1])
// //                 {
// //                     swap(arr[j],arr[j+1]);
// //                     minswaps++;
// //                 }
// //             }
// //         }

// //         for(int i=0;i<n;i++)
// //         {
// //             if(arr[i]<n-1-i)
// //             return -1;;
// //         }
// //         return minswaps;
// //     }
// // };
// #include <vector>
// #include <algorithm>

// using namespace std;

// class Solution {
// public:
//     int minSwaps(vector<vector<int>>& grid) {
//         int n = grid.size();
//         vector<int> trailing_zeros(n, 0);
        
//         // 1. Count trailing zeros for each row
//         for (int i = 0; i < n; ++i) {
//             int zeros = 0;
//             for (int j = n - 1; j >= 0; --j) {
//                 if (grid[i][j] == 0) zeros++;
//                 else break;
//             }
//             trailing_zeros[i] = zeros;
//         }
        
//         int total_swaps = 0;
        
//         // 2. Greedily find and simulate adjacent swaps
//         for (int i = 0; i < n; ++i) {
//             int required = n - 1 - i;
//             int found_idx = -1;
            
//             for (int j = i; j < n; ++j) {
//                 if (trailing_zeros[j] >= required) {
//                     found_idx = j;
//                     break; // Take the closest matching row
//                 }
//             }
            
//             if (found_idx == -1) return -1; // Impossible grid
            
//             // Bubble the target row up to position i
//             for (int k = found_idx; k > i; --k) {
//                 swap(trailing_zeros[k], trailing_zeros[k - 1]);
//                 total_swaps++;
//             }
//         }
        
//         return total_swaps;
//     }
// };
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailing_zeros(n, 0);
        vector<int> counts(n, 0); // Tracks frequencies of zero capacities
        
        for (int i = 0; i < n; ++i) {
            int zeros = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) zeros++;
                else break;
            }
            trailing_zeros[i] = zeros;
            counts[min(zeros, n - 1)]++; // Cap at n-1 since extra zeros don't hurt
        }
        
        // --- EARLY EXIT FEASIBILITY CHECK ---
        int available_rows = 0;
        for (int req = n - 1; req >= 0; --req) {
            available_rows += counts[req];
            if (available_rows < (n - req)) {
                return -1; // Fail early: not enough qualified rows exist globally
            }
        }
        
        // --- SIMULATION PHASE (Guaranteed to succeed now) ---
        int total_swaps = 0;
        for (int i = 0; i < n; ++i) {
            int required = n - 1 - i;
            int found_idx = i;
            
            while (trailing_zeros[found_idx] < required) {
                found_idx++;
            }
            
            for (int k = found_idx; k > i; --k) {
                swap(trailing_zeros[k], trailing_zeros[k - 1]);
                total_swaps++;
            }
        }
        
        return total_swaps;
    }
};
