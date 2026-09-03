// // class Solution {
// // public:
// //     bool is_palindrome(string& s,int l ,int r)
// //     {
// //         while(l<=r)
// //         {
// //             if(s[l]!=s[r]) return false;
// //             l++;
// //             r--;
// //         }
// //         return true;
// //     }
// //     int minCut(string s) {
// //         int n=s.size();
// //         vector<int>dp(n+1);
// //         dp[n]=-1;
// //         for(int i=n-1;i>=0;i--)
// //         {
// //             int minCuts=1e9;
// //             for(int j=i;j<n;j++)
// //             {
// //                 if(is_palindrome(s,i,j))
// //                 minCuts=min(minCuts,1+dp[j+1]);
// //             }
// //             dp[i]=minCuts;
// //         }
// //         return dp[0];
// //     }
// // };
// class Solution {
// public:
//     int minCut(string s) {
//         int n=s.size();
//         vector<int>dp(n+1);
//         dp[n]=-1;
//         vector<vector<bool>>is_palindrome(n,vector<bool>(n,false));
//         for(int i=n-1;i>=0;i--)
//         {
//             int minCuts=1e9;
//             for(int j=i;j<n;j++)
//             {
//                 // if(is_palindrome(s,i,j))
//                 if(s[i]==s[j] && (j-i<2 || is_palindrome[i+1][j-1]) ) //remember j-i correctly 
//                 {
//                     is_palindrome[i][j]=true;
//                     minCuts=min(minCuts,1+dp[j+1]);
//                 }
//             }
//             dp[i]=minCuts;
//         }
//         return dp[0];
//     }
// };

class Solution {
public:
    void expandAroundCenter(string s, int left, int right, vector<int>& dp) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            // If valid palindrome, cost to cut at right+1 is cost at left plus 1 cut
            dp[right + 1] = min(dp[right + 1], dp[left] + 1);
            left--;
            right++;
        }
    }

    int minCut(string s) {
        if (s.length() <= 1) return 0;
        int n = s.length();
        
        vector<int>dp(n+1,1e9);
        // dp[0]=0; this won't work
        for (int i = 0; i <= n; i++) {
            dp[i] = i - 1; // Maximum cuts possible for a string of length i
        }

        for (int i = 0; i < n; i++) {
            // 1. Odd length palindromes: centered at index i (e.g., "aba")
            expandAroundCenter(s, i, i, dp);
            
            // 2. Even length palindromes: centered between i and i+1 (e.g., "abba")
            expandAroundCenter(s, i, i + 1, dp);
        }
        
        return dp[n];
    }
};
     
