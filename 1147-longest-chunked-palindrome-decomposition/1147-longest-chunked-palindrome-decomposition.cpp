#include <string>
#include <string_view>
#include <algorithm>

class Solution {
public:
    int longestDecomposition(std::string text) {
        int n = text.length();
        int chunks = 0;
        
        // left_start and right_end track the boundaries of the remaining middle string
        int left_start = 0;
        int right_end = n - 1;
        
        // left_len tracks how long our current testing chunk is
        int left_len = 1;
        
        while (left_start + left_len - 1 < right_end - left_len + 1) {
            // Use std::string_view for O(1) slicing without memory allocation
            std::string_view prefix = std::string_view(text).substr(left_start, left_len);
            std::string_view suffix = std::string_view(text).substr(right_end - left_len + 1, left_len);
            
            if (prefix == suffix) {
                chunks += 2;               // Found matching outer chunks
                left_start += left_len;    // Move left boundary inward
                right_end -= left_len;     // Move right boundary inward
                left_len = 1;              // Reset chunk size for the next layer
            } else {
                left_len++;                // Keep expanding the current chunk size
            }
        }
        
        // If there are any characters left over in the middle that couldn't be paired,
        // they form one final single chunk in the center.
        if (left_start <= right_end) {
            chunks++;
        }
        
        return chunks;
    }
};
