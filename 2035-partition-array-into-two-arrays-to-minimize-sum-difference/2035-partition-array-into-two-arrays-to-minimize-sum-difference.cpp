class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;

        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        // vector<long long> L, R;
        vector<vector<long long>> L(mid + 1);
        vector<vector<long long>> R(mid + 1);

         // Generate subset sums of left
        for (int mask = 0; mask < (1 << left.size()); mask++) {
            long long sum = 0;
            int cnt = 0;

            for (int i = 0; i < left.size(); i++) {
                if (mask & (1 << i)){
                    sum += left[i];
                    cnt++;
                }
            }

            L[cnt].push_back(sum);
        }

        // Generate subset sums of right
        for (int mask = 0; mask < (1 << right.size()); mask++) {
            long long sum = 0;
            int cnt=0;
            for (int i = 0; i < right.size(); i++) {
                if (mask & (1 << i)){
                    sum += right[i];
                    cnt++;
                }
            }

            R[cnt].push_back(sum);
        }
        // sort(R.begin(), R.end());
        for (int k = 0; k <= mid; k++) {
            sort(R[k].begin(), R[k].end());
        }

        long long total=0;
        for (int x : nums)
        total += x;
        long long ans = LLONG_MAX;
        long long goal= total/2;         //we want s ,t-s diff min s+t-s=0 t-2s=0 so find s=t/2 and s=n/2
        for (int k = 0; k <= mid; k++) {

            for (long long x : L[k]) {

                long long need = goal - x;

                auto it = lower_bound(R[mid-k].begin(), R[mid-k].end(), need); //lowerbound gives number or first number greater than need

                // Candidate >= need
                if (it != R[mid-k].end()) {
                    // ans = min(ans, llabs(2*(x + *it - goal))); can cuase error due to divisoon that is why use normal
                    ans = min(ans, llabs(2 * (x + *it) - total));
                }

                // Candidate < need
                if (it != R[mid-k].begin()) {
                    --it;
                    // ans = min(ans, llabs(2*(x + *it - goal))); // since number before has less diatnce than number greater than it 
                    ans = min(ans, llabs(2 * (x + *it) - total));
                }
            }
        }

        return ans;
    }
};
// class Solution {
// public:
//     int minimumDifference(vector<int>& nums) {
//         int n=nums.size();
//         int sum=0;
//         for(auto &n:nums) sum+=abs(n);
//         vector<vector<bool>> dp(n,vector<bool>(2*sum+1,false));
//         for(int i=0;i<n;i++)
//         {
//             dp[i][sum]=true;
//         }
//         if(abs(nums[0])<=sum) dp[0][abs(nums[0])]=true;
//         int ans=1e9;
//         for(int i=1;i<n;i++)
//         {
//             for(int s=-sum;s<=sum;s++)
//             {
//             bool not_take=dp[i-1][s+sum];
//             bool take=false;
//             if(s>nums[i])
//             take=dp[i-1][s+sum-nums[i]];
//             dp[i][s+sum]=take|not_take;
//             if(dp[i][s+sum]) ans=min(ans,abs((sum-s)-s));
//             }
//         }
//         return ans;
//     }
// };