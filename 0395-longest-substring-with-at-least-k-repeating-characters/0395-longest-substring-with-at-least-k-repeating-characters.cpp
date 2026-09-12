// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// class Solution {
// public:
//     int longestSubstring(string s, int k) {
//         int n = s.size();
//         if (n == 0 || k > n) return 0;
//         if (k <= 1) return n;

//         // Step 1: Count total frequencies of characters in the current string
//         vector<int> count(26, 0);
//         for (char c : s) {
//             count[c - 'a']++;
//         }

//         // Step 2: Find the first character that breaks the 'at least k' rule
//         int idx = 0;
//         while (idx < n && count[s[idx] - 'a'] >= k) {
//             idx++;
//         }

//         // If all characters meet the requirement, the entire string is valid
//         if (idx == n) return n;

//         // Step 3: Split the string and recurse on left and right segments
//         int left_res = longestSubstring(s.substr(0, idx), k);
        
//         // Skip consecutive invalid splitters to save recursion depth
//         while (idx < n && count[s[idx] - 'a'] < k) {
//             idx++;
//         }
//         int right_res = (idx < n) ? longestSubstring(s.substr(idx), k) : 0;

//         return max(left_res, right_res);
//     }
// };


class Solution {
public:
    int longestSubstring(string s, int k) {
        int max_len = 0;
        int n = s.size();

        // U represents the targeted number of unique characters in the window
        for (int U = 1; U <= 26; U++) {
            vector<int> count(26, 0);
            int left = 0, right = 0;
            int unique_chars = 0;
            int count_at_least_k = 0;

            while (right < n) {
                // Expand window
                if (unique_chars <= U) {
                    int idx = s[right] - 'a';
                    if (count[idx] == 0) unique_chars++;
                    count[idx]++;
                    if (count[idx] == k) count_at_least_k++;
                    right++;
                } 
                // Shrink window
                else {
                    int idx = s[left] - 'a';
                    if (count[idx] == k) count_at_least_k--;
                    count[idx]--;
                    if (count[idx] == 0) unique_chars--;
                    left++;
                }

                // If window contains exactly U unique letters, and all match frequency >= k
                if (unique_chars == U && unique_chars == count_at_least_k) {
                    max_len = max(max_len, right - left);
                }
            }
        }
        return max_len;
    }
};
