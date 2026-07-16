class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        
        // The maximum length of a repeating substring cannot exceed half the total length
        for (int i = 1; i <= n / 2; ++i) {
            // A pattern length must be a perfect divisor of the total length
            if (n % i == 0) {
                std::string pattern = s.substr(0, i);
                std::string repeated = "";
                
                // Build the string by repeating the pattern
                for (int j = 0; j < n / i; ++j) {
                    repeated += pattern;
                }
                
                if (repeated == s) {
                    return true;
                }
            }
        }
        return false;
    }
};