// // class Solution {
// // public:
// //     string longestSubsequenceRepeatedK(string s, int k) {
        
// //     }
// // };
// class Solution {
// public:
//     // Helper function to check if the candidate string 't' repeated 'k' times 
//     // exists as a subsequence inside 's'
//     bool check(const string& t, const string& s, int k) {
//         if (t.empty()) return true;
//         int i = 0; // Tracks position inside the candidate 't'
        
//         for (char c : s) {
//             if (c == t[i]) {
//                 i++;
//                 if (i == t.length()) { // We successfully matched 't' once
//                     k--;
//                     if (k == 0) return true; // Matched 't' all k times!
//                     i = 0; // Reset to match the next repetition
//                 }
//             }
//         }
//         return false;
//     }

//     string longestSubsequenceRepeatedK(string s, int k) {
//         // 1. Count frequencies of elements
//         vector<int> count(26, 0);
//         for (char c : s) count[c - 'a']++;
        
//         // 2. Keep only elements that appear at least k times
//         vector<char> valid_chars;
//         for (int i = 0; i < 26; i++) {
//             if (count[i] >= k) {
//                 valid_chars.push_back('a' + i);
//             }
//         }
        
//         // 3. BFS to build candidates incrementally
//         queue<string> q;
//         q.push("");
//         string ans = "";
        
//         while (!q.empty()) {
//             string curr = q.front();
//             q.pop();
            
//             // Try expanding the current sequence with every valid character
//             for (char c : valid_chars) {
//                 string next_candidate = curr + c;
                
//                 // If it can be repeated k times, it's valid
//                 if (check(next_candidate, s, k)) {
//                     ans = next_candidate; // Because BFS goes length by length, the last valid one is longest
//                     q.push(next_candidate);
//                 }
//             }
//         }
        
//         return ans;
//     }
// };
class Solution {
public:
    string result = "";

    bool isSubsequence(string &s, string& sub, int k) {
        int i = 0;
        int j = 0;
        int L = sub.length();
        int n = s.length();

        while(i < n && j < k*L) {
            // Modulo L cleanly simulates repeating 'sub' k times
            if(s[i] == sub[j%L])
                j++;
            
            i++;
        }

        return j == k * L;
    }

    void backtracking(string& s, string &curr, vector<bool>& canUse, vector<int>& requiredFreq, int k, int maxLen) {
        if(curr.length() > maxLen)
            return;
        
        // Update result if 'curr' is longer, or same length but lexicographically larger
        if(!isSubsequence(s, curr, k)) return;
        if(curr.length() > result.length() ||(curr.length() == result.length() && curr > result) ) 
        {
                result = curr;
        }

        for(int i = 0; i <= 25; i++) {
            // Note: canUse[i] == false is redundant here since requiredFreq[i] == 0 handles it
            if(canUse[i] == false || requiredFreq[i] == 0)
                continue;
            
            //DO
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;

            //EXPLORE
            backtracking(s, curr, canUse, requiredFreq, k, maxLen);

            //UNDO
            curr.pop_back();
            requiredFreq[i]++;

        }

    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();

        int freq[26] = {};
        for(char &ch : s) {
            freq[ch-'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> requiredFreq(26, 0);
        for(int i = 0; i < 26; ++i) {
            if(freq[i] >= k) {
                canUse[i] = true;
                requiredFreq[i] = freq[i]/k; //atmost this can be used in a subsequence
            }
        }

        int maxLen = n / k;

        string curr;
        backtracking(s, curr, canUse, requiredFreq, k, maxLen);

        return result;


    }
};