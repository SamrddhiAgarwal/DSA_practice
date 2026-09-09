class Solution {
public:

    
    int minAbsDifference(vector<int>& nums, int goal) {

        int n = nums.size();
        int mid = n / 2;

        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        vector<long long> L, R;

         // Generate subset sums of left
        for (int mask = 0; mask < (1 << left.size()); mask++) {
            long long sum = 0;

            for (int i = 0; i < left.size(); i++) {
                if (mask & (1 << i))
                    sum += left[i];
            }

            L.push_back(sum);
        }

        // Generate subset sums of right
        for (int mask = 0; mask < (1 << right.size()); mask++) {
            long long sum = 0;

            for (int i = 0; i < right.size(); i++) {
                if (mask & (1 << i))
                    sum += right[i];
            }

            R.push_back(sum);
        }
        sort(R.begin(), R.end());

        long long ans = LLONG_MAX;

        for (long long x : L) {

            long long need = goal - x;

            auto it = lower_bound(R.begin(), R.end(), need); //lowerbound gives number or first number greater than need

            // Candidate >= need
            if (it != R.end()) {
                ans = min(ans, abs(x + *it - goal));
            }

            // Candidate < need
            if (it != R.begin()) {
                --it;
                ans = min(ans, abs(x + *it - goal)); // since number before has less diatnce than number greater than it 
            }
        }

        return ans;
    }
};
// class Solution {
// public:
//     int minAbsDifference(vector<int>& nums, int goal) {
//         int sum=0;
//         for(auto&n:nums) sum+=abs(n);

//         int n=nums.size();
//         // vector<vector<bool>>dp(n,nums);
//         vector<bool>prev(2*sum+1,false),curr(2*sum+1,false);
//         int ans=INT_MAX;

//         // prev[nums[0]+sum]=true;
//         // if (nums[0] + sum >= 0 && nums[0] + sum <= 2 * sum) {
//             prev[nums[0] + sum] = true; // Picking the first element
//             ans = min(ans, abs(nums[0] - goal));

//         // }
        
//         prev[0+sum]=true;
//         ans = min(ans, abs(0 - goal));

//         for(int i=1;i<n;i++)
//         {
//             // curr[0]=true;
//             for(int s=-sum;s<=sum;s++)
//             {
//                 curr[s+sum]=false;
//                 curr[s+sum]=prev[s+sum];
//                 // if(nums[i]<=s) curr[s+sum]=curr[s+sum] || prev[s-nums[i]+sum];
//                  long long prev_s = (long long)s - nums[i]; 
//                 if(prev_s >= -sum && prev_s <= sum) {
//                     curr[s+sum] = curr[s+sum] || prev[prev_s + sum];
//                 }
        
//                 if(curr[s+sum]) ans=min(ans,abs(s-goal));
//             }
//             prev=curr;
//         }
//         return ans;
//     }
// };
