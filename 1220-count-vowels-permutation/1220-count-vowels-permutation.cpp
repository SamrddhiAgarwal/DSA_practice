// class Solution {
// public:
//     int countVowelPermutation(int n) {
//         vector<vector<int>> adj(5);
//         adj[0]={1};
//         adj[1]={0,2};
//         adj[2]={0,1,3,4};
//         adj[3]={2,4};
//         adj[4]={0};

//         vector<long long>prev(5,1),curr(5,0);
        
//         int ans=0,MOD=1e9+7;
//         for(int i=1;i<n;i++)
//         {
//             for(int j=0;j<5;j++)
//             {
//                 curr[j]=0;
//                 for(auto c:adj[j])
//                 curr[j]=(curr[j]+prev[c])%MOD;
//             }
//             prev=curr;
//         }
//         for(int i=0;i<5;i++)
//         {
//             ans=(ans+prev[i])%MOD;
//         }
//         return ans;
//     }
// };


// method-2
#include <numeric>

class Solution {
public:
    int countVowelPermutation(int n) {
        int MOD = 1e9 + 7;
        
        // Base case: for strings of length 1, each vowel has exactly 1 valid combination
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        
        for (int step = 1; step < n; ++step) {
            // Calculate next states based on who can precede each character:
            // 'a' can be preceded by 'e', 'i', 'u'
            long long next_a = (e + i + u) % MOD;
            // 'e' can be preceded by 'a', 'i'
            long long next_e = (a + i) % MOD;
            // 'i' can be preceded by 'e', 'o'
            long long next_i = (e + o) % MOD;
            // 'o' can be preceded by 'i'
            long long next_o = i;
            // 'u' can be preceded by 'i', 'o'
            long long next_u = (i + o) % MOD;
            
            // Move next states into active trackers
            a = next_a;
            e = next_e;
            i = next_i;
            o = next_o;
            u = next_u;
        }
        
        // Safely accumulate everything using long long tracking to prevent overflows
        long long total_permutations = (a + e + i + o + u) % MOD;
        
        return (total_permutations);
    }
};
