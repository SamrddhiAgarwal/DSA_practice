#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int maxSumTwoNoOverlap(std::vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        
        // 1. Build an in-place prefix sum array to calculate range sums in O(1)
        std::vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }
        
        // Helper lambda to get the sum of elements in range [left, right] inclusive
        auto getRangeSum = [&](int left, int right) {
            return pref[right + 1] - pref[left];
        };
        
        int max_total_sum = 0;
        
        // Case 1: 'firstLen' subarray comes BEFORE 'secondLen' subarray
        int max_first = 0;
        for (int i = firstLen + secondLen - 1; i < n; ++i) {
            // Update the maximum sum of the 'firstLen' window seen so far to the left
            int current_first = getRangeSum(i - firstLen - secondLen + 1, i - secondLen);
            max_first = std::max(max_first, current_first);
            
            // Pair it with the current 'secondLen' window ending at index i
            int current_second = getRangeSum(i - secondLen + 1, i);
            max_total_sum = std::max(max_total_sum, max_first + current_second);
        }
        
        // Case 2: 'secondLen' subarray comes BEFORE 'firstLen' subarray
        int max_second = 0;
        for (int i = firstLen + secondLen - 1; i < n; ++i) {
            // Update the maximum sum of the 'secondLen' window seen so far to the left
            int current_second = getRangeSum(i - firstLen - secondLen + 1, i - firstLen);
            max_second = std::max(max_second, current_second);
            
            // Pair it with the current 'firstLen' window ending at index i
            int current_first = getRangeSum(i - firstLen + 1, i);
            max_total_sum = std::max(max_total_sum, max_second + current_first);
        }
        
        return max_total_sum;
    }
};
