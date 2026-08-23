class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        long long MOD = 1e9 + 7;
        
        // 1. Create the prefix sum array
        vector<int> P(n, 0);
        P[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            P[i] = P[i - 1] + nums[i];
        }
        
        int total_sum = P[n - 1];
        int count = 0;
        
        // 2. Iterate through the possible end indices of the 'left' subarray
        // Left can at most go up to n-3 because mid and right must be non-empty.
        // Also, P[i] cannot exceed total_sum / 3.
        for (int i = 0; i < n - 2 && P[i] <= total_sum / 3; ++i) {
            
            // Define the search space bounds for P[j]
            int min_Pj = 2 * P[i];
            int max_Pj = (total_sum + P[i]) / 2;
            
            // Search range for j must be strictly within (i + 1) and (n - 2)
            auto start_it = P.begin() + i + 1;
            auto end_it = P.begin() + n - 1; 
            
            // Find the first index where P[j] >= min_Pj
            auto left_idx_it = lower_bound(start_it, end_it, min_Pj);
            
            // Find the first index where P[j] > max_Pj
            auto right_idx_it = upper_bound(start_it, end_it, max_Pj);
            
            // Calculate how many valid 'j' positions exist in this window
            if (left_idx_it < right_idx_it) {
                int valid_options = distance(left_idx_it, right_idx_it);
                count = (count + valid_options) % MOD;
            }
        }
        
        return count;
    }
};
//thuis won't work since we need atleast lowest of mid to strat is sum atleast  low is p[i]  and to reach the idx to reach that p[i]+p[i] is need like 
//max totalsum-p[i])/2   to reach totalsum/2-p[i]/2+p[i]=toatlsum+p[i])/2

                    // #include <vector>
                    // #include <algorithm>

                    // using namespace std;

                    // class Solution {
                    // public:
                    //     int waysToSplit(vector<int>& nums) {
                    //         int n = nums.size();
                    //         long long MOD = 1e9 + 7;
                            
                    //         // 1. Create the prefix sum array
                    //         vector<int> P(n, 0);
                    //         P[0] = nums[0];
                    //         for (int i = 1; i < n; ++i) {
                    //             P[i] = P[i - 1] + nums[i];
                    //         }
                            
                    //         int total_sum = P[n - 1];
                    //         int count = 0;
                            
                    //         // 2. Iterate through the possible end indices of the 'left' subarray
                    //         // Left can at most go up to n-3 because mid and right must be non-empty.
                    //         // Also, P[i] cannot exceed total_sum / 3.
                    //         for (int i = 0; i < n - 2 && P[i] <= total_sum / 3; ++i) {
                                
                    //             // Define the search space bounds for P[j]
                    //             int min_Pj = P[i];
                    //             int max_Pj = (total_sum - P[i]) / 2;
                                
                    //             // Search range for j must be strictly within (i + 1) and (n - 2)
                    //             auto start_it = P.begin() + i + 1;
                    //             auto end_it = P.begin() + n - 1; 
                                
                    //             // Find the first index where P[j] >= min_Pj
                    //             // auto left_idx_it = lower_bound(start_it, end_it, min_Pj);
                                
                    //             // Find the first index where P[j] > max_Pj
                    //             auto right_idx_it = upper_bound(start_it, end_it, max_Pj);
                                
                    //             // Calculate how many valid 'j' positions exist in this window
                    //             // if (left_idx_it < right_idx_it) {
                    //             //     int valid_options = distance(left_idx_it, right_idx_it);
                    //             //     count = (count + valid_options) % MOD;
                    //             // }
                    //             count+=right_idx_it-start_it;
                    //         }
                            
                    //         return count;
                    //     }
                    // };
                    //thuis won't work since we need atleast lowest of mid to strat is sum atleast  low is p[i]  and to reach the idx to reach that p[i]+p[i] is need like 
                    //max totalsum-p[i])/2   to reach totalsum/2-p[i]/2+p[i]=toatlsum+p[i])/2
