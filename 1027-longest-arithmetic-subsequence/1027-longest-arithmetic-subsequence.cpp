// class Solution {
// public:
//     helper()
//     {
//         if(i==n)
//         return 0;

//         //take 
//         if(arr[i]-prev==diff)
//         {
//             take=1+helper(i+1,arr[i],diff);
//         }
//         not_take=helper(i+1,prev,diff);
//         return max(take,not_take);
//     }
//     int longestArithSeqLength(vector<int>& nums) {
        
//     }
// };
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int max_len = 2;
        
        // dp[i][diff] stores the max length ending at index i with a given difference
        // Difference range: -500 to 500. With 500 offset, the range is 0 to 1000.
        vector<vector<int>> dp(n, vector<int>(1001, 1));
                // dp[i] is a hash map storing {diff -> length} for sequences ending at index i

        // vector<unordered_map<int, int>> dp(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // Add 500 offset to handle negative differences safely
                int diff = nums[i] - nums[j] + 500; 
                
                // Extend the sequence ending at j, or start a new one (1 + 1 = 2)
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                // dp[i][diff] = ( dp[j][diff] + 1);
                // int new_len = dp[j].count(diff) ? dp[j][diff] + 1 : 2;

                // // Use max to ensure we never overwrite a longer sequence found via a different 'j'
                // dp[i][diff] = max(dp[i][diff], new_len); 

                
                // Track the global maximum length found so far
                max_len = max(max_len, dp[i][diff]);
            }
        }
        
        return max_len;
    }
};
