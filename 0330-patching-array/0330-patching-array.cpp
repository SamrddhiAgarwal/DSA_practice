class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long last=0;
        int i=0,ans=0;
        while(last<n)
        {
            if(i>=nums.size() || last+1<nums[i])
            {
                ans++;
                last=last+last+1;
            }
            else
            {
                last=last+nums[i];
                i++;
            }
        }
        return ans;
    }
};



// class Solution {
// public:
//     int minPatches(vector<int>& nums, int n) {
//         // A set to store all possible summations that can be formed
//         unordered_set<int> achievable_sums;
//         achievable_sums.insert(0); // Base case: sum of 0 elements

//         // 1. Initial loop through nums: update the summation combinations
//         for (int num : nums) {
//             // We must copy the current sums to avoid modifying the set while iterating
//             vector<int> current_sums(achievable_sums.begin(), achievable_sums.end());
//             for (int sum : current_sums) {
//                 long long new_sum = (long long)sum + num;
//                 if (new_sum <= n) {
//                     achievable_sums.insert(new_sum);
//                 }
//             }
//         }

//         int patches = 0;

//         // 2. Loop from 1 to n: check if the number cannot be formed
//         for (int target = 1; target <= n; ++target) {
//             // If the number doesn't exist in our achievable sums
//             if (achievable_sums.find(target) == achievable_sums.end()) {
//                 // Add that number (patch it)
//                 patches++;
                
//                 // Run summation updates for this new patched number
//                 vector<int> current_sums(achievable_sums.begin(), achievable_sums.end());
//                 for (int sum : current_sums) {
//                     long long new_sum = (long long)sum + target;
//                     if (new_sum <= n) {
//                         achievable_sums.insert(new_sum);
//                     }
//                 }
//             }
//         }

//         return patches;
//     }
// };
