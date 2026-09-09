// // // class Solution {
// // // public:
// // //     bool splitArraySameAverage(vector<int>& nums) {

// // //         int n = nums.size();

// // //         int mid = n / 2;

// // //         vector<vector<long long>> L(mid + 1);
// // //         vector<vector<long long>> R(n - mid + 1);

// // //         long long total = 0;

// // //         for (int x : nums)
// // //             total += x;


// // //         // Generate LEFT subset sums
// // //         for (int mask = 0; mask < (1 << mid); mask++) {

// // //             long long sum = 0;
// // //             int cnt = 0;

// // //             for (int i = 0; i < mid; i++) {

// // //                 if (mask & (1 << i)) {
// // //                     sum += nums[i];
// // //                     cnt++;
// // //                 }
// // //             }

// // //             L[cnt].push_back(sum);
// // //         }


// // //         // Generate RIGHT subset sums
// // //         int m = n - mid;

// // //         for (int mask = 0; mask < (1 << m); mask++) {

// // //             long long sum = 0;
// // //             int cnt = 0;

// // //             for (int i = 0; i < m; i++) {

// // //                 if (mask & (1 << i)) {
// // //                     sum += nums[mid + i];
// // //                     cnt++;
// // //                 }
// // //             }

// // //             R[cnt].push_back(sum);
// // //         }


// // //         // Try every possible subset size
// // //         for (int k = 1; k < n; k++) {

// // //             // k * total must be divisible by n
// // //             if ((k * total) % n != 0)
// // //                 continue;

// // //             long long target = (k * total) / n;


// // //             // i = elements selected from LEFT
// // //             for (int i = 0; i <= mid; i++) {

// // //                 int j = k - i;

// // //                 if (j < 0 || j > m)
// // //                     continue;

// // //                 unordered_set<long long> st(
// // //                     R[j].begin(),
// // //                     R[j].end()
// // //                 );

// // //                 for (long long x : L[i]) {

// // //                     long long need = target - x;

// // //                     if (st.count(need))
// // //                         return true;
// // //                 }
// // //             }
// // //         }

// // //         return false;
// // //     }
// // // };

// // // -----------------method-2---------------------
// // class Solution {
// // public:
// //     bool splitArraySameAverage(vector<int>& nums) {
// //         int n = nums.size();

// //         int total = accumulate(nums.begin(), nums.end(), 0);

// //         // dp[k][sum] = can we choose k elements with this sum?
// //         vector<vector<bool>> dp(n + 1, vector<bool>(total + 1, false));

// //         dp[0][0] = true;

// //         for (int num : nums) {

// //             // Go backwards so that one number isn't used multiple times
// //             for (int k = n - 1; k >= 0; k--) {

// //                 for (int sum = 0; sum + num <= total; sum++) {

// //                     if (dp[k][sum]) {
// //                         dp[k + 1][sum + num] = true;
// //                     }
// //                 }
// //             }
// //         }

// //         // Check every possible subset size
// //         for (int k = 1; k < n; k++) {

// //             // target must be an integer
// //             if ((k * total) % n != 0)
// //                 continue;

// //             int target = (k * total) / n;

// //             if (dp[k][target])
// //                 return true;
// //         }

// //         return false;
// //     }
// // };

// // ---------------------- method-3  dp optimisation
// class Solution {
// public:
//     bool splitArraySameAverage(vector<int>& nums) {

//         int n = nums.size();

//         int total = accumulate(nums.begin(), nums.end(), 0);

//         vector<vector<bool>> dp(
//             n / 2 + 1,
//             vector<bool>(total / 2 + 1, false)
//         );

//         dp[0][0] = true;

//         for (int num : nums) {

//             for (int k = n / 2; k >= 1; k--) {

//                 for (int sum = total / 2; sum >= num; sum--) {

//                     dp[k][sum] =
//                         dp[k][sum] ||
//                         dp[k - 1][sum - num];
//                 }
//             }
//         }

//         for (int k = 1; k <= n / 2; k++) {

//             if ((k * total) % n != 0)
//                 continue;

//             int target = (k * total) / n;

//             if (dp[k][target])
//                 return true;
//         }

//         return false;
//     }
// };
// ------------------method-4 mitm optimisation
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n=nums.size();
        int n1=n/2;
        int n2=n-n1;
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i]=n*nums[i];
        }
        vector<pair<int,int>>temp;
        for(int mask=0;mask<(1<<n1);mask++){
            int sum=0;
            int count=0;
            for(int i=0;i<n1;i++){
            if(1<<i & mask){
                sum+=nums[i];
                count++;
            }
            }
            temp.push_back({total*count-sum,count});
        }
        sort(temp.begin(),temp.end());
        for(int mask=0;mask<(1<<n2);mask++){
            int sum=0;
            int count=0;
            for(int i=0;i<n2;i++){
            if(1<<i & mask){
                sum+=nums[n1+i];
                count++;
            }
            }
            auto it=lower_bound(temp.begin(),temp.end(),make_pair(sum-total*count,-1));
            while(it!=temp.end() &&  (count+it->second==n || it->second+count==0))it++;
            if(it!=temp.end() && it->first==sum-total*count)return true;
        }
        return false;


    }
};