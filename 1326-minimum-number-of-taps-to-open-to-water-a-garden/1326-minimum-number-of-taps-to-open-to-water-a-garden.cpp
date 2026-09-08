class Solution {
public:
    int minTaps(int n, std::vector<int>& ranges) {
        // max_reach[i] will store the furthest index we can reach starting from index i
        std::vector<int> max_reach(n + 1, 0);
        
        for (int i = 0; i <= n; ++i) {
            int start = std::max(0, i - ranges[i]);
            int end = std::min(n, i + ranges[i]);
            max_reach[start] = std::max(max_reach[start], end);
        }
        
        int taps = 0;
        int current_end = 0;
        int next_end = 0;
        
        // Loop through the garden up to n - 1
        for (int i = 0; i < n; ++i) {
            next_end = std::max(next_end, max_reach[i]);
            
            // If we reach the end of our current tap's coverage
            if (i == current_end) {
                // If the next best tap can't even move us past the current point, there's a gap
                if (next_end <= current_end) {
                    return -1;
                }
                current_end = next_end;
                taps++;
            }
        }
        
        return taps;
    }
};

// class Solution {
// public:
//     int minTaps(int n, std::vector<int>& ranges) {
//         std::vector<std::pair<int, int>> intervals;
        
//         // 1. Create intervals: [max(0, i - range), i + range]
//         for (int i = 0; i <= n; ++i) {
//             int start = std::max(0, i - ranges[i]);
//             int end = i + ranges[i];
//             intervals.push_back({start, end});
//         }
        
//         // 2. Sort intervals by start time ascending. 
//         // If start times match, C++ pairs naturally sort by end time ascending,
//         // which works perfectly fine for our greedy lookahead loop.
//         std::sort(intervals.begin(), intervals.end());
        
//         int taps = 0;
//         int current_end = 0;
//         int next_end = 0;
//         int i = 0;
        
//         // 3. Greedy Line Sweep
//         while (current_end < n) {
//             // Find the interval that starts before or at current_end 
//             // but extends the absolute farthest
//             while (i <= n && intervals[i].first <= current_end) {
//                 next_end = std::max(next_end, intervals[i].second);
//                 i++;
//             }
            
//             // If we didn't manage to move our boundary forward, there is a gap
//             if (current_end == next_end) {
//                 return -1;
//             }
            
//             current_end = next_end;
//             taps++;
//         }
        
//         return taps;
//     }
// };
// // normal way of doing sorting and arranging greedly fails simple because can we came accross max at first can lead to more interval later
