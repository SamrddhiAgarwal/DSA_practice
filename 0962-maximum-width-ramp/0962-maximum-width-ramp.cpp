// // class Solution {
// // public:
// //     int maxWidthRamp(vector<int>& nums) {
// //         vector<int>st;
// //         int len=0,n=nums.size();
// //         for(int i=0;i<n;i++)
// //         {
// //             while(!st.empty() && nums[st.back()]>nums[i])
// //             {
// //                 st.pop_back();
// //             }
// //             st.push_back(i);
// //             len=max(len,st.back()-st.front());
// //         }
// //         return len;
// //     }
// // };
// class Solution {
// public:
//     int maxWidthRamp(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> max_right(n);
        
//         // Fill max_right from right to left
//         max_right[n - 1] = nums[n - 1];
//         for (int i = n - 2; i >= 0; --i) {
//             max_right[i] = max(nums[i], max_right[i + 1]);
//         }
        
//         int i = 0, j = 0, max_width = 0;
        
//         // Two-pointer scan moving forward
//         while (j < n ) {
//             if (nums[i] <= max_right[j]) {
//                 max_width = max(max_width, j - i);
//                 j++; // Try to expand the window to the right
//             } else {
//                 i++; // Shrink the window from the left
//             }
//         }
//         return max_width;
//     }
// };
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // vector<int> index_stack;
        
        int n = nums.size();
        vector<int>min_left(n);
        min_left[0]=nums[0];
        // Step 1: Build a strictly decreasing stack of candidate starting indices
        for (int i = 0; i < n; ++i) {
            // if (index_stack.empty() || nums[index_stack.back()] > nums[i]) {
            //     index_stack.push_back(i);
            // }
            if(i==0) continue;
            min_left[i]=min(min_left[i-1],nums[i]);
        }
        
        int max_width = 0;
        
        // Step 2: Traverse backward with right pointer 'j'
        int i=n-1;
        for (int j = n - 1; j >= 0 && i>=0;) {
            // while (!index_stack.empty() && nums[index_stack.back()] <= nums[j]) {
            //     max_width = max(max_width, j - index_stack.back());
            //     index_stack.pop_back(); // Pop because this 'i' cannot get a wider ramp
            // }
            if(nums[j]>=min_left[i])
            {
                max_width=max(max_width,j-i);
                i--;
            }
            else
            {
                j--;
            }
            
        }
        return max_width;
    }
};
