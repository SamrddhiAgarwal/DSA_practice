#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int totalSum = 0;
        int max_so_far = -1e9, current_max = 0;
        int min_so_far = 1e9, current_min = 0;
        
        for (int x : nums) {
            totalSum += x;
            
            // Standard Kadane to find the max subarray sum
            current_max += x;
            max_so_far = std::max(max_so_far, current_max);
            if (current_max < 0) current_max = 0;
            
            // Inverted Kadane to find the min subarray sum
            current_min += x;
            min_so_far = std::min(min_so_far, current_min);
            if (current_min > 0) current_min = 0;
        }
        
        // Edge Case: If all numbers are negative, max_so_far will be negative.
        // totalSum - min_so_far would equal 0 (empty array), which isn't allowed.
        if (max_so_far < 0) {
            return max_so_far;
        }
        
        // Return the best option between the straight max and the wrapped max
        return std::max(max_so_far, totalSum - min_so_far);
    }
};
// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& nums) {

//         int n=nums.size();
//         int ans=-1e9;
//         int s=0;
//         int start=0;
//         for(int i=0;i<n;i++)
//         {
//             if(s==0)
//             start=i;
//             s+=nums[i];
//             ans=max(ans,s);
//             if(s<0)
//             {
//                 s=0;
//             }

//         }
//         if(ans<0) return ans;
//         for(int i=0;i<n;i++)
//         {
//             if(i>=start)
//             s-=nums[i];
//             ans=max(ans,s);
//             s+=nums[i];
//             if(s<0)
//             break;
//         }
//         return ans;
//     }
// };