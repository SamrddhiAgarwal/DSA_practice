class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
                int n = nums.size();
        int totalFlips = 0;
        int currentFlips = 0; // Tracks the flip count currently affecting index i
        
        for (int i = 0; i < n; i++) {
            // 1. Remove the flip that expires at index i
            if (i >= k && nums[i - k] > 1) {
                currentFlips--;
                nums[i - k] -= 2; // Optional: Restore original value (0 or 1)
            }
            
            // 2. Check the parity to see if the current bit is effectively 0
            // If original bit is 0 and flips are even, it remains 0.
            // If original bit is 1 and flips are odd, it becomes 0.
            if ((nums[i] + currentFlips) % 2 == 0) {
                // If a flip is needed but the window extends out of bounds, it's impossible
                if (i + k > n) {
                    return -1;
                }
                
                // Execute the greedy flip starting at index i
                totalFlips++;
                currentFlips++;
                nums[i] += 2; // Mark that a flip was initiated at this index
            }
        }
        
        return totalFlips;

    }
};
// class Solution {
// public:
//     int minKBitFlips(vector<int>& nums, int k) {
//         int n=nums.size(),no=0;
//         int mask=(1<<k)-1;
//         for(int i=0;i<n;i++)
//         {
//             no=no*10+nums[i]
//         }
//         for(int i=0;i<n-k;i++)
//         {
//             if(nums[i]==0)
//             {
//                 no=no^(mask<<n-i-k)
//             }
//         }
//     }
// };
