// class Solution {
// public:
//     int minSideJumps(vector<int>& obstacles) {
//         int first=1,second=0,third=1;
//         int n=obstacles.size();
//         for(int i=0;i<n-1;i++)
//         {
//             if(obstacles[i+1]==1)
//             first++;
//             else if(obstacles[i+1]==2)
//             second++;
//             else if(obstacles[i+1]==3)
//             third++;
//         }
//         return min(first,min(second,third));
//     }
// };
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        // Base case at index 0: Starting in Lane 2 takes 0 jumps.
        // Side-jumping to Lane 1 or Lane 3 immediately takes 1 jump.
        int first = 1, second = 0, third = 1;
        int n = obstacles.size();
        
        // Use a large value to represent a lane blocked by an obstacle
        int INF = 1e9; 

        for (int i = 1; i < n; i++) {
            // 1. Mark the lane as unreachable if it has an obstacle at the CURRENT index
            if (obstacles[i] == 1) first = INF;
            if (obstacles[i] == 2) second = INF;
            if (obstacles[i] == 3) third = INF;

            // 2. Find the absolute minimum jumps needed to reach this index safely in ANY lane
            int min_jumps = min({first, second, third});

            // 3. Allow sideways jumps: If a lane is clear, you can choose to jump into it 
            // from the best available lane at the cost of +1 jump.
            if (obstacles[i] != 1) first = min(first, min_jumps + 1);
            if (obstacles[i] != 2) second = min(second, min_jumps + 1);
            if (obstacles[i] != 3) third = min(third, min_jumps + 1);
        }

        // Return the minimum jumps required to reach the end across any of the 3 lanes
        return min({first, second, third});
    }
};
// class Solution {
// public:
//     int minSideJumps(vector<int>& obstacles) {
//         int n = obstacles.size() - 1;
//         int lane = 2; // Start in Lane 2
//         int jumps = 0;
        
//         for (int i = 0; i < n; i++) {
//             // If the next point in our current lane has an obstacle
//             if (obstacles[i + 1] == lane) {
//                 int furthest_lane = -1;
//                 int max_distance = -1;
                
//                 // Check all 3 lanes to see where we should jump
//                 for (int next_lane = 1; next_lane <= 3; next_lane++) {
//                     // 1. Cannot stay in the current lane
//                     // 2. Cannot jump into a lane that is blocked at the CURRENT index i
//                     if (next_lane == lane || obstacles[i] == next_lane) continue;
                    
//                     // Look ahead to find where the next obstacle is in this lane
//                     int look_ahead = i;
//                     while (look_ahead < n && obstacles[look_ahead] != next_lane) {
//                         look_ahead++;
//                     }
                    
//                     // Track the lane whose next obstacle is furthest in the future
//                     if (look_ahead > max_distance) {
//                         max_distance = look_ahead;
//                         furthest_lane = next_lane;
//                     }
//                 }
                
//                 // Switch to the best lane and log the jump
//                 lane = furthest_lane;
//                 jumps++;
//             }
//         }
//         return jumps;
//     }
// };
