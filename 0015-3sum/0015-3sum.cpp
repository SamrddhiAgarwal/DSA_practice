class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        // Step 1: Sort the array to use the two-pointer technique
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            // Early Stopping: If the smallest number is > 0, 
            // no three numbers can sum to 0
            if (nums[i] > 0) {
                break;
            }
            
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Step 2: Initialize two pointers
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicate values for the left pointer
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // Skip duplicate values for the right pointer
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    // Move both pointers inward after finding a valid triplet
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    // Sum is too small, move left pointer to get a larger number
                    left++;
                } 
                else {
                    // Sum is too large, move right pointer to get a smaller number
                    right--;
                }
            }
        }
        
        return result;
    }
};