// #include <vector>
// #include <algorithm>

// using namespace std;

// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int n = nums.size();
//         if (n < 2) return n;
        
//         // Base Case: A single element is a valid wiggle subsequence of length 1
//         int state_0 = 1; // Ends with a negative difference
//         int state_1 = 1; // Ends with a positive difference
        
//         for (int i = 1; i < n; ++i) {
//             int diff = nums[i] - nums[i - 1];
            
//             if (diff > 0) {
//                 // A positive difference extends a sequence that ended in a negative difference
//                 state_1 = state_0 + 1;
//             } 
//             else if (diff < 0) {
//                 // A negative difference extends a sequence that ended in a positive difference
//                 state_0 = state_1 + 1;
//             }
//             // If diff == 0, we do nothing; the elements are flat
//         }
        
//         // The overall answer is the max of both valid sequence patterns
//         return max(state_0, state_1);
//     }
// };
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> ans;

        for(int i=1;i<nums.size();i++){
            int p=nums[i]-nums[i-1];
            ans.push_back(p);
        }
        int count=1;
        int prev=0;
    
        for(int i=0;i<ans.size();i++){
                if(ans[i]>0 && prev<=0){
                    count++;
                    prev=ans[i];
                }else if(ans[i]<0 && prev>=0){
                    count++;
                    prev=ans[i];
                }
            }
        return count; 
    }
};